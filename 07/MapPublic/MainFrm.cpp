// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "MapPublic.h"
#include "MapPublicView.h"
#include "MainFrm.h"
#include<MMSYSTEM.H>

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
	ON_WM_TIMER()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_SKIN, OnSkin)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_SEPARATOR,
	ID_SEPARATOR,
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
	
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
//	m_color=RGB(193,193,255);
	m_color=RGB(193,0,0);
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	//创建扩展工具栏

	if(!m_wndReBar.Create(this))
	{
		return -1;
	}	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC))
	{
		return -1;      
	}
	m_wndToolBar.LoadToolBar(IDR_MAINFRAME);
	m_wndReBar.AddBar(&m_wndToolBar);

    /************************************************************************/
    /*                   在工具栏上添加数字时钟                                                                     */
    /************************************************************************/
	if(!m_clock.Create("",WS_CHILD|WS_VISIBLE,CRect(0,0,135,30),this,IDC_CLOCK))
	{
		return -1;
	}
	m_wndReBar.AddBar(&m_clock,NULL, NULL, RBBS_FIXEDSIZE | RBBS_FIXEDBMP);
	m_clock.SetStyle(CLEDClock::XDC_SECOND);
	m_clock.SetColor(RGB(0,255,0));
	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	/*--------------------------------------------------------------*/
	////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
	if (!m_featureToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE 
		                           | CBRS_LEFT	| CBRS_GRIPPER | CBRS_TOOLTIPS 
								   | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) 
		|| !m_featureToolBar.LoadToolBar(IDR_TOOLBAR1))
	{
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}

    if(!CreateMyEditBox())
		AfxMessageBox("创建编辑框失败！");
	// 使工具栏可停靠
	m_featureToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);	
	DockControlBar(&m_featureToolBar);
	this->SetTimer(1,500,NULL);

	//------------------------------------------------------------
	//coolmeun的安装
	AddMenu();
	//----------------------------------------------------------------


	return 0;
}

void CMainFrame::AddMenu()
{
	m_CoolMenu.Attach(GetMenu()->GetSafeHmenu());//菜单连接
	CCoolMenu::SubClass(this->GetSafeHwnd());//子类化
//	CCoolMenu::SetLogoText("hello", RGB(0, 0, 255));
	
	CCoolMenu::SetLogoImage(IDB_LOGOBAR2,0);
//	CCoolMenu::SetBackGroundBmp(IDB_BKBMP);
	
 //   CCoolMenuTheme::SetTheme(MENU_STYLE_XP);
    CCoolMenu::SetStyle(CCoolMenu::GetStyle() & ~CMS_ICONBAR);
	CCoolMenu::SetMenuColor(m_color);//菜单背景色
	CCoolMenu::SetIconBarColor(::GetSysColor(COLOR_3DFACE));
	
	CCoolMenu::SetLightBarColor(RGB(61, 128, 152));//高亮栏的边框的颜色
	
	CCoolMenu::SetLightBarStartColor(RGB(255, 255, 255));
	CCoolMenu::SetLightBarEndColor(RGB(77,109, 120));
	
	CCoolMenu::SetTextColor(RGB(0, 0, 0));
	CCoolMenu::SetHighLightColor(RGB(20, 20, 50));
	
/*	CMenuWndHook::m_crFrame[0] = RGB(120, 120, 158);
	CMenuWndHook::m_crFrame[1] = RGB(48, 50, 48);
	CMenuWndHook::m_crFrame[2] = RGB(255, 255, 255);
	CMenuWndHook::m_crFrame[3] = RGB(168, 168, 210);
	*/

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


BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) 
{
    if(!m_wndSplitter.CreateStatic(this,1,2))	
	{
		return false;
	}
	CRect rect;
	GetClientRect(&rect);

//////////////////////////////////////////////////////////////

	if(!m_wndSplitter.CreateView(0,0,RUNTIME_CLASS(CMapPublicView),CSize(rect.Width()*15/16,rect.Height()),pContext))
	{
		TRACE0("创建视图失败!");
		return false;
	}

	////////////////////////////////////////////////////////
	if(!m_wndSplitter2.CreateStatic(&m_wndSplitter,//父窗口
		3,1,//三行一列
		WS_CHILD|WS_VISIBLE|WS_BORDER,//子窗口有边框
		m_wndSplitter.IdFromRowCol(0,1)
		))
	{
		
		return false;
	}

	if(!m_wndSplitter2.CreateView(0,0,RUNTIME_CLASS(CMapControlView),CSize(0,rect.Height()*11/20),pContext))
	{
         TRACE0("创建视图失败!");
		 return false;
	}

	if(!m_wndSplitter2.CreateView(1,0,RUNTIME_CLASS(CAttribute),CSize(0,rect.Height()/4),pContext))
	{
		TRACE0("创建视图失败!");
		return false;
	}

	if(!m_wndSplitter2.CreateView(2,0,RUNTIME_CLASS(CHawkSightView),CSize(0,0),pContext))
	{
		TRACE0("创建视图失败!");
		return false;
	}

	return true;
}

BOOL CMainFrame::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{    
	return CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

void CMainFrame::DoDataExchange(CDataExchange* pDX) 
{
    DDX_Control(pDX, IDC_CLOCK, m_clock);	
	CFrameWnd::DoDataExchange(pDX);
}

int CMainFrame::CreateMyEditBox()
{
	int index = 0;
	CRect rect;
	while(m_wndToolBar.GetItemID(index)!=ID_MY_EDIT_BOX) 
		index++;
	m_wndToolBar.SetButtonInfo(index,
		ID_MY_EDIT_BOX, TBBS_SEPARATOR, 0);
    m_wndToolBar.GetItemRect(index, &rect);
	rect.top+=4;
	rect.bottom-=4;
	rect.right+=60;
    if (!m_wndToolBar.m_EditBox.Create(ES_AUTOHSCROLL|
						ES_LEFT|ES_NOHIDESEL|WS_BORDER|
						WS_CHILD,
		rect, &m_wndToolBar, ID_MY_EDIT_BOX))
    {
        TRACE0("Failed to create combo-box\n");
        return FALSE;
    }
    m_wndToolBar.m_EditBox.ShowWindow(SW_SHOW);
    m_wndToolBar.m_EditBox.SetFocus();
	return 1;
}

void CMainFrame::OnTimer(UINT nIDEvent) 
{
    static int icons[]={IDI_ICON1,IDI_ICON2,IDI_ICON3};
	static long index=0;
	HICON hIconOld;
	HICON hIconNew;
	hIconNew=AfxGetApp()->LoadIcon(icons[index++%3]);
	hIconOld=(HICON)GetClassLong(m_hWnd,GCL_HICON);
	ASSERT(hIconNew);
	ASSERT(hIconOld);
	if(hIconNew!=hIconOld)
	{
		DestroyIcon(hIconOld);
		SetClassLong(m_hWnd,GCL_HICON,(long)hIconNew);
		RedrawWindow(NULL,NULL,RDW_FRAME|RDW_ERASE);
	}	
	CFrameWnd::OnTimer(nIDEvent);
}

void CMainFrame::OnMouseMove(UINT nFlags, CPoint point) 
{
    
	CFrameWnd::OnMouseMove(nFlags, point);
}

void CMainFrame::OnSkin() 
{
   	CColorDialog colordlg;
    if(colordlg.DoModal()==IDOK)
	   m_color=colordlg.GetColor();
	CCoolMenu::SetMenuColor(m_color);//菜单背景色
}


BOOL CMainFrame::PlayResource(WORD wResourceID)
{	
// Get the handle to the current instance of the application
	HINSTANCE hInstance = AfxGetInstanceHandle();
    ASSERT (hInstance != NULL);
	
	// Find the WAVE resource
	HRSRC hResInfo = 
		FindResource(hInstance, MAKEINTRESOURCE(wResourceID), _T("WAVE"));
	if(hResInfo == NULL)
		return FALSE;
	
	// Load the WAVE resource
    HANDLE hRes = LoadResource(hInstance, hResInfo);
	if (hRes == NULL)
		return FALSE;
    
	// Lock the WAVE resource and play it
    LPSTR lpRes = (LPSTR) LockResource(hRes);
	if(lpRes==NULL)
		return FALSE;
    
	if (sndPlaySound(lpRes, SND_MEMORY | SND_ASYNC) == NULL)
		return FALSE;	
	
    // Free the WAVE resource and return success or failure.
    FreeResource(hRes);
	
	return TRUE;
}


void CMainFrame::OnClose() 
{
    CMapPublicApp *app=(CMapPublicApp *)AfxGetApp();
	app->m_pMainWnd->ShowWindow(SW_HIDE);
	m_dlg.DoModal();

	CFrameWnd::OnClose();
}

BOOL CMainFrame::PreTranslateMessage(MSG* pMsg) 
{
   	if (WM_KEYFIRST <= pMsg->message && pMsg->message <= WM_KEYLAST) 
	{
		if(pMsg->wParam==VK_RETURN )
		{
			HWND hWnd=::GetFocus();
			int iID=::GetDlgCtrlID(hWnd);
			if(iID==ID_MY_EDIT_BOX)//编辑框的标识
			{
				UpdateData(TRUE);
				CString viewstr;
                m_wndToolBar.m_EditBox.GetWindowText(viewstr);
				CMapPublicView *pView=(CMapPublicView *)(m_wndSplitter.GetPane(0,0));
               	pView->FindArea(viewstr);
              
			}
		}
	}
	return CFrameWnd::PreTranslateMessage(pMsg);
}
