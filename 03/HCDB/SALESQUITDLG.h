#if !defined(AFX_SALESQUITDLG_H__36EE594D_0E34_4970_926A_4889229AA777__INCLUDED_)
#define AFX_SALESQUITDLG_H__36EE594D_0E34_4970_926A_4889229AA777__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SALESQUITDLG.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSALESQUITDLG dialog

class CSALESQUITDLG : public CDialog
{
// Construction
public:
	void Update(CString sqlstr);
	void UpdateRecord(CString sqlstr,CString);
	int GetRecord1(CString sqlstr);
	int m_index;
	int m_index3;
	void SetEditValues();
	void SetList2Values(CString sqlstr);
	void SetList3Values(CString sqlstr);
	void SetList1Values(CString sqlstr);
	int GetRecord(CString sqlstr);
	void SetListStyle();
	CSALESQUITDLG(CWnd* pParent = NULL);   // standard constructor
    _RecordsetPtr m_record;
// Dialog Data
	//{{AFX_DATA(CSALESQUITDLG)
	enum { IDD = IDD_SALESQUIT };
	CEdit	m_quit;
	CListCtrl	m_list3;
	CListCtrl	m_list2;
	CListCtrl	m_list1;
	CString	m_operid;
	CString	m_info;
	CString	m_buyid;
	CString	m_mercid;
	float	m_quitnum;
	double	m_backmoney;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSALESQUITDLG)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSALESQUITDLG)
	virtual BOOL OnInitDialog();
	afx_msg void OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void Onfind();
	afx_msg void OnInvalidate();
	afx_msg void OnItemchangedList2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnTsprd();
	afx_msg void OnTspcd();
	afx_msg void OnItemchangedList3(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnOk();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SALESQUITDLG_H__36EE594D_0E34_4970_926A_4889229AA777__INCLUDED_)
