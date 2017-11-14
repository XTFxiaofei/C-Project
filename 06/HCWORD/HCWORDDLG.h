// HCWORDDlg.h : header file
//
#include "ClockST.h"
#if !defined(AFX_HCWORDDLG_H__77AEE2E4_2EDB_4EA7_BDD7_C8FE598F422A__INCLUDED_)
#define AFX_HCWORDDLG_H__77AEE2E4_2EDB_4EA7_BDD7_C8FE598F422A__INCLUDED_
#include "HCset.h"
#include "BANZGHU.h"
#include "BANZGHU.h"
#include "Splash1.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "BTNST.H"
#include "ADDdlg.h"
extern int mm;
/////////////////////////////////////////////////////////////////////////////
// CHCWORDDlg dialog

class CHCWORDDlg : public CDialog
{
// Construction
public:
	CHCWORDDlg(CWnd* pParent = NULL);	// standard constructor
    CDatabase *pdb;
    HCset * m_pset;
	void LoadData();
	void ShowData();
	COLORREF m_color;
	CButtonST m_btn,m_btn1,m_btn2,m_btn3;
	//void DrawH();

// Dialog Data
	//{{AFX_DATA(CHCWORDDlg)
	enum { IDD = IDD_HCWORD_DIALOG };
	CClockST	m_Clock;
	CListCtrl	m_list1;
	CListCtrl	m_list;
	CString	m_find;
	//CString	m_sno;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHCWORDDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CHCWORDDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnHu();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	afx_msg void OnButton5();
	afx_msg void OnButton6();
	afx_msg void Onciku();
	afx_msg void OnBeifen();
	afx_msg void OnHelp();
	afx_msg void OnMenuitem32778();
	afx_msg void OnJi();
	afx_msg void OnMenuitem32782();
	afx_msg void OnJl();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnBen();
	afx_msg void OnYu();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
/*class dddd : public CWinApp
{
public:
	int aa;
}*/
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HCWORDDLG_H__77AEE2E4_2EDB_4EA7_BDD7_C8FE598F422A__INCLUDED_)
