#if !defined(AFX_INSTOCKQUERY_H__BF965DF4_71A0_4EB3_AD11_1DBEFC158490__INCLUDED_)
#define AFX_INSTOCKQUERY_H__BF965DF4_71A0_4EB3_AD11_1DBEFC158490__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// INSTOCKQUERY.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CINSTOCKQUERY dialog

class CINSTOCKQUERY : public CDialog
{
// Construction
public:
	_RecordsetPtr m_mercRecord;	
	_RecordsetPtr m_record;
	_ConnectionPtr m_connection;
	void GetMercRecord(CString sqlstr);
	void GetRecord(CString sqlstr);
	void InitDate();
	void SetListStyle();

	CINSTOCKQUERY(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CINSTOCKQUERY)
	enum { IDD = IDF_INSTOCKQUERY };
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


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CINSTOCKQUERY)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CINSTOCKQUERY)
	afx_msg void OnButton1();
	afx_msg void OnKillfocusEdit2();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INSTOCKQUERY_H__BF965DF4_71A0_4EB3_AD11_1DBEFC158490__INCLUDED_)
