// KaoqinSet.cpp : implementation file
//

#include "stdafx.h"
#include "gradudemis.h"
#include "KaoqinSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKaoqinSet

IMPLEMENT_DYNAMIC(CKaoqinSet, CRecordset)

CKaoqinSet::CKaoqinSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CKaoqinSet)
	m_stu_name = _T("");
	m_stu_ChuQinTime = _T("");
	m_stu_ChuQinStatus = FALSE;
	m_stu_UnAtedReason = _T("");
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CKaoqinSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=GraduDeMIS");
}

CString CKaoqinSet::GetDefaultSQL()
{
	return _T("[tab_KaoQin]");
}

void CKaoqinSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CKaoqinSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[stu_name]"), m_stu_name);
	RFX_Text(pFX, _T("[stu_ChuQinTime]"), m_stu_ChuQinTime);
	RFX_Bool(pFX, _T("[stu_ChuQinStatus]"), m_stu_ChuQinStatus);
	RFX_Text(pFX, _T("[stu_UnAtedReason]"), m_stu_UnAtedReason);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CKaoqinSet diagnostics

#ifdef _DEBUG
void CKaoqinSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CKaoqinSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
