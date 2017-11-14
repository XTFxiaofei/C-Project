#if !defined(AFX_INDETAIL_H__17A7277E_B884_4E0B_84BE_8A5DA68206A3__INCLUDED_)
#define AFX_INDETAIL_H__17A7277E_B884_4E0B_84BE_8A5DA68206A3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// INDETAIL.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CINDETAIL dialog

class CINDETAIL : public CDialog
{
// Construction
public:
	int GetRecordCount(_RecordsetPtr ptr);
	CString m_mercid;
	CString GetMerc(CString sqlstr);	
	_RecordsetPtr m_mercRecord;
	void GetMercRecord(CString sqlstr);
	void GetRecord(CString sqlstr);
	void InitDate();
	void SetListStyle();
	void Connect();
	_RecordsetPtr m_record;
	CINDETAIL(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CINDETAIL)
	enum { IDD = IDF_INDETAIL };
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
	//}}AFX_DATA

	_ConnectionPtr m_connection;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CINDETAIL)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CINDETAIL)
	virtual BOOL OnInitDialog();
	afx_msg void OnButton1();
	afx_msg void OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnCheck1();
	afx_msg void OnCheck2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INDETAIL_H__17A7277E_B884_4E0B_84BE_8A5DA68206A3__INCLUDED_)
