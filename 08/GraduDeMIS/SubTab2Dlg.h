#if !defined(AFX_SUBTAB2DLG_H__3135E211_A8A5_4F2A_AEB2_68397E0915F9__INCLUDED_)
#define AFX_SUBTAB2DLG_H__3135E211_A8A5_4F2A_AEB2_68397E0915F9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SubTab2Dlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSubTab2Dlg dialog

class CSubTab2Dlg : public CDialog
{
// Construction
public:
	CSubTab2Dlg(CWnd* pParent = NULL);   // standard constructor
    void CSubTab2Dlg::MyShow();
// Dialog Data
	//{{AFX_DATA(CSubTab2Dlg)
	enum { IDD = IDD_SubTab2_DLG };
	CComboBox	m_combo;
	CString	m_demand;
	CString	m_name;
	CString	m_pro;
	CString	m_type;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSubTab2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSubTab2Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUBTAB2DLG_H__3135E211_A8A5_4F2A_AEB2_68397E0915F9__INCLUDED_)
