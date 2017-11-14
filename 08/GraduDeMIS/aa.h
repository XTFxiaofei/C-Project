#if !defined(AFX_AA_H__A3FD1181_1365_4CFC_8147_1B5040CC16A6__INCLUDED_)
#define AFX_AA_H__A3FD1181_1365_4CFC_8147_1B5040CC16A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// aa.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// aa DAO recordset

class aa : public CDaoRecordset
{
public:
	aa(CDaoDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(aa)

// Field/Param Data
	//{{AFX_FIELD(aa, CDaoRecordset)
	//}}AFX_FIELD

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(aa)
	public:
	virtual CString GetDefaultDBName();		// Default database name
	virtual CString GetDefaultSQL();		// Default SQL for Recordset
	virtual void DoFieldExchange(CDaoFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AA_H__A3FD1181_1365_4CFC_8147_1B5040CC16A6__INCLUDED_)
