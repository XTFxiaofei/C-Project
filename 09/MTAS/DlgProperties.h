#if !defined(AFX_DLGPROPERTIES_H__954BD641_6BE0_48AD_AEF6_AADA1BBB4767__INCLUDED_)
#define AFX_DLGPROPERTIES_H__954BD641_6BE0_48AD_AEF6_AADA1BBB4767__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgProperties.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgProperties dialog

class CDlgProperties : public CNewDialog
{
// Construction
public:
	CDlgProperties(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgProperties)
	enum { IDD = IDD_PROPERTIES };
	CWinXPButtonST	m_btnCancel;
	CWinXPButtonST	m_btnOk;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgProperties)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

public:
	CString m_sLabel;
	CString m_sTooltip;
	CString m_sUrl;

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgProperties)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPROPERTIES_H__954BD641_6BE0_48AD_AEF6_AADA1BBB4767__INCLUDED_)
