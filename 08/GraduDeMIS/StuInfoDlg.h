#if !defined(AFX_STUINFODLG_H__484E57F8_917C_4E25_A942_EF50A5292C90__INCLUDED_)
#define AFX_STUINFODLG_H__484E57F8_917C_4E25_A942_EF50A5292C90__INCLUDED_
//#include "StuLoginSet.h"
#include "SubjectSet.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StuInfoDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStuInfoDlg dialog

class CStuInfoDlg : public CDialog
{
// Construction
public:
	CStuInfoDlg(CWnd* pParent = NULL);   // standard constructor
	bool flag;
//	CStuLoginSet pStuLgnSet;
	CSubjectSet psubSet;
	void MyHide(int n);
// Dialog Data
	//{{AFX_DATA(CStuInfoDlg)
	enum { IDD = IDD_StuInfo_DLG };
	CString	m_ChoiSubStatusVal;
	CString	m_EnsuPswdVal;
	CString	m_FormerPswdVal;
	CString	m_NewPswdVal;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStuInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CStuInfoDlg)
	afx_msg void OnEditPswdBTN();
	afx_msg void OnOkBTN();
	afx_msg void OnQueChoiedSubBTN();
	afx_msg void OnCancelBTN();
	virtual BOOL OnInitDialog();
	afx_msg void OnToChoiSubBTN();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUINFODLG_H__484E57F8_917C_4E25_A942_EF50A5292C90__INCLUDED_)
