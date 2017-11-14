// LICAIDlg.h : header file
//

#if !defined(AFX_LICAIDLG_H__18EA2420_B2D5_4D7D_9B94_D2E7F6A78CB1__INCLUDED_)
#define AFX_LICAIDLG_H__18EA2420_B2D5_4D7D_9B94_D2E7F6A78CB1__INCLUDED_
#include "PAGE1.h"
#include "PAGE2.h"
#include "PAGE3.h"
#include "PAGE4.h"
#include "PAGE5.h"
#include "GUANLI.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CLICAIDlg dialog

class CLICAIDlg : public CDialog
{
// Construction
public:
	CLICAIDlg(CWnd* pParent = NULL);	// standard constructor
    int m_CurSelTab;
	PAGE1 m_page1;
	PAGE2 m_page2;
	PAGE3 m_page3;
	PAGE4 m_page4;
	PAGE5 m_page5;
    CDialog *pDialog[5];
// Dialog Data
	//{{AFX_DATA(CLICAIDlg)
	enum { IDD = IDD_LICAI_DIALOG };
	CButton	m_RECOVER;
	CButton	m_COPY;
	CButton	m_MODIFY;
	CButton	m_GUANLI;
	CButton	m_ADD;
	CTabCtrl	m_tab;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLICAIDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CLICAIDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnAdd();
	afx_msg void OnGuanli();
	afx_msg void OnModify();
	afx_msg void OnCopy();
	afx_msg void OnRecover();
	virtual void OnCancel();
	afx_msg void OnZhuxiao();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LICAIDLG_H__18EA2420_B2D5_4D7D_9B94_D2E7F6A78CB1__INCLUDED_)
