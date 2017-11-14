#if !defined(AFX_QUERYDLG_H__76F2A6CB_5A96_4305_9CD9_A6C4B493778B__INCLUDED_)
#define AFX_QUERYDLG_H__76F2A6CB_5A96_4305_9CD9_A6C4B493778B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// QueryDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// QueryDlg dialog

class QueryDlg : public CDialog
{
// Construction
public:
	QueryDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(QueryDlg)
	enum { IDD = IDD_DIALOG2 };
	CString	m_condition;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(QueryDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(QueryDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QUERYDLG_H__76F2A6CB_5A96_4305_9CD9_A6C4B493778B__INCLUDED_)
