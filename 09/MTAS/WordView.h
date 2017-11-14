#if !defined(AFX_WORDVIEW_H__26E16D9D_06A1_43F3_8924_DFA9A9C781A2__INCLUDED_)
#define AFX_WORDVIEW_H__26E16D9D_06A1_43F3_8924_DFA9A9C781A2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WordView.h : header file
//

#include "MyView.h"
/////////////////////////////////////////////////////////////////////////////
// CWordView view

class CWordView : public CMyView
{
public:
	CWordView(BOOL bBlankPage = FALSE);           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CWordView)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWordView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CWordView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CWordView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WORDVIEW_H__26E16D9D_06A1_43F3_8924_DFA9A9C781A2__INCLUDED_)
