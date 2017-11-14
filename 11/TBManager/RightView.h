#if !defined(AFX_RIGHTVIEW_H__20431321_C23A_47FD_93D0_0EEA07EDD592__INCLUDED_)
#define AFX_RIGHTVIEW_H__20431321_C23A_47FD_93D0_0EEA07EDD592__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RightView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRightView form view
#include "ado.h"
#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CRightView : public CFormView
{
protected:
	CRightView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CRightView)

// Form Data
public:
	//{{AFX_DATA(CRightView)
	enum { IDD = IDD_FORMVIEW };
	CButton	m_top;
	CButton	m_last;
	CButton	m_front;
	CButton	m_back;
	CListCtrl	m_list;
	CString	m_tixing;
	CString	m_difficulty;
	CString	m_content;
	CString	m_pageno;
	//}}AFX_DATA

// Attributes
public:
	CToolTipCtrl m_tooltip;
	CADODatabase *pDB;
	CADORecordset *pRS;
	CString strtixing;
	int page;
	CString strsql;
	int selectrow;
//	CADORecordset &recordset;
//	CString strcondition;
// Operations
public:
	void OperationUpdate();
	void ShowThemeprocedure(CString strsql);
	void ShowThemefilltext(CString strsql);
	void Hidetopbuttom(int page);
	void ShowfullMessage(int selectrow);
	void ShowThemejudge(CString strsql);
	void ShowTheme(CString strsql);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRightView)
	public:
	virtual void OnInitialUpdate();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CRightView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CRightView)
	afx_msg void OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnFront();
	afx_msg void OnLast();
	afx_msg void OnBack();
	afx_msg void OnTop();
	afx_msg void OnDestroy();
	afx_msg void OnUpdate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RIGHTVIEW_H__20431321_C23A_47FD_93D0_0EEA07EDD592__INCLUDED_)
