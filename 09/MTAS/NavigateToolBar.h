#if !defined(AFX_NAVIGATETOOLBAR_H__561DAB11_A2DD_4171_896A_7E789B9A0F00__INCLUDED_)
#define AFX_NAVIGATETOOLBAR_H__561DAB11_A2DD_4171_896A_7E789B9A0F00__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NavigateToolBar.h : header file
//

#include "./tools/toolbarxp.h"
#include "AddressComboBox.h"
/////////////////////////////////////////////////////////////////////////////
// CNavigateToolBar window

class CNavigateToolBar : public CToolBarXP
{
// Construction
public:
	CNavigateToolBar();

// Attributes
public:
	CAddressComboBox	m_comboBox;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNavigateToolBar)
	//}}AFX_VIRTUAL

// Implementation
public:
	BOOL CreateComboBox(class CComboBox& comboBox, UINT nIndex, 
		UINT nID, int nWidth, int nDropHeight);
	virtual ~CNavigateToolBar();

	// Generated message map functions
protected:
	CImageList	  m_imgNavigateToolBar;

	//{{AFX_MSG(CNavigateToolBar)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NAVIGATETOOLBAR_H__561DAB11_A2DD_4171_896A_7E789B9A0F00__INCLUDED_)
