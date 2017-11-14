#if !defined(AFX_STUACHIEVESET_H__83172A55_149D_4F5D_825D_B9CB615D05E6__INCLUDED_)
#define AFX_STUACHIEVESET_H__83172A55_149D_4F5D_825D_B9CB615D05E6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StuAchieveSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStuAchieveSet recordset

class CStuAchieveSet : public CRecordset
{
public:
	CStuAchieveSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CStuAchieveSet)

// Field/Param Data
	//{{AFX_FIELD(CStuAchieveSet, CRecordset)
	CString	m_stu_name;
	CString	m_forlanLevel;
	CString	m_comLevel;
	CString	m_schship;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStuAchieveSet)
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

#endif // !defined(AFX_STUACHIEVESET_H__83172A55_149D_4F5D_825D_B9CB615D05E6__INCLUDED_)
