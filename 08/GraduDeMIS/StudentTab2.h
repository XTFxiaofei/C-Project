#if !defined(AFX_STUDENTTAB2_H__C422F316_E815_4C6A_8DC4_81C8E2FFD1B3__INCLUDED_)
#define AFX_STUDENTTAB2_H__C422F316_E815_4C6A_8DC4_81C8E2FFD1B3__INCLUDED_
#include "StudentSet.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StudentTab2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStudentTab2 dialog

class CStudentTab2 : public CDialog
{
// Construction
public:
	CStudentTab2(CWnd* pParent = NULL);   // standard constructor
	CStudentSet pSet2;			//定义记录集对象
    MyClearItem();
    MyBtnHide(bool bBtnAdd,bool bBtnEdit,bool bBtnDel,bool bBtnSave,bool bBtnCancel);
    BOOL bAddBtnFlag,bEditBtnFlag;

//	MyUpdateData();
	void OnShow();
	
// Dialog Data
	//{{AFX_DATA(CStudentTab2)
	enum { IDD = IDD_STU_DIALOG2 };
	CComboBox	m_ctrlDepart;
	CComboBox	m_ctrlAge;
	CComboBox	m_ctrlClass;
	CComboBox	m_ctrlSex;
	CEdit	m_StuTab2EditCtl;
	CString	m_StuTab2_ID;
	CString	m_StuTab2_NAME;
//	CString	m_StuTab2_DEPART;
	CString	m_StuTab2_CLASS;
//	CString	m_StuTab2_AGE;
	CString	m_strSex;
	CString	m_strClass;
	CString	m_strAge;
	CString	m_strDepart;
	//}}AFX_DATA

    
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStudentTab2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CStudentTab2)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonCancle();
	afx_msg void OnButtonDel();
	afx_msg void OnButtonEdit();
	afx_msg void OnButtonSave();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUDENTTAB2_H__C422F316_E815_4C6A_8DC4_81C8E2FFD1B3__INCLUDED_)
