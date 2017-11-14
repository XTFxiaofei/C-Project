// SubjectSet.cpp : implementation file
//

#include "stdafx.h"
#include "gradudemis.h"
#include "SubjectSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSubjectSet

IMPLEMENT_DYNAMIC(CSubjectSet, CRecordset)

CSubjectSet::CSubjectSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CSubjectSet)
	m_sub_title = _T("");
	m_sub_type = _T("");
	m_sub_pro = _T("");
	m_sub_demand = _T("");
	m_tecr_name = _T("");
	m_nFields = 5;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CSubjectSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=GraduDeMIS");
}

CString CSubjectSet::GetDefaultSQL()
{
	return _T("[tab_sub]");
}

void CSubjectSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CSubjectSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[sub_title]"), m_sub_title);
	RFX_Text(pFX, _T("[sub_type]"), m_sub_type);
	RFX_Text(pFX, _T("[sub_pro]"), m_sub_pro);
	RFX_Text(pFX, _T("[sub_demand]"), m_sub_demand);
	RFX_Text(pFX, _T("[tecr_name]"), m_tecr_name);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CSubjectSet diagnostics

#ifdef _DEBUG
void CSubjectSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CSubjectSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
