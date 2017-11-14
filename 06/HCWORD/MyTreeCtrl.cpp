// MyTreeCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "HCWORD.h"
#include "MyTreeCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyTreeCtrl

CMyTreeCtrl::CMyTreeCtrl()
{
}

CMyTreeCtrl::~CMyTreeCtrl()
{
}


BEGIN_MESSAGE_MAP(CMyTreeCtrl, CTreeCtrl)
	//{{AFX_MSG_MAP(CMyTreeCtrl)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_NOTIFY_REFLECT(TVN_ITEMEXPANDED, OnItemexpanded)
	ON_NOTIFY_REFLECT(TVN_ITEMEXPANDING, OnItemexpanding)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyTreeCtrl message handlers
BOOL CMyTreeCtrl::SetBKImage(LPCTSTR LpszResource)
{

	// if this is not the first call then delete gdi objects
	if( m_bitmap.m_hObject != NULL )
		m_bitmap.DeleteObject();
	
	HBITMAP hbmp = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), 
			LpszResource, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION|LR_LOADFROMFILE);


	if( hbmp == NULL ) 
		return FALSE;

	m_bitmap.Attach( hbmp );
	
	return TRUE;
}
void CMyTreeCtrl::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	CRect rcclient;
	GetClientRect(&rcclient);

	// create a compatible memory dc 
	CDC memdc;
	memdc.CreateCompatibleDC(&dc);	
	CBitmap bitmap;
	bitmap.CreateCompatibleBitmap(&dc, rcclient.Width(), rcclient.Height());
	memdc.SelectObject( &bitmap );

	CWnd::DefWindowProc(WM_PAINT, (WPARAM)memdc.m_hDC , 0);

	CDC maskdc;
	maskdc.CreateCompatibleDC(&dc);
	CBitmap maskbitmap;
	maskbitmap.CreateBitmap(rcclient.Width(), rcclient.Height(), 1, 1, NULL);
	maskdc.SelectObject( &maskbitmap );
	maskdc.BitBlt( 0, 0, rcclient.Width(), rcclient.Height(), &memdc, 
		rcclient.left, rcclient.top, SRCCOPY);

	CBrush brush;
	brush.CreatePatternBrush(&m_bitmap);
	dc.FillRect(rcclient, &brush);	
	
	memdc.SetBkColor(RGB(12,34,44));          
	memdc.SetTextColor(RGB(3,253,25));  
	memdc.BitBlt(rcclient.left, rcclient.top, rcclient.Width(), rcclient.Height(), &maskdc, rcclient.left, rcclient.top, SRCAND);	

	dc.SetBkColor(RGB(34,245,25));
	dc.SetTextColor(RGB(67,0,0));
	dc.BitBlt(rcclient.left, rcclient.top, rcclient.Width(), rcclient.Height(), &maskdc, rcclient.left, rcclient.top, SRCAND);
	
	dc.BitBlt(rcclient.left, rcclient.top, rcclient.Width(), rcclient.Height(), &memdc, 
					rcclient.left, rcclient.top,SRCPAINT);
	brush.DeleteObject();
	// Do not call CTreeCtrl::OnPaint() for painting messages
}

BOOL CMyTreeCtrl::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	
	return CTreeCtrl::OnEraseBkgnd(pDC);
}

void CMyTreeCtrl::OnItemexpanded(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	Invalidate();
	SetRedraw(TRUE);
	*pResult = 0;
}

void CMyTreeCtrl::OnItemexpanding(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	SetRedraw(FALSE);

	*pResult = 0;
}

LRESULT CMyTreeCtrl::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CTreeCtrl::WindowProc(message, wParam, lParam);
}
