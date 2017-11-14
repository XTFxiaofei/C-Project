#if !defined(AFX_PPTVIEW_H__B0562C00_A277_4EB3_95B4_E276B8182B0E__INCLUDED_)
#define AFX_PPTVIEW_H__B0562C00_A277_4EB3_95B4_E276B8182B0E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PptView.h : header file
//

#include "MyView.h"
/////////////////////////////////////////////////////////////////////////////
// CPptView view

class CPptView : public CMyView
{
public:
	CPptView(BOOL bBlankPage = FALSE);           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CPptView)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPptView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CPptView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CPptView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PPTVIEW_H__B0562C00_A277_4EB3_95B4_E276B8182B0E__INCLUDED_)
