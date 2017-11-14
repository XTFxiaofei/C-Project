// HCCP.h : main header file for the HCCP application
//

#if !defined(AFX_HCCP_H__54FD24E2_7003_47BC_B63F_BC6F1E2CB6AA__INCLUDED_)
#define AFX_HCCP_H__54FD24E2_7003_47BC_B63F_BC6F1E2CB6AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
extern CString leaf111,leaf11,leaf12,str1112,str1212,str1213;
extern int nCount,qiqi;
extern BOOL flag123,flag121,flag001;
/////////////////////////////////////////////////////////////////////////////
// CHCCPApp:
// See HCCP.cpp for the implementation of this class
//

class CHCCPApp : public CWinApp
{
public:
	CHCCPApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHCCPApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CHCCPApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HCCP_H__54FD24E2_7003_47BC_B63F_BC6F1E2CB6AA__INCLUDED_)
