#if !defined(AFX_ADMIN_H__2C0864CF_AB34_49B6_9EB5_A57C52D138BF__INCLUDED_)
#define AFX_ADMIN_H__2C0864CF_AB34_49B6_9EB5_A57C52D138BF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ADMIN.h : header file
//
#include "ADOConn.h"
/////////////////////////////////////////////////////////////////////////////
// ADMIN dialog

class ADMIN : public CDialog
{
// Construction
public:
	ADMIN(CWnd* pParent = NULL);   // standard constructor
	ADOConn m_AdoConn;   //定义数据库操作对象
	_bstr_t sql;
	_RecordsetPtr m_pRecordset;	   //定义记录集

// Dialog Data
	//{{AFX_DATA(ADMIN)
	enum { IDD = IDD_DIALOG1 };
	CString	m_mpassword;
	CString	m_user;
	CString	m_newpass;
	CString	m_oldpass;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ADMIN)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ADMIN)
	virtual BOOL OnInitDialog();
	afx_msg void OnModify();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADMIN_H__2C0864CF_AB34_49B6_9EB5_A57C52D138BF__INCLUDED_)
