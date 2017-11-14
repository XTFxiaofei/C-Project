// HCWORD.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "HCWORD.h"
#include "HCWORDDlg.h"
#include "odbcinst.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
int aa=0;
CString logFileName,lpszFileName;
/////////////////////////////////////////////////////////////////////////////
// CHCWORDApp

BEGIN_MESSAGE_MAP(CHCWORDApp, CWinApp)
	//{{AFX_MSG_MAP(CHCWORDApp)
	ON_COMMAND(ID_FGHU1, OnFghu1)
	ON_COMMAND(ID_BJ2, OnBj2)
	ON_COMMAND(ID_PF1, OnPf1)
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHCWORDApp construction



CHCWORDApp::CHCWORDApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CHCWORDApp object

CHCWORDApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CHCWORDApp initialization

BOOL CHCWORDApp::InitInstance()
{
	CCommandLineInfo cmdInfo; 
	ParseCommandLine(cmdInfo); 
	//if(aa==0)
	CSplashWnd::EnableSplashScreen(cmdInfo.m_bShowSplash);
	//if(aa==0)
	//SetDialogBkColor(RGB(35,135,50),RGB (105,20, 67));                         //设置背景颜色
	//else if(aa==1)
	//   SetDialogBkColor(RGB(130,194,22),RGB (105,20, 255));
	//else if(aa==2)
	//   SetDialogBkColor(RGB(1,194,22),RGB (105,20, 1));
	//else if(aa==3)
	{
		//m_skin.LoadSkinFile("corona.smf");                                         //装载皮肤
		//m_skin.SetDialogSkin("Dialog");
	}


	CString sPath,constr,str,filename;
	GetModuleFileName(NULL,sPath.GetBufferSetLength(MAX_PATH+1),MAX_PATH);
	int nPos;
	nPos=sPath.ReverseFind('\\');
	sPath=sPath.Left(nPos);              //获取Debug路径
	nPos=sPath.ReverseFind('\\');
	sPath=sPath.Left(nPos);
	filename=sPath+"\\database\\Dictionary.bak";
	CDatabase db;
	constr="DRIVER={SQL Server};SERVER=HC\\MSSQL2008;DATABASE=master;";
	//constr="DRIVER={SQL Server};SERVER=HC\\MSSQL2008;DATABASE=master; UID=sa; PWD=";
	db.OpenEx(constr,CDatabase::noOdbcDialog);
	str.Format("use master use master if not exists(select * from sysdatabases where name='Dictionary') restore database Dictionary from Disk = '%s' WITH MOVE 'Dictionary'  TO  'c:\\Dictionary.mdf', MOVE  'Dictionary_Log'  TO  'c:\\Dictionary.ldf'",filename);  //sql语句用于还原数据库
	db.ExecuteSQL(str);

	db.Close();
	BOOL  bODBC=SQLConfigDataSource(NULL,ODBC_ADD_DSN,"SQL Server",
		"DSN=词库\0"          
		"DATABASE=Dictionary\0"
		"SERVER=HC\\MSSQL2008\0 "); 
	if(!bODBC)
	{   AfxMessageBox("创建数据源失败");
        return false;
	}

	AfxEnableControlContainer();

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CHCWORDDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

 
	return FALSE;
}


void CHCWORDApp::OnFghu1() 
{
	aa=1;
	AfxGetMainWnd()->SendMessage(WM_CLOSE);                                            
    InitInstance();                                               //调用初始化函数

	
}

void CHCWORDApp::OnBj2() 
{
	aa=2;
	AfxGetMainWnd()->SendMessage(WM_CLOSE);
    InitInstance();
	
	
}

void CHCWORDApp::OnPf1() 
{
	aa=3;
	AfxGetMainWnd()->SendMessage(WM_CLOSE);
    InitInstance();
	
}
