#if !defined(AFX_BAOBIAODLG_H__A1AFB3E4_5124_40B2_9EFD_1C43478AE77A__INCLUDED_)
#define AFX_BAOBIAODLG_H__A1AFB3E4_5124_40B2_9EFD_1C43478AE77A__INCLUDED_
#include "LCSet.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BAOBIAODLG.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// BAOBIAODLG dialog

class BAOBIAODLG : public CDialog
{
// Construction
public:
	BAOBIAODLG(CWnd* pParent = NULL);   // standard LCSet *mySet;
	LCSet *mySet;
	CDatabase *pdb;
// Dialog Data
	//{{AFX_DATA(BAOBIAODLG)
	enum { IDD = IDD_BAOBIAO };
	CListCtrl	m_list;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(BAOBIAODLG)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(BAOBIAODLG)
	virtual BOOL OnInitDialog();
	afx_msg void LOADDATA();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BAOBIAODLG_H__A1AFB3E4_5124_40B2_9EFD_1C43478AE77A__INCLUDED_)
