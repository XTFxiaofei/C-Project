#if !defined(AFX_STUDENTDLG_H__DA8FBED2_D7D0_4AC8_8426_0072B6830C65__INCLUDED_)
#define AFX_STUDENTDLG_H__DA8FBED2_D7D0_4AC8_8426_0072B6830C65__INCLUDED_
#include "StudentTab1.h"
#include "StudentTab2.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StudentDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStudentDlg dialog

class CStudentDlg : public CDialog
{
// Construction
public:
	CStudentDlg(CWnd* pParent = NULL);   // standard constructor

	CStudentTab1 *m_pTab1Dlg;			//定义对话框指针
	CStudentTab2 *m_pTab2Dlg;
	void CStudentDlg::SetDlgState(CWnd *pWnd,BOOL bShow);
	void CStudentDlg::DoTab(int nTab);
	CStudentSet pSet;
	BOOL bTab[3];
//	extern str;

// Dialog Data
	//{{AFX_DATA(CStudentDlg)
	enum { IDD = IDD_STU_DIALOG };
	CTabCtrl	m_Tab;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStudentDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CStudentDlg)
	afx_msg void OnDestroy();
	afx_msg void OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUDENTDLG_H__DA8FBED2_D7D0_4AC8_8426_0072B6830C65__INCLUDED_)
