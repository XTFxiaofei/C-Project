#if !defined(AFX_STOCKMANAGE_H__774F5D35_1867_40D1_B10E_768D32A06356__INCLUDED_)
#define AFX_STOCKMANAGE_H__774F5D35_1867_40D1_B10E_768D32A06356__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// STOCKMANAGE.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSTOCKMANAGE dialog

class CSTOCKMANAGE : public CDialog
{
// Construction
public:
	void ShowListValue(CString sqlstr);
	CString Justify();
	int item;
	_RecordsetPtr m_record;
	void GetRecord(CString );
	void SetListStyle();
	CSTOCKMANAGE(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSTOCKMANAGE)
	enum { IDD = IDD_STOCKMANAGEDIALOG };
	CListCtrl	m_list;
	CButton	m_check2;
	CButton	m_check1;
	CString	m_mercid;
	double	m_min;
	double	m_max;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSTOCKMANAGE)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSTOCKMANAGE)
	afx_msg void OnBtnQuery();
	afx_msg void OnBtnSet();
	afx_msg void OnBtnClose();
	virtual BOOL OnInitDialog();
	afx_msg void OnItemchangedList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButtonShowspecial();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STOCKMANAGE_H__774F5D35_1867_40D1_B10E_768D32A06356__INCLUDED_)
