// AddCourseWareDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mtas.h"
#include "AddCourseWareDlg.h"
#include <map>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddCourseWareDlg dialog


CAddCourseWareDlg::CAddCourseWareDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAddCourseWareDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddCourseWareDlg)
	m_strName = _T("");
	m_strPath = _T("");
	m_strType = _T("");
	//}}AFX_DATA_INIT
}


void CAddCourseWareDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddCourseWareDlg)
	DDX_Control(pDX, IDCANCEL, m_btnCancel);
	DDX_Control(pDX, IDADD, m_btnAdd);
	DDX_Control(pDX, IDC_BROWSE, m_btnBrowse);
	DDX_Control(pDX, IDC_COMBO_SECTION, m_cbSection);
	DDX_Control(pDX, IDC_COMBO_CHAPTER, m_cbChapter);
	DDX_Control(pDX, IDC_COMBO_CLASS, m_cbClass);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_PATH, m_strPath);
	DDX_Text(pDX, IDC_EDIT_TYPE, m_strType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddCourseWareDlg, CDialog)
	//{{AFX_MSG_MAP(CAddCourseWareDlg)
	ON_BN_CLICKED(IDC_BROWSE, OnBrowse)
	ON_BN_CLICKED(IDADD, OnAdd)
	ON_CBN_SELCHANGE(IDC_COMBO_CLASS, OnSelchangeComboClass)
	ON_CBN_SELCHANGE(IDC_COMBO_CHAPTER, OnSelchangeComboChapter)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddCourseWareDlg message handlers

void CAddCourseWareDlg::OnBrowse() 
{
	CFileDialog dlg(TRUE);
	if(dlg.DoModal() != IDOK)
		return;

	m_strPath = dlg.GetPathName();
	m_strName = dlg.GetFileName();
	m_strType = dlg.GetFileExt();
	m_strType.MakeLower();
	UpdateData(FALSE);

	CFileStatus rStatus;
	CFile::GetStatus(m_strPath, rStatus);
	m_cwi.m_lSize = rStatus.m_size;	
	m_cwi.m_strModTime = rStatus.m_mtime.Format(_T("%Y-%M-%d, %H:%M"));
}

void CAddCourseWareDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CAddCourseWareDlg::OnAdd() 
{
	if(m_strPath.IsEmpty() || m_strName.IsEmpty() || m_strType.IsEmpty()) {
		MessageBox(_T("请选择要添加的课件!"), _T("错误!"), MB_ICONEXCLAMATION);
		return;
	}

	int nClass = m_cbClass.GetCurSel();
	int nChapter = m_cbChapter.GetCurSel();
	int nSection = m_cbSection.GetCurSel();
	if(nClass == CB_ERR || nChapter == CB_ERR || nSection == CB_ERR) {
		MessageBox(_T("请选择相应课程与章节!"), _T("错误!"), MB_ICONEXCLAMATION);
		return;
	}

	m_cwi.m_strName = m_strName;
	m_cwi.m_strPath = m_strPath;
	m_cwi.m_strType = m_strType;
	m_cbClass.GetLBText(nClass, m_cwi.m_strClass);
	m_cbChapter.GetLBText(nChapter, m_cwi.m_strChapter);
	m_cbSection.GetLBText(nSection, m_cwi.m_strSection);
		
	CDialog::OnOK();
}

CCourseWareInfo CAddCourseWareDlg::GetCourseWare() const
{
	return m_cwi;
}

BOOL CAddCourseWareDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	short shBtnColor = 30;
	m_btnAdd.SetIcon(IDI_ADD, 17, 17);
	m_btnAdd.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, shBtnColor);
	m_btnAdd.SetRounded(TRUE);
	m_btnCancel.SetIcon(IDI_CANCEL, 15, 15);
	m_btnCancel.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, shBtnColor);
	m_btnCancel.SetRounded(TRUE);
	m_btnBrowse.SetIcon(IDI_BROWSE);
	m_btnBrowse.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, shBtnColor);
	m_btnBrowse.SetRounded(TRUE);

	CClassRecordset   rsClass(&theDB);
	CChapterRecordset rsChapter(&theDB);
	CSectionRecordset rsSection(&theDB);
	
	CString strSQL;
	strSQL.Format(_T("SELECT * FROM class"));
	vector<ClassTableItem> vecCTI;
	rsClass.Query(strSQL, vecCTI);
	for(int i = 0; i < vecCTI.size(); ++i) 
		m_cbClass.AddString(vecCTI[i].m_strName);
	
	m_cbChapter.EnableWindow(FALSE);
	m_cbSection.EnableWindow(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAddCourseWareDlg::OnSelchangeComboClass() 
{
	m_cbChapter.EnableWindow();
	m_cbChapter.ResetContent();

	CString strClassSel;
	m_cbClass.GetLBText(m_cbClass.GetCurSel(), strClassSel);

	CClassRecordset   rsClass(&theDB);
	CChapterRecordset rsChapter(&theDB);
	long lClassID = rsClass.GetClassID(strClassSel);
	CString strSQL;
	strSQL.Format(_T("SELECT * FROM chapter WHERE classid=%ld"), lClassID);
	vector<ChapterTableItem> vecCTI;
	rsChapter.Query(strSQL, vecCTI);

	for(int i = 0; i < vecCTI.size(); ++i) 
		m_cbChapter.AddString(vecCTI[i].m_strName);
}

void CAddCourseWareDlg::OnSelchangeComboChapter() 
{
	m_cbSection.EnableWindow();
	m_cbSection.ResetContent();

	CString strClassSel;
	m_cbClass.GetLBText(m_cbClass.GetCurSel(), strClassSel);
	CString strChapterSel;
	m_cbChapter.GetLBText(m_cbChapter.GetCurSel(), strChapterSel);

	CClassRecordset   rsClass(&theDB);
	CChapterRecordset rsChapter(&theDB);
	CSectionRecordset rsSection(&theDB);
	long lClassID = rsClass.GetClassID(strClassSel);
	long lChapterID = rsChapter.GetChapterID(lClassID, strChapterSel);
	CString strSQL;
	strSQL.Format(_T("SELECT * FROM section WHERE chapterid=%ld"), lChapterID);
	vector<SectionTableItem> vecSTI;
	rsSection.Query(strSQL, vecSTI);

	for(int i = 0; i < vecSTI.size(); ++i) 
		m_cbSection.AddString(vecSTI[i].m_strName);
}
