#if !defined(AFX_CHECKMANAGEDLG_H__F114B728_021D_48E6_9C55_61C3FBD7EB3B__INCLUDED_)
#define AFX_CHECKMANAGEDLG_H__F114B728_021D_48E6_9C55_61C3FBD7EB3B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CheckManageDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCheckManageDlg dialog

class CCheckManageDlg : public CDialog
{
// Construction
public:
	CCheckManageDlg(CWnd* pParent = NULL);   // standard constructor
	_RecordsetPtr m_pRecordset;
	CString m_strState[7];
	int m_nFlag;
// Dialog Data
	//{{AFX_DATA(CCheckManageDlg)
	enum { IDD = IDD_CHECK_MANAGE_DLG };
	CButton	m_Radio;
	CString	m_strID;
	CString	m_strMore;
	BOOL	m_Check1;
	BOOL	m_Check2;
	BOOL	m_Check3;
	BOOL	m_Check4;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCheckManageDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCheckManageDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnSure();
	afx_msg void OnRadio3();
	afx_msg void OnRadio4();
	afx_msg void OnOvertime();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHECKMANAGEDLG_H__F114B728_021D_48E6_9C55_61C3FBD7EB3B__INCLUDED_)
