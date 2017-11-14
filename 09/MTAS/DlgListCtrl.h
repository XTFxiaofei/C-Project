#if !defined(AFX_DLGLISTCTRL_H__0C00D191_4F36_428D_A9BA_DFCE1A6EC430__INCLUDED_)
#define AFX_DLGLISTCTRL_H__0C00D191_4F36_428D_A9BA_DFCE1A6EC430__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgListCtrl.h : header file
//

#include "MyListCtrl.h"
#include <vector>

/////////////////////////////////////////////////////////////////////////////
// CDlgListCtrl window

class CDlgListCtrl : public CMyListCtrl
{
// Construction
public:
	CDlgListCtrl();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgListCtrl)
	//}}AFX_VIRTUAL

// Implementation
public:
	void FillListCtrl(std::vector<CCourseWareInfo>& vecCwi);
	void InitListCtrl();
	virtual ~CDlgListCtrl();
	virtual void UpdateDisplay();

	// Generated message map functions
protected:
	void DeleteFromList(int nItemDeleted);

	//{{AFX_MSG(CDlgListCtrl)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnColumnclick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

public:
	std::vector<CCourseWareInfo> m_vecCwi;
private:
	void MergeVector(std::vector<CCourseWareInfo>& vec1, std::vector<CCourseWareInfo>& vec2);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGLISTCTRL_H__0C00D191_4F36_428D_A9BA_DFCE1A6EC430__INCLUDED_)
