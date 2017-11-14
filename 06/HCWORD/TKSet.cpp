// TKSet.cpp : implementation file
//

#include "stdafx.h"
#include "HCWORD.h"
#include "TKSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// TKSet

IMPLEMENT_DYNAMIC(TKSet, CRecordset)

TKSet::TKSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(TKSet)
	m_id = 0;
	m_xuanx1 = _T("");
	m_xuanx2 = _T("");
	m_xuanx3 = _T("");
	m_xuanx4 = _T("");
	m_tm = _T("");
    m_da = _T("");
	m_nFields = 7;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString TKSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=´Ê¿â;Trusted_Connection=Yes;");
}

CString TKSet::GetDefaultSQL()
{
	return _T("[TK]");
}

void TKSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(TKSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[id]"), m_id);
	RFX_Text(pFX, _T("[xuanx1]"), m_xuanx1);
	RFX_Text(pFX, _T("[xuanx2]"), m_xuanx2);
	RFX_Text(pFX, _T("[xuanx3]"), m_xuanx3);
	RFX_Text(pFX, _T("[xuanx4]"), m_xuanx4);
	RFX_Text(pFX, _T("[tm]"), m_tm);
    RFX_Text(pFX, _T("[da]"), m_da);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// TKSet diagnostics

#ifdef _DEBUG
void TKSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void TKSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
