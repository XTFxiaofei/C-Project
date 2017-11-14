#if !defined(AFX_SINGIN_H__712C406C_0DA1_436C_9732_F646BD99F94B__INCLUDED_)
#define AFX_SINGIN_H__712C406C_0DA1_436C_9732_F646BD99F94B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SINGIN.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// SINGIN dialog

class SINGIN : public CDialog
{
// Construction
public:
	SINGIN(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(SINGIN)
	enum { IDD = IDD_DIALOG2 };
	CComboBox	m_combo2;
	CComboBox	m_combo1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SINGIN)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(SINGIN)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SINGIN_H__712C406C_0DA1_436C_9732_F646BD99F94B__INCLUDED_)
