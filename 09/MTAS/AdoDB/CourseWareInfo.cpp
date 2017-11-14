// CourseWareInfo.cpp: implementation of the CCourseWareInfo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CourseWareInfo.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCourseWareInfo::CCourseWareInfo()
{
	m_strName    = _T("");
	m_strType    = _T("");
	m_lSize      = 0;
	m_strPath    = _T("");
	m_strModTime = _T("");
	m_strClass   = _T("");
	m_strChapter = _T("");
	m_strSection = _T("");
}

CCourseWareInfo::CCourseWareInfo(const CCourseWareInfo &cwi)
{
	m_strName    = cwi.m_strName;
	m_strType    = cwi.m_strType;
	m_lSize      = cwi.m_lSize;
	m_strPath    = cwi.m_strPath;
	m_strModTime = cwi.m_strModTime;
	m_strClass   = cwi.m_strClass;
	m_strChapter = cwi.m_strChapter;
	m_strSection = cwi.m_strSection;
}

CCourseWareInfo::~CCourseWareInfo()
{
}


CCourseWareInfo CCourseWareInfo::operator =(const CCourseWareInfo &cwi)
{
	m_strName    = cwi.m_strName;
	m_strType    = cwi.m_strType;
	m_lSize      = cwi.m_lSize;
	m_strPath    = cwi.m_strPath;
	m_strModTime = cwi.m_strModTime;
	m_strClass   = cwi.m_strClass;
	m_strChapter = cwi.m_strChapter;
	m_strSection = cwi.m_strSection;

	return *this;
}

BOOL CCourseWareInfo::operator ==(const CCourseWareInfo &cwi)
{
	if(m_strName != cwi.m_strName)
		return FALSE;
	if(m_strType != cwi.m_strType)
		return FALSE;
	if(m_strPath != cwi.m_strPath)
		return FALSE;
	if(m_strModTime != cwi.m_strModTime)
		return FALSE;
	if(m_strClass != cwi.m_strClass)
		return FALSE;
	if(m_strChapter != cwi.m_strChapter)
		return FALSE;
	if(m_strSection != cwi.m_strSection)
		return FALSE;

	return TRUE;
}
