// ChapterRecordset.h: interface for the CChapterRecordset Chapter.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHAPTERRECORDSET_H__1DD34714_2E9D_4784_B4DD_71E0757ED90F__INCLUDED_)
#define AFX_CHAPTERRECORDSET_H__1DD34714_2E9D_4784_B4DD_71E0757ED90F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ChapterTableItem.h"
#include "AdoRecordset.h"
#include <vector>
using std::vector;

class AFX_EXT_CLASS CChapterRecordset : public CAdoRecordset  
{
public:
	long GetChapterID(long lClassID, const CString& strChapterName);
	CChapterRecordset();
	CChapterRecordset(CAdoDatabase* pDB);
	virtual ~CChapterRecordset();

	int Query(const CString& strSQL, vector<ChapterTableItem>& vecCTI, const CString& strSort = _T(""));
	int Insert(const ChapterTableItem& cti);
	int Delete(const CString& strSQL);
	int Modify(const CString& strSQL, const ChapterTableItem& cti);

};

#endif // !defined(AFX_CHAPTERRECORDSET_H__1DD34714_2E9D_4784_B4DD_71E0757ED90F__INCLUDED_)
