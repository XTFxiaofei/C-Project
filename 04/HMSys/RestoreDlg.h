#if !defined(AFX_RESTOREDLG_H__EC9CE8C7_9EC9_4DA4_AB18_94DD407C6870__INCLUDED_)
#define AFX_RESTOREDLG_H__EC9CE8C7_9EC9_4DA4_AB18_94DD407C6870__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RestoreDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRestoreDlg dialog

class CRestoreDlg : public CDialog
{
// Construction
public:
	CRestoreDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRestoreDlg)
	enum { IDD = IDD_RESTORE_DLG };
	CString	m_strPath;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRestoreDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRestoreDlg)
	afx_msg void OnButton1();
	afx_msg void OnRestore();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RESTOREDLG_H__EC9CE8C7_9EC9_4DA4_AB18_94DD407C6870__INCLUDED_)
