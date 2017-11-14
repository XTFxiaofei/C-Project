#if !defined(AFX_HCHSET_H__2403312E_E5BA_4181_950E_15FB21C68876__INCLUDED_)
#define AFX_HCHSET_H__2403312E_E5BA_4181_950E_15FB21C68876__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HCHSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// HCHSet recordset

class HCHSet : public CRecordset
{
public:
	HCHSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(HCHSet)

// Field/Param Data
	//{{AFX_FIELD(HCHSet, CRecordset)
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(HCHSet)
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

#endif // !defined(AFX_HCHSET_H__2403312E_E5BA_4181_950E_15FB21C68876__INCLUDED_)
