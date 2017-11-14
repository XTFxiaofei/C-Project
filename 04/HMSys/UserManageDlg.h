#if !defined(AFX_USERMANAGEDLG_H__8F8C03F6_56A0_4172_BD00_3F9DC36BB88C__INCLUDED_)
#define AFX_USERMANAGEDLG_H__8F8C03F6_56A0_4172_BD00_3F9DC36BB88C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UserManageDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUserManageDlg dialog

class CUserManageDlg : public CDialog
{
// Construction
public:
	CUserManageDlg(CWnd* pParent = NULL);   // standard constructor
	_RecordsetPtr m_pRecordset;
	void RefushListBox();

// Dialog Data
	//{{AFX_DATA(CUserManageDlg)
	enum { IDD = IDD_USER_MANAGE_DLG };
	CListBox	m_UsersCtrl;
	CComboBox	m_TyprCtrl;
	CString	m_strPwd1;
	CString	m_strPwd2;
	CString	m_strUsers;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUserManageDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUserManageDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnClean();
	afx_msg void OnAdd();
	afx_msg void OnDel();
	afx_msg void OnSelchangeList1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERMANAGEDLG_H__8F8C03F6_56A0_4172_BD00_3F9DC36BB88C__INCLUDED_)
