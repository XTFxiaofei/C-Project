#if !defined(AFX_TABDLG4_H__AD5EBF78_F938_4FC9_9BA7_0D9CA1CD9E3D__INCLUDED_)
#define AFX_TABDLG4_H__AD5EBF78_F938_4FC9_9BA7_0D9CA1CD9E3D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TABDLG4.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTABDLG4 dialog

class CTABDLG4 : public CDialog
{
// Construction
public:
	CTABDLG4(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTABDLG4)
	enum { IDD = IDD_DIALOG_TAB4 };
	CString	m_tigan;
	CString	m_answer;
	CString	m_difficulty;
	int		m_tno;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTABDLG4)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTABDLG4)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TABDLG4_H__AD5EBF78_F938_4FC9_9BA7_0D9CA1CD9E3D__INCLUDED_)
