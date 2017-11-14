#if !defined(AFX_WAGECALDLG_H__8B2FABFF_3C07_48E8_B63A_034448DCD199__INCLUDED_)
#define AFX_WAGECALDLG_H__8B2FABFF_3C07_48E8_B63A_034448DCD199__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WageCalDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWageCalDlg dialog

class CWageCalDlg : public CDialog
{
// Construction
public:
	CWageCalDlg(CWnd* pParent = NULL);   // standard constructor
	_RecordsetPtr m_pRecordset;
// Dialog Data
	//{{AFX_DATA(CWageCalDlg)
	enum { IDD = IDD_WAGE_CAL_DLG };
	int		m_bingjia;
	int		m_chuchai;
	int		m_fading;
	int		m_pingshi;
	int		m_shijia;
	int		m_shuangxiu;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWageCalDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWageCalDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSure();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WAGECALDLG_H__8B2FABFF_3C07_48E8_B63A_034448DCD199__INCLUDED_)
