#if !defined(AFX_OUTSTOCKQUERY_H__29103E7E_FD24_4075_A9FF_4EA6CE067CDB__INCLUDED_)
#define AFX_OUTSTOCKQUERY_H__29103E7E_FD24_4075_A9FF_4EA6CE067CDB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OUTSTOCKQUERY.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COUTSTOCKQUERY dialog

class COUTSTOCKQUERY : public CDialog
{
// Construction
public:
	int GetRecordCount(_RecordsetPtr ptr);
	void SetListStyle();
	void InitDate();
	void GetRecord(CString sqlstr);
	void GetMercRecord(CString sqlstr);
	COUTSTOCKQUERY(CWnd* pParent = NULL);   // standard constructor
	_RecordsetPtr m_mercRecord;	
	_RecordsetPtr m_record;
	_ConnectionPtr m_connection;
// Dialog Data
	//{{AFX_DATA(COUTSTOCKQUERY)
	enum { IDD = IDF_OUTSTOCKQUERY };
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
	//{{AFX_VIRTUAL(COUTSTOCKQUERY)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COUTSTOCKQUERY)
	afx_msg void OnButton1();
	afx_msg void OnKillfocusEdit2();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OUTSTOCKQUERY_H__29103E7E_FD24_4075_A9FF_4EA6CE067CDB__INCLUDED_)
