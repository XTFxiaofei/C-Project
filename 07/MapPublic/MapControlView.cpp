// MapControlView.cpp : implementation file
//

#include "stdafx.h"
#include "MapPublic.h"
#include "MapControlView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMapControlView

IMPLEMENT_DYNCREATE(CMapControlView, CFormView)

CMapControlView::CMapControlView()
	: CFormView(CMapControlView::IDD)
{
	//{{AFX_DATA_INIT(CMapControlView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CMapControlView::~CMapControlView()
{
}

void CMapControlView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMapControlView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMapControlView, CFormView)
	//{{AFX_MSG_MAP(CMapControlView)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMapControlView diagnostics

#ifdef _DEBUG
void CMapControlView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMapControlView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMapControlView message handlers

void CMapControlView::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
//	GetParentFrame()->RecalcLayout();
 //   ResizeParentToFit(FALSE);
    m_Sheet.AddPage(&m_RoadWay);	
	m_Sheet.AddPage(&m_Staion);
	m_Sheet.AddPage(&m_Transfer);
	m_Sheet.Create(this, WS_CHILD | WS_VISIBLE, 0); // 创建窗口
	m_Sheet.ModifyStyleEx (0, WS_EX_CONTROLPARENT); // 修改风格
	m_Sheet.ModifyStyle( 0, WS_TABSTOP ); // 修改风格
   	m_Sheet.SetWindowPos( NULL, 0, 0, 0, 0, 
			SWP_NOZORDER | SWP_NOSIZE | SWP_NOACTIVATE );
	
}

void CMapControlView::OnSize(UINT nType, int cx, int cy) 
{
	CFormView::OnSize(nType, cx, cy);
//	m_RoadWay.SetWindowPos(0,0,0,cx,cy,SWP_NOZORDER);

	
}
