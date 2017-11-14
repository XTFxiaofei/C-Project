// TBManagerView.h : interface of the CTBManagerView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TBMANAGERVIEW_H__65319CAB_4CE1_4B13_BA76_FFB8A2A42570__INCLUDED_)
#define AFX_TBMANAGERVIEW_H__65319CAB_4CE1_4B13_BA76_FFB8A2A42570__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTBManagerView : public CView
{
protected: // create from serialization only
	CTBManagerView();
	DECLARE_DYNCREATE(CTBManagerView)

// Attributes
public:
	CTBManagerDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTBManagerView)
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
	virtual ~CTBManagerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTBManagerView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TBManagerView.cpp
inline CTBManagerDoc* CTBManagerView::GetDocument()
   { return (CTBManagerDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TBMANAGERVIEW_H__65319CAB_4CE1_4B13_BA76_FFB8A2A42570__INCLUDED_)
