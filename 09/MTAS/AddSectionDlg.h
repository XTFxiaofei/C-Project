#if !defined(AFX_ADDSECTIONDLG_H__AA585FE7_566D_4555_9561_5D93510E0F4A__INCLUDED_)
#define AFX_ADDSECTIONDLG_H__AA585FE7_566D_4555_9561_5D93510E0F4A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddSectionDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAddSectionDlg dialog

class CAddSectionDlg : public CNewDialog
{
// Construction
public:
	CAddSectionDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAddSectionDlg)
	enum { IDD = IDD_ADD_SECTION_DIALOG };
	CEdit	m_editChapter;
	CEdit	m_editClass;
	CWinXPButtonST	m_btnCancel;
	CWinXPButtonST	m_btnAdd;
	CString		m_strChapterName;
	CString		m_strClassName;
	CString		m_strSectionName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddSectionDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddSectionDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnAdd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDSECTIONDLG_H__AA585FE7_566D_4555_9561_5D93510E0F4A__INCLUDED_)
