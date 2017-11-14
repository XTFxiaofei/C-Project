// BACKUPDLG.cpp : implementation file
//

#include "stdafx.h"
#include "tbmanager.h"
#include "BACKUPDLG.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// BACKUPDLG dialog


BACKUPDLG::BACKUPDLG(CWnd* pParent /*=NULL*/)
	: CDialog(BACKUPDLG::IDD, pParent)
{
	//{{AFX_DATA_INIT(BACKUPDLG)
	m_path = _T("D:\\abao.bak");
	//}}AFX_DATA_INIT
}


void BACKUPDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(BACKUPDLG)
	DDX_Text(pDX, IDC_EDIT1, m_path);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(BACKUPDLG, CDialog)
	//{{AFX_MSG_MAP(BACKUPDLG)
	ON_BN_CLICKED(ID_SELECT, OnSelect)
	ON_BN_CLICKED(ID_BACKUP, OnBackup)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// BACKUPDLG message handlers

void BACKUPDLG::OnSelect() 
{
	CFileDialog filedlg(false,"bak",NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,
		"备份文件(*.bak)|*.bak|All Files (*.*)|*.*||");  
	if(filedlg.DoModal()==IDOK)
	{
		m_path=filedlg.GetPathName();
		UpdateData(FALSE);
	}		
}

void BACKUPDLG::OnBackup() 
{
	if(m_path!="")
	{
		CString ConnectString;
		CString sqlstr;
		sqlstr.Format("backup database abao to Disk = '%s'",m_path);
		pDB->Execute(sqlstr);
		AfxMessageBox("备份成功!\r\n文件放在:"+m_path);
	}
	else
	{
		AfxMessageBox("请选择路径!");
		return;		
	}	
}

BOOL BACKUPDLG::OnInitDialog() 
{
	CDialog::OnInitDialog();	
	pDB=new CADODatabase;
	pDB->Open("driver={SQL Server};Server=HC\\MSSQL2008;DATABASE=abao;");
	//pDB->Open("driver={SQL Server};Server=HC\\MSSQL2008;DATABASE=master;UID=sa; PWD=");
	return TRUE;  
}
