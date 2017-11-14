// PasswordSet.cpp : implementation file
//

#include "stdafx.h"
#include "gradudemis.h"
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
	m_lgn_user = _T("");
	m_lgn_passwd = _T("");
	m_lgn_isAdmin = FALSE;
	m_user_type = _T("");
	m_user_unit = _T("");
	m_nFields = 5;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CPasswordSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=GraduDeMIS");
}

CString CPasswordSet::GetDefaultSQL()
{
	return _T("[tab_password]");
}

void CPasswordSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CPasswordSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[lgn_user]"), m_lgn_user);
	RFX_Text(pFX, _T("[lgn_passwd]"), m_lgn_passwd);
	RFX_Bool(pFX, _T("[lgn_isAdmin]"), m_lgn_isAdmin);
	RFX_Text(pFX, _T("[user_type]"), m_user_type);
	RFX_Text(pFX, _T("[user_unit]"), m_user_unit);
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
