#if !defined(AFX_BYSONGTYPDLG_H__809E8357_FAEC_4749_804E_25D48CB6A70B__INCLUDED_)
#define AFX_BYSONGTYPDLG_H__809E8357_FAEC_4749_804E_25D48CB6A70B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BYSONGTYPDLG.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// BYSONGTYPDLG dialog

class BYSONGTYPDLG : public CDialog
{
// Construction
public:
	BYSONGTYPDLG(CWnd* pParent = NULL);   // standard constructor
void 	showsong();	
// Dialog Data
	//{{AFX_DATA(BYSONGTYPDLG)
	enum { IDD = IDD_BYSONGTYP };
	CListCtrl	m_list;
	CComboBox	m_combo;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(BYSONGTYPDLG)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(BYSONGTYPDLG)
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BYSONGTYPDLG_H__809E8357_FAEC_4749_804E_25D48CB6A70B__INCLUDED_)
