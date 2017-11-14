#if !defined(AFX_BACKUPDLG_H__5742A0F7_C002_418E_B401_B585CD2E8FBF__INCLUDED_)
#define AFX_BACKUPDLG_H__5742A0F7_C002_418E_B401_B585CD2E8FBF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BackupDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBackupDlg dialog

class CBackupDlg : public CDialog
{
// Construction
public:
	CBackupDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBackupDlg)
	enum { IDD = IDD_BACKUP_DLG };
	CString	m_strPath;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBackupDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBackupDlg)
	afx_msg void OnButton1();
	afx_msg void OnBackup();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BACKUPDLG_H__5742A0F7_C002_418E_B401_B585CD2E8FBF__INCLUDED_)
