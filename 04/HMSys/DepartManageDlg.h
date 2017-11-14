#if !defined(AFX_DEPARTMANAGEDLG_H__E6ADEC3B_2284_4746_B85B_231F62E660EC__INCLUDED_)
#define AFX_DEPARTMANAGEDLG_H__E6ADEC3B_2284_4746_B85B_231F62E660EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DepartManageDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDepartManageDlg dialog

class CDepartManageDlg : public CDialog
{
// Construction
public:
	CDepartManageDlg(CWnd* pParent = NULL);   // standard constructor
	HTREEITEM m_hParent;				//treeµÄ½Úµã
	HTREEITEM m_hSelect;
	_RecordsetPtr m_pRecordset;
	void ShowTreeData();
	int m_nSelect;
	int m_nID;
// Dialog Data
	//{{AFX_DATA(CDepartManageDlg)
	enum { IDD = IDD_DEPART_MANAGE_DLG };
	CTreeCtrl	m_TreeCrtl;
	CString	m_strManager;
	CString	m_strMore;
	CString	m_strName;
	CString	m_strPhone;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDepartManageDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDepartManageDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkTree1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnAdd();
	afx_msg void OnUpdate();
	afx_msg void OnSave();
	afx_msg void OnDel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEPARTMANAGEDLG_H__E6ADEC3B_2284_4746_B85B_231F62E660EC__INCLUDED_)
