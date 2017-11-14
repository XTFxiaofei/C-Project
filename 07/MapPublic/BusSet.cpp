// BusSet.cpp : implementation file
//

#include "stdafx.h"
#include "MapPublic.h"
#include "BusSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBusSet

IMPLEMENT_DYNAMIC(CBusSet, CRecordset)

CBusSet::CBusSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CBusSet)
	m_ID_BUS = _T("");
	m_BEGIN = _T("");
	m_END = _T("");
	m_AMTIME = _T("");
	m_PMTIME = _T("");
	m_nFields = 5;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CBusSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=HangzhouSet");
}

CString CBusSet::GetDefaultSQL()
{
	return _T("[BUS]");
}

void CBusSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CBusSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[ID_BUS]"), m_ID_BUS);
	RFX_Text(pFX, _T("[BEGIN]"), m_BEGIN);
	RFX_Text(pFX, _T("[END]"), m_END);
	RFX_Text(pFX, _T("[AMTIME]"), m_AMTIME);
	RFX_Text(pFX, _T("[PMTIME]"), m_PMTIME);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CBusSet diagnostics

#ifdef _DEBUG
void CBusSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CBusSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
