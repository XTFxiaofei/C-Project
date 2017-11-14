#if !defined(AFX_CLOCKDLG_H__2343C404_352F_4DC6_B014_44BBF8ECF847__INCLUDED_)
#define AFX_CLOCKDLG_H__2343C404_352F_4DC6_B014_44BBF8ECF847__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ClockDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CClockDlg dialog

class CClockDlg : public CNewDialog
{
// Construction
public:
	CClockDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CClockDlg)
	enum { IDD = IDD_CLOCK_DIALOG };
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClockDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CClockST m_Clock;

	// Generated message map functions
	//{{AFX_MSG(CClockDlg)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnViewClock();
	afx_msg UINT OnNcHitTest(CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLOCKDLG_H__2343C404_352F_4DC6_B014_44BBF8ECF847__INCLUDED_)
