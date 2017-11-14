#if !defined(AFX_ADDDLG_H__0BDE94EE_292E_4E3D_BADE_35BA3F8EE0A4__INCLUDED_)
#define AFX_ADDDLG_H__0BDE94EE_292E_4E3D_BADE_35BA3F8EE0A4__INCLUDED_
#include "HCset.h"
#include "ZLSet.h"
#include "SIJI.h"
#include "REMDlg.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ADDdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ADDdlg dialog
//CString extern logFileName;
class ADDdlg : public CDialog
{
// Construction
public:
	ADDdlg(CWnd* pParent = NULL);   // standard constructor
    void ShowData();                //自定义函数
	void show();
	CDatabase *pdb;                 //定义访问数据库指针            
	CString str;
	CString strsql,tablename,columnname1,columnname2,word,mean;                 //定义字符串变量
	int selectrow;
	//{{AFX_DATA(ADDdlg)
	enum { IDD = IDD_DIALOG1 };
	CListCtrl	m_list;
	CComboBox	m_combo;
	CListBox	m_list3;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ADDdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ADDdlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnItemchangedList3(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButton1();
	afx_msg void OnAdd();
	afx_msg void OnDelete();
	afx_msg void OnModify();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDDLG_H__0BDE94EE_292E_4E3D_BADE_35BA3F8EE0A4__INCLUDED_)
