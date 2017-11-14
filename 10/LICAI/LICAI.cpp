// LICAI.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "LICAI.h"
#include "LICAIDlg.h"
#include "odbcinst.h"
#include "LOGIN.h"
#include "PWSet.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
bool addflag,authorflag,loginflag=true,glflag=true;//用来判断现在执行的是添加操作还是修改操作;authorflag是用来判断当前为哪种登陆权限;loginflag用来记录在下拉框上点了哪个权限，是管理员还是宾客
CString ID,lpszFileName,logFileName,mianFileName;//ID用来标记现在登陆的用户名是什么,logFileName用来获取日志路径，lpszFileName用来获取数据库路径,mianFileName记录主程序路径
int static num1=1,num2=1;//num1用来记录管理员权限的帐号登陆的次数，num2用来记录宾客权限的帐号登陆的次数
/////////////////////////////////////////////////////////////////////////////
// CLICAIApp

BEGIN_MESSAGE_MAP(CLICAIApp, CWinApp)
	//{{AFX_MSG_MAP(CLICAIApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLICAIApp construction

CLICAIApp::CLICAIApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CLICAIApp object

CLICAIApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CLICAIApp initialization

BOOL CLICAIApp::InitInstance()
{
    CString sPath,user;//保存数据库文件路径名
	GetModuleFileName(NULL,sPath.GetBufferSetLength (MAX_PATH+1),MAX_PATH);//为sPath分配存储空间
	sPath.ReleaseBuffer();
	int nPos;
	nPos=sPath.ReverseFind('\\');
	sPath=sPath.Left(nPos);//获取文件的Debug路径,这样变为发行版的时候数据库可以放在同一目录下。
	nPos=sPath.ReverseFind('\\');
	sPath=sPath.Left(nPos);//获取文件的工程文件夹路径
    lpszFileName = sPath + "\\message.mdb";//保存数据库文件名称       
    logFileName = sPath + "\\log.txt";
	CFileFind  fFind;
	if(!fFind.FindFile(lpszFileName))
	{
		::AfxMessageBox("没有找到数据库message");
		exit(0);
	}
	CString szDesc;//保存对数据源的描述
	szDesc.Format( "DSN=LICAI;FIL=Microsoft Access;DEFAULTDIR=%s;DBQ=%s;" ,sPath,lpszFileName);      
	//添加数据源
	if(!::SQLConfigDataSource(NULL,ODBC_ADD_DSN, "Microsoft Access Driver (*.mdb)",(LPCSTR)szDesc))
	{
		::AfxMessageBox("32位ODBC数据源配置错误!");
		exit(0);
	}
	bool passflag=false;//用来判断是否登陆成功
	PWSet mySet;
	mySet.Open();
	LOGIN mydlg;
begin:	 
	mySet.Requery(); 
	if(mydlg.DoModal()==IDOK)
	{  
		if(mydlg.m_id==""||mydlg.m_password=="")
		{
			AfxMessageBox("用户或密码不能为空");
			return false;
		}		
		if(mydlg.author=="管理员")
		{
			loginflag=true;
			user="管理员";
		}
		else
		{
			loginflag=false;
			user="来宾";
		}
		while(!mySet.IsEOF()) 
		{						
			mySet.m_ID.TrimLeft();
			mySet.m_ID.TrimRight();
            if(mySet.m_ID==mydlg.m_id&&mySet.m_PASSWORD==mydlg.m_password&&mySet.m_AUTHOR==mydlg.author)
			{ 
					mySet.Close();
					passflag=true;
					authorflag=true;
					ID=mydlg.m_id;
					COleDateTime oleDt=COleDateTime::GetCurrentTime();//获取本地的当前时间
					CString strFileName=oleDt.Format("%Y年%m月%d日 %H时%M分%S秒");
					CString strTmp=strFileName+"\r\n\n"+user+ID+" 登陆系统\r\n\n\n\n\n";
					CStdioFile file(logFileName,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);
					file.SeekToEnd();//先定位到文件尾部
					file.WriteString(strTmp);
					file.Close();
					break;
			}
			else 
					mySet.MoveNext();		
		}

		if(!passflag)
		{
			AfxMessageBox("登录失败，请重试");
			mydlg.m_password="";
			mydlg.m_id="";
			mydlg.m_password="";
			goto begin;
		}
	}
	else 
		return false;




	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CLICAIDlg dlg;
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
		

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
