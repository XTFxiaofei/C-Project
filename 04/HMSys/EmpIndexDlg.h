#if !defined(AFX_EMPINDEXDLG_H__4415F24A_F936_449C_BE5E_373A4A164D7C__INCLUDED_)
#define AFX_EMPINDEXDLG_H__4415F24A_F936_449C_BE5E_373A4A164D7C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EmpIndexDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEmpIndexDlg dialog

class CEmpIndexDlg : public CDialog
{
// Construction
public:
	CEmpIndexDlg(CWnd* pParent = NULL);   // standard constructor
	int m_nFlag;
// Dialog Data
	//{{AFX_DATA(CEmpIndexDlg)
	enum { IDD = IDD_EMP_INDEX_DLG };
	CButton	m_Radio;
	CString	m_strID;
	CString	m_strName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEmpIndexDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEmpIndexDlg)
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EMPINDEXDLG_H__4415F24A_F936_449C_BE5E_373A4A164D7C__INCLUDED_)
