#if !defined(AFX_FOREMANGE_H__C435F86F_5583_43EF_9D2D_E2AC27EECE7F__INCLUDED_)
#define AFX_FOREMANGE_H__C435F86F_5583_43EF_9D2D_E2AC27EECE7F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ForeMange.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CForeMange dialog
#include "MyEdit.h"
#include "MyNumEdit.h"
#include "MyListCtrl.h"
#include "Hutext.h"
extern 	CRect rectsmall;
extern  CRect rectlarge;
extern CString operid;

class CForeMange : public CDialog
{
// Construction
public:
	void SetList2Value(CString sqlstr);
	void SetList2Style();
	int GetRecord(CString sqlstr);
	void DeleteMerc();
	bool m_delflag;
	int m_delitem;
	bool m_backenter;
	void InitValue();

	_RecordsetPtr m_salesrs;
	CString SetSalesNum();
	void SetBackMoney();
	float m_floatallmoney;
	void SetEditStyle(int nSize);
	void SetBackMoneyStyle();
	void SetRealMoneyStyle();
	void SetAllMoneyStyle();
	void GetAllMoney();
	void SetStaticStyle();
	bool m_enter;
	int m_alreadynum;
	_RecordsetPtr m_rs;
	_RecordsetPtr m_record;
	_ConnectionPtr m_connect;
	void SetListStyle();
	CForeMange(CWnd* pParent = NULL);   // standard constructor
    CWnd *cwnd;
	CDC *dc;
	CFont   queryFont; 
// Dialog Data
	//{{AFX_DATA(CForeMange)
	enum { IDD = IDD_FOREMANGE };
	CListCtrl	m_list2;
	CEdit	m_editrealmoneyctrl;
	Hutext	m_backmoneyctrl;
	CEdit	m_editbackmoney;
	Hutext	m_anothe2;
	Hutext	m_another;
	Hutext	m_realmoneyctrl;
	Hutext	m_allmoneyctrl;
	CMyNumEdit	m_mercnum;
	CMyEdit	m_mercid;
	CMyListCtrl	m_list;
	CString	m_id;
	double	m_num;
	CString	m_singlediscount;
	CString	m_allmoney;
	CString	m_backmoney;
	CString	m_realmoney;
	CString	m_editrealmoney;
	CString	m_buynum;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CForeMange)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CForeMange)
	afx_msg void OnBtnLockscreen();
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnok();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnBtnDelmerc();
	afx_msg void OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBtncancelsales();
	afx_msg void OnBtnquit();
	afx_msg void OnKillfocusMercid();
	afx_msg void OnKillfocusMercnum();
	afx_msg void OnKillfocusEditRealmoney();
	afx_msg void OnButton7();
	afx_msg void OnButton6();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FOREMANGE_H__C435F86F_5583_43EF_9D2D_E2AC27EECE7F__INCLUDED_)
