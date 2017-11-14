#if !defined(AFX_XSZHPC_H__30168576_1244_4FC4_85CB_B1674F448E9F__INCLUDED_)
#define AFX_XSZHPC_H__30168576_1244_4FC4_85CB_B1674F448E9F__INCLUDED_
#include "ADOConn.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// XSZHPC.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// XSZHPC dialog

class XSZHPC : public CDialog
{
// Construction
public:
	XSZHPC(CWnd* pParent = NULL);   // standard constructor
	CString temp,temp1;
	ADOConn myado;
	_RecordsetPtr m_pRc;
	int row;
// Dialog Data
	//{{AFX_DATA(XSZHPC)
	enum { IDD = IDD_XSZHPC };
	CComboBox	m_banji;
	CComboBox	m_xueyuan;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(XSZHPC)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(XSZHPC)
	virtual BOOL OnInitDialog();
	afx_msg void OnZhpcbt();
	afx_msg void OnSelchangeXueyuan();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XSZHPC_H__30168576_1244_4FC4_85CB_B1674F448E9F__INCLUDED_)
