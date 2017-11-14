#if !defined(AFX_EMPADDDLG_H__C9EB0A21_9318_45AF_A5C2_515585F9C8B8__INCLUDED_)
#define AFX_EMPADDDLG_H__C9EB0A21_9318_45AF_A5C2_515585F9C8B8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EmpAddDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEmpAddDlg dialog

class CEmpAddDlg : public CDialog
{
// Construction
public:
	CEmpAddDlg(CWnd* pParent = NULL);   // standard constructor
	HBITMAP	m_hBitmap;
	DWORD m_nFileLen;
	char *m_pBMPBuffer;
	_RecordsetPtr m_pRecordset,m_pRecordset1;
	HBITMAP	m_hPhotoBitmap;
// Dialog Data
	//{{AFX_DATA(CEmpAddDlg)
	enum { IDD = IDD_EMP_ADD_DLG };
	CComboBox	m_DepartCtrl;
	CComboBox	m_SexCtrl;
	CString	m_strName;
	int		m_nAge;
	CString	m_strAddr;
	CString	m_strPhone;
	CString	m_strMore;
	CTime	m_Birth;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEmpAddDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEmpAddDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnAdd();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EMPADDDLG_H__C9EB0A21_9318_45AF_A5C2_515585F9C8B8__INCLUDED_)
