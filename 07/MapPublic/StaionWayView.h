#if !defined(AFX_STAIONWAYVIEW_H__A5C52ACD_6417_4422_B06B_8FD0F826CBBA__INCLUDED_)
#define AFX_STAIONWAYVIEW_H__A5C52ACD_6417_4422_B06B_8FD0F826CBBA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StaionWayView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStaionWayView dialog

class CStaionWayView : public CPropertyPage
{
	DECLARE_DYNCREATE(CStaionWayView)

// Construction
public:
	CStaionWayView();
	~CStaionWayView();

// Dialog Data
	//{{AFX_DATA(CStaionWayView)
	enum { IDD = IDD_STAION };
	CListCtrl	m_list;
	CString	m_station;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CStaionWayView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CStaionWayView)
	virtual BOOL OnInitDialog();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STAIONWAYVIEW_H__A5C52ACD_6417_4422_B06B_8FD0F826CBBA__INCLUDED_)
