// Action_Time_Set.cpp : implementation file
//

#include "stdafx.h"
#include "mappublic.h"
#include "Action_Time_Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAction_Time_Set

IMPLEMENT_DYNAMIC(CAction_Time_Set, CRecordset)

CAction_Time_Set::CAction_Time_Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CAction_Time_Set)
	m_USER_ID = _T("");
	m_ACTION = _T("");
	m_COME_LEAVE_TIME = _T("");
	m_nFields = 3;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CAction_Time_Set::GetDefaultConnect()
{
	return _T("ODBC;DSN=HangzhouSet");
}

CString CAction_Time_Set::GetDefaultSQL()
{
	return _T("[Action_Log]");
}

void CAction_Time_Set::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CAction_Time_Set)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[USER_ID]"), m_USER_ID);
	RFX_Text(pFX, _T("[ACTION]"), m_ACTION);
	RFX_Text(pFX, _T("[COME_LEAVE_TIME]"), m_COME_LEAVE_TIME);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CAction_Time_Set diagnostics

#ifdef _DEBUG
void CAction_Time_Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CAction_Time_Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
