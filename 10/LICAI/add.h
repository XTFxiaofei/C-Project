#if !defined(AFX_ADD_H__A4322E08_A7B3_4820_B6AC_1CFE2A7AC64E__INCLUDED_)
#define AFX_ADD_H__A4322E08_A7B3_4820_B6AC_1CFE2A7AC64E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// add.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// add dialog

class add : public CDialog
{
// Construction
public:
	add(CWnd* pParent = NULL);   // standard constructor
    CString incometype,costtype;
// Dialog Data
	//{{AFX_DATA(add)
	enum { IDD = IDD_ADD };
	CComboBox	m_costtype;
	CComboBox	m_incometype;
	long	m_id;
	CString	m_time;
	long	m_incomenum;
	long	m_costnum;
	CString	m_about;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(add)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(add)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADD_H__A4322E08_A7B3_4820_B6AC_1CFE2A7AC64E__INCLUDED_)
