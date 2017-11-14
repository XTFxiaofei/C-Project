// MyView.cpp : implementation file
//

#include "stdafx.h"
#include "mtas.h"
#include "MyView.h"

#include "MTASDoc.h"
#include "MTASView.h"
#include "MainFrm.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyView

IMPLEMENT_DYNCREATE(CMyView, CView)

CMyView::CMyView()
{
	m_pCntrItem = NULL;
}

CMyView::CMyView(BOOL bBlankPage) : m_bBlankPage(bBlankPage)
{
	m_pCntrItem = NULL;
}

CMyView::~CMyView()
{
	if(m_pCntrItem)
		delete m_pCntrItem;
}


BEGIN_MESSAGE_MAP(CMyView, CView)
	//{{AFX_MSG_MAP(CMyView)
	ON_WM_SIZE()
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyView drawing

void CMyView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CMyView diagnostics

#ifdef _DEBUG
void CMyView::AssertValid() const
{
	CView::AssertValid();
}

void CMyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyView message handlers


void CMyView::AddNewCntrItemFromFile(const CString& strFilePath)
{
	BeginWaitCursor();

	CMTASDoc* pDoc = (CMTASDoc*)((CMainFrame*)AfxGetMainWnd())->GetActiveDocument();
	CMTASCntrItem* pItem = NULL;
	TRY
	{
		// Create new item connected to document.
		pItem = new CMTASCntrItem(pDoc);
		ASSERT_VALID(pItem);

		if (!pItem->CreateFromFile(strFilePath)) {
			delete pItem;
			return;
		}
		ASSERT_VALID(pItem);
		m_pCntrItem = pItem;		
	}
	CATCH(CException, e)
	{
		if (pItem != NULL)
		{
			ASSERT_VALID(pItem);
			pItem->Delete();
		}
	}
	END_CATCH
	EndWaitCursor();
}

void CMyView::SwitchToThisCntrItem()
{
	BeginWaitCursor();
	CView* pViewObjCont = (CView*)((CMainFrame*)AfxGetMainWnd())->GetActiveView();
	CMTASDoc* pDoc = (CMTASDoc*)((CMainFrame*)AfxGetMainWnd())->GetActiveDocument();
	// make sure we deactivate any active items first.
	COleClientItem* pActiveItem = pDoc->GetInPlaceActiveItem(pViewObjCont);
	if (pActiveItem != NULL)
		pActiveItem->Deactivate();
	
	if(m_pCntrItem)
		m_pCntrItem->Activate(OLEIVERB_SHOW, this);
	pViewObjCont->Invalidate();
	EndWaitCursor();
}

void CMyView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	
	if (m_pCntrItem != NULL)
		m_pCntrItem->SetItemRects();

	if(m_bBlankPage)
		m_wndWebBrowser.MoveWindow(0, 0, cx, cy);
}

int CMyView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if(m_bBlankPage && !m_wndWebBrowser.Create(NULL, WS_CHILD | WS_VISIBLE, 
		CRect(0, 0, 0, 0), this, 100)) 
	{
		return -1;
	}
	return 0;
}

void CMyView::SetLabel(const CString &strLabel)
{
	m_strLabel = strLabel;
}

CString CMyView::GetLabel() const
{
	return m_strLabel;
}
