// DllTestView.h : interface of the CDllTestView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DLLTESTVIEW_H__B72F398B_38CA_4C7B_84BC_2DB1580478B4__INCLUDED_)
#define AFX_DLLTESTVIEW_H__B72F398B_38CA_4C7B_84BC_2DB1580478B4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDllTestView : public CView
{
protected: // create from serialization only
	CDllTestView();
	DECLARE_DYNCREATE(CDllTestView)

// Attributes
public:
	CDllTestDoc* GetDocument();

// Operations
public:
	CWnd		m_wndTest;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDllTestView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDllTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDllTestView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DllTestView.cpp
inline CDllTestDoc* CDllTestView::GetDocument()
   { return (CDllTestDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLLTESTVIEW_H__B72F398B_38CA_4C7B_84BC_2DB1580478B4__INCLUDED_)
