#if !defined(AFX_OUTSTOCKMANGE_H__E71F72AD_04B8_4571_845E_3129F841D06D__INCLUDED_)
#define AFX_OUTSTOCKMANGE_H__E71F72AD_04B8_4571_845E_3129F841D06D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OUTSTOCKMANGE.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COUTSTOCKMANGE dialog
#include "Hutext.h"
class COUTSTOCKMANGE : public CDialog
{
// Construction
public:
	COUTSTOCKMANGE(CWnd* pParent = NULL);   // standard constructor
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
// Dialog Data
	//{{AFX_DATA(COUTSTOCKMANGE)
	enum { IDD = IDF_OUT_STOCKMANGE };
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
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA
    CString sqlstr1,sqlstr2;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COUTSTOCKMANGE)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COUTSTOCKMANGE)
		// NOTE: the ClassWizard will add member functions here
	afx_msg void OnButton6();
	afx_msg void OnButton7();
	afx_msg void OnCloseupCombo1();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OUTSTOCKMANGE_H__E71F72AD_04B8_4571_845E_3129F841D06D__INCLUDED_)
