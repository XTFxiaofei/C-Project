#if !defined(AFX_SYSDLG_H__2216BB8B_1CE4_49C8_AAF0_FD1016B6AFCF__INCLUDED_)
#define AFX_SYSDLG_H__2216BB8B_1CE4_49C8_AAF0_FD1016B6AFCF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SYSDLG.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// SYSDLG dialog

class SYSDLG : public CDialog
{
// Construction
public:
	SYSDLG(CWnd* pParent = NULL);   // standard constructor

	_ConnectionPtr m_pConnection;   //ADO指向Connection对象的指针
	_RecordsetPtr m_pRecordset;     //ADO指向Recordset对象的指针

	void ShowData();
// Dialog Data
	//{{AFX_DATA(SYSDLG)
	enum { IDD = IDD_SYSDLG };
	CListBox	m_list;
	CComboBox	m_combo;
	CString	m_newpass;
	CString	m_newpassr;
	CString	m_oldpass;
	CString	m_pass;
	CString	m_passr;
	CString	m_name;
	CString	m_id;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SYSDLG)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(SYSDLG)
	virtual BOOL OnInitDialog();
	afx_msg void OnAdduser();
	afx_msg void OnDeluser();
	afx_msg void OnModipass();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SYSDLG_H__2216BB8B_1CE4_49C8_AAF0_FD1016B6AFCF__INCLUDED_)
