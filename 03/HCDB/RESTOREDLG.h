#if !defined(AFX_RESTOREDLG_H__D012429A_B77B_4AB9_B41E_102E3B99DD05__INCLUDED_)
#define AFX_RESTOREDLG_H__D012429A_B77B_4AB9_B41E_102E3B99DD05__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RESTOREDLG.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRESTOREDLG dialog

class CRESTOREDLG : public CDialog
{
// Construction
public:
	_RecordsetPtr m_record;
	void SetListStyle();
	void Connect();
	CRESTOREDLG(CWnd* pParent = NULL);   // standard constructor
    _ConnectionPtr m_connection;
// Dialog Data
	//{{AFX_DATA(CRESTOREDLG)
	enum { IDD = IDD_RESTOREDIALOG };
	CListCtrl	m_list;
	CString	m_edit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRESTOREDLG)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRESTOREDLG)
	virtual BOOL OnInitDialog();
	afx_msg void OnButton4();
	afx_msg void OnButton1();
	afx_msg void OnButton3();
	afx_msg void OnItemchangedList2(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RESTOREDLG_H__D012429A_B77B_4AB9_B41E_102E3B99DD05__INCLUDED_)
