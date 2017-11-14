// CourseWareRecordset.h: interface for the CCourseWareRecordset class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COURSEWARERECORDSET_H__0242B0C3_80B3_4B30_B550_ACF417D09982__INCLUDED_)
#define AFX_COURSEWARERECORDSET_H__0242B0C3_80B3_4B30_B550_ACF417D09982__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AdoRecordset.h"
#include "AdoDatabase.h"
#include "CourseWareInfo.h"
#include <vector>
using std::vector;

class AFX_EXT_CLASS CCourseWareRecordset : public CAdoRecordset 
{
public:
	CCourseWareRecordset(CAdoDatabase* pDB);
	CCourseWareRecordset();
	virtual ~CCourseWareRecordset();

	int Query(const CString& strSQL, vector<CCourseWareInfo>& vecCWInfo, const CString& strSort = _T(""));
	int QueryField(const CString& strSQL, const CString& strField, vector<CString>& vecStr, const CString& strSort = _T(""));
	int Insert(const CCourseWareInfo& cwi);
	int Delete(const CString& strSQL);
	int Modify(const CString& strSQL, const CCourseWareInfo& cwi);
};

#endif // !defined(AFX_COURSEWARERECORDSET_H__0242B0C3_80B3_4B30_B550_ACF417D09982__INCLUDED_)
