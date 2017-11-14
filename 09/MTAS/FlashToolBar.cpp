// FlashToolBar.cpp : implementation file
//

#include "stdafx.h"
#include "mtas.h"
#include "FlashToolBar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFlashToolBar

CFlashToolBar::CFlashToolBar()
{
}

CFlashToolBar::~CFlashToolBar()
{
}


BEGIN_MESSAGE_MAP(CFlashToolBar, CToolBarXP)
	//{{AFX_MSG_MAP(CFlashToolBar)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFlashToolBar message handlers

BOOL CFlashToolBar::CreateComboBox(CComboBox &comboBox, UINT nIndex, 
								   UINT nID, int nWidth, int nDropHeight)
{
	// Create the combo box
    SetButtonInfo(nIndex, nID, TBBS_SEPARATOR, nWidth);

    CRect rect;
    GetItemRect(nIndex, &rect);
    rect.top = 2;
    rect.bottom = rect.top + nDropHeight;
    if (!comboBox.Create(CBS_DROPDOWNLIST | WS_VISIBLE | WS_TABSTOP | WS_VSCROLL,
                         rect, this, nID))
    {
        TRACE("Failed to create combo-box\n");
        return FALSE;
    }

    return TRUE;
}

int CFlashToolBar::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CToolBarXP::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	//	加载工具条图标
	m_imgFlashToolBar.Create(16, 16, ILC_MASK | ILC_COLOR32, 9, 9);  
	UINT nIconID[] = {
		IDI_PLAY, IDI_PAUSE, IDI_STOP, IDI_FULL_SCREEN, IDI_NORMAL_SCREEN
	};
	for(int i = 0; i < sizeof(nIconID) / sizeof(UINT); ++i) {
		HICON m_icon;  
		m_icon = AfxGetApp()->LoadIcon(nIconID[i]);  
		m_imgFlashToolBar.Add(m_icon);  
	}

	GetToolBarCtrl().SetImageList(&m_imgFlashToolBar); 

	return 0;
}
