#if !defined(AFX_SPECIESSET_H__18B93B24_6F4B_4773_B2CC_5B4E84704474__INCLUDED_)
#define AFX_SPECIESSET_H__18B93B24_6F4B_4773_B2CC_5B4E84704474__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SpeciesSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSpeciesSet recordset

class CSpeciesSet : public CRecordset
{
public:
	CSpeciesSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CSpeciesSet)

// Field/Param Data
	//{{AFX_FIELD(CSpeciesSet, CRecordset)
	long	m_index;
	CString	m_ShpName;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpeciesSet)
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

#endif // !defined(AFX_SPECIESSET_H__18B93B24_6F4B_4773_B2CC_5B4E84704474__INCLUDED_)
