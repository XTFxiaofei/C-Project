#if !defined(AFX_SALESQUERY_H__AEB9EEA3_F69B_42C8_AC7A_B1D5AEC95DFB__INCLUDED_)
#define AFX_SALESQUERY_H__AEB9EEA3_F69B_42C8_AC7A_B1D5AEC95DFB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SALESQUERY.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSALESQUERY dialog

class CSALESQUERY : public CDialog
{
// Construction
public:
	void SetList2Value(CString sqlstr);
	void SetList1Value(CString sqlstr);
	void SetList2Style();
	void SetList1Style();
	_RecordsetPtr m_record;
	int GetRecord(CString sqlstr);
	CSALESQUERY(CWnd* pParent = NULL);   // standard constructor
    void Initdate();
	void ShowWindows(bool flag);
// Dialog Data
	//{{AFX_DATA(CSALESQUERY)
	enum { IDD = IDD_SALESQUERY };
	CButton	m_check;
	CListCtrl	m_list2;
	CListCtrl	m_list1;
	CComboBox	m_comquery;
	CTime	m_begintime;
	CTime	m_endtime;
	CString	m_edit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSALESQUERY)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSALESQUERY)
	virtual BOOL OnInitDialog();
	afx_msg void OnInvalidate();
	afx_msg void OnCheck1();
	afx_msg void OnCloseupCombo1();
	afx_msg void OnCHAXUNxsd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SALESQUERY_H__AEB9EEA3_F69B_42C8_AC7A_B1D5AEC95DFB__INCLUDED_)
