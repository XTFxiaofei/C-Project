// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__E8E5C62B_509E_4863_912C_EAA90123ABD9__INCLUDED_)
#define AFX_STDAFX_H__E8E5C62B_509E_4863_912C_EAA90123ABD9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxole.h>         // MFC OLE classes
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT
#include <afxhtml.h>			// MFC HTML view support

#include <afxsock.h>		// MFC socket extensions

#pragma warning(disable : 4786)	// too long identifiers.
#pragma warning(disable : 4146)
#pragma warning(disable : 4390)

#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include "ClickSound.h"

#import "C:\program files\common files\system\ado\msado15.dll" \
	no_namespace rename ("EOF", "adoEOF")
#pragma comment(lib, "AdoDB.lib")

#include "AdoDB\ClassTableItem.h"
#include "AdoDB\ChapterTableItem.h"
#include "AdoDB\SectionTableItem.h"
#include "AdoDB\AdoDatabase.h"
#include "AdoDB\ClassRecordset.h"
#include "AdoDB\ChapterRecordset.h"
#include "AdoDB\SectionRecordset.h"
#include "AdoDB\CourseWareRecordset.h"

#define USE_NEW_DOCK_BAR

#include "SizingCtrlBar\sizecbar.h"
#include "SizingCtrlBar\scbarg.h"
#include "SizingCtrlBar\scbarcf.h"

#include "PinnableCtrlBar\PinDockBar.h"
#include "PinnableCtrlBar\DrawFrame.h"
#include "PinnableCtrlBar\AutoHideBar.h"

#include "OutlookTabCtrl\OutlookTabCtrl.h"
#include "OutlookTabCtrl\OutlookTabCtrlEx.h"

#include "CoolMenu\NewMenu.h"
#include "CoolMenu\NewToolbar.h"

#include "tools\ComboBoxXP.h"
#include "tools\draw.h"

#include "FileOpenPreDlg.h"
#include "MyGuideTree.h"
#include "Options.h"
#include "TreeCtrlMethod.h"

#include "BtnST\WinXPButtonST.h"
#include "ClockST\ClockST.h"

#include "AddClassDlg.h"
#include "AddChapterDlg.h"
#include "AddChapterDlg2.h"
#include "AddSectionDlg.h"
#include "AddSectionDlg2.h"
#include "AddCoursewareDlg1.h"
#include "AddCoursewareDlg2.h"
#include "AddCoursewareDlg3.h"

#include "PptListCtrl.h"
#include "FlashListCtrl.h"
#include "WordListCtrl.h"

#include "CourseManager.h"
#include "CourseWareManager.h"

extern CAdoDatabase theDB;

typedef vector<CCourseWareInfo> vec_cwi;
typedef vector<CCourseWareInfo>::iterator i_vec_cwi;
typedef vector<CCourseWareInfo>::const_iterator ci_vec_cwi;
typedef vector<CCourseWareInfo>::reverse_iterator ri_vec_cwi;

#define GetMainFrame()  ((CMainFrame*)AfxGetMainWnd())
#define GetCourseWareManager() (((CMTASApp*)AfxGetApp())->m_cwManager)
#define GetCourseManager()	   (((CMTASApp*)AfxGetApp())->m_cManager)


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__E8E5C62B_509E_4863_912C_EAA90123ABD9__INCLUDED_)
