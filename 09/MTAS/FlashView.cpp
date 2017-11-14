// FlashView.cpp : implementation file
//

#include "stdafx.h"
#include "mtas.h"
#include "MTASDoc.h"
#include "FlashView.h"
#include "mainfrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFlashView

IMPLEMENT_DYNCREATE(CFlashView, CMyView)

CFlashView::CFlashView(BOOL bBlankPage) : CMyView(bBlankPage)
{
	m_bLoad = FALSE;
}

CFlashView::~CFlashView()
{
}


BEGIN_MESSAGE_MAP(CFlashView, CMyView)
	//{{AFX_MSG_MAP(CFlashView)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_SETFOCUS()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFlashView drawing

void CFlashView::OnDraw(CDC* pDC)
{
	CMTASDoc* pDoc = (CMTASDoc*)GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CFlashView diagnostics

#ifdef _DEBUG
void CFlashView::AssertValid() const
{
	CMyView::AssertValid();
}

void CFlashView::Dump(CDumpContext& dc) const
{
	CMyView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFlashView message handlers

#define ID_FLASHWND 666
int CFlashView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CMyView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if(!m_flashWnd.Create(NULL, NULL, WS_CHILD | WS_VISIBLE, 
		CRect(0, 0, 0, 0), this, ID_FLASHWND))
		return -1;

	CMTASDoc* pDoc = (CMTASDoc*)((CMainFrame*)AfxGetMainWnd())->GetActiveDocument();
	pDoc->m_pFlashCtrl = &m_flashWnd;
	
	return 0;
}

void CFlashView::OnSize(UINT nType, int cx, int cy) 
{
	CMyView::OnSize(nType, cx, cy);
	
	m_flashWnd.MoveWindow(0, 0, cx, cy);
}

void CFlashView::OnSetFocus(CWnd* pOldWnd) 
{
	CMyView::OnSetFocus(pOldWnd);
	
	m_flashWnd.SetFocus();
}

void CFlashView::LoadMovie(const CString &strPath)
{
	m_flashWnd.LoadMovie(0, strPath);
	m_flashWnd.StopPlay();
	m_bLoad = TRUE;
}

void CFlashView::Play()
{
	m_flashWnd.Play();
}

void CFlashView::Pause()
{
	m_flashWnd.Stop();
}

void CFlashView::Stop()
{
	m_flashWnd.StopPlay();
}
