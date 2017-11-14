#if !defined(AFX_DOCCHEKDLG_H__395B23A4_75CA_465C_A0C2_BA36A23CC6EA__INCLUDED_)
#define AFX_DOCCHEKDLG_H__395B23A4_75CA_465C_A0C2_BA36A23CC6EA__INCLUDED_
#include "KaitiSet.h"
#include "ShixiSet.h"
#include "FanyiSet.h"
#include "StudentSet.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DocChekDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDocChekDlg dialog

class CDocChekDlg : public CDialog
{
// Construction
public:
	CDocChekDlg(CWnd* pParent = NULL);   // standard constructor

	CKaitiSet pkaitiSet;			//定义记录集对象
	CShixiSet pShixiSet;
	CFanyiSet pFanyiSet;
	CStudentSet stuSet;
// Dialog Data
	//{{AFX_DATA(CDocChekDlg)
	enum { IDD = IDD_DocChek_DLG };
	CComboBox	m_ctrlKTunderstand;
	CComboBox	m_ctrlShixi;
	CComboBox	m_ctrlFanyi;
	CComboBox	m_ctrlStuName;
	CComboBox	m_ctrlStuID;
	CComboBox	m_ctrlClass;
	CString	m_strFanyi;
	CString	m_strKaiti;
	CString	m_strShixi;
	BOOL	m_bFYnum;
	BOOL	m_bFYrelate;
	BOOL	m_bFYsubmit;
	BOOL	m_bKTbasecndi;
	BOOL	m_bKTplan;
	BOOL	m_bKTsubmit;
	BOOL	m_bSXrelate;
	BOOL	m_bSXsubmit;
	CString	m_strFYQuality;
	CString	m_strKTunderstand;
	CString	m_strSXbehave;
	CString	m_strStuName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDocChekDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDocChekDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnOkBTN();
	afx_msg void OnClose();
	afx_msg void OnSelchangeStuNameCOMBO();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOCCHEKDLG_H__395B23A4_75CA_465C_A0C2_BA36A23CC6EA__INCLUDED_)
