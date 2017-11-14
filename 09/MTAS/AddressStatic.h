#if !defined(AFX_ADDRESSSTATIC_H__8C8AA0D1_A991_40E0_BCEC_D8C5FD1F1B15__INCLUDED_)
#define AFX_ADDRESSSTATIC_H__8C8AA0D1_A991_40E0_BCEC_D8C5FD1F1B15__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddressStatic.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAddressStatic window

class CAddressStatic : public CStatic
{
protected:
	CFont m_font;

// Construction
public:
	CAddressStatic();

// Attributes
public:
    LONG    m_lfHeight;
    LONG    m_lfWeight;
    CString m_strFaceName;

// Operations
public:
	BOOL CreateFont(LONG lfHeight, LONG lfWeight, LPCTSTR lpszFaceName);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddressStatic)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CAddressStatic();

	// Generated message map functions
protected:
	//{{AFX_MSG(CAddressStatic)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDRESSSTATIC_H__8C8AA0D1_A991_40E0_BCEC_D8C5FD1F1B15__INCLUDED_)
