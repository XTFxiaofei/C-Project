#if !defined(AFX_PASSDLG_H__9833763E_F388_419C_B091_282C2BB24A5A__INCLUDED_)
#define AFX_PASSDLG_H__9833763E_F388_419C_B091_282C2BB24A5A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PASSDLG.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PASSDLG dialog

class PASSDLG : public CDialog
{
// Construction
public:
	PASSDLG(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PASSDLG)
	enum { IDD = IDD_DIALOG1 };
	CString	m_user;
	CString	m_pass;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PASSDLG)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(PASSDLG)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PASSDLG_H__9833763E_F388_419C_B091_282C2BB24A5A__INCLUDED_)
