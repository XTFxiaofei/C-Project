#if !defined(AFX_DABIANFENZUDLG_H__97819A53_DFE0_474B_BA82_25D5716CEF64__INCLUDED_)
#define AFX_DABIANFENZUDLG_H__97819A53_DFE0_474B_BA82_25D5716CEF64__INCLUDED_
#include "StudentSet.h"
#include "DabianfenzuSet.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DabianfenzuDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDabianfenzuDlg dialog

class CDabianfenzuDlg : public CDialog
{
// Construction
public:
	CDabianfenzuDlg(CWnd* pParent = NULL);   // standard constructor
    CStudentSet stuSet;							//定义记录集对象
	CDabianfenzuSet dabianfuzeSet;
	void CDabianfenzuDlg::MyClearSubTypeCombo();
void CDabianfenzuDlg::MyDate_Posi_Dem_Exp(CString strDabianType,CString strSubType);

// Dialog Data
	//{{AFX_DATA(CDabianfenzuDlg)
	enum { IDD = IDD_DabianFenzu_DLG };
	CListCtrl	m_ctrlList;
	CComboBox	m_ctrlSubType;
	CComboBox	m_ctrlDabianType;
	CComboBox	m_ctrlClass;
	CComboBox	m_ctrlName;
	CString	m_strName;
	CString	m_strClass;
	CString	m_strDabianType;
	CString	m_strSubType;
	CString	m_strDate;
	CString	m_strPosition;
	CString	m_strDemand;
	CString	m_strExpers;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDabianfenzuDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDabianfenzuDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeClassCOMBO();
	afx_msg void OnSelchangeNameCOMBO();
	afx_msg void OnSelchangeDabianTypeCOMBO();
	afx_msg void OnSelchangeSubTypeCOMBO();
	afx_msg void OnOkBTN();
	afx_msg void OnQueryBtn();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DABIANFENZUDLG_H__97819A53_DFE0_474B_BA82_25D5716CEF64__INCLUDED_)
