#if !defined(AFX_SUBJECTDLG_H__BEB1A787_2BCD_499C_A7AC_4CB45CA0E7BC__INCLUDED_)
#define AFX_SUBJECTDLG_H__BEB1A787_2BCD_499C_A7AC_4CB45CA0E7BC__INCLUDED_
#include "SubTab1Dlg.h"
#include "SubTab2Dlg.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SubjectDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSubjectDlg dialog

class CSubjectDlg : public CDialog
{
// Construction
public:
	CSubjectDlg(CWnd* pParent = NULL);   // standard constructor
    CSubTab1Dlg *m_pTab1Dlg;
	CSubTab2Dlg *m_pTab2Dlg;
	void CSubjectDlg::SetDlgState(CWnd *pWnd,BOOL bShow);
	void CSubjectDlg::DoTab(int nTab);
   	BOOL bTab[3];
// Dialog Data
	//{{AFX_DATA(CSubjectDlg)
	enum { IDD = IDD_Subject_DLG };
	CTabCtrl	m_Tab;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSubjectDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSubjectDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUBJECTDLG_H__BEB1A787_2BCD_499C_A7AC_4CB45CA0E7BC__INCLUDED_)
