// HCDB.h : main header file for the HCDB application
//

#if !defined(AFX_HCDB_H__67553A22_31D6_402F_9761_C1C1154EBE7B__INCLUDED_)
#define AFX_HCDB_H__67553A22_31D6_402F_9761_C1C1154EBE7B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CHCDBApp:
// See HCDB.cpp for the implementation of this class
//
extern CString operid;
class CHCDBApp : public CWinApp
{
public:
	int GetRecord(CString sqlstr);
	BOOL ConnectMaster(CString sqlstr);
	BOOL ConnectSql(CString sql);
	_ConnectionPtr m_connection;
	_ConnectionPtr m_connection1;
	_RecordsetPtr m_record;
	CHCDBApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHCDBApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CHCDBApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HCDB_H__67553A22_31D6_402F_9761_C1C1154EBE7B__INCLUDED_)
