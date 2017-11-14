#if !defined(AFX_GUIDEBAR_H__8954CB54_6FCC_4906_B4EE_0E38029166E0__INCLUDED_)
#define AFX_GUIDEBAR_H__8954CB54_6FCC_4906_B4EE_0E38029166E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GuideBar.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGuideBar window

#ifndef baseCGuideBar
#define baseCGuideBar CPinDockBar
#endif

class CGuideBar : public baseCGuideBar
{
// Construction
public:
	CGuideBar();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGuideBar)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CGuideBar();
	virtual void AddToDrawBar(CAutoHideBar * pDrawBar);
	virtual void RemoveFromDrawBar(CAutoHideBar * pDrawBar);

	// Generated message map functions
protected:
	OutlookTabCtrlEx m_OutlookTabCtrlEx;
public:
	CPptListCtrl   m_listPpt;
	CFlashListCtrl m_listFlash;
	CWordListCtrl  m_listWord;

protected:
	//{{AFX_MSG(CGuideBar)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL CreateListCtrls();
	BOOL CreateImageLists();
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GUIDEBAR_H__8954CB54_6FCC_4906_B4EE_0E38029166E0__INCLUDED_)
