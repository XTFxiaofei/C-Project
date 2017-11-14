#if !defined(AFX_UPDATEPWDDLG_H__0BE0D2A0_4ADB_49B0_A3A0_E80A60297DDD__INCLUDED_)
#define AFX_UPDATEPWDDLG_H__0BE0D2A0_4ADB_49B0_A3A0_E80A60297DDD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UpdatePwdDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUpdatePwdDlg dialog

class CUpdatePwdDlg : public CDialog
{
// Construction
public:
	CUpdatePwdDlg(CWnd* pParent = NULL);   // standard constructor
	_RecordsetPtr m_pRecordset;
// Dialog Data
	//{{AFX_DATA(CUpdatePwdDlg)
	enum { IDD = IDD_UPDATE_PWD_DLG };
	CString	m_strPwd1;
	CString	m_strPwd2;
	CString	m_strID;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUpdatePwdDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUpdatePwdDlg)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UPDATEPWDDLG_H__0BE0D2A0_4ADB_49B0_A3A0_E80A60297DDD__INCLUDED_)
