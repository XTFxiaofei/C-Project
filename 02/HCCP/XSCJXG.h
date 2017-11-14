#if !defined(AFX_XSCJXG_H__118347AC_D30A_4ABB_A69A_37F02B9A772E__INCLUDED_)
#define AFX_XSCJXG_H__118347AC_D30A_4ABB_A69A_37F02B9A772E__INCLUDED_
#include "ADOConn.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// XSCJXG.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// XSCJXG dialog

class XSCJXG : public CDialog
{
// Construction
public:
	XSCJXG(CWnd* pParent = NULL);   // standard constructor

	ADOConn m_ado;
	_RecordsetPtr m_pRs112;
	_bstr_t vSQL112;
// Dialog Data
	//{{AFX_DATA(XSCJXG)
	enum { IDD = IDD_XSCJXG };
	CSpinButtonCtrl	m_spin;
	double	m_sgrade;
	CString	m_sno;
	CString	m_sname;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(XSCJXG)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(XSCJXG)
	afx_msg void OnChangeSgrade();
	virtual BOOL OnInitDialog();
	afx_msg void OnXiu();
	afx_msg void OnDelcy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XSCJXG_H__118347AC_D30A_4ABB_A69A_37F02B9A772E__INCLUDED_)
