#if !defined(AFX_ADDCOURSEWAREDLG3_H__DB7E32C1_8488_4580_A429_73618970740E__INCLUDED_)
#define AFX_ADDCOURSEWAREDLG3_H__DB7E32C1_8488_4580_A429_73618970740E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddCoursewareDlg3.h : header file
//

#include "DlgListCtrl.h"
/////////////////////////////////////////////////////////////////////////////
// CAddCoursewareDlg3 dialog

class CAddCoursewareDlg3 : public CNewDialog
{
// Construction
public:
	CAddCoursewareDlg3(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAddCoursewareDlg3)
	enum { IDD = IDD_ADD_COURSEWARE_DIALOG3 };
	CWinXPButtonST	m_btnDel;
	CWinXPButtonST	m_btnCancel;
	CWinXPButtonST	m_btnOk;
	CWinXPButtonST	m_btnBrowse;
	CString	m_strChapter;
	CString	m_strClass;
	CString	m_strSection;
	//}}AFX_DATA

	
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddCoursewareDlg3)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

public:
	std::vector<CCourseWareInfo> m_vecCwi;

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddCoursewareDlg3)
	virtual void OnOK();
	afx_msg void OnButtonBrowse();
	virtual BOOL OnInitDialog();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	afx_msg void OnButtonDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	
	CDlgListCtrl	m_listCourseware;
	CClassRecordset		m_rsClass;
	CChapterRecordset	m_rsChapter;
	CSectionRecordset	m_rsSection;
private:
	CString GetFileExtFromPath(const CString& strFilePath);
	CString GetFileNameFromPath(const CString& strFilePath);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDCOURSEWAREDLG3_H__DB7E32C1_8488_4580_A429_73618970740E__INCLUDED_)
