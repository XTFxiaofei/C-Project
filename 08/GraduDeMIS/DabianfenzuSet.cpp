// DabianfenzuSet.cpp : implementation file
//

#include "stdafx.h"
#include "gradudemis.h"
#include "DabianfenzuSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDabianfenzuSet

IMPLEMENT_DYNAMIC(CDabianfenzuSet, CRecordset)

CDabianfenzuSet::CDabianfenzuSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CDabianfenzuSet)
	m_stu_name = _T("");
	m_dabian_unit = _T("");
	m_keti_type = _T("");
	m_nFields = 3;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CDabianfenzuSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=GraduDeMIS");
}

CString CDabianfenzuSet::GetDefaultSQL()
{
	return _T("[tab_DabianFenzu]");
}

void CDabianfenzuSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CDabianfenzuSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[stu_name]"), m_stu_name);
	RFX_Text(pFX, _T("[dabian_unit]"), m_dabian_unit);
	RFX_Text(pFX, _T("[keti_type]"), m_keti_type);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CDabianfenzuSet diagnostics

#ifdef _DEBUG
void CDabianfenzuSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CDabianfenzuSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
