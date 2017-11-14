// LICAIDlg.cpp : implementation file
//

#include "stdafx.h"
#include "LICAI.h"
#include "LICAIDlg.h"
#include "add.h"
#include "PWSet.h"
#include "REGIST.h"
#include "XGMIMA.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

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
// CLICAIDlg dialog

CLICAIDlg::CLICAIDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLICAIDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLICAIDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLICAIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLICAIDlg)
	DDX_Control(pDX, IDC_RECOVER, m_RECOVER);
	DDX_Control(pDX, IDC_COPY, m_COPY);
	DDX_Control(pDX, IDC_MODIFY, m_MODIFY);
	DDX_Control(pDX, IDC_GUANLI, m_GUANLI);
	DDX_Control(pDX, IDC_ADD, m_ADD);
	DDX_Control(pDX, IDC_TAB1, m_tab);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CLICAIDlg, CDialog)
	//{{AFX_MSG_MAP(CLICAIDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, OnSelchangeTab1)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_GUANLI, OnGuanli)
	ON_BN_CLICKED(IDC_MODIFY, OnModify)
	ON_BN_CLICKED(IDC_COPY, OnCopy)
	ON_BN_CLICKED(IDC_RECOVER, OnRecover)
	ON_BN_CLICKED(IDZHUXIAO, OnZhuxiao)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLICAIDlg message handlers

BOOL CLICAIDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
    //为Tab Control增加五个页面
	m_tab.InsertItem(0, _T("用户收支详细情况"));
    m_tab.InsertItem(1, _T("收支情况统计与意见"));
	m_tab.InsertItem(2, _T("图表统计信息"));
    m_tab.InsertItem(3, _T("软件使用日志"));
    //创建对话框
    m_page1.Create(IDD_PAGE1, &m_tab);
    m_page2.Create(IDD_PAGE2, &m_tab);
	m_page3.Create(IDD_PAGE3, &m_tab);
    m_page4.Create(IDD_PAGE4, &m_tab);
    //设定在Tab内显示的范围
    CRect rc;
    m_tab.GetClientRect(rc);
    rc.top += 20;
    rc.bottom -= 8;
    rc.left += 8;
    rc.right -= 8;
	m_page1.MoveWindow(&rc);
    m_page2.MoveWindow(&rc);
	m_page3.MoveWindow(&rc);
    m_page4.MoveWindow(&rc);
//把对话框对象指针保存起来
    pDialog[0] = &m_page1;
    pDialog[1] = &m_page2;
	pDialog[2] = &m_page3;
    pDialog[3] = &m_page4;
//显示初始页面
    pDialog[0]->ShowWindow(SW_SHOW);
    pDialog[1]->ShowWindow(SW_HIDE);
	pDialog[2]->ShowWindow(SW_HIDE);
	pDialog[3]->ShowWindow(SW_HIDE);
//保存当前选择
    m_CurSelTab = 0;
    if(!loginflag)
	{
		m_ADD.EnableWindow(FALSE);
		m_GUANLI.EnableWindow(FALSE);
		m_COPY.EnableWindow(FALSE);
		m_RECOVER.EnableWindow(FALSE);
	}
	return TRUE;
}

void CLICAIDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLICAIDlg::OnPaint() 
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
HCURSOR CLICAIDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CLICAIDlg::OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	pDialog[m_CurSelTab]->ShowWindow(SW_HIDE);
    m_CurSelTab = m_tab.GetCurSel();
    pDialog[m_CurSelTab]->ShowWindow(SW_SHOW);
	*pResult = 0;
}


void CLICAIDlg::OnAdd() 
{
	PWSet mySet;
	mySet.Open();
	REGIST mydlg;
	if(mydlg.DoModal()==IDOK)
	{
		while(!mySet.IsEOF()) 
		{
			if(mySet.m_ID!=mydlg.m_id)
				mySet.MoveNext();
			else 
			{
				MessageBox("用户名已存在","注意",MB_OK|MB_ICONINFORMATION);
				break;
			}
		}
		if(mydlg.m_id==""||mydlg.m_password==""||mydlg.m_npassword=="")
		{
			MessageBox("用户名密码确认密码不能为空","注意",MB_OK|MB_ICONINFORMATION);
			return;
		}
		if(mydlg.m_password!=mydlg.m_npassword)
		{
			MessageBox("两次密码输入不符","注意",MB_OK|MB_ICONINFORMATION);
			return;
		}
		else 
		{   
			mySet.AddNew();
			CString strTmp;
			COleDateTime oleDt=COleDateTime::GetCurrentTime();//获取本地的当前时间
			CString strFileName=oleDt.Format("%Y年%m月%d日 %H时%M分%S秒");
			strTmp=strFileName+"\r\n管理员 "+ID+"创建"+mydlg.m_id+"用户,权限为"+mySet.m_AUTHOR+"\r\n\n";
			mySet.m_ID=mydlg.m_id;
			mySet.m_PASSWORD=mydlg.m_password;
			mySet.m_AUTHOR=mydlg.author;
			mySet.Update();
			mySet.Requery();
			MessageBox("成功添加用户","家庭个人理财系统",MB_OK|MB_ICONINFORMATION);			
    		CStdioFile file(logFileName,CFile::modeNoTruncate|CFile::modeWrite);
        	file.SeekToEnd();//先定位到文件尾部
	       	file.WriteString(strTmp);
        	file.Close();
		}	
	}	
}

void CLICAIDlg::OnGuanli() 
{
	GUANLI mydlg;
	mydlg.DoModal();
	
}

void CLICAIDlg::OnModify() 
{
	PWSet mySet;
	mySet.Open();
begin:          
	mySet.Requery();
	XGMIMA mydlg;
	if(mydlg.DoModal()==IDOK)
	{ 
		while(!mySet.IsEOF()) 
		{
			if(mySet.m_ID!=mydlg.m_id)
				mySet.MoveNext();
			else 
				break;
		}
		if(mydlg.m_id==""||mydlg.m_npassword==""||mydlg.m_anpassword==""||mydlg.m_password=="")
		{
			MessageBox("   用户名原密码密码确认密码不能为空  ","家庭个人理财系统",MB_OK|MB_ICONINFORMATION);
			goto begin;
		}
		mySet.m_ID.TrimLeft();
        mySet.m_ID.TrimRight();
		if(mySet.m_ID!=mydlg.m_id)
		{
			MessageBox("          用户不存在           ","家庭个人理财系统",MB_OK|MB_ICONINFORMATION);
			goto begin;
		}
		if(mySet.m_PASSWORD!=mydlg.m_password)
		{
			MessageBox("       原密码错误,无法修改         ","家庭个人理财系统",MB_OK|MB_ICONINFORMATION);
			goto begin;
		}
		if(mydlg.m_npassword!=mydlg.m_anpassword)
		{ 
			MessageBox("       两次新密码输入不符         ","家庭个人理财系统",MB_OK|MB_ICONINFORMATION);
			goto begin;
		}
		else 
		{        
			mySet.Edit();
			mySet.m_PASSWORD=mydlg.m_npassword;
			mySet.Update();
			mySet.Requery();
			MessageBox("       用户口令修改成功         ","家庭个人理财系统",MB_OK|MB_ICONINFORMATION);
	    	COleDateTime oleDt=COleDateTime::GetCurrentTime();//获取本地的当前时间
		   	CString strFileName=oleDt.Format("%Y年%m月%d日 %H时%M分%S秒");
       		CString strTmp=strFileName+"\r\n\n用户 "+mydlg.m_id+" 修改口令成功\r\n\n\n\n\n";
	   		CStdioFile file(logFileName,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);
      		file.SeekToEnd();//先定位到文件尾部
	       	file.WriteString(strTmp);
      		file.Close();
		}	
	}
}

void CLICAIDlg::OnCopy()    //数据库的 备份
{
    CString   strDes;  
	static   char   BASED_CODE   szFilter[]   =   "ACCSESS   Files   (*.mdb)   |*.mdb||"; //可打开的文件类型
    CFileDialog   cFileDlg(FALSE,".mdb",NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,szFilter,this);   //false代表“另存为”，true代表“打开”
    cFileDlg.m_ofn.lStructSize   =   88;   
	if(cFileDlg.DoModal()   ==   IDOK)   
	{  
		strDes   =   cFileDlg.GetPathName();   //要备份的文件名(全路径)   
	    CopyFile(lpszFileName,strDes,FALSE);
	    MessageBox("       数据库备份成功         ","家庭个人理财系统",MB_OK|MB_ICONINFORMATION);
		COleDateTime oleDt=COleDateTime::GetCurrentTime();//获取本地的当前时间
	   	CString strFileName=oleDt.Format("%Y年%m月%d日 %H时%M分%S秒");
   		CString strTmp=strFileName+"\r\n\n管理员 "+ID+" 成功备份数据库\r\n\n\n\n\n";
		CStdioFile file(logFileName,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);
     	file.SeekToEnd();//先定位到文件尾部
	   	file.WriteString(strTmp);
      	file.Close();
    }	
}

void CLICAIDlg::OnRecover()    //数据的恢复
{
	CString   strDes;  
	static   char   BASED_CODE   szFilter[]   =   "ACCSESS   Files   (*.mdb)   |*.mdb||";   //设置打开的文件类型是什么在最后一个|前面可以继续添加你所需要的其他类型
    CFileDialog   cFileDlg(true,".mdb",NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,szFilter,this);   //true表示是打开的方式，窗口显示“打开两个字”
    cFileDlg.m_ofn.lStructSize   =   88;   
	if(cFileDlg.DoModal()   ==   IDOK)   
	{  
		strDes   =   cFileDlg.GetPathName();   //选择要还原的数据库的文件名(全路径)  
		CFile TempFile; 
		CStdioFile file; 
		if(file.Open(logFileName,CFile::modeRead))
		{
			file.Close();
			TempFile.Remove(logFileName);
		}
		CopyFile(strDes,lpszFileName,FALSE);
		MessageBox("       数据库还原成功         ","家庭个人理财系统",MB_OK|MB_ICONINFORMATION);
		COleDateTime oleDt=COleDateTime::GetCurrentTime();//获取本地的当前时间
	   	CString strFileName=oleDt.Format("%Y年%m月%d日 %H时%M分%S秒");
   		CString strTmp=strFileName+"\r\n\n管理员 "+ID+" 成功还原数据库\r\n\n\n\n\n";
		CStdioFile sfile(logFileName,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);
     	sfile.SeekToEnd();//先定位到文件尾部
	   	sfile.WriteString(strTmp);
      	sfile.Close();
    }
}

void CLICAIDlg::OnCancel()    //下面用到调用这个函数用来关闭窗口 程序
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CLICAIDlg::OnZhuxiao() 
{
	if(MessageBox("          确定注销当前系统吗?                 ","是否注销",MB_YESNO|MB_ICONINFORMATION)==IDYES)
	{
		OnCancel();
        CString   cmdLine=mianFileName;   
        STARTUPINFO   si;   
        ZeroMemory(&si,sizeof(si));   
        si.cb=sizeof(si);   
        PROCESS_INFORMATION   pi;   
        ZeroMemory(&pi,sizeof(pi));   
		if(CreateProcess(NULL,cmdLine.GetBufferSetLength(MAX_PATH+1),NULL,NULL,FALSE,CREATE_NO_WINDOW,NULL,NULL,&si,&pi))   
		{   
			CloseHandle(pi.hThread);   
            CloseHandle(pi.hProcess);   
		}   
		WaitForSingleObject(pi.hProcess,INFINITE);
		COleDateTime oleDt=COleDateTime::GetCurrentTime();//获取本地的当前时间
	   	CString strFileName=oleDt.Format("%Y年%m月%d日 %H时%M分%S秒");
   		CString strTmp=strFileName+"\r\n\n用户 "+ID+" 注销系统\r\n\n\n\n\n";
		CStdioFile sfile(logFileName,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);
     	sfile.SeekToEnd();//先定位到文件尾部
	   	sfile.WriteString(strTmp);
      	sfile.Close();
	}	
}
