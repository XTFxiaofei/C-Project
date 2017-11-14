#if !defined(AFX_CHOISUBDLG_H__21C25D36_692A_4AAA_AD9F_28A5508827BC__INCLUDED_)
#define AFX_CHOISUBDLG_H__21C25D36_692A_4AAA_AD9F_28A5508827BC__INCLUDED_
#include "SubjectSet.h"
#include "TeacherSet.h"
#include "ChoiceSubSet.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ChoisubDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CChoisubDlg dialog

class CChoisubDlg : public CDialog
{
// Construction
public:
	CChoisubDlg(CWnd* pParent = NULL);   // standard constructor
    void  SelectItem(int n);
	CSubjectSet psubSet;				//定义记录集对象
	CTeacherSet ptecrSet;				//定义记录集对象
	CChoiceSubSet pchoisubSet;

//	CStuLoginSet pstuloginSet;
// Dialog Data
	//{{AFX_DATA(CChoisubDlg)
	enum { IDD = IDD_SubInfoDLG };
	CEdit	m_QueSubCtrl;
	CListCtrl	m_SubQueryList;
	CComboBox	m_SubQueryCombo;
	CString	m_QueSubVal;
	//}}AFX_DATA

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChoisubDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CChoisubDlg)
	afx_msg void OnQueryBtn();
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkSubQueryLIST(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHOISUBDLG_H__21C25D36_692A_4AAA_AD9F_28A5508827BC__INCLUDED_)
