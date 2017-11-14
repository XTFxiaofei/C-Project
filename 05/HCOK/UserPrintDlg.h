#if !defined(AFX_USERPRINTDLG_H__8182F4F0_F0D1_4374_BC7B_27CAA5A9E31D__INCLUDED_)
#define AFX_USERPRINTDLG_H__8182F4F0_F0D1_4374_BC7B_27CAA5A9E31D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UserPrintDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// UserPrintDlg dialog

class UserPrintDlg : public CDialog
{
// Construction
public:
	UserPrintDlg(CWnd* pParent = NULL);   // standard constructor
   void showprint();
   	static void DrawInfo(CDC &memDC, PRNINFO PrnInfo);
// Dialog Data
	//{{AFX_DATA(UserPrintDlg)
	enum { IDD = IDD_DIALOG4 };
	CListCtrl	m_list;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(UserPrintDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(UserPrintDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERPRINTDLG_H__8182F4F0_F0D1_4374_BC7B_27CAA5A9E31D__INCLUDED_)
