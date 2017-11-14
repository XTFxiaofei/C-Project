#if !defined(AFX_ZHPCDLG_H__D027BC6A_08D2_459C_9401_BA313EBE0E66__INCLUDED_)
#define AFX_ZHPCDLG_H__D027BC6A_08D2_459C_9401_BA313EBE0E66__INCLUDED_
#include "ADOConn.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ZHPCDLG.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ZHPCDLG dialog

class ZHPCDLG : public CDialog
{
// Construction
public:
	ZHPCDLG(CWnd* pParent = NULL);   // standard constructor
	void ShengCh();
	float xkzh,xfzh,deyu,tiyu,fujia,zcj;
	ADOConn myado;
	BOOL flg;
	static void DrawInfo(CDC &memDC, PRNINFO PrnInfo);
// Dialog Data
	//{{AFX_DATA(ZHPCDLG)
	enum { IDD = IDD_ZHPCDLG };
	CListCtrl	m_list3;
	float	m_zhiyu;
	float	m_tiyu;
	float	m_fujia;
	float	m_deyu;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ZHPCDLG)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ZHPCDLG)
	virtual BOOL OnInitDialog();
	afx_msg void OnJisuan();
	afx_msg void OnZpx();
	afx_msg void OnPrint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZHPCDLG_H__D027BC6A_08D2_459C_9401_BA313EBE0E66__INCLUDED_)
