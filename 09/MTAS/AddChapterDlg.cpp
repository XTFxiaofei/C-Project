// AddChapterDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mtas.h"
#include "AddChapterDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddChapterDlg dialog


CAddChapterDlg::CAddChapterDlg(CWnd* pParent /*=NULL*/)
	: CNewDialog(CAddChapterDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddChapterDlg)
	m_strChapterName = _T("");
	m_strClassName   = _T("");
	//}}AFX_DATA_INIT
}


void CAddChapterDlg::DoDataExchange(CDataExchange* pDX)
{
	CNewDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddChapterDlg)
	DDX_Control(pDX, IDC_EDIT_CLASS, m_editClass);
	DDX_Control(pDX, IDCANCEL, m_btnCancel);
	DDX_Control(pDX, IDADD, m_btnAdd);
	DDX_Text(pDX, IDC_EDIT_CHAPTER, m_strChapterName);
	DDX_Text(pDX, IDC_EDIT_CLASS, m_strClassName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddChapterDlg, CNewDialog)
	//{{AFX_MSG_MAP(CAddChapterDlg)
	ON_BN_CLICKED(IDADD, OnAdd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddChapterDlg message handlers

void CAddChapterDlg::OnAdd() 
{
	UpdateData();

	if(m_strChapterName.IsEmpty()) {
		MessageBox(_T("填写的信息不完整!"), _T("错误!"), MB_ICONEXCLAMATION);
		return;
	}

	CNewDialog::OnOK();
}

BOOL CAddChapterDlg::OnInitDialog() 
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
