#if !defined(AFX_ADDCHAPTERDLG2_H__4FC34A89_528F_4B28_BE1E_92BCB70DB596__INCLUDED_)
#define AFX_ADDCHAPTERDLG2_H__4FC34A89_528F_4B28_BE1E_92BCB70DB596__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddChapterDlg2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAddChapterDlg2 dialog

class CAddChapterDlg2 : public CNewDialog
{
// Construction
public:
	CAddChapterDlg2(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAddChapterDlg2)
	enum { IDD = IDD_ADD_CHAPTER_DIALOG2 };
	CComboBoxXP	m_cbClass;
	CWinXPButtonST	m_btnCancel;
	CWinXPButtonST	m_btnAdd;
	CString	m_strChapterName;
	//}}AFX_DATA
	CString m_strClassName;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddChapterDlg2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddChapterDlg2)
	virtual BOOL OnInitDialog();
	afx_msg void OnAdd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDCHAPTERDLG2_H__4FC34A89_528F_4B28_BE1E_92BCB70DB596__INCLUDED_)
