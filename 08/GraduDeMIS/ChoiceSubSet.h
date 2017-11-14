#if !defined(AFX_CHOICESUBSET_H__7CEE2B31_E95D_407D_AE9C_957F7FE7D3DE__INCLUDED_)
#define AFX_CHOICESUBSET_H__7CEE2B31_E95D_407D_AE9C_957F7FE7D3DE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ChoiceSubSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CChoiceSubSet recordset

class CChoiceSubSet : public CRecordset
{
public:
	CChoiceSubSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CChoiceSubSet)

// Field/Param Data
	//{{AFX_FIELD(CChoiceSubSet, CRecordset)
	CString	m_stu_name;
	BOOL	m_stu_choisubStatus;
	CString	m_sub_Name;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChoiceSubSet)
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

#endif // !defined(AFX_CHOICESUBSET_H__7CEE2B31_E95D_407D_AE9C_957F7FE7D3DE__INCLUDED_)
