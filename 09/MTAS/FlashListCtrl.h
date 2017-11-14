#if !defined(AFX_FLASHLISTCTRL_H__809084AF_1F70_4D4C_83F2_2B5EA7A529BD__INCLUDED_)
#define AFX_FLASHLISTCTRL_H__809084AF_1F70_4D4C_83F2_2B5EA7A529BD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FlashListCtrl.h : header file
//

#include "MyListCtrl.h"

/////////////////////////////////////////////////////////////////////////////
// CFlashListCtrl window

class CFlashListCtrl : public CMyListCtrl
{
// Construction
public:
	CFlashListCtrl();

// Attributes
public:

// Operations
public:
	//	IUpdate
	virtual void UpdateDisplay();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFlashListCtrl)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFlashListCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CFlashListCtrl)
	afx_msg void OnRclick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnAddFlash();
	afx_msg void OnDelFlash();
	afx_msg void OnOpenFlash();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnColumnclick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnDirFlash();
	afx_msg void OnAddFlashs();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FLASHLISTCTRL_H__809084AF_1F70_4D4C_83F2_2B5EA7A529BD__INCLUDED_)
