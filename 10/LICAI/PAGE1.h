#if !defined(AFX_PAGE1_H__DE48ECF9_19E6_41DF_8625_05627F17F348__INCLUDED_)
#define AFX_PAGE1_H__DE48ECF9_19E6_41DF_8625_05627F17F348__INCLUDED_
#include "LCSet.h"
#include "add.h"
#include "BAOBIAODLG.h"
#include "FIND.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PAGE1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PAGE1 dialog

class PAGE1 : public CDialog
{
// Construction
public:
	PAGE1(CWnd* pParent = NULL);   // standard constructor
    LCSet *mySet;
	CDatabase *pdb;
	CString m_id;
// Dialog Data
	//{{AFX_DATA(PAGE1)
	enum { IDD = IDD_PAGE1 };
	CButton	m_PRINT;
	CButton	m_FIND;
	CButton	m_look;
	CButton	m_SHUAXIN;
	CButton	m_MODIFY;
	CButton	m_DELE;
	CButton	m_ADD;
	CListCtrl	m_list;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PAGE1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	static void DrawInfo(CDC &memDC, PRNINFO PrnInfo);
	// Generated message map functions
	//{{AFX_MSG(PAGE1)
	virtual BOOL OnInitDialog();
    afx_msg void LOADDATA();
	afx_msg void OnAdd();
	afx_msg void OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDele();
	afx_msg void OnModify();
	afx_msg void OnLook();
	afx_msg void OnFind();
	afx_msg void OnPrint();
	afx_msg void OnRequery();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGE1_H__DE48ECF9_19E6_41DF_8625_05627F17F348__INCLUDED_)
