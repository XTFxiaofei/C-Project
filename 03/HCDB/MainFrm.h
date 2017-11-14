// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__22A250A0_6BF3_4ED7_BAEF_5B1380B618AD__INCLUDED_)
#define AFX_MAINFRM_H__22A250A0_6BF3_4ED7_BAEF_5B1380B618AD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "MQQAppearanceDlg.h"
#include "AnotherView.h"

#include "ForeMange.h"

extern CString operid;
class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)
    CSplitterWnd m_wndSplitter;
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	protected:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	//}}AFX_VIRTUAL

// Implementation
public:
	int GetRecord(CString sqlstr);
	_RecordsetPtr m_record;
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnForemange();
	afx_msg void OnBackup();
	afx_msg void OnRestore();
	afx_msg void OnInStockmange();
	afx_msg void OnGetherOut();
	afx_msg void OnGetherIn();
	afx_msg void OnIndetail();
	afx_msg void OnInstockquery();
	afx_msg void OnOutStockmange();
	afx_msg void OnOutdetail();
	afx_msg void OnOutstockquery();
	afx_msg void OnMain();
	afx_msg void OnClose();
	afx_msg void OnSalesquit();
	afx_msg void OnUsermanage();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__22A250A0_6BF3_4ED7_BAEF_5B1380B618AD__INCLUDED_)
