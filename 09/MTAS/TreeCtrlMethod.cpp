// TreeCtrlMethod.cpp: implementation of the TreeCtrlMethod class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "mtas.h"
#include "TreeCtrlMethod.h"
using namespace std;

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

TreeCtrlMethod::TreeCtrlMethod()
{
}

TreeCtrlMethod::~TreeCtrlMethod()
{
	
}

void TreeCtrlMethod::FillTree()
{
	CClassRecordset rsClass(&theDB);
	CChapterRecordset rsChapter(&theDB);
	CSectionRecordset rsSection(&theDB);
	CCourseWareRecordset rsCourseWare(&theDB);
	HTREEITEM hClass, hChapter, hSection, hCWI;
	
	m_pTree->DeleteAllItems();
	//	insert class
	vector<ClassTableItem> vecClassTI;
	CString strSQL = _T("SELECT * FROM `class`");
	rsClass.Query(strSQL, vecClassTI);
	for(vector<ClassTableItem>::iterator iterClass = vecClassTI.begin();
		iterClass != vecClassTI.end(); ++iterClass)
	{
		if(iterClass->m_strName != _T(""))
			hClass = m_pTree->InsertItem(iterClass->m_strName, 0, 1, TVI_ROOT, TVI_LAST);
		else
			continue;

		//	insert chapter
		long lClassID = rsClass.GetClassID(iterClass->m_strName);
		vector<ChapterTableItem> vecChapterTI;
		strSQL.Format(_T("SELECT * FROM `chapter` WHERE `classid`=%ld"), lClassID);
		rsChapter.Query(strSQL, vecChapterTI);
		for(vector<ChapterTableItem>::iterator iterChapter = vecChapterTI.begin();
			iterChapter != vecChapterTI.end(); ++iterChapter)
		{
			if(iterChapter->m_strName != _T(""))
				hChapter = m_pTree->InsertItem(iterChapter->m_strName, 0, 1, hClass, TVI_LAST);
			else
				continue;

			//	insert section
			long lChapterID = rsChapter.GetChapterID(lClassID, iterChapter->m_strName);
			vector<SectionTableItem> vecSTI;
			strSQL.Format(_T("SELECT * FROM `section` WHERE `chapterid`=%ld"), lChapterID);
			rsSection.Query(strSQL, vecSTI);
			for(vector<SectionTableItem>::iterator iterSection = vecSTI.begin();
				iterSection != vecSTI.end(); ++iterSection)
			{
				if(iterSection->m_strName != _T(""))
					hSection = m_pTree->InsertItem(iterSection->m_strName, 0, 1, hChapter, TVI_LAST);
				else
					continue;

				//	insert course ware
				strSQL.Format(_T("SELECT * FROM `cw` WHERE `class`='%s' AND `chapter`='%s' AND `section`='%s'"), 
					iterClass->m_strName, iterChapter->m_strName, iterSection->m_strName
				);
				vec_cwi vecCwi;
				rsCourseWare.Query(strSQL, vecCwi);
				for(i_vec_cwi iterCwi = vecCwi.begin(); iterCwi != vecCwi.end(); ++iterCwi) {
					if(iterSection->m_strName != _T("")) {
						hCWI = m_pTree->InsertItem(iterCwi->m_strName, 0, 1, hSection, TVI_LAST);
						m_map[hCWI] = *iterCwi;
					}
				}	//	for cwi
			}	//	for section
		}	//	for chapter
	}	//	for class

	HTREEITEM hRootItem = m_pTree->GetRootItem();
	while(hRootItem) {
		m_pTree->Expand(hRootItem, TVE_EXPAND);
		hRootItem = m_pTree->GetNextSiblingItem(hRootItem);
	}
}

void TreeCtrlMethod::UpdateTree()
{
	FillTree();
}

void TreeCtrlMethod::SetTree(CTreeCtrl* pTree)
{
	m_pTree = pTree;
}

CCourseWareInfo* TreeCtrlMethod::FindCourseWareInfo(HTREEITEM hItem, const CString &strName)
{
	if(m_map[hItem].m_strName == strName)
		return &m_map[hItem];

	return NULL;
}
