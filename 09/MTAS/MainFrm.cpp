// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "MTAS.h"

#include "MainFrm.h"
#include "MyView.h"
#include "DlgProperties.h"
#include "MTASDoc.h"
#include "SimpleSplashWnd.h"
#include "MTASView.h"
#include "FlashView.h"
#include "PptView.h"
#include "WordView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame


IMPLEMENT_DYNCREATE(CMainFrame, CPersistentFrame)
IMPLEMENT_PINDOCK(CMainFrame)
BEGIN_MESSAGE_MAP(CMainFrame, CPersistentFrame)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_VIEW_COURSEWARE_GUIDE, OnViewCoursewareGuide)
	ON_UPDATE_COMMAND_UI(ID_VIEW_COURSEWARE_GUIDE, OnUpdateViewCoursewareGuide)
	ON_COMMAND(ID_VIEW_COURSEWARE_PREVIEW, OnViewCoursewarePreview)
	ON_UPDATE_COMMAND_UI(ID_VIEW_COURSEWARE_PREVIEW, OnUpdateViewCoursewarePreview)
	ON_COMMAND(ID_VIEW_TOOLBAR_FLASH, OnViewToolbarFlash)
	ON_UPDATE_COMMAND_UI(ID_VIEW_TOOLBAR_FLASH, OnUpdateViewToolbarFlash)
	ON_COMMAND(ID_VIEW_TOOLBAR_GUIDE, OnViewToolbarGuide)
	ON_UPDATE_COMMAND_UI(ID_VIEW_TOOLBAR_GUIDE, OnUpdateViewToolbarGuide)
	ON_COMMAND(ID_OPEN_MYCOMPUTER, OnOpenMycomputer)
	ON_COMMAND(ID_OPEN_MYDOCUMENT, OnOpenMydocument)
	ON_COMMAND(ID_VIEW_COURSEWARE_ASSORT, OnViewCoursewareAssort)
	ON_UPDATE_COMMAND_UI(ID_VIEW_COURSEWARE_ASSORT, OnUpdateViewCoursewareAssort)
	ON_COMMAND(ID_VIEW_CLOCK, OnViewClock)
	ON_UPDATE_COMMAND_UI(ID_VIEW_CLOCK, OnUpdateViewClock)
	ON_UPDATE_COMMAND_UI(ID_OPEN_MYCOMPUTER, OnUpdateOpenMycomputer)
	ON_UPDATE_COMMAND_UI(ID_OPEN_MYDOCUMENT, OnUpdateOpenMydocument)
	ON_COMMAND(ID_VIEW_TOOLBAR_COURSEWARE, OnViewToolbarCourseware)
	ON_UPDATE_COMMAND_UI(ID_VIEW_TOOLBAR_COURSEWARE, OnUpdateViewToolbarCourseware)
	ON_COMMAND(ID_PAGE_ADD_BLANK, OnPageAddBlank)
	ON_COMMAND(ID_PAGE_CLOSE_CURRENT, OnPageCloseCurrent)
	ON_UPDATE_COMMAND_UI(ID_PAGE_ADD_BLANK, OnUpdatePageAddBlank)
	ON_UPDATE_COMMAND_UI(ID_PAGE_CLOSE_CURRENT, OnUpdatePageCloseCurrent)
	ON_COMMAND(ID_PAGE_FIRST, OnPageFirst)
	ON_UPDATE_COMMAND_UI(ID_PAGE_FIRST, OnUpdatePageFirst)
	ON_COMMAND(ID_PAGE_LAST, OnPageLast)
	ON_UPDATE_COMMAND_UI(ID_PAGE_LAST, OnUpdatePageLast)
	ON_COMMAND(ID_PAGE_PREVIOUS, OnPagePrevious)
	ON_UPDATE_COMMAND_UI(ID_PAGE_PREVIOUS, OnUpdatePagePrevious)
	ON_COMMAND(ID_PAGE_NEXT, OnPageNext)
	ON_UPDATE_COMMAND_UI(ID_PAGE_NEXT, OnUpdatePageNext)
	ON_COMMAND(ID_PAGE_PROPERTY, OnPageProperty)
	ON_UPDATE_COMMAND_UI(ID_PAGE_PROPERTY, OnUpdatePageProperty)
	//}}AFX_MSG_MAP
	ON_NOTIFY(CTCN_RCLICK, IDC_TABCTRL, OnRclickTabctrl)
	ON_NOTIFY(CTCN_CLICK, IDC_TABCTRL, OnClickTabctrl)
	ON_PINDOCK_MESSAGES()
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
	m_bFullScreen = FALSE;
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CPersistentFrame::OnCreate(lpCreateStruct) == -1)
		return -1;

	CSimpleSplashWnd _splash( this, IDB_BITMAP_SPLASH );

	_splash.SetStatusText( _T("初始化工具栏...") );
	if(!CreateNavigateToolBar()) {
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if(!CreateCourseWareToolBar()) {
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if(!CreateFlashToolBar()) {		
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
	
	_splash.SetStatusText( _T("创建状态栏...") );
	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	EnablePinDocking(CBRS_ALIGN_ANY);	

	_splash.SetStatusText( _T("初始化课程导航栏...") );
	if(!CreateTreeGuideBar()) {
		TRACE0("Failed to create guide bar\n");
		return -1;      // fail to create
	}

	_splash.SetStatusText( _T("初始化课件导航栏...") );
	if(!CreateGuideBar()) {
		TRACE0("Failed to create guide bar\n");
		return -1;      // fail to create
	}

	_splash.SetStatusText( _T("生成电子时钟...") );
	//	create clock dialog
	if(!CreateClockWnd()) {
		TRACE0("Failed to create clock wnd\n");
		return -1;      // fail to create
	}

	_splash.SetStatusText( _T("初始化Custom Tab...") );
	if(!CreateCustomTabCtrl()) {
		TRACE0("Failed to create customtabctrl\n");
		return -1;      // fail to create
	}

	m_imgList.Create(16, 16, ILC_COLOR16 | ILC_MASK, 4, 1);
	UINT nID[] = {	IDI_SLIDER, IDI_MOVIE, IDI_ASSIGNMENT, IDI_COMMUNICATION  };
	for(int i = 0; i < sizeof(nID) / sizeof(UINT); ++i) {
		HICON hIcon = reinterpret_cast<HICON>(
                ::LoadImage ( AfxGetResourceHandle(), MAKEINTRESOURCE(nID[i]),
                              IMAGE_ICON, 24, 24, LR_DEFAULTCOLOR ));
		m_imgList.Add(hIcon);
	}
	for(i = 0; i < sizeof(nID) / sizeof(UINT); ++i)
		m_AutoHideBar[i].SetImageList(&m_imgList);

	_splash.SetStatusText( _T("初始化菜单...") );
	InitMenu();

	m_wndFlashToolBar.EnableDocking(CBRS_ALIGN_ANY);
	m_wndNavigateToolBar.EnableDocking(CBRS_ALIGN_ANY);
	m_wndCWToolBar.EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndFlashToolBar);	
	DockControlBarLeftOf(&m_wndCWToolBar, &m_wndFlashToolBar);
	//DockControlBarBottomOf(&m_wndCWToolBar, &m_wndFlashToolBar);
//	RecalcLayout();

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CPersistentFrame::PreCreateWindow(cs) )
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
	CPersistentFrame::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CPersistentFrame::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


BOOL CMainFrame::CreateGuideBar()
{
	if (!m_wndGuideBar.Create(_T("课件导航"), this, 123))
    {
        TRACE0("Failed to create mybar\n");
        return -1;      // fail to create
	}

	m_wndGuideBar.SetSCBStyle(m_wndGuideBar.GetSCBStyle() |
		SCBS_SIZECHILD);
    m_wndGuideBar.SetBarStyle(m_wndGuideBar.GetBarStyle() |
        CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC);	
    m_wndGuideBar.EnableDocking(CBRS_ALIGN_ANY);	
    DockControlBar(&m_wndGuideBar, AFX_IDW_DOCKBAR_RIGHT);

	return TRUE;
}

BOOL CMainFrame::CreateCustomTabCtrl()
{	
	if(!m_wndTab.Create(WS_CHILD | WS_VISIBLE | CTCS_FOURBUTTONS | CTCS_DRAGMOVE |
			CTCS_TOOLTIPS/* | CTCS_TOP */, CRect(0,0,0,20), this, IDC_TABCTRL))
    {
		TRACE0("Failed to create tab control\n");
		return FALSE;
    }

    m_wndTab.SetDragCursors(AfxGetApp()->LoadCursor(IDC_CURSORMOVE), NULL);
    m_wndTab.SetItemTooltipText(CTCID_FIRSTBUTTON, _T("First"));
    m_wndTab.SetItemTooltipText(CTCID_PREVBUTTON,  _T("Prev"));
    m_wndTab.SetItemTooltipText(CTCID_NEXTBUTTON,  _T("Next"));
    m_wndTab.SetItemTooltipText(CTCID_LASTBUTTON,  _T("Last"));

	return TRUE;
}

void CMainFrame::OnClickTabctrl(NMHDR* pNMHDR, LRESULT* pResult) 
{
	CPersistentFrame::OnClickTabctrl(pNMHDR, pResult);

	int nCount = m_wndTab.GetItemCount();
	int nCurItem = m_wndTab.GetCurSel();

	switch(((CTC_NMHDR*)pNMHDR)->nItem) {
	case CTCHT_ONFIRSTBUTTON:
		if(nCurItem != 0)
			SetCurView(0);
		break;
	case CTCHT_ONPREVBUTTON:
		if(nCurItem > 0)
			SetCurView(nCurItem - 1);
		break;
	case CTCHT_ONNEXTBUTTON:
		if(nCurItem < nCount - 1)
			SetCurView(nCurItem + 1);
		break;
	case CTCHT_ONLASTBUTTON:
		if(nCurItem != nCount - 1)
			SetCurView(nCount - 1);
		break;
	case CTCHT_NOWHERE:
		TRACE("OnLButtonClicked: Nowhere\n");
		break;
	default:
		break;
	}
}

void CMainFrame::OnRclickTabctrl(NMHDR* pNMHDR, LRESULT* pResult) 
{
	CNewMenu menu;
	menu.CreatePopupMenu();
	menu.AppendMenu(MF_STRING, ID_PAGE_ADD_BLANK, _T("打开空白页"));
	menu.AppendMenu(MF_STRING, ID_OPEN_CW, _T("打开课件"));	
	menu.AppendMenu(MF_SEPARATOR);
	menu.AppendMenu(MF_STRING, ID_VIEW_COURSE_GUIDE, _T("课程导航"));
	menu.AppendMenu(MF_STRING, ID_VIEW_COURSEWARE_GUIDE, _T("课件导航"));
	menu.AppendMenu(MF_STRING, ID_FULL_SCREEN, _T("全屏"));
	menu.AppendMenu(MF_STRING, ID_NORMAL_SCREEN, _T("窗口"));
	menu.AppendMenu(MF_SEPARATOR);
	menu.AppendMenu(MF_STRING, ID_PAGE_PROPERTY, _T("属性"));
	menu.AppendMenu(MF_STRING, ID_PAGE_CLOSE_CURRENT, _T("关闭该页"));
	menu.LoadToolBar(IDR_TOOLBAR_FOR_TAB_FRAME);

	menu.CheckMenuItem(ID_VIEW_COURSE_GUIDE, m_wndTreeGuideBar.IsWindowVisible() ? MF_CHECKED : MF_UNCHECKED);
	menu.CheckMenuItem(ID_VIEW_COURSEWARE_GUIDE, m_wndGuideBar.IsWindowVisible() ? MF_CHECKED : MF_UNCHECKED);
	menu.EnableMenuItem(ID_FULL_SCREEN, !IsFullScreen() ? MF_ENABLED : MF_GRAYED);
	menu.EnableMenuItem(ID_NORMAL_SCREEN, IsFullScreen() ? MF_ENABLED : MF_GRAYED);

	int nCurItem = m_wndTab.GetCurSel();
	int nClickItem = ((CTC_NMHDR*)pNMHDR)->nItem;
	if( nClickItem >= 0 && nCurItem != nClickItem ) {		
		SetCurView(nClickItem);
	}	

	if(m_wndTab.GetItemCount() < 2)
		menu.EnableMenuItem(ID_PAGE_CLOSE_CURRENT, MF_GRAYED);
	CString strClassName = GetActiveView()->GetRuntimeClass()->m_lpszClassName;
	if(strClassName != _T("CMTASView"))
		menu.EnableMenuItem(ID_PAGE_PROPERTY, MF_GRAYED);
	
	CPoint pt(((CTC_NMHDR*)pNMHDR)->ptHitTest);
	m_wndTab.ClientToScreen(&pt);

	int nRet = menu.TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON |
		TPM_RETURNCMD | TPM_NONOTIFY, pt.x, pt.y, this);
	switch(nRet)
	{
	case ID_PAGE_ADD_BLANK:
		AddBlankPage();
		break;
	case ID_OPEN_CW:
		AddCourseWarePage();
		break;
	case ID_PAGE_CLOSE_CURRENT:
		DeleteActiveView();
		break;
	case ID_PAGE_PROPERTY:
		SetViewProperty();
		break;
	case ID_VIEW_COURSE_GUIDE:
		ShowControlBar(&m_wndTreeGuideBar, m_wndTreeGuideBar.IsWindowVisible() ? FALSE : TRUE, FALSE);
		break;
	case ID_VIEW_COURSEWARE_GUIDE:
		ShowControlBar(&m_wndGuideBar, m_wndGuideBar.IsWindowVisible() ? FALSE : TRUE, FALSE);
		break;
	case ID_FULL_SCREEN:
		FullScreen();
		break;
	case ID_NORMAL_SCREEN:
		NormalScreen();
		break;
	}
	*pResult = 0;
}

void CMainFrame::InitMenu()
{
	//	load the menu's icon
	m_DefaultNewMenu.LoadToolBar(IDR_MAINFRAME);
	CFont font;
	font.CreatePointFont (90, _T ("Times New Roman"));
	m_SystemNewMenu.SetMenuTitleFont(&font);
    m_SystemNewMenu.SetMenuTitle(_T("大学数学辅助教学系统 Ver 1.0"),MFT_LINE | MFT_CENTER | MFT_ROUND);
}

BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) 
{
	m_ccx = *pContext;	
	return CPersistentFrame::OnCreateClient(lpcs, pContext);
}

BOOL CMainFrame::CreateFlashToolBar()
{
	if (!m_wndFlashToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndFlashToolBar.LoadToolBar(IDR_FLASH_TOOLBAR))
	{
		TRACE0("Failed to create toolbar\n");
		return FALSE;      // fail to create
	}

	m_wndFlashToolBar.SetWindowText(_T("Flash控制条"));

	/////////////调整工具条/////////////////
	CRect rect;
	CSize sizeMax(0, 0);
	CToolBarCtrl& bar = m_wndFlashToolBar.GetToolBarCtrl();
		
	for (int nIndex = bar.GetButtonCount() - 1; nIndex >= 0; nIndex--)
	{
		bar.GetItemRect(nIndex, rect);

		rect.NormalizeRect();
		sizeMax.cx = __max(rect.Size().cx, sizeMax.cx);
		sizeMax.cy = __max(rect.Size().cy, sizeMax.cy);
	}
	m_wndFlashToolBar.SetSizes(sizeMax, CSize(16,15));

	//	添加组合框
	if (!m_wndFlashToolBar.CreateComboBox(m_wndFlashToolBar.m_comboBox, 7, 100, 200, 100))
	{
		TRACE0("Failed to create toolbar's combo box\n");
		return -1;      // fail to create
	}	

	return TRUE;
}

BOOL CMainFrame::AddBlankPage()
{
	CMTASView* pView = new CMTASView;
	if(!pView)
		return FALSE;
	if(!pView->Create(NULL, NULL, AFX_WS_DEFAULT_VIEW,CRect(0, 0, 0, 0), AfxGetApp()->GetMainWnd(), AFX_IDW_PANE_FIRST, NULL))
		return FALSE;

	AddView(pView->m_sLabel,pView,pView->m_sTooltip);
	pView->Navigate2(pView->m_sUrl,NULL,NULL);

	return TRUE;
}

BOOL CMainFrame::AddCourseWarePage()
{
	static char BASED_CODE szFilter[] = 
		"PowerPoint Files (*.ppt)|*.ppt|Word Files (*.doc)|*.doc|Flash Files (*.swf)|*.swf|All Files (*.*)|*.*||";
	CFileDialog dlg(TRUE, _T("*.ppt"), NULL, 
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, NULL);
	if(dlg.DoModal() == IDCANCEL) 
		return FALSE;

	CString strFilePath = dlg.GetPathName();	//	获得文件路径
	CString strFileName = dlg.GetFileName();
	CString strExtName = dlg.GetFileExt();
	if(strFilePath.IsEmpty())
		return FALSE;
	strExtName.MakeLower();
	if(strExtName != "ppt" && strExtName != "swf" && strExtName != "doc") {
		MessageBox(_T("对不起，您选择的课件类型无法打开!"), NULL, MB_ICONERROR);
		return FALSE;
	}

	CMyView* pViewNew = NULL;
	if(strExtName == _T("ppt")) {
		CPptView* pView = new CPptView;
		pViewNew = pView;		
		
	} else if(strExtName == _T("swf")) {
		CFlashView* pView = new CFlashView;
		if(!pView->Create(NULL, NULL, WS_CHILD | WS_VISIBLE, 
				CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST))
			return FALSE;
		pView->SwitchToThisCntrItem();
		AddView(strFileName, pView, strExtName);
		pView->LoadMovie(strFilePath);
		pView->Stop();
		return TRUE;		
	} else if(strExtName == _T("doc")) {
		CWordView* pView = new CWordView;
		pViewNew = pView;
	}

	if(!pViewNew->Create(NULL, NULL, WS_CHILD | WS_VISIBLE, 
				CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST))
			return FALSE;
	if(strExtName != _T("swf")) {
		pViewNew->AddNewCntrItemFromFile(strFilePath);
		pViewNew->SwitchToThisCntrItem();
	}
	AddView(strFileName, pViewNew, strExtName);

	return TRUE;
}

BOOL CMainFrame::CreateCourseWareToolBar()
{
	if (!m_wndCWToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_SIZE_DYNAMIC) ||
		!m_wndCWToolBar.LoadToolBar(IDR_CW_TOOLBAR))
	{
		TRACE0("Failed to create toolbar\n");
		return FALSE;      // fail to create
	}

	m_wndCWToolBar.SetWindowText(_T("CourseWare"));

	// 设置文字  
	std::vector<CString> vecStr;
	vecStr.push_back(_T("打开课件"));
	vecStr.push_back(_T("添加课件"));
	vecStr.push_back(_T("批量添加"));
	vecStr.push_back(_T("删除课件"));
	vecStr.push_back(_T("转到目录"));
	m_wndCWToolBar.SetButtonTextArray(vecStr);

	/////////////调整工具条/////////////////
	CRect rect;
	CSize sizeMax(0, 0);
	CToolBarCtrl& bar = m_wndCWToolBar.GetToolBarCtrl();
		
	for (int nIndex = bar.GetButtonCount() - 1; nIndex >= 0; nIndex--)
	{
		bar.GetItemRect(nIndex, rect);

		rect.NormalizeRect();
		sizeMax.cx = __max(rect.Size().cx, sizeMax.cx);
		sizeMax.cy = __max(rect.Size().cy, sizeMax.cy);
	}
	sizeMax.cx += 55;
	m_wndCWToolBar.SetSizes(sizeMax, CSize(16,15));

	return TRUE;
}

BOOL CMainFrame::CreateNavigateToolBar()
{
	if (!m_wndNavigateToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_SIZE_DYNAMIC) ||
		!m_wndNavigateToolBar.LoadToolBar(IDR_NAVIGATE_TOOLBAR))
	{
		TRACE0("Failed to create toolbar\n");
		return FALSE;      // fail to create
	}

	m_wndNavigateToolBar.SetWindowText(_T("Navigate"));

	// 设置文字  
	std::vector<CString> vecStr;
	vecStr.push_back(_T("返回"));
	vecStr.push_back(_T("前进"));
	vecStr.push_back(_T("停止"));
	vecStr.push_back(_T("刷新"));
	vecStr.push_back(_T("转到"));
	m_wndNavigateToolBar.SetButtonTextArray(vecStr);

	/////////////调整工具条/////////////////
	CRect rect;
	CSize sizeMax(0, 0);
	CToolBarCtrl& bar = m_wndNavigateToolBar.GetToolBarCtrl();
		
	for (int nIndex = bar.GetButtonCount() - 1; nIndex >= 0; nIndex--)
	{
		bar.GetItemRect(nIndex, rect);

		rect.NormalizeRect();
		sizeMax.cx = __max(rect.Size().cx, sizeMax.cx);
		sizeMax.cy = __max(rect.Size().cy, sizeMax.cy);
	}
	sizeMax.cx += 30;
	m_wndNavigateToolBar.SetSizes(sizeMax, CSize(16,15));

	// Create the static 
    m_wndNavigateToolBar.SetButtonInfo(5, ID_NAVIGATE_TEXT, TBBS_SEPARATOR, 50);
    CRect rcStatic;
    m_wndNavigateToolBar.GetItemRect(5, &rcStatic);
	if(!m_wndAddressText.Create(_T("地址:"), WS_CHILD | WS_VISIBLE | SS_CENTER | SS_CENTERIMAGE, 
		rcStatic, &m_wndNavigateToolBar, 255))
	{
	    TRACE("Failed to create static\n");
        return FALSE;
    }

	//	添加组合框
	if (!m_wndNavigateToolBar.CreateComboBox(m_wndNavigateToolBar.m_comboBox,
			6, 700, 400, 300))
	{
		TRACE0("Failed to create toolbar's combo box\n");
		return -1;      // fail to create
	}	

	return TRUE;
}

void CMainFrame::OnViewCoursewareGuide() 
{
	m_bVisibleGuideBar = m_wndGuideBar.IsWindowVisible();
	if(!m_wndGuideBar.IsFloating())
	{				
		ShowControlBar(&m_wndGuideBar, m_bVisibleGuideBar ? FALSE : TRUE, FALSE);
	} else {
		::ShowWindow(m_wndGuideBar.m_hWnd, m_bVisibleGuideBar ? SW_HIDE : SW_SHOW);
	}
}

void CMainFrame::OnUpdateViewCoursewareGuide(CCmdUI* pCmdUI) 
{
	if(!m_wndGuideBar.IsFloating()) {	
		CAutoHideBar* pAutoHideBar = NULL;
		switch(m_wndGuideBar.GetDockBarID())								
		{															
			case AFX_IDW_DOCKBAR_TOP:								
				pAutoHideBar = &m_AutoHideBar[0];					
				break;												
			case AFX_IDW_DOCKBAR_LEFT:								
				pAutoHideBar = &m_AutoHideBar[1];					
				break;												
			case AFX_IDW_DOCKBAR_RIGHT:								
				pAutoHideBar = &m_AutoHideBar[2];					
				break;												
			case AFX_IDW_DOCKBAR_BOTTOM:							
				pAutoHideBar = &m_AutoHideBar[3];					
				break;												
		}
		if(pAutoHideBar->IsWindowVisible()) {
			pCmdUI->Enable(FALSE);
			return;
		}
	}

	pCmdUI->SetCheck(m_wndGuideBar.IsWindowVisible());
}

void CMainFrame::OnViewCoursewarePreview() 
{
	// TODO: Add your command handler code here
	
}

void CMainFrame::OnUpdateViewCoursewarePreview(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

void CMainFrame::OnViewToolbarFlash() 
{
	ShowControlBar(&m_wndFlashToolBar, !m_wndFlashToolBar.IsWindowVisible(), FALSE);
}

void CMainFrame::OnUpdateViewToolbarFlash(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_wndFlashToolBar.IsWindowVisible());
}

void CMainFrame::OnViewToolbarGuide() 
{
	m_bVisibleNavigateToolBar = m_wndNavigateToolBar.IsWindowVisible();
	ShowControlBar(&m_wndNavigateToolBar, !m_bVisibleNavigateToolBar, FALSE);
}

void CMainFrame::OnUpdateViewToolbarGuide(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_wndNavigateToolBar.IsWindowVisible());
}

void CMainFrame::OnOpenMycomputer() 
{
	CView* pView = GetActiveView();
	if(pView->GetRuntimeClass()->m_lpszClassName == _T("CMTASView")) {
		CMTASView* pMTASView = (CMTASView*)pView;
		pMTASView->Navigate2("::{20D04FE0-3AEA-1069-A2D8-08002B30309D}");
	}
}

void CMainFrame::OnOpenMydocument() 
{
	CView* pView = GetActiveView();
	if(pView->GetRuntimeClass()->m_lpszClassName == _T("CMTASView")) {
		CMTASView* pMTASView = (CMTASView*)pView;
		pMTASView->Navigate2("::{450D8FBA-AD25-11D0-98A8-0800361B1103}");
	}
}


BOOL CMainFrame::CreateTreeGuideBar()
{
	if (!m_wndTreeGuideBar.Create(_T("课程导航"), this, 345))
    {
        TRACE0("Failed to create mybar\n");
        return -1;      // fail to create
	}

	m_wndTreeGuideBar.SetSCBStyle(m_wndTreeGuideBar.GetSCBStyle() |
		SCBS_SIZECHILD);
    m_wndTreeGuideBar.SetBarStyle(m_wndTreeGuideBar.GetBarStyle() |
        CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC);	
    m_wndTreeGuideBar.EnableDocking(CBRS_ALIGN_ANY);	
    DockControlBar(&m_wndTreeGuideBar, AFX_IDW_DOCKBAR_LEFT);

	return TRUE;
}

void CMainFrame::OnViewCoursewareAssort() 
{
	m_bVisibleTreeGuideBar = m_wndTreeGuideBar.IsWindowVisible();
	if(!m_wndTreeGuideBar.IsFloating())
	{		
		ShowControlBar(&m_wndTreeGuideBar, m_bVisibleTreeGuideBar ? FALSE : TRUE, FALSE);
	} else {
		::ShowWindow(m_wndTreeGuideBar.m_hWnd, m_bVisibleTreeGuideBar ? SW_HIDE : SW_SHOW);
	}

}

void CMainFrame::OnUpdateViewCoursewareAssort(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_wndTreeGuideBar.IsWindowVisible());
}

void CMainFrame::OnViewClock() 
{
	m_wndClock.ShowWindow(m_wndClock.IsWindowVisible() ? SW_HIDE : SW_SHOW);
	m_bVisibleClock = m_wndClock.IsWindowVisible();
}

BOOL CMainFrame::CreateClockWnd()
{
	if(!m_wndClock.Create(IDD_CLOCK_DIALOG, this))
		return FALSE;

	int cxScreen = ::GetSystemMetrics(SM_CXSCREEN);
	int cyScreen = ::GetSystemMetrics(SM_CYSCREEN);
	int x, y;
/*	CRect rt;
	m_wndClock.GetWindowRect(rt);
	x = (cxScreen - rt.Width()) / 2;
	y = (cyScreen - rt.Height()) / 2 - 50;
*/
	x = cxScreen - 250;
	y = 10;
	m_wndClock.SetWindowPos(NULL, x, y, 0, 0, SWP_NOSIZE | SWP_NOREDRAW);
	m_wndClock.ShowWindow(SW_SHOW);

	return TRUE;
}

void CMainFrame::OnUpdateViewClock(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_wndClock.IsWindowVisible());
}

void CMainFrame::OnUpdateOpenMycomputer(CCmdUI* pCmdUI) 
{
	CView* pActiveView = GetActiveView();
	CMTASView* pMTASView = dynamic_cast<CMTASView*>(pActiveView);
	pCmdUI->Enable(pMTASView ? TRUE : FALSE);
}

void CMainFrame::OnUpdateOpenMydocument(CCmdUI* pCmdUI) 
{
	CView* pActiveView = GetActiveView();
	CMTASView* pMTASView = dynamic_cast<CMTASView*>(pActiveView);
	pCmdUI->Enable(pMTASView ? TRUE : FALSE);
}

void CMainFrame::FullScreen()
{
	m_bFullScreen = TRUE;
	m_bVisibleClock = m_wndClock.IsWindowVisible();
	m_bVisibleStatusBar = m_wndStatusBar.IsWindowVisible();
	m_bVisibleTreeGuideBar = m_wndTreeGuideBar.IsWindowVisible();
	m_bVisibleGuideBar = m_wndGuideBar.IsWindowVisible();
	m_bVisibleCWToolBar = m_wndCWToolBar.IsWindowVisible();
	m_bVisibleNavigateToolBar = m_wndNavigateToolBar.IsWindowVisible();
	m_wndStatusBar.ShowWindow(SW_HIDE);   
	m_wndNavigateToolBar.ShowWindow(SW_HIDE);
	m_wndCWToolBar.ShowWindow(SW_HIDE);
	m_wndClock.ShowWindow(SW_HIDE);
	ShowControlBar(&m_wndTreeGuideBar, FALSE, FALSE);
	ShowControlBar(&m_wndGuideBar, FALSE, FALSE);

	::GetWindowRect(m_hWnd, m_rtMainWnd);
	::GetWindowRect(::GetDesktopWindow(), m_rtDesktop);   
	long lStyle = ::GetWindowLong(m_hWnd, GWL_STYLE);
	lStyle &= ~WS_CAPTION;
	::SetWindowLong(m_hWnd, GWL_STYLE, lStyle);
	MoveWindow(m_rtDesktop, TRUE);

	FloatControlBar(&m_wndFlashToolBar, CPoint(50, 50)); 
	m_wndFlashToolBar.EnableDocking(FALSE);
	m_wndFlashToolBar.ShowWindow(SW_SHOW);

	RecalcLayout();
}

void CMainFrame::NormalScreen()
{
	m_bFullScreen = FALSE;
	m_wndStatusBar.ShowWindow(m_bVisibleStatusBar ? SW_SHOW : SW_HIDE);   
	m_wndNavigateToolBar.ShowWindow(m_bVisibleNavigateToolBar ? SW_SHOW : SW_HIDE);
	m_wndCWToolBar.ShowWindow(m_bVisibleCWToolBar ? SW_SHOW : SW_HIDE);
	m_wndClock.ShowWindow(m_bVisibleClock ? SW_SHOW : SW_HIDE);
	ShowControlBar(&m_wndTreeGuideBar, m_bVisibleTreeGuideBar ? TRUE : FALSE, FALSE);
	ShowControlBar(&m_wndGuideBar, m_bVisibleGuideBar ? TRUE : FALSE, FALSE);

	long lStyle = ::GetWindowLong(m_hWnd, GWL_STYLE);
	lStyle |= WS_CAPTION;
	::SetWindowLong(m_hWnd, GWL_STYLE, lStyle);
	m_wndFlashToolBar.EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndFlashToolBar);
//	DockControlBarRightOf(&m_wndFlashToolBar, &m_wndCWToolBar);
	m_wndFlashToolBar.ShowWindow(SW_SHOW);
	MoveWindow(m_rtMainWnd, TRUE);
	RecalcLayout();
}

BOOL CMainFrame::IsFullScreen() const
{
	return m_bFullScreen;
}

void CMainFrame::OnViewToolbarCourseware() 
{
	m_wndCWToolBar.ShowWindow(m_wndCWToolBar.IsWindowVisible() ? FALSE : TRUE);
}

void CMainFrame::OnUpdateViewToolbarCourseware(CCmdUI* pCmdUI) 
{
	m_bVisibleCWToolBar = m_wndCWToolBar.IsWindowVisible();
	pCmdUI->SetCheck(m_bVisibleCWToolBar ? TRUE : FALSE);
}

void CMainFrame::OnPageAddBlank() 
{
	AddBlankPage();
}

void CMainFrame::OnPageCloseCurrent() 
{
	DeleteActiveView();
}

void CMainFrame::OnUpdatePageAddBlank(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

void CMainFrame::OnUpdatePageCloseCurrent(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_wndTab.GetItemCount() < 2 ? FALSE : TRUE);
}

void CMainFrame::OnPageFirst() 
{
	int nCount = m_wndTab.GetItemCount();
	int nCurItem = m_wndTab.GetCurSel();

	if(nCurItem > 0)
		SetCurView(0);
}

void CMainFrame::OnUpdatePageFirst(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

void CMainFrame::OnPageLast() 
{
	int nCount = m_wndTab.GetItemCount();
	int nCurItem = m_wndTab.GetCurSel();

	if(nCurItem != nCount - 1)
		SetCurView(nCount - 1);
}

void CMainFrame::OnUpdatePageLast(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

void CMainFrame::OnPagePrevious() 
{
	int nCount = m_wndTab.GetItemCount();
	int nCurItem = m_wndTab.GetCurSel();

	if(nCurItem > 0)
		SetCurView(nCurItem - 1);
}

void CMainFrame::OnUpdatePagePrevious(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

void CMainFrame::OnPageNext() 
{
	int nCount = m_wndTab.GetItemCount();
	int nCurItem = m_wndTab.GetCurSel();

	if(nCurItem < nCount - 1)
		SetCurView(nCurItem + 1);
}

void CMainFrame::OnUpdatePageNext(CCmdUI* pCmdUI) 
{

}

void CMainFrame::OnPageProperty() 
{
	SetViewProperty();
}

void CMainFrame::OnUpdatePageProperty(CCmdUI* pCmdUI) 
{
	CView* pActiveView = GetActiveView();
	CString strClassName = pActiveView->GetRuntimeClass()->m_lpszClassName;
	pCmdUI->Enable(strClassName == _T("CMTASView") ? TRUE : FALSE);
}

void CMainFrame::SetViewProperty()
{
	DWORD dwData;
	int ndx = m_wndTab.GetCurSel();
	m_wndTab.GetItemData(ndx,dwData);

	CMTASView* pView = (CMTASView*)dwData;

	CDlgProperties dlg;
	dlg.m_sLabel = pView->m_sLabel;
	dlg.m_sTooltip = pView->m_sTooltip;
	dlg.m_sUrl = pView->m_sUrl;
	if(dlg.DoModal()==IDOK)
	{
		pView->m_sLabel = dlg.m_sLabel;
		m_wndTab.SetItemText(ndx,dlg.m_sLabel);
		pView->m_sTooltip = dlg.m_sTooltip;
		m_wndTab.SetItemTooltipText(ndx,dlg.m_sTooltip);
		pView->m_sUrl = dlg.m_sUrl;
		pView->Navigate2(dlg.m_sUrl,NULL,NULL);
	}	
}
