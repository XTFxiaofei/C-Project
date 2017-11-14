// HCOK.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "HCOK.h"
#include "HCOKDlg.h"
#include "ADOConn.h"
#include "SkinPlusPlus.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
CString addroomtype,addcardtype,givenmoney,	mkusingername,     printmoneybake,	mkusingersex ,mkusingerarea ,	mkusingerpin,nowp,timestr1,timestr2,printprice ,printabate;;
int tempshow1,tempshow,showsinger1,showsinger2,delsongfresh,mainshowlist;
CRect rectsmall,rectlarge;
/////////////////////////////////////////////////////////////////////////////
// CHCOKApp

BEGIN_MESSAGE_MAP(CHCOKApp, CWinApp)
	//{{AFX_MSG_MAP(CHCOKApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHCOKApp construction

CHCOKApp::CHCOKApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}
CHCOKApp::~CHCOKApp()
{


}

/////////////////////////////////////////////////////////////////////////
// The one and only CHCOKApp object

CHCOKApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CHCOKApp initialization

BOOL CHCOKApp::InitInstance()
{
	AfxEnableControlContainer();
	::CoInitialize(NULL);  //初始化OLE/COM库环境
	tempshow1=0;
	tempshow=0;
	showsinger1=0;
	showsinger2=0;
	delsongfresh=0;
	mainshowlist=0;

	//-----连接master数据库
	_ConnectionPtr m_pConnection;
	try
	{
		HRESULT hr = m_pConnection.CreateInstance("ADODB.Connection");//创建Connection对象
		if(SUCCEEDED(hr))
		{
			//hr = pConnection->Open("driver={SQL Server};Server=.;DATABASE=master;UID=sa;PWD=","","",adModeUnknown);//2000版本
			hr = m_pConnection->Open("driver={SQL Server};Server=HC\\MSSQL2008;DATABASE=master;","","",adModeUnknown);//2005及以上版本
			//hr = pConnection->Open("driver={SQL Server};Server=HC\\MSSQL2008;DATABASE=master; UID=sa; PWD=", "","",adModeUnknown);
		}
	}
	catch (_com_error e) //COM错误取得,当执行COM功能的时候，如果出错，可以捕捉到_com_error的异常
	{  
		CString strComError;
		strComError.Format("错误编号: %08lx\n错误信息: %s\n错误源: %s\n错误描述: %s",
			e.Error(),                  // 错误编号
			e.ErrorMessage(),           // 错误信息
			(LPCSTR) e.Source(),        // 错误源
			(LPCSTR) e.Description());  // 错误描述      
		
		::MessageBox(NULL,strComError,"错误",MB_ICONEXCLAMATION);
	}

	//程序启动时自动还原数据库
	_bstr_t vSQL;
	
	CString str1;
	CString filename,ConnectString;
	CString sPath;
	GetModuleFileName(NULL,sPath.GetBufferSetLength (MAX_PATH+1),MAX_PATH);  //获取当前路径
	sPath.ReleaseBuffer();
	int nPos;
	nPos=sPath.ReverseFind('\\');
	sPath=sPath.Left(nPos);
	nPos=sPath.ReverseFind('\\');
	sPath=sPath.Left(nPos);
	filename=sPath+"\\database\\music.bak";  //获取数据库备份文件路径

	//------判断数据库是否存在
	_RecordsetPtr pRecordset;
	pRecordset.CreateInstance("ADODB.Recordset");
	_variant_t vCount;
	try
	{
		_variant_t ra;
		pRecordset = m_pConnection->Execute("SELECT COUNT(*) FROM sysdatabases WHERE name = 'music'",&ra,adCmdText);
		vCount = pRecordset->GetCollect((_variant_t)(long)(0)); 
	}
	catch(_com_error e)
	{
		AfxMessageBox("error!");
		return false;
	}
	CString str;
	str.Format("%d", vCount.iVal);
	if(0 == vCount.iVal)
	{
		str1.Format("use master restore database music from Disk = '%s' WITH MOVE 'music_Data'  TO  'c:\\music.mdf', MOVE  'music_Log'  TO  'c:\\music.ldf'",filename);  //sql语句用于还原数据库
		vSQL=(_bstr_t)str1;
		m_pConnection->Execute(vSQL,NULL,adCmdText);  //执行还原数据库语句
	}
		
#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CHCOKDlg dlg;
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
		//////////////////////////////////////////////////美化
	
	return FALSE;
}
