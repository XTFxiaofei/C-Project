#if !defined(AFX_BYZISHUDLG_H__56A6A724_6D73_4311_BD3B_4693AB581DF0__INCLUDED_)
#define AFX_BYZISHUDLG_H__56A6A724_6D73_4311_BD3B_4693AB581DF0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BYZISHUDLG.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// BYZISHUDLG dialog

class BYZISHUDLG : public CDialog
{
// Construction
public:
	BYZISHUDLG(CWnd* pParent = NULL);   // standard constructor
void showsong();
// Dialog Data
	//{{AFX_DATA(BYZISHUDLG)
	enum { IDD = IDD_BYZISHU };
	CListCtrl	m_list;
	CComboBox	m_combo1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(BYZISHUDLG)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(BYZISHUDLG)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BYZISHUDLG_H__56A6A724_6D73_4311_BD3B_4693AB581DF0__INCLUDED_)
