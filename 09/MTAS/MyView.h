#if !defined(AFX_MYVIEW_H__0A542EC9_5E5B_4CF5_8BEA_9469AB097F6D__INCLUDED_)
#define AFX_MYVIEW_H__0A542EC9_5E5B_4CF5_8BEA_9469AB097F6D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyView.h : header file
//

class CMTASCntrItem;

/////////////////////////////////////////////////////////////////////////////
// CMyView view

class CMyView : public CView
{
protected:
	CMyView();
	CMyView(BOOL bBlankPage);    // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CMyView)

private:
	CString m_strLabel;
	CWebBrowser2 m_wndWebBrowser;
	BOOL m_bBlankPage;
// Attributes
public:

// Operations
public:
	CString GetLabel() const;
	void SetLabel(const CString& strLabel);
	void SwitchToThisCntrItem();
	void AddNewCntrItemFromFile(const CString& strFilePath);

	CMTASCntrItem* m_pCntrItem;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CMyView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CMyView)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYVIEW_H__0A542EC9_5E5B_4CF5_8BEA_9469AB097F6D__INCLUDED_)
