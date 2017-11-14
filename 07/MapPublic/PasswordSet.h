#if !defined(AFX_PASSWORDSET_H__675A7288_3161_41F6_B7DE_461B18C11E35__INCLUDED_)
#define AFX_PASSWORDSET_H__675A7288_3161_41F6_B7DE_461B18C11E35__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PasswordSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPasswordSet recordset

class CPasswordSet : public CRecordset
{
public:
	CPasswordSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CPasswordSet)

// Field/Param Data
	//{{AFX_FIELD(CPasswordSet, CRecordset)
	CString	m_USER_ID;
	CString	m_USER_PASSWORD;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPasswordSet)
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

#endif // !defined(AFX_PASSWORDSET_H__675A7288_3161_41F6_B7DE_461B18C11E35__INCLUDED_)
