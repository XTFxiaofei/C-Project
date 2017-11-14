#if !defined(AFX_REMDLG_H__1C63667F_EA2E_456A_8530_57932A4AC3A2__INCLUDED_)
#define AFX_REMDLG_H__1C63667F_EA2E_456A_8530_57932A4AC3A2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// REMDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// REMDlg dialog

class REMDlg : public CDialog
{
// Construction
public:
	REMDlg(CWnd* pParent = NULL);   // standard constructor
//CString  logFileName;

// Dialog Data
	//{{AFX_DATA(REMDlg)
	enum { IDD = IDD_DIALOG7 };
	CString	m_edit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(REMDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(REMDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REMDLG_H__1C63667F_EA2E_456A_8530_57932A4AC3A2__INCLUDED_)
