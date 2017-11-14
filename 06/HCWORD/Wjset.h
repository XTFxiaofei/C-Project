#if !defined(AFX_WJSET_H__8E1C1E4A_E69E_4DA8_A69C_D52566F5831F__INCLUDED_)
#define AFX_WJSET_H__8E1C1E4A_E69E_4DA8_A69C_D52566F5831F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Wjset.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Wjset recordset

class Wjset : public CRecordset
{
public:
	Wjset(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(Wjset)

// Field/Param Data
	//{{AFX_FIELD(Wjset, CRecordset)
	long	m_id;
	CString	m_danci;
	CString	m_jieshi;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Wjset)
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

#endif // !defined(AFX_WJSET_H__8E1C1E4A_E69E_4DA8_A69C_D52566F5831F__INCLUDED_)
