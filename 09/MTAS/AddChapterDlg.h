#if !defined(AFX_ADDCHAPTERDLG_H__6DCE8037_E5A1_479A_A4F7_F42AE52B3A1E__INCLUDED_)
#define AFX_ADDCHAPTERDLG_H__6DCE8037_E5A1_479A_A4F7_F42AE52B3A1E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddChapterDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAddChapterDlg dialog

class CAddChapterDlg : public CNewDialog
{
// Construction
public:
	CAddChapterDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAddChapterDlg)
	enum { IDD = IDD_ADD_CHAPTER_DIALOG };
	CEdit	m_editClass;
	CWinXPButtonST	m_btnCancel;
	CWinXPButtonST	m_btnAdd;
	CString		m_strChapterName;
	CString		m_strClassName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddChapterDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddChapterDlg)
	afx_msg void OnAdd();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDCHAPTERDLG_H__6DCE8037_E5A1_479A_A4F7_F42AE52B3A1E__INCLUDED_)
