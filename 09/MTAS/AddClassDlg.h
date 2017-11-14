#if !defined(AFX_ADDCLASSDLG_H__34F22DEE_A844_461D_9FC5_D1BF868A184C__INCLUDED_)
#define AFX_ADDCLASSDLG_H__34F22DEE_A844_461D_9FC5_D1BF868A184C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddClassDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAddClassDlg dialog

class CAddClassDlg : public CNewDialog
{
// Construction
public:
	CAddClassDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAddClassDlg)
	enum { IDD = IDD_ADD_CLASS_DIALOG };
	CWinXPButtonST	m_btnCancel;
	CWinXPButtonST	m_btnAdd;
	CString		m_strClassName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddClassDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddClassDlg)
	afx_msg void OnAdd();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDCLASSDLG_H__34F22DEE_A844_461D_9FC5_D1BF868A184C__INCLUDED_)
