// ShixiSet.cpp : implementation file
//

#include "stdafx.h"
#include "gradudemis.h"
#include "ShixiSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShixiSet

IMPLEMENT_DYNAMIC(CShixiSet, CRecordset)

CShixiSet::CShixiSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CShixiSet)
	m_stu_name = _T("");
	m_shixi_bSubmit = FALSE;
	m_shixi_Behave = _T("");
	m_shixi_bRelate = FALSE;
	m_shixi_Result = _T("");
	m_nFields = 5;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CShixiSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=GraduDeMIS");
}

CString CShixiSet::GetDefaultSQL()
{
	return _T("[tab_ShiXi]");
}

void CShixiSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CShixiSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[stu_name]"), m_stu_name);
	RFX_Bool(pFX, _T("[shixi_bSubmit]"), m_shixi_bSubmit);
	RFX_Text(pFX, _T("[shixi_Behave]"), m_shixi_Behave);
	RFX_Bool(pFX, _T("[shixi_bRelate]"), m_shixi_bRelate);
	RFX_Text(pFX, _T("[shixi_Result]"), m_shixi_Result);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CShixiSet diagnostics

#ifdef _DEBUG
void CShixiSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CShixiSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
