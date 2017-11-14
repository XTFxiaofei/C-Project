// HCDB.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "HCDB.h"

#include "MainFrm.h"
#include "HCDBDoc.h"
#include "HCDBView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include "PASSDLG.h"
#include "ForeMange.h"
/////////////////////////////////////////////////////////////////////////////
// CHCDBApp
#include "RESTOREDLG.h"
BEGIN_MESSAGE_MAP(CHCDBApp, CWinApp)
	//{{AFX_MSG_MAP(CHCDBApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHCDBApp construction

CHCDBApp::CHCDBApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CHCDBApp object


CRect rectsmall;
CRect rectlarge;
CHCDBApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CHCDBApp initialization

BOOL CHCDBApp::InitInstance()
{
	AfxEnableControlContainer();
     ::CoInitialize(NULL);
	if(!ConnectSql("driver={SQL Server};Server=HC\\MSSQL2008;Database=Sales"))
	{
		AfxMessageBox("数据库连接失败，请检查数据库Sales是否存在，检查服务器名称和帐号信息");
		return false;
	}
	//ConnectSql("driver={SQL Server};Server=HC\\MSSQL2008;Database=Sales;UID=sa;PWD=");
	if(!ConnectMaster("driver={SQL Server};Server=HC\\MSSQL2008;Database=master"))
	{
		AfxMessageBox("数据库连接失败，请检查服务器名称和帐号信息");
		return false;
	}
	//ConnectMaster("driver={SQL Server};Server=HC\\MSSQL2008;Database=master;UID=sa;PWD=");
    CRESTOREDLG dlg;
	dlg.DoModal();
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CHCDBDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CHCDBView));
	AddDocTemplate(pDocTemplate);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The one and only window has been initialized, so show and update it.

    PASSDLG dlg1;
	CString str;
	m_pMainWnd->ShowWindow(SW_HIDE);
	if(dlg1.DoModal()==IDOK)
	{
		CString sqlstr;		
		sqlstr.Format("select * from tb_operator where operid='%s' and operpassword='%s'",dlg1.m_user,dlg1.m_pass);
        if(GetRecord(sqlstr)==0){AfxMessageBox("没有该用户!");return true;}
        operid=dlg1.m_user;
        str=(LPCSTR)(_bstr_t)m_record->Fields->GetItem("operlevel")->Value;
		str.TrimRight();
	}
	else return true;
    if(str!="管理员")
	{
		CForeMange dlg;
		dlg.DoModal();
		m_pMainWnd->ShowWindow(SW_HIDE);
	}
	else
	{
		m_pMainWnd->ShowWindow(SW_SHOWMAXIMIZED);
		m_pMainWnd->UpdateWindow();
		m_pMainWnd->SetWindowText("超市管理系统--HC1.0");
	}


	return TRUE;
}


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
		// No message handlers
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

// App command to run the dialog
void CHCDBApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CHCDBApp message handlers


BOOL CHCDBApp::ConnectSql(CString sqlstr)
{
   if(m_connection!=NULL)
	   m_connection=NULL;
   try
   {
	   m_connection.CreateInstance("ADODB.Connection");
	   HRESULT rs;
	   rs=m_connection->Open((_bstr_t)sqlstr,"","",adModeUnknown);
	   if(rs)
	   {
		   ::AfxMessageBox("连接失败");
		   return false;
	   }
   }
   catch(_com_error e)
   { 
	   CString strError;
	   strError.Format("CADOWrong is %s\nCode Meaning is %s\nDescription is %s",e.ErrorMessage(),
		(LPCSTR)e.Source(),(LPCSTR)e.Description());
       ::AfxMessageBox(strError);
	    return false;
   }
   return true;
}

BOOL CHCDBApp::ConnectMaster(CString sqlstr)
{
   

   if(m_connection1!=NULL)
	   m_connection1=NULL;
   try
   {
	   m_connection1.CreateInstance("ADODB.Connection");
	   HRESULT rs;
	   rs=m_connection1->Open((_bstr_t)sqlstr,"","",adModeUnknown);
	   if(rs)
	   {
		   ::AfxMessageBox("连接失败");
		   return false;
	   }
   }
   catch(_com_error e)
   { 
	   CString strError;
	   strError.Format("CADOWrong is %s\nCode Meaning is %s\nDescription is %s",e.ErrorMessage(),
		(LPCSTR)e.Source(),(LPCSTR)e.Description());
       ::AfxMessageBox(strError);
	    return false;
   }
   return true;
}

int CHCDBApp::ExitInstance() 
{
	// TODO: Add your specialized code here and/or call the base class

	return CWinApp::ExitInstance();
}

int CHCDBApp::GetRecord(CString sqlstr)
{
	m_record=NULL;
	m_record.CreateInstance(__uuidof(Recordset));
	m_record->Open((_variant_t )sqlstr,theApp.m_connection.GetInterfacePtr(),
		           adOpenDynamic,adLockOptimistic,adCmdText);
	int count=0;
	if(m_record!=NULL)
	{
		try
		{
			m_record->MoveFirst();
		}
		catch(...)
		{
			return 0;
		}
		if(m_record->_EOF)return 0;
		while(!m_record->_EOF)
		{
			m_record->MoveNext();
			count++;
		}
	}
	m_record->MoveFirst();
	return count;
}
