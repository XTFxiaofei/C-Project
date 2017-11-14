#if !defined(AFX_MYCANSHOWEDIT_H__EB7B6FDA_A98B_43C4_9A15_D7433D9984BB__INCLUDED_)
#define AFX_MYCANSHOWEDIT_H__EB7B6FDA_A98B_43C4_9A15_D7433D9984BB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyCanShowEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyCanShowEdit window

class CMyCanShowEdit : public CEdit
{
// Construction
public:
	CMyCanShowEdit();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyCanShowEdit)
	//}}AFX_VIRTUAL

// Implementation
public:
	void JustiyProvid();
	void GetMercName();
	bool Connect();
	_RecordsetPtr m_record;
	_ConnectionPtr m_connection;
	
	virtual ~CMyCanShowEdit();

	// Generated message map functions
protected:
	//{{AFX_MSG(CMyCanShowEdit)
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYCANSHOWEDIT_H__EB7B6FDA_A98B_43C4_9A15_D7433D9984BB__INCLUDED_)
