// StudentSet.cpp : implementation file
//

#include "stdafx.h"
#include "gradudemis.h"
#include "StudentSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStudentSet

IMPLEMENT_DYNAMIC(CStudentSet, CRecordset)

CStudentSet::CStudentSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CStudentSet)
	m_stu_id = _T("");
	m_stu_name = _T("");
	m_stu_sex = _T("");
	m_stu_class = _T("");
	m_stu_age = _T("");
	m_stu_depart = _T("");
	m_nFields = 6;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CStudentSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=GraduDeMIS");
}

CString CStudentSet::GetDefaultSQL()
{
	return _T("[tab_stu]");
}

void CStudentSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CStudentSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[stu_id]"), m_stu_id);
	RFX_Text(pFX, _T("[stu_name]"), m_stu_name);
	RFX_Text(pFX, _T("[stu_sex]"), m_stu_sex);
	RFX_Text(pFX, _T("[stu_class]"), m_stu_class);
	RFX_Text(pFX, _T("[stu_age]"), m_stu_age);
	RFX_Text(pFX, _T("[stu_depart]"), m_stu_depart);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CStudentSet diagnostics

#ifdef _DEBUG
void CStudentSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CStudentSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
