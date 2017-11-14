#if !defined(AFX_TECRSUBSET_H__E448B3B0_80FD_4872_83FA_5196DDE20A85__INCLUDED_)
#define AFX_TECRSUBSET_H__E448B3B0_80FD_4872_83FA_5196DDE20A85__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TecrsubSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTecrsubSet recordset

class CTecrsubSet : public CRecordset
{
public:
	CTecrsubSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CTecrsubSet)

// Field/Param Data
	//{{AFX_FIELD(CTecrsubSet, CRecordset)
	CString	m_tecr_name;
	CString	m_sub_title;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTecrsubSet)
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

#endif // !defined(AFX_TECRSUBSET_H__E448B3B0_80FD_4872_83FA_5196DDE20A85__INCLUDED_)
