// ourseWareManager.cpp: implementation of the CourseWareManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "mtas.h"
#include "CourseWareManager.h"
#include "AddCourseWareDlg.h"
#include "mainfrm.h"
#include "PptView.h"
#include "FlashView.h"
#include "WordView.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CourseWareManager::CourseWareManager()
{
	m_rsCourseWare.SetDatabase(&theDB);
}

CourseWareManager::~CourseWareManager()
{
}

int CourseWareManager::AddCourseWare(const CCourseWareInfo &cwi, BOOL bRePaint)
{
	if(!m_rsCourseWare.Insert(cwi))
		return 0;

	if(bRePaint)
		UpdateAllDisplay();

	return 1;
}

int CourseWareManager::DeleteCourseWare(const CString &strPath, BOOL bRePaint)
{
	CString strSQL;
	strSQL.Format(_T("SELECT * FROM `cw` WHERE `path`='%s'"), strPath);
	if(!m_rsCourseWare.Delete(strSQL))
		return 0;

	if(bRePaint)
		UpdateAllDisplay();

	return 1;
}

int CourseWareManager::OpenCourseWare(const CCourseWareInfo &cwi)
{
	CMainFrame* pMainWnd = (CMainFrame*)AfxGetMainWnd();

	if(cwi.m_strType == _T("ppt")) {
		CPptView* pView = new CPptView;
		if(!pView->Create(NULL, NULL, WS_CHILD | WS_VISIBLE, 
				CRect(0, 0, 0, 0), pMainWnd, AFX_IDW_PANE_FIRST))
			return 0;

		pView->SetLabel(cwi.m_strName);
		pMainWnd->AddView(cwi.m_strName, pView, _T("ppt"));
		pView->AddNewCntrItemFromFile(cwi.m_strPath);
		pView->SwitchToThisCntrItem();
	} 
	else if(cwi.m_strType == _T("doc")) {
		CWordView* pView = new CWordView;
		if(!pView->Create(NULL, NULL, WS_CHILD | WS_VISIBLE, 
				CRect(0, 0, 0, 0), pMainWnd, AFX_IDW_PANE_FIRST))
			return 0;

		pView->SetLabel(cwi.m_strName);
		pMainWnd->AddView(cwi.m_strName, pView, _T("doc"));
		pView->AddNewCntrItemFromFile(cwi.m_strPath);
		pView->SwitchToThisCntrItem();
	}
	else if(cwi.m_strType == _T("swf")) {
		CFlashView* pView = new CFlashView;
		if(!pView->Create(NULL, NULL, WS_CHILD | WS_VISIBLE, 
				CRect(0, 0, 0, 0), pMainWnd, AFX_IDW_PANE_FIRST))
			return 0;

		pView->SwitchToThisCntrItem();
		pView->SetLabel(cwi.m_strName);
		pMainWnd->AddView(cwi.m_strName, pView, _T("swf"));
		pView->LoadMovie(cwi.m_strPath);
		pView->Stop();
	}

	return 1;
}

int CourseWareManager::OpenCourseWareDir(const CString &strPath)
{
	int nIndex = strPath.ReverseFind(_T('\\'));
	CString strDirPath = strPath.Left(nIndex);
	ShellExecute(AfxGetMainWnd()->m_hWnd, NULL, strDirPath, NULL, NULL, SW_SHOW);

	return 1;
}

void CourseWareManager::AddUpdateWindow(IUpdate *pUpdate)
{
	m_vecUpdatePointers.push_back(pUpdate);
}

void CourseWareManager::UpdateAllDisplay(IUpdate *pExcept)
{
	for(vector<IUpdate*>::iterator iter = m_vecUpdatePointers.begin();
		iter != m_vecUpdatePointers.end(); ++iter)
	{
		if(*iter == pExcept)
			continue;
		(*iter)->UpdateDisplay();
	}
}

void CourseWareManager::UpdateDisplay(IUpdate *pUpdate)
{
	ASSERT(pUpdate);
	pUpdate->UpdateDisplay();
}
