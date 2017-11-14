// HCCPDlg.h : header file
//

#if !defined(AFX_HCCPDLG_H__DE5C34A2_C014_4216_B2B3_FD886F60C870__INCLUDED_)
#define AFX_HCCPDLG_H__DE5C34A2_C014_4216_B2B3_FD886F60C870__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Hutext.h"
#include "ADOConn.h"
#include "XSCJXG.h"
#include "XSCJCX.h"
#include "XSCJPX.h"
#include "XKXFXG.h"
#include "XSZHPC.h"

#include "MyTree.h"
/////////////////////////////////////////////////////////////////////////////
// CHCCPDlg dialog

class CHCCPDlg : public CDialog
{
// Construction
public:
	CHCCPDlg(CWnd* pParent = NULL);	// standard constructor
	ADOConn m_AdoConn;
	void CreateTree();
	CImageList m_TreeBootImage;
	void InitTab();
	void ShowDlg();
	void ShowList(CString cnamedd);
	void Select(CString ming,HTREEITEM root,_RecordsetPtr m_pRs);
	int showdlgnum;
	_RecordsetPtr m_pRs1,m_pRs2,m_pRs3;
	_bstr_t vSQL,vSQL1,vSQL2;
	_variant_t name;
	HTREEITEM leaf,leaf1,leaf2;
	CString str;
	XSCJXG modifydlg;XSCJCX finddlg;XSCJPX sortdlg;
	CDialog* pdlg[5];
	XKXFXG xkxgdlg;
	
	XSZHPC zhcpdlg;
	COLORREF color;int i,j,k;
// Dialog Data
	//{{AFX_DATA(CHCCPDlg)
	enum { IDD = IDD_HCCP_DIALOG };
	CListCtrl	m_list1;
	CTabCtrl	m_tab;
	MyTree	m_tree;
	CString	m_text;
	Hutext	m_textctrl;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHCCPDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CHCCPDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelchangedTree1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HCCPDLG_H__DE5C34A2_C014_4216_B2B3_FD886F60C870__INCLUDED_)
