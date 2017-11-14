#if !defined(AFX_CWTOOLBAR_H__223CD24B_EC6D_4B83_BD7B_65FBB8500B44__INCLUDED_)
#define AFX_CWTOOLBAR_H__223CD24B_EC6D_4B83_BD7B_65FBB8500B44__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CWToolBar.h : header file
//

#include "./tools/toolbarxp.h"
/////////////////////////////////////////////////////////////////////////////
// CCWToolBar window

class CCWToolBar : public CToolBarXP
{
// Construction
public:
	CCWToolBar();

// Attributes
public:
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCWToolBar)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCWToolBar();
	// Generated message map functions
protected:
	CImageList m_imgCWToolBar;

	//{{AFX_MSG(CCWToolBar)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CWTOOLBAR_H__223CD24B_EC6D_4B83_BD7B_65FBB8500B44__INCLUDED_)
