// AddChapterDlg2.cpp : implementation file
//

#include "stdafx.h"
#include "mtas.h"
#include "AddChapterDlg2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddChapterDlg2 dialog


CAddChapterDlg2::CAddChapterDlg2(CWnd* pParent /*=NULL*/)
	: CNewDialog(CAddChapterDlg2::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddChapterDlg2)
	m_strChapterName = _T("");
	//}}AFX_DATA_INIT
	m_strClassName = _T("");
}


void CAddChapterDlg2::DoDataExchange(CDataExchange* pDX)
{
	CNewDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddChapterDlg2)
	DDX_Control(pDX, IDC_COMBO_CLASS, m_cbClass);
	DDX_Control(pDX, IDCANCEL, m_btnCancel);
	DDX_Control(pDX, IDADD, m_btnAdd);
	DDX_Text(pDX, IDC_EDIT_CHAPTER, m_strChapterName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddChapterDlg2, CNewDialog)
	//{{AFX_MSG_MAP(CAddChapterDlg2)
	ON_BN_CLICKED(IDADD, OnAdd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddChapterDlg2 message handlers

BOOL CAddChapterDlg2::OnInitDialog() 
{
	CClassRecordset rsClass(&theDB);
	vector<ClassTableItem> vecCti;
	rsClass.Query(_T("SELECT * FROM `class`"), vecCti);
	if(vecCti.size() == 0) {
		MessageBox(_T("该系统尚未添加任何课程，请先添加课程"), _T("错误!"), MB_ICONEXCLAMATION);
		return FALSE;
	}
	CNewDialog::OnInitDialog();
	
	short shBtnColor = 30;
	m_btnAdd.SetIcon(IDI_ADD, 17, 17);
	m_btnAdd.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, shBtnColor);
	m_btnAdd.SetRounded(TRUE);
	m_btnCancel.SetIcon(IDI_CANCEL, 15, 15);
	m_btnCancel.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, shBtnColor);
	m_btnCancel.SetRounded(TRUE);

	for(vector<ClassTableItem>::iterator iter = vecCti.begin();
			iter != vecCti.end(); ++iter)
	{
		m_cbClass.AddString(iter->m_strName);
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAddChapterDlg2::OnAdd() 
{
	UpdateData();

	TCHAR szBuf[255];
	m_cbClass.GetLBText(m_cbClass.GetCurSel(), szBuf);
	m_strClassName = szBuf;
	if(m_strClassName.IsEmpty() || m_strChapterName.IsEmpty()) {
		MessageBox(_T("填写的信息不完整!"), _T("错误!"), MB_ICONEXCLAMATION);
		return;
	}

	CNewDialog::OnOK();
}
