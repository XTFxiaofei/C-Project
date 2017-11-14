#if !defined(AFX_TIANJIADLG_H__7F898175_82CB_45DB_9130_37D7D5D5B4CE__INCLUDED_)
#define AFX_TIANJIADLG_H__7F898175_82CB_45DB_9130_37D7D5D5B4CE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TIANJIADlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// TIANJIADlg dialog

class TIANJIADlg : public CDialog
{
// Construction
public:
	TIANJIADlg(CWnd* pParent = NULL);   // standard constructor
	bool addflag;
// Dialog Data
	//{{AFX_DATA(TIANJIADlg)
	enum { IDD = IDD_DIALOG4 };
	CEdit	m_word;
	CString	m_1;
	CString	m_3;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(TIANJIADlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(TIANJIADlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIANJIADLG_H__7F898175_82CB_45DB_9130_37D7D5D5B4CE__INCLUDED_)
