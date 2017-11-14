// HMSysView.h : interface of the CHMSysView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HMSYSVIEW_H__BACD180B_6083_4653_8CEC_6F425EBB7ABB__INCLUDED_)
#define AFX_HMSYSVIEW_H__BACD180B_6083_4653_8CEC_6F425EBB7ABB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CHMSysView : public CView
{
protected: // create from serialization only
	CHMSysView();
	DECLARE_DYNCREATE(CHMSysView)

// Attributes
public:
	CHMSysDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHMSysView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHMSysView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHMSysView)
	afx_msg void OnUserManage();
	afx_msg void OnUpdatePwd();
	afx_msg void OnEmpAdd();
	afx_msg void OnDepartManage();
	afx_msg void OnEmpInfo();
	afx_msg void OnHolidatManage();
	afx_msg void OnCheckManage();
	afx_msg void OnCheckInfo();
	afx_msg void OnWageCal();
	afx_msg void OnWagemanage();
	afx_msg void OnWageTotal();
	afx_msg void OnRestore();
	afx_msg void OnBackup();
	afx_msg void OnWage();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in HMSysView.cpp
inline CHMSysDoc* CHMSysView::GetDocument()
   { return (CHMSysDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HMSYSVIEW_H__BACD180B_6083_4653_8CEC_6F425EBB7ABB__INCLUDED_)
