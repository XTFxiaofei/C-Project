// DlgProperties.cpp : implementation file
//

#include "stdafx.h"
#include "MTAS.h"
#include "DlgProperties.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgProperties dialog


CDlgProperties::CDlgProperties(CWnd* pParent /*=NULL*/)
	: CNewDialog(CDlgProperties::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgProperties)
	//}}AFX_DATA_INIT
}


void CDlgProperties::DoDataExchange(CDataExchange* pDX)
{
	CNewDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgProperties)
	DDX_Control(pDX, IDCANCEL, m_btnCancel);
	DDX_Control(pDX, IDOK, m_btnOk);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgProperties, CNewDialog)
	//{{AFX_MSG_MAP(CDlgProperties)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgProperties message handlers

BOOL CDlgProperties::OnInitDialog() 
{
	CNewDialog::OnInitDialog();

	short shBtnColor = 30;
	m_btnOk.SetIcon(IDI_OK);
	m_btnOk.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, shBtnColor);
	m_btnOk.SetRounded(TRUE);
	m_btnCancel.SetIcon(IDI_CANCEL, 15, 15);
	m_btnCancel.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, shBtnColor);
	m_btnCancel.SetRounded(TRUE);

	GetDlgItem(IDC_LABELED)->SetWindowText(m_sLabel);
	GetDlgItem(IDC_TOOLTIPED)->SetWindowText(m_sTooltip);
	GetDlgItem(IDC_URLED)->SetWindowText(m_sUrl);
	return TRUE;
}

void CDlgProperties::OnOK() 
{
	GetDlgItem(IDC_LABELED)->GetWindowText(m_sLabel);
	GetDlgItem(IDC_TOOLTIPED)->GetWindowText(m_sTooltip);
	GetDlgItem(IDC_URLED)->GetWindowText(m_sUrl);
	CNewDialog::OnOK();
}
