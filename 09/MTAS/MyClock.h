#if !defined(AFX_MYCLOCK_H__75D18BE0_96D1_4C83_9522_B19558A44649__INCLUDED_)
#define AFX_MYCLOCK_H__75D18BE0_96D1_4C83_9522_B19558A44649__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyClock.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyClock window

class CMyClock : public CClockST
{
// Construction
public:
	CMyClock();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyClock)
	//}}AFX_VIRTUAL

// Implementation
public:
	CSize GetClockSize();
	virtual ~CMyClock();

	// Generated message map functions
protected:
	//{{AFX_MSG(CMyClock)
	afx_msg void OnClockClose();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYCLOCK_H__75D18BE0_96D1_4C83_9522_B19558A44649__INCLUDED_)
