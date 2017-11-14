#if !defined(AFX_TECRINFODLG_H__36E8A578_5A64_4829_9F3D_706092C7B7CB__INCLUDED_)
#define AFX_TECRINFODLG_H__36E8A578_5A64_4829_9F3D_706092C7B7CB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TecrInfoDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTecrInfoDlg dialog

class CTecrInfoDlg : public CDialog
{
// Construction
public:
	CTecrInfoDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTecrInfoDlg)
	enum { IDD = IDD_TecrInfo_DLG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTecrInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTecrInfoDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TECRINFODLG_H__36E8A578_5A64_4829_9F3D_706092C7B7CB__INCLUDED_)
