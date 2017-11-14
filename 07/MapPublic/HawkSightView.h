#if !defined(AFX_HAWKSIGHTVIEW_H__650AD027_C53E_406F_8BEE_BAB94C5E37B2__INCLUDED_)
#define AFX_HAWKSIGHTVIEW_H__650AD027_C53E_406F_8BEE_BAB94C5E37B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HawkSightView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHawkSightView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

#include "HawkView.h"
#include "SightDlg.h"
class CHawkSightView : public CFormView
{
protected:
	CHawkSightView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CHawkSightView)

// Form Data
public:
	//{{AFX_DATA(CHawkSightView)
	enum { IDD = IDD_HAWK_SIGHT_FORMVIEW };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	CPropertySheet m_Sheet;
    CHawkView  m_hawkview;
    CSightDlg m_sightdlg;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHawkSightView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CHawkSightView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CHawkSightView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HAWKSIGHTVIEW_H__650AD027_C53E_406F_8BEE_BAB94C5E37B2__INCLUDED_)
