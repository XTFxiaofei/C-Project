#if !defined(AFX_TECRDCLRSUBDLG_H__EF947861_8566_4239_81BB_A00A3AFE8EC6__INCLUDED_)
#define AFX_TECRDCLRSUBDLG_H__EF947861_8566_4239_81BB_A00A3AFE8EC6__INCLUDED_
#include "SubjectSet.h"
#include "TeacherSet.h"

#include "ChoiceSubSet.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TecrDclrSubDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTecrDclrSubDlg dialog

class CTecrDclrSubDlg : public CDialog
{
// Construction
public:
	CTecrDclrSubDlg(CWnd* pParent = NULL);   // standard constructor
    CSubjectSet psubSet;
	CTeacherSet ptecrSet;
    CChoiceSubSet  pchoisubSet;
// Dialog Data
	//{{AFX_DATA(CTecrDclrSubDlg)
	enum { IDD = IDD_Tecr_DclrSubDlg };
	CComboBox	m_SubTypeCtrl;
	CString	m_SubDemandVal;
	CString	m_SubProVal;
	CString	m_SubTitleVal;
	CString	m_TecrAsociVal;
	CString	m_strSubType;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTecrDclrSubDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTecrDclrSubDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TECRDCLRSUBDLG_H__EF947861_8566_4239_81BB_A00A3AFE8EC6__INCLUDED_)
