// PasswordSet.cpp : implementation file
//

#include "stdafx.h"
#include "mappublic.h"
#include "PasswordSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPasswordSet

IMPLEMENT_DYNAMIC(CPasswordSet, CRecordset)

CPasswordSet::CPasswordSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CPasswordSet)
	m_USER_ID = _T("");
	m_USER_PASSWORD = _T("");
	m_nFields = 2;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CPasswordSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=HangzhouSet");
}

CString CPasswordSet::GetDefaultSQL()
{
	return _T("[USER]");
}

void CPasswordSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CPasswordSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[USER_ID]"), m_USER_ID);
	RFX_Text(pFX, _T("[USER_PASSWORD]"), m_USER_PASSWORD);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CPasswordSet diagnostics

#ifdef _DEBUG
void CPasswordSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CPasswordSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
