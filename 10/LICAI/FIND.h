#if !defined(AFX_FIND_H__65872C02_845E_4AD2_AAFE_5784C085137E__INCLUDED_)
#define AFX_FIND_H__65872C02_845E_4AD2_AAFE_5784C085137E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FIND.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// FIND dialog

class FIND : public CDialog
{
// Construction
public:
	FIND(CWnd* pParent = NULL);   // standard constructor
	CString year,month,day,time;
	bool timeflag,yearflag,monthflag;//timeflag用来判断是按年月查找还是年月日查找，yearflag判断是否是按年份查找
// Dialog Data
	//{{AFX_DATA(FIND)
	enum { IDD = IDD_FIND };
	CButton	m_foryear;
	CComboBox	m_day;
	CComboBox	m_month;
	CComboBox	m_year;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(FIND)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(FIND)
	virtual BOOL OnInitDialog();
	afx_msg void GetSelTime(UINT nID);
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FIND_H__65872C02_845E_4AD2_AAFE_5784C085137E__INCLUDED_)
