#if !defined(AFX_KAOQINDLG_H__F30018FC_CC28_4145_AADC_9C1619178529__INCLUDED_)
#define AFX_KAOQINDLG_H__F30018FC_CC28_4145_AADC_9C1619178529__INCLUDED_
#include "StudentSet.h"
#include "KaoqinSet.h"
#include "KaoqinsumSet.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// KaoqinDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CKaoqinDlg dialog

class CKaoqinDlg : public CDialog
{
// Construction
public:
	CKaoqinDlg(CWnd* pParent = NULL);   // standard constructor
    CStudentSet stuSet;					//定义记录集对象
	CKaoqinSet kaoqinSet;
	CKaoqinsumSet kqsumSet;
// Dialog Data
	//{{AFX_DATA(CKaoqinDlg)
	enum { IDD = IDD_Kaoqin_DLG };
	CEdit	m_ctrUnAttRea;
	CComboBox	m_ctrlStuName2;
	CComboBox	m_ctrlClass2;
	CListCtrl	m_ctrlList;
	CComboBox	m_ctrlStuName;
	CComboBox	m_ctrlClass;
	CString	m_strClass;
	CString	m_strStuName;
	CString	m_strClass2;
	CString	m_strStuName2;
	CTime	m_strFrom;
	CTime	m_strTo;
	BOOL	m_bCheck;
	CString	m_strUnAttRea;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKaoqinDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CKaoqinDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeClassCOMBO();
	afx_msg void OnSelchangeStuNameCOMBO();
	afx_msg void OnAddBTN();
	afx_msg void OnSelchangeClassCOMBO2();
	afx_msg void OnSelchangeStuNameCOMBO2();
	afx_msg void OnQueryBtn();
	afx_msg void OnDelBTN();
	afx_msg void OnCheck1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KAOQINDLG_H__F30018FC_CC28_4145_AADC_9C1619178529__INCLUDED_)
