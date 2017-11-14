#if !defined(AFX_ADDONEROADWAY_H__80282D92_589B_4401_BD41_EBC3D2F8E428__INCLUDED_)
#define AFX_ADDONEROADWAY_H__80282D92_589B_4401_BD41_EBC3D2F8E428__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddOneRoadway.h : header file
//
#include "XPButton.h"
/////////////////////////////////////////////////////////////////////////////
// AddOneRoadway dialog

class AddOneRoadway : public CDialog
{
// Construction
public:
	AddOneRoadway(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(AddOneRoadway)
	enum { IDD = IDD_ADD_ROADWAY };
	CXPButton	m_quit;
	CXPButton	m_ok;
	CString	m_roadway;
	CString	m_sendtime;
	CString	m_startstation;
	CString	m_station;
	CString	m_stoptime;
	CString	m_endstation;
	//}}AFX_DATA
    bool addroadflag;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(AddOneRoadway)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
	public:
		bool firstflag;
		bool stationflag;
// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(AddOneRoadway)
	afx_msg void OnOk();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDONEROADWAY_H__80282D92_589B_4401_BD41_EBC3D2F8E428__INCLUDED_)
