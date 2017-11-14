#if !defined(AFX_MYGUIDETREE_H__D099DE85_2572_4338_89A2_5EB9A4A3A390__INCLUDED_)
#define AFX_MYGUIDETREE_H__D099DE85_2572_4338_89A2_5EB9A4A3A390__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyGuideTree.h : header file
//

#include "IUpdate.h"
/////////////////////////////////////////////////////////////////////////////
// CMyGuideTree window

#include "TreeCtrlMethod.h"
#include "VividTree.h"

class CMyGuideTree : public VividTree, public IUpdate
{
// Construction
public:
	CMyGuideTree();

// Attributes
public:
	TreeCtrlMethod		 m_method;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyGuideTree)
	//}}AFX_VIRTUAL

// Implementation
public:
	BOOL m_bRClick;
	CString m_strPathCurSel;
	virtual ~CMyGuideTree();
	//	IUpdate
	virtual void UpdateDisplay();

	virtual BOOL PreTranslateMessage( MSG* pMsg );
	// Generated message map functions
protected:
	CCourseWareInfo*	m_pCwi;
	CNewMenu	m_treeMenu;

	//{{AFX_MSG(CMyGuideTree)
	afx_msg void OnSelchangedTree(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRclickTree(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnAddClass();
	afx_msg void OnAddChapter();
	afx_msg void OnAddSection();
	afx_msg void OnAddCourseware();
	afx_msg void OnOpenCourseware();
	afx_msg void OnOpenCoursewareDir();
	afx_msg void OnDelCourseware();
	afx_msg void OnDelSection();
	afx_msg void OnDelChapter();
	afx_msg void OnDelClass();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnAddMultiCourseware();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYGUIDETREE_H__D099DE85_2572_4338_89A2_5EB9A4A3A390__INCLUDED_)
