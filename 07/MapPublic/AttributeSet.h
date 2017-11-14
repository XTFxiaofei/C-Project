#if !defined(AFX_ATTRIBUTESET_H__FD023DD9_8FF7_471E_BD90_04111D2F4CB7__INCLUDED_)
#define AFX_ATTRIBUTESET_H__FD023DD9_8FF7_471E_BD90_04111D2F4CB7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AttributeSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAttributeSet recordset

class CAttributeSet : public CRecordset
{
public:
	CAttributeSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CAttributeSet)

// Field/Param Data
	//{{AFX_FIELD(CAttributeSet, CRecordset)
	CString	m_ATTRIBUTE;
	int		m_ISPICTURE;
	CString	m_NAME;
	CString	m_PICTURE_NAME;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAttributeSet)
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

#endif // !defined(AFX_ATTRIBUTESET_H__FD023DD9_8FF7_471E_BD90_04111D2F4CB7__INCLUDED_)
