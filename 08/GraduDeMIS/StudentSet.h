#if !defined(AFX_STUDENTSET_H__86EB5643_6E81_46B6_BE3C_CE3C24A9693E__INCLUDED_)
#define AFX_STUDENTSET_H__86EB5643_6E81_46B6_BE3C_CE3C24A9693E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StudentSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStudentSet recordset

class CStudentSet : public CRecordset
{
public:
	CStudentSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CStudentSet)

// Field/Param Data
	//{{AFX_FIELD(CStudentSet, CRecordset)
	CString	m_stu_id;
	CString	m_stu_name;
	CString	m_stu_sex;
	CString	m_stu_class;
	CString	m_stu_age;
	CString	m_stu_depart;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStudentSet)
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

#endif // !defined(AFX_STUDENTSET_H__86EB5643_6E81_46B6_BE3C_CE3C24A9693E__INCLUDED_)
