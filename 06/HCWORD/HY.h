#if !defined(AFX_HY_H__87CEC157_A9C1_4C99_84C4_DD79D68419A9__INCLUDED_)
#define AFX_HY_H__87CEC157_A9C1_4C99_84C4_DD79D68419A9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HY.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// HY recordset

class HY : public CRecordset
{
public:
	HY(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(HY)

// Field/Param Data
	//{{AFX_FIELD(HY, CRecordset)
	CString	m_eg;
	CString	m_jsh;
	long	m_mosh;
	CString	m_riqi;
	CString	m_yinbiao;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(HY)
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

#endif // !defined(AFX_HY_H__87CEC157_A9C1_4C99_84C4_DD79D68419A9__INCLUDED_)
