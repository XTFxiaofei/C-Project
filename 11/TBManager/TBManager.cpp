// TBManager.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "TBManager.h"
#include "LoginDlg.h"
#include "MainFrm.h"
#include "TBManagerDoc.h"
#include "TBManagerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
CString Conditionstr,username,userright;
bool modifyflag;
int num=10,stratnum=1;
CString e_mima,e_user;
/////////////////////////////////////////////////////////////////////////////
// CTBManagerApp

BEGIN_MESSAGE_MAP(CTBManagerApp, CWinApp)
	//{{AFX_MSG_MAP(CTBManagerApp)
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
// CTBManagerApp construction

CTBManagerApp::CTBManagerApp()
{
	CString strConnection="File Name=ThemeBase.udl";
	pDB=new CADODatabase;
	pDB->Open(strConnection);
	pRS=new CADORecordset(pDB);
	modifyflag=false;
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CTBManagerApp object

CTBManagerApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CTBManagerApp initialization

BOOL CTBManagerApp::InitInstance()
{
	AfxEnableControlContainer();
	CString str1,str2;
	bool flag;
	flag=false;
	CLoginDlg mydlg;	
test:
	pRS->Open("select * from password",CADORecordset.openQuery);
	if(!pRS->IsOpen())return false;
	if(pRS->GetRecordCount()<=0)return false;
	pRS->MoveFirst();
	if(mydlg.DoModal()==IDOK)
	{
		while(!pRS->IsEOF())
		{
			pRS->GetFieldValue("name",str1);
			pRS->GetFieldValue("password",str2);
			if(str1==mydlg.m_name&&str2==mydlg.m_password)
			{
				username=str1;
				pRS->GetFieldValue("userright",userright);
				e_mima=str2;
				e_user=str1;
				flag=true;
				break;	
			}
			pRS->MoveNext();
		}
	}
	else return false;
	if(!flag)
	{
		AfxMessageBox("�û�������������");
		goto test;
	}
	pRS->Close();
	pDB->Close();

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
		RUNTIME_CLASS(CTBManagerDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CTBManagerView));
	AddDocTemplate(pDocTemplate);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The one and only window has been initialized, so show and update it.
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	m_pMainWnd->SetWindowText("������ϵͳ");
//	m_Skin.SetWindowSkin(m_pMainWnd->m_hWnd, "MainFrame");
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
void CTBManagerApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CTBManagerApp message handlers
