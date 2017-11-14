// Wjset.cpp : implementation file
//

#include "stdafx.h"
#include "HCWORD.h"
#include "Wjset.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Wjset

IMPLEMENT_DYNAMIC(Wjset, CRecordset)

Wjset::Wjset(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(Wjset)
	m_id = 0;
	m_danci = _T("");
	m_jieshi= _T("");
	m_nFields = 3;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString Wjset::GetDefaultConnect()
{
	return _T("ODBC;DSN=´Ê¿â;Trusted_Connection=Yes;");
}

CString Wjset::GetDefaultSQL()
{
	return _T("guess");
}

void Wjset::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(Wjset)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[id]"), m_id);
	RFX_Text(pFX, _T("[danci]"), m_danci);
	RFX_Text(pFX, _T("[jieshi]"), m_jieshi);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// Wjset diagnostics

#ifdef _DEBUG
void Wjset::AssertValid() const
{
	CRecordset::AssertValid();
}

void Wjset::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
