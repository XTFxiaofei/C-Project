// KaitiSet.cpp : implementation file
//

#include "stdafx.h"
#include "gradudemis.h"
#include "KaitiSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKaitiSet

IMPLEMENT_DYNAMIC(CKaitiSet, CRecordset)

CKaitiSet::CKaitiSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CKaitiSet)
	m_stu_name = _T("");
	m_kaiti_bSubmit = FALSE;
	m_kaiti_Understand = _T("");
	m_kaiti_bPlan = FALSE;
	m_kaiti_bBaseCndi = FALSE;
	m_kaiti_ColiResult = _T("");
	m_nFields = 6;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CKaitiSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=GraduDeMIS");
}

CString CKaitiSet::GetDefaultSQL()
{
	return _T("[tab_KaiTi]");
}

void CKaitiSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CKaitiSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[stu_name]"), m_stu_name);
	RFX_Bool(pFX, _T("[kaiti_bSubmit]"), m_kaiti_bSubmit);
	RFX_Text(pFX, _T("[kaiti_Understand]"), m_kaiti_Understand);
	RFX_Bool(pFX, _T("[kaiti_bPlan]"), m_kaiti_bPlan);
	RFX_Bool(pFX, _T("[kaiti_bBaseCndi]"), m_kaiti_bBaseCndi);
	RFX_Text(pFX, _T("[kaiti_ColiResult]"), m_kaiti_ColiResult);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CKaitiSet diagnostics

#ifdef _DEBUG
void CKaitiSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CKaitiSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
