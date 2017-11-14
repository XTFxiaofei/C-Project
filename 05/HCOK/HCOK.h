// HCOK.h : main header file for the HCOK application
//

#if !defined(AFX_HCOK_H__64A22C73_09F6_4A7E_99D8_594FA5CD864A__INCLUDED_)
#define AFX_HCOK_H__64A22C73_09F6_4A7E_99D8_594FA5CD864A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

extern CString addroomtype,addcardtype,givenmoney,	mkusingername,	mkusingersex ,mkusingerarea ,	mkusingerpin,nowp,timestr1,timestr2;
extern int tempshow1,tempshow,showsinger1,showsinger2,delsongfresh,mainshowlist;
extern CString printprice,     printmoneybake ,printabate;

extern CRect rectsmall,rectlarge;
/////////////////////////////////////////////////////////////////////////////
// CHCOKApp:
// See HCOK.cpp for the implementation of this class
//

class CHCOKApp : public CWinApp
{
public:
	CHCOKApp();
	~CHCOKApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHCOKApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CHCOKApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HCOK_H__64A22C73_09F6_4A7E_99D8_594FA5CD864A__INCLUDED_)
