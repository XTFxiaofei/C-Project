#if !defined(AFX_TREEGUIDEBAR_H__E4BEB513_311D_4663_935E_B657F90BD50C__INCLUDED_)
#define AFX_TREEGUIDEBAR_H__E4BEB513_311D_4663_935E_B657F90BD50C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TreeGuideBar.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTreeGuideBar window
#ifndef baseCTreeGuideBar
#define baseCTreeGuideBar CSizingControlBarCF
#endif

class CTreeGuideBar : public baseCTreeGuideBar
{
// Construction
public:
	CTreeGuideBar();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTreeGuideBar)
	//}}AFX_VIRTUAL

// Implementation
public:
	CMyGuideTree* GetTree();
	virtual ~CTreeGuideBar();

	// Generated message map functions
private:
	CMyGuideTree::BkMode m_background_mode;
	CMyGuideTree         m_tree;
	HICON		         m_icon;
protected:
	//{{AFX_MSG(CTreeGuideBar)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void NcCalcClient(LPRECT pRc, UINT nDockBarID);
	afx_msg void NcPaintGripper(CDC* pDC, CRect rcClient);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TREEGUIDEBAR_H__E4BEB513_311D_4663_935E_B657F90BD50C__INCLUDED_)
