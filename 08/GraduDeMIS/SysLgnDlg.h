#if !defined(AFX_SYSLGNDLG_H__AB0DED11_1FE2_47C1_8824_0B3DDB102F86__INCLUDED_)
#define AFX_SYSLGNDLG_H__AB0DED11_1FE2_47C1_8824_0B3DDB102F86__INCLUDED_
#include "PasswordSet.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SysLgnDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSysLgnDlg dialog

class CSysLgnDlg : public CDialog
{
// Construction
public:
	CSysLgnDlg(CWnd* pParent = NULL);   // standard constructor
	void CSysLgnDlg::MyAddComboBoxItem(CString str);
    CPasswordSet passwdSet;
// Dialog Data
	//{{AFX_DATA(CSysLgnDlg)
	enum { IDD = IDD_SysLog_DLG };
	CComboBox	m_ctrlUserUnit;
	CComboBox	m_ctrlUserType;
	CEdit	m_ctrlPasswd;
	CComboBox	m_ctrlUser;
	CString	m_strUser;
	CString	m_strPasswd;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSysLgnDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSysLgnDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnLoginBtn();
	afx_msg void OnSelchangeUserTypeCOMBO();
	afx_msg void OnSelchangeUserUnitCOMBO();
	afx_msg void OnExitBtn();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SYSLGNDLG_H__AB0DED11_1FE2_47C1_8824_0B3DDB102F86__INCLUDED_)
