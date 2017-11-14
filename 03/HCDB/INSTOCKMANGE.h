#if !defined(AFX_INSTOCKMANGE_H__5460423B_D249_46D7_AF2E_18004FE280F7__INCLUDED_)
#define AFX_INSTOCKMANGE_H__5460423B_D249_46D7_AF2E_18004FE280F7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// INSTOCKMANGE.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CINSTOCKMANGE dialog
#include "Hutext.h"
class CINSTOCKMANGE : public CDialog
{
// Construction
public:
	int GetRecordCount(_RecordsetPtr ptr);
	void GetAllMoney(CString sqlstr);
	void GetAllNum(CString sqlstr);
	void ShowList2(CString sqlstr);
	bool queryflag;
	_RecordsetPtr m_record;
	void Sum(CString sqlstr);
	void ShowWindows(bool flag);
	void SetList2Style();
	void SetListstyle();
	CINSTOCKMANGE(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CINSTOCKMANGE)
	enum { IDD = IDF_IN_STOCKMANGE };
	Hutext	m_allmoneyctrl;
	Hutext	m_allnumctrl;
	CButton	m_static2;
	CEdit	m_edit;
	CButton	m_static1;
	CDateTimeCtrl	m_endtime;
	CDateTimeCtrl	m_begintime;
	CComboBox	m_combox;
	CListCtrl	m_list2;
	CListCtrl	m_list;
	CString	m_edit1;
	CTime	m_begin;
	CTime	m_end;
	CString	m_allnum;
	CString	m_allmoney;
	//}}AFX_DATA
    CString sqlstr1,sqlstr2;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CINSTOCKMANGE)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CINSTOCKMANGE)
	
	virtual BOOL OnInitDialog();
	afx_msg void OnButton6();
	afx_msg void OnButton7();
	afx_msg void OnCloseupCombo1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INSTOCKMANGE_H__5460423B_D249_46D7_AF2E_18004FE280F7__INCLUDED_)
