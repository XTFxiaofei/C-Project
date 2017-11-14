#if !defined(AFX_LEFTVIEW_H__C94843A4_0438_443A_9832_8503B8DBE4EF__INCLUDED_)
#define AFX_LEFTVIEW_H__C94843A4_0438_443A_9832_8503B8DBE4EF__INCLUDED_
#include "MyTreeCtrl.h"
#include "TrackLookButton.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LeftView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLeftView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CLeftView : public CFormView
{
protected:
	CLeftView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CLeftView)

// Form Data
public:
	//{{AFX_DATA(CLeftView)
	enum { IDD = IDD_FORMVIEW1 };
	CTrackLookButton	m_button4;
	CTrackLookButton	m_button3;
	CTrackLookButton	m_button2;
	CTrackLookButton	m_button1;
	CMyTreeCtrl	m_tree;
	CString	m_userinformation;
	//}}AFX_DATA

// Attributes
public:

// Operations
public:
	CString str;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLeftView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CImageList m_imagelist;
	virtual ~CLeftView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CLeftView)
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	afx_msg void OnDblclkTree1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnUpdateFileSave(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LEFTVIEW_H__C94843A4_0438_443A_9832_8503B8DBE4EF__INCLUDED_)
