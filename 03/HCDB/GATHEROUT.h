#if !defined(AFX_GATHEROUT_H__5CF41996_441E_48E6_BA9C_20DD60D01C4C__INCLUDED_)
#define AFX_GATHEROUT_H__5CF41996_441E_48E6_BA9C_20DD60D01C4C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GATHEROUT.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGATHEROUT dialog
#include "MyEditShowList.h"
#include "Hutext.h"
class CGATHEROUT : public CDialog
{
// Construction
public:
	bool flag;
	int delitem;
	float GetAllmoney();
	void ClearAll();
	void ShowWindows(bool flag);
	void ShowButton(bool flag);
	void SetListStyle();
	bool enterflag;
	void GetProvid();
	CString GetProvname(CString sqlstr);
	_RecordsetPtr m_record;
	CString GetStroid();
	void SetInNumber();
	CGATHEROUT(CWnd* pParent = NULL);   // standard constructor
    bool CloseupFlag;
// Dialog Data
	//{{AFX_DATA(CGATHEROUT)
	enum { IDD = IDF_GATHER_OUT };
	CEdit	m_operidctrl;
	Hutext	m_allmoney;
	CListCtrl	m_list;
	CComboBox	m_comprovid;
	CComboBox	m_comtype;
	CMyEditShowList	m_mercidctrl;
	CString	m_mercid;
	CString	m_mercname;
	CString	m_outprice;
	CString	m_merctype;
	CString	m_provid;
	CString	m_uint;
	CString	m_outnumberid;
	CTime	m_date;
	CString	m_provname;
	CString	m_operid;
	CString	m_provid1;
	float	m_numbers;
	CString	m_storinfo;
	CString	m_intype;
	//}}AFX_DATA
	CStringArray m_provArr;
	CStringArray m_innumberArr;
	CStringArray m_dateArr;
	CStringArray m_merctypeArr;
	CStringArray m_storinfoArr;
	CStringArray m_operidArr;
    CStringArray m_intypeArr;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGATHEROUT)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGATHEROUT)
	virtual BOOL OnInitDialog();
	afx_msg void OnKillfocusEdit5();
	afx_msg void OnDatetimechangeDatetimepicker1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnCloseupComboprovid();
	afx_msg void OnKillfocusEdit3();
	afx_msg void OnBtnAddnew();
	afx_msg void OnBtnOk();
	afx_msg void OnTnSave();
	afx_msg void OnBtnDel();
	afx_msg void OnBtnCancel();
	afx_msg void OnItemchangedList2(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GATHEROUT_H__5CF41996_441E_48E6_BA9C_20DD60D01C4C__INCLUDED_)
