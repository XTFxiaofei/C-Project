#if !defined(AFX_USERDLG_H__ACC0FF9E_C3FE_4562_B474_21BA668C272F__INCLUDED_)
#define AFX_USERDLG_H__ACC0FF9E_C3FE_4562_B474_21BA668C272F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// USERDLG.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// USERDLG dialog

class USERDLG : public CDialog
{
// Construction
public:
	USERDLG(CWnd* pParent = NULL);   // standard constructor

	CString sqlstr;
	void showdata();

	CADODatabase *pDB;
	CADORecordset *pRS;

	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset;

// Dialog Data
	//{{AFX_DATA(USERDLG)
	enum { IDD = IDD_POWER };
	CListBox	m_list;
	CComboBox	m_combo;
	CString	m_name;
	CString	m_newpass;
	CString	m_nnewpass;
	CString	m_oldpass;
	CString	m_pass1;
	CString	m_pass2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(USERDLG)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(USERDLG)
	afx_msg void OnModify();
	afx_msg void OnAdduser();
	afx_msg void OnDeluser();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERDLG_H__ACC0FF9E_C3FE_4562_B474_21BA668C272F__INCLUDED_)
