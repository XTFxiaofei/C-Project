//{{AFX_INCLUDES()
#include "mschart.h"
//}}AFX_INCLUDES
#if !defined(AFX_PAGE3_H__A8F4B4BB_64CF_4D2C_BE16_29C97B8DB561__INCLUDED_)
#define AFX_PAGE3_H__A8F4B4BB_64CF_4D2C_BE16_29C97B8DB561__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PAGE3.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PAGE3 dialog

class PAGE3 : public CDialog
{
// Construction
public:
	PAGE3(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PAGE3)
	enum { IDD = IDD_PAGE3 };
	CMSChart	m_Chart;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PAGE3)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void DrawChart();
	void InitChart();
	// Generated message map functions
	//{{AFX_MSG(PAGE3)
	virtual BOOL OnInitDialog();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDrawline();
	afx_msg void OnDrawcombi();
	afx_msg void OnDrawpie();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGE3_H__A8F4B4BB_64CF_4D2C_BE16_29C97B8DB561__INCLUDED_)
