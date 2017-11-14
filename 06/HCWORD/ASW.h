#if !defined(AFX_ASW_H__90FF59C9_1138_4761_8404_0211CAB16952__INCLUDED_)
#define AFX_ASW_H__90FF59C9_1138_4761_8404_0211CAB16952__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ASW.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ASW recordset

class ASW : public CRecordset
{
public:
	ASW(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(ASW)

// Field/Param Data
	//{{AFX_FIELD(ASW, CRecordset)
	CString	m_eg;
	CString	m_IDR;
	CString	m_jieshi;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ASW)
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

#endif // !defined(AFX_ASW_H__90FF59C9_1138_4761_8404_0211CAB16952__INCLUDED_)
