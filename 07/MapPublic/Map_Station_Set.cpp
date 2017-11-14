// Map_Station_Set.cpp : implementation file
//

#include "stdafx.h"
#include "mappublic.h"
#include "Map_Station_Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMap_Station_Set

IMPLEMENT_DYNAMIC(CMap_Station_Set, CRecordset)

CMap_Station_Set::CMap_Station_Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CMap_Station_Set)
	m_ID = _T("");
	m_NAME = _T("");
	m_nFields = 2;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CMap_Station_Set::GetDefaultConnect()
{
	return _T("ODBC;DSN=HangzhouSet");
}

CString CMap_Station_Set::GetDefaultSQL()
{
	return _T("[Map_Station]");
}

void CMap_Station_Set::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CMap_Station_Set)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[NAME]"), m_NAME);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CMap_Station_Set diagnostics

#ifdef _DEBUG
void CMap_Station_Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMap_Station_Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
