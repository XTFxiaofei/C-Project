#if !defined(AFX_SHIXISET_H__D98CCBC3_D343_447B_A794_4D33100DC385__INCLUDED_)
#define AFX_SHIXISET_H__D98CCBC3_D343_447B_A794_4D33100DC385__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ShixiSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CShixiSet recordset

class CShixiSet : public CRecordset
{
public:
	CShixiSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CShixiSet)

// Field/Param Data
	//{{AFX_FIELD(CShixiSet, CRecordset)
	CString	m_stu_name;
	BOOL	m_shixi_bSubmit;
	CString	m_shixi_Behave;
	BOOL	m_shixi_bRelate;
	CString	m_shixi_Result;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShixiSet)
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

#endif // !defined(AFX_SHIXISET_H__D98CCBC3_D343_447B_A794_4D33100DC385__INCLUDED_)
