#if !defined(AFX_BYPINYINDLG_H__E20A6B3C_AF3E_49D9_9B35_40AE6F8B9717__INCLUDED_)
#define AFX_BYPINYINDLG_H__E20A6B3C_AF3E_49D9_9B35_40AE6F8B9717__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BYPINYINDLG.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// BYPINYINDLG dialog

class BYPINYINDLG : public CDialog
{
// Construction
public:
	BYPINYINDLG(CWnd* pParent = NULL);   // standard constructor
   void ShowDate() ;
	void showsong();
	void addsong();
	void showsinger();
// Dialog Data
	//{{AFX_DATA(BYPINYINDLG)
	enum { IDD = IDD_BYPINYIN };
	CListCtrl	m_list;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(BYPINYINDLG)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(BYPINYINDLG)
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeEdit1();
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnUp();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BYPINYINDLG_H__E20A6B3C_AF3E_49D9_9B35_40AE6F8B9717__INCLUDED_)
