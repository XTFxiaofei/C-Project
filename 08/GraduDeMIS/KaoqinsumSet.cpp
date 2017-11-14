// KaoqinsumSet.cpp : implementation file
//

#include "stdafx.h"
#include "gradudemis.h"
#include "KaoqinsumSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKaoqinsumSet

IMPLEMENT_DYNAMIC(CKaoqinsumSet, CRecordset)

CKaoqinsumSet::CKaoqinsumSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CKaoqinsumSet)
	m_stu_name = _T("");
	m_stu_YDaoDays = _T("");
	m_stu_attDays = _T("");
	m_stu_holiDays = _T("");
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CKaoqinsumSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=GraduDeMIS");
}

CString CKaoqinsumSet::GetDefaultSQL()
{
	return _T("[tab_KaoqinSum]");
}

void CKaoqinsumSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CKaoqinsumSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[stu_name]"), m_stu_name);
	RFX_Text(pFX, _T("[stu_YDaoDays]"), m_stu_YDaoDays);
	RFX_Text(pFX, _T("[stu_attDays]"), m_stu_attDays);
	RFX_Text(pFX, _T("[stu_holiDays]"), m_stu_holiDays);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CKaoqinsumSet diagnostics

#ifdef _DEBUG
void CKaoqinsumSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CKaoqinsumSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
