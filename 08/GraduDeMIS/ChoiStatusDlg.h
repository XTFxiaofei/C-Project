#if !defined(AFX_CHOISTATUSDLG_H__7AE2883B_B24D_405A_9D9B_E38375766610__INCLUDED_)
#define AFX_CHOISTATUSDLG_H__7AE2883B_B24D_405A_9D9B_E38375766610__INCLUDED_
#include "ChoiceSubSet.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ChoiStatusDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CChoiStatusDlg dialog

class CChoiStatusDlg : public CDialog
{
// Construction
public:
	CChoiStatusDlg(CWnd* pParent = NULL);   // standard constructor
	CChoiceSubSet choisubSet;				//定义记录集对象


// Dialog Data
	//{{AFX_DATA(CChoiStatusDlg)
	enum { IDD = IDD_ChoiStatusShow_DLG };
	CString	m_strChoiSubStatus;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChoiStatusDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CChoiStatusDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSeeChoisubInfoBTN();
	afx_msg void OnEnterChoiSubBTN();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHOISTATUSDLG_H__7AE2883B_B24D_405A_9D9B_E38375766610__INCLUDED_)
