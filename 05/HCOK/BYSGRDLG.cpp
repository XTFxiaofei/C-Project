// BYSGRDLG.cpp : implementation file
//

#include "stdafx.h"
#include "HCOK.h"
#include "BYSGRDLG.h"
#include "ADOConn.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

///////////////////////////////////////////////////////////////////////

//////
// BYSGRDLG dialog
int k;//用于判断菜单级数
CString singarea,addsingerna,remenber;
BYSGRDLG::BYSGRDLG(CWnd* pParent /*=NULL*/)
	: CDialog(BYSGRDLG::IDD, pParent)
{
	//{{AFX_DATA_INIT(BYSGRDLG)
	//}}AFX_DATA_INIT
}


void BYSGRDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(BYSGRDLG)
	DDX_Control(pDX, IDC_COMBO2, m_combo);
	DDX_Control(pDX, IDC_LIST1, m_list);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(BYSGRDLG, CDialog)
	//{{AFX_MSG_MAP(BYSGRDLG)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, OnItemchangedList1)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList1)
	ON_CBN_SELCHANGE(IDC_COMBO2, OnSelchangeCombo2)
	ON_BN_CLICKED(IDC_UP, OnUp)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

///////////////////////////////////////////////////////////////////////

//////
// BYSGRDLG message handlers

BOOL BYSGRDLG::OnInitDialog() 
{
	CDialog::OnInitDialog();
	//*************初始化combo************//
	m_combo.InsertString(0,"大陆男歌手");
	m_combo.InsertString(1,"大陆女歌手");
	m_combo.InsertString(2,"香港男歌手");
	m_combo.InsertString(3,"香港女歌手");
	m_combo.InsertString(4,"台湾男歌手");
	m_combo.InsertString(5,"台湾女歌手");
	m_combo.InsertString(6,"日韩男歌手");
	m_combo.InsertString(7,"日韩女歌手");
    m_combo.InsertString(8,"欧美男歌手");
	m_combo.InsertString(9,"欧美女歌手");
    m_combo.InsertString(10,"其他歌手");
	m_combo.SetCurSel(0);	   
	//*************初始化list************//
    m_list.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	m_list.InsertColumn(0,"序号",LVCFMT_CENTER,100);
	m_list.InsertColumn(1,"歌手名",LVCFMT_CENTER,270);
	k=2;  //用于判断菜单级数
	SetTimer(1,5000,NULL); //设定定时器用于更新用户操作反馈
	ShowDate();
    GetDlgItem(IDC_INFOR)->SetWindowText("请双击鼠标左键选择需点播歌!");	
	return TRUE; 
}


void BYSGRDLG::OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult) //的到list控件的值,在OnDblclkList1中得到值更好
                                                                  //m_list.GetItemText(m_list.GetSelectionMark(),1);//得到列表中第二列的值
{                                                                 //在按拼音查询时用的那种方法
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
 	int selectrow=pNMListView->iItem;   //得到选择的列
     addsingerna=m_list.GetItemText(selectrow,1);//得到第二列的值,addsingerna不仅代表歌手名,还有歌曲名
     if(k==2)       // 显示的是歌手名,保留歌手名,在返回时待用
	{
	 remenber=addsingerna;
	}
    UpdateData(false);
	*pResult = 0;
}

void BYSGRDLG::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 

////////////////////////鼠标双击,进入下一级菜单
{
	mainshowlist++;
	k--;      //鼠表的级数变化
	if (k<0)   //如果点多了
	k=0;
    ShowDate() ;   //刷新数据
	GetDlgItem(IDC_UP)->EnableWindow(true);
	*pResult = 0;
}


//*******************自定义显示函数*************************************//
void BYSGRDLG::ShowDate()    
{
	switch(k)     
	{
	case 0:  addsong();break;//执行添加歌曲到用户临时表
	case 1:  showsong();break;//显示歌曲在表中
	case 2:  showsinger();	break;//显示歌手函数
	default:  MessageBox("错误!");break;
	}
}

//********************执行添加歌曲到用户临时表**********************************************//
void BYSGRDLG::addsong()
{
	ADOConn m_AdoConn;   //创建数据库操作对象
	m_AdoConn.OnInitADOConn();  //创建链接
	_RecordsetPtr m_pRecordset;   //定义记录集指针
	_bstr_t sql;
	sql = "select*from musiclist where muname='"+addsingerna+"' ";//定义SQL语句
    m_pRecordset=m_AdoConn.GetRecordSet(sql); //得到记录集
	if(m_pRecordset->adoEOF)    //如果歌库中没有该条歌曲记录跳出
	   {
		m_AdoConn.ExitConnect();//断开链接并关闭记录集
		return;
	   }
	//添加歌曲到临时表
	   sql = "select* from usertemp where tmuname='"+addsingerna+"'\
		   and tsingername = '"+remenber+"'";//查出用户表中歌名和歌手相符的记录集
	   m_pRecordset=m_AdoConn.GetRecordSet(sql); //得到符合要求的记录集
	   if(!m_pRecordset->adoEOF)    //如果该歌曲已经存在,则跳出添加歌曲
	   {
		   GetDlgItem(IDC_INFOR)->SetWindowText("该歌曲您已经点播过!");	
		   return;
	   }
	   else
	   {  //如果该歌曲不存在,定义数据库复制语句,添加到usertemp表
		  sql = "insert into usertemp(tmuname,tformate,tfilename,tsongtype,tsingername,playpath) select  muname,format,fname,mtpye,singernam,path from musiclist where muname ='"+addsingerna+"'and singernam = '"+remenber+"' ";
			  m_AdoConn.ExecuteSQL(sql );//执行
		  //*********添加到播放临时表************//
		  //定义数据库复制语句,添加到playlist表
		  sql = "insert into playlist(tmuname,tformate,tfilename,tsongtype,tsingername,playpath) select  muname,format,fname,mtpye,singernam,path from musiclist  where muname ='"+addsingerna+"'and singernam = '"+remenber+"' ";
			  m_AdoConn.ExecuteSQL(sql );//执行
		  GetDlgItem(IDC_INFOR)->SetWindowText("点播歌曲 "+addsingerna+" 成功!");//点播成功
	   }
	   m_AdoConn.ExitConnect();//释放数据库资源
	   mainshowlist++;	
	   GetDlgItem(IDC_INFOR)->SetWindowText("点播歌曲 "+addsingerna+" 成功!");			
}

//***************************显示歌曲在表中*****************************************************//
void BYSGRDLG::showsong()
{
	   CString songid,  songname;
	   //清除以前的显示,重新初始化list
	   m_list.DeleteAllItems(); //解决显示上次列名问题
	   m_list.DeleteColumn(0);
	   m_list.DeleteColumn(0);
	   m_list.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	   m_list.InsertColumn(0,"序号",LVCFMT_CENTER,100);
	   m_list.InsertColumn(1,"歌曲名",LVCFMT_CENTER,270);
	   ADOConn m_AdoConn;    //创建数据库操作对象
	   m_AdoConn.OnInitADOConn(); //创建数据库链接
	   _bstr_t sql;
	   _RecordsetPtr m_pRecordset;	 //记录集指针
	   sql = "select*from musiclist where singernam ='"+remenber+"'"; //定义查询改歌手歌曲的语句
	   m_pRecordset=m_AdoConn.GetRecordSet(sql);  //得到记录集
	   if(m_pRecordset->adoEOF)  //如果没有歌曲
	   {
		   m_AdoConn.ExitConnect();  //释放数据库资源
		   return;
	   }
	   
	   int t=0;    //做list的序列号
	   while(!m_pRecordset->adoEOF)  //遍历记录集
	   {int b=t+1;
	   songid.Format("%d",b); //转换类型
	   songname =m_pRecordset->GetFields()->GetItem("muname")->Value.bstrVal;//得到歌曲名
	   m_list.InsertItem(t,songid);     //在list中插值
	   m_list.SetItemText(t,1,	songname);
	   m_pRecordset->MoveNext();   //移到下调记录
	   t++;
	   }
	   
	   m_AdoConn.ExitConnect();  //释放数据库资源

}

//*********************显示歌手函数********************************************//
void BYSGRDLG::showsinger()
{
	//*****************初始化列表*************************//
	m_list.DeleteAllItems(); 
	m_list.DeleteColumn(0);//解决显示上次列名问题	
	m_list.DeleteColumn(1);
	m_list.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	m_list.InsertColumn(0,"序号",LVCFMT_CENTER,100);
	m_list.InsertColumn(1,"歌手名",LVCFMT_CENTER,270);
	int L=m_combo.GetCurSel();
	m_combo.GetLBText(L,singarea);  //得到combo的值
	   ADOConn m_AdoConn;     //创建数据库对象
	   m_AdoConn.OnInitADOConn();  //建立连接
	   _bstr_t sql;
	   _RecordsetPtr m_pRecordset;	  //定义记录集指针
	   CString  id, //序列号
		   singernameby, //歌手名
		   sex;//性别
	   if(singarea=="其他歌手")
	   {	
		   singarea=singarea.Left(4);   //截取得到'其他'
		   sql = "select*from singer where sinarea ='"+singarea+"'";  //查找地区为'其他'的歌手
	   }
	   else
	   {
		   sex=singarea.Right (6);  //得到'性别+歌手'
		   singarea=singarea.Left(singarea.GetLength()-6);   //得到地区
		   sql = "select*from singer where sinarea ='"+singarea+"'and sinsex='"+sex+"'";//根据性别和地区查找
	   }
	   m_pRecordset=m_AdoConn.GetRecordSet(sql);   //得到记录集
	   if(m_pRecordset->adoEOF) //如果不存在
	   {
		   m_AdoConn.ExitConnect();  //释放数据库资源
		   return;   //跳出函数
	   }
	   int t=0;    //做list的序列号
	   while(!m_pRecordset->adoEOF)  //遍历记录集
	   {
		   int b=t+1;
		   id.Format("%d",b);
		   singernameby =m_pRecordset->GetFields()->GetItem("sinnam")->Value.bstrVal;//得到歌手名
		   
		   m_list.InsertItem(t,id);  //显示在list控件
		   m_list.SetItemText(t,1,singernameby); //显示歌手姓名
		   m_pRecordset->MoveNext();
		   t++;
	   }
	   m_AdoConn.ExitConnect();	 //释放数据库资源	   
}

//*****************点击后显示歌手列表,k=2*************************************//
void BYSGRDLG::OnSelchangeCombo2() 
{	
     k=2;   //显示歌手
	ShowDate() ;

}

//*********************返回上级菜单**********************************//
void BYSGRDLG::OnUp() 
{
  k++;//菜单级数变化
 if(k>2)  //超出显示级数
 {k=2; 	GetDlgItem(IDC_UP)->EnableWindow(FALSE);}  //禁用返回键
  ShowDate() ;	//显示数据
}

//********************更新操作反馈信息********************************//
void BYSGRDLG::OnTimer(UINT nIDEvent) 
{
   GetDlgItem(IDC_INFOR)->SetWindowText("请双击鼠标左键选择需点播歌!");	
	CDialog::OnTimer(nIDEvent);
}
