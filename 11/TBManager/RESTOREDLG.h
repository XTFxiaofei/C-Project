#if !defined(AFX_RESTOREDLG_H__9B06BCC4_46BE_4706_9F7E_06556F292769__INCLUDED_)
#define AFX_RESTOREDLG_H__9B06BCC4_46BE_4706_9F7E_06556F292769__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RESTOREDLG.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// RESTOREDLG dialog

class RESTOREDLG : public CDialog
{
// Construction
public:
	RESTOREDLG(CWnd* pParent = NULL);   // standard constructor
	CADODatabase *pDB;
	CString strConnection1,strConnection;

// Dialog Data
	//{{AFX_DATA(RESTOREDLG)
	enum { IDD = IDD_RESTOREDIALOG };
	CString	m_path;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(RESTOREDLG)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(RESTOREDLG)
	afx_msg void OnSelect();
	afx_msg void OnRestore();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RESTOREDLG_H__9B06BCC4_46BE_4706_9F7E_06556F292769__INCLUDED_)
