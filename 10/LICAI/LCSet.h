#if !defined(AFX_LCSET_H__347C8D82_1D29_4B18_943B_BB2352946A88__INCLUDED_)
#define AFX_LCSET_H__347C8D82_1D29_4B18_943B_BB2352946A88__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LCSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// LCSet recordset

class LCSet : public CRecordset
{
public:
	LCSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(LCSet)

// Field/Param Data
	//{{AFX_FIELD(LCSet, CRecordset)
	CString	m_about;
	long	m_costnum;
	CString	m_costtype;
	long	m_id;
	long	m_incomenum;
	CString	m_incometype;
	CString	m_time;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(LCSet)
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

#endif // !defined(AFX_LCSET_H__347C8D82_1D29_4B18_943B_BB2352946A88__INCLUDED_)
