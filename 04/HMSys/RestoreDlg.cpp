// RestoreDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hmsys.h"
#include "RestoreDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRestoreDlg dialog


CRestoreDlg::CRestoreDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRestoreDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRestoreDlg)
	m_strPath = _T("");
	//}}AFX_DATA_INIT
}


void CRestoreDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRestoreDlg)
	DDX_Text(pDX, IDC_PATH, m_strPath);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRestoreDlg, CDialog)
	//{{AFX_MSG_MAP(CRestoreDlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_RESTORE, OnRestore)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRestoreDlg message handlers

void CRestoreDlg::OnButton1() 
{
	CFileDialog FileDlg(true, "bak", ".bak", OFN_OVERWRITEPROMPT | OFN_HIDEREADONLY, "数据库文件(*.bak)|*.bak|"); 
	if(IDOK != FileDlg.DoModal()) 
	{ 	
		return ;
	}	
	m_strPath = FileDlg.GetPathName();
	UpdateData(FALSE);		
}

void CRestoreDlg::OnRestore() 
{
	UpdateData();					//数据的更新
	if(m_strPath == "")
	{
		MessageBox("请选择路径!");
		return ;
	}
	_ConnectionPtr pConnection;
	try
	{
		HRESULT hr = pConnection.CreateInstance("ADODB.Connection");//创建Connection对象
		pConnection->Open("driver={SQL Server};Server=HC\\MSSQL2008;DATABASE=master;","","",adModeUnknown);
		//pConnection->Open("driver={SQL Server};Server=HC\\MSSQL2008;DATABASE=master;UID=sa; PWD=","","",adModeUnknown);
		CString sql;//定义字符串变量
		sql.Format("use master restore database HMSys from disk = '%s' with move 'HMSys_data' to 'c:\\HMSys.mdf', move 'HMSys_log' to 'c:\\HMSys.ldf'", m_strPath);
		pConnection->Execute((_bstr_t)sql, NULL, adCmdText);
		MessageBox("还原成功！");
		pConnection->Close();//关闭连接
	}
	CATCH_ERROR;
}
