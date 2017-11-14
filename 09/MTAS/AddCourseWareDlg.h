#if !defined(AFX_ADDCOURSEWAREDLG_H__DAC2EBBD_F632_46BD_BD14_F4F6BB1EE429__INCLUDED_)
#define AFX_ADDCOURSEWAREDLG_H__DAC2EBBD_F632_46BD_BD14_F4F6BB1EE429__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddCourseWareDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAddCourseWareDlg dialog

class CAddCourseWareDlg : public CDialog
{
// Construction
public:
	CCourseWareInfo GetCourseWare() const;
	CAddCourseWareDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAddCourseWareDlg)
	enum { IDD = IDD_ADD_CWI_DIALOG };
	CWinXPButtonST	m_btnCancel;
	CWinXPButtonST	m_btnAdd;
	CWinXPButtonST	m_btnBrowse;
	CComboBoxXP	m_cbSection;
	CComboBoxXP	m_cbChapter;
	CComboBoxXP	m_cbClass;
	CString	m_strName;
	CString	m_strPath;
	CString	m_strType;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddCourseWareDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddCourseWareDlg)
	afx_msg void OnBrowse();
	virtual void OnCancel();
	afx_msg void OnAdd();
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeComboClass();
	afx_msg void OnSelchangeComboChapter();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CCourseWareInfo m_cwi;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDCOURSEWAREDLG_H__DAC2EBBD_F632_46BD_BD14_F4F6BB1EE429__INCLUDED_)
