#if !defined(AFX_TEACHERDLG_H__7ED0ED24_E779_441C_B110_FA31A7D446ED__INCLUDED_)
#define AFX_TEACHERDLG_H__7ED0ED24_E779_441C_B110_FA31A7D446ED__INCLUDED_

#include "TeacherTab1.h"
#include "TeacherTab2.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TeacherDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTeacherDlg dialog

class CTeacherDlg : public CDialog
{
// Construction
public:
	CTeacherDlg(CWnd* pParent = NULL);   // standard constructor

	CTeacherTab1 *m_pTab1Dlg;
	CTeacherTab2 *m_pTab2Dlg;
	void CTeacherDlg::SetDlgState(CWnd *pWnd,BOOL bShow);
	void CTeacherDlg::DoTab(int nTab);

	BOOL bTab[3];

// Dialog Data
	//{{AFX_DATA(CTeacherDlg)
	enum { IDD = IDD_TEACHER_DIALOG };
	CTabCtrl	m_TeacherTab;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTeacherDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTeacherDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	afx_msg void OnSelchangeTeacherTab(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEACHERDLG_H__7ED0ED24_E779_441C_B110_FA31A7D446ED__INCLUDED_)
