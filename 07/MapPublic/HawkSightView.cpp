// HawkSightView.cpp : implementation file
//

#include "stdafx.h"
#include "mappublic.h"
#include "HawkSightView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHawkSightView

IMPLEMENT_DYNCREATE(CHawkSightView, CFormView)

CHawkSightView::CHawkSightView()
	: CFormView(CHawkSightView::IDD)
{
	//{{AFX_DATA_INIT(CHawkSightView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CHawkSightView::~CHawkSightView()
{
}

void CHawkSightView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHawkSightView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHawkSightView, CFormView)
	//{{AFX_MSG_MAP(CHawkSightView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHawkSightView diagnostics

#ifdef _DEBUG
void CHawkSightView::AssertValid() const
{
	CFormView::AssertValid();
}

void CHawkSightView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHawkSightView message handlers

void CHawkSightView::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	m_Sheet.AddPage(&m_sightdlg);
    m_Sheet.AddPage(&m_hawkview);	
//	m_Sheet.AddPage(&m_Transfer);
	m_Sheet.Create(this, WS_CHILD | WS_VISIBLE, 0); // 创建窗口
	m_Sheet.ModifyStyleEx (0, WS_EX_CONTROLPARENT); // 修改风格
	m_Sheet.ModifyStyle( 0, WS_TABSTOP ); // 修改风格
   	m_Sheet.SetWindowPos( NULL, 0, 0, 0, 0, 
			SWP_NOZORDER | SWP_NOSIZE | SWP_NOACTIVATE );	
}
