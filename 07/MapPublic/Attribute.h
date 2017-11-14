#if !defined(AFX_ATTRIBUTE_H__6A5BFCD0_3A3E_4923_8D11_88808B977501__INCLUDED_)
#define AFX_ATTRIBUTE_H__6A5BFCD0_3A3E_4923_8D11_88808B977501__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Attribute.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAttribute form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CAttribute : public CFormView
{
protected:
	
	DECLARE_DYNCREATE(CAttribute)

// Form Data
public:
	CAttribute();           // protected constructor used by dynamic creation
		virtual ~CAttribute();
	//{{AFX_DATA(CAttribute)
	enum { IDD = IDD_ATTRIBUTE_FORMVIEW };
	CString	m_strAttribute;
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAttribute)
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
	//{{AFX_MSG(CAttribute)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ATTRIBUTE_H__6A5BFCD0_3A3E_4923_8D11_88808B977501__INCLUDED_)
