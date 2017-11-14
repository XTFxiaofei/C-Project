#if !defined(AFX_MYTREECTRL_H__919A0A81_912B_49B0_A773_342D9405B60D__INCLUDED_)
#define AFX_MYTREECTRL_H__919A0A81_912B_49B0_A773_342D9405B60D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyTreeCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyTreeCtrl window

class CMyTreeCtrl : public CTreeCtrl
{
// Construction
public:
	CMyTreeCtrl();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyTreeCtrl)
	protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
public:
	BOOL SetBKImage(LPCTSTR LpszResource);
	virtual ~CMyTreeCtrl();

	// Generated message map functions
protected:
	CBitmap m_bitmap;
	//{{AFX_MSG(CMyTreeCtrl)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnItemexpanded(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnItemexpanding(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnPaint();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYTREECTRL_H__919A0A81_912B_49B0_A773_342D9405B60D__INCLUDED_)
