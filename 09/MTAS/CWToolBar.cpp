// CWToolBar.cpp : implementation file
//

#include "stdafx.h"
#include "mtas.h"
#include "CWToolBar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCWToolBar

CCWToolBar::CCWToolBar()
{
}

CCWToolBar::~CCWToolBar()
{
}


BEGIN_MESSAGE_MAP(CCWToolBar, CToolBarXP)
	//{{AFX_MSG_MAP(CCWToolBar)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCWToolBar message handlers

int CCWToolBar::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CToolBarXP::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	m_imgCWToolBar.Create(16, 16, ILC_MASK | ILC_COLOR32, 9, 9);  
	UINT nIconID[] = {
		IDI_CW_OPEN, IDI_CW_ADD, IDI_CW_ADDS, IDI_CW_DEL, IDI_CW_DIR
	};
	for(int i = 0; i < sizeof(nIconID) / sizeof(UINT); ++i) {
		HICON m_icon;  
		m_icon = AfxGetApp()->LoadIcon(nIconID[i]);  
		m_imgCWToolBar.Add(m_icon);  
	}
	GetToolBarCtrl().SetImageList(&m_imgCWToolBar); 	
	
	return 0;
}


