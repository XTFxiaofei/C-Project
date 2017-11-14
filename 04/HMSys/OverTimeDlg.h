#if !defined(AFX_OVERTIMEDLG_H__8A91228A_7F15_42FD_9CD5_DACB5317DD89__INCLUDED_)
#define AFX_OVERTIMEDLG_H__8A91228A_7F15_42FD_9CD5_DACB5317DD89__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OverTimeDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COverTimeDlg dialog

class COverTimeDlg : public CDialog
{
// Construction
public:
	COverTimeDlg(CWnd* pParent = NULL);   // standard constructor
	int m_nType;
// Dialog Data
	//{{AFX_DATA(COverTimeDlg)
	enum { IDD = IDD_OVERTIME_DLG };
	CComboBox	m_Type;
	int		m_nHour;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COverTimeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COverTimeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnEditchangeCombo1();
	afx_msg void OnSelchangeCombo1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OVERTIMEDLG_H__8A91228A_7F15_42FD_9CD5_DACB5317DD89__INCLUDED_)
