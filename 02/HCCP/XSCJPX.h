#if !defined(AFX_XSCJPX_H__E7E8F4D6_1284_433C_909E_62D1FD072F9E__INCLUDED_)
#define AFX_XSCJPX_H__E7E8F4D6_1284_433C_909E_62D1FD072F9E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// XSCJPX.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// XSCJPX dialog

class XSCJPX : public CDialog
{
// Construction
public:
	XSCJPX(CWnd* pParent = NULL);   // standard constructor
	CString temp;
// Dialog Data
	//{{AFX_DATA(XSCJPX)
	enum { IDD = IDD_XSCJPX };
	CComboBox	m_yiju;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(XSCJPX)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(XSCJPX)
	virtual BOOL OnInitDialog();
	afx_msg void OnSort();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XSCJPX_H__E7E8F4D6_1284_433C_909E_62D1FD072F9E__INCLUDED_)
