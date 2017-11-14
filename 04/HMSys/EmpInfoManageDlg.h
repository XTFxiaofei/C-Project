#if !defined(AFX_EMPINFOMANAGEDLG_H__EAAA278C_C947_4379_A14C_6CA650246EC8__INCLUDED_)
#define AFX_EMPINFOMANAGEDLG_H__EAAA278C_C947_4379_A14C_6CA650246EC8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EmpInfoManageDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEmpInfoManageDlg dialog

class CEmpInfoManageDlg : public CDialog
{
// Construction
public:
	CEmpInfoManageDlg(CWnd* pParent = NULL);   // standard constructor
	HTREEITEM m_hParent;				//treeµÄ½Úµã
	HTREEITEM m_hSelect;
	_RecordsetPtr m_pRecordset;
	_RecordsetPtr m_pRecordset1;
	void ShowTreeData();
	void ShowListData(const CString& sql);
	int m_nSelect;
	int m_nID;
// Dialog Data
	//{{AFX_DATA(CEmpInfoManageDlg)
	enum { IDD = IDD_EMPINFO_MANAGE_DLG };
	CListCtrl	m_ListCrtl;
	CTreeCtrl	m_TreeCrtl;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEmpInfoManageDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEmpInfoManageDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkTree1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnAdd();
	afx_msg void OnUpdate();
	afx_msg void OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDel();
	afx_msg void OnIndex();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EMPINFOMANAGEDLG_H__EAAA278C_C947_4379_A14C_6CA650246EC8__INCLUDED_)
