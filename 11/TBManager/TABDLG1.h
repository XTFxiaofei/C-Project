#if !defined(AFX_TABDLG1_H__2C092501_9165_4A24_B733_6988610B6709__INCLUDED_)
#define AFX_TABDLG1_H__2C092501_9165_4A24_B733_6988610B6709__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TABDLG1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTABDLG1 dialog

class CTABDLG1 : public CDialog
{
// Construction
public:
	CTABDLG1(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTABDLG1)
	enum { IDD = IDD_DIALOG_TAB1 };
	CString	m_tigan;
	CString	m_xa;
	CString	m_xb;
	CString	m_xc;
	CString	m_xd;
	CString	m_answer;
	CString	m_difficulty;
	int		m_tno;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTABDLG1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTABDLG1)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TABDLG1_H__2C092501_9165_4A24_B733_6988610B6709__INCLUDED_)
