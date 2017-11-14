#if !defined(AFX_HANDPAPERS_H__3897376C_54DC_4108_8F8D_7228003ED7A9__INCLUDED_)
#define AFX_HANDPAPERS_H__3897376C_54DC_4108_8F8D_7228003ED7A9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HandPapers.h : header file
//
#include "ado.h"
/////////////////////////////////////////////////////////////////////////////
// CHandPapers dialog

class CHandPapers : public CDialog
{
// Construction
public:
	int listcount1,listcount2,listcount3,listcount4;
	CString str1,str2,str3,str4,str5;
	void ShowRecord();
	CString strsql;
	CADODatabase *pDB;
	CADORecordset *pRS;
	void ShowFullScore();
	void ShowScore4();
	void ShowScore3();
	void ShowScore2();
	void ShowScore1();
	CHandPapers(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CHandPapers)
	enum { IDD = IDD_DIALOG_HAND };
	CListBox	m_listprocedure;
	CListBox	m_listfilltext;
	CListBox	m_listjudge;
	CListBox	m_listchoose;
	CComboBox	m_combo2;
	CComboBox	m_combo1;
	int		m_num1;
	int		m_num2;
	int		m_num3;
	int		m_num4;
	int		m_score1;
	int		m_score2;
	int		m_score3;
	int		m_score4;
	CString	m_fscore1;
	CString	m_fscore2;
	CString	m_fscore3;
	CString	m_fscore4;
	CString	m_fullscore;
	CString	m_page;
	CString	m_pagesname;
	CString	m_subjectcontent;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHandPapers)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CHandPapers)
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeNum1();
	afx_msg void OnChangeNum2();
	afx_msg void OnChangeNum3();
	afx_msg void OnChangeNum4();
	afx_msg void OnChangeScore1();
	afx_msg void OnChangeScore2();
	afx_msg void OnChangeScore3();
	afx_msg void OnChangeScore4();
	virtual void OnOK();
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnSelchangeCombo2();
	afx_msg void OnTop();
	afx_msg void OnBack();
	afx_msg void OnLast();
	afx_msg void OnFront();
	afx_msg void OnAddtheme();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HANDPAPERS_H__3897376C_54DC_4108_8F8D_7228003ED7A9__INCLUDED_)
