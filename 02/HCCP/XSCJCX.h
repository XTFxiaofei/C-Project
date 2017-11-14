#if !defined(AFX_XSCJCX_H__35A5EA81_CE52_425A_B34A_6A2A815F1C52__INCLUDED_)
#define AFX_XSCJCX_H__35A5EA81_CE52_425A_B34A_6A2A815F1C52__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// XSCJCX.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// XSCJCX dialog

class XSCJCX : public CDialog
{
// Construction
public:
	XSCJCX(CWnd* pParent = NULL);   // standard constructor
	CString temp;
	void DuiHua();
// Dialog Data
	//{{AFX_DATA(XSCJCX)
	enum { IDD = IDD_XSCJCX };
	CComboBox	m_fanwei;
	CString	m_guanjian;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(XSCJCX)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(XSCJCX)
	virtual BOOL OnInitDialog();
	afx_msg void OnFind();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XSCJCX_H__35A5EA81_CE52_425A_B34A_6A2A815F1C52__INCLUDED_)
