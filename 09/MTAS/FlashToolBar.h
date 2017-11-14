#if !defined(AFX_FLASHTOOLBAR_H__90C4C0DB_F285_4331_B0B7_CAA34FB239BD__INCLUDED_)
#define AFX_FLASHTOOLBAR_H__90C4C0DB_F285_4331_B0B7_CAA34FB239BD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FlashToolBar.h : header file
//

#include "./tools/toolbarxp.h"
#include "FlashComboBox.h"
/////////////////////////////////////////////////////////////////////////////
// CFlashToolBar window

class CFlashToolBar : public CToolBarXP
{
// Construction
public:
	CFlashToolBar();

// Attributes
public:
	CFlashComboBox m_comboBox;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFlashToolBar)
	//}}AFX_VIRTUAL

// Implementation
public:
	BOOL CreateComboBox(class CComboBox& comboBox, UINT nIndex, 
		UINT nID, int nWidth, int nDropHeight);
	virtual ~CFlashToolBar();

	// Generated message map functions
protected:
	CImageList	  m_imgFlashToolBar;

	//{{AFX_MSG(CFlashToolBar)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FLASHTOOLBAR_H__90C4C0DB_F285_4331_B0B7_CAA34FB239BD__INCLUDED_)
