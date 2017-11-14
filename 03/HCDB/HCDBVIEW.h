// HCDBView.h : interface of the CHCDBView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HCDBVIEW_H__5C18A4A7_93A1_48A2_A822_633D052BA299__INCLUDED_)
#define AFX_HCDBVIEW_H__5C18A4A7_93A1_48A2_A822_633D052BA299__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CHCDBView : public CView
{
protected: // create from serialization only
	CHCDBView();
	DECLARE_DYNCREATE(CHCDBView)

// Attributes
public:
	CHCDBDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHCDBView)
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
	virtual ~CHCDBView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHCDBView)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in HCDBView.cpp
inline CHCDBDoc* CHCDBView::GetDocument()
   { return (CHCDBDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HCDBVIEW_H__5C18A4A7_93A1_48A2_A822_633D052BA299__INCLUDED_)
