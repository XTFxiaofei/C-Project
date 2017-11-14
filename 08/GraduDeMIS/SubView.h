#if !defined(AFX_SUBVIEW_H__84C6D5FB_CE4E_4FBA_B62C_A4FB3231ED8C__INCLUDED_)
#define AFX_SUBVIEW_H__84C6D5FB_CE4E_4FBA_B62C_A4FB3231ED8C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SubView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSubView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CSubView : public CFormView
{
protected:
	CSubView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CSubView)

// Form Data
public:
	//{{AFX_DATA(CSubView)
	enum { IDD = IDD_Sub_FORMVIEW };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSubView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CSubView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CSubView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUBVIEW_H__84C6D5FB_CE4E_4FBA_B62C_A4FB3231ED8C__INCLUDED_)
