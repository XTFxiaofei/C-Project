#if !defined(AFX_TESTDLG_H__28BF6D43_85F5_4678_A8A2_A976CC05C863__INCLUDED_)
#define AFX_TESTDLG_H__28BF6D43_85F5_4678_A8A2_A976CC05C863__INCLUDED_
#include "TKSet.h"
#include "Hutext.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TESTdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// TESTdlg dialog

class TESTdlg : public CDialog
{
// Construction
public:
	TESTdlg(CWnd* pParent = NULL);   // standard constructor
    CDatabase *pdb;
    TKSet * m_pset;
	int i;
	Hutext m_resultControl;
    Hutext m_resultControl1;
	Hutext m_resultControl2;
	Hutext m_resultControl3;
	Hutext m_resultControl4;
// Dialog Data
	//{{AFX_DATA(TESTdlg)
	enum { IDD = IDD_DIALOG5 };
	int		answer;
	CString	m_test;
	CString	m_test1;
	CString	m_test2;
	CString	m_test3;
	CString	m_test4;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(TESTdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(TESTdlg)
	afx_msg void Answer(UINT nID);
	virtual BOOL OnInitDialog();
	afx_msg void OnNext();
	afx_msg void OnSelect();
	afx_msg void OnSubmit();
	afx_msg void OnSum();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTDLG_H__28BF6D43_85F5_4678_A8A2_A976CC05C863__INCLUDED_)
