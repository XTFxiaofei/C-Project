#if !defined(AFX_FINDDLG_H__B4530E94_47F4_4733_A886_751303378F5A__INCLUDED_)
#define AFX_FINDDLG_H__B4530E94_47F4_4733_A886_751303378F5A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FindDlg.h : header file
//
#include "SuperProgressCtrl.h"
/////////////////////////////////////////////////////////////////////////////
// CFindDlg dialog

class CFindDlg : public CDialog
{
// Construction
public:
	CFindDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFindDlg)
	enum { IDD = IDD_DIALOG_FIND };
	CProgressCtrl	m_progress;
//	CSuperProgressCtrl m_progress;
	//}}AFX_DATA

	int temp;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFindDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFindDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	afx_msg void OnMess();
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FINDDLG_H__B4530E94_47F4_4733_A886_751303378F5A__INCLUDED_)
