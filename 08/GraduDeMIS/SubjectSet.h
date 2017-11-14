#if !defined(AFX_SUBJECTSET_H__5559A2A0_F638_4FA6_A434_6DE9998432A0__INCLUDED_)
#define AFX_SUBJECTSET_H__5559A2A0_F638_4FA6_A434_6DE9998432A0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SubjectSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSubjectSet recordset

class CSubjectSet : public CRecordset
{
public:
	CSubjectSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CSubjectSet)

// Field/Param Data
	//{{AFX_FIELD(CSubjectSet, CRecordset)
	CString	m_sub_title;
	CString	m_sub_type;
	CString	m_sub_pro;
	CString	m_sub_demand;
	CString	m_tecr_name;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSubjectSet)
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

#endif // !defined(AFX_SUBJECTSET_H__5559A2A0_F638_4FA6_A434_6DE9998432A0__INCLUDED_)
