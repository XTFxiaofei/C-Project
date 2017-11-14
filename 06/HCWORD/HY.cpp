// HY.cpp : implementation file
//

#include "stdafx.h"
#include "HCWORD.h"
#include "HY.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// HY

IMPLEMENT_DYNAMIC(HY, CRecordset)

HY::HY(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(HY)
	m_eg = _T("");
	m_yinbiao = _T("");
	m_jsh = _T("");
	m_riqi = _T("");
	m_mosh = 0;
	m_nFields = 5;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString HY::GetDefaultConnect()
{
	return _T("ODBC;DSN=´Ê¿â;Trusted_Connection=Yes;");
}

CString HY::GetDefaultSQL()
{
	return _T("[shengci]");
}

void HY::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(HY)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[eg]"), m_eg);
	RFX_Text(pFX, _T("[yinbiao]"), m_yinbiao);
	RFX_Text(pFX, _T("[jsh]"), m_jsh);
	RFX_Text(pFX, _T("[riqi]"), m_riqi);
	RFX_Long(pFX, _T("[mosh]"), m_mosh);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// HY diagnostics

#ifdef _DEBUG
void HY::AssertValid() const
{
	CRecordset::AssertValid();
}

void HY::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
