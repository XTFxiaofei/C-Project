//{{AFX_INCLUDES()
#include "webbrowser2.h"
//}}AFX_INCLUDES
#if !defined(AFX_ADDCOURSEWAREDLG1_H__EADC6134_8E14_491E_AF08_9EBEFB5B7241__INCLUDED_)
#define AFX_ADDCOURSEWAREDLG1_H__EADC6134_8E14_491E_AF08_9EBEFB5B7241__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddCoursewareDlg1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAddCoursewareDlg dialog

class CAddCoursewareDlg : public CNewDialog
{
// Construction
public:
	long m_lSize;
	CCourseWareInfo m_cwi;
	CAddCoursewareDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAddCoursewareDlg)
	enum { IDD = IDD_ADD_COURSEWARE_DIALOG };
	CWinXPButtonST	m_btnCancel;
	CWinXPButtonST	m_btnBrowse;
	CWinXPButtonST	m_btnAdd;
	CString	m_strChapter;
	CString	m_strClass;
	CString	m_strModTime;
	CString	m_strName;
	CString	m_strPath;
	CString	m_strSection;
	CString	m_strSize;
	CString	m_strType;
	CWebBrowser2	m_webbrowser;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddCoursewareDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddCoursewareDlg)
	afx_msg void OnAdd();
	afx_msg void OnBrowse();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDCOURSEWAREDLG1_H__EADC6134_8E14_491E_AF08_9EBEFB5B7241__INCLUDED_)
