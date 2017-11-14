#if !defined(AFX_PPTLISTCTRL_H__38FEF16F_DBAE_4114_9AC9_1355405BCA86__INCLUDED_)
#define AFX_PPTLISTCTRL_H__38FEF16F_DBAE_4114_9AC9_1355405BCA86__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PptListCtrl.h : header file
//

#include "MyListCtrl.h"

/////////////////////////////////////////////////////////////////////////////
// CPptListCtrl window

class CPptListCtrl : public CMyListCtrl
{
// Construction
public:
	CPptListCtrl();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPptListCtrl)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPptListCtrl();

	//	IUpdate
	virtual void UpdateDisplay();
	// Generated message map functions
protected:
	//{{AFX_MSG(CPptListCtrl)
	afx_msg void OnRclick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnAddPpt();
	afx_msg void OnDelPpt();
	afx_msg void OnOpenPpt();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg int  OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnColumnclick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnDirPpt();
	afx_msg void OnAddPpts();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PPTLISTCTRL_H__38FEF16F_DBAE_4114_9AC9_1355405BCA86__INCLUDED_)
