#if !defined(AFX_FLASHVIEW_H__DDD160AF_F550_4DBA_808D_E4026DBE55C1__INCLUDED_)
#define AFX_FLASHVIEW_H__DDD160AF_F550_4DBA_808D_E4026DBE55C1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FlashView.h : header file
//

#include "shockwaveflash.h"
#include "MyView.h"
#include "FlashToolBar.h"

/////////////////////////////////////////////////////////////////////////////
// CFlashView view

class CFlashView : public CMyView
{
public:
	CFlashView(BOOL bBlankPage = FALSE);
	DECLARE_DYNCREATE(CFlashView)

// Attributes
public:
	CShockwaveFlash m_flashWnd;
	BOOL m_bLoad;
// Operations
public:
	void Stop();
	void Pause();
	void Play();
	void LoadMovie(const CString& strPath);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFlashView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CFlashView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CFlashView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FLASHVIEW_H__DDD160AF_F550_4DBA_808D_E4026DBE55C1__INCLUDED_)
