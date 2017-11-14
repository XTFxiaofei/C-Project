// ChoiceSubSet.cpp : implementation file
//

#include "stdafx.h"
#include "gradudemis.h"
#include "ChoiceSubSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChoiceSubSet

IMPLEMENT_DYNAMIC(CChoiceSubSet, CRecordset)

CChoiceSubSet::CChoiceSubSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CChoiceSubSet)
	m_stu_name = _T("");
	m_stu_choisubStatus = FALSE;
	m_sub_Name = _T("");
	m_nFields = 3;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CChoiceSubSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=GraduDeMIS");
}

CString CChoiceSubSet::GetDefaultSQL()
{
	return _T("[tab_choisub]");
}

void CChoiceSubSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CChoiceSubSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[stu_name]"), m_stu_name);
	RFX_Bool(pFX, _T("[stu_choisubStatus]"), m_stu_choisubStatus);
	RFX_Text(pFX, _T("[sub_Name]"), m_sub_Name);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CChoiceSubSet diagnostics

#ifdef _DEBUG
void CChoiceSubSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CChoiceSubSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
