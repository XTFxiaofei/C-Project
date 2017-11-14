#if !defined(AFX_SUBOPERPROPAGE_H__D486E106_5D6F_4ED2_8389_8819E94A1E12__INCLUDED_)
#define AFX_SUBOPERPROPAGE_H__D486E106_5D6F_4ED2_8389_8819E94A1E12__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SubOperProPage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSubOperProPage dialog

class CSubOperProPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CSubOperProPage)

// Construction
public:
	CSubOperProPage();
	~CSubOperProPage();

// Dialog Data
	//{{AFX_DATA(CSubOperProPage)
	enum { IDD = IDD_SubOper_DLG };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CSubOperProPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CSubOperProPage)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUBOPERPROPAGE_H__D486E106_5D6F_4ED2_8389_8819E94A1E12__INCLUDED_)
