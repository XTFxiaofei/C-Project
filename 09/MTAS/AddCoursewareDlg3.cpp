// AddCoursewareDlg3.cpp : implementation file
//

#include "stdafx.h"
#include "mtas.h"
#include "AddCoursewareDlg3.h"
#include <vector>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddCoursewareDlg3 dialog


CAddCoursewareDlg3::CAddCoursewareDlg3(CWnd* pParent /*=NULL*/)
	: CNewDialog(CAddCoursewareDlg3::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddCoursewareDlg3)
	m_strChapter = _T("");
	m_strClass = _T("");
	m_strSection = _T("");
	//}}AFX_DATA_INIT
	m_rsClass.SetDatabase(&theDB);
	m_rsChapter.SetDatabase(&theDB);
	m_rsSection.SetDatabase(&theDB);
	m_vecCwi.clear();
}


void CAddCoursewareDlg3::DoDataExchange(CDataExchange* pDX)
{
	CNewDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddCoursewareDlg3)
	DDX_Control(pDX, IDC_BUTTON_DELETE, m_btnDel);
	DDX_Control(pDX, IDCANCEL, m_btnCancel);
	DDX_Control(pDX, IDOK, m_btnOk);
	DDX_Control(pDX, IDC_BUTTON_BROWSE, m_btnBrowse);
	DDX_Text(pDX, IDC_EDIT_CHAPTER, m_strChapter);
	DDX_Text(pDX, IDC_EDIT_CLASS, m_strClass);
	DDX_Text(pDX, IDC_EDIT_SECTION, m_strSection);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddCoursewareDlg3, CNewDialog)
	//{{AFX_MSG_MAP(CAddCoursewareDlg3)
	ON_BN_CLICKED(IDC_BUTTON_BROWSE, OnButtonBrowse)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddCoursewareDlg3 message handlers

void CAddCoursewareDlg3::OnOK() 
{
	m_vecCwi.clear();
	m_vecCwi = m_listCourseware.m_vecCwi;
	
	CNewDialog::OnOK();
}

void CAddCoursewareDlg3::OnButtonBrowse() 
{
	UpdateData();
	static char BASED_CODE szFilter[] = "PowerPoint Files (*.ppt)|*.ppt|Flash Files (*.swf)|*.swf|Word Files (*.doc)|*.doc; *.ppt|All Files (*.*)|*.*||";
	CFileDialog dlg(TRUE, NULL, NULL, OFN_ALLOWMULTISELECT | OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, NULL);  
	DWORD  MAXFILE = 2562;   //2562   is   the   max  
	dlg.m_ofn.nMaxFile = MAXFILE;  
	TCHAR  szFile[2562];  
	dlg.m_ofn.lpstrFile = szFile;  
	dlg.m_ofn.lpstrFile[0] = NULL;  

	if(dlg.DoModal() != IDOK) 
		return;

	vector<CCourseWareInfo> vecCwi;
	POSITION  pos = dlg.GetStartPosition();  
	while(pos) { 
		CCourseWareInfo cwi;
		cwi.m_strPath = dlg.GetNextPathName(pos);
		cwi.m_strName = GetFileNameFromPath(cwi.m_strPath);
		cwi.m_strType = GetFileExtFromPath(cwi.m_strPath);
		cwi.m_strClass = (m_strClass == _T("") ? _T("未指定") : m_strClass);
		cwi.m_strChapter = (m_strChapter == _T("") ? _T("未指定") : m_strChapter);
		cwi.m_strSection = (m_strSection == _T("") ? _T("未指定") : m_strSection);
		CFileStatus rStatus;
		CFile::GetStatus(cwi.m_strPath, rStatus);
		cwi.m_lSize = rStatus.m_size;		
		cwi.m_strModTime = rStatus.m_mtime.Format(_T("%Y-%m-%d  %H:%M:%S"));
		vecCwi.push_back(cwi);		
	}   
	m_listCourseware.DeleteAllItems();
	m_listCourseware.FillListCtrl(vecCwi);
}

BOOL CAddCoursewareDlg3::OnInitDialog() 
{
	CNewDialog::OnInitDialog();
	
	short shBtnColor = 30;
	m_btnOk.SetIcon(IDI_OK);
	m_btnOk.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, shBtnColor);
	m_btnOk.SetRounded(TRUE);
	m_btnCancel.SetIcon(IDI_CANCEL, 15, 15);
	m_btnCancel.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, shBtnColor);
	m_btnCancel.SetRounded(TRUE);
	m_btnBrowse.SetIcon(IDI_ADD);
	m_btnBrowse.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, shBtnColor);
	m_btnBrowse.SetRounded(TRUE);
	m_btnDel.SetIcon(IDI_SUB);
	m_btnDel.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, shBtnColor);
	m_btnDel.SetRounded(TRUE);


	CRect rtcb, rtbtn, rt;
	GetDlgItem(IDC_EDIT_SECTION)->GetWindowRect(rtcb);
	ScreenToClient(rtcb);
	int x = 20, y = rtcb.bottom + 10;
	GetDlgItem(IDOK)->GetWindowRect(rtbtn);
	ScreenToClient(rtbtn);
	GetClientRect(rt);
	int width = rt.Width() - 40, height = rtbtn.top - rtcb.bottom - 20;
	m_listCourseware.MoveWindow(x, y, width, height);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


CString CAddCoursewareDlg3::GetFileNameFromPath(const CString &strFilePath)
{
	return strFilePath.Right(strFilePath.GetLength()-strFilePath.ReverseFind(_T('\\'))-1);
}

CString CAddCoursewareDlg3::GetFileExtFromPath(const CString &strFilePath)
{
	return strFilePath.Right(strFilePath.GetLength()-strFilePath.ReverseFind(_T('.'))-1);
}

int CAddCoursewareDlg3::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CNewDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if( !m_listCourseware.Create(WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN |
		 LVS_REPORT | LVS_SHOWSELALWAYS, CRect(0, 0, 0, 0), this, 968) )
		return -1;
	m_listCourseware.InitListCtrl();

	return 0;
}

void CAddCoursewareDlg3::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	CRect rt;
	m_listCourseware.GetWindowRect(rt);
	ScreenToClient(rt);

	dc.SetBkMode(TRANSPARENT);
	CPen pen (PS_SOLID, 0, RGB (166, 166, 166));
	CPen* pOldPen = dc.SelectObject (&pen);
	CBrush brush;
	brush.CreateStockObject(NULL_BRUSH);
	CBrush* pOldBrush = (CBrush*)dc.SelectObject(&brush);

	dc.Rectangle(rt.left-1, rt.top-1, rt.left + rt.Width()+1, rt.top + rt.Height()+1);
}

void CAddCoursewareDlg3::OnButtonDelete() 
{
	
	::SendMessage(m_listCourseware.m_hWnd, WM_KEYDOWN, VK_DELETE, 0);	
}
