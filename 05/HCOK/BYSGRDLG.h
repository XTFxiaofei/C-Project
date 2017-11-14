#if !defined(AFX_BYSGRDLG_H__CDD6B1CF_0085_40CB_B1E6_D41AE279B3AE__INCLUDED_)
#define AFX_BYSGRDLG_H__CDD6B1CF_0085_40CB_B1E6_D41AE279B3AE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BYSGRDLG.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// BYSGRDLG dialog

class BYSGRDLG : public CDialog
{
// Construction
public:
	BYSGRDLG(CWnd* pParent = NULL);   // standard constructor
	void ShowDate() ;
	void showsong();
	void addsong();
	void showsinger();

// Dialog Data
	//{{AFX_DATA(BYSGRDLG)
	enum { IDD = IDD_BYSINGER };
	CComboBox	m_combo;
	CListCtrl	m_list;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(BYSGRDLG)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(BYSGRDLG)
	virtual BOOL OnInitDialog();
	afx_msg void OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelchangeCombo2();
	afx_msg void OnUp();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BYSGRDLG_H__CDD6B1CF_0085_40CB_B1E6_D41AE279B3AE__INCLUDED_)
