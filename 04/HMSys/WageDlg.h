#if !defined(AFX_WAGEDLG_H__50A77BB1_3868_4E54_B031_F6B313DE30DF__INCLUDED_)
#define AFX_WAGEDLG_H__50A77BB1_3868_4E54_B031_F6B313DE30DF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WageDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWageDlg dialog

class CWageDlg : public CDialog
{
// Construction
public:
	CWageDlg(CWnd* pParent = NULL);   // standard constructor
	_RecordsetPtr m_pRecordset;
	_RecordsetPtr m_pRecordset1;
	void ShowListData(const CString& sql);
// Dialog Data
	//{{AFX_DATA(CWageDlg)
	enum { IDD = IDD_WAGE_DLG };
	CComboBox	m_Month;
	CListCtrl	m_ListCrtl;
	CString	m_strID;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWageDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWageDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WAGEDLG_H__50A77BB1_3868_4E54_B031_F6B313DE30DF__INCLUDED_)
