#if !defined(AFX_EMPUPDATEDLG_H__D0EBD591_0FDE_4BE6_805A_5C4BFEA9CA45__INCLUDED_)
#define AFX_EMPUPDATEDLG_H__D0EBD591_0FDE_4BE6_805A_5C4BFEA9CA45__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EmpUpdateDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEmpUpdateDlg dialog

class CEmpUpdateDlg : public CDialog
{
// Construction
public:
	CEmpUpdateDlg(CWnd* pParent = NULL);   // standard constructor
	_RecordsetPtr	m_pRecordset;
	HBITMAP			m_hPhotoBitmap;		//位图句柄
	void			ReadData();
	DWORD			m_nFileLen;
	HBITMAP			BufferToHBITMAP();
	BOOL			LoadBMPFile(const char* pBMPPathname);
	char			*m_pBMPBuffer;		//内存数据
	void			DestroyPhoto();
	void			ShowPhoto(int x,int y,CDC* pDC);
	void			Selectphoto();
// Dialog Data
	//{{AFX_DATA(CEmpUpdateDlg)
	enum { IDD = IDD_EMP_UPDATE_DLG };
	CComboBox	m_DepartCrtl;
	CComboBox	m_SexCrtl;
	CString	m_strAddr;
	int		m_nAge;
	CString	m_strMore;
	CString	m_strName;
	CString	m_strPhone;
	CTime	m_Birth;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEmpUpdateDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEmpUpdateDlg)
	afx_msg void OnUpdate();
	virtual BOOL OnInitDialog();
	afx_msg void OnExit();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EMPUPDATEDLG_H__D0EBD591_0FDE_4BE6_805A_5C4BFEA9CA45__INCLUDED_)
