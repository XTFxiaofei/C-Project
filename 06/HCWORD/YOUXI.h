#if !defined(AFX_YOUXI_H__88642195_5E73_4288_89FC_CC82FADBC618__INCLUDED_)
#define AFX_YOUXI_H__88642195_5E73_4288_89FC_CC82FADBC618__INCLUDED_
#include "Hutext.h"
#include "ASW.h"
#include "mmsystem.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// YOUXI.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// YOUXI dialog

class YOUXI : public CDialog
{
// Construction
public:
	YOUXI(CWnd* pParent = NULL);   // standard constructor
  

    CString n;
	CDatabase *pdb;
    ASW *m_pset;
	CString danci;
	long mn;
	int j;
	int i;
	void ddd(void);
	Hutext m_resultControl;
	Hutext m_resultControl1;
	Hutext m_resultControl2;
// Dialog Data
	//{{AFX_DATA(YOUXI)
	enum { IDD = IDD_DIALOG6 };

	CButton	m_26;
	CButton	m_25;
	CButton	m_24;
	CButton	m_23;
	CButton	m_22;
	CButton	m_21;
	CButton	m_20;
	CButton	m_19;
	CButton	m_18;
	CButton	m_17;
	CButton	m_16;
	CButton	m_15;
	CButton	m_14;
	CButton	m_13;
	CButton	m_12;
	CButton	m_11;
	CButton	m_10;
	CButton	m_9;
	CButton	m_8;
	CButton	m_7;
	CButton	m_2;
	CButton	m_6;
	CButton	m_5;
	CButton	m_4;
	CButton	m_3;
	CButton	m_1;
	CString	m_result;
	CString	m_test1;
	CString	m_test;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(YOUXI)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(YOUXI)
	virtual BOOL OnInitDialog();
	afx_msg void OnButton27();
	afx_msg void OnButton29();
	afx_msg void OnButton30();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	afx_msg  void OnNumberKey(UINT nID);    

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_YOUXI_H__88642195_5E73_4288_89FC_CC82FADBC618__INCLUDED_)
