// LICAI.h : main header file for the LICAI application
//

#if !defined(AFX_LICAI_H__291869CF_2DF3_482F_BDD2_07C324470F1F__INCLUDED_)
#define AFX_LICAI_H__291869CF_2DF3_482F_BDD2_07C324470F1F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif
#include "SkinMagic.h"
#include "resource.h"		// main symbols
bool extern addflag,authorflag,loginflag,glflag;          //flag用来判断执行的是添加还是修改操作；authorflag是用来判断当前为哪种登陆权限;loginflag用来记录点了哪个权限，是管理员还是宾客,glflag在管理对话筐里面弹出的修改对话框里获取当前的用户权限  
CString extern ID,lpszFileName,logFileName,mianFileName;  //ID用来标记登陆的用户名是什么，lpszFileName 记录数据库所在路径（相对），logFileName 记录日志文件所在路径（相对）
/////////////////////////////////////////////////////////////////////////////
// CLICAIApp:
// See LICAI.cpp for the implementation of this class
//

class CLICAIApp : public CWinApp
{
public:
	CLICAIApp();
	CSkinMagic	m_Skin;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLICAIApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLICAIApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LICAI_H__291869CF_2DF3_482F_BDD2_07C324470F1F__INCLUDED_)
