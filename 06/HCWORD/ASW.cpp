// ASW.cpp : implementation file
//

#include "stdafx.h"
#include "HCWORD.h"
#include "ASW.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ASW

IMPLEMENT_DYNAMIC(ASW, CRecordset)

ASW::ASW(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(ASW)
	m_eg = _T("");
	m_IDR = _T("");
	m_jieshi = _T("");
	m_nFields = 3;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString ASW::GetDefaultConnect()
{
	return _T("ODBC;DSN=´Ê¿â");
}

CString ASW::GetDefaultSQL()
{
	return _T("guess");
}

void ASW::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(ASW)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[eg]"), m_eg);
	RFX_Text(pFX, _T("[IDR]"), m_IDR);
	RFX_Text(pFX, _T("[jieshi]"), m_jieshi);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// ASW diagnostics

#ifdef _DEBUG
void ASW::AssertValid() const
{
	CRecordset::AssertValid();
}

void ASW::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
