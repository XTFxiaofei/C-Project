// GuideBar.cpp : implementation file
//

#include "stdafx.h"
#include "mtas.h"
#include "mainfrm.h"
#include "GuideBar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGuideBar

CGuideBar::CGuideBar()
{
}

CGuideBar::~CGuideBar()
{
}


BEGIN_MESSAGE_MAP(CGuideBar, baseCGuideBar)
	//{{AFX_MSG_MAP(baseCGuideBar)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	ON_WM_CREATE()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


void CGuideBar::AddToDrawBar(CAutoHideBar * pDrawBar)
{
	CRect rt;
	m_listPpt.GetClientRect(&rt);
	m_listPpt.ShowWindow(SW_SHOW);
	pDrawBar->AddButton(_T(" 教学幻灯 "), DRAWBTNSTYLE_GROUP | DRAWBTNSTYLE_SELECT, &m_listPpt, &m_OutlookTabCtrlEx, &rt, this, 0);
	
	m_listFlash.ShowWindow(SW_SHOW);
	pDrawBar->AddButton(_T(" 演示动画 "), DRAWBTNSTYLE_GROUP, &m_listFlash, &m_OutlookTabCtrlEx, &rt, this, 1);

	m_listWord.ShowWindow(SW_SHOW);
	pDrawBar->AddButton(_T(" 相关练习 "), DRAWBTNSTYLE_GROUP, &m_listWord, &m_OutlookTabCtrlEx, &rt, this, 2);
	
}

void CGuideBar::RemoveFromDrawBar(CAutoHideBar * pDrawBar)
{
	CRect rt;
	pDrawBar->RemoveButton(&m_listPpt);
	pDrawBar->RemoveButton(&m_listFlash);
	pDrawBar->RemoveButton(&m_listWord);
	pDrawBar->Shrink();
	pDrawBar->CalcLayout();
	pDrawBar->Invalidate();
	GetParentFrame()->ShowControlBar(this, TRUE, FALSE);
	m_listPpt.ShowWindow(SW_HIDE);
	m_listFlash.ShowWindow(SW_HIDE);
	m_listWord.ShowWindow(SW_HIDE);

	HTAB hTab = m_OutlookTabCtrlEx.GetSel();
	m_OutlookTabCtrlEx.SetSel(hTab);
	CWnd* pWnd = FromHandlePermanent(m_OutlookTabCtrlEx.GetItemWnd(hTab));
	if(pWnd) {
		CRect rc, rcBtnMenu;
		int nCapHeight = m_OutlookTabCtrlEx.GetCaptionHeight();
		int nBtnHeight = m_OutlookTabCtrlEx.GetButtonHeight();		
		int nSplitterHeight = m_OutlookTabCtrlEx.GetSplitterHeight();
		int nCount = m_OutlookTabCtrlEx.GetCountVisibleTabs();
		m_OutlookTabCtrlEx.GetButtonMenuRect(&rcBtnMenu);
		m_OutlookTabCtrlEx.GetClientRect(&rc);
		rc.top += nCapHeight;
		rc.bottom = rc.bottom - nCount * nBtnHeight - nSplitterHeight - rcBtnMenu.Height() - 2;
		pWnd->ShowWindow(SW_SHOW);
		pWnd->MoveWindow(&rc);		
	}
}

/////////////////////////////////////////////////////////////////////////////
// CGuideBar message handlers

int CGuideBar::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (baseCGuideBar::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if(!m_OutlookTabCtrlEx.Create(this, WS_CHILD | WS_VISIBLE | WS_BORDER,
		CRect(0, 0, 0, 0), 2001)) 
		return -1;
		// 
	if(!CreateImageLists() || !CreateListCtrls())
		return -1;

	if( !m_OutlookTabCtrlEx.Add(&m_listPpt, _T(" 教学幻灯"), 0, 0) ||
		!m_OutlookTabCtrlEx.Add(&m_listFlash, _T(" 演示动画"), 1, 1) ||
		!m_OutlookTabCtrlEx.Add(&m_listWord, _T(" 相关练习"), 2, 2) ) 
		return -1;
		// 
	if(m_OutlookTabCtrlEx.LoadState(
			AfxGetApp(), _T("OutlookTabCtrl"), _T("TabsState")) == false)
		m_OutlookTabCtrlEx.PushItem();
		// 
	m_OutlookTabCtrlEx.Update();

	return 0;
}

void CGuideBar::OnSize(UINT nType, int cx, int cy)
{
	baseCGuideBar::OnSize(nType, cx, cy);
		// 
	if(m_OutlookTabCtrlEx.GetSafeHwnd()) {	
		CRect rt;
		GetClientRect(&rt);
		rt.top += 3;
		m_OutlookTabCtrlEx.MoveWindow(&rt);
	}
}

BOOL CGuideBar::CreateImageLists()
{
	CImageList imagelistBig, imagelistSmall;
	CBitmap bmpBig, bmpSmall;
		// 
	if(!imagelistBig.Create(16, 16, ILC_COLOR24 | ILC_MASK, 4, 0))
		return FALSE;
	bmpBig.LoadBitmap(IDB_BITMAP1);
	imagelistBig.Add(&bmpBig,RGB(255, 0, 255));
		// 
	if(!imagelistSmall.Create(16, 16, ILC_COLOR24 | ILC_MASK, 4, 0))
		return FALSE;
	bmpSmall.LoadBitmap(IDB_BITMAP2);
	imagelistSmall.Add(&bmpSmall, RGB(255, 0, 255));
		// 
	m_OutlookTabCtrlEx.SetImageLists(&imagelistBig, &imagelistSmall, NULL, NULL);

	return TRUE;
}

BOOL CGuideBar::CreateListCtrls()
{
	if( !m_listPpt.Create(WS_CHILD | WS_CLIPCHILDREN | LVS_REPORT | LVS_SHOWSELALWAYS,
			CRect(0,0,0,0), &m_OutlookTabCtrlEx, 2002) ||
		!m_listFlash.Create(WS_CHILD | WS_CLIPCHILDREN | LVS_REPORT | LVS_SHOWSELALWAYS,
			CRect(0,0,0,0), &m_OutlookTabCtrlEx, 2003) ||
		!m_listWord.Create(WS_CHILD | WS_CLIPCHILDREN | LVS_REPORT | LVS_SHOWSELALWAYS,
			CRect(0,0,0,0), &m_OutlookTabCtrlEx, 2004) )
		return FALSE;

	m_listPpt.InitListCtrl(_T("SELECT * FROM `cw` WHERE `TYPE`='ppt'"));
	m_listFlash.InitListCtrl(_T("SELECT * FROM `cw` WHERE `TYPE`='swf'"));	
	m_listWord.InitListCtrl(_T("SELECT * FROM `cw` WHERE `TYPE`='doc' OR `TYPE`='txt'"));

	GetCourseManager().AddUpdateWindow(&m_listPpt);
	GetCourseManager().AddUpdateWindow(&m_listFlash);
	GetCourseManager().AddUpdateWindow(&m_listWord);

	GetCourseWareManager().AddUpdateWindow(&m_listPpt);
	GetCourseWareManager().AddUpdateWindow(&m_listFlash);
	GetCourseWareManager().AddUpdateWindow(&m_listWord);

	return TRUE;
}
