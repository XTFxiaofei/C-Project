// TeacherSet.cpp : implementation file
//

#include "stdafx.h"
#include "gradudemis.h"
#include "TeacherSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTeacherSet

IMPLEMENT_DYNAMIC(CTeacherSet, CRecordset)

CTeacherSet::CTeacherSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CTeacherSet)
	m_tecr_name = _T("");
	m_tecr_age = _T("");
	m_tecr_asoci = _T("");
	m_tecr_id = _T("");
	m_tecr_level = _T("");
	m_tecr_sex = _T("");
	m_tecr_TRroom = _T("");
	m_nFields = 7;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CTeacherSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=GraduDeMIS");
}

CString CTeacherSet::GetDefaultSQL()
{
	return _T("[tab_tecr]");
}

void CTeacherSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CTeacherSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[tecr_age]"), m_tecr_age);
	RFX_Text(pFX, _T("[tecr_asoci]"), m_tecr_asoci);
	RFX_Text(pFX, _T("[tecr_id]"), m_tecr_id);
	RFX_Text(pFX, _T("[tecr_level]"), m_tecr_level);
	RFX_Text(pFX, _T("[tecr_name]"), m_tecr_name);
	RFX_Text(pFX, _T("[tecr_sex]"), m_tecr_sex);
	RFX_Text(pFX, _T("[tecr_TRroom]"), m_tecr_TRroom);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CTeacherSet diagnostics

#ifdef _DEBUG
void CTeacherSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CTeacherSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
