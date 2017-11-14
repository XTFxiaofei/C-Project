#if !defined(AFX_PASSWORDSET_H__E2F3F079_61DE_4E52_AE70_ABCD0635F640__INCLUDED_)
#define AFX_PASSWORDSET_H__E2F3F079_61DE_4E52_AE70_ABCD0635F640__INCLUDED_

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
	CString	m_lgn_user;
	CString	m_lgn_passwd;
	BOOL	m_lgn_isAdmin;
	CString	m_user_type;
	CString	m_user_unit;
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

#endif // !defined(AFX_PASSWORDSET_H__E2F3F079_61DE_4E52_AE70_ABCD0635F640__INCLUDED_)
