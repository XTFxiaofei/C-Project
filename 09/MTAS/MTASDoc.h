// MTASDoc.h : interface of the CMTASDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MTASDOC_H__DE01E853_CF7F_43F2_AFBB_62463382B61A__INCLUDED_)
#define AFX_MTASDOC_H__DE01E853_CF7F_43F2_AFBB_62463382B61A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMTASView;
class CShockwaveFlash;

class CMTASDoc : public COleDocument
{
protected: // create from serialization only
	CMTASDoc();
	DECLARE_DYNCREATE(CMTASDoc)

// Attributes
public:
	CStringArray	  m_aStrings;
	CShockwaveFlash*  m_pFlashCtrl;
	BOOL			  m_bListSelected;
	CListCtrl*		  m_pListCtrlSelected;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMTASDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual void OnCloseDocument();
	//}}AFX_VIRTUAL

// Implementation
public:
	CCourseWareInfo m_cwiCurSel;
	virtual ~CMTASDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMTASDoc)
	afx_msg void OnPlayFlash();
	afx_msg void OnUpdatePlayFlash(CCmdUI* pCmdUI);
	afx_msg void OnPauseFlash();
	afx_msg void OnUpdatePauseFlash(CCmdUI* pCmdUI);
	afx_msg void OnStopFlash();
	afx_msg void OnUpdateStopFlash(CCmdUI* pCmdUI);
	afx_msg void OnFullScreen();
	afx_msg void OnUpdateFullScreen(CCmdUI* pCmdUI);
	afx_msg void OnNormalScreen();
	afx_msg void OnUpdateNormalScreen(CCmdUI* pCmdUI);
	afx_msg void OnNavigateForward();
	afx_msg void OnUpdateNavigateForward(CCmdUI* pCmdUI);
	afx_msg void OnNavigateBackward();
	afx_msg void OnUpdateNavigateBackward(CCmdUI* pCmdUI);
	afx_msg void OnNavigateStop();
	afx_msg void OnUpdateNavigateStop(CCmdUI* pCmdUI);
	afx_msg void OnNavigateRefresh();
	afx_msg void OnUpdateNavigateRefresh(CCmdUI* pCmdUI);
	afx_msg void OnNavigateGoto();
	afx_msg void OnOpenCw();
	afx_msg void OnAddCw();
	afx_msg void OnDelCw();
	afx_msg void OnOpenCwDir();
	afx_msg void OnFileOpen();
	afx_msg void OnUpdateDelCw(CCmdUI* pCmdUI);
	afx_msg void OnUpdateOpenCwDir(CCmdUI* pCmdUI);
	afx_msg void OnAddMultiCw();
	afx_msg void OnCourseAddChapter();
	afx_msg void OnCourseAddSection();
	afx_msg void OnCourseAddClass();
	afx_msg void OnViewToolbarCourseware();
	afx_msg void OnUpdateViewToolbarCourseware(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MTASDOC_H__DE01E853_CF7F_43F2_AFBB_62463382B61A__INCLUDED_)
