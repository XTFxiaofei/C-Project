// BYSONGTYPDLG.cpp : implementation file
//

#include "stdafx.h"
#include "HCOK.h"
#include "BYSONGTYPDLG.h"
#include "ADOConn.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
CString bysongtype,singername1;
/////////////////////////////////////////////////////////////////////////////
// BYSONGTYPDLG dialog


BYSONGTYPDLG::BYSONGTYPDLG(CWnd* pParent /*=NULL*/)
: CDialog(BYSONGTYPDLG::IDD, pParent)
{
	//{{AFX_DATA_INIT(BYSONGTYPDLG)
	// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void BYSONGTYPDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(BYSONGTYPDLG)
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(BYSONGTYPDLG, CDialog)
//{{AFX_MSG_MAP(BYSONGTYPDLG)
ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList1)

ON_WM_TIMER()
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// BYSONGTYPDLG message handlers
BOOL BYSONGTYPDLG::OnInitDialog() 
{
	CDialog::OnInitDialog();
    m_combo.InsertString(0,"流行");//初始化combo
	m_combo.InsertString(1,"民族");
	m_combo.InsertString(2,"通俗");
	m_combo.InsertString(3,"古典");
	m_combo.InsertString(4,"爵士");
	m_combo.InsertString(5,"摇滚");
    m_combo.InsertString(6,"轻音乐");
	m_combo.SetCurSel(0);   //设置默认
	m_list.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);//初始化list
	m_list.InsertColumn(0,"序号",LVCFMT_CENTER,100);
	m_list.InsertColumn(1,"歌曲名",LVCFMT_CENTER,270);
	SetTimer(1,5000,NULL);//设定定时器,用于刷新用户的操作信息
	GetDlgItem(IDC_INFOR)->SetWindowText("请双击鼠标左键选歌!");  //设定用户提示信息
	showsong();	         //显示歌曲	
	return TRUE;  
}



void BYSONGTYPDLG::OnSelchangeCombo1() //选择改变时刷新显示
{
	showsong();	
}


//*************************歌曲的显示****************************************//

void BYSONGTYPDLG::showsong()
{
	int ktype=m_combo.GetCurSel();
	m_combo.GetLBText(ktype,bysongtype);///////////////////得到歌类型
    CString songid,  songname;
	ADOConn m_AdoConn;  //创建数据库操作对象
	m_AdoConn.OnInitADOConn();  //链接
	_RecordsetPtr m_pRecordset;  //记录集指针
	_bstr_t sql;
	sql = "select*from musiclist where mtpye ='"+bysongtype+"'"; //定义SQL查询语句
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

void BYSONGTYPDLG::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 
{

	CString addtsongname =m_list.GetItemText(m_list.GetSelectionMark(),1);//得到要添加的歌曲名
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
	
     //---------------------------添加歌曲到临时表--------------------------------------//
	
	sql = "select* from usertemp where tmuname='"+addtsongname+"'";//查询该歌曲在临时表的记录
	m_pRecordset=m_AdoConn.GetRecordSet(sql);  //得到记录集
	if(!m_pRecordset->adoEOF)     //如果存在,则给出提示,并跳出
	{
		GetDlgItem(IDC_INFOR)->SetWindowText("该歌曲您已经点播过,请选择其他歌曲点播!");
		return;
	}
	
	//定义数据库复制语句,添加到usertemp表
	sql = "insert into usertemp (tmuname,tformate,tfilename,tsongtype,tsingername,playpath) select  muname,format,fname,mtpye,singernam,path from musiclist where muname ='"+addtsongname+"' ";
	m_AdoConn.ExecuteSQL(sql );//执行
	//定义数据库复制语句,添加到playlist表
	sql = "insert into playlist (tmuname,tformate,tfilename,tsongtype,tsingername,playpath) select  muname,format,fname,mtpye,singernam,path from musiclist where muname ='"+addtsongname+"' ";
	m_AdoConn.ExecuteSQL(sql );//执行
	GetDlgItem(IDC_INFOR)->SetWindowText("点播歌曲  "+addtsongname+"  成功!");  //给出提示
				
	m_AdoConn.ExitConnect();//释放数据库资源	



	
*pResult = 0;
}

void BYSONGTYPDLG::OnTimer(UINT nIDEvent) //更新提示
{
    GetDlgItem(IDC_INFOR)->SetWindowText("请双击鼠标左键选歌!");	
	CDialog::OnTimer(nIDEvent);
}

