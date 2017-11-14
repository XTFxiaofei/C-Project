#if !defined(AFX_OUTDETAIL_H__CAE7BC39_7D56_4F97_AC6A_CB26C9C72007__INCLUDED_)
#define AFX_OUTDETAIL_H__CAE7BC39_7D56_4F97_AC6A_CB26C9C72007__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OUTDETAIL.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COUTDETAIL dialog

class COUTDETAIL : public CDialog
{
// Construction
public:
	void SetListStyle();
	void InitDate();
	int GetRecordCount(_RecordsetPtr ptr);
	void GetRecord(CString sqlstr);
	void GetMercRecord(CString sqlstr);
	CString GetMerc(CString sqlstr);
	COUTDETAIL(CWnd* pParent = NULL);   // standard constructor
	CString m_mercid;
	_RecordsetPtr m_mercRecord;
	_RecordsetPtr m_record;
// Dialog Data
	//{{AFX_DATA(COUTDETAIL)
	enum { IDD = IDF_OUTDETAIL };
	CListBox	m_list2ctrl;
	CListCtrl	m_list;
	CDateTimeCtrl	m_endtimectrl;
	CDateTimeCtrl	m_begintimectrl;
	CComboBox	m_comquery;
	CButton	m_check2;
	CButton	m_check;
	CTime	m_begintime;
	CTime	m_endtime;
	CString	m_edit2;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COUTDETAIL)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COUTDETAIL)
	afx_msg void OnButton1();
	afx_msg void OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnCheck1();
	afx_msg void OnCheck2();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OUTDETAIL_H__CAE7BC39_7D56_4F97_AC6A_CB26C9C72007__INCLUDED_)
