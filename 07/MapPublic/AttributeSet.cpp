// AttributeSet.cpp : implementation file
//

#include "stdafx.h"
#include "mappublic.h"
#include "AttributeSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAttributeSet

IMPLEMENT_DYNAMIC(CAttributeSet, CRecordset)

CAttributeSet::CAttributeSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CAttributeSet)
	m_ATTRIBUTE = _T("");
	m_ISPICTURE = 0;
	m_NAME = _T("");
	m_PICTURE_NAME = _T("");
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CAttributeSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=HangzhouSet");
}

CString CAttributeSet::GetDefaultSQL()
{
	return _T("[AttributeSet]");
}

void CAttributeSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CAttributeSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[ATTRIBUTE]"), m_ATTRIBUTE);
	RFX_Int(pFX, _T("[ISPICTURE]"), m_ISPICTURE);
	RFX_Text(pFX, _T("[NAME]"), m_NAME);
	RFX_Text(pFX, _T("[PICTURE_NAME]"), m_PICTURE_NAME);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CAttributeSet diagnostics

#ifdef _DEBUG
void CAttributeSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CAttributeSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
