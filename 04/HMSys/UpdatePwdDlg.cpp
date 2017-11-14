// UpdatePwdDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HMSys.h"
#include "UpdatePwdDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUpdatePwdDlg dialog
extern CHMSysApp theApp;

CUpdatePwdDlg::CUpdatePwdDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUpdatePwdDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUpdatePwdDlg)
	m_strPwd1 = _T("");
	m_strPwd2 = _T("");
	m_strID = _T("");
	//}}AFX_DATA_INIT
}


void CUpdatePwdDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUpdatePwdDlg)
	DDX_Text(pDX, IDC_PWD1, m_strPwd1);
	DDX_Text(pDX, IDC_PWD2, m_strPwd2);
	DDX_Text(pDX, IDC_ID, m_strID);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUpdatePwdDlg, CDialog)
	//{{AFX_MSG_MAP(CUpdatePwdDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUpdatePwdDlg message handlers

void CUpdatePwdDlg::OnOK() 
{
	UpdateData();
	if(m_strPwd1 != m_strPwd2)
	{
		MessageBox("请输入密码！");
		return ;
	}
	if(m_strPwd1 != m_strPwd2)
	{
		MessageBox("两次密码输入的不一致！");
		return ;
	}
	CString strSQL;
	strSQL.Format("update users set pwd = '%s' where users = '%s'", m_strPwd1, theApp.m_strUser);
	try
	{
		theApp.m_pConnection->Execute((_bstr_t)strSQL, NULL, adCmdText);
		MessageBox("修改成功");
	}
	CATCH_ERROR;
	CDialog::OnOK();
}

BOOL CUpdatePwdDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_strID = theApp.m_strUser;
	m_pRecordset.CreateInstance("ADODB.Recordset");	
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
