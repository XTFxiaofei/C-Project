#if !defined(AFX_TEACHERTAB2_H__259E7F45_4348_4ADA_A38D_F679D12316C8__INCLUDED_)
#define AFX_TEACHERTAB2_H__259E7F45_4348_4ADA_A38D_F679D12316C8__INCLUDED_
#include "TeacherSet.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TeacherTab2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTeacherTab2 dialog

class CTeacherTab2 : public CDialog
{
// Construction
public:
	CTeacherTab2(CWnd* pParent = NULL);   // standard constructor
	void CTeacherTab2::MyShow();
	CTeacherSet tecrSet;
// Dialog Data
	//{{AFX_DATA(CTeacherTab2)
	enum { IDD = IDD_TEACHER_DIALOG2 };
	CString	m_tecr_age;
	CString	m_tecr_id;
	CString	m_tecr_level;
	CString	m_tecr_name;
	CString	m_tecr_sex;
	CString	m_tecr_TRroom;
	CString	m_tecr_ascio;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTeacherTab2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTeacherTab2)
	afx_msg void OnTecrAdd();
	afx_msg void OnTecrDel();
	afx_msg void OnTecrEdit();
	afx_msg void OnTecrSave();
	afx_msg void OnTecrCancel();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEACHERTAB2_H__259E7F45_4348_4ADA_A38D_F679D12316C8__INCLUDED_)
