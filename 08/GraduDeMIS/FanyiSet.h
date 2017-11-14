#if !defined(AFX_FANYISET_H__9C6F11AF_F8AE_40FB_B07F_22E1589FF9E1__INCLUDED_)
#define AFX_FANYISET_H__9C6F11AF_F8AE_40FB_B07F_22E1589FF9E1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FanyiSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFanyiSet recordset

class CFanyiSet : public CRecordset
{
public:
	CFanyiSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CFanyiSet)

// Field/Param Data
	//{{AFX_FIELD(CFanyiSet, CRecordset)
	CString	m_stu_name;
	BOOL	m_fanyi_bSubmit;
	CString	m_fanyi_Quality;
	BOOL	m_fanyi_bNum;
	BOOL	m_fanyi_bRelate;
	CString	m_fanyi_Result;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFanyiSet)
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

#endif // !defined(AFX_FANYISET_H__9C6F11AF_F8AE_40FB_B07F_22E1589FF9E1__INCLUDED_)
