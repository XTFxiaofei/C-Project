// TBManagerView.cpp : implementation of the CTBManagerView class
//

#include "stdafx.h"
#include "TBManager.h"

#include "TBManagerDoc.h"
#include "TBManagerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTBManagerView

IMPLEMENT_DYNCREATE(CTBManagerView, CView)

BEGIN_MESSAGE_MAP(CTBManagerView, CView)
	//{{AFX_MSG_MAP(CTBManagerView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTBManagerView construction/destruction

CTBManagerView::CTBManagerView()
{
	// TODO: add construction code here

}

CTBManagerView::~CTBManagerView()
{
}

BOOL CTBManagerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTBManagerView drawing

void CTBManagerView::OnDraw(CDC* pDC)
{
	CTBManagerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTBManagerView printing

BOOL CTBManagerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTBManagerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTBManagerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTBManagerView diagnostics

#ifdef _DEBUG
void CTBManagerView::AssertValid() const
{
	CView::AssertValid();
}

void CTBManagerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTBManagerDoc* CTBManagerView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTBManagerDoc)));
	return (CTBManagerDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTBManagerView message handlers
