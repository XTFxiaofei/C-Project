// SectionRecordset.h: interface for the CSectionRecordset class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SECTIONRECORDSET_H__90DE78F6_4E87_41FE_9FEF_A3D90CD2956A__INCLUDED_)
#define AFX_SECTIONRECORDSET_H__90DE78F6_4E87_41FE_9FEF_A3D90CD2956A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SectionTableItem.h"
#include "AdoRecordset.h"
#include <vector>
using std::vector;

class AFX_EXT_CLASS CSectionRecordset : public CAdoRecordset  
{
public:
	CSectionRecordset();
	CSectionRecordset(CAdoDatabase* pDB);
	virtual ~CSectionRecordset();

	int Query(const CString& strSQL, vector<SectionTableItem>& vecSTI, const CString& strSort = _T(""));
	int Insert(const SectionTableItem& sti);
	int Delete(const CString& strSQL);
	int Modify(const CString& strSQL, const SectionTableItem& sti);

};

#endif // !defined(AFX_SECTIONRECORDSET_H__90DE78F6_4E87_41FE_9FEF_A3D90CD2956A__INCLUDED_)
