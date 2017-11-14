#if !defined(AFX_WAGEMANAGEDLG_H__42FB512E_CAD7_4D71_AEF5_75620A40C779__INCLUDED_)
#define AFX_WAGEMANAGEDLG_H__42FB512E_CAD7_4D71_AEF5_75620A40C779__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WageManageDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWageManageDlg dialog

class CWageManageDlg : public CDialog
{
// Construction
public:
	CWageManageDlg(CWnd* pParent = NULL);   // standard constructor
	_RecordsetPtr m_pRecordset;
	_RecordsetPtr m_pRecordset1;
	void ShowTreeData();
	void ShowListData(const CString& sql);
	HTREEITEM m_hParent;				//treeµÄ½Úµã
	HTREEITEM m_hSelect;
	int m_nFlag;
// Dialog Data
	//{{AFX_DATA(CWageManageDlg)
	enum { IDD = IDD_WAGE_MANAGE_DLG };
	CComboBox	m_Depart;
	CListCtrl	m_ListCrtl;
	CTreeCtrl	m_TreeCrtl;
	CString	m_strID;
	int		m_nWage;
	CTime	m_Date;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWageManageDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWageManageDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkTree1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnAdd();
	afx_msg void OnUpdate();
	afx_msg void OnSave();
	afx_msg void OnDel();
	afx_msg void OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnIndex();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WAGEMANAGEDLG_H__42FB512E_CAD7_4D71_AEF5_75620A40C779__INCLUDED_)
