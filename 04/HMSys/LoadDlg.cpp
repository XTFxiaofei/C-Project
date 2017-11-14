// LoadDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hmsys.h"
#include "LoadDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLoadDlg dialog


CLoadDlg::CLoadDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLoadDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLoadDlg)
	m_strPwd = _T("");
	m_strUser = _T("");
	//}}AFX_DATA_INIT
}


void CLoadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLoadDlg)
	DDX_Text(pDX, IDC_PWD, m_strPwd);
	DDX_Text(pDX, IDC_USER, m_strUser);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLoadDlg, CDialog)
	//{{AFX_MSG_MAP(CLoadDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLoadDlg message handlers
extern CHMSysApp theApp;
void CLoadDlg::OnOK() 
{
	UpdateData();
	CString strSQL;
	strSQL.Format("select count(*) from users where users = '%s' and pwd = '%s'", m_strUser, m_strPwd);
	try
	{
		_variant_t r;
		m_pRecordset = theApp.m_pConnection->Execute((_bstr_t)strSQL, NULL, adCmdText);
		r = m_pRecordset->GetCollect(_variant_t((long)0));
		m_bFlag = r.intVal; 
	}
	CATCH_ERROR;
	CDialog::OnOK();
}

BOOL CLoadDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_pRecordset.CreateInstance("ADODB.Recordset");		
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
