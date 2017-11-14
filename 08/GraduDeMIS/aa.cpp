// aa.cpp : implementation file
//

#include "stdafx.h"
#include "gradudemis.h"
#include "aa.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// aa

IMPLEMENT_DYNAMIC(aa, CDaoRecordset)

aa::aa(CDaoDatabase* pdb)
	: CDaoRecordset(pdb)
{
	//{{AFX_FIELD_INIT(aa)
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString aa::GetDefaultDBName()
{
	return _T("");
}

CString aa::GetDefaultSQL()
{
	return _T("");
}

void aa::DoFieldExchange(CDaoFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(aa)
	pFX->SetFieldType(CDaoFieldExchange::outputColumn);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// aa diagnostics

#ifdef _DEBUG
void aa::AssertValid() const
{
	CDaoRecordset::AssertValid();
}

void aa::Dump(CDumpContext& dc) const
{
	CDaoRecordset::Dump(dc);
}
#endif //_DEBUG
