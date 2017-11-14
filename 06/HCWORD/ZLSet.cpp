// ZLSet.cpp : implementation file
//

#include "stdafx.h"
#include "HCWORD.h"
#include "ZLSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ZLSet

IMPLEMENT_DYNAMIC(ZLSet, CRecordset)

ZLSet::ZLSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(ZLSet)
	m_piezi = _T("");
	m_guoqing = _T("");
	m_baozi = _T("");
	m_dian = _T("");
	m_hua = _T("");
	m_w1= _T("");
	m_w2= _T("");
	m_w3= _T("");
    m_w4=_T("");
	m_j1=_T("");
	m_j2=_T("");
	m_j3=_T("");
	m_j4=_T("");
    m_j5=_T("");
	m_j6=_T("");
    m_j7=_T("");
    m_j8=_T("");
    m_j9=_T("");
	m_nFields = 18;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString ZLSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=´Ê¿â;Trusted_Connection=Yes;");
}

CString ZLSet::GetDefaultSQL()
{
	return _T("[ziliao]");
}

void ZLSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(ZLSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[piezi]"), m_piezi);
	RFX_Text(pFX, _T("[guoqing]"), m_guoqing);
	RFX_Text(pFX, _T("[baozi]"), m_baozi);
	RFX_Text(pFX, _T("[dian]"), m_dian);
	RFX_Text(pFX, _T("[hua]"), m_hua);
	RFX_Text(pFX, _T("[w1]"), m_w1);
	RFX_Text(pFX, _T("[w2]"), m_w2);
	RFX_Text(pFX, _T("[w3]"), m_w3);
	RFX_Text(pFX, _T("[w4]"), m_w4);
	RFX_Text(pFX, _T("[j1]"), m_j1);
	RFX_Text(pFX, _T("[j2]"), m_j2);
	RFX_Text(pFX, _T("[j3]"), m_j3);
	RFX_Text(pFX, _T("[j4]"), m_j4);
	RFX_Text(pFX, _T("[j5]"), m_j5);
	RFX_Text(pFX, _T("[j6]"), m_j6);
	RFX_Text(pFX, _T("[j7]"), m_j7);
	RFX_Text(pFX, _T("[j8]"), m_j8);
	RFX_Text(pFX, _T("[j9]"), m_j9);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// ZLSet diagnostics

#ifdef _DEBUG
void ZLSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void ZLSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
