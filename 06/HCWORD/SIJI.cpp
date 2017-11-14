// SIJI.cpp : implementation file
//

#include "stdafx.h"
#include "HCWORD.h"
#include "SIJI.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// SIJI

IMPLEMENT_DYNAMIC(SIJI, CRecordset)

SIJI::SIJI(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(SIJI)
	m_si1 = _T("");
	m_si2 = _T("");
	m_nFields = 2;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString SIJI::GetDefaultConnect()
{
	return _T("ODBC;DSN=´Ê¿â;Trusted_Connection=Yes;");
}

CString SIJI::GetDefaultSQL()
{
	return _T("[four]");
}

void SIJI::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(SIJI)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[si1]"), m_si1);
	RFX_Text(pFX, _T("[si2]"), m_si2);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// SIJI diagnostics

#ifdef _DEBUG
void SIJI::AssertValid() const
{
	CRecordset::AssertValid();
}

void SIJI::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
