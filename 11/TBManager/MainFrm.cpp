// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "TBManager.h"
#include "RightView.h"
#include "LeftView.h"
#include "MainFrm.h"
#include "ShowCondition.h"
#include "QueryDlg.h"
#include "ADDDLG.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	ON_COMMAND(ID_MANAGER, OnManager)
	ON_COMMAND(ID_MANAGER_ADD, OnManagerAdd)
	ON_COMMAND(ID_MANAGER_DEL, OnManagerDel)
	ON_COMMAND(ID_MANAGER_UPDATE, OnManagerUpdate)
	ON_COMMAND(ID_MANAGER_SELECT, OnManagerSelect)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

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
	m_prview=NULL;
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

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	cs.style   &=   ~WS_MAXIMIZEBOX;   
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




void CMainFrame::OnFileNew() 
{
	CShowCondition mydlg;
	mydlg.DoModal();
	
}


void CMainFrame::OnManager() 
{
	QueryDlg mydlg;
	CString str,strcondition;
	if(mydlg.DoModal()==IDOK)
	{
		strcondition=mydlg.m_condition;	
		Conditionstr=strcondition;
		str.Format("select top 15 * from ti_choose where tigan like '%%%s%%' order by 'tno'",strcondition); 
		m_prview->m_pageno="1";
		m_prview->page=1;
		m_prview->ShowTheme(str);
		
		m_prview->m_tixing="选择题";


			//
	}
	
}

void CMainFrame::OnManagerAdd() 
{
	CADDDLG mydlg;
	mydlg.DoModal();
	
}

void CMainFrame::OnManagerDel() 
{
	CString str;
	m_prview->UpdateData();
	if(MessageBox("确定删除吗？","提示",MB_YESNO|MB_ICONINFORMATION)==IDYES)
	{
		if(m_prview->selectrow==-1)
		{
			AfxMessageBox("没有选定记录");
			return;
		}
		else
		{
			str.Format("delete from %s where tno=%s",m_prview->strtixing,m_prview->m_list.GetItemText(m_prview->selectrow,0));
			m_prview->pRS->Open(_bstr_t(str),CADORecordset.openQuery);
			m_prview->selectrow=-1;;
			m_prview->pRS->Close();
			m_prview->OperationUpdate();
			AfxMessageBox("删除成功！");
		
		}

	}
	
	
}

void CMainFrame::OnManagerUpdate() 
{
	CADDDLG mydlg;
	CString str;
	if(m_prview->strtixing=="ti_choose")mydlg.font=0;
	if(m_prview->strtixing=="ti_judge")mydlg.font=1;
	if(m_prview->strtixing=="ti_filltext")mydlg.font=2;
	if(m_prview->strtixing=="ti_procedure")mydlg.font=3;
	if(m_prview->selectrow==-1)
		{
			AfxMessageBox("没有选定记录");
			return;
		}
	else 
	{
		mydlg.position=atoi(m_prview->m_list.GetItemText(m_prview->selectrow,0));
		str.Format("%d",mydlg.position);
	//	AfxMessageBox(str);
		m_prview->selectrow=-1;
	}
//	mydlg.font=1;
	mydlg.DoModal();
	
	
}

void CMainFrame::OnManagerSelect() 
{
	OnManager();
	
}

void CMainFrame::OnSize(UINT nType, int cx, int cy) 
{
	//if(nType==SIZE_MAXIMIZED)return;  
	CFrameWnd::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	
}

BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) 
{
	m_splitter.CreateStatic(this,1,2);
	m_splitter.CreateView(0,0,RUNTIME_CLASS(CLeftView),CSize(100,100),pContext);
	m_splitter.CreateView(0,1,RUNTIME_CLASS(CRightView),CSize(100,100),pContext);
	m_prview=(CRightView*)m_splitter.GetPane(0,1);
	return true;

}
