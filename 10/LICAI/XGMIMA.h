#if !defined(AFX_XGMIMA_H__2657DD6C_3E48_423B_8D6B_B82FCF68BEC2__INCLUDED_)
#define AFX_XGMIMA_H__2657DD6C_3E48_423B_8D6B_B82FCF68BEC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// XGMIMA.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// XGMIMA dialog

class XGMIMA : public CDialog
{
// Construction
public:
	XGMIMA(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(XGMIMA)
	enum { IDD = IDD_XGMIMA };
	CString	m_npassword;
	CString	m_anpassword;
	CString	m_password;
	CString	m_id;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(XGMIMA)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(XGMIMA)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XGMIMA_H__2657DD6C_3E48_423B_8D6B_B82FCF68BEC2__INCLUDED_)
