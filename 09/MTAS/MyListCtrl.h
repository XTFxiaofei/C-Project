#if !defined(AFX_MYLISTCTRL_H__A18C1033_7057_442D_80B1_157032E6BC49__INCLUDED_)
#define AFX_MYLISTCTRL_H__A18C1033_7057_442D_80B1_157032E6BC49__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyListCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyListCtrl window
#include "IUpdate.h"

class CMyListCtrl : public CListCtrl, public IUpdate
{
// Construction
public:
	CMyListCtrl();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyListCtrl)
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	void InitListCtrl(const CString& strSQL);
	virtual ~CMyListCtrl();

	// Generated message map functions
public:
	void OpenCourseware();
	void OpenCoursewareDir();
	void DeleteCourseware();
	void AddMutiCourseware();
	void AddCourseware();
	CImageList m_imglist;
	BOOL	m_bAsc;
	CString m_strLastClick;
	CNewMenu	m_listMenu;

	void FillCourseWareInfo(CCourseWareInfo &cwi, int nItem);
	virtual void FillListCtrl(const CString &strSQL, const CString& strSort = _T(""));
	//{{AFX_MSG(CMyListCtrl)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnCustomdrawList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnColumnclick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRclick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnItemchanged(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYLISTCTRL_H__A18C1033_7057_442D_80B1_157032E6BC49__INCLUDED_)
