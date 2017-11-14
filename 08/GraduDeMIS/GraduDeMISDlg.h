// GraduDeMISDlg.h : header file
//

#if !defined(AFX_GRADUDEMISDLG_H__1BF1B959_EF40_4E73_BF9C_E1DD6A9B330A__INCLUDED_)
#define AFX_GRADUDEMISDLG_H__1BF1B959_EF40_4E73_BF9C_E1DD6A9B330A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGraduDeMISDlg dialog

class CGraduDeMISDlg : public CDialog
{
// Construction
public:
	CGraduDeMISDlg(CWnd* pParent = NULL);	// standard constructor
//	CSubjectSet pSet;
// Dialog Data
	bool flag;
	//{{AFX_DATA(CGraduDeMISDlg)
	enum { IDD = IDD_GRADUDEMIS_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGraduDeMISDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGraduDeMISDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStuDialog();
	afx_msg void OnLoginDlg();
	afx_msg void OnExitSys();
	afx_msg void OnSysLgnDLG();
	afx_msg void OnUserGL();
	afx_msg void OnChoisublistDLG();
	afx_msg void OnMENUITEMUserHelp();
	afx_msg void OnAnswZigeChekDLG();
	afx_msg void OnMENUITEMDBCopy();
	afx_msg void OnMENUITEMDBRestore();
	afx_msg void OnMENUITEMDocChek();
	afx_msg void OnChoiStatusDLG();
	afx_msg void OnUpdateStuDialog(CCmdUI* pCmdUI);
	afx_msg void OnSubFORMVIEW();
	afx_msg void OnDclrSubStatusDLG();
	afx_msg void OnClose();
	afx_msg void OnDabianFenzuDLG();
	afx_msg void OnTeacherDialog();
	afx_msg void OnSubjectDLG();
	afx_msg void OnUpdateChoiStatusShowDLG(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDclrSubStatusDLG(CCmdUI* pCmdUI);
	afx_msg void OnUpdateMENUITEMDocChek(CCmdUI* pCmdUI);
	afx_msg void OnUpdateMENUITEMDBCopy(CCmdUI* pCmdUI);
	afx_msg void OnUpdateMENUITEMDBRestore(CCmdUI* pCmdUI);
	afx_msg void OnUpdateUserGL(CCmdUI* pCmdUI);
	afx_msg void OnKaoqinDLG();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRADUDEMISDLG_H__1BF1B959_EF40_4E73_BF9C_E1DD6A9B330A__INCLUDED_)
