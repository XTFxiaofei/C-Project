#if !defined(AFX_SUBTAB1DLG_H__81D13E2A_1008_4419_BEC0_15A47A4C169C__INCLUDED_)
#define AFX_SUBTAB1DLG_H__81D13E2A_1008_4419_BEC0_15A47A4C169C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SubTab1Dlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSubTab1Dlg dialog
#include "SubjectSet.h"
class CSubTab1Dlg : public CDialog
{
// Construction
public:
	CSubTab1Dlg(CWnd* pParent = NULL);   // standard constructor
	CSubjectSet m_pSet;
// Dialog Data
	//{{AFX_DATA(CSubTab1Dlg)
	enum { IDD = IDD_SubTab1_DLG };
	CComboBox	m_combo;
	CListCtrl	m_ctrlsubTab1list;
	CString	m_find;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSubTab1Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSubTab1Dlg)
	afx_msg void OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUBTAB1DLG_H__81D13E2A_1008_4419_BEC0_15A47A4C169C__INCLUDED_)
