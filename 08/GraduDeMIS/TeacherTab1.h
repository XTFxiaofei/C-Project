#if !defined(AFX_TEACHERTAB1_H__257F2556_4BDE_4D43_8E39_ED2A5963F323__INCLUDED_)
#define AFX_TEACHERTAB1_H__257F2556_4BDE_4D43_8E39_ED2A5963F323__INCLUDED_
#include "TeacherSet.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TeacherTab1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTeacherTab1 dialog

class CTeacherTab1 : public CDialog
{
// Construction
public:
	CTeacherTab1(CWnd* pParent = NULL);   // standard constructor
    CTeacherSet pSet1;
	void SelectItem(int n);
// Dialog Data
	//{{AFX_DATA(CTeacherTab1)
	enum { IDD = IDD_TEACHER_DIALOG1 };
	CEdit	m_tecr_editctrl;
	CComboBox	m_tecr_combo;
	CListCtrl	m_tecr_listctrl;
	CString	m_tecr_edit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTeacherTab1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	static void DrawInfo(CDC &memDC, PRNINFO PrnInfo);

	// Generated message map functions
	//{{AFX_MSG(CTeacherTab1)
	virtual BOOL OnInitDialog();
	afx_msg void OnTeacherBtn();
	afx_msg void OnItemchangedTeacherList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnPrinttest();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEACHERTAB1_H__257F2556_4BDE_4D43_8E39_ED2A5963F323__INCLUDED_)
