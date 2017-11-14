// FlashListCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "mtas.h"
#include "FlashListCtrl.h"
#include "mainfrm.h"
#include "MTASView.h"
#include "MTASDoc.h"
#include "FlashView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFlashListCtrl

CFlashListCtrl::CFlashListCtrl()
{
}

CFlashListCtrl::~CFlashListCtrl()
{
}

void CFlashListCtrl::UpdateDisplay()
{
	DeleteAllItems();
	FillListCtrl(_T("SELECT * FROM `cw` WHERE `TYPE`='swf'"));
}


BEGIN_MESSAGE_MAP(CFlashListCtrl, CMyListCtrl)
	//{{AFX_MSG_MAP(CFlashListCtrl)
	ON_NOTIFY_REFLECT(NM_RCLICK, OnRclick)
	ON_COMMAND(IDR_ADD_FLASH, OnAddFlash)
	ON_COMMAND(IDR_DEL_FLASH, OnDelFlash)
	ON_COMMAND(IDR_OPEN_FLASH, OnOpenFlash)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_CREATE()
	ON_NOTIFY_REFLECT(LVN_COLUMNCLICK, OnColumnclick)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(IDR_DIR_FLASH, OnDirFlash)
	ON_COMMAND(ID_ADD_FLASHS, OnAddFlashs)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFlashListCtrl message handlers

void CFlashListCtrl::OnRclick(NMHDR* pNMHDR, LRESULT* pResult) 
{
	CMyListCtrl::OnRclick(pNMHDR, pResult);

	int nItem = GetNextItem(-1, LVNI_SELECTED);
	CMainFrame* pMainWnd = (CMainFrame*)AfxGetMainWnd();
	CMTASDoc* pDoc = (CMTASDoc*)pMainWnd->GetActiveDocument();
	pDoc->m_bListSelected = (nItem == -1 ? FALSE : TRUE);
	pDoc->m_pListCtrlSelected = (nItem == -1 ? NULL : this);	

	CPoint pt;
	GetCursorPos(&pt);
	m_listMenu.GetSubMenu(1)->TrackPopupMenu(TPM_LEFTALIGN, pt.x, pt.y, this);	

	*pResult = 0;
}

void CFlashListCtrl::OnAddFlash()
{
	AddCourseware();
}

void CFlashListCtrl::OnDelFlash() 
{
	DeleteCourseware();
}

void CFlashListCtrl::OnOpenFlash() 
{
	OpenCourseware();
}

void CFlashListCtrl::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	OpenCourseware();

	CMyListCtrl::OnLButtonDblClk(nFlags, point);
}

int CFlashListCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CMyListCtrl::OnCreate(lpCreateStruct) == -1)
		return -1;
	m_listMenu.LoadToolBar(IDR_TOOLBAR_FOR_FLASHLIST);

	HICON  hFlashIcon;
	// Set up the image list.	
    hFlashIcon = reinterpret_cast<HICON>(
					::LoadImage ( AfxGetResourceHandle(), MAKEINTRESOURCE(IDI_FLASH_FILE),
                              IMAGE_ICON, 16, 16, LR_DEFAULTCOLOR ));

    m_imglist.Add(hFlashIcon);
    SetImageList ( &m_imglist, LVSIL_SMALL );
	
	return 0;
}

void CFlashListCtrl::OnColumnclick(NMHDR* pNMHDR, LRESULT* pResult) 
{
	CMyListCtrl::OnColumnclick(pNMHDR, pResult);

	CString sql, strSort;
	sql.Format(_T("SELECT * FROM `cw` WHERE `TYPE`='swf'")); 
	strSort.Format(_T("%s %s"), m_strLastClick, m_bAsc ? _T("") : _T("DESC"));
	DeleteAllItems();
	FillListCtrl(sql, strSort);
	
	*pResult = 0;
}

void CFlashListCtrl::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CMyListCtrl::OnLButtonDown(nFlags, point);

	int nItem = GetNextItem(-1, LVNI_SELECTED);
	CMainFrame* pMainWnd = (CMainFrame*)AfxGetMainWnd();
	CMTASDoc* pDoc = (CMTASDoc*)pMainWnd->GetActiveDocument();
	pDoc->m_bListSelected = (nItem == -1 ? FALSE : TRUE);
	pDoc->m_pListCtrlSelected = (nItem == -1 ? NULL : this);	
}

void CFlashListCtrl::OnDirFlash() 
{
	OpenCoursewareDir();
}

void CFlashListCtrl::OnAddFlashs() 
{
	AddMutiCourseware();
}
