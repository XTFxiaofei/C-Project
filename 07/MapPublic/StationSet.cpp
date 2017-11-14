// StationSet.cpp : implementation file
//

#include "stdafx.h"
#include "MapPublic.h"
#include "StationSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStationSet

IMPLEMENT_DYNAMIC(CStationSet, CRecordset)

CStationSet::CStationSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CStationSet)
	m_ID = _T("");
	m_STATION = _T("");
	m_nFields = 2;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CStationSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=HangzhouSet");
}

CString CStationSet::GetDefaultSQL()
{
	return _T("[STATION]");
}

void CStationSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CStationSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[STATION]"), m_STATION);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CStationSet diagnostics

#ifdef _DEBUG
void CStationSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CStationSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
