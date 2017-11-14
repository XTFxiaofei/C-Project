#if !defined(AFX_ROADVIEW_H__9238DDBF_4E12_4646_A3C7_595C6AD19830__INCLUDED_)
#define AFX_ROADVIEW_H__9238DDBF_4E12_4646_A3C7_595C6AD19830__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RoadView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRoadView dialog

class CRoadView : public CPropertyPage
{
	DECLARE_DYNCREATE(CRoadView)

// Construction
public:
	CRoadView();
	~CRoadView();

// Dialog Data
	//{{AFX_DATA(CRoadView)
	enum { IDD = IDD_ROADWAY };
	CString	m_id;
	CString	m_show;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CRoadView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CRoadView)
	afx_msg void OnButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROADVIEW_H__9238DDBF_4E12_4646_A3C7_595C6AD19830__INCLUDED_)
