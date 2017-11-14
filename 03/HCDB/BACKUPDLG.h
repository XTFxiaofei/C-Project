#if !defined(AFX_BACKUPDLG_H__B473EDA8_FE51_4F7E_8D69_32EA01E264A1__INCLUDED_)
#define AFX_BACKUPDLG_H__B473EDA8_FE51_4F7E_8D69_32EA01E264A1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BACKUPDLG.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// BACKUPDLG dialog

class BACKUPDLG : public CDialog
{
// Construction
public:
	void Connect();
	_ConnectionPtr m_connection;
	BACKUPDLG(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(BACKUPDLG)
	enum { IDD = IDD_BACKUPDIALOG };
	CString	m_edit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(BACKUPDLG)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(BACKUPDLG)
	afx_msg void OnButton1();
	afx_msg void OnButton3();
	virtual BOOL OnInitDialog();
	afx_msg void OnButton4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BACKUPDLG_H__B473EDA8_FE51_4F7E_8D69_32EA01E264A1__INCLUDED_)
