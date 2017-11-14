#if !defined(AFX_GUANLI_H__0E0EEAA6_4089_4607_87E3_E61E46B3C5F5__INCLUDED_)
#define AFX_GUANLI_H__0E0EEAA6_4089_4607_87E3_E61E46B3C5F5__INCLUDED_
#include "PWSet.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GUANLI.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// GUANLI dialog

class GUANLI : public CDialog
{
// Construction
public:
	GUANLI(CWnd* pParent = NULL);   // standard constructor
    PWSet *mySet;
	CDatabase *pdb;
	CString m_id;
// Dialog Data
	//{{AFX_DATA(GUANLI)
	enum { IDD = IDD_GUANLI };
	CListCtrl	m_list;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(GUANLI)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(GUANLI)
	virtual BOOL OnInitDialog();
	afx_msg void LOADDATA();
	afx_msg void OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnModify();
	afx_msg void OnDele();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GUANLI_H__0E0EEAA6_4089_4607_87E3_E61E46B3C5F5__INCLUDED_)
