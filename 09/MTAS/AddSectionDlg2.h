#if !defined(AFX_ADDSECTIONDLG2_H__34ED6711_33E3_47FF_B7F5_4D97352E7384__INCLUDED_)
#define AFX_ADDSECTIONDLG2_H__34ED6711_33E3_47FF_B7F5_4D97352E7384__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddSectionDlg2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAddSectionDlg2 dialog

class CAddSectionDlg2 : public CNewDialog
{
// Construction
public:
	CAddSectionDlg2(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAddSectionDlg2)
	enum { IDD = IDD_ADD_SECTION_DIALOG2 };
	CWinXPButtonST	m_btnCancel;
	CComboBoxXP		m_cbClass;
	CComboBoxXP		m_cbChapter;
	CWinXPButtonST	m_btnAdd;
	CString	m_strSectionName;
	//}}AFX_DATA
	CString m_strClassName;
	CString m_strChapterName;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddSectionDlg2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddSectionDlg2)
	virtual BOOL OnInitDialog();
	afx_msg void OnAdd();
	afx_msg void OnSelchangeComboClass();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDSECTIONDLG2_H__34ED6711_33E3_47FF_B7F5_4D97352E7384__INCLUDED_)
