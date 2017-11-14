// StuAchieveSet.cpp : implementation file
//

#include "stdafx.h"
#include "gradudemis.h"
#include "StuAchieveSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStuAchieveSet

IMPLEMENT_DYNAMIC(CStuAchieveSet, CRecordset)

CStuAchieveSet::CStuAchieveSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CStuAchieveSet)
	m_stu_name = _T("");
	m_forlanLevel = _T("");
	m_comLevel = _T("");
	m_schship = _T("");
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CStuAchieveSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=GraduDeMIS");
}

CString CStuAchieveSet::GetDefaultSQL()
{
	return _T("[tab_stuAchieve]");
}

void CStuAchieveSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CStuAchieveSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[stu_name]"), m_stu_name);
	RFX_Text(pFX, _T("[forlanLevel]"), m_forlanLevel);
	RFX_Text(pFX, _T("[comLevel]"), m_comLevel);
	RFX_Text(pFX, _T("[schship]"), m_schship);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CStuAchieveSet diagnostics

#ifdef _DEBUG
void CStuAchieveSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CStuAchieveSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
