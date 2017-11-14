// GraduDeMIS.h : main header file for the GRADUDEMIS application
//

#if !defined(AFX_GRADUDEMIS_H__4FDAEBCD_3E76_4116_93F4_B8217A3EE14E__INCLUDED_)
#define AFX_GRADUDEMIS_H__4FDAEBCD_3E76_4116_93F4_B8217A3EE14E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

extern CString selectID;
extern CString strExternUser;
extern bool bstuExternFlag,btecrExternFlag,badminExternFlag;
/////////////////////////////////////////////////////////////////////////////
// CGraduDeMISApp:
// See GraduDeMIS.cpp for the implementation of this class
//

class CGraduDeMISApp : public CWinApp
{
public:
	CGraduDeMISApp();
  
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGraduDeMISApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGraduDeMISApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRADUDEMIS_H__4FDAEBCD_3E76_4116_93F4_B8217A3EE14E__INCLUDED_)
