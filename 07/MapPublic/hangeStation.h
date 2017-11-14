#if !defined(AFX_HANGESTATION_H__AE319BAA_0F7D_4901_A814_22F2A0B9A9B0__INCLUDED_)
#define AFX_HANGESTATION_H__AE319BAA_0F7D_4901_A814_22F2A0B9A9B0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// hangeStation.h : header file
//
#include "XPButton.h"
#include "newListCtrl.h"
/////////////////////////////////////////////////////////////////////////////
// ChangeStation dialog

class ChangeStation : public CDialog
{
// Construction
public:
	ChangeStation(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ChangeStation)
	enum { IDD = IDD_CHANGE_STATION };
	CXPButton	m_ok;
	CXPButton	m_change_station;
	CnewListCtrl	m_list;
	CComboBox	m_roadway;
	//}}AFX_DATA

CEdit m_edit;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ChangeStation)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ChangeStation)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnChangeStation();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HANGESTATION_H__AE319BAA_0F7D_4901_A814_22F2A0B9A9B0__INCLUDED_)
