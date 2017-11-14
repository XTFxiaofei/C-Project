// CourseWareManager.h: interface for the CourseWareManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OURSEWAREMANAGER_H__4F3CE3F0_5586_4A42_B3E0_7BECBB168A21__INCLUDED_)
#define AFX_OURSEWAREMANAGER_H__4F3CE3F0_5586_4A42_B3E0_7BECBB168A21__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>
	
class IUpdate;

class CourseWareManager : public CObject
{
public:
	void UpdateDisplay(IUpdate* pUpdate);
	void UpdateAllDisplay(IUpdate* pExcept = NULL);
	void AddUpdateWindow(IUpdate* pUpdate);
	int  OpenCourseWareDir(const CString& strPath);
	int  OpenCourseWare(const CCourseWareInfo& cwi);
	int  DeleteCourseWare(const CString& strPath, BOOL bRePaint = TRUE);
	int  AddCourseWare(const CCourseWareInfo &cwi, BOOL bRePaint = TRUE);
	CourseWareManager();
	virtual ~CourseWareManager();

protected:
	CCourseWareRecordset	m_rsCourseWare;
	std::vector<IUpdate*>	m_vecUpdatePointers;
};

#endif // !defined(AFX_OURSEWAREMANAGER_H__4F3CE3F0_5586_4A42_B3E0_7BECBB168A21__INCLUDED_)
