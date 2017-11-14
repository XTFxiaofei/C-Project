#if !defined(AFX_SIMPLESPLASHWND_H__7220C1D9_DBC7_4D02_A9D5_3488CF5E7425__INCLUDED_)
#define AFX_SIMPLESPLASHWND_H__7220C1D9_DBC7_4D02_A9D5_3488CF5E7425__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SimpleSplashWnd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSimpleSplashWnd window

class CSimpleSplashWnd : public CWnd
{
private:
	CBitmap m_bitmap;
	CSize	m_sizeBitmap;
	CString m_sStatusText;

// Construction
public:
	CSimpleSplashWnd();
	CSimpleSplashWnd(CWnd * pWndParent, UINT nBitmapID);

// Attributes
public:

// Operations
public:
	bool Create(CWnd* pWndParent, UINT nBitmapID);
	void SetStatusText(LPCTSTR sStatusText);

	static bool RegisterSplashWndClass();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSimpleSplashWnd)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSimpleSplashWnd();

	// Generated message map functions
protected:
	//{{AFX_MSG(CSimpleSplashWnd)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaint();
	afx_msg void OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS FAR* lpncsp);
	afx_msg UINT OnNcHitTest(CPoint point);
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
}; // class CSimpleSplashWnd

#define MTAS_SPLASHWND_WNDCLASS _T("MTASSplashWnd")


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIMPLESPLASHWND_H__7220C1D9_DBC7_4D02_A9D5_3488CF5E7425__INCLUDED_)
