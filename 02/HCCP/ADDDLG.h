#if !defined(AFX_ADDDLG_H__E6410F6D_DD3F_4A26_A96E_292452AC7263__INCLUDED_)
#define AFX_ADDDLG_H__E6410F6D_DD3F_4A26_A96E_292452AC7263__INCLUDED_
#include "ADOConn.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ADDDLG.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ADDDLG dialog

class ADDDLG : public CDialog
{
// Construction
public:
	ADDDLG(CWnd* pParent = NULL);   // standard constructor

	void XueSheng();
	ADOConn myado;_RecordsetPtr m_pRc;
	int k;_bstr_t leaf;CString str,str1,str2,zhao;_bstr_t sQL;
// Dialog Data
	//{{AFX_DATA(ADDDLG)
	enum { IDD = IDD_ADDDLG };
	CComboBox	m_xhao;
	CButton	m_xuanze;
	CStatic	m_mz;
	CString	m_name;
	CString	m_cno;
	float	m_cgrade;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ADDDLG)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ADDDLG)
	virtual BOOL OnInitDialog();
	afx_msg void OnCheck1();
	afx_msg void OnSelchangeXhao();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDDLG_H__E6410F6D_DD3F_4A26_A96E_292452AC7263__INCLUDED_)
