#if !defined(AFX_TEACHERSET_H__FBC3F141_AEE1_48CD_851E_904AFF85253F__INCLUDED_)
#define AFX_TEACHERSET_H__FBC3F141_AEE1_48CD_851E_904AFF85253F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TeacherSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTeacherSet recordset

class CTeacherSet : public CRecordset
{
public:
	CTeacherSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CTeacherSet)

// Field/Param Data
	//{{AFX_FIELD(CTeacherSet, CRecordset)
	CString	m_tecr_age;
	CString	m_tecr_asoci;
	CString	m_tecr_id;
	CString	m_tecr_level;
	CString	m_tecr_name;
	CString	m_tecr_sex;
	CString	m_tecr_TRroom;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTeacherSet)
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

#endif // !defined(AFX_TEACHERSET_H__FBC3F141_AEE1_48CD_851E_904AFF85253F__INCLUDED_)
