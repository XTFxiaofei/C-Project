// SubView.cpp : implementation file
//

#include "stdafx.h"
#include "gradudemis.h"
#include "SubView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSubView

IMPLEMENT_DYNCREATE(CSubView, CFormView)

CSubView::CSubView()
	: CFormView(CSubView::IDD)
{
	//{{AFX_DATA_INIT(CSubView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CSubView::~CSubView()
{
}

void CSubView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSubView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSubView, CFormView)
	//{{AFX_MSG_MAP(CSubView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSubView diagnostics

#ifdef _DEBUG
void CSubView::AssertValid() const
{
	CFormView::AssertValid();
}

void CSubView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSubView message handlers
