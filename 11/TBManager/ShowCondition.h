#if !defined(AFX_SHOWCONDITION_H__1A4DFD19_1D9D_4224_838E_CFDB908A0869__INCLUDED_)
#define AFX_SHOWCONDITION_H__1A4DFD19_1D9D_4224_838E_CFDB908A0869__INCLUDED_
#include "ado.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ShowCondition.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CShowCondition dialog

class CShowCondition : public CDialog
{
// Construction
public:
	CString ShowFullSubject(CString strsql);
	CADODatabase *pDB;
	CADORecordset *pRS;
	void ShowData();
	CShowCondition(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CShowCondition)
	enum { IDD = IDD_DIALOG1 };
	int		m_difficult2;
	int		m_difficult4;
	CString	m_fulldifficult;
	CString	m_fullscore;
	int		m_num1;
	int		m_num2;
	int		m_num3;
	int		m_num4;
	int		m_score1;
	int		m_score2;
	int		m_score3;
	int		m_score4;
	int		m_difficult1;
	int		m_difficult3;
	CString	m_examname;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowCondition)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CShowCondition)
	afx_msg void OnCheck1();
	afx_msg void OnCheck2();
	afx_msg void OnCheck3();
	afx_msg void OnCheck4();
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeDifficult1();
	afx_msg void OnChangeDifficult2();
	afx_msg void OnChangeDifficult3();
	afx_msg void OnChangeDifficult4();
	afx_msg void OnChangeNum1();
	afx_msg void OnChangeNum2();
	afx_msg void OnChangeNum3();
	afx_msg void OnChangeNum4();
	afx_msg void OnChangeScore1();
	afx_msg void OnChangeScore2();
	afx_msg void OnChangeScore3();
	afx_msg void OnChangeScore4();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWCONDITION_H__1A4DFD19_1D9D_4224_838E_CFDB908A0869__INCLUDED_)
