// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__17B0F4AD_153F_437E_9761_1ADA4E696982__INCLUDED_)
#define AFX_MAINFRM_H__17B0F4AD_153F_437E_9761_1ADA4E696982__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "GuideBar.h"
#include "FlashToolBar.h"
#include "NavigateToolBar.h"
#include "AddressStatic.h"
#include "cwtoolbar.h"
#include "tools/StatusBarXP.h"
#include "Persist.h"
#include "ClockDlg.h"
#include "TreeGuideBar.h"

class CMainFrame : public CPersistentFrame
{
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:
	CCreateContext m_ccx;
	CNavigateToolBar	m_wndNavigateToolBar;
	CFlashToolBar	    m_wndFlashToolBar;
	CCWToolBar			m_wndCWToolBar;
	CFlashComboBox	    m_wndFlashComboBox;
	CAddressStatic		m_wndAddressText;

	CClockDlg	m_wndClock;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	//}}AFX_VIRTUAL
	
// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

public:  // control bar embedded members
	CStatusBarXP	m_wndStatusBar;
	CNewToolBar		m_wndToolBar;
	CGuideBar		m_wndGuideBar;
	CTreeGuideBar	m_wndTreeGuideBar;

	CImageList	  m_imgList;

// Generated message map functions
protected:
	void SetViewProperty();
	BOOL AddCourseWarePage();
	BOOL AddBlankPage();
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnViewCoursewareGuide();
	afx_msg void OnUpdateViewCoursewareGuide(CCmdUI* pCmdUI);
	afx_msg void OnViewCoursewarePreview();
	afx_msg void OnUpdateViewCoursewarePreview(CCmdUI* pCmdUI);
	afx_msg void OnViewToolbarFlash();
	afx_msg void OnUpdateViewToolbarFlash(CCmdUI* pCmdUI);
	afx_msg void OnViewToolbarGuide();
	afx_msg void OnUpdateViewToolbarGuide(CCmdUI* pCmdUI);
	afx_msg void OnOpenMycomputer();
	afx_msg void OnOpenMydocument();
	afx_msg void OnViewCoursewareAssort();
	afx_msg void OnUpdateViewCoursewareAssort(CCmdUI* pCmdUI);
	afx_msg void OnViewClock();	
	afx_msg void OnUpdateViewClock(CCmdUI* pCmdUI);
	afx_msg void OnUpdateOpenMycomputer(CCmdUI* pCmdUI);
	afx_msg void OnUpdateOpenMydocument(CCmdUI* pCmdUI);
	afx_msg void OnViewToolbarCourseware();
	afx_msg void OnUpdateViewToolbarCourseware(CCmdUI* pCmdUI);
	afx_msg void OnPageAddBlank();
	afx_msg void OnPageCloseCurrent();
	afx_msg void OnUpdatePageAddBlank(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePageCloseCurrent(CCmdUI* pCmdUI);
	afx_msg void OnPageFirst();
	afx_msg void OnUpdatePageFirst(CCmdUI* pCmdUI);
	afx_msg void OnPageLast();
	afx_msg void OnUpdatePageLast(CCmdUI* pCmdUI);
	afx_msg void OnPagePrevious();
	afx_msg void OnUpdatePagePrevious(CCmdUI* pCmdUI);
	afx_msg void OnPageNext();
	afx_msg void OnUpdatePageNext(CCmdUI* pCmdUI);
	afx_msg void OnPageProperty();
	afx_msg void OnUpdatePageProperty(CCmdUI* pCmdUI);
	//}}AFX_MSG
	afx_msg void OnRclickTabctrl(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClickTabctrl(NMHDR* pNMHDR, LRESULT* pResult);
	DECLARE_MESSAGE_MAP()
	DECLARE_PINDOCK()

public:
	BOOL IsFullScreen() const;
	void NormalScreen();
	void FullScreen();
	BOOL CreateClockWnd();
	BOOL CreateMenuBar();

private:
	BOOL CreateTreeGuideBar();
	BOOL CreateCourseWareToolBar();
	BOOL CreateNavigateToolBar();
	BOOL CreateFlashToolBar();
	void InitMenu();
	BOOL CreateCustomTabCtrl();
	BOOL CreateGuideBar();

private:   
	CRect  m_rtMainWnd;
	CRect  m_rtDesktop;
	BOOL   m_bFullScreen;   //	full screen flag
	BOOL   m_bVisibleStatusBar;
	BOOL   m_bVisibleTreeGuideBar;
	BOOL   m_bVisibleGuideBar;
	BOOL   m_bVisibleCWToolBar;
	BOOL   m_bVisibleNavigateToolBar;
	BOOL   m_bVisibleClock;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__17B0F4AD_153F_437E_9761_1ADA4E696982__INCLUDED_)
