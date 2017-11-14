// TBManager.h : main header file for the TBMANAGER application
//

#if !defined(AFX_TBMANAGER_H__9A3FA9E0_5FBC_491C_9DFF_C0ED63B9DC1E__INCLUDED_)
#define AFX_TBMANAGER_H__9A3FA9E0_5FBC_491C_9DFF_C0ED63B9DC1E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif
extern CString Conditionstr,username,userright;
extern int num,startnum;
extern bool modifyflag;
extern CString e_mima,e_user;
#include "resource.h"       // main symbols
#include "ado.h"
#include "SkinMagic.h"
/////////////////////////////////////////////////////////////////////////////
// CTBManagerApp:
// See TBManager.cpp for the implementation of this class
//

class CTBManagerApp : public CWinApp
{
public:
	CTBManagerApp();
	CADODatabase *pDB;
	CADORecordset *pRS;
	CSkinMagic	m_Skin;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTBManagerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTBManagerApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TBMANAGER_H__9A3FA9E0_5FBC_491C_9DFF_C0ED63B9DC1E__INCLUDED_)
