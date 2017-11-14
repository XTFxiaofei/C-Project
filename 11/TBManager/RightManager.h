#if !defined(AFX_RIGHTMANAGER_H__0225C020_4F49_4109_8CE1_4512F6C92234__INCLUDED_)
#define AFX_RIGHTMANAGER_H__0225C020_4F49_4109_8CE1_4512F6C92234__INCLUDED_
#include "ado.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RightManager.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRightManager dialog

class CRightManager : public CDialog
{
// Construction
public:
	CRightManager(CWnd* pParent = NULL);   // standard constructor
	CADODatabase *pDB;
	CADORecordset *pRS;
//	CString strname;
// Dialog Data
	//{{AFX_DATA(CRightManager)
	enum { IDD = IDD_DIALOG_RIGHT };
	CListBox	m_list;
	CString	m_name;
	CString	m_right;
	CString	m_namemanager;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRightManager)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRightManager)
	virtual BOOL OnInitDialog();
	afx_msg void OnShowupdate();
	afx_msg void OnDestroy();
	afx_msg void OnSelchangeList1();
	afx_msg void OnAdduser();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RIGHTMANAGER_H__0225C020_4F49_4109_8CE1_4512F6C92234__INCLUDED_)
