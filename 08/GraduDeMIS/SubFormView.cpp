// SubFormView.cpp : implementation file
//

#include "stdafx.h"
#include "gradudemis.h"
#include "SubFormView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSubFormView

IMPLEMENT_DYNCREATE(CSubFormView, CFormView)

CSubFormView::CSubFormView()
	: CFormView(CSubFormView::IDD)
{
	//{{AFX_DATA_INIT(CSubFormView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CSubFormView::~CSubFormView()
{
}

void CSubFormView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSubFormView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSubFormView, CFormView)
	//{{AFX_MSG_MAP(CSubFormView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSubFormView diagnostics

#ifdef _DEBUG
void CSubFormView::AssertValid() const
{
	CFormView::AssertValid();
}

void CSubFormView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSubFormView message handlers

void CSubFormView::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	CFormView::OnInitialUpdate();
	m_Sheet.AddPage(&m_suboper);
    m_Sheet.AddPage(&m_subquery);	
//	m_Sheet.AddPage(&m_Transfer);
	m_Sheet.Create(this, WS_CHILD | WS_VISIBLE, 0); // 创建窗口
	m_Sheet.ModifyStyleEx (0, WS_EX_CONTROLPARENT); // 修改风格
	m_Sheet.ModifyStyle( 0, WS_TABSTOP ); // 修改风格
   	m_Sheet.SetWindowPos( NULL, 0, 0, 0, 0, SWP_NOZORDER | SWP_NOSIZE | SWP_NOACTIVATE );	
}
