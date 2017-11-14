#if !defined(AFX_ADDSGEDLG_H__A39DBD2D_9AAF_4E48_8324_3DB92C8CC099__INCLUDED_)
#define AFX_ADDSGEDLG_H__A39DBD2D_9AAF_4E48_8324_3DB92C8CC099__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ADDSGEDLG.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ADDSGEDLG dialog

class ADDSGEDLG : public CDialog
{
// Construction
public:
	ADDSGEDLG(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ADDSGEDLG)
	enum { IDD = IDD_DIALOG3 };
	CComboBox	m_combo2;
	CComboBox	m_combo1;
	CString	m_singer;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ADDSGEDLG)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ADDSGEDLG)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDSGEDLG_H__A39DBD2D_9AAF_4E48_8324_3DB92C8CC099__INCLUDED_)
