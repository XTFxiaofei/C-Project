#if !defined(AFX_KAOQINSET_H__69F89484_6CEB_46FC_8CD5_63683EA04B75__INCLUDED_)
#define AFX_KAOQINSET_H__69F89484_6CEB_46FC_8CD5_63683EA04B75__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// KaoqinSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CKaoqinSet recordset

class CKaoqinSet : public CRecordset
{
public:
	CKaoqinSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CKaoqinSet)

// Field/Param Data
	//{{AFX_FIELD(CKaoqinSet, CRecordset)
	CString	m_stu_name;
	CString	m_stu_ChuQinTime;
	BOOL	m_stu_ChuQinStatus;
	CString	m_stu_UnAtedReason;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKaoqinSet)
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

#endif // !defined(AFX_KAOQINSET_H__69F89484_6CEB_46FC_8CD5_63683EA04B75__INCLUDED_)
