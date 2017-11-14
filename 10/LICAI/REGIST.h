#if !defined(AFX_REGIST_H__D801B488_CE4A_4AD6_9032_37CAC7C11245__INCLUDED_)
#define AFX_REGIST_H__D801B488_CE4A_4AD6_9032_37CAC7C11245__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// REGIST.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// REGIST dialog

class REGIST : public CDialog
{
// Construction
public:
	REGIST(CWnd* pParent = NULL);   // standard constructor
	CString author;
// Dialog Data
	//{{AFX_DATA(REGIST)
	enum { IDD = IDD_REG };
	CComboBox	m_author;
	CString	m_id;
	CString	m_password;
	CString	m_npassword;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(REGIST)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(REGIST)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGIST_H__D801B488_CE4A_4AD6_9032_37CAC7C11245__INCLUDED_)
