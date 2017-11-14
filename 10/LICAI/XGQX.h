#if !defined(AFX_XGQX_H__65586B66_2C8F_410F_8295_3586DD60E641__INCLUDED_)
#define AFX_XGQX_H__65586B66_2C8F_410F_8295_3586DD60E641__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// XGQX.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// XGQX dialog

class XGQX : public CDialog
{
// Construction
public:
	XGQX(CWnd* pParent = NULL);   // standard constructor
    CString author;
// Dialog Data
	//{{AFX_DATA(XGQX)
	enum { IDD = IDD_XGQX };
	CComboBox	m_author;
	CString	m_id;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(XGQX)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(XGQX)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XGQX_H__65586B66_2C8F_410F_8295_3586DD60E641__INCLUDED_)
