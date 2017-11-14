#if !defined(AFX_MODIFISINGER_H__C32D9115_F648_4D25_A9E6_6832614D1BF7__INCLUDED_)
#define AFX_MODIFISINGER_H__C32D9115_F648_4D25_A9E6_6832614D1BF7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MODIFISINGER.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// MODIFISINGER dialog

class MODIFISINGER : public CDialog
{
// Construction
public:
	MODIFISINGER(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(MODIFISINGER)
	enum { IDD = IDD_MODIFISINGER };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(MODIFISINGER)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(MODIFISINGER)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MODIFISINGER_H__C32D9115_F648_4D25_A9E6_6832614D1BF7__INCLUDED_)
