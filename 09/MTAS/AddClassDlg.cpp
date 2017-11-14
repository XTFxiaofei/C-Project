// AddClassDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mtas.h"
#include "AddClassDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddClassDlg dialog


CAddClassDlg::CAddClassDlg(CWnd* pParent /*=NULL*/)
	: CNewDialog(CAddClassDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddClassDlg)
	m_strClassName = _T("");
	//}}AFX_DATA_INIT
}


void CAddClassDlg::DoDataExchange(CDataExchange* pDX)
{
	CNewDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddClassDlg)
	DDX_Control(pDX, IDCANCEL, m_btnCancel);
	DDX_Control(pDX, IDADD, m_btnAdd);
	DDX_Text(pDX, IDC_EDIT_CLASS_NAME, m_strClassName);
	DDV_MaxChars(pDX, m_strClassName, 255);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddClassDlg, CNewDialog)
	//{{AFX_MSG_MAP(CAddClassDlg)
	ON_BN_CLICKED(IDADD, OnAdd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddClassDlg message handlers

BOOL CAddClassDlg::OnInitDialog() 
{
	CNewDialog::OnInitDialog();
	
	short shBtnColor = 30;
	m_btnAdd.SetIcon(IDI_ADD, 17, 17);
	m_btnAdd.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, shBtnColor);
	m_btnAdd.SetRounded(TRUE);
	m_btnCancel.SetIcon(IDI_CANCEL, 15, 15);
	m_btnCancel.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, shBtnColor);
	m_btnCancel.SetRounded(TRUE);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAddClassDlg::OnAdd() 
{
	UpdateData();
	if(m_strClassName.IsEmpty()) {
		MessageBox(_T("填写的信息不完整!"), _T("错误!"), MB_ICONEXCLAMATION);
		return;
	}

	CNewDialog::OnOK();
}
