// TecrsubSet.cpp : implementation file
//

#include "stdafx.h"
#include "gradudemis.h"
#include "TecrsubSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTecrsubSet

IMPLEMENT_DYNAMIC(CTecrsubSet, CRecordset)

CTecrsubSet::CTecrsubSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CTecrsubSet)
	m_tecr_name = _T("");
	m_sub_title = _T("");
	m_nFields = 2;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CTecrsubSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=GraduDeMIS");
}

CString CTecrsubSet::GetDefaultSQL()
{
	return _T("[tab_TecrSub]");
}

void CTecrsubSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CTecrsubSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[tecr_name]"), m_tecr_name);
	RFX_Text(pFX, _T("[sub_title]"), m_sub_title);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CTecrsubSet diagnostics

#ifdef _DEBUG
void CTecrsubSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CTecrsubSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
