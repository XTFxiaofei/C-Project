// MTASView.cpp : implementation of the CMTASView class
//

#include "stdafx.h"
#include "MTAS.h"

#include "MTASDoc.h"
#include "MTASView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define WM_MYINITIALUPDATE (WM_USER + 1)

/////////////////////////////////////////////////////////////////////////////
// CMTASView

IMPLEMENT_DYNCREATE(CMTASView, CHtmlView)

BEGIN_MESSAGE_MAP(CMTASView, CHtmlView)
	//{{AFX_MSG_MAP(CMTASView)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CHtmlView::OnFilePrint)
	ON_MESSAGE(WM_MYINITIALUPDATE, OnMyInitialUpdate)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMTASView construction/destruction

CMTASView::CMTASView()
{
	CString sModFileName, strFilePath;
	GetModuleFileName(NULL, sModFileName.GetBuffer(MAX_PATH), MAX_PATH);
	sModFileName.ReleaseBuffer();		
	sModFileName.MakeReverse();
	int nIdx = sModFileName.Find('\\');
	nIdx = sModFileName.Find('\\', --nIdx);
	strFilePath = sModFileName.Right(nIdx);
	strFilePath.MakeReverse();

	m_sLabel = _T("Right click for menu");
//	m_sUrl = _T(strFilePath + "res\\index.htm");
	m_sUrl = _T("http://jpkc.sdibt.edu.cn/sxxy/show/maths/jxkj.asp");
}

CMTASView::~CMTASView()
{

}

BOOL CMTASView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMTASView drawing

void CMTASView::OnDraw(CDC* pDC)
{
	CMTASDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

void CMTASView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	PostMessage(WM_MYINITIALUPDATE);
}

LRESULT CMTASView::OnMyInitialUpdate(WPARAM /*wParam*/, LPARAM /*lParam*/)
{
	CStringArray& a = GetDocument()->m_aStrings;
	if(a.GetSize())
	{
		CMTASView* pView = this;
		for(int i = 0; i < a.GetSize(); i++)
		{
			if(i == 0) // use a current view and set m_sLabel
				pView->m_sLabel = a[i];
			else if(i % 3 == 0) // add a new view and set m_sLabel
			{				
				pView->m_sLabel = a[i];
			}
			else if(i % 3 == 1) // set m_sUrl
				pView->m_sUrl = a[i];
			else // set m_sTooltip
			{
				pView->m_sTooltip = a[i];
				((CMainFrame*)AfxGetApp()->m_pMainWnd)->AddView(pView->m_sLabel,pView,pView->m_sTooltip);
				pView->Navigate2(pView->m_sUrl,NULL,NULL);
			}
		}
		a.RemoveAll();
	}
	else
	{
		CString sModFileName, strFilePath;
		GetModuleFileName(NULL, sModFileName.GetBuffer(MAX_PATH), MAX_PATH);
		sModFileName.ReleaseBuffer();		
		sModFileName.MakeReverse();
		int nIdx = sModFileName.Find('\\');
		nIdx = sModFileName.Find('\\', --nIdx);
		strFilePath = sModFileName.Right(nIdx);
		strFilePath.MakeReverse();

		m_sTooltip = _T("");
		//m_sUrl = _T(strFilePath + "res\\index.htm");
		m_sUrl = _T("http://jpkc.sdibt.edu.cn/sxxy/show/maths/jxkj.asp");

		m_sLabel = _T("Right click for menu");
		((CMainFrame*)AfxGetApp()->m_pMainWnd)->AddView(m_sLabel,this,m_sTooltip);
		Navigate2(m_sUrl,NULL,NULL);
	}
	((CMainFrame*)AfxGetApp()->m_pMainWnd)->SetCurView(0);
	return 0;
}

/////////////////////////////////////////////////////////////////////////////
// CMTASView printing


/////////////////////////////////////////////////////////////////////////////
// CMTASView diagnostics

#ifdef _DEBUG
void CMTASView::AssertValid() const
{
	CView::AssertValid();
}

void CMTASView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMTASDoc* CMTASView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMTASDoc)));
	return (CMTASDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMTASView message handlers
