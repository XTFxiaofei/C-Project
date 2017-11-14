#if !defined(AFX_MAPCONTROLVIEW_H__7AB4419F_A159_4EF8_A10E_E484D9C18D16__INCLUDED_)
#define AFX_MAPCONTROLVIEW_H__7AB4419F_A159_4EF8_A10E_E484D9C18D16__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MapControlView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMapControlView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

#include "TransView.h"
#include "StaionWayView.h"
#include "RoadView.h"
class CMapControlView : public CFormView
{
protected:
	CMapControlView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CMapControlView)

// Form Data
public:
	//{{AFX_DATA(CMapControlView)
	enum { IDD = IDD_MAPCONTROL_FORMVIEW };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	CRoadView m_RoadWay;
	CStaionWayView m_Staion;
    CTransView m_Transfer;
    CPropertySheet m_Sheet;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMapControlView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CMapControlView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CMapControlView)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAPCONTROLVIEW_H__7AB4419F_A159_4EF8_A10E_E484D9C18D16__INCLUDED_)
