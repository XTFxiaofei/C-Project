#if !defined(AFX_COISUBSET_H__DEC36585_B599_47F4_992A_8F5151E87D66__INCLUDED_)
#define AFX_COISUBSET_H__DEC36585_B599_47F4_992A_8F5151E87D66__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CoisubSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCoisubSet recordset

class CCoisubSet : public CRecordset
{
public:
	CCoisubSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CCoisubSet)


// Field/Param Data
	//{{AFX_FIELD(CCoisubSet, CRecordset)
	CString	m_sub_id;
	CString	m_tecr_id;
	CString	m_stu_id;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCoisubSet)
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

#endif // !defined(AFX_COISUBSET_H__DEC36585_B599_47F4_992A_8F5151E87D66__INCLUDED_)
