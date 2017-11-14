#if !defined(AFX_ZLSET_H__18814AC1_5DEC_4011_A47E_06933A36A7D0__INCLUDED_)
#define AFX_ZLSET_H__18814AC1_5DEC_4011_A47E_06933A36A7D0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ZLSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ZLSet recordset

class ZLSet : public CRecordset
{
public:
	ZLSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(ZLSet)

// Field/Param Data
	//{{AFX_FIELD(ZLSet, CRecordset)
	CString	m_piezi;
	CString	m_guoqing;
	CString	m_baozi;
	CString	m_dian;
	CString	m_hua;
	CString m_w1;
		CString m_w2;
		CString m_w3;
		CString m_w4;
		CString m_j1;
		CString m_j2;
		CString m_j3;
		CString m_j4;
		CString m_j5;
		CString m_j6;
		CString m_j7;
		CString m_j8;
		CString m_j9;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ZLSet)
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

#endif // !defined(AFX_ZLSET_H__18814AC1_5DEC_4011_A47E_06933A36A7D0__INCLUDED_)
