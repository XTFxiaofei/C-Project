#if !defined(AFX_STUCHOISUBDLG_H__28948DCE_BD60_484D_9620_B5C51AC31256__INCLUDED_)
#define AFX_STUCHOISUBDLG_H__28948DCE_BD60_484D_9620_B5C51AC31256__INCLUDED_

#include "SubjectSet.h"
#include "ChoiceSubSet.h"
//#include "SubjectSet.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StuChoiSubDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStuChoiSubDlg dialog

class CStuChoiSubDlg : public CDialog
{
// Construction
public:
	CStuChoiSubDlg(CWnd* pParent = NULL);   // standard constructor
	CSubjectSet psubSet;			//定义记录集对象
	CChoiceSubSet pchoisubSet;
    BOOL flag;
// Dialog Data
	//{{AFX_DATA(CStuChoiSubDlg)
	enum { IDD = IDD_SubDLG };
	CListCtrl	m_ChoiSubList;
	//}}AFX_DATA
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStuChoiSubDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CStuChoiSubDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnDclrSubBTN();
	afx_msg void OnStuInfoBTN();
	afx_msg void OnTecrInfoBTN();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUCHOISUBDLG_H__28948DCE_BD60_484D_9620_B5C51AC31256__INCLUDED_)
