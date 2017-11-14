#if !defined(AFX_DELROADWAY_H__7BB6A064_CE0E_4C72_9CCF_3F31076B1929__INCLUDED_)
#define AFX_DELROADWAY_H__7BB6A064_CE0E_4C72_9CCF_3F31076B1929__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DelRoadway.h : header file
//
#include "XPButton.h"
/////////////////////////////////////////////////////////////////////////////
// DelRoadway dialog

class DelRoadway : public CDialog
{
// Construction
public:
	DelRoadway(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DelRoadway)
	enum { IDD = IDD_DEL_ROADWAY };
	CXPButton	m_cancel;
	CXPButton	m_del;
	CListCtrl	m_list;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DelRoadway)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DelRoadway)
	virtual BOOL OnInitDialog();
	afx_msg void OnDel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DELROADWAY_H__7BB6A064_CE0E_4C72_9CCF_3F31076B1929__INCLUDED_)
