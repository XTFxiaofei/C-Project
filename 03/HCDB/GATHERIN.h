#if !defined(AFX_GATHERIN_H__43F7049A_2385_487D_8BD6_0C166073E8D3__INCLUDED_)
#define AFX_GATHERIN_H__43F7049A_2385_487D_8BD6_0C166073E8D3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GATHERIN.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGATHERIN dialog
#include "Hutext.h"
#include "MyCanShowEdit.h"
extern CString m_extermprovid;

#include "PROVDLG.h"
class CGATHERIN : public CDialog
{
// Construction
public:
	bool SaveMercInfo();
	_RecordsetPtr m_recordstore;
	_RecordsetPtr m_record;
	int delitem;
	void ClearAll();
	_RecordsetPtr m_recordmercinfo;
	void SetComUint();
	double GetAllmoney();
	void ShowWindows(bool flag);
	void ShowButton(bool flag);
	int GetRecordCount(_RecordsetPtr ptr);
	_RecordsetPtr m_recordstorid;
	CString GetStroId();
	void SetDate(CTime tm);
	void SetInNumber();
	bool CloseupFlag;
	CString GetProvname(CString sqlstr);
	_RecordsetPtr m_recordprovid;
	_ConnectionPtr m_connection;
	void GetProvid();
	void SetListStyle();
	CRect ReSetRect(CRect rect);
	CGATHERIN(CWnd* pParent = NULL);   // standard constructor
    Hutext *cwnd;
	CPROVDLG dlg;
// Dialog Data
	//{{AFX_DATA(CGATHERIN)
	enum { IDD = IDF_GATHER_IN };
	CEdit	m_providctrl;
	CEdit	m_merctypectrl;
	CEdit	m_operidctrl;
	CComboBox	m_comuint;
	CEdit	m_inpricectrl;
	CEdit	m_numbersctrl;
	CEdit	m_mercnuamectrl;
	CMyCanShowEdit	m_mercidctrl;
	Hutext	m_allmoney;
	CComboBox	m_comprovid;
	CComboBox	m_comintype;
	CListCtrl	m_list;
	CString	m_provname;
	CString	m_innumber;
	CTime	m_date;
	CString	m_mercid;
	CString	m_mercname;
	CString	m_merctype;
	CString	m_provid;
	double	m_inprice;
	double	m_numbers;
	CString	m_uint;
	CString	m_storinfo;
	CString	m_operid;
	CString	m_intype;
	CString	m_provid1;
	//}}AFX_DATA
    CStringArray m_provArr;
	CStringArray m_innumberArr;
	CStringArray m_dateArr;
	CStringArray m_merctypeArr;
	CStringArray m_storinfoArr;
	CStringArray m_operidArr;
    CStringArray m_intypeArr;
    bool flag;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGATHERIN)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGATHERIN)
	virtual BOOL OnInitDialog();
	afx_msg void OnTnSave();
	afx_msg void OnBtnAddnew();
	afx_msg void OnBtnDel();
	afx_msg void OnBtnOk();
	afx_msg void OnBtnCancel();
	afx_msg void OnCloseupComboprovid();
	afx_msg void OnDatetimechangeDatetimepicker1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnItemchangedList2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnEditchangeComboprovid();
	afx_msg void OnKillfocusComboprovid();
	afx_msg void OnKillfocusEdit3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GATHERIN_H__43F7049A_2385_487D_8BD6_0C166073E8D3__INCLUDED_)
