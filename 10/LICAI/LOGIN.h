#if !defined(AFX_LOGIN_H__ABE5E67A_2251_4D20_9200_F139E6400869__INCLUDED_)
#define AFX_LOGIN_H__ABE5E67A_2251_4D20_9200_F139E6400869__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LOGIN.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// LOGIN dialog

class LOGIN : public CDialog
{
// Construction
public:
	LOGIN(CWnd* pParent = NULL);   // standard constructor
	CString author;
// Dialog Data
	//{{AFX_DATA(LOGIN)
	enum { IDD = IDD_LOGIN };
	CComboBox	m_combo;
	CString	m_id;
	CString	m_password;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(LOGIN)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(LOGIN)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGIN_H__ABE5E67A_2251_4D20_9200_F139E6400869__INCLUDED_)
