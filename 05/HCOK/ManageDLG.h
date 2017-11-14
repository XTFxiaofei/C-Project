#if !defined(AFX_MANAGEDLG_H__A3AE3C8A_F688_4622_8270_C6D99A89C3CC__INCLUDED_)
#define AFX_MANAGEDLG_H__A3AE3C8A_F688_4622_8270_C6D99A89C3CC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ManageDLG.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ManageDLG dialog

class ManageDLG : public CDialog
{
// Construction
public:
	ManageDLG(CWnd* pParent = NULL);   // standard constructor

	void ShowData() ;
	void singerShowData() ;
// Dialog Data
	//{{AFX_DATA(ManageDLG)
	enum { IDD = IDD_MANAGE };
	CListCtrl	m_list2;
	CListCtrl	m_list;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ManageDLG)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ManageDLG)
	afx_msg void OnAddsong();
	afx_msg void OnPrice();
	virtual BOOL OnInitDialog();
	afx_msg void OnDelsong();
	afx_msg void OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnAddsinger();
	afx_msg void OnItemchangedList2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDel();
	afx_msg void OnModifsinger();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MANAGEDLG_H__A3AE3C8A_F688_4622_8270_C6D99A89C3CC__INCLUDED_)
