#if !defined(AFX_LOADDLG_H__B6441595_2753_43F4_9556_316E2CD85C17__INCLUDED_)
#define AFX_LOADDLG_H__B6441595_2753_43F4_9556_316E2CD85C17__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LoadDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLoadDlg dialog

class CLoadDlg : public CDialog
{
// Construction
public:
	CLoadDlg(CWnd* pParent = NULL);   // standard constructor
	_RecordsetPtr m_pRecordset;
	BOOL m_bFlag;
// Dialog Data
	//{{AFX_DATA(CLoadDlg)
	enum { IDD = IDD_LOAD_DLG };
	CString	m_strPwd;
	CString	m_strUser;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLoadDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLoadDlg)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOADDLG_H__B6441595_2753_43F4_9556_316E2CD85C17__INCLUDED_)
