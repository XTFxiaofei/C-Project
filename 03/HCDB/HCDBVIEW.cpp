// HCDBView.cpp : implementation of the CHCDBView class
//

#include "stdafx.h"
#include "HCDB.h"

#include "HCDBDoc.h"
#include "HCDBView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHCDBView

IMPLEMENT_DYNCREATE(CHCDBView, CView)

BEGIN_MESSAGE_MAP(CHCDBView, CView)
	//{{AFX_MSG_MAP(CHCDBView)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHCDBView construction/destruction

CHCDBView::CHCDBView()
{
	// TODO: add construction code here

}

CHCDBView::~CHCDBView()
{
}

BOOL CHCDBView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CHCDBView drawing

void CHCDBView::OnDraw(CDC* pDC)
{
	CHCDBDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CHCDBView printing

BOOL CHCDBView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CHCDBView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CHCDBView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CHCDBView diagnostics

#ifdef _DEBUG
void CHCDBView::AssertValid() const
{
	CView::AssertValid();
	
}

void CHCDBView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHCDBDoc* CHCDBView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHCDBDoc)));
	return (CHCDBDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHCDBView message handlers
//DEL void CHCDBView::OnLButtonDown(UINT nFlags, CPoint point) 
//DEL {
//DEL 	// TODO: Add your message handler code here and/or call default
//DEL 	 AfxBeginThread((AFX_THREADPROC)restore,this);
//DEL 	CView::OnLButtonDown(nFlags, point);
//DEL }
