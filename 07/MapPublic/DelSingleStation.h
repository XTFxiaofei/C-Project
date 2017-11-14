#if !defined(AFX_DELSINGLESTATION_H__828B81D8_80EC_4E7D_87FE_48FC12401414__INCLUDED_)
#define AFX_DELSINGLESTATION_H__828B81D8_80EC_4E7D_87FE_48FC12401414__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DelSingleStation.h : header file
//
#include "XPButton.h"
/////////////////////////////////////////////////////////////////////////////
// DelSingleStation dialog

class DelSingleStation : public CDialog
{
// Construction
public:
	DelSingleStation(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DelSingleStation)
	enum { IDD = IDD_DELSINGLESTATION };
	CXPButton	m_ok;
	CXPButton	m_del;
	CListCtrl	m_list;
	CComboBox	m_roadway;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DelSingleStation)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
public:
	CString m_str;
	void Refresh();

protected:

	// Generated message map functions
	//{{AFX_MSG(DelSingleStation)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeRoadway();
	afx_msg void OnDel();
	afx_msg void OnItemchangingList2(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DELSINGLESTATION_H__828B81D8_80EC_4E7D_87FE_48FC12401414__INCLUDED_)
