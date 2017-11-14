// CourseWareInfo.h: interface for the CCourseWareInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COURSEWAREINFO_H__EAF2A448_B64D_48B5_9757_69534F10B2F5__INCLUDED_)
#define AFX_COURSEWAREINFO_H__EAF2A448_B64D_48B5_9757_69534F10B2F5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class AFX_EXT_CLASS CCourseWareInfo : public CObject  
{
public:
	CCourseWareInfo();
	CCourseWareInfo(const CCourseWareInfo &cwi);
	virtual ~CCourseWareInfo();

	CCourseWareInfo operator =(const CCourseWareInfo &cwi);
	BOOL operator ==(const CCourseWareInfo &cwi);
public:
	CString			m_strName;
	CString			m_strType;
	long			m_lSize;
	CString			m_strPath;
	CString			m_strModTime;
	CString			m_strClass;
	CString			m_strChapter;
	CString			m_strSection;
};

#endif // !defined(AFX_COURSEWAREINFO_H__EAF2A448_B64D_48B5_9757_69534F10B2F5__INCLUDED_)
