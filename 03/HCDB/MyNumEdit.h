#if !defined(AFX_MYNUMEDIT_H__CCAB4989_EA31_43B9_AB73_F59992D0D3AD__INCLUDED_)
#define AFX_MYNUMEDIT_H__CCAB4989_EA31_43B9_AB73_F59992D0D3AD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyNumEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyNumEdit window

class CMyNumEdit : public CEdit
{
// Construction
public:
	CMyNumEdit();
    float num;
	float t;
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyNumEdit)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_VIRTUAL

// Implementation
public:
	int m_allnum;
	int m_lastnum[6];
	int lastnum;
	bool m_intdouflag;
	virtual ~CMyNumEdit();

	// Generated message map functions
protected:
	//{{AFX_MSG(CMyNumEdit)
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYNUMEDIT_H__CCAB4989_EA31_43B9_AB73_F59992D0D3AD__INCLUDED_)
