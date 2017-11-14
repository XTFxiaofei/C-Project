#if !defined(AFX_THESISGROUPDLG_H__6B072A3A_CA43_4ACF_9C8A_7CE4274F98A1__INCLUDED_)
#define AFX_THESISGROUPDLG_H__6B072A3A_CA43_4ACF_9C8A_7CE4274F98A1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ThesisGroupDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CThesisGroupDlg dialog

class CThesisGroupDlg : public CDialog
{
// Construction
public:
	CThesisGroupDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CThesisGroupDlg)
	enum { IDD = IDD_ThesisGroup_DLG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThesisGroupDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CThesisGroupDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THESISGROUPDLG_H__6B072A3A_CA43_4ACF_9C8A_7CE4274F98A1__INCLUDED_)
