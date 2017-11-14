#if !defined(AFX_ADDDLG_H__5A2CD429_CA2F_4E50_9D83_AFD4F0D12B89__INCLUDED_)
#define AFX_ADDDLG_H__5A2CD429_CA2F_4E50_9D83_AFD4F0D12B89__INCLUDED_
#include "TABDLG1.h"
#include "TABDLG2.h"
#include "TABDLG3.h"
#include "TABDLG4.h"
#include "RightView.h"
#include "ado.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ADDDLG.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CADDDLG dialog

class CADDDLG : public CDialog
{
// Construction
public:
	int font;//set the ÑשÊ½
	void DoTab(int ntab);
	void SetDlgState(CWnd *pWnd,BOOL bShow);
	CADDDLG(CWnd* pParent = NULL);   // standard constructor
	CTABDLG1 *m_ptab1;
	CTABDLG2 *m_ptab2;
	CTABDLG3 *m_ptab3;
	CTABDLG4 *m_ptab4;
	int position;
//	CRightView *m_prview;
	int nselect;
	CADODatabase *pDB;
	CADORecordset *pRS;
// Dialog Data
	//{{AFX_DATA(CADDDLG)
	enum { IDD = IDD_DIALOG_ADD };
	CTabCtrl	m_tab;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CADDDLG)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CImageList m_imagelist;
	// Generated message map functions
	//{{AFX_MSG(CADDDLG)
	afx_msg void OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDDLG_H__5A2CD429_CA2F_4E50_9D83_AFD4F0D12B89__INCLUDED_)
