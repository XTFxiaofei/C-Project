// CoisubSet.cpp : implementation file
//

#include "stdafx.h"
#include "gradudemis.h"
#include "CoisubSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCoisubSet

IMPLEMENT_DYNAMIC(CCoisubSet, CRecordset)

CCoisubSet::CCoisubSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CCoisubSet)
	m_sub_id = _T("");
	m_tecr_id = _T("");
	m_stu_id = _T("");
	m_nFields = 3;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CCoisubSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=GraduDeMIS");
}

CString CCoisubSet::GetDefaultSQL()
{
	return _T("[tab_ChoiceSub]");
}

void CCoisubSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CCoisubSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[sub_id]"), m_sub_id);
	RFX_Text(pFX, _T("[tecr_id]"), m_tecr_id);
	RFX_Text(pFX, _T("[stu_id]"), m_stu_id);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CCoisubSet diagnostics

#ifdef _DEBUG
void CCoisubSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CCoisubSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
