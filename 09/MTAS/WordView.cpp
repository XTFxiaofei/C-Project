// WordView.cpp : implementation file
//

#include "stdafx.h"
#include "mtas.h"
#include "WordView.h"
#include "MTASDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWordView

IMPLEMENT_DYNCREATE(CWordView, CMyView)

CWordView::CWordView(BOOL bBlankPage) : CMyView(bBlankPage)
{
}

CWordView::~CWordView()
{
}


BEGIN_MESSAGE_MAP(CWordView, CMyView)
	//{{AFX_MSG_MAP(CWordView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWordView drawing

void CWordView::OnDraw(CDC* pDC)
{
	CMTASDoc* pDoc = (CMTASDoc*)GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CWordView diagnostics

#ifdef _DEBUG
void CWordView::AssertValid() const
{
	CMyView::AssertValid();
}

void CWordView::Dump(CDumpContext& dc) const
{
	CMyView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWordView message handlers

