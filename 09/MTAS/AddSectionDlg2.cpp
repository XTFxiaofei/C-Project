// AddSectionDlg2.cpp : implementation file
//

#include "stdafx.h"
#include "mtas.h"
#include "AddSectionDlg2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddSectionDlg2 dialog


CAddSectionDlg2::CAddSectionDlg2(CWnd* pParent /*=NULL*/)
	: CNewDialog(CAddSectionDlg2::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddSectionDlg2)
	m_strSectionName = _T("");
	//}}AFX_DATA_INIT
	m_strChapterName = _T("");
	m_strClassName	 = _T("");
}


void CAddSectionDlg2::DoDataExchange(CDataExchange* pDX)
{
	CNewDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddSectionDlg2)
	DDX_Control(pDX, IDCANCEL, m_btnCancel);
	DDX_Control(pDX, IDC_COMBO_CLASS, m_cbClass);
	DDX_Control(pDX, IDC_COMBO_CHAPTER, m_cbChapter);
	DDX_Control(pDX, IDADD, m_btnAdd);
	DDX_Text(pDX, IDC_EDIT_SECTION, m_strSectionName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddSectionDlg2, CNewDialog)
	//{{AFX_MSG_MAP(CAddSectionDlg2)
	ON_BN_CLICKED(IDADD, OnAdd)
	ON_CBN_SELCHANGE(IDC_COMBO_CLASS, OnSelchangeComboClass)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddSectionDlg2 message handlers

BOOL CAddSectionDlg2::OnInitDialog() 
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

void CAddSectionDlg2::OnAdd() 
{
	UpdateData();

	TCHAR szBuf1[255];
	m_cbClass.GetLBText(m_cbClass.GetCurSel(), szBuf1);
	m_strClassName = szBuf1;

	TCHAR szBuf2[255];
	m_cbChapter.GetLBText(m_cbChapter.GetCurSel(), szBuf2);
	m_strChapterName = szBuf2;

	if(m_strClassName.IsEmpty() || m_strChapterName.IsEmpty() || m_strSectionName.IsEmpty()) {
		MessageBox(_T("填写的信息不完整!"), _T("错误!"), MB_ICONEXCLAMATION);
		return;
	}

	CNewDialog::OnOK();
}

void CAddSectionDlg2::OnSelchangeComboClass() 
{
	m_cbChapter.ResetContent();
	TCHAR szBuf[255];
	m_cbClass.GetLBText(m_cbClass.GetCurSel(), szBuf);
	m_strClassName = szBuf;
	if(m_strClassName.IsEmpty())
		return;

	CClassRecordset rsClass(&theDB);
	long lClassID = rsClass.GetClassID(m_strClassName);
	CChapterRecordset rsChapter(&theDB);
	CString strSQL;
	strSQL.Format(_T("SELECT * FROM `chapter` WHERE `classid`=%ld"), lClassID);
	vector<ChapterTableItem> vecCti;
	rsChapter.Query(strSQL, vecCti);
	if(vecCti.size() == 0) {
		MessageBox(_T("该课程尚未添加任何章，请先为该课程添加章"), _T("错误!"), MB_ICONEXCLAMATION);
		return;
	}
	
	for(vector<ChapterTableItem>::iterator iter = vecCti.begin();
			iter != vecCti.end(); ++iter)
	{
		m_cbChapter.AddString(iter->m_strName);
	}
}
