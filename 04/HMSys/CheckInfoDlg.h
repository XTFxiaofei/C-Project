#if !defined(AFX_CHECKINFODLG_H__B64B9441_2586_41C5_AB3F_7741925C8ED4__INCLUDED_)
#define AFX_CHECKINFODLG_H__B64B9441_2586_41C5_AB3F_7741925C8ED4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CheckInfoDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCheckInfoDlg dialog

class CCheckInfoDlg : public CDialog
{
// Construction
public:
	CCheckInfoDlg(CWnd* pParent = NULL);   // standard constructor
	_RecordsetPtr m_pRecordset;
	void ShowListData(const CString& sql);
// Dialog Data
	//{{AFX_DATA(CCheckInfoDlg)
	enum { IDD = IDD_CHECK_INFO_DLG };
	CListCtrl	m_ListCrtl;
	CString	m_strID;
	CTime	m_Date;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCheckInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCheckInfoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnIndex();
	afx_msg void OnDel();
	afx_msg void OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHECKINFODLG_H__B64B9441_2586_41C5_AB3F_7741925C8ED4__INCLUDED_)
