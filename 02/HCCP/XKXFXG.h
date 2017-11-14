#if !defined(AFX_XKXFXG_H__8C3E773D_2CA1_4095_85D7_B8426F234657__INCLUDED_)
#define AFX_XKXFXG_H__8C3E773D_2CA1_4095_85D7_B8426F234657__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// XKXFXG.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// XKXFXG dialog

class XKXFXG : public CDialog
{
// Construction
public:
	XKXFXG(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(XKXFXG)
	enum { IDD = IDD_XKXFXG };
	CString	m_xkm;
	float	m_xuekf;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(XKXFXG)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(XKXFXG)
	afx_msg void OnXfxg();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XKXFXG_H__8C3E773D_2CA1_4095_85D7_B8426F234657__INCLUDED_)
