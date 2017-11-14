#if !defined(AFX_DCLRSUBSTATUSDLG_H__AEC684A2_FCF3_4697_B014_B04F8791BACB__INCLUDED_)
#define AFX_DCLRSUBSTATUSDLG_H__AEC684A2_FCF3_4697_B014_B04F8791BACB__INCLUDED_
#include "DclrsubSet.h"
#include "TecrsubSet.h"
#include "ChoiceSubSet.h"
#include "StuAchieveSet.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DclrsubStatusDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDclrsubStatusDlg dialog

class CDclrsubStatusDlg : public CDialog
{
// Construction
public:
	CDclrsubStatusDlg(CWnd* pParent = NULL);   // standard constructor
    CDclrsubSet pDclrsubSet;				//定义记录集对象
	CTecrsubSet pTecrsubSet;
    CChoiceSubSet pstusubSet;
    CStuAchieveSet pstuAchvSet;
    struct ACHIEVE							//定义结构
	{
		CString forlanLevel;
		CString comLevel;
		CString schship;
	};

// Dialog Data
	//{{AFX_DATA(CDclrsubStatusDlg)
	enum { IDD = IDD_DclrSubStatus_DLG };
	CListBox	m_ctrlStuName;
	CListCtrl	m_ctrlOwnsub;
	CString	m_strDclrmax;
	CString	m_strDclrnum;
	CString	m_strComlevel;
	CString	m_strForlanlevel;
	CString	m_strSchship;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDclrsubStatusDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDclrsubStatusDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSeeSubChoiedBTN();
	afx_msg void OnDclrSubBTN();
	afx_msg void OnClickOwnsubLIST(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnItemchangingOwnsubLIST(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRclickOwnsubLIST(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkChoisubStuLIST();
	afx_msg void OnSelchangeChoisubStuLIST();
	afx_msg void OnChoiStuBTN();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DCLRSUBSTATUSDLG_H__AEC684A2_FCF3_4697_B014_B04F8791BACB__INCLUDED_)
