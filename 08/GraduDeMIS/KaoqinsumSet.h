#if !defined(AFX_KAOQINSUMSET_H__F8242EFE_5E88_4770_B351_1481953B7F73__INCLUDED_)
#define AFX_KAOQINSUMSET_H__F8242EFE_5E88_4770_B351_1481953B7F73__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// KaoqinsumSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CKaoqinsumSet recordset

class CKaoqinsumSet : public CRecordset
{
public:
	CKaoqinsumSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CKaoqinsumSet)

// Field/Param Data
	//{{AFX_FIELD(CKaoqinsumSet, CRecordset)
	CString	m_stu_name;
	CString	m_stu_YDaoDays;
	CString	m_stu_attDays;
	CString	m_stu_holiDays;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKaoqinsumSet)
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

#endif // !defined(AFX_KAOQINSUMSET_H__F8242EFE_5E88_4770_B351_1481953B7F73__INCLUDED_)
