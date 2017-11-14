#if !defined(AFX_SUBFORMVIEW_H__0EB3D5E1_743D_450F_8CD5_E512463F6F2A__INCLUDED_)
#define AFX_SUBFORMVIEW_H__0EB3D5E1_743D_450F_8CD5_E512463F6F2A__INCLUDED_
#include "SubOperProPage.h"
#include "SubQueryProPage.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SubFormView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSubFormView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CSubFormView : public CFormView
{
protected:
	CSubFormView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CSubFormView)

	CPropertySheet m_Sheet;
    CSubOperProPage  m_suboper;
    CSubQueryProPage m_subquery;
// Form Data
public:
	//{{AFX_DATA(CSubFormView)
	enum { IDD = IDD_Sub_FORMVIEW };
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSubFormView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CSubFormView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CSubFormView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUBFORMVIEW_H__0EB3D5E1_743D_450F_8CD5_E512463F6F2A__INCLUDED_)
