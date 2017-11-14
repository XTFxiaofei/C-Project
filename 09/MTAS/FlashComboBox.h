#if !defined(AFX_FLASHCOMBOBOX_H__CF7E8A1C_A8C9_4DEA_9600_BFD5A5489FE5__INCLUDED_)
#define AFX_FLASHCOMBOBOX_H__CF7E8A1C_A8C9_4DEA_9600_BFD5A5489FE5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FlashComboBox.h : header file
//

#include "./tools/comboboxxp.h"
/////////////////////////////////////////////////////////////////////////////
// CFlashComboBox window

class CFlashComboBox : public CComboBoxXP, public IUpdate
{
protected:
	CFont m_font;
// Construction
public:
	CFlashComboBox();

    LONG    m_lfHeight;
    LONG    m_lfWeight;
    CString m_strFaceName;

    BOOL CreateFont(LONG lfHeight, LONG lfWeight, LPCTSTR lpszFaceName);
	virtual void UpdateDisplay();
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFlashComboBox)
	//}}AFX_VIRTUAL

// Implementation
public:
	void UpdateContent();
	virtual ~CFlashComboBox();

	// Generated message map functions
protected:
	//{{AFX_MSG(CFlashComboBox)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSelchange();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FLASHCOMBOBOX_H__CF7E8A1C_A8C9_4DEA_9600_BFD5A5489FE5__INCLUDED_)
