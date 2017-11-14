// HCWORD.h : main header file for the HCWORD application
//

#if !defined(AFX_HCWORD_H__0E81AB58_3A24_47C2_9672_3F84000D1AA0__INCLUDED_)
#define AFX_HCWORD_H__0E81AB58_3A24_47C2_9672_3F84000D1AA0__INCLUDED_
#include "SkinMagic.h"
#include "Splash1.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
extern int aa;
extern CString  logFileName,lpszFileName;
#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CHCWORDApp:
// See HCWORD.cpp for the implementation of this class
//

class CHCWORDApp : public CWinApp
{
public:
	CHCWORDApp();
    CSkinMagic m_skin;                                           
    //int aa;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHCWORDApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CHCWORDApp)
	afx_msg void OnFghu1();
	afx_msg void OnBj2();
	afx_msg void OnPf1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HCWORD_H__0E81AB58_3A24_47C2_9672_3F84000D1AA0__INCLUDED_)
