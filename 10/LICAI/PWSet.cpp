// PWSet.cpp : implementation file
//

#include "stdafx.h"
#include "licai.h"
#include "PWSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PWSet

IMPLEMENT_DYNAMIC(PWSet, CRecordset)

PWSet::PWSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(PWSet)
	m_PASSWORD = _T("");
	m_ID = _T("");
	m_AUTHOR = _T("");
	m_nFields = 3;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString PWSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=LICAI");
}

CString PWSet::GetDefaultSQL()
{
	return _T("[password]");
}

void PWSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(PWSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[PASSWORD]"), m_PASSWORD);
	RFX_Text(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[AUTHOR]"), m_AUTHOR);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// PWSet diagnostics

#ifdef _DEBUG
void PWSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void PWSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
