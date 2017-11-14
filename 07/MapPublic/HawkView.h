//{{AFX_INCLUDES()
#include "map.h"
//}}AFX_INCLUDES
#if !defined(AFX_HAWKVIEW_H__403AF79F_E5F7_4F72_855E_6E1649616170__INCLUDED_)
#define AFX_HAWKVIEW_H__403AF79F_E5F7_4F72_855E_6E1649616170__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HawkView.h : header file
//

#include "momapLayer.h"
/////////////////////////////////////////////////////////////////////////////
// CHawkView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CHawkView : public CPropertyPage
{
protected:
         // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CHawkView)

// Form Data
public:
	CHawkView();  
	virtual ~CHawkView();
	//{{AFX_DATA(CHawkView)
	enum { IDD = IDD_HAWK_FORMVIEW };
	CMap1	m_HawkMap;
	//}}AFX_DATA

// Attributes
public:

	CString GetFileName(const CString &path);
	CString GetFileTitle(const CString &path);
	CString GetFileDirectory(const CString &path);
    CString CHawkView::AddShpLayer(const CString &VectorFileName,COLORREF color,short symbolSize,short symbolStyle,BOOL VisibleFlag,int index);
	
// Operations
public:
	CString sPath;
	

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHawkView)
	public:
	virtual BOOL OnInitDialog();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CHawkView)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnMouseDownMap1(short Button, short Shift, long X, long Y);
	afx_msg void OnAfterLayerDrawMap1(short index, BOOL canceled, long hDC);
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HAWKVIEW_H__403AF79F_E5F7_4F72_855E_6E1649616170__INCLUDED_)
