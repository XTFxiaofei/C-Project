//{{AFX_INCLUDES()
#include "webbrowser2.h"
//}}AFX_INCLUDES
#if !defined(AFX_BANZGHU_H__5F7EB3AE_A31C_4DD9_8292_EEE794EF4EC2__INCLUDED_)
#define AFX_BANZGHU_H__5F7EB3AE_A31C_4DD9_8292_EEE794EF4EC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BANZGHU.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// BANZGHU dialog

class BANZGHU : public CDialog
{
// Construction
public:
	BANZGHU(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(BANZGHU)
	enum { IDD = IDD_DIALOG8 };
	CWebBrowser2	m_browser;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(BANZGHU)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(BANZGHU)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BANZGHU_H__5F7EB3AE_A31C_4DD9_8292_EEE794EF4EC2__INCLUDED_)
