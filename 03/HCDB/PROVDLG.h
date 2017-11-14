#if !defined(AFX_PROVDLG_H__8B6F24E8_908B_412F_A1FA_CAECB60EDDA6__INCLUDED_)
#define AFX_PROVDLG_H__8B6F24E8_908B_412F_A1FA_CAECB60EDDA6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PROVDLG.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPROVDLG dialog
#include "Hutext.h"
extern CString m_extermprovid;
class CPROVDLG : public CDialog
{
// Construction
public:
	_RecordsetPtr m_record;
	bool flag;
	void SetEditStyle(int nSize);
	void SetStaticStyle();
	CPROVDLG(CWnd* pParent = NULL);   // standard constructor
    CFont   queryFont; 
// Dialog Data
	//{{AFX_DATA(CPROVDLG)
	enum { IDD = IDD_PROVDIALOG };
	CEdit	m_edit4ctrl;
	CEdit	m_edit3ctrl;
	CEdit	m_edit2ctrl;
	CEdit	m_edit1ctrl;
	Hutext	m_hutex23;
	Hutext	m_hutex22;
	Hutext	m_hutex21;
	Hutext	m_hutex20;
	Hutext	m_m_static3;
	Hutext	m_m_static;
	Hutext	m_m_static2;
	Hutext	m_static1;
	CString	m_edit1;
	CString	m_edit2;
	CString	m_edit3;
	CString	m_edit4;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPROVDLG)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPROVDLG)
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROVDLG_H__8B6F24E8_908B_412F_A1FA_CAECB60EDDA6__INCLUDED_)
