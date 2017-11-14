#if !defined(AFX_KAITISET_H__AC749652_8AD8_4816_A77D_B80107530271__INCLUDED_)
#define AFX_KAITISET_H__AC749652_8AD8_4816_A77D_B80107530271__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// KaitiSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CKaitiSet recordset

class CKaitiSet : public CRecordset
{
public:
	CKaitiSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CKaitiSet)

// Field/Param Data
	//{{AFX_FIELD(CKaitiSet, CRecordset)
	CString	m_stu_name;
	BOOL	m_kaiti_bSubmit;
	CString	m_kaiti_Understand;
	BOOL	m_kaiti_bPlan;
	BOOL	m_kaiti_bBaseCndi;
	CString	m_kaiti_ColiResult;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKaitiSet)
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

#endif // !defined(AFX_KAITISET_H__AC749652_8AD8_4816_A77D_B80107530271__INCLUDED_)
