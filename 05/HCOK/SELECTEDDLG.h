#if !defined(AFX_SELECTEDDLG_H__6E159874_E8A7_4665_B7A5_D1C18E49478C__INCLUDED_)
#define AFX_SELECTEDDLG_H__6E159874_E8A7_4665_B7A5_D1C18E49478C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SELECTEDDLG.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// SELECTEDDLG dialog

class SELECTEDDLG : public CDialog
{
// Construction
public:
	SELECTEDDLG(CWnd* pParent = NULL);   // standard constructor
   void ShowDate();
   int getSongNum();
// Dialog Data
	//{{AFX_DATA(SELECTEDDLG)
	enum { IDD = IDD_SELECTED };
	CListCtrl	m_list;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SELECTEDDLG)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(SELECTEDDLG)
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SELECTEDDLG_H__6E159874_E8A7_4665_B7A5_D1C18E49478C__INCLUDED_)
