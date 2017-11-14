#if !defined(AFX_ACTION_TIME_SET_H__9B52B86F_CDCA_4166_89A7_C265FE63F2B2__INCLUDED_)
#define AFX_ACTION_TIME_SET_H__9B52B86F_CDCA_4166_89A7_C265FE63F2B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Action_Time_Set.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAction_Time_Set recordset

class CAction_Time_Set : public CRecordset
{
public:
	CAction_Time_Set(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CAction_Time_Set)

// Field/Param Data
	//{{AFX_FIELD(CAction_Time_Set, CRecordset)
	CString	m_USER_ID;
	CString	m_ACTION;
	CString	m_COME_LEAVE_TIME;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAction_Time_Set)
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

#endif // !defined(AFX_ACTION_TIME_SET_H__9B52B86F_CDCA_4166_89A7_C265FE63F2B2__INCLUDED_)
