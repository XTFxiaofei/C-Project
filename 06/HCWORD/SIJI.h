#if !defined(AFX_SIJI_H__8EAC46EA_98B4_45E8_82E0_C518F74BA116__INCLUDED_)
#define AFX_SIJI_H__8EAC46EA_98B4_45E8_82E0_C518F74BA116__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SIJI.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// SIJI recordset

class SIJI : public CRecordset
{
public:
	SIJI(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(SIJI)

// Field/Param Data
	//{{AFX_FIELD(SIJI, CRecordset)
	CString	m_si1;
	CString	m_si2;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SIJI)
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

#endif // !defined(AFX_SIJI_H__8EAC46EA_98B4_45E8_82E0_C518F74BA116__INCLUDED_)
