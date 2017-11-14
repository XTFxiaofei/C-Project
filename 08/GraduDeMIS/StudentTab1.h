#if !defined(AFX_STUDENTTAB1_H__D29CE345_C2FA_413B_88D1_D542C107C37F__INCLUDED_)
#define AFX_STUDENTTAB1_H__D29CE345_C2FA_413B_88D1_D542C107C37F__INCLUDED_
#include "StudentSet.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StudentTab1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStudentTab1 dialog

class CStudentTab1 : public CDialog
{
// Construction
public:
	CStudentTab1(CWnd* pParent = NULL);   // standard constructor
	CStudentSet pSet;			//定义记录集对象
void SelectItem(int n);
   void CStudentTab1::MyClearCombo2();
// Dialog Data
	//{{AFX_DATA(CStudentTab1)
	enum { IDD = IDD_STU_DIALOG1 };
	CComboBox	m_ctrlCombo2;
	CComboBox	m_StuTab1Combo;
	CListCtrl	m_StuTab1listctl;
	CString	    m_StuTab1Edit;
	CEdit       m_StuTab1EditCtrl;
	CString	m_strcombo1;
	CString	m_strCombo2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStudentTab1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CStudentTab1)
	virtual BOOL OnInitDialog();
	afx_msg void OnStutab1Button();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelchangeCombo1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUDENTTAB1_H__D29CE345_C2FA_413B_88D1_D542C107C37F__INCLUDED_)
