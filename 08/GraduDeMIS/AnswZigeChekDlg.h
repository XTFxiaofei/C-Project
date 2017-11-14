#if !defined(AFX_ANSWZIGECHEKDLG_H__77E5D585_3905_4CCA_A4EB_B44A202C7B2F__INCLUDED_)
#define AFX_ANSWZIGECHEKDLG_H__77E5D585_3905_4CCA_A4EB_B44A202C7B2F__INCLUDED_
#include "StudentSet.h"
#include "StuAchieveSet.h"
#include "KaoqinsumSet.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AnswZigeChekDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// AnswZigeChekDlg dialog

class AnswZigeChekDlg : public CDialog
{
// Construction
public:
	AnswZigeChekDlg(CWnd* pParent = NULL);   // standard constructor
    CStudentSet stuSet;						//定义记录集对象
	CStuAchieveSet pstuachieveSet;
	CKaoqinsumSet kqsumSet;
// Dialog Data
	//{{AFX_DATA(AnswZigeChekDlg)
	enum { IDD = IDD_AnswZigeChek_DLG };
	CComboBox	m_ctrlStuName;
	CComboBox	m_ctrlStuID;
	CComboBox	m_ctrlClass;
	CString	m_strAttDays;
	CString	m_strCompuLevel;
	CString	m_strHoliDays;
	CString	m_strYDaoDays;
	CString	m_strEngLevel;
	CString	m_strResult;
	CString	m_strColiResult;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(AnswZigeChekDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(AnswZigeChekDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeStuIDCOMBO();
	afx_msg void OnSelchangeStuNameCOMBO();
	afx_msg void OnSelchangeClassCOMBO();
	afx_msg void OnDropdownStuNameCOMBO();
	afx_msg void OnEditupdateStuNameCOMBO();
	afx_msg void OnSetfocusStuNameCOMBO();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANSWZIGECHEKDLG_H__77E5D585_3905_4CCA_A4EB_B44A202C7B2F__INCLUDED_)
