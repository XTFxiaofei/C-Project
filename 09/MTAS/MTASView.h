// MTASView.h : interface of the CMTASView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MTASVIEW_H__3D7510FE_909C_4F68_8A0C_23436549D2E0__INCLUDED_)
#define AFX_MTASVIEW_H__3D7510FE_909C_4F68_8A0C_23436549D2E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMTASDoc;

class CMTASView : public CHtmlView
{
public: // create from serialization only
	CMTASView();
	DECLARE_DYNCREATE(CMTASView)

// Attributes
public:
	CMTASDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMTASView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMTASView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

public:
	CString m_sLabel;
	CString m_sTooltip;
	CString m_sUrl;
private:
	afx_msg LRESULT OnMyInitialUpdate(WPARAM wParam, LPARAM lParam);

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMTASView)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MTASView.cpp
inline CMTASDoc* CMTASView::GetDocument()
   { return (CMTASDoc*)m_pDocument; }
#endif




/*
class CMFCBindView : public CView
{
protected: // create from serialization only
	CMFCBindView();
	DECLARE_DYNCREATE(CMFCBindView)

// Attributes
public:
	CMFCBindDoc* GetDocument();
	// m_pSelection holds the selection to the current CMFCBindCntrItem.
	// For many applications, such a member variable isn't adequate to
	//  represent a selection, such as a multiple selection or a selection
	//  of objects that are not CMFCBindCntrItem objects.  This selection
	//  mechanism is provided just to help you get started.

	// TODO: replace this selection mechanism with one appropriate to your app.
	CMFCBindCntrItem* m_pSelection;
	void OnInitialUpdate();
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCBindView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL IsSelected(const CObject* pDocItem) const;// Container support
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMFCBindView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFCBindView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	afx_msg void OnDestroy();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnInsertObject();
	afx_msg void OnCancelEditCntr();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in BindView.cpp
inline CMFCBindDoc* CMFCBindView::GetDocument()
   { return (CMFCBindDoc*)m_pDocument; }
#endif
*/
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MTASVIEW_H__3D7510FE_909C_4F68_8A0C_23436549D2E0__INCLUDED_)
