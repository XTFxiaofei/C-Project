#if !defined(AFX_DABIANFENZUSET_H__8C7E469D_5A3A_4930_89D6_3ECCE0366736__INCLUDED_)
#define AFX_DABIANFENZUSET_H__8C7E469D_5A3A_4930_89D6_3ECCE0366736__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DabianfenzuSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDabianfenzuSet recordset

class CDabianfenzuSet : public CRecordset
{
public:
	CDabianfenzuSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CDabianfenzuSet)

// Field/Param Data
	//{{AFX_FIELD(CDabianfenzuSet, CRecordset)
	CString	m_stu_name;
	CString	m_dabian_unit;
	CString	m_keti_type;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDabianfenzuSet)
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

#endif // !defined(AFX_DABIANFENZUSET_H__8C7E469D_5A3A_4930_89D6_3ECCE0366736__INCLUDED_)
