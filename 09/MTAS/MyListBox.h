#if !defined(AFX_MYLISTBOX_H__D043D221_5E68_4333_B2A5_6587A798791B__INCLUDED_)
#define AFX_MYLISTBOX_H__D043D221_5E68_4333_B2A5_6587A798791B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyListBox.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyListBox window

class CMyListBox : public CListBox
{
// Construction
public:
	CMyListBox();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyListBox)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyListBox();

	// Generated message map functions
protected:
	//{{AFX_MSG(CMyListBox)
	afx_msg void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	afx_msg void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYLISTBOX_H__D043D221_5E68_4333_B2A5_6587A798791B__INCLUDED_)
