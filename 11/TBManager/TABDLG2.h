#if !defined(AFX_TABDLG2_H__3B326289_A7FA_4D87_B18C_3DED512A825B__INCLUDED_)
#define AFX_TABDLG2_H__3B326289_A7FA_4D87_B18C_3DED512A825B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TABDLG2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTABDLG2 dialog

class CTABDLG2 : public CDialog
{
// Construction
public:
	CTABDLG2(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTABDLG2)
	enum { IDD = IDD_DIALOG_TAB2 };
	CString	m_tigan;
	CString	m_answer;
	CString	m_difficulty;
	int		m_tno;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTABDLG2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTABDLG2)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TABDLG2_H__3B326289_A7FA_4D87_B18C_3DED512A825B__INCLUDED_)
