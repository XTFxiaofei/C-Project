#if !defined(AFX_MYLIST_H__6B728410_BFF2_4991_ADC0_4DBE8481A31F__INCLUDED_)
#define AFX_MYLIST_H__6B728410_BFF2_4991_ADC0_4DBE8481A31F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyList.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyList window

class CMyList : public CListCtrl
{
// Construction
public:
	CMyList();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyList)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyList();

	// Generated message map functions
protected:
	//{{AFX_MSG(CMyList)
	afx_msg void OnItemchanged(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYLIST_H__6B728410_BFF2_4991_ADC0_4DBE8481A31F__INCLUDED_)
