#if !defined(AFX_ANOTHERVIEW_H__737771F5_CE34_4896_8EE2_A31C700D344F__INCLUDED_)
#define AFX_ANOTHERVIEW_H__737771F5_CE34_4896_8EE2_A31C700D344F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AnotherView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAnotherView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif
#include "GATHERIN.h"
#include "GATHEROUT.h"
#include "INDETAIL.h"
#include "OUTDETAIL.h"
#include "INSTOCKMANGE.h"
#include "OUTSTOCKMANGE.h"
#include "INSTOCKQUERY.h"
#include "OUTSTOCKQUERY.h"
#include "BMP.h"
class CAnotherView : public CFormView
{
protected:
	CAnotherView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CAnotherView)

// Form Data
public:
	//{{AFX_DATA(CAnotherView)
	enum { IDD = IDD_FORMVIEW1 };
	CTabCtrl	m_Tab;
	//}}AFX_DATA
    TCITEM item;
// Attributes
public:
    CGATHERIN cgatherin;
	CGATHEROUT cgatherout;
	CINDETAIL cindetail;
	COUTDETAIL coutdetail;
	CINSTOCKMANGE cinstockmange;
    COUTSTOCKMANGE coutstockmange;
    CINSTOCKQUERY cinstockquery;
	COUTSTOCKQUERY coutstockquery;
	CBMP cbmp;
	CRect DlgRect,PageRect,NewRect;
	int nFramewidth,nTitHeight;
// Operations
public:
	void CreateWindows();
	bool gatherinflag;
	bool gatheroutflag;
	bool indetailflag;
	bool outdetailflag;
	bool instockmanageflag;
	bool outstockmanageflag;
	bool instockqueryflag;
	bool outstockqueryflag;

	void ClickTab(bool showflag);
	void ShowBmo(bool showflag);
	void ShowGatherin(bool showflag);
	void ShowGatherOut(bool showflag);
	void ShowIndetail(bool showflag);
	void ShowOutdetail(bool showflag);
	void ShowInStockMange(bool showflag);
	void ShowOutStockMange(bool showflag);
	void ShowInStockQuery(bool showflag);
	void ShowOutStockquery(bool showflag);
	
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAnotherView)
	public:
	virtual void OnInitialUpdate();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CAnotherView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CAnotherView)
	afx_msg void OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANOTHERVIEW_H__737771F5_CE34_4896_8EE2_A31C700D344F__INCLUDED_)
