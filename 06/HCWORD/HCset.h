#if !defined(AFX_HCSET_H__391DD704_2716_42AC_BBB5_9C6E39BAE7B3__INCLUDED_)
#define AFX_HCSET_H__391DD704_2716_42AC_BBB5_9C6E39BAE7B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HCset.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// HCset recordset

class HCset : public CRecordset
{
public:
	HCset(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(HCset)

// Field/Param Data
	//{{AFX_FIELD(HCset, CRecordset)
	CString	m_eg;
	CString	m_zw;
	CString	m_vi;
	CString	m_vt;
	CString	m_n;
	CString	m_adj;
	CString	m_adv;
	CString	m_riqi;
	long	m_id;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(HCset)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HCSET_H__391DD704_2716_42AC_BBB5_9C6E39BAE7B3__INCLUDED_)
