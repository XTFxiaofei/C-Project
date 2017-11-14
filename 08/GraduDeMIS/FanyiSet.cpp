// FanyiSet.cpp : implementation file
//

#include "stdafx.h"
#include "gradudemis.h"
#include "FanyiSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFanyiSet

IMPLEMENT_DYNAMIC(CFanyiSet, CRecordset)

CFanyiSet::CFanyiSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CFanyiSet)
	m_stu_name = _T("");
	m_fanyi_bSubmit = FALSE;
	m_fanyi_Quality = _T("");
	m_fanyi_bNum = FALSE;
	m_fanyi_bRelate = FALSE;
	m_fanyi_Result = _T("");
	m_nFields = 6;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CFanyiSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=GraduDeMIS");
}

CString CFanyiSet::GetDefaultSQL()
{
	return _T("[tab_FanYi]");
}

void CFanyiSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CFanyiSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[stu_name]"), m_stu_name);
	RFX_Bool(pFX, _T("[fanyi_bSubmit]"), m_fanyi_bSubmit);
	RFX_Text(pFX, _T("[fanyi_Quality]"), m_fanyi_Quality);
	RFX_Bool(pFX, _T("[fanyi_bNum]"), m_fanyi_bNum);
	RFX_Bool(pFX, _T("[fanyi_bRelate]"), m_fanyi_bRelate);
	RFX_Text(pFX, _T("[fanyi_Result]"), m_fanyi_Result);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CFanyiSet diagnostics

#ifdef _DEBUG
void CFanyiSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CFanyiSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
