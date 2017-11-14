#if !defined(AFX_JIEGUO_H__070567C0_578B_4D9F_B825_CDBF2A7C976C__INCLUDED_)
#define AFX_JIEGUO_H__070567C0_578B_4D9F_B825_CDBF2A7C976C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// JIEGUO.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// JIEGUO dialog

class JIEGUO : public CDialog
{
// Construction
public:
	JIEGUO(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(JIEGUO)
	enum { IDD = IDD_DIALOG1 };
	CStatic	m_tiaomu;
	CListCtrl	m_list2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(JIEGUO)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(JIEGUO)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JIEGUO_H__070567C0_578B_4D9F_B825_CDBF2A7C976C__INCLUDED_)
