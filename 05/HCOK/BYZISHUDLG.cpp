// BYZISHUDLG.cpp : implementation file
//

#include "stdafx.h"
#include "HCOK.h"
#include "BYZISHUDLG.h"
#include "ADOConn.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
CString munum,addnsingerna;
/////////////////////////////////////////////////////////////////////////////
// BYZISHUDLG dialog


BYZISHUDLG::BYZISHUDLG(CWnd* pParent /*=NULL*/)
	: CDialog(BYZISHUDLG::IDD, pParent)
{
	//{{AFX_DATA_INIT(BYZISHUDLG)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void BYZISHUDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(BYZISHUDLG)
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_COMBO1, m_combo1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(BYZISHUDLG, CDialog)
	//{{AFX_MSG_MAP(BYZISHUDLG)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList1)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// BYZISHUDLG message handlers


BOOL BYZISHUDLG::OnInitDialog() 
{
	CDialog::OnInitDialog();	
    m_combo1.InsertString(0,"1");//初始化combo控件
	m_combo1.InsertString(1,"2");
	m_combo1.InsertString(2,"3");
	m_combo1.InsertString(3,"4");
	m_combo1.InsertString(4,"5");
	m_combo1.InsertString(5,"6");
    m_combo1.InsertString(6,"7");
	m_combo1.InsertString(7,"8");
	m_combo1.InsertString(8,"9");
	m_combo1.InsertString(9,"10");
	m_combo1.InsertString(10,"11");
	m_combo1.InsertString(11,"12");
    m_combo1.SetCurSel(0);   //设默认值
	m_list.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);	//初始化list控件
	m_list.InsertColumn(0,"序号",LVCFMT_CENTER,100);
	m_list.InsertColumn(1,"歌曲名",LVCFMT_CENTER,270);
	SetTimer(1,5000,NULL);//显示刷新提示定时器
	showsong();   //显示歌曲
	GetDlgItem(IDC_INFOR)->SetWindowText("请双击鼠标左键选歌!");	 //设置默认信息
	return TRUE;
}




void BYZISHUDLG::OnSelchangeCombo1() //选择改变时刷新显示
{
	showsong();	
}



//*************************歌曲的显示****************************************//

void BYZISHUDLG::showsong()
{
	int ktype=m_combo1.GetCurSel();
	m_combo1.GetLBText(ktype,munum);///////////////////得到歌字数
    CString songid,  songname;
	ADOConn m_AdoConn;  //创建数据库操作对象
	m_AdoConn.OnInitADOConn();  //链接
	_RecordsetPtr m_pRecordset;  //记录集指针
	_bstr_t sql;
	sql = "select*from musiclist where mnum ='"+munum+"'"; //定义SQL查询语句
	m_pRecordset=m_AdoConn.GetRecordSet(sql);   //得到记录集 
	if(m_pRecordset->adoEOF)    //如果歌库中没有该条歌曲记录跳出
	{
		m_AdoConn.ExitConnect();//断开链接并关闭记录集
		return;
	}  
	int t=0;   //list标号
	m_list.DeleteAllItems();  //删除所有
	while(!m_pRecordset->adoEOF)  //遍历记录集
	{
		int b=t+1;  
		songid.Format("%d",b); //得到list序列号
		songname =m_pRecordset->GetFields()->GetItem("muname")->Value.bstrVal;//得到歌名
		m_list.InsertItem(t,songid);  //显示序列
		m_list.SetItemText(t,1,	songname); //显示歌名
		m_pRecordset->MoveNext(); //移到下条记录
		t++;
	   }
	m_AdoConn.ExitConnect();//释放数据库资源
}


void BYZISHUDLG::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
    CString addtsongname;
	addtsongname=m_list.GetItemText(m_list.GetSelectionMark(),1);//得到要添加的歌曲名	
	ADOConn m_AdoConn;   //创建数据库操作对象
	m_AdoConn.OnInitADOConn();  //建立数据库连接
	_RecordsetPtr m_pRecordset;  //定义记录集指针
	_bstr_t sql;
	sql = "select*from musiclist where muname='"+addtsongname+"' "; //定义SQL语句
	m_pRecordset=m_AdoConn.GetRecordSet(sql);   //得到记录集
	if(m_pRecordset->adoEOF)  //如果不存在
	{
		m_AdoConn.ExitConnect();  //释放数据库资源
		return;   //跳出函数
	}
	sql = "select* from usertemp where tmuname='"+addtsongname+"'";//查询该歌曲在临时表的记录
	m_pRecordset=m_AdoConn.GetRecordSet(sql);  //得到记录集
	if(!m_pRecordset->adoEOF)     //如果存在,则给出提示,并跳出
	{
		GetDlgItem(IDC_INFOR)->SetWindowText("该歌曲您已经点播过,请选择其他歌曲点播!");
		return;
	}
	//定义数据库复制语句,添加到usertemp表
	sql = "insert into usertemp(tmuname,tformate,tfilename,tsongtype,tsingername,playpath)select  muname,format,fname,mtpye,singernam,path from musiclist where muname ='"+addtsongname+"' ";
	m_AdoConn.ExecuteSQL(sql );//执行
	//定义数据库复制语句,添加到playlist表
	sql = "insert into playlist (tmuname,tformate,tfilename,tsongtype,tsingername,playpath)select  muname,format,fname,mtpye,singernam,path from musiclist where muname ='"+addtsongname+"' ";
	m_AdoConn.ExecuteSQL(sql );//执行
	GetDlgItem(IDC_INFOR)->SetWindowText("点播歌曲  "+addtsongname+"  成功!");  //给出提示				
	m_AdoConn.ExitConnect();//释放数据库资源	
    GetDlgItem(IDC_INFOR)->SetWindowText("添加歌曲  "+addtsongname+"  成功!");	
	*pResult = 0;
}

void BYZISHUDLG::OnTimer(UINT nIDEvent)  //刷新提示信息
{
    
	GetDlgItem(IDC_INFOR)->SetWindowText("请双击鼠标左键选歌!");	
	CDialog::OnTimer(nIDEvent);
}
