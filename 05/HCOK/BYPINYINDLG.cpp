// BYPINYINDLG.cpp : implementation file
//

#include "stdafx.h"
#include "HCOK.h"
#include "BYPINYINDLG.h"
#include "ADOConn.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// BYPINYINDLG dialog

CString 
pinyin,   //编辑框的值
add,      //从list中的到的第二列的值
singername;   //歌手姓名

int k1;       //用于判断菜单级数

BYPINYINDLG::BYPINYINDLG(CWnd* pParent /*=NULL*/)
: CDialog(BYPINYINDLG::IDD, pParent)
{
	//{{AFX_DATA_INIT(BYPINYINDLG)
	// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void BYPINYINDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(BYPINYINDLG)
	DDX_Control(pDX, IDC_LIST1, m_list);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(BYPINYINDLG, CDialog)
//{{AFX_MSG_MAP(BYPINYINDLG)
ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList1)
ON_BN_CLICKED(IDC_UP, OnUp)
ON_WM_TIMER()
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// BYPINYINDLG message handlers

BOOL BYPINYINDLG::OnInitDialog() 
{
	   CDialog::OnInitDialog();
	   m_list.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT); //初始化列表控件
	   m_list.InsertColumn(0,"序号",LVCFMT_CENTER,100);
	   m_list.InsertColumn(1,"歌手名",LVCFMT_CENTER,270);
	   SetTimer(1,5000,NULL);  //设定用于显示操作提示的定时器
	   k1=2;                  //设定显示级数为2级
	   ShowDate();             //显示相关数据
	   GetDlgItem(IDC_INFOR)->SetWindowText("请双击鼠标左键选择需点播歌!");	
	   return false;  
}

//*****************监听编辑框输入值的变化***********************************//
void BYPINYINDLG::OnChangeEdit1() 
{
    m_list.DeleteAllItems();   //清空列表框的所有内容
	GetDlgItem(IDC_EDIT1)->GetWindowText( pinyin);  //的到输入的拼音值
	k1=2;      // 将菜单级数设置为显示歌手的级别        
	ShowDate() ;  //显示符合条件的歌手
	
}

//*********************列表框的鼠标双击事件****************************************//
void BYPINYINDLG::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 
{ 
    add=m_list.GetItemText(m_list.GetSelectionMark(),1);//得到列表中第二列的值
    
	if(k1==2)//保留歌手名,在返回时待用
		
	{
		
		singername=add;
		
	}
	
	k1--;       //进入一层           
	if (k1<0)    //点了多次
		k1=0;
	
	ShowDate() ;     //显示数据
	GetDlgItem(IDC_UP)->EnableWindow(true);  //将后退按键变为可用
				
	*pResult = 0;
}

//******************自定义显示函数*****************************************//

void BYPINYINDLG::ShowDate()   
{
	switch(k1)  //判断执行什么 操作
	{
	case 0:  addsong();break;       //执行添加歌曲到用户临时表
	case 1:  showsong();break;      //显示歌曲在表中
	case 2:  showsinger();	break;  //显示歌手函数
	default:  MessageBox("错误!");break;
	}
}

//*********************执行添加歌曲到用户临时表 和 播放列表 表中*****************************************//
void BYPINYINDLG::addsong()
{
    CString 	sformat,	sfilename,	stype,	ssname,	spath;
	
    
	ADOConn m_AdoConn;          //定义一个封装数据库类的对象
	m_AdoConn.OnInitADOConn();  //连接数据库
	
	_RecordsetPtr m_pRecordset;
	_bstr_t sql,addtolist; 
	
	sql = "select*from musiclist where muname='"+add+"' and singernam ='"+singername+"' ";   //查出歌库中歌名和歌手相符的记录集
	
	addtolist="select* from playlist where tmuname='"+add+"' and  tsingername = '"+singername+"'";//查出播放列表 表中歌名和歌手相符的记录集	
	
	
	
	m_pRecordset=m_AdoConn.GetRecordSet(sql);    // 在musiclist取得符合要求的记录集
	
	   if(m_pRecordset->adoEOF)    //如果歌库中没有该条歌曲记录跳出
	   {
		   m_AdoConn.ExitConnect();//断开链接并关闭记录集
		   return;
	   }
	   
	   ////////////////////////////////////////////////////////////////////添加歌曲到临时表
	   
	   sql = "select* from usertemp where tmuname='"+add+"' and tsingername = '"+singername+"'";//查出用户表中歌名和歌手相符的记录集
	   m_pRecordset=m_AdoConn.GetRecordSet(sql); //得到符合要求的记录集
	   if(!m_pRecordset->adoEOF)    //如果该歌曲已经存在,则跳出添加歌曲
	   {
		   GetDlgItem(IDC_INFOR)->SetWindowText("该歌曲您已经点播过,请选择其他歌曲点播!");	
		   return;
	   }
	   else{  //如果该歌曲不存在
		   //定义数据库复制语句,添加到usertemp表
		   sql = "insert into usertemp (tmuname,tformate,tfilename,tsongtype,tsingername,playpath) select  muname,format,fname,mtpye,singernam,path from musiclist where muname ='"+add+"' ";
		   m_AdoConn.ExecuteSQL(sql );//执行
		   
		   //************************添加到播放临时表*******************************************///
		   //定义数据库复制语句,添加到playlist表
		   sql = "insert into playlist (tmuname,tformate,tfilename,tsongtype,tsingername,playpath) select  muname,format,fname,mtpye,singernam,path from musiclist where muname ='"+add+"' ";
		   m_AdoConn.ExecuteSQL(sql );//执行
		   GetDlgItem(IDC_INFOR)->SetWindowText("点播歌曲   "+add+"   成功!");//点播成功
	   }
	   m_AdoConn.ExitConnect();//释放数据库资源
	   
}

//*************************显示歌曲在表中**********************************************//
void BYPINYINDLG::showsong()
{
	CString songid,  songname;
	
	   m_list.DeleteColumn(0);    //解决显示上次列名问题
	   m_list.DeleteColumn(0);
	   m_list.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	   m_list.InsertColumn(0,"序号",LVCFMT_CENTER,100);
	   m_list.InsertColumn(1,"歌曲名",LVCFMT_CENTER,270);
	   
	   ADOConn m_AdoConn;     //定义一个封装数据库类的对象
	   m_AdoConn.OnInitADOConn();//连接数据库
	   _bstr_t sql;           
	   _RecordsetPtr m_pRecordset;	//定义记录集指针
	   
	   sql = "select * from musiclist where singernam ='"+add+"'";  //将该歌手的所有歌曲显示
	   
	   m_pRecordset=m_AdoConn.GetRecordSet(sql); //的到歌曲记录集
	   if(m_pRecordset->adoEOF)    //如果没有则跳出函数
	   {
		   m_AdoConn.ExitConnect();
		   return;
	   }
	   if(!m_pRecordset->adoEOF)     //该歌手有歌曲
	   {  
		   int t=0;
		   m_list.DeleteAllItems();  //删除先前的显示
		   while(!m_pRecordset->adoEOF)   //遍历记录集
		   {
			   int b=t+1; //列序号
			   songid.Format("%d",b);  //转换类型
			   songname =m_pRecordset->GetFields()->GetItem("muname")->Value.bstrVal; //得歌名
			   m_list.InsertItem(t,songid);   //设置列序号
			   m_list.SetItemText(t,1,	songname);  //设置歌名
			   m_pRecordset->MoveNext();  //移到下条记录
			   t++;
		   }
	   }
	   
	   else 
	   {
		   m_list.DeleteAllItems();//删除所有歌曲记录
	   }
	   
	   m_AdoConn.ExitConnect();//断开数据库连接
	   
}

//***********************显示歌手函数**************************************//
void BYPINYINDLG::showsinger()
{
	//m_list.DeleteAllItems();   //删除列表元素
	   m_list.DeleteColumn(0);    //解决显示上次列名问题
	   m_list.DeleteColumn(0); 
	   m_list.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT); //初始化列表控件
	   m_list.InsertColumn(0,"序号",LVCFMT_CENTER,100);
	   m_list.InsertColumn(1,"歌手名",LVCFMT_CENTER,270);
	   
	   ADOConn m_AdoConn;
	   m_AdoConn.OnInitADOConn();
	   _bstr_t sql;
	   CString songid,  singernameby, songtotal,sex;
	   _RecordsetPtr m_pRecordset;	
	   sql = "select * from singer where 1=1";//没有输入时显示所有歌曲
	  
	

	   if(pinyin !="")   //没有输入则跳出
	   {
		   sql = sql +"and sinpin like '"+pinyin+"%'";//定义根据歌手拼音模糊查询语句
		  
	   }
	   m_pRecordset=m_AdoConn.GetRecordSet(sql);   //得到记录集
	   if(m_pRecordset->adoEOF)    //如果没有符合输入的记录,则跳出
	   {
		   m_AdoConn.ExitConnect();
		   return;
	   }
	   if(!m_pRecordset->adoEOF)    //有记录
	   {    
		   int t=0;    
		   m_list.DeleteAllItems();    //删除列表控件元素
		   while(!m_pRecordset->adoEOF) //遍历记录集
		   {
			   int b=t+1;
			   songid.Format("%d",b);
			   singernameby =m_pRecordset->GetFields()->GetItem("sinnam")->Value.bstrVal;//取歌手名
			   m_list.InsertItem(t,songid);    //添加序列号
			   m_list.SetItemText(t,1,singernameby);  //添加歌手名
			   m_pRecordset->MoveNext();  //移到下条
			   t++;
		   }
	   }
	   
	   else 
	   {
		   m_list.DeleteAllItems(); //清空显示
	   }
	   
	   m_AdoConn.ExitConnect();	
	   
}
//********************返回键*************************************//
void BYPINYINDLG::OnUp() 
{
	if(k1==0) //如果完成了添加则将显示的默认级别加 1
		k1=1;
	k1++;   //将显示的级别加 1
	if(k1>2)  //如果K1>设定值
	{k1=2; 	GetDlgItem(IDC_UP)->EnableWindow(FALSE);} //恢复到定值,并禁用后退按钮
	ShowDate() ;//调用显示函数	
}

void BYPINYINDLG::OnTimer(UINT nIDEvent) //设置提示信息
{
    GetDlgItem(IDC_INFOR)->SetWindowText("请双击鼠标左键选歌!");
	CDialog::OnTimer(nIDEvent);
}
