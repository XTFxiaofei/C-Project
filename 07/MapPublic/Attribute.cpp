// Attribute.cpp : implementation file
//

#include "stdafx.h"
#include "mappublic.h"
#include "Attribute.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAttribute

IMPLEMENT_DYNCREATE(CAttribute, CFormView)

CAttribute::CAttribute()
	: CFormView(CAttribute::IDD)
{
	//{{AFX_DATA_INIT(CAttribute)
	m_strAttribute = _T("");
	//}}AFX_DATA_INIT
}

CAttribute::~CAttribute()
{
}

void CAttribute::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAttribute)
	DDX_Text(pDX, IDC_SHOW_ATTRIBUTE, m_strAttribute);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAttribute, CFormView)
	//{{AFX_MSG_MAP(CAttribute)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAttribute diagnostics

#ifdef _DEBUG
void CAttribute::AssertValid() const
{
	CFormView::AssertValid();
}

void CAttribute::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAttribute message handlers
