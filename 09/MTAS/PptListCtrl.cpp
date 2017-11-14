// PptListCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "mtas.h"
#include "PptListCtrl.h"
#include "MTASDoc.h"
#include "PptView.h"
#include "mainfrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPptListCtrl

CPptListCtrl::CPptListCtrl()
{
}

CPptListCtrl::~CPptListCtrl()
{
}

void CPptListCtrl::UpdateDisplay()
{
	DeleteAllItems();
	FillListCtrl(_T("SELECT * FROM `cw` WHERE `TYPE`='ppt'"));
}


BEGIN_MESSAGE_MAP(CPptListCtrl, CMyListCtrl)
	//{{AFX_MSG_MAP(CPptListCtrl)
	ON_NOTIFY_REFLECT(NM_RCLICK, OnRclick)
	ON_COMMAND(IDR_ADD_PPT, OnAddPpt)
	ON_COMMAND(IDR_DEL_PPT, OnDelPpt)
	ON_COMMAND(IDR_OPEN_PPT, OnOpenPpt)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_CREATE()
	ON_NOTIFY_REFLECT(LVN_COLUMNCLICK, OnColumnclick)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(IDR_DIR_PPT, OnDirPpt)
	ON_COMMAND(ID_ADD_PPTS, OnAddPpts)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPptListCtrl message handlers

void CPptListCtrl::OnRclick(NMHDR* pNMHDR, LRESULT* pResult) 
{
	CMyListCtrl::OnRclick(pNMHDR, pResult);

	int nItem = GetNextItem(-1, LVNI_SELECTED);
	CMainFrame* pMainWnd = (CMainFrame*)AfxGetMainWnd();
	CMTASDoc* pDoc = (CMTASDoc*)pMainWnd->GetActiveDocument();
	pDoc->m_bListSelected = (nItem == -1 ? FALSE : TRUE);
	pDoc->m_pListCtrlSelected = (nItem == -1 ? NULL : this);	

	CPoint pt;
	GetCursorPos(&pt);
	m_listMenu.GetSubMenu(0)->TrackPopupMenu(TPM_LEFTALIGN, pt.x, pt.y, this);
	
	*pResult = 0;
}

void CPptListCtrl::OnAddPpt() 
{
	AddCourseware();
}

void CPptListCtrl::OnDelPpt() 
{
	DeleteCourseware();
}

void CPptListCtrl::OnOpenPpt() 
{
	OpenCourseware();
}

void CPptListCtrl::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	OpenCourseware();

	CMyListCtrl::OnLButtonDblClk(nFlags, point);
}

int CPptListCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CMyListCtrl::OnCreate(lpCreateStruct) == -1)
		return -1;
	m_listMenu.LoadToolBar(IDR_TOOLBAR_FOR_PPTLIST);
	
	HICON  hPptIcon;
	// Set up the image list.	
    hPptIcon = reinterpret_cast<HICON>(
					::LoadImage ( AfxGetResourceHandle(), MAKEINTRESOURCE(IDI_PPT_FILE),
                              IMAGE_ICON, 16, 16, LR_DEFAULTCOLOR ));

    m_imglist.Add(hPptIcon);
    SetImageList(&m_imglist, LVSIL_SMALL);	

	return 0;
}

void CPptListCtrl::OnColumnclick(NMHDR* pNMHDR, LRESULT* pResult) 
{
	CMyListCtrl::OnColumnclick(pNMHDR, pResult);

	CString sql, strSort;
	sql.Format(_T("SELECT * FROM `cw` WHERE `TYPE`='ppt'")); 
	strSort.Format(_T("%s %s"), m_strLastClick, m_bAsc ? _T("") : _T("DESC"));
	DeleteAllItems();
	FillListCtrl(sql, strSort);
	
	*pResult = 0;
}

void CPptListCtrl::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CMyListCtrl::OnLButtonDown(nFlags, point);

	int nItem = GetNextItem(-1, LVNI_SELECTED);
	CMainFrame* pMainWnd = (CMainFrame*)AfxGetMainWnd();
	CMTASDoc* pDoc = (CMTASDoc*)pMainWnd->GetActiveDocument();
	pDoc->m_bListSelected = (nItem == -1 ? FALSE : TRUE);
	pDoc->m_pListCtrlSelected = (nItem == -1 ? NULL : this);	
}

void CPptListCtrl::OnDirPpt() 
{
	OpenCoursewareDir();
}

void CPptListCtrl::OnAddPpts() 
{
	AddMutiCourseware();
}
