#if !defined(AFX_PWSET_H__E5943B87_9886_4D72_89AE_B60CD1804A24__INCLUDED_)
#define AFX_PWSET_H__E5943B87_9886_4D72_89AE_B60CD1804A24__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PWSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PWSet recordset

class PWSet : public CRecordset
{
public:
	PWSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(PWSet)

// Field/Param Data
	//{{AFX_FIELD(PWSet, CRecordset)
	CString	m_PASSWORD;
	CString	m_ID;
	CString	m_AUTHOR;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PWSet)
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

#endif // !defined(AFX_PWSET_H__E5943B87_9886_4D72_89AE_B60CD1804A24__INCLUDED_)
