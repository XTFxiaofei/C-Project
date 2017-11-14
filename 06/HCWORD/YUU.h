#if !defined(AFX_YUU_H__29344170_45A1_4180_BC51_FAED982B1787__INCLUDED_)
#define AFX_YUU_H__29344170_45A1_4180_BC51_FAED982B1787__INCLUDED_
#include "ZLSet.h"
#include "MyTreeCtrl.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// YUU.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// YUU dialog

class YUU : public CDialog
{
// Construction
public:
	YUU(CWnd* pParent = NULL);   // standard constructor
   // void CreateTree();
    CDatabase *pdb;
    ZLSet * m_pset;
// Dialog Data
	//{{AFX_DATA(YUU)
	enum { IDD = IDD_DIALOG3 };
	CListCtrl	m_list;
	CTreeCtrl	m_tree;
	//}}AFX_DATA

  	CImageList m_theImageList;//树形控件图像列表
	HTREEITEM activeItem;//活动子项
	HTREEITEM activeparentItem;//活动父项
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(YUU)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
    CPoint m_point;
	int m_nWidth,m_nHeight;
	int m_nDx,m_nDy;
	int m_nDx1,m_nDy1;

	// Generated message map functions
	//{{AFX_MSG(YUU)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangedTree1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_YUU_H__29344170_45A1_4180_BC51_FAED982B1787__INCLUDED_)
