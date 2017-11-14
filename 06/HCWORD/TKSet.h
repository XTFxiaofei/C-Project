#if !defined(AFX_TKSET_H__EFFAFEFE_C36C_458F_BD9A_736FD937B95B__INCLUDED_)
#define AFX_TKSET_H__EFFAFEFE_C36C_458F_BD9A_736FD937B95B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TKSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// TKSet recordset

class TKSet : public CRecordset
{
public:
	TKSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(TKSet)

// Field/Param Data
	//{{AFX_FIELD(TKSet, CRecordset)
	long	m_id;
	CString	m_xuanx1;
	CString	m_xuanx2;
	CString	m_xuanx3;
	CString	m_xuanx4;
	CString	m_tm;
    CString	m_da;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(TKSet)
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

#endif // !defined(AFX_TKSET_H__EFFAFEFE_C36C_458F_BD9A_736FD937B95B__INCLUDED_)
