// MTAS.h : main header file for the MTAS application
//

#if !defined(AFX_MTAS_H__F235FBD0_B654_4518_B63B_8BB9427E8AAA__INCLUDED_)
#define AFX_MTAS_H__F235FBD0_B654_4518_B63B_8BB9427E8AAA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMTASApp:
// See MTAS.cpp for the implementation of this class
//

class CMTASApp : public CWinApp
{
public:
	CMTASApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMTASApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMTASApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	CourseManager	  m_cManager;
	CourseWareManager m_cwManager;
	
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MTAS_H__F235FBD0_B654_4518_B63B_8BB9427E8AAA__INCLUDED_)
