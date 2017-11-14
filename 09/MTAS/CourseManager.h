// CourseManager.h: interface for the CourseManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COURSEMANAGER_H__84A40CD8_9228_4E54_966C_460765CFD4AE__INCLUDED_)
#define AFX_COURSEMANAGER_H__84A40CD8_9228_4E54_966C_460765CFD4AE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IUpdate.h"

class CourseManager : public CObject  
{
public:
	void UpdateDisplay(IUpdate* pUpdate);
	int DeleteChapter(const CString& strClass, const CString& strChapter, BOOL bRePaint = TRUE);
	int DeleteSection(const CString& strClass, const CString& strChapter, const CString& strSection, BOOL bRePaint = TRUE);
	int AddSection(const CString& strClass, const CString& strChapter, const CString& strSection, BOOL bRePaint = TRUE);
	int DeleteClass(const CString& strClass, BOOL bRePaint = TRUE);
	int AddChapter(const CString &strClass, const CString& strChapter, BOOL bRePaint = TRUE);
	int AddClass(const CString &strClass, BOOL bRePaint = TRUE);
	CourseManager();
	virtual ~CourseManager();

	void UpdateAllDisplay(IUpdate* pExcept = NULL);
	void AddUpdateWindow(IUpdate* pUpdate);

protected:
	CClassRecordset		m_rsClass;
	CChapterRecordset	m_rsChapter;
	CSectionRecordset	m_rsSection;
	std::vector<IUpdate*>	m_vecUpdatePointers;
};

#endif // !defined(AFX_COURSEMANAGER_H__84A40CD8_9228_4E54_966C_460765CFD4AE__INCLUDED_)
