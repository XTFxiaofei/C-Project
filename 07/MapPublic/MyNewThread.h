#if !defined(AFX_MYNEWTHREAD_H__662B88E3_CC42_4AA2_B004_82DA3A43C6ED__INCLUDED_)
#define AFX_MYNEWTHREAD_H__662B88E3_CC42_4AA2_B004_82DA3A43C6ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyNewThread.h : header file
//

#include "FindDlg.h"

/////////////////////////////////////////////////////////////////////////////
// CMyNewThread thread

class CMyNewThread : public CWinThread
{
	DECLARE_DYNCREATE(CMyNewThread)
protected:
           // protected constructor used by dynamic creation

// Attributes
public:
	CMyNewThread();
	virtual ~CMyNewThread();
// Operations
public:
	

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyNewThread)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
protected:
	

	// Generated message map functions
	//{{AFX_MSG(CMyNewThread)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYNEWTHREAD_H__662B88E3_CC42_4AA2_B004_82DA3A43C6ED__INCLUDED_)
