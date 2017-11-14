// TESTSet.cpp : implementation file
//

#include "stdafx.h"
#include "HCWORD.h"
#include "TESTSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// TESTSet

IMPLEMENT_DYNAMIC(TESTSet, CRecordset)

TESTSet::TESTSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(TESTSet)
	m_id = 0;
	m_xuanx1 = _T("");
	m_xuanx2 = _T("");
	m_xuanx3 = _T("");
	m_xuanx4 = _T("");
	m_tm = _T("");
	m_nFields = 6;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString TESTSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=´Ê¿â;Trusted_Connection=Yes;");
}

CString TESTSet::GetDefaultSQL()
{
	return _T("[TK]");
}

void TESTSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(TESTSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[id]"), m_id);
	RFX_Text(pFX, _T("[xuanx1]"), m_xuanx1);
	RFX_Text(pFX, _T("[xuanx2]"), m_xuanx2);
	RFX_Text(pFX, _T("[xuanx3]"), m_xuanx3);
	RFX_Text(pFX, _T("[xuanx4]"), m_xuanx4);
	RFX_Text(pFX, _T("[tm]"), m_tm);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// TESTSet diagnostics

#ifdef _DEBUG
void TESTSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void TESTSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
