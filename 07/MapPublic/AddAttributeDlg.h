#if !defined(AFX_ADDATTRIBUTEDLG_H__51A5956E_CC37_4CFF_A3E4_875C16CC0951__INCLUDED_)
#define AFX_ADDATTRIBUTEDLG_H__51A5956E_CC37_4CFF_A3E4_875C16CC0951__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddAttributeDlg.h : header file
//
#include "XPButton.h"
/////////////////////////////////////////////////////////////////////////////
// CAddAttributeDlg dialog

class CAddAttributeDlg : public CDialog
{
// Construction
public:
	CAddAttributeDlg(CWnd* pParent = NULL);   // standard constructor

	bool m_check;
// Dialog Data
	//{{AFX_DATA(CAddAttributeDlg)
	enum { IDD = IDD_ADD_SELECT_ATTRIBUTE };
	CXPButton	m_cancel;
	CString	m_strAttribute;
	CString	m_strName;
	CString	m_pitcure_name;
	//}}AFX_DATA

   
   bool writeflag;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddAttributeDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddAttributeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnAdd();
	virtual void OnCancel();
	afx_msg void OnCheck();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDATTRIBUTEDLG_H__51A5956E_CC37_4CFF_A3E4_875C16CC0951__INCLUDED_)
