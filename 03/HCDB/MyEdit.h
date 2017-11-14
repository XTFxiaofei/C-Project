#if !defined(AFX_MYEDIT_H__B4080AD2_04B6_4BB5_8F42_D66F08968C60__INCLUDED_)
#define AFX_MYEDIT_H__B4080AD2_04B6_4BB5_8F42_D66F08968C60__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyEdit window

class CMyEdit : public CEdit
{
// Construction
public:
	CMyEdit();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyEdit)
	//}}AFX_VIRTUAL

// Implementation
public:
	CString m_querystr;
	int m_backnum;
	int InsertItem;
	void Refrish();
	CString querystr;
	virtual ~CMyEdit();
	// Generated message map functions
protected:
	//{{AFX_MSG(CMyEdit)
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYEDIT_H__B4080AD2_04B6_4BB5_8F42_D66F08968C60__INCLUDED_)
