#if !defined(AFX_SHOWENDDLG_H__157E9818_A237_4637_B5BD_964D06F9630D__INCLUDED_)
#define AFX_SHOWENDDLG_H__157E9818_A237_4637_B5BD_964D06F9630D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ShowEndDlg.h : header file
//
#include "ColorStatic.h"
/////////////////////////////////////////////////////////////////////////////
// CShowEndDlg dialog

class CShowEndDlg : public CDialog
{
// Construction
public:
	CShowEndDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CShowEndDlg)
	enum { IDD = IDD_DIALOG_END };
	CColorStatic	m_sta;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowEndDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CShowEndDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWENDDLG_H__157E9818_A237_4637_B5BD_964D06F9630D__INCLUDED_)
