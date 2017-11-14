#if !defined(AFX_MQQAPPEARANCEDLG_H__AB37A9B8_0E4B_487F_8904_0E473E1B9FE9__INCLUDED_)
#define AFX_MQQAPPEARANCEDLG_H__AB37A9B8_0E4B_487F_8904_0E473E1B9FE9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MQQAppearanceDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMQQAppearanceDlg form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif
#include "GfxOutBarCtrl.h"
class CMQQAppearanceDlg : public CFormView
{
protected:
	CMQQAppearanceDlg();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CMQQAppearanceDlg)
    CGfxOutBarCtrl	wndBar;
	CImageList		imaLarge, imaSmall;
// Form Data
public:
	//{{AFX_DATA(CMQQAppearanceDlg)
	enum { IDD = IDD_MQQAPPEARANCE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMQQAppearanceDlg)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CMQQAppearanceDlg();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CMQQAppearanceDlg)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MQQAPPEARANCEDLG_H__AB37A9B8_0E4B_487F_8904_0E473E1B9FE9__INCLUDED_)
