#if !defined(AFX_WORDLISTCTRL_H__4796F187_1E25_43F6_A777_033A32F758D1__INCLUDED_)
#define AFX_WORDLISTCTRL_H__4796F187_1E25_43F6_A777_033A32F758D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WordListCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWordListCtrl window

class CWordListCtrl : public CMyListCtrl
{
// Construction
public:
	CWordListCtrl();

// Attributes
public:

// Operations
public:
	//	IUpdate
	virtual void UpdateDisplay();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWordListCtrl)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CWordListCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CWordListCtrl)
	afx_msg void OnRclick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnOpenWord();
	afx_msg void OnAddWord();
	afx_msg void OnDelWord();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnColumnclick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnDirWord();
	afx_msg void OnAddWords();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WORDLISTCTRL_H__4796F187_1E25_43F6_A777_033A32F758D1__INCLUDED_)
