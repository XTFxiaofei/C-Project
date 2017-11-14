#if !defined(AFX_TESTSET_H__C639ECDC_8C0D_485E_A260_D3B20C9E08E5__INCLUDED_)
#define AFX_TESTSET_H__C639ECDC_8C0D_485E_A260_D3B20C9E08E5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TESTSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// TESTSet recordset

class TESTSet : public CRecordset
{
public:
	TESTSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(TESTSet)

// Field/Param Data
	//{{AFX_FIELD(TESTSet, CRecordset)
	long	m_id;
	CString	m_xuanx1;
	CString	m_xuanx2;
	CString	m_xuanx3;
	CString	m_xuanx4;
	CString	m_tm;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(TESTSet)
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

#endif // !defined(AFX_TESTSET_H__C639ECDC_8C0D_485E_A260_D3B20C9E08E5__INCLUDED_)
