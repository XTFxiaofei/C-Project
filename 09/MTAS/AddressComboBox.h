#if !defined(AFX_ADDRESSCOMBOBOX_H__51E56794_5185_48D1_9132_A8C3D24AFA24__INCLUDED_)
#define AFX_ADDRESSCOMBOBOX_H__51E56794_5185_48D1_9132_A8C3D24AFA24__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddressComboBox.h : header file
//

#include "./tools/comboboxxp.h"
/////////////////////////////////////////////////////////////////////////////
// CAddressComboBox window

class CAddressComboBox : public CComboBoxXP
{
protected:
	CFont m_font;

// Construction
public:
	CAddressComboBox();

    BOOL CreateFont(LONG lfHeight, LONG lfWeight, LPCTSTR lpszFaceName);

// Attributes
public:		
    LONG    m_lfHeight;
    LONG    m_lfWeight;
    CString m_strFaceName;
	CString m_strURL;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddressComboBox)
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CAddressComboBox();

	// Generated message map functions
protected:	
	//{{AFX_MSG(CAddressComboBox)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDRESSCOMBOBOX_H__51E56794_5185_48D1_9132_A8C3D24AFA24__INCLUDED_)
