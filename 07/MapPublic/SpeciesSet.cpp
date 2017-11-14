// SpeciesSet.cpp : implementation file
//

#include "stdafx.h"
#include "MapPublic.h"
#include "SpeciesSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSpeciesSet

IMPLEMENT_DYNAMIC(CSpeciesSet, CRecordset)

CSpeciesSet::CSpeciesSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CSpeciesSet)
	m_index = 0;
	m_ShpName = _T("");
	m_nFields = 2;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CSpeciesSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=HangzhouSet");
}

CString CSpeciesSet::GetDefaultSQL()
{
	return _T("[Species]");
}

void CSpeciesSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CSpeciesSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[index]"), m_index);
	RFX_Text(pFX, _T("[ShpName]"), m_ShpName);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CSpeciesSet diagnostics

#ifdef _DEBUG
void CSpeciesSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CSpeciesSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
