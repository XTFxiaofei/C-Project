#if !defined(AFX_NEWLISTCTRL_H__B5AA6D6D_9AA5_4CAF_BA54_3DF8275128B1__INCLUDED_)
#define AFX_NEWLISTCTRL_H__B5AA6D6D_9AA5_4CAF_BA54_3DF8275128B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// newListCtrl.h : header file
//
#include "MapPublic.h"
/////////////////////////////////////////////////////////////////////////////
// CnewListCtrl window

class CnewListCtrl : public CListCtrl
{
// Construction
public:
	CnewListCtrl();

// Attributes
public:

	CEdit m_edit;//编辑框控件
   int m_nitem,m_nsubitem,m_nitem1,m_nsubitem1;
//m_nitem,m_nsubitem为点击的行号与列号,m_nitem1,m_nsubitem1为前一点点击行号与列号
    void Edit();//自定义的编辑函数
    void EndEdit();//自定义的结束编辑函数

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CnewListCtrl)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CnewListCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CnewListCtrl)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWLISTCTRL_H__B5AA6D6D_9AA5_4CAF_BA54_3DF8275128B1__INCLUDED_)
