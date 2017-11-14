// DllTestView.cpp : implementation of the CDllTestView class
//

#include "stdafx.h"
#include "DllTest.h"

#include "DllTestDoc.h"
#include "DllTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern "C" __declspec(dllimport) void dllEntry();
/////////////////////////////////////////////////////////////////////////////
// CDllTestView

IMPLEMENT_DYNCREATE(CDllTestView, CView)

BEGIN_MESSAGE_MAP(CDllTestView, CView)
	//{{AFX_MSG_MAP(CDllTestView)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDllTestView construction/destruction

CDllTestView::CDllTestView()
{
	// TODO: add construction code here
	dllEntry();
}

CDllTestView::~CDllTestView()
{
}

BOOL CDllTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDllTestView drawing

void CDllTestView::OnDraw(CDC* pDC)
{
	CDllTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->TextOut(10, 10, "bigbug");
}

/////////////////////////////////////////////////////////////////////////////
// CDllTestView diagnostics

#ifdef _DEBUG
void CDllTestView::AssertValid() const
{
	CView::AssertValid();
}

void CDllTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDllTestDoc* CDllTestView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDllTestDoc)));
	return (CDllTestDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDllTestView message handlers

int CDllTestView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_wndTest.Create(_T("OutlookTabCtrl"), _T("OutlookTabControl"), 
		WS_CHILD | WS_VISIBLE | WS_THICKFRAME | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,
		CRect(100, 10, 350, 400), this, 100, NULL);
		
	return 0;
}
