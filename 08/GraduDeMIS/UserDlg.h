#if !defined(AFX_USERDLG_H__3B814D5A_B94A_4B2F_961E_EA983F3E767E__INCLUDED_)
#define AFX_USERDLG_H__3B814D5A_B94A_4B2F_961E_EA983F3E767E__INCLUDED_
#include "PasswordSet.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UserDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUserDlg dialog

class CUserDlg : public CDialog
{
// Construction
public:
	CUserDlg(CWnd* pParent = NULL);   // standard constructor
	CPasswordSet passwdSet;
	struct UserInfo
	{
		CString user;
		CString passwd;
		CString repasswd;
		bool bIsAdmin;
	};
// Dialog Data
	//{{AFX_DATA(CUserDlg)
	enum { IDD = IDD_UserGL};
	CEdit	m_ctrlUser;
	CEdit	m_ctrlPass;
	CListBox	m_ctrlUserList;
	CString	m_strPass;
	CString	m_strRePass;
	CString	m_user;
	BOOL	m_IsAdmin;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUserDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUserDlg)
	afx_msg void OnExitBTN();
	afx_msg void OnEdit();
	afx_msg void OnDel();
	afx_msg void OnAdd();
	afx_msg void OnCancelBTN();
	afx_msg void OnIsAdminCHECK();
	afx_msg void OnSaveBTN();
	afx_msg void OnSelchangeUserLIST();
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERDLG_H__3B814D5A_B94A_4B2F_961E_EA983F3E767E__INCLUDED_)
