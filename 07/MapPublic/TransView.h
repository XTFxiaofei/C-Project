#if !defined(AFX_TRANSVIEW_H__A85AF6B7_F989_42CF_92C1_58E8B2E77C9D__INCLUDED_)
#define AFX_TRANSVIEW_H__A85AF6B7_F989_42CF_92C1_58E8B2E77C9D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TransView.h : header file
//
#include "InfoMation.h"
/////////////////////////////////////////////////////////////////////////////
// CTransView dialog

class CTransView : public CPropertyPage
{
	DECLARE_DYNCREATE(CTransView)

// Construction
public:
	CTransView();
	~CTransView();

// Dialog Data
	//{{AFX_DATA(CTransView)
	enum { IDD = IDD_TRANSFER };
	CComboBox	m_end;
	CComboBox	m_start;
	CString	m_scheme;
	//}}AFX_DATA

    CInfoMation m_InfoMation;
// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CTransView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CTransView)
	virtual BOOL OnInitDialog();
	afx_msg void OnButFind();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRANSVIEW_H__A85AF6B7_F989_42CF_92C1_58E8B2E77C9D__INCLUDED_)
