// HCset.cpp : implementation file
//

#include "stdafx.h"
#include "hcword.h"
#include "HCset.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// HCset

IMPLEMENT_DYNAMIC(HCset, CRecordset)

HCset::HCset(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(HCset)
	m_eg = _T("");
	m_zw = _T("");
	m_vi = _T("");
	m_vt = _T("");
	m_n = _T("");
	m_adj = _T("");
	m_adv = _T("");
	m_riqi = _T("");
	m_id = 0;
	m_nFields = 9;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString HCset::GetDefaultConnect()
{
//	return _T("ODBC;DSN=´Ê¿â;Trusted_Connection=Yes;");
	return _T("ODBC;DSN=´Ê¿â;UID=sa;PWD=;");
}

CString HCset::GetDefaultSQL()
{
	return _T("[dbo].[eh]");
}

void HCset::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(HCset)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[eg]"), m_eg);
	RFX_Text(pFX, _T("[zw]"), m_zw);
	RFX_Text(pFX, _T("[vi]"), m_vi);
	RFX_Text(pFX, _T("[vt]"), m_vt);
	RFX_Text(pFX, _T("[n]"), m_n);
	RFX_Text(pFX, _T("[adj]"), m_adj);
	RFX_Text(pFX, _T("[adv]"), m_adv);
	RFX_Text(pFX, _T("[riqi]"), m_riqi);
	RFX_Long(pFX, _T("[id]"), m_id);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// HCset diagnostics

#ifdef _DEBUG
void HCset::AssertValid() const
{
	CRecordset::AssertValid();
}

void HCset::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
