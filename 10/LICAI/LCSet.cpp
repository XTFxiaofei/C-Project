// LCSet.cpp : implementation file
//

#include "stdafx.h"
#include "licai.h"
#include "LCSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// LCSet

IMPLEMENT_DYNAMIC(LCSet, CRecordset)

LCSet::LCSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(LCSet)
	m_about = _T("");
	m_costnum = 0;
	m_costtype = _T("");
	m_id = 0;
	m_incomenum = 0;
	m_incometype = _T("");
	m_time = _T("");
	m_nFields = 7;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString LCSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=LICAI");
}

CString LCSet::GetDefaultSQL()
{
	return _T("[licai]");
}

void LCSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(LCSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[about]"), m_about);
	RFX_Long(pFX, _T("[costnum]"), m_costnum);
	RFX_Text(pFX, _T("[costtype]"), m_costtype);
	RFX_Long(pFX, _T("[id]"), m_id);
	RFX_Long(pFX, _T("[incomenum]"), m_incomenum);
	RFX_Text(pFX, _T("[incometype]"), m_incometype);
	RFX_Text(pFX, _T("[time]"), m_time);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// LCSet diagnostics

#ifdef _DEBUG
void LCSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void LCSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
