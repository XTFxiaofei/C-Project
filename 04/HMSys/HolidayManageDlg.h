#if !defined(AFX_HOLIDAYMANAGEDLG_H__1D7A2313_583B_4E1D_BD92_045C945AA2A2__INCLUDED_)
#define AFX_HOLIDAYMANAGEDLG_H__1D7A2313_583B_4E1D_BD92_045C945AA2A2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HolidayManageDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHolidayManageDlg dialog
#include "ClockST.h"

class CHolidayManageDlg : public CDialog
{
// Construction
public:
	CHolidayManageDlg(CWnd* pParent = NULL);   // standard constructor
	_RecordsetPtr m_pRecordset;
	void ShowListData();
	int m_nFlag;
	CString m_strID;
// Dialog Data
	//{{AFX_DATA(CHolidayManageDlg)
	enum { IDD = IDD_HOLIDAY_MANAGE_DLG };
	CListCtrl	m_ListCrtl;
	CClockST	m_Clock;
	CString	m_strName;
	CTime	m_Date;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHolidayManageDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CHolidayManageDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnAdd();
	afx_msg void OnUpdate();
	afx_msg void OnDel();
	afx_msg void OnSave();
	afx_msg void OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HOLIDAYMANAGEDLG_H__1D7A2313_583B_4E1D_BD92_045C945AA2A2__INCLUDED_)
