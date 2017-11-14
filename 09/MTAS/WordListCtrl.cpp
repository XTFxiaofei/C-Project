// WordListCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "mtas.h"
#include "WordListCtrl.h"
#include "MTASDoc.h"
#include "WordView.h"
#include "mainfrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWordListCtrl

CWordListCtrl::CWordListCtrl()
{
}

CWordListCtrl::~CWordListCtrl()
{
}

void CWordListCtrl::UpdateDisplay()
{
	DeleteAllItems();
	FillListCtrl(_T("SELECT * FROM `cw` WHERE `TYPE`='doc' OR `TYPE`='txt'"));
}

BEGIN_MESSAGE_MAP(CWordListCtrl, CMyListCtrl)
	//{{AFX_MSG_MAP(CWordListCtrl)
	ON_NOTIFY_REFLECT(NM_RCLICK, OnRclick)
	ON_COMMAND(IDR_OPEN_WORD, OnOpenWord)
	ON_COMMAND(IDR_ADD_WORD, OnAddWord)
	ON_COMMAND(IDR_DEL_WORD, OnDelWord)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_CREATE()
	ON_NOTIFY_REFLECT(LVN_COLUMNCLICK, OnColumnclick)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(IDR_DIR_WORD, OnDirWord)
	ON_COMMAND(ID_ADD_WORDS, OnAddWords)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWordListCtrl message handlers

void CWordListCtrl::OnRclick(NMHDR* pNMHDR, LRESULT* pResult) 
{
	CMyListCtrl::OnRclick(pNMHDR, pResult);

	int nItem = GetNextItem(-1, LVNI_SELECTED);
	CMainFrame* pMainWnd = (CMainFrame*)AfxGetMainWnd();
	CMTASDoc* pDoc = (CMTASDoc*)pMainWnd->GetActiveDocument();
	pDoc->m_bListSelected = (nItem == -1 ? FALSE : TRUE);
	pDoc->m_pListCtrlSelected = (nItem == -1 ? NULL : this);	

	CPoint pt;
	GetCursorPos(&pt);
	m_listMenu.GetSubMenu(2)->TrackPopupMenu(TPM_LEFTALIGN, pt.x, pt.y, this);	
	
	*pResult = 0;
}

void CWordListCtrl::OnOpenWord() 
{
	OpenCourseware();
}

void CWordListCtrl::OnAddWord() 
{
	AddCourseware();
}

void CWordListCtrl::OnDelWord() 
{
	DeleteCourseware();
}

void CWordListCtrl::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	OpenCourseware();
	
	CMyListCtrl::OnLButtonDblClk(nFlags, point);
}

int CWordListCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CMyListCtrl::OnCreate(lpCreateStruct) == -1)
		return -1;
	m_listMenu.LoadToolBar(IDR_TOOLBAR_FOR_WORDLIST);

	HICON  hWordIcon;
	// Set up the image list.	
    hWordIcon = reinterpret_cast<HICON>(
					::LoadImage ( AfxGetResourceHandle(), MAKEINTRESOURCE(IDI_WORD_FILE),
                              IMAGE_ICON, 16, 16, LR_DEFAULTCOLOR ));

    m_imglist.Add(hWordIcon);
    SetImageList(&m_imglist, LVSIL_SMALL);	

	return 0;
}

void CWordListCtrl::OnColumnclick(NMHDR* pNMHDR, LRESULT* pResult) 
{
	CMyListCtrl::OnColumnclick(pNMHDR, pResult);

	CString sql, strSort;
	sql.Format(_T("SELECT * FROM `cw` WHERE `TYPE`='doc' OR `TYPE`='txt'")); 
	strSort.Format(_T("%s %s"), m_strLastClick, m_bAsc ? _T("") : _T("DESC"));
	DeleteAllItems();
	FillListCtrl(sql, strSort);
	
	*pResult = 0;
}

void CWordListCtrl::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CMyListCtrl::OnLButtonDown(nFlags, point);

	int nItem = GetNextItem(-1, LVNI_SELECTED);
	CMainFrame* pMainWnd = (CMainFrame*)AfxGetMainWnd();
	CMTASDoc* pDoc = (CMTASDoc*)pMainWnd->GetActiveDocument();
	pDoc->m_bListSelected = (nItem == -1 ? FALSE : TRUE);
	pDoc->m_pListCtrlSelected = (nItem == -1 ? NULL : this);	
}

void CWordListCtrl::OnDirWord() 
{
	OpenCoursewareDir();
}

void CWordListCtrl::OnAddWords() 
{
	AddMutiCourseware();
}
