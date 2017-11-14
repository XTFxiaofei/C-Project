// DclrsubSet.cpp : implementation file
//

#include "stdafx.h"
#include "gradudemis.h"
#include "DclrsubSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDclrsubSet

IMPLEMENT_DYNAMIC(CDclrsubSet, CRecordset)

CDclrsubSet::CDclrsubSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CDclrsubSet)
	m_tecr_name = _T("");
	m_tecr_MaxNum = _T("");
	m_tecr_DclrNum = _T("");
	m_nFields = 3;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CDclrsubSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=GraduDeMIS");
}

CString CDclrsubSet::GetDefaultSQL()
{
	return _T("[tab_Dclrsub]");
}

void CDclrsubSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CDclrsubSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[tecr_name]"), m_tecr_name);
	RFX_Text(pFX, _T("[tecr_MaxNum]"), m_tecr_MaxNum);
	RFX_Text(pFX, _T("[tecr_DclrNum]"), m_tecr_DclrNum);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CDclrsubSet diagnostics

#ifdef _DEBUG
void CDclrsubSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CDclrsubSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
