#if !defined(AFX_PAGE2_H__FDBF0394_51A1_49A2_8481_EA8339A575F1__INCLUDED_)
#define AFX_PAGE2_H__FDBF0394_51A1_49A2_8481_EA8339A575F1__INCLUDED_
#include "LCSet.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PAGE2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PAGE2 dialog

class PAGE2 : public CDialog
{
// Construction
public:
	PAGE2(CWnd* pParent = NULL);   // standard constructor
    LCSet *mySet;
	CDatabase *pdb;
	int incomenum,costnum,total;//表示总收入，costnum表示支出数目，total表示剩余的数目
    int xfsm1,xfsm2,xfsm3,xfsm4,xfsm5,xfsm6,xfsm7,xfsm8,xfsm9; //依次分别代表 9 种消费类型的消费总数

// Dialog Data
	//{{AFX_DATA(PAGE2)
	enum { IDD = IDD_PAGE2 };
	CListCtrl	m_list;
	CString	m_jianyi;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PAGE2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(PAGE2)
	virtual BOOL OnInitDialog();
	afx_msg void LOADDATA();
	afx_msg void LOADJY();
	afx_msg void OnRequery();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGE2_H__FDBF0394_51A1_49A2_8481_EA8339A575F1__INCLUDED_)
