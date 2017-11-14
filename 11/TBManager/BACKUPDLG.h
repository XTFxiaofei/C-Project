#if !defined(AFX_BACKUPDLG_H__682DBAC9_0BD1_4E79_AD74_B92EB2975CDB__INCLUDED_)
#define AFX_BACKUPDLG_H__682DBAC9_0BD1_4E79_AD74_B92EB2975CDB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BACKUPDLG.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// BACKUPDLG dialog

class BACKUPDLG : public CDialog
{
// Construction
public:
	BACKUPDLG(CWnd* pParent = NULL);   // standard constructor
	CADODatabase *pDB;

// Dialog Data
	//{{AFX_DATA(BACKUPDLG)
	enum { IDD = IDD_BACKUPDIALOG };
	CString	m_path;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(BACKUPDLG)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(BACKUPDLG)
	afx_msg void OnSelect();
	afx_msg void OnBackup();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BACKUPDLG_H__682DBAC9_0BD1_4E79_AD74_B92EB2975CDB__INCLUDED_)
