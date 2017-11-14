// HCHSet.cpp : implementation file
//

#include "stdafx.h"
#include "hcword.h"
#include "HCHSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// HCHSet

IMPLEMENT_DYNAMIC(HCHSet, CRecordset)

HCHSet::HCHSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(HCHSet)
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString HCHSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=´Ê¿â");
}

CString HCHSet::GetDefaultSQL()
{
	return _T("");
}

void HCHSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(HCHSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// HCHSet diagnostics

#ifdef _DEBUG
void HCHSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void HCHSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
