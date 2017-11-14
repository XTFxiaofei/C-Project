// PptView.cpp : implementation file
//

#include "stdafx.h"
#include "mtas.h"
#include "PptView.h"
#include "MTASDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPptView

IMPLEMENT_DYNCREATE(CPptView, CMyView)

CPptView::CPptView(BOOL bBlankPage) : CMyView(bBlankPage)
{
}

CPptView::~CPptView()
{
}


BEGIN_MESSAGE_MAP(CPptView, CMyView)
	//{{AFX_MSG_MAP(CPptView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPptView drawing

void CPptView::OnDraw(CDC* pDC)
{
	CMTASDoc* pDoc = (CMTASDoc*)GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CPptView diagnostics

#ifdef _DEBUG
void CPptView::AssertValid() const
{
	CMyView::AssertValid();
}

void CPptView::Dump(CDumpContext& dc) const
{
	CMyView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPptView message handlers
