// ClassRecordset.h: interface for the CClassRecordset class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLASSRECORDSET_H__5E7674E9_FCEE_45B0_B782_6C9B14EB7EC5__INCLUDED_)
#define AFX_CLASSRECORDSET_H__5E7674E9_FCEE_45B0_B782_6C9B14EB7EC5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AdoDatabase.h"
#include "AdoRecordset.h"
#include "ClassTableItem.h"
#include <vector>
using std::vector;

class AFX_EXT_CLASS CClassRecordset : public CAdoRecordset
{
public:
	long GetClassID(const CString& strClassName);
	CClassRecordset();
	CClassRecordset(CAdoDatabase* pDB);
	virtual ~CClassRecordset();

	int Query(const CString& strSQL, vector<ClassTableItem>& vecCTI, const CString& strSort = _T(""));
	int Insert(const ClassTableItem& cti);
	int Delete(const CString& strSQL);
	int Modify(const CString& strSQL, const ClassTableItem& cti);
};

#endif // !defined(AFX_CLASSRECORDSET_H__5E7674E9_FCEE_45B0_B782_6C9B14EB7EC5__INCLUDED_)
