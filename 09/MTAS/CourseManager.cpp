// CourseManager.cpp: implementation of the CourseManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "mtas.h"
#include "CourseManager.h"
#include "mainfrm.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CourseManager::CourseManager()
{
	m_rsClass.SetDatabase(&theDB);	
	m_rsChapter.SetDatabase(&theDB);
	m_rsSection.SetDatabase(&theDB);
}

CourseManager::~CourseManager()
{

}

void CourseManager::AddUpdateWindow(IUpdate *pUpdate)
{
	m_vecUpdatePointers.push_back(pUpdate);
}


void CourseManager::UpdateAllDisplay(IUpdate *pExcept)
{
	for(vector<IUpdate*>::iterator iter = m_vecUpdatePointers.begin();
		iter != m_vecUpdatePointers.end(); ++iter)
	{
		if(*iter == pExcept)
			continue;
		(*iter)->UpdateDisplay();
	}
}

int CourseManager::AddClass(const CString &strClass, BOOL bRePaint)
{
	ClassTableItem cti;
	cti.m_strName = strClass;
	if(!m_rsClass.Insert(cti))
		return 0;

	if(bRePaint)
		UpdateAllDisplay();

	return 1;
}

int CourseManager::AddChapter(const CString &strClass, const CString &strChapter, BOOL bRePaint)
{
	ChapterTableItem cti;
	long lClassID = m_rsClass.GetClassID(strClass);
	cti.m_lClassID = lClassID;
	cti.m_strName  = strChapter;
	if(!m_rsChapter.Insert(cti))
		return 0;

	if(bRePaint)
		UpdateAllDisplay();

	return 1;
}

int CourseManager::AddSection(const CString &strClass, const CString &strChapter, const CString &strSection, BOOL bRePaint)
{
	long lClassID = m_rsClass.GetClassID(strClass);
	long lChapterID = m_rsChapter.GetChapterID(lClassID, strChapter);

	SectionTableItem sti;
	sti.m_lChapterID = lChapterID;
	sti.m_strName  = strSection;
	if(!m_rsSection.Insert(sti))
		return 0;

	if(bRePaint)
		UpdateAllDisplay();

	return 1;
}

int CourseManager::DeleteSection(const CString &strClass, const CString &strChapter, const CString &strSection, BOOL bRePaint)
{
	long lClassID = m_rsClass.GetClassID(strClass);
	long lChapterID = m_rsChapter.GetChapterID(lClassID, strChapter);
	CString strSQL;
	strSQL.Format(_T("SELECT * FROM `section` WHERE `chapterid`=%ld AND `name`='%s'"),
		lChapterID, strSection);
	if(!m_rsSection.Delete(strSQL))
		return 0;

	CCourseWareRecordset rscw(&theDB);
	strSQL.Format(_T("SELECT * FROM `cw` WHERE `class`='%s' AND `chapter`='%s' AND `section`='%s'"), 
		strClass, strChapter, strSection);
	if(!rscw.Delete(strSQL))
		return 0;

	if(bRePaint)
		UpdateAllDisplay();

	return 1;
}

int CourseManager::DeleteChapter(const CString &strClass, const CString &strChapter, BOOL bRePaint)
{
	long lClassID = m_rsClass.GetClassID(strClass);
	long lChapterID = m_rsChapter.GetChapterID(lClassID, strChapter);
	CString strSQL;
	strSQL.Format(_T("SELECT * FROM `section` WHERE `chapterid`=%ld"), lChapterID);
	vector<SectionTableItem> vecSti;
	m_rsSection.Query(strSQL, vecSti);

	for(int i = 0; i < vecSti.size(); ++i) {
		if(!DeleteSection(strClass, strChapter, vecSti[i].m_strName))
			return 0;
	}
	
	strSQL.Format(_T("SELECT * FROM `chapter` WHERE `id`=%ld"), lChapterID);
	m_rsChapter.Delete(strSQL);

	if(bRePaint)
		UpdateAllDisplay();

	return 1;
}

int CourseManager::DeleteClass(const CString &strClass, BOOL bRePaint)
{
	long lClassID = m_rsClass.GetClassID(strClass);
	CString strSQL;
	strSQL.Format(_T("SELECT * FROM `chapter` WHERE `classid`=%ld"), lClassID);
	vector<ChapterTableItem> vecCti;
	m_rsChapter.Query(strSQL, vecCti);

	for(int i = 0; i < vecCti.size(); ++i) {
		if(!DeleteChapter(strClass, vecCti[i].m_strName))
			return 0;
	}

	strSQL.Format(_T("SELECT * FROM `class` WHERE `name`='%s'"), strClass);
	if(!m_rsClass.Delete(strSQL))
		return 0;	

	if(bRePaint)
		UpdateAllDisplay();

	return 1;
}

void CourseManager::UpdateDisplay(IUpdate *pUpdate)
{
	ASSERT(pUpdate);
	pUpdate->UpdateDisplay();
}
