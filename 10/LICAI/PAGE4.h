#if !defined(AFX_PAGE4_H__73F45F28_1074_4FF5_AF4D_AE56E6498C7F__INCLUDED_)
#define AFX_PAGE4_H__73F45F28_1074_4FF5_AF4D_AE56E6498C7F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PAGE4.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PAGE4 dialog

class PAGE4 : public CDialog
{
// Construction
public:
	PAGE4(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PAGE4)
	enum { IDD = IDD_PAGE4 };
	CButton	m_open;
	CButton	m_dele;
	CString	m_edit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PAGE4)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(PAGE4)
	virtual BOOL OnInitDialog();
	afx_msg void OnShuxin();
	afx_msg void Ondelefile();
	afx_msg void OnOpen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGE4_H__73F45F28_1074_4FF5_AF4D_AE56E6498C7F__INCLUDED_)
