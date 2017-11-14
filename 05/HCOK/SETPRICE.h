#if !defined(AFX_SETPRICE_H__16CB1E26_52AD_45C4_8043_7276A2D9493A__INCLUDED_)
#define AFX_SETPRICE_H__16CB1E26_52AD_45C4_8043_7276A2D9493A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SETPRICE.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// SETPRICE dialog

class SETPRICE : public CDialog
{
// Construction
public:
	SETPRICE(CWnd* pParent = NULL);   // standard constructor
void ShowroomtDate();
void ShowabatetDate() ;
// Dialog Data
	//{{AFX_DATA(SETPRICE)
	enum { IDD = IDD_SETPRICE };
	CListCtrl	m_list2;
	CListCtrl	m_list1;
	CComboBox	m_combo2;
	CComboBox	m_combo1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SETPRICE)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(SETPRICE)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnSetroom();
	afx_msg void OnSetabate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETPRICE_H__16CB1E26_52AD_45C4_8043_7276A2D9493A__INCLUDED_)
