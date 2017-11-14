// AddCoursewareDlg1.cpp : implementation file
//

#include "stdafx.h"
#include "mtas.h"
#include "AddCoursewareDlg1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddCoursewareDlg dialog


CAddCoursewareDlg::CAddCoursewareDlg(CWnd* pParent /*=NULL*/)
	: CNewDialog(CAddCoursewareDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddCoursewareDlg)
	m_strChapter = _T("");
	m_strClass = _T("");
	m_strModTime = _T("");
	m_strName = _T("");
	m_strPath = _T("");
	m_strSection = _T("");
	m_strSize = _T("");
	m_strType = _T("");
	//}}AFX_DATA_INIT
}


void CAddCoursewareDlg::DoDataExchange(CDataExchange* pDX)
{
	CNewDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddCoursewareDlg)
	DDX_Control(pDX, IDCANCEL, m_btnCancel);
	DDX_Control(pDX, IDC_BROWSE, m_btnBrowse);
	DDX_Control(pDX, IDADD, m_btnAdd);
	DDX_Text(pDX, IDC_EDIT_CHAPTER, m_strChapter);
	DDX_Text(pDX, IDC_EDIT_CLASS, m_strClass);
	DDX_Text(pDX, IDC_EDIT_MODTIME, m_strModTime);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_PATH, m_strPath);
	DDX_Text(pDX, IDC_EDIT_SECTION, m_strSection);
	DDX_Text(pDX, IDC_EDIT_SIZE, m_strSize);
	DDX_Text(pDX, IDC_EDIT_TYPE, m_strType);
	DDX_Control(pDX, IDC_EXPLORER, m_webbrowser);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddCoursewareDlg, CNewDialog)
	//{{AFX_MSG_MAP(CAddCoursewareDlg)
	ON_BN_CLICKED(IDADD, OnAdd)
	ON_BN_CLICKED(IDC_BROWSE, OnBrowse)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddCoursewareDlg message handlers

void CAddCoursewareDlg::OnAdd() 
{
	UpdateData();
	if(m_strPath.IsEmpty()) {
		MessageBox(_T("请选择课件路径!"), _T("错误!"), MB_ICONEXCLAMATION);
		return;
	}
	
	if(m_strClass.IsEmpty()) {
		m_strClass = _T("未指定");
	}
	if(m_strChapter.IsEmpty()) {
		m_strChapter = _T("未指定");
	}
	if(m_strSection.IsEmpty()) {
		m_strSection = _T("未指定");
	}

	m_cwi.m_strName = m_strName;
	m_cwi.m_strPath = m_strPath;
	m_cwi.m_strType = m_strType;
	m_cwi.m_lSize   = m_lSize;
	m_cwi.m_strModTime = m_strModTime;
	m_cwi.m_strClass   = m_strClass;
	m_cwi.m_strChapter = m_strChapter;
	m_cwi.m_strSection = m_strSection;
		
	CNewDialog::OnOK();
}

void CAddCoursewareDlg::OnBrowse() 
{
	static char BASED_CODE szFilter[] = "PowerPoint Files (*.ppt)|*.ppt|Flash Files (*.swf)|*.swf|Word Files (*.doc)|*.doc; *.ppt|All Files (*.*)|*.*||";
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, NULL); 
	if(dlg.DoModal() != IDOK)
		return;

	UpdateData();
	m_strPath = dlg.GetPathName();
	m_strName = dlg.GetFileName();
	m_strType = dlg.GetFileExt();
	m_strType.MakeLower(); 
	CFileStatus rStatus;
	CFile::GetStatus(m_strPath, rStatus);
	m_strSize.Format(_T("%ldk"), rStatus.m_size / 1024);
	m_strModTime = rStatus.m_mtime.Format(_T("%Y-%m-%d  %H:%M:%S"));
	m_lSize = rStatus.m_size;		
	UpdateData(FALSE);

	COleVariant vURL(m_strPath, VT_BSTR);		
	m_webbrowser.Navigate2(vURL, 0, 0, 0, 0);
}

BOOL CAddCoursewareDlg::OnInitDialog() 
{
	CNewDialog::OnInitDialog();
	
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

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
