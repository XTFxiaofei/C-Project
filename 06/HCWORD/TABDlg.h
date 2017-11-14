#if !defined(AFX_TABDLG_H__8D9B8F28_3E44_4710_826C_351A4FB48350__INCLUDED_)
#define AFX_TABDLG_H__8D9B8F28_3E44_4710_826C_351A4FB48350__INCLUDED_
#include "TIANJIADlg.h"
#include "HCset.h"
//#include "PreParent.h"
#include "HY.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TABDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// TABDlg dialog

class TABDlg : public CDialog
{
// Construction
public:
	TABDlg(CWnd* pParent = NULL);   // standard constructor
    	CString string1,string2;
    static void DrawInfo(CDC &memDC, PRNINFO PrnInfo);
	HCset *m_pSet;
	HY *m_set;
	CDatabase *pdb;
	CString word;
	bool showdlgflag;
	void ShowData();
    CString Time;
// Dialog Data
	//{{AFX_DATA(TABDlg)
	enum { IDD = IDD_DIALOG2 };
	CSpinButtonCtrl	m_spin;
	CListCtrl	m_list;
	int		m_mosh;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(TABDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
//   static void DrawInfo(CDC &memDC, PRNINFO PrnInfo);
    // Generated message map functions
	//{{AFX_MSG(TABDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnOutofmemorySpin1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnModify();
	afx_msg void OnAdd();
	afx_msg void OnOut();
	afx_msg void OnDelete();
	afx_msg void OnPrint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TABDLG_H__8D9B8F28_3E44_4710_826C_351A4FB48350__INCLUDED_)
