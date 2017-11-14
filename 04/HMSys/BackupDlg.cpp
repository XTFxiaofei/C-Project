// BackupDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hmsys.h"
#include "BackupDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBackupDlg dialog


CBackupDlg::CBackupDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBackupDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBackupDlg)
	m_strPath = _T("");
	//}}AFX_DATA_INIT
}


void CBackupDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBackupDlg)
	DDX_Text(pDX, IDC_PATH, m_strPath);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBackupDlg, CDialog)
	//{{AFX_MSG_MAP(CBackupDlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BACKUP, OnBackup)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBackupDlg message handlers

void CBackupDlg::OnButton1() 
{
	CFileDialog FileDlg(false, "bak", ".bak", OFN_OVERWRITEPROMPT | OFN_HIDEREADONLY, "数据库文件(*.bak)|*.bak|"); 
	if(IDOK != FileDlg.DoModal())				//打开打开文件对话框
	{ 	
		return ;
	}	
	m_strPath = FileDlg.GetPathName();			//获取选择文件的路径
	UpdateData(FALSE);							//数据的更新
}

void CBackupDlg::OnBackup() 
{
	UpdateData();								//数据的更新
	if(m_strPath == "")							//条件的判断
	{
		MessageBox("请选择路径!");				//提示信息
		return ;			
	}
	_ConnectionPtr pConnection;
	try
	{
		HRESULT hr = pConnection.CreateInstance("ADODB.Connection");//创建Connection对象
		pConnection->Open("driver={SQL Server};Server=HC\\MSSQL2008;DATABASE=master;","","",adModeUnknown);
		//pConnection->Open("driver={SQL Server};Server=HC\\MSSQL2008;DATABASE=master;UID=sa; PWD=","","",adModeUnknown);
		//连接数据库
		CString sql;						//定义字符串变量
		sql.Format("Backup Database HMSys to Disk = '%s' ", m_strPath);
		pConnection->Execute((_bstr_t)sql, NULL, adCmdText);//执行SQL语句
		MessageBox("备份成功！");
		pConnection->Close();				//关闭连接
	}
	CATCH_ERROR;	
}
