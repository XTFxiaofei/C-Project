#if !defined(AFX_TABDLG3_H__CA63FEA8_424B_42EF_BAD7_06411FBF38BF__INCLUDED_)
#define AFX_TABDLG3_H__CA63FEA8_424B_42EF_BAD7_06411FBF38BF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TABDLG3.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTABDLG3 dialog

class CTABDLG3 : public CDialog
{
// Construction
public:
	CTABDLG3(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTABDLG3)
	enum { IDD = IDD_DIALOG_TAB3 };
	CString	m_tigan;
	CString	m_ka;
	CString	m_kb;
	CString	m_kc;
	CString	m_kd;
	CString	m_difficulty;
	int		m_tno;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTABDLG3)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTABDLG3)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TABDLG3_H__CA63FEA8_424B_42EF_BAD7_06411FBF38BF__INCLUDED_)
