// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "HCDB.h"

#include "MainFrm.h"
#include "BACKUPDLG.h"
#include "RESTOREDLG.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include "SALESQUITDLG.h"
#include "SALESQUERY.h"
#include "PASSDLG.h"
#include "SYSDLG.h"
/////////////////////////////////////////////////////////////////////////////
// CMainFrame
extern CHCDBApp theApp;
IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(IDM_FOREMANGE, OnForemange)
	ON_COMMAND(IDF_BACKUP, OnBackup)
	ON_COMMAND(IDF_RESTORE, OnRestore)
	ON_COMMAND(IDM_IN_STOCKMANGE, OnInStockmange)
	ON_COMMAND(IDM_GETHER_OUT, OnGetherOut)
	ON_COMMAND(IDM_GETHER_IN, OnGetherIn)
	ON_COMMAND(IDM_INDETAIL, OnIndetail)
	ON_COMMAND(IDM_INSTOCKQUERY, OnInstockquery)
	ON_COMMAND(IDM_OUT_STOCKMANGE, OnOutStockmange)
	ON_COMMAND(IDM_OUTDETAIL, OnOutdetail)
	ON_COMMAND(IDM_OUTSTOCKQUERY, OnOutstockquery)
	ON_COMMAND(IDM_MAIN, OnMain)
	ON_WM_CLOSE()
	ON_COMMAND(IDF_SALESQUIT, OnSalesquit)
	ON_COMMAND(ID_USERMANAGE, OnUsermanage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
CString operid;
static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);
    ::SetWindowPos(this->m_hWnd,NULL,90,90,600,600,true);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


BOOL CMainFrame::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class

	return CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
		if (!m_wndSplitter.CreateStatic(this, 1, 2))
		return FALSE;

	if (!m_wndSplitter.CreateView(0, 0, RUNTIME_CLASS(CMQQAppearanceDlg), CSize(100, 100), pContext) ||
		!m_wndSplitter.CreateView(0, 1, RUNTIME_CLASS(CAnotherView), CSize(900, 900), pContext))
	{
		m_wndSplitter.DestroyWindow();
		return FALSE;
	}

	return TRUE;
	return CFrameWnd::OnCreateClient(lpcs, pContext);
}

void CMainFrame::OnForemange() 
{
	// TODO: Add your command handler code here
	PASSDLG dlg1;
	if(dlg1.DoModal()==IDOK)
	{
		CString sqlstr;
		
		sqlstr.Format("select * from tb_operator where operid='%s' and operpassword='%s'",dlg1.m_user,dlg1.m_pass);
        if(GetRecord(sqlstr)==0){MessageBox("没有该用户!");return;}
        operid=dlg1.m_user;
	}
	else
		return;
	CForeMange dlg;
	dlg.DoModal();
}

void CMainFrame::OnBackup() 
{
	// TODO: Add your command handler code here
	BACKUPDLG dlg;
	dlg.DoModal();
}

void CMainFrame::OnRestore() 
{
	// TODO: Add your command handler code here

	CRESTOREDLG dlg;
	dlg.DoModal();
}

void CMainFrame::OnInStockmange() 
{
	// TODO: Add your command handler code here
	m_wndSplitter.SetActivePane(0,1);
	CAnotherView *cwnd=(CAnotherView *)m_wndSplitter.GetPane(0,1);
    cwnd->ShowInStockMange(false);
	cwnd->m_Tab.SetCurSel(1);
}

void CMainFrame::OnGetherOut() 
{
	// TODO: Add your command handler code here
	m_wndSplitter.SetActivePane(0,1);
	CAnotherView *cwnd=(CAnotherView *)m_wndSplitter.GetPane(0,1);
    cwnd->ShowGatherOut(true);
	cwnd->m_Tab.SetCurSel(8);
}

void CMainFrame::OnGetherIn() 
{
	// TODO: Add your command handler code here
	m_wndSplitter.SetActivePane(0,1);
	CAnotherView *cwnd=(CAnotherView *)m_wndSplitter.GetPane(0,1);
	cwnd->ShowGatherin(true);
	cwnd->m_Tab.SetCurSel(7);
}
void CMainFrame::OnIndetail() 
{
	// TODO: Add your command handler code here
	m_wndSplitter.SetActivePane(0,1);
	CAnotherView *cwnd=(CAnotherView *)m_wndSplitter.GetPane(0,1);
	cwnd->ShowIndetail(true);
	cwnd->m_Tab.SetCurSel(3);
}

void CMainFrame::OnInstockquery() 
{
	// TODO: Add your command handler code here
	m_wndSplitter.SetActivePane(0,1);

	CAnotherView *cwnd=(CAnotherView *)m_wndSplitter.GetPane(0,1);
	cwnd->ShowInStockQuery(true);
	cwnd->m_Tab.SetCurSel(2);
}

void CMainFrame::OnOutStockmange() 
{
	// TODO: Add your command handler code here
	m_wndSplitter.SetActivePane(0,1);
	CAnotherView *cwnd=(CAnotherView *)m_wndSplitter.GetPane(0,1);
	cwnd->ShowOutStockMange(true);
	cwnd->m_Tab.SetCurSel(4);
}

void CMainFrame::OnOutdetail() 
{
	// TODO: Add your command handler code here
	m_wndSplitter.SetActivePane(0,1);
	CAnotherView *cwnd=(CAnotherView *)m_wndSplitter.GetPane(0,1);
	cwnd->ShowOutdetail(true);
	cwnd->m_Tab.SetCurSel(6);
}

void CMainFrame::OnOutstockquery() 
{
	// TODO: Add your command handler code here
	m_wndSplitter.SetActivePane(0,1);
	CAnotherView *cwnd=(CAnotherView *)m_wndSplitter.GetPane(0,1);	
	cwnd->ShowOutStockquery(true);
	cwnd->m_Tab.SetCurSel(5);
}

void CMainFrame::OnMain() 
{
	// TODO: Add your command handler code here
	m_wndSplitter.SetActivePane(0,1);
	CAnotherView *cwnd=(CAnotherView *)m_wndSplitter.GetPane(0,1);	
	cwnd->ShowBmo(true);
	cwnd->m_Tab.SetCurSel(0);
}

void CMainFrame::OnClose() 
{
	// TODO: Add your message handler code here and/or call default

    //AfxBeginThread((AFX_THREADPROC)restore,this);
	CFrameWnd::OnClose();
}

void CMainFrame::OnSalesquit() 
{
	// TODO: Add your command handler code here
	CSALESQUITDLG dlg;
	dlg.DoModal();
}


int CMainFrame::GetRecord(CString sqlstr)
{
    m_record=NULL;
	m_record.CreateInstance(__uuidof(Recordset));
	m_record->Open((_variant_t )sqlstr,theApp.m_connection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	int count=0;
   if(m_record!=NULL)
   {
	   try
	   {
		   m_record->MoveFirst();
	   }
	   catch(...)
	   {
		   return 0;
	   }
	   if(m_record->_EOF)return 0;
	   while(!m_record->_EOF)
	   {
		  m_record->MoveNext();
		   count++;
	   }
   }
   m_record->MoveFirst();
   return count;
}

void CMainFrame::OnUsermanage() 
{
	SYSDLG dlg;
	dlg.DoModal();
	
}
