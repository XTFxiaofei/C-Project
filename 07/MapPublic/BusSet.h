#if !defined(AFX_BUSSET_H__49C9FCE7_958A_47F8_862E_2FB8EB7F9946__INCLUDED_)
#define AFX_BUSSET_H__49C9FCE7_958A_47F8_862E_2FB8EB7F9946__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BusSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBusSet recordset

class CBusSet : public CRecordset
{
public:
	CBusSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CBusSet)

// Field/Param Data
	//{{AFX_FIELD(CBusSet, CRecordset)
	CString	m_ID_BUS;
	CString	m_BEGIN;
	CString	m_END;
	CString	m_AMTIME;
	CString	m_PMTIME;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBusSet)
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

#endif // !defined(AFX_BUSSET_H__49C9FCE7_958A_47F8_862E_2FB8EB7F9946__INCLUDED_)
