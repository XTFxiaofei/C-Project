#if !defined(AFX_DCLRSUBSET_H__189362C1_2AAE_437B_9AB0_1D896AA0409D__INCLUDED_)
#define AFX_DCLRSUBSET_H__189362C1_2AAE_437B_9AB0_1D896AA0409D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DclrsubSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDclrsubSet recordset

class CDclrsubSet : public CRecordset
{
public:
	CDclrsubSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CDclrsubSet)

// Field/Param Data
	//{{AFX_FIELD(CDclrsubSet, CRecordset)
	CString	m_tecr_name;
	CString	m_tecr_MaxNum;
	CString	m_tecr_DclrNum;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDclrsubSet)
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

#endif // !defined(AFX_DCLRSUBSET_H__189362C1_2AAE_437B_9AB0_1D896AA0409D__INCLUDED_)
