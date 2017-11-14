// MTASDoc.cpp : implementation of the CMTASDoc class
//

#include "stdafx.h"
#include "MTAS.h"

#include "MTASDoc.h"
#include "CntrItem.h"
#include "mainfrm.h"
#include "MTASView.h"
#include "shockwaveflash.h"
#include "WordView.h"
#include "PptView.h"
#include "FlashView.h"
#include "MyListCtrl.h"
#include "WordListCtrl.h"
#include "PptListCtrl.h"
#include "FlashListCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#if defined (_MSC_VER)
#pragma warning(disable: 4786)
#endif

using namespace std;

/////////////////////////////////////////////////////////////////////////////
// CMTASDoc

IMPLEMENT_DYNCREATE(CMTASDoc, COleDocument)

BEGIN_MESSAGE_MAP(CMTASDoc, COleDocument)
	//{{AFX_MSG_MAP(CMTASDoc)
	ON_COMMAND(ID_PLAY_FLASH, OnPlayFlash)
	ON_UPDATE_COMMAND_UI(ID_PLAY_FLASH, OnUpdatePlayFlash)
	ON_COMMAND(ID_PAUSE_FLASH, OnPauseFlash)
	ON_UPDATE_COMMAND_UI(ID_PAUSE_FLASH, OnUpdatePauseFlash)
	ON_COMMAND(ID_STOP_FLASH, OnStopFlash)
	ON_UPDATE_COMMAND_UI(ID_STOP_FLASH, OnUpdateStopFlash)
	ON_COMMAND(ID_FULL_SCREEN, OnFullScreen)
	ON_UPDATE_COMMAND_UI(ID_FULL_SCREEN, OnUpdateFullScreen)
	ON_COMMAND(ID_NORMAL_SCREEN, OnNormalScreen)
	ON_UPDATE_COMMAND_UI(ID_NORMAL_SCREEN, OnUpdateNormalScreen)
	ON_COMMAND(ID_NAVIGATE_FORWARD, OnNavigateForward)
	ON_UPDATE_COMMAND_UI(ID_NAVIGATE_FORWARD, OnUpdateNavigateForward)
	ON_COMMAND(ID_NAVIGATE_BACKWARD, OnNavigateBackward)
	ON_UPDATE_COMMAND_UI(ID_NAVIGATE_BACKWARD, OnUpdateNavigateBackward)
	ON_COMMAND(ID_NAVIGATE_STOP, OnNavigateStop)
	ON_UPDATE_COMMAND_UI(ID_NAVIGATE_STOP, OnUpdateNavigateStop)
	ON_COMMAND(ID_NAVIGATE_REFRESH, OnNavigateRefresh)
	ON_UPDATE_COMMAND_UI(ID_NAVIGATE_REFRESH, OnUpdateNavigateRefresh)
	ON_COMMAND(ID_NAVIGATE_GOTO, OnNavigateGoto)
	ON_COMMAND(ID_OPEN_CW, OnOpenCw)
	ON_COMMAND(ID_ADD_CW, OnAddCw)
	ON_COMMAND(ID_DEL_CW, OnDelCw)
	ON_COMMAND(ID_OPEN_CW_DIR, OnOpenCwDir)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_UPDATE_COMMAND_UI(ID_DEL_CW, OnUpdateDelCw)
	ON_UPDATE_COMMAND_UI(ID_OPEN_CW_DIR, OnUpdateOpenCwDir)
	ON_COMMAND(ID_ADD_MULTI_CW, OnAddMultiCw)
	ON_COMMAND(ID_COURSE_ADD_CHAPTER, OnCourseAddChapter)
	ON_COMMAND(ID_COURSE_ADD_SECTION, OnCourseAddSection)
	ON_COMMAND(ID_COURSE_ADD_CLASS, OnCourseAddClass)
	//}}AFX_MSG_MAP
	// Enable default OLE container implementation
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, COleDocument::OnUpdatePasteMenu)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE_LINK, COleDocument::OnUpdatePasteLinkMenu)
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_CONVERT, COleDocument::OnUpdateObjectVerbMenu)
	ON_COMMAND(ID_OLE_EDIT_CONVERT, COleDocument::OnEditConvert)
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_LINKS, COleDocument::OnUpdateEditLinksMenu)
	ON_COMMAND(ID_OLE_EDIT_LINKS, COleDocument::OnEditLinks)
	ON_UPDATE_COMMAND_UI(ID_OLE_VERB_FIRST, COleDocument::OnUpdateObjectVerbMenu)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMTASDoc construction/destruction

CMTASDoc::CMTASDoc()
{
	// Use OLE compound files
	EnableCompoundFile();
	m_pFlashCtrl = NULL;
	m_bListSelected = FALSE;
	m_pListCtrlSelected = NULL;
}

CMTASDoc::~CMTASDoc()
{
}

BOOL CMTASDoc::OnNewDocument()
{
	if (!COleDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMTASDoc serialization

void CMTASDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}

	// Calling the base class COleDocument enables serialization
	//  of the container document's COleClientItem objects.
	COleDocument::Serialize(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CMTASDoc diagnostics

#ifdef _DEBUG
void CMTASDoc::AssertValid() const
{
	COleDocument::AssertValid();
}

void CMTASDoc::Dump(CDumpContext& dc) const
{
	COleDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMTASDoc commands

BOOL CMTASDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	//Open the new document
	if (!COleDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	return TRUE;
}

void CMTASDoc::OnCloseDocument()
{
	COleDocument::OnCloseDocument();
}
/*
void CMTASDoc::OnFilePrint() 
{
	CMainFrame *pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	ASSERT_VALID(pFrame);

	CView *pView = pFrame->GetActiveView();

	CPrintInfo pi;
	//Active Document containers must specify whether or not
	//to prompt the user with a print dialog.
	pi.m_dwFlags |= PRINTFLAG_PROMPTUSER;

	if(!COleDocObjectItem::OnPreparePrinting(pView,&pi,FALSE))
		return;

	if(!pView->DoPreparePrinting(&pi))
		return;

	COleDocObjectItem::OnPrint(pView,&pi,FALSE);
}

void CMTASDoc::OnFilePrintallsections() 
{
	CMainFrame *pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	ASSERT_VALID(pFrame);

	CView *pView = pFrame->GetActiveView();
	ASSERT_VALID(pView);

	CPrintInfo pi;

	if(!COleDocObjectItem::OnPreparePrinting(pView,&pi))
		return;

	if(!pView->DoPreparePrinting(&pi))
		return;

	COleDocObjectItem::OnPrint(pView,&pi);
}
*/
void CMTASDoc::OnPlayFlash() 
{
	m_pFlashCtrl->Play();
}

void CMTASDoc::OnUpdatePlayFlash(CCmdUI* pCmdUI) 
{
	CMainFrame* pMainWnd = (CMainFrame*)AfxGetMainWnd();
	CView* pView = pMainWnd->GetActiveView();
	CString strClassName = pView->GetRuntimeClass()->m_lpszClassName;
	if(strClassName == _T("CFlashView")) {
		CFlashView* pFlashView = (CFlashView*)pView;
		pCmdUI->Enable(pFlashView->m_flashWnd.IsPlaying() ? FALSE : TRUE);
	} else {
		pCmdUI->Enable(FALSE);
	}
}

void CMTASDoc::OnPauseFlash() 
{
	m_pFlashCtrl->Stop();
}

void CMTASDoc::OnUpdatePauseFlash(CCmdUI* pCmdUI) 
{
	CMainFrame* pMainWnd = (CMainFrame*)AfxGetMainWnd();
	CView* pView = pMainWnd->GetActiveView();
	CString strClassName = pView->GetRuntimeClass()->m_lpszClassName;
	if(strClassName == _T("CFlashView")) {
		CFlashView* pFlashView = (CFlashView*)pView;
		pCmdUI->Enable(pFlashView->m_flashWnd.IsPlaying() ? TRUE : FALSE);
	} else {
		pCmdUI->Enable(FALSE);
	}
}

void CMTASDoc::OnStopFlash() 
{
	m_pFlashCtrl->Rewind();
	
}

void CMTASDoc::OnUpdateStopFlash(CCmdUI* pCmdUI) 
{
	CMainFrame* pMainWnd = (CMainFrame*)AfxGetMainWnd();
	CView* pView = pMainWnd->GetActiveView();
	CString strClassName = pView->GetRuntimeClass()->m_lpszClassName;
	pCmdUI->Enable(strClassName == _T("CFlashView") ? TRUE : FALSE);
}

void CMTASDoc::OnFullScreen() 
{
	GetMainFrame()->FullScreen();
}

void CMTASDoc::OnUpdateFullScreen(CCmdUI* pCmdUI) 
{
	CMainFrame* pMainWnd = (CMainFrame*)AfxGetMainWnd();
	pCmdUI->Enable(!pMainWnd->IsFullScreen() ? TRUE : FALSE);
}

void CMTASDoc::OnNormalScreen() 
{
	GetMainFrame()->NormalScreen();
}

void CMTASDoc::OnUpdateNormalScreen(CCmdUI* pCmdUI) 
{
	CMainFrame* pMainWnd = (CMainFrame*)AfxGetMainWnd();
	pCmdUI->Enable(pMainWnd->IsFullScreen() ? TRUE : FALSE);
}

void CMTASDoc::OnNavigateForward() 
{
	ClickSound sound;
	CMainFrame* pMainWnd = (CMainFrame*)AfxGetMainWnd();
	CView* pView = pMainWnd->GetActiveView();
	CString strClassName = pView->GetRuntimeClass()->m_lpszClassName;
	if(strClassName == _T("CMTASView")) {
		CMTASView* pMTASView = (CMTASView*)pView;
		pMTASView->GoForward();
	}
}

void CMTASDoc::OnUpdateNavigateForward(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

void CMTASDoc::OnNavigateBackward() 
{
	ClickSound sound;
	CMainFrame* pMainWnd = (CMainFrame*)AfxGetMainWnd();
	CView* pView = pMainWnd->GetActiveView();
	CString strClassName = pView->GetRuntimeClass()->m_lpszClassName;
	if(strClassName == _T("CMTASView")) {
		CMTASView* pMTASView = (CMTASView*)pView;
		pMTASView->GoBack();
	}
}

void CMTASDoc::OnUpdateNavigateBackward(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

void CMTASDoc::OnNavigateStop() 
{
	ClickSound sound;
	CMainFrame* pMainWnd = (CMainFrame*)AfxGetMainWnd();
	CView* pView = pMainWnd->GetActiveView();
	CString strClassName = pView->GetRuntimeClass()->m_lpszClassName;
	if(strClassName == _T("CMTASView")) {
		CMTASView* pMTASView = (CMTASView*)pView;
		pMTASView->Stop();
	}
}

void CMTASDoc::OnUpdateNavigateStop(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

void CMTASDoc::OnNavigateRefresh() 
{
	ClickSound sound;
	CMainFrame* pMainWnd = (CMainFrame*)AfxGetMainWnd();
	CView* pView = pMainWnd->GetActiveView();
	CString strClassName = pView->GetRuntimeClass()->m_lpszClassName;
	if(strClassName == _T("CMTASView")) {
		CMTASView* pMTASView = (CMTASView*)pView;
		pMTASView->Refresh();
	}
}

void CMTASDoc::OnUpdateNavigateRefresh(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

void CMTASDoc::OnNavigateGoto() 
{
	ClickSound sound;
	CMainFrame* pMainWnd = (CMainFrame*)AfxGetMainWnd();
	CView* pView = pMainWnd->GetActiveView();
	CString strClassName = pView->GetRuntimeClass()->m_lpszClassName;
	if(strClassName == _T("CMTASView")) {
		CMTASView* pMTASView = (CMTASView*)pView;
		CString strURL;
		pMainWnd->m_wndNavigateToolBar.m_comboBox.GetWindowText(strURL);
		pMTASView->m_sUrl = strURL;
		pMTASView->Navigate2(strURL);
	}	
}

void CMTASDoc::OnOpenCw() 
{
	ClickSound sound;
	OnFileOpen();
}

void CMTASDoc::OnAddCw() 
{
	ClickSound sound;
	CAddCoursewareDlg dlg;
	if(dlg.DoModal() != IDOK)
		return;

	CourseManager& cManager = GetCourseManager();
	cManager.AddClass(dlg.m_strClass, FALSE);
	cManager.AddChapter(dlg.m_strClass, dlg.m_strChapter, FALSE);
	cManager.AddSection(dlg.m_strClass, dlg.m_strChapter, dlg.m_strSection, FALSE);

	CourseWareManager& cwManager = GetCourseWareManager();
	cwManager.AddCourseWare(dlg.m_cwi, TRUE);
}

void CMTASDoc::OnDelCw() 
{
	ClickSound sound;
	if(m_cwiCurSel.m_strPath.IsEmpty()) {
		::MessageBox(AfxGetMainWnd()->m_hWnd, _T("请先选择课件!"), _T("错误!"), MB_ICONEXCLAMATION);
		return;
	}
	CString strAsk = _T("真的要删除该课件吗?");
	int nRet = ::MessageBox(AfxGetMainWnd()->m_hWnd, strAsk, _T("删除提示"), MB_YESNO | MB_ICONQUESTION);
	if(nRet == IDNO)
		return;

	CourseWareManager& cwManager = GetCourseWareManager();
	cwManager.DeleteCourseWare(m_cwiCurSel.m_strPath);
}

void CMTASDoc::OnUpdateDelCw(CCmdUI* pCmdUI) 
{
}

void CMTASDoc::OnOpenCwDir() 
{
	ClickSound sound;
	CourseWareManager& cwManager = GetCourseWareManager();
	cwManager.OpenCourseWareDir(m_cwiCurSel.m_strPath);
}

void CMTASDoc::OnUpdateOpenCwDir(CCmdUI* pCmdUI) 
{
}

void CMTASDoc::OnFileOpen() 
{
	static char BASED_CODE szFilter[] = "PowerPoint Files (*.ppt)|*.ppt|Flash Files (*.swf)|*.swf|Word Files (*.doc)|*.doc; *.ppt|All Files (*.*)|*.*||";
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, NULL); 
	if(dlg.DoModal() != IDOK)
		return;

	CString strFileName = dlg.GetFileName(),
			strPathName = dlg.GetPathName(),
			strFileExt  = dlg.GetFileExt();
	strFileExt.MakeLower();
	CCourseWareInfo cwi;
	cwi.m_strName = strFileName;
	cwi.m_strPath = strPathName;
	cwi.m_strType = strFileExt;

	GetCourseWareManager().OpenCourseWare(cwi);
}

void CMTASDoc::OnAddMultiCw() 
{
	CAddCoursewareDlg3 dlg;
	if(dlg.DoModal() != IDOK)
		return;

	if(dlg.m_vecCwi.size() == 0)
		return;
	vec_cwi vecCwi = dlg.m_vecCwi;
	CourseManager& cManager = GetCourseManager();
	CourseWareManager& cwManager = GetCourseWareManager();
	for(i_vec_cwi iter = vecCwi.begin();
			iter != vecCwi.end(); ++iter)
	{		
		if(!iter->m_strClass.IsEmpty() && iter->m_strClass != _T("未指定"))
			cManager.AddClass(iter->m_strClass, FALSE);
		if(!dlg.m_strChapter.IsEmpty() && dlg.m_strChapter != _T("未指定"))
			cManager.AddChapter(iter->m_strClass, iter->m_strChapter, FALSE);
		if(!dlg.m_strSection.IsEmpty() && dlg.m_strSection != _T("未指定"))
			cManager.AddSection(iter->m_strClass, iter->m_strChapter, iter->m_strSection, FALSE);
		
		cwManager.AddCourseWare(*iter, FALSE);
	}
	cwManager.UpdateAllDisplay();
}

void CMTASDoc::OnCourseAddClass() 
{
	CAddClassDlg dlg;
	if(dlg.DoModal() != IDOK)
		return;

	GetCourseManager().AddClass(dlg.m_strClassName, FALSE);
	GetMainFrame()->m_wndTreeGuideBar.GetTree()->UpdateDisplay();
}

void CMTASDoc::OnCourseAddChapter() 
{
	CAddChapterDlg2 dlg;
	if(dlg.DoModal() != IDOK)
		return;

	GetCourseManager().AddChapter(dlg.m_strClassName, dlg.m_strChapterName, FALSE);
	GetMainFrame()->m_wndTreeGuideBar.GetTree()->UpdateDisplay();
}

void CMTASDoc::OnCourseAddSection() 
{
	CAddSectionDlg2 dlg;
	if(dlg.DoModal() != IDOK)
		return;

	GetCourseManager().AddSection(
		dlg.m_strClassName, dlg.m_strChapterName, dlg.m_strSectionName, FALSE);
	GetMainFrame()->m_wndTreeGuideBar.GetTree()->UpdateDisplay();
}


