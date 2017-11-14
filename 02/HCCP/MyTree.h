#if !defined(AFX_MYTREE_H__4CC486A3_03A4_416E_A3A9_E3143FD72A0A__INCLUDED_)
#define AFX_MYTREE_H__4CC486A3_03A4_416E_A3A9_E3143FD72A0A__INCLUDED_
#include "ADOConn.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyTree.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// MyTree window

class MyTree : public CTreeCtrl
{
// Construction
public:
	MyTree();
	
// Attributes
public:
	BOOL flag;
	void add();
	void del();
	ADOConn m_AdoConn;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(MyTree)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~MyTree();

	// Generated message map functions
protected:
	//{{AFX_MSG(MyTree)
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void Operate(UINT nID);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYTREE_H__4CC486A3_03A4_416E_A3A9_E3143FD72A0A__INCLUDED_)
