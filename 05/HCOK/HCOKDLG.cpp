// HCOKDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HCOK.h"
#include "HCOKDlg.h"
#include "ADMIN.h"
#include "ManageDLG.h"
#include "ADOConn.h"
#include "SINGIN.h"
#include "BYSGRDLG.h"
#include "BYPINYINDLG.h"
#include "BYZISHUDLG.h"
#include "BYSONGTYPDLG.h"
#include "SELECTEDDLG.h"
#include "UserPrintDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
CString playsongname;//////////////////////////播放的歌曲名
CString  playpath;///////////////////////////////播放文件路径
CString playsongformat;//////////////////////////播放的歌曲格式
CString delmuname1;////////////////////////////////要删除的歌曲名
CString seepath;
int row;
int radiocheck;
bool     Menutype;
int mode;////////////////////方式
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();
	
	// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA
	
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
	
	// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
//{{AFX_MSG_MAP(CAboutDlg)
// No message handlers
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHCOKDlg dialog

CHCOKDlg::CHCOKDlg(CWnd* pParent /*=NULL*/)
: CDialog(CHCOKDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHCOKDlg)
	m_text = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHCOKDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHCOKDlg)
	DDX_Control(pDX, IDC_SHOWTEXT, m_textctrl);
	DDX_Control(pDX, IDC_LIST2, m_list);
	DDX_Control(pDX, IDC_MEDIAPLAYER1, m_mediaplayer);
	DDX_Text(pDX, IDC_SHOWTEXT, m_text);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CHCOKDlg, CDialog)
//{{AFX_MSG_MAP(CHCOKDlg)
ON_COMMAND_RANGE(IDC_RADIOdb,IDC_RADIOlx, GetPlayMode)
ON_WM_SYSCOMMAND()
ON_WM_PAINT()
ON_WM_QUERYDRAGICON()
ON_BN_CLICKED(IDC_VOLUP, OnVolup)
ON_BN_CLICKED(IDC_VOLDOWN, OnVoldown)
ON_BN_CLICKED(IDC_QIUC, OnQiuc)
ON_BN_CLICKED(IDC_QBACK, OnQback)
ON_BN_CLICKED(IDC_PLAYPAUSE, OnPlaypause)
ON_BN_CLICKED(IDC_STOP, OnStop)
ON_BN_CLICKED(IDC_MANAGE, OnManage)
ON_BN_CLICKED(IDC_LOGOUT, OnLogout)
ON_BN_CLICKED(IDC_CHECKINOUT, OnCheckinout)
ON_WM_TIMER()
ON_BN_CLICKED(IDC_SINFIND, OnSinfind)
ON_BN_CLICKED(IDC_PYFIND, OnPyfind)
ON_BN_CLICKED(IDC_NUFIND, OnNufind)
ON_BN_CLICKED(IDC_TFIND, OnTfind)
ON_BN_CLICKED(IDC_SELECTED, OnSelected)
ON_NOTIFY(NM_DBLCLK, IDC_LIST2, OnDblclkList2)
ON_BN_CLICKED(IDC_PREVIOUS, OnPrevious)
ON_BN_CLICKED(IDC_NEXT, OnNext)
ON_WM_CONTEXTMENU()
ON_COMMAND(ID_MENUDANXUN, OnMenudanxun)
ON_COMMAND(ID_MENUDELALL, OnMenudelall)
ON_COMMAND(ID_MENUDELDAN, OnMenudeldan)
ON_COMMAND(ID_MENUNANQU, OnMenunanqu)
ON_COMMAND(ID_MENUSHUBO, OnMenushubo)
ON_COMMAND(ID_MENUXUNBO, OnMenuxunbo)
ON_BN_CLICKED(IDC_DELLIST, OnDellist)
ON_WM_CLOSE()
ON_NOTIFY(NM_RCLICK, IDC_LIST2, OnRclickList2)
ON_BN_CLICKED(IDC_HELP, OnHelp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHCOKDlg message handlers

BOOL CHCOKDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	// Add "About..." menu item to system menu.
	
	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	//***********初始化窗体指针***********************//	
	seleceddlg  =  NULL ; //已点歌曲
	bysingerdlg = NULL;  //按歌手查询
	bypinyindlg = NULL;   //按拼音查询 
	bynumdlg =NULL;       //按歌曲名字数查询
	bysongtypedlg = NULL;  //按歌曲类别查询	
	//**************************************************///
	m_text="点歌系统";            //m_text：字符串对应的值变量 
	m_textctrl.SetFontSize(27);
	m_textctrl.SetTextColor(RGB(0,255,0));
	m_textctrl.SetBkColor(RGB(247,247,247));
	m_textctrl.SetFontBold(TRUE);
	m_textctrl.SetText(m_text);	
	m_list.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	m_list.InsertColumn(0,"序号",LVCFMT_CENTER,140);
	m_list.InsertColumn(1,"节目名称",LVCFMT_CENTER,140);
	m_list.InsertColumn(2,"歌手",LVCFMT_CENTER,140);
	m_list.InsertColumn(3,"歌曲类别",LVCFMT_CENTER,140);
	m_list.InsertColumn(4,"文件名",LVCFMT_CENTER,140);
	m_list.InsertColumn(5,"文件格式",LVCFMT_CENTER,140);	   
	///////////////////////////////////////////////////////////////
	timenum=-1;     //开始让时间无效
	SetTimer(1,1000,NULL);   //设定定时器
	row=0;    //初始化在第一行
	m_list.SetItemState(row,LVIS_SELECTED|LVIS_FOCUSED,LVIS_SELECTED|LVIS_FOCUSED);
	m_list.SetFocus();     //设定list控件的焦点  
	/////////////////////////////////////
	/////////////////////////////////////////////////////////////临时表操作语句
	   
	_bstr_t createlistsql,  createsql;
	ADOConn m_AdoConn;
	createsql = "Create table usertemp(tmuname varchar(50),tformate varchar(50),tfilename varchar(50),tsongtype varchar(50),tsingername varchar(50),tsingerpin varchar(50),playpath  varchar(200))"; 
	createlistsql = "Create table playlist(tmuname varchar(50),tformate varchar(50),tfilename varchar(50),tsongtype varchar(50),tsingername varchar(50),tsingerpin varchar(50),playpath  varchar(200))";   
	m_AdoConn.ExecuteSQL(createsql);///创建usertemp表用于存放用户点的歌      在程序关闭时删除
	m_AdoConn.ExecuteSQL(createlistsql);//创建playlist表用于存放用户正在播放的歌  在程序关闭时删除
	//***********************禁用相应按键*******************************************//
	GetDlgItem(IDC_PREVIOUS)->EnableWindow(false);
	   GetDlgItem(IDC_NEXT)->EnableWindow(false);
	   GetDlgItem(IDC_VOLUP)->EnableWindow(false);
	   GetDlgItem(IDC_VOLDOWN)->EnableWindow(false);
	   GetDlgItem(IDC_QIUC)->EnableWindow(false);
	   GetDlgItem(IDC_QBACK)->EnableWindow(false);
	   GetDlgItem(IDC_PLAYPAUSE)->EnableWindow(false);
	   
	   
	   GetDlgItem(IDC_STOP)->EnableWindow(false);
	   GetDlgItem(IDC_SELECTED)->EnableWindow(false);
	   GetDlgItem(IDC_DELLIST)->EnableWindow(false);
	   GetDlgItem(IDC_SINFIND)->EnableWindow(false);
	   GetDlgItem(IDC_PYFIND)->EnableWindow(false);
	   GetDlgItem(IDC_NUFIND)->EnableWindow(false);
	   GetDlgItem(IDC_TFIND)->EnableWindow(false);
	   
	   //************************************************************//
	   ShowListDate();//显示数据
	   // TODO: Add extra initialization here
	   /////////////////////////////////////////////////////////设置默认播放方式
	   mode=3;
	   ((CButton *)GetDlgItem(IDC_RADIOdx))->SetCheck(false);  //控制播放模式的
	   ((CButton *)GetDlgItem(IDC_RADIOdb))->SetCheck(false);
	   ((CButton *)GetDlgItem(IDC_RADIOxb))->SetCheck(false);
	   ((CButton *)GetDlgItem(IDC_RADIOlx))->SetCheck(true);/////////////循环播放列表
	   return TRUE;  // return TRUE  unless you set the focus to a control
}

void CHCOKDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CHCOKDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting
		
		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);
		
		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		
		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CHCOKDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CHCOKDlg::GetPlayMode(UINT nID)
{
	switch(nID)
	{
	case IDC_RADIOdb:mode=0;break;
	case IDC_RADIOdx:mode=1;break;
	case IDC_RADIOxb:mode=2;break;
	case IDC_RADIOlx:mode=3;break;
	}
}
void CHCOKDlg::OnVolup()  //播放器控件加大音量
{
	if(m_mediaplayer.GetPlayState()!=2)return;
	long vl=m_mediaplayer.GetVolume();
	if(vl>=0)return;
	m_mediaplayer.Pause();
	m_mediaplayer.SetVolume(vl+200);	
	m_mediaplayer.Play();
	
}

void CHCOKDlg::OnVoldown()  //播放器控件减小音量
{
	if(m_mediaplayer.GetPlayState()!=2)return;
	long vl=m_mediaplayer.GetVolume();
	if(vl<=-9000)return;
	m_mediaplayer.Pause();
	m_mediaplayer.SetVolume(vl-200);	
	m_mediaplayer.Play();	
	
}

void CHCOKDlg::OnQiuc()   
{
	double pos=0;
	if(m_mediaplayer.GetPlayState()!=2)
		return;
	pos=m_mediaplayer.GetCurrentPosition();
	m_mediaplayer.Pause();
	m_mediaplayer.SetCurrentPosition(pos+5);
	m_mediaplayer.Play();	
}

void CHCOKDlg::OnQback() 
{
	if(m_mediaplayer.GetPlayState()!=2)return;
	double pos=m_mediaplayer.GetCurrentPosition();
	if(pos>5)
	{
		m_mediaplayer.Pause();
		m_mediaplayer.SetCurrentPosition(pos-5);
		m_mediaplayer.Play();
	}		
	
}

void CHCOKDlg::OnPlaypause() 
{
	CString text;
	GetDlgItem(IDC_PLAYPAUSE)->GetWindowText(text);
	if(m_mediaplayer.GetPlayState()!=2&&m_mediaplayer.GetPlayState()!=1)return;
	if(text=="暂停")
	{
		m_mediaplayer.Pause();
		GetDlgItem(IDC_PLAYPAUSE)->SetWindowText("播放");
	}	
	else
	{
		m_mediaplayer.Play();
		GetDlgItem(IDC_PLAYPAUSE)->SetWindowText("暂停");
	}	
	
}

void CHCOKDlg::OnStop() 
{
	m_mediaplayer.Stop();
	m_mediaplayer.SetCurrentPosition(0);
	
	
}

//********************管理员设置****************************************//
void CHCOKDlg::OnManage() 
{
    
	ADMIN mydlg;       //定义密码框窗体
	ManageDLG mydlg1;
	ADOConn m_AdoConn;    //定义数据库操作对象
	m_AdoConn.OnInitADOConn();  //创建数据库链接
	_bstr_t sql;
	_RecordsetPtr m_pRecordset;	//定义记录集
    
	if(mydlg.DoModal()==IDOK)
	{
		sql = "select*from admin where  adminpwd ='"+mydlg.m_mpassword+"'"; //查询密码
		m_pRecordset=m_AdoConn.GetRecordSet(sql);   //得到记录集
		if(m_pRecordset->adoEOF)	    //如果没有
		{AfxMessageBox("密码错误");	}   //提示错误
		else
		{
			mydlg1.DoModal();     //进入管理
		}
	}
	m_AdoConn.ExitConnect();//释放数据库资源
}


//********************注销****************************************//
void CHCOKDlg::OnLogout()
{
	ADMIN mydlg;   //定义密码框对象
	ADOConn m_AdoConn;  //创建数据库操作对象
	_bstr_t sql,dellistsql,delusersql;
	_RecordsetPtr m_pRecordset;	  //定义记录集
    
	if(mydlg.DoModal()==IDOK)
	{
		sql = "select*from admin where  adminpwd ='"+mydlg.m_mpassword+"'";  //验证密码语句
		m_pRecordset=m_AdoConn.GetRecordSet(sql);   //得到记录集
		if(m_pRecordset->adoEOF)	//没有
		{AfxMessageBox("密码错误");	}
		
		else            ///进入注销
		{
			
			GetDlgItem(IDC_CHECKINOUT)->SetWindowText("开户点歌");   //改变'开户点歌'按钮的显示
			dellistsql = "delete from playlist";     //删除播放列表表
			delusersql="delete from usertemp";       //删除用户临时歌库表
			m_AdoConn.ExecuteSQL (	dellistsql);      //执行
			m_AdoConn.ExecuteSQL (	 delusersql);     //执行
			ShowListDate();                           //刷新显示
			OnStop() ;                            //停止播放
		}
		MessageBox("注销成功!","系统提示：",MB_OK|MB_ICONASTERISK);  //给出提示信息
		
		//**********************禁用界面相关按钮******************************************//
		GetDlgItem(IDC_PREVIOUS)->EnableWindow(false);
		GetDlgItem(IDC_NEXT)->EnableWindow(false);
		GetDlgItem(IDC_VOLUP)->EnableWindow(false);
		GetDlgItem(IDC_VOLDOWN)->EnableWindow(false);
		GetDlgItem(IDC_QIUC)->EnableWindow(false);
		GetDlgItem(IDC_QBACK)->EnableWindow(false);
		GetDlgItem(IDC_PLAYPAUSE)->EnableWindow(false);
		
		
		GetDlgItem(IDC_STOP)->EnableWindow(false);
		GetDlgItem(IDC_SELECTED)->EnableWindow(false);
		GetDlgItem(IDC_DELLIST)->EnableWindow(false);
		GetDlgItem(IDC_SINFIND)->EnableWindow(false);
		GetDlgItem(IDC_PYFIND)->EnableWindow(false);
		GetDlgItem(IDC_NUFIND)->EnableWindow(false);
		GetDlgItem(IDC_TFIND)->EnableWindow(false);
		//*************************************************************************//
		
		m_AdoConn.ExitConnect(); //释放数据库资源
	}	
}


//********************开户点歌与结帐****************************************//

void CHCOKDlg::OnCheckinout() 
{	
	ADMIN mydlg;          //密码框对象
    CString price,abate,str;
	_bstr_t 	dellistsql, delusersql;	
	dellistsql ="delete from playlist";    //清空播放表,待下个用户使用,在此不删除
    delusersql="delete from usertemp";      //清空用户歌库表,待下个用户使用,在此不删除
	ADOConn m_AdoConn;         //定义数据库操作对象
	m_AdoConn.OnInitADOConn();  //链接数据库
	_bstr_t sql;
	_RecordsetPtr m_pRecordset;	   //定义记录集
	//*********************弹出密码框**********************//
    if(mydlg.DoModal()==IDOK)
	{	
		sql = "select*from admin where  adminname ='"+mydlg.m_user+"'"+"and adminpwd ='"+mydlg.m_mpassword+"'";//验证密码
		m_pRecordset=m_AdoConn.GetRecordSet(sql);
		if(m_pRecordset->adoEOF)	
		{
			MessageBox("密码错误,无权进入!","系统提示：",MB_OK|MB_ICONASTERISK);
			return ;
		}
		CString text;
		GetDlgItem(IDC_CHECKINOUT)->GetWindowText(text);//判断按钮的标题
		if(text=="开户点歌")	
		{   //----------------计算由预付金额所得到的时间---------------------------///
			SINGIN indlg;     //开户对话框
			if(indlg.DoModal()==IDOK)
			{
				GetDlgItem(IDC_CHECKINOUT)->SetWindowText("结帐");//设置按键名,改变状态
				//-----------------------开始计算------------------------//
				//得到房间价格
				ADOConn m_AdoConn;
				m_AdoConn.OnInitADOConn();
				_RecordsetPtr m_pRecordset;
				_bstr_t sql;
				sql = "select*from room where roomtype='"+addroomtype+"' ";//查询相应包间
				m_pRecordset=m_AdoConn.GetRecordSet(sql);   //得到记录集
				if(m_pRecordset->adoEOF) //如果没有记录
				{		
					MessageBox("您没有为"+addroomtype+"设置计费标准,请先设置价格!","系统提示：",MB_OK|MB_ICONASTERISK);
					GetDlgItem(IDC_CHECKINOUT)->SetWindowText("开户点歌");   //开户失败
					return;
				}
				else{
					price =m_pRecordset->GetFields()->GetItem("price")->Value.bstrVal;//得到相应房间的价格
					printprice=price;
				}
				m_pRecordset->Close();   //关闭记录集
				sql = "select*from abate where cardtype='"+addcardtype+"' ";   //根据选择的来查询打折率
				m_pRecordset=m_AdoConn.GetRecordSet(sql);  //得到记录集
				if(m_pRecordset->adoEOF)   //如果没有设置则开户失败
				{
					MessageBox("您没有为"+addcardtype+"设置打折率,请先设置!","系统提示：",MB_OK|MB_ICONASTERISK);
					GetDlgItem(IDC_CHECKINOUT)->SetWindowText("开户点歌");
					return;
				}
				else
				{
					abate =m_pRecordset->GetFields()->GetItem("abate")->Value.bstrVal;//若成功,则取出打折率
					printabate=	abate;
				}
				m_pRecordset->Close();
				CTime t=CTime::GetCurrentTime();
				timestr1=t.Format("%y年%m月%d日%H点%M时");/////////////////获得用户进入时间
				timenum=int(atof(givenmoney)*3600/atof(price)/atof(abate));//由用户付的钱根据包间价和打折率计算得到可用时间
				if(timenum==0)  //如果时间为0,则提示输入钱,开户失败
				{
					GetDlgItem(IDC_CHECKINOUT)->SetWindowText("开户点歌");
					MessageBox("您没有输入预交费!","系统提示：",MB_OK|MB_ICONASTERISK);	
					return;
				}			
				if(timenum<300)  //如果操作时间小于5分中给出提示
					MessageBox("您的预交费不足5分钟的点播时间,请注意系统将随时关闭!","系统提示：",MB_OK|MB_ICONASTERISK);
				//------------------------按钮变得可用-------------------------------------------------//
				GetDlgItem(IDC_PREVIOUS)->EnableWindow(true);
				GetDlgItem(IDC_NEXT)->EnableWindow(true);
				GetDlgItem(IDC_VOLUP)->EnableWindow(true);
				GetDlgItem(IDC_VOLDOWN)->EnableWindow(true);
				GetDlgItem(IDC_QIUC)->EnableWindow(true);
				GetDlgItem(IDC_QBACK)->EnableWindow(true);
				GetDlgItem(IDC_PLAYPAUSE)->EnableWindow(true);
				GetDlgItem(IDC_STOP)->EnableWindow(true);
				GetDlgItem(IDC_SELECTED)->EnableWindow(true);
				GetDlgItem(IDC_DELLIST)->EnableWindow(true);
				GetDlgItem(IDC_SINFIND)->EnableWindow(true);
				GetDlgItem(IDC_PYFIND)->EnableWindow(true);
				GetDlgItem(IDC_NUFIND)->EnableWindow(true);
				GetDlgItem(IDC_TFIND)->EnableWindow(true);
				MessageBox("进入点歌系统,开始计费!","系统提示：",MB_OK|MB_ICONASTERISK); //成功开户
			}
		}	
		else//-------------------结帐------------------------------//
		{	
			sql = "select*from room where roomtype='"+addroomtype+"' ";
			m_pRecordset=m_AdoConn.GetRecordSet(sql);
			price =m_pRecordset->GetFields()->GetItem("price")->Value.bstrVal;//得到包间价格
			sql = "select*from abate where cardtype='"+addcardtype+"' ";
			m_pRecordset=m_AdoConn.GetRecordSet(sql);
			if(m_pRecordset->adoEOF)
			{	AfxMessageBox("您没有为"+addcardtype+"设置打折率,请先设置!");}
			else
			{
				abate =m_pRecordset->GetFields()->GetItem("abate")->Value.bstrVal;	//得到打折率
			}
			float moneybake=double(timenum)*atof(price)*atof(abate)/3600;   //根据所剩时间算出应找回钱数
			if(moneybake<=0)           //由于是用定时器减时间的,所以有可能为负
				moneybake=0;
			CString strmoney;
			strmoney.Format("%.1f",moneybake); //找出应找的钱数
			printmoneybake=strmoney;
			CTime t1=CTime::GetCurrentTime();
			timestr2=t1.Format("%y年%m月%d日%H点%M时");/////////////////获得用户离开时间
			m_AdoConn.ExecuteSQL (	dellistsql);   //清空表
			m_AdoConn.ExecuteSQL (	 delusersql);   //清空表
		    ShowListDate();                   //刷新显示
			OnStop() ;                         //停止播放
			UserPrintDlg printdlg;//打印
			printdlg.DoModal();//打印
			GetDlgItem(IDC_CHECKINOUT)->SetWindowText("开户点歌");//改变按钮标题
			//----------------------禁用按钮----------------------------------------//
			GetDlgItem(IDC_PREVIOUS)->EnableWindow(false);
			GetDlgItem(IDC_NEXT)->EnableWindow(false);
			GetDlgItem(IDC_VOLUP)->EnableWindow(false);
			GetDlgItem(IDC_VOLDOWN)->EnableWindow(false);
			GetDlgItem(IDC_QIUC)->EnableWindow(false);
			GetDlgItem(IDC_QBACK)->EnableWindow(false);
			GetDlgItem(IDC_PLAYPAUSE)->EnableWindow(false);
			GetDlgItem(IDC_STOP)->EnableWindow(false);
			GetDlgItem(IDC_SELECTED)->EnableWindow(false);
			GetDlgItem(IDC_DELLIST)->EnableWindow(false);
			GetDlgItem(IDC_SINFIND)->EnableWindow(false);
			GetDlgItem(IDC_PYFIND)->EnableWindow(false);
			GetDlgItem(IDC_NUFIND)->EnableWindow(false);
			GetDlgItem(IDC_TFIND)->EnableWindow(false);
		}	
		m_AdoConn.ExitConnect();	//释放数据库资源
	}
}

void CHCOKDlg::OnTimer(UINT nIDEvent) 
{
	
	timenum--;  //根据预付费算出的时间每秒减1
	
	if(timenum==300)
	{	
		MessageBox("您还有5分钟的点歌时间,请联系管理员充值,否则将自动关闭!","系统提示：",MB_OK|MB_ICONASTERISK);
	}
	if(timenum==0)//////////实现和注销一样的功能
	{
		
		
		GetDlgItem(IDC_PREVIOUS)->EnableWindow(false);
		GetDlgItem(IDC_NEXT)->EnableWindow(false);
		GetDlgItem(IDC_VOLUP)->EnableWindow(false);
		GetDlgItem(IDC_VOLDOWN)->EnableWindow(false);
		GetDlgItem(IDC_QIUC)->EnableWindow(false);
		GetDlgItem(IDC_QBACK)->EnableWindow(false);
		GetDlgItem(IDC_PLAYPAUSE)->EnableWindow(false);
		
		
		GetDlgItem(IDC_STOP)->EnableWindow(false);
		GetDlgItem(IDC_SELECTED)->EnableWindow(false);
		GetDlgItem(IDC_DELLIST)->EnableWindow(false);
		GetDlgItem(IDC_SINFIND)->EnableWindow(false);
		GetDlgItem(IDC_PYFIND)->EnableWindow(false);
		GetDlgItem(IDC_NUFIND)->EnableWindow(false);
		GetDlgItem(IDC_TFIND)->EnableWindow(false);
		
		///////////////////////////////////////////////////////////////
		
		ADOConn m_AdoConn;
		_bstr_t dellistsql,delusersql;
		GetDlgItem(IDC_CHECKINOUT)->SetWindowText("开户点歌");
		dellistsql = "delete from playlist";
		delusersql="delete from usertemp";
		m_AdoConn.ExecuteSQL (	dellistsql);
		m_AdoConn.ExecuteSQL (	 delusersql);
		ShowListDate();
		OnStop() ;  
		
	}	
    
	
	
	
	int num = getSongNum();     //得到usertemp表中歌曲的条数
	int b=m_list.GetItemCount();//得到列表中的歌曲条数
	if(num != b)    //如果不相等那么刷新
	{ShowListDate();}
	
	
	if(m_list.GetItemCount()==1)//////////////////////实现添加立即播放
	{  
		playsongname=m_list.GetItemText(0,1);
		playsongformat=m_list.GetItemText(0,5);
		if(m_mediaplayer.GetPlayState()!=2&&m_mediaplayer.GetPlayState()!=1&&mode!=1)///////////如果不是播放和暂停状态,且不为单曲播放
			play();
	}
	
	
    //char szFilter[] =" 媒体文件 (所有类型)|*.mp3;*.wma;*.wmv;*.wav;*.avi;*.rm;*.rmvb|视频文件 |*.wmv;*.avi;*.rm;*.rmvb|音频文件|*.mp3;*.wma;*.wav|所有文件 (*.*)|*.*||";
	
    // CFileDialog filedlg( TRUE, NULL, NULL, OFN_HIDEREADONLY, szFilter ); 
    //	 filedlg.m_ofn.lpstrInitialDir   = ""; 
	CDialog::OnTimer(nIDEvent);
	
	
}

//********************按歌手查询****************************************//
void CHCOKDlg::OnSinfind() 
{
	//如果指针为NULL,则说明窗体还没创建,那么动态创建
	if(bysingerdlg == NULL)
	{  // 动态创建对话框对象
		bysingerdlg = new  BYSGRDLG;
		bysingerdlg->Create(IDD_BYSINGER,NULL);
	}
	
	bysingerdlg->ShowWindow(SW_SHOW);
}

//********************按歌手拼音查询****************************************//
void CHCOKDlg::OnPyfind() 
{
	
	//如果指针为NULL,则说明窗体还没创建,那么动态创建
	if(bypinyindlg == NULL)
	{  // 动态创建对话框对象
		bypinyindlg = new  BYPINYINDLG;
		bypinyindlg->Create(IDD_BYPINYIN,NULL);
	}
	bypinyindlg->ShowWindow(SW_SHOW);
	
}


//********************按歌曲名字数查询****************************************//
void CHCOKDlg::OnNufind() 
{
	//如果指针为NULL,则说明窗体还没创建,那么动态创建
	if(bynumdlg == NULL)
	{  // 动态创建对话框对象
		bynumdlg = new  BYZISHUDLG;
		bynumdlg->Create(IDD_BYZISHU,NULL);
	}
	bynumdlg->ShowWindow(SW_SHOW);
}


//********************按歌曲类别查询****************************************//
void CHCOKDlg::OnTfind() 
{
	//BYSONGTYPDLG bysongtypedlg;
	//bysongtypedlg.DoModal ();	
	//如果指针为NULL,则说明窗体还没创建,那么动态创建
	if(bysongtypedlg == NULL)
	{  // 动态创建对话框对象
		bysongtypedlg = new  BYSONGTYPDLG;
		bysongtypedlg->Create(IDD_BYSONGTYP,NULL);
	}
	bysongtypedlg->ShowWindow(SW_SHOW);
}

void CHCOKDlg::ShowListDate() /////////////////////////在在播放列表里显示歌曲
{
	CString songid,  songname,		  singername,  songtype,  filename,fileformat;
	   m_list.DeleteAllItems();//删除所有
	   
	   ADOConn m_AdoConn;   //定义数据库操作对象
	   m_AdoConn.OnInitADOConn();  //链接数据库
	   _bstr_t sql;
	   _RecordsetPtr m_pRecordset;	
	   sql = "select*from playlist ";    //查询 playlist表
	   m_pRecordset=m_AdoConn.GetRecordSet(sql);  //得到记录集
	   if(m_pRecordset->adoEOF)    //如果没有歌曲则退出
	   {
		   m_AdoConn.ExitConnect();
		   return;
	   }     
	   if(!m_pRecordset->adoEOF)
	   {  
		   int t=0;
		   m_list.DeleteAllItems();
		   while(!m_pRecordset->adoEOF)//遍历记录集
		   {int b=t+1;
		   
		   songid.Format("%d",b);
		   
		   songname =m_pRecordset->GetFields()->GetItem("tmuname")->Value.bstrVal;/////////////////取歌名
		   singername =m_pRecordset->GetFields()->GetItem("tsingername")->Value.bstrVal;/////////////////取歌手名
		   songtype =m_pRecordset->GetFields()->GetItem("tsongtype")->Value.bstrVal;/////////////////取歌的类型
		   filename =m_pRecordset->GetFields()->GetItem("tfilename")->Value.bstrVal;/////////////////取歌的文件名
		   fileformat =m_pRecordset->GetFields()->GetItem("tformate")->Value.bstrVal;/////////////////取歌的格式
		   //************************将信息显示在表上************************************//
		   m_list.InsertItem(t,songid);
		   m_list.SetItemText(t,1,	songname);
           m_list.SetItemText(t,2,	singername );
		   m_list.SetItemText(t,3,	songtype);
		   m_list.SetItemText(t,4,	filename);
		   m_list.SetItemText(t,5,	 fileformat);
		   m_pRecordset->MoveNext();
		   t++;
		   }
	   }
	   m_AdoConn.ExitConnect();  //释放数据库资源
}

//**************显示已选歌曲列表,用户可以将当中的歌曲添加到播放列表中*********************************//
void CHCOKDlg::OnSelected() 
{
	//SELECTEDDLG seleceddlg;
	
	
	//如果指针为NULL,则说明窗体还没创建,那么动态创建
	if(seleceddlg == NULL)
	{  // 动态创建对话框对象
		seleceddlg = new  SELECTEDDLG;
		seleceddlg->Create(IDD_SELECTED,NULL);
	}
	
	seleceddlg->ShowWindow(SW_SHOW);
	
}



void CHCOKDlg::OnDblclkList2(NMHDR* pNMHDR, LRESULT* pResult) ///////////////////双击
{
	
    playsongname=m_list.GetItemText(m_list.GetSelectionMark(),1);
    playsongformat=m_list.GetItemText(m_list.GetSelectionMark(),5);
	play();
	
	*pResult = 0;
}

//*********************播放歌曲函数*****************************************//
void CHCOKDlg::	play()
{	
    ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	_bstr_t sql;
	CString tempplaypath1,tempplaypath ;
	CString sPath ;
	int nPos;
    _RecordsetPtr m_pRecordset;
	sql = "select*from playlist where tmuname ='"+playsongname+"'";
	m_pRecordset=m_AdoConn.GetRecordSet(sql);
	if(m_pRecordset->adoEOF)
	{
		m_AdoConn.ExitConnect();
		return;
	}
	if(!m_pRecordset->adoEOF)
	{    
		while(!m_pRecordset->adoEOF)
		{
			tempplaypath1 =m_pRecordset->GetFields()->GetItem("playpath")->Value.bstrVal;/////////////////取字段
			tempplaypath=tempplaypath1;
			tempplaypath.TrimRight ();
			if(tempplaypath=="系统文件夹下")
			{
				GetModuleFileName(NULL,sPath.GetBufferSetLength (MAX_PATH+1),MAX_PATH);
				nPos=sPath.ReverseFind('\\');
				sPath=sPath.Left(nPos);
				nPos=sPath.ReverseFind('\\');
				sPath=sPath.Left(nPos);
				sPath=sPath+"\\歌库文件夹";
				playpath=sPath+	"\\"+playsongname+'.'+ playsongformat;
			}
			else
				playpath=tempplaypath1;
			m_pRecordset->MoveNext();	
		}
	}
	m_AdoConn.ExitConnect();	
	seepath=playpath;
	m_mediaplayer.Open(playpath);	
}

void CHCOKDlg::OnPrevious() ////////////////////上一首
{
	row=row-1;     //行标 - 1  
	playsongname=m_list.GetItemText(row,1);   //得到歌名
    playsongformat=m_list.GetItemText(row,5);  //歌曲格式
	
	if(playsongname=="")    //歌名不存在
	{ 
		row=m_list.GetItemCount()-1;	//循环到第一首	 
		playsongname=m_list.GetItemText(row,1);
		playsongformat=m_list.GetItemText(row,5);
	} 
	play(); 	 //播放
	ShowListDate() ;   //显示数据
	m_list.SetItemState(row,LVIS_SELECTED|LVIS_FOCUSED,LVIS_SELECTED|LVIS_FOCUSED);
	m_list.SetFocus();   //设置焦点
	
}

void CHCOKDlg::OnNext() ///////////////////下一首
{
	row=row+1;  //行标+1
	playsongname=m_list.GetItemText(row,1);
	playsongformat=m_list.GetItemText(row,5);
	
	if(playsongname=="")    //如果是最后一首则进入第一首
	{ 
		row=0;
		playsongname=m_list.GetItemText(row,1);
		playsongformat=m_list.GetItemText(row,5);
	} 
	play(); 	 //播放
	ShowListDate() ;  //显示
	m_list.SetItemState(row,LVIS_SELECTED|LVIS_FOCUSED,LVIS_SELECTED|LVIS_FOCUSED);
	m_list.SetFocus(); //设置焦点
	
}

void CHCOKDlg::OnContextMenu(CWnd* pWnd, CPoint point) /////////////////////////右击菜单
{
  		
}
//*************************下面的函数是用菜单创建的**************************************//
void CHCOKDlg::OnMenudanxun() //////////////////////////////////////单曲循环
{
	mode=0;
	((CButton *)GetDlgItem(IDC_RADIOdx))->SetCheck(TRUE);
	((CButton *)GetDlgItem(IDC_RADIOdb))->SetCheck(false);
	((CButton *)GetDlgItem(IDC_RADIOxb))->SetCheck(false);
	((CButton *)GetDlgItem(IDC_RADIOlx))->SetCheck(false);////////////////////单曲循环
}

void CHCOKDlg::OnMenudelall() ////////////////////////////////////////清空列表
{
	OnDellist();//调用函数
}

void CHCOKDlg::OnMenudeldan() ////////////////////////////////////删除所选曲目
{
	ADOConn m_AdoConn; //数据库操作对象
	_bstr_t sql;
	sql = "delete from playlist where tmuname= '"+delmuname1+"'";//删除语句
	
	m_AdoConn.ExecuteSQL (sql);  //执行
	ShowListDate();   //刷新
    m_AdoConn.ExitConnect();
	
	
}

void CHCOKDlg::OnMenunanqu() ////////////////////////////////////单曲播放
{
	mode=1;
	((CButton *)GetDlgItem(IDC_RADIOdx))->SetCheck(false);
	((CButton *)GetDlgItem(IDC_RADIOdb))->SetCheck(true);
	((CButton *)GetDlgItem(IDC_RADIOxb))->SetCheck(false);
	((CButton *)GetDlgItem(IDC_RADIOlx))->SetCheck(false);/////////////////单曲播放
	
}

void CHCOKDlg::OnMenushubo() ////////////////////////////////////顺序播放
{
	mode=2;
	((CButton *)GetDlgItem(IDC_RADIOdx))->SetCheck(false);
	((CButton *)GetDlgItem(IDC_RADIOdb))->SetCheck(false);
	((CButton *)GetDlgItem(IDC_RADIOxb))->SetCheck(true);
	((CButton *)GetDlgItem(IDC_RADIOlx))->SetCheck(false);/////////////顺序播放
	
}

void CHCOKDlg::OnMenuxunbo() ////////////////////////////////循环播放
{
	mode=3;
	((CButton *)GetDlgItem(IDC_RADIOdx))->SetCheck(false);
	((CButton *)GetDlgItem(IDC_RADIOdb))->SetCheck(false);
	((CButton *)GetDlgItem(IDC_RADIOxb))->SetCheck(false);
	((CButton *)GetDlgItem(IDC_RADIOlx))->SetCheck(true);/////////////循环播放列表
	
}




BEGIN_EVENTSINK_MAP(CHCOKDlg, CDialog)
//{{AFX_EVENTSINK_MAP(CHCOKDlg)
ON_EVENT(CHCOKDlg, IDC_MEDIAPLAYER1, 3002 /* EndOfStream */, OnEndOfStreamMediaplayer1, VTS_I4)
//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

//****************播放结束控件自动调用该函数************************************//
void CHCOKDlg::OnEndOfStreamMediaplayer1(long Result) 
{
	
	int b=m_list.GetItemCount();
	
	switch(mode)
	{
	case 0:  	play();break;        //单曲循环
		
	case 1:  OnStop() ;	break;  //单曲播放
		
	case 2:    row++;            //顺序播放
		if(row==b)
			OnStop() ;
		else play();
		break;
		
	case 3:  OnNext();break;      //循环播放列表
		
	default:  m_mediaplayer.SetCurrentPosition(0);break;
	}
	
}

//*********************清空播放列表***********************************//
void CHCOKDlg::OnDellist() 
{
	ADOConn m_AdoConn; //创建数据库操作对象
	_bstr_t sql;
	sql = "delete from playlist";   //定义SQL语句
	if(AfxMessageBox("是否真的要清空播放列表?",MB_YESNO) == IDYES)
	{	
		OnStop();
		m_AdoConn.ExecuteSQL (sql);  //执行语句
		ShowListDate();     //刷新
        m_AdoConn.ExitConnect();   //释放数据库资源
	}
}

//************************** 窗口关闭函数***********************************************//
void CHCOKDlg::OnClose() 
{
	//********首先输入密码进入****************** //
	ADMIN mydlg;        //创建密码框对象
    ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	_bstr_t sql;
	_RecordsetPtr m_pRecordset;	
    if(mydlg.DoModal()==IDOK)    //按下密码框的确定建
	{
		sql = "select*from admin where  adminpwd ='"+mydlg.m_mpassword+"'";
		m_pRecordset=m_AdoConn.GetRecordSet(sql);
		if(m_pRecordset->adoEOF)	
		{
			MessageBox("密码错误,你无权关闭!","系统提示：",MB_OK|MB_ICONASTERISK);	return;
		}
		
		//************释放非模态指针空间***************// 
		if(seleceddlg  !=  NULL)
			seleceddlg  =  NULL ; //已点歌曲
		
		if(bysingerdlg  !=  NULL)
			bysingerdlg = NULL;    //按歌手查询
		
		if(bypinyindlg  !=  NULL)  //按拼音查询
			bypinyindlg = NULL; 
		
		if(bynumdlg  !=  NULL)  //按歌曲名字数查询
			bynumdlg = NULL; 
		
		if(bysongtypedlg  !=  NULL)  //按歌曲类型查询
			bysongtypedlg = NULL; 
		
		//********************************************//
		CDialog::OnClose();
		
	}
	
}


BOOL CHCOKDlg::PreTranslateMessage(MSG* pMsg) //////////////////键盘消息函数
{
	if(pMsg->message   ==   WM_KEYDOWN)   
	{   
		if(pMsg->wParam   ==   VK_ESCAPE   ||   pMsg->wParam   ==   VK_RETURN)  /////////屏蔽回车和取消键 
		{   
			return   -1;   
		}   
		switch(pMsg->wParam)   
		{   
        case VK_SPACE:OnPlaypause() ;break;////////////////暂停播放
		case VK_LEFT:OnQback() ;break;    ////////////////////快退
		case VK_RIGHT:OnQiuc() ;break;   ////////////////////快进
		case VK_UP:OnPrevious() ;break;  ///////////////////////增加音量
		case VK_DOWN:OnNext() ;break;    //////////////////////减小音量
			
		}   
	}
	
	return CDialog::PreTranslateMessage(pMsg);
}

void CHCOKDlg::OnRclickList2(NMHDR* pNMHDR, LRESULT* pResult) /////////////////////////右击菜单
{
	delmuname1=m_list.GetItemText(m_list.GetSelectionMark(),1);  //得到要删除歌曲的名称
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
    int selectrow=pNMListView->iItem;  //得到所选的当前行数,当没有选中元素时值为 -1
    if(selectrow != -1)   //如果选中了一首歌曲,则可以显示菜单
	{
		LPPOINT lpoint=new tagPOINT;   
		::GetCursorPos(lpoint);     //获得当前鼠标的位置
		CMenu   menu,*pSubMenu; 
		menu.LoadMenu(IDR_MENU);                //添加菜单自定义资源
		pSubMenu=menu.GetSubMenu(0);           //设置菜单弹出项目起始位置
		pSubMenu->TrackPopupMenu(TPM_LEFTALIGN,lpoint->x,lpoint->y,this);    //获得鼠标位置
	}
	*pResult = 0;
}

//*********************帮助***************************************//
void CHCOKDlg::OnHelp() 
{
	CString sPath ;
	int nPos;
	GetModuleFileName(NULL,sPath.GetBufferSetLength (MAX_PATH+1),MAX_PATH);
	nPos=sPath.ReverseFind('\\');
	sPath=sPath.Left(nPos);                //由上到此得到DEBUG路径
    CString filename=sPath+"\\help.txt";   //得到帮助文档的全路径
	ShellExecute(NULL, "open",filename, NULL, NULL,SW_SHOWNORMAL);//打开帮助文件
	
	//函数原型-------ShellExecute(handle, "open", path_to_folder, NULL, NULL, SW_SHOWNORMAL)---//
	
}


//*****************得到playlist表中歌曲的条数*************************************//
int CHCOKDlg::getSongNum()
{
	   int songNum =0 ;
	   ADOConn m_AdoConn;
	   m_AdoConn.OnInitADOConn();
	   _bstr_t sql;
	   _RecordsetPtr m_pRecordset;	
	   sql = "select*from playlist ";
	   m_pRecordset=m_AdoConn.GetRecordSet(sql);
	   if(m_pRecordset->adoEOF)
	   {
		   m_AdoConn.ExitConnect();
		   return 0;
	   }
	   else{ 
		   while(!m_pRecordset->adoEOF)
		   {
			   songNum++;
			   m_pRecordset->MoveNext();
		   }
		   return songNum ;  //返回歌曲条数
	   }
	   m_AdoConn.ExitConnect();
}

