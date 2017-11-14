// NavigateToolBar.cpp : implementation file
//

#include "stdafx.h"
#include "mtas.h"
#include "NavigateToolBar.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNavigateToolBar

CNavigateToolBar::CNavigateToolBar()
{
}

CNavigateToolBar::~CNavigateToolBar()
{
}


BEGIN_MESSAGE_MAP(CNavigateToolBar, CToolBarXP)
	//{{AFX_MSG_MAP(CNavigateToolBar)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


BOOL CNavigateToolBar::CreateComboBox(class CComboBox& comboBox, UINT nIndex, 
					UINT nID, int nWidth, int nDropHeight)
{
	// Create the combo box
    SetButtonInfo(nIndex, nID, TBBS_SEPARATOR, nWidth);

    CRect rect;
    GetItemRect(nIndex, &rect);
    rect.top = 2;
    rect.bottom = rect.top + nDropHeight;
    if (!comboBox.Create(CBS_DROPDOWN | WS_VISIBLE | WS_TABSTOP | WS_VSCROLL,
                         rect, this, nID))
    {
        TRACE("Failed to create combo-box\n");
        return FALSE;
    }

    return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CNavigateToolBar message handlers

int CNavigateToolBar::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CToolBarXP::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	m_imgNavigateToolBar.Create(16, 16, ILC_MASK | ILC_COLOR32, 9, 9);  
	UINT nIconID[] = {
		IDI_NAVIGATE_BACKWARD, IDI_NAVIGATE_FORWARD, IDI_NAVIGATE_STOP,
		IDI_NAVIGATE_REFRESH, IDI_NAVIGATE_GOTO, IDI_NAVIGATE_GOTO, IDI_NAVIGATE_GOTO, IDI_NAVIGATE_GOTO
	};
	for(int i = 0; i < sizeof(nIconID) / sizeof(UINT); ++i) {
		HICON m_icon;  
		m_icon = AfxGetApp()->LoadIcon(nIconID[i]);  
		m_imgNavigateToolBar.Add(m_icon);  
	}
	GetToolBarCtrl().SetImageList(&m_imgNavigateToolBar); 	

	return 0;
}
