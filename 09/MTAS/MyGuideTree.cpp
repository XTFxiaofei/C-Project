// MyGuideTree.cpp : implementation file
//

#include "stdafx.h"
#include "mtas.h"
#include "mainfrm.h"
#include "MTASDoc.h"
#include "MyGuideTree.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyGuideTree

CMyGuideTree::CMyGuideTree()
{
	m_method.SetTree(this);
	m_strPathCurSel = _T("");
	m_pCwi = NULL;
	m_bRClick = FALSE;
}

CMyGuideTree::~CMyGuideTree()
{
}

void CMyGuideTree::UpdateDisplay()
{
	m_method.UpdateTree();
}

BEGIN_MESSAGE_MAP(CMyGuideTree, VividTree)
	//{{AFX_MSG_MAP(CMyGuideTree)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, OnSelchangedTree)
	ON_WM_LBUTTONDBLCLK()
	ON_NOTIFY_REFLECT(NM_RCLICK, OnRclickTree)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_ADD_CLASS, OnAddClass)
	ON_COMMAND(ID_ADD_CHAPTER, OnAddChapter)
	ON_COMMAND(ID_ADD_SECTION, OnAddSection)
	ON_COMMAND(ID_ADD_COURSEWARE, OnAddCourseware)
	ON_COMMAND(ID_OPEN_COURSEWARE, OnOpenCourseware)
	ON_COMMAND(ID_OPEN_COURSEWARE_DIR, OnOpenCoursewareDir)
	ON_COMMAND(ID_DEL_COURSEWARE, OnDelCourseware)
	ON_COMMAND(ID_DEL_SECTION, OnDelSection)
	ON_COMMAND(ID_DEL_CHAPTER, OnDelChapter)
	ON_COMMAND(ID_DEL_CLASS, OnDelClass)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_ADD_MULTI_COURSEWARE, OnAddMultiCourseware)
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



BOOL CMyGuideTree::PreTranslateMessage( MSG* pMsg )
{
	return VividTree::PreTranslateMessage(pMsg);
}

/////////////////////////////////////////////////////////////////////////////
// CMyGuideTree message handlers

void CMyGuideTree::OnSelchangedTree(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	HTREEITEM hItem = GetSelectedItem();
	CString strName = GetItemText(hItem);
	m_pCwi = m_method.FindCourseWareInfo(hItem, strName);

	CMainFrame* pMainWnd = GetMainFrame();
	CMTASDoc* pDoc = (CMTASDoc*)pMainWnd->GetActiveDocument();
	if(m_pCwi) {
		CMainFrame* pMainWnd = GetMainFrame();
		pDoc->m_cwiCurSel = *m_pCwi;
	} else {		
		pDoc->m_cwiCurSel.m_strName    = _T("");
		pDoc->m_cwiCurSel.m_strType    = _T("");
		pDoc->m_cwiCurSel.m_lSize      = 0;
		pDoc->m_cwiCurSel.m_strPath    = _T("");
		pDoc->m_cwiCurSel.m_strModTime = _T("");
		pDoc->m_cwiCurSel.m_strClass   = _T("");
		pDoc->m_cwiCurSel.m_strChapter = _T("");
		pDoc->m_cwiCurSel.m_strSection = _T("");	
	}

	*pResult = 0;

	return;
}

void CMyGuideTree::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	if(!m_pCwi)	return;
	GetCourseWareManager().OpenCourseWare(*m_pCwi);

	VividTree::OnLButtonDblClk(nFlags, point);
}


void CMyGuideTree::OnLButtonDown(UINT nFlags, CPoint point) 
{
	ClickSound sound;

	CPoint   pt;  
	GetCursorPos(&pt);  
	HTREEITEM   hItem = HitTest(pt);  
	SelectItem(hItem);   

	hItem = GetSelectedItem();
	m_pCwi = hItem ? m_method.FindCourseWareInfo(hItem, GetItemText(hItem)) : NULL;

	CMainFrame* pMainWnd = GetMainFrame();
	CMTASDoc* pDoc = (CMTASDoc*)pMainWnd->GetActiveDocument();
	if(m_pCwi) {
		pDoc->m_cwiCurSel = *m_pCwi;
	} else {		
		CCourseWareInfo cwi;
		pDoc->m_cwiCurSel = cwi;
	}

	VividTree::OnLButtonDown(nFlags, point);
}

void CMyGuideTree::OnRclickTree(NMHDR* pNMHDR, LRESULT* pResult)
{
	ClickSound sound;

	CPoint   pt;  
	GetCursorPos(&pt);  
	ScreenToClient(&pt);
	HTREEITEM   hItem = HitTest(pt);  
	SelectItem(hItem);   

	hItem = GetSelectedItem();
	m_pCwi = hItem ? m_method.FindCourseWareInfo(hItem, GetItemText(hItem)) : NULL;

	CMainFrame* pMainWnd = GetMainFrame();
	CMTASDoc* pDoc = (CMTASDoc*)pMainWnd->GetActiveDocument();
	if(m_pCwi) {
		pDoc->m_cwiCurSel = *m_pCwi;
	} else {		
		CCourseWareInfo cwi;
		pDoc->m_cwiCurSel = cwi;
	}

	//	判断选定item的层数
	int nCount = 0;
	while(hItem) {		
		hItem = GetParentItem(hItem);
		nCount++;
	} 
	//	根据不同层数弹出不同的菜单
	ClientToScreen(&pt);
	m_treeMenu.GetSubMenu(nCount)->TrackPopupMenu(TPM_LEFTALIGN, pt.x, pt.y, this);

	*pResult = 0;
}

void CMyGuideTree::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	m_treeMenu.GetSubMenu(4)->TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, this);	
}

void CMyGuideTree::OnAddClass() 
{
	CAddClassDlg dlg;
	if(dlg.DoModal() != IDOK)
		return;

	GetCourseManager().AddClass(dlg.m_strClassName, FALSE);
	GetCourseManager().UpdateDisplay(this);
}

void CMyGuideTree::OnAddChapter() 
{	
	HTREEITEM hItem = GetSelectedItem();
	CString strClassName = GetItemText(hItem);

	CAddChapterDlg dlg;
	dlg.m_strClassName = strClassName;
	if(dlg.DoModal() != IDOK)
		return;

	GetCourseManager().AddChapter(dlg.m_strClassName, dlg.m_strChapterName, FALSE);
	GetCourseManager().UpdateDisplay(this);
}

void CMyGuideTree::OnAddSection() 
{
	HTREEITEM hItem = GetSelectedItem();
	CString strChapterName = GetItemText(hItem);
	CString strClassName = GetItemText(GetParentItem(hItem));

	CAddSectionDlg dlg;
	dlg.m_strClassName   = strClassName;
	dlg.m_strChapterName = strChapterName;
	if(dlg.DoModal() != IDOK)
		return;

	GetCourseManager().AddSection(
		dlg.m_strClassName, dlg.m_strChapterName, dlg.m_strSectionName, FALSE);
	GetCourseManager().UpdateDisplay(this);
}

void CMyGuideTree::OnAddCourseware() 
{
	HTREEITEM hItem = GetSelectedItem();
	CString strSection = GetItemText(hItem);
	hItem = GetParentItem(hItem);
	CString strChapter = GetItemText(hItem);
	hItem = GetParentItem(hItem);
	CString strClass = GetItemText(hItem);

	CAddCoursewareDlg2 dlg;
	dlg.m_strClass = strClass;
	dlg.m_strChapter = strChapter;
	dlg.m_strSection = strSection;
	if(dlg.DoModal() != IDOK)
		return;

	GetCourseWareManager().AddCourseWare(dlg.m_cwi);
}

void CMyGuideTree::OnOpenCourseware() 
{
	if(!m_pCwi)	return;
	GetCourseWareManager().OpenCourseWare(*m_pCwi);
}

void CMyGuideTree::OnOpenCoursewareDir() 
{
	if(!m_pCwi)	return;
	GetCourseWareManager().OpenCourseWareDir(m_pCwi->m_strPath);
}

void CMyGuideTree::OnDelCourseware() 
{
	CString strAsk = _T("真的要删除该课件吗?");
	int nRet = MessageBox(strAsk, _T("删除提示"), MB_YESNO | MB_ICONQUESTION);
	if(nRet == IDNO)
		return;

	if(!m_pCwi)	return;
	GetCourseWareManager().DeleteCourseWare(m_pCwi->m_strPath);
}

void CMyGuideTree::OnDelSection() 
{
	CString strAsk = _T("该操作将同时删除该节所关联的课件\n真的要删除该节吗?");
	int nRet = MessageBox(strAsk, _T("删除提示"), MB_YESNO | MB_ICONQUESTION);
	if(nRet == IDNO)
		return;

	HTREEITEM hItem = GetSelectedItem();
	CString strSection = GetItemText(hItem);
	hItem = GetParentItem(hItem);
	CString strChapter = GetItemText(hItem);
	hItem = GetParentItem(hItem);
	CString strClass = GetItemText(hItem);
	GetCourseManager().DeleteSection(strClass, strChapter, strSection);
	GetCourseManager().UpdateDisplay(this);
}

void CMyGuideTree::OnDelChapter() 
{
	CString strAsk = _T("该操作将同时删除该章所关联的节\n真的要删除该章吗?");
	int nRet = MessageBox(strAsk, _T("删除提示"), MB_YESNO | MB_ICONQUESTION);
	if(nRet == IDNO)
		return;

	HTREEITEM hItem = GetSelectedItem();
	CString strChapter = GetItemText(hItem);
	hItem = GetParentItem(hItem);
	CString strClass = GetItemText(hItem);

	GetCourseManager().DeleteChapter(strClass, strChapter);
}

void CMyGuideTree::OnDelClass() 
{
	CString strAsk = _T("该操作将同时删除该课程所关联的章\n真的要删除该课程吗?");
	int nRet = MessageBox(strAsk, _T("删除提示"), MB_YESNO | MB_ICONQUESTION);
	if(nRet == IDNO)
		return;

	HTREEITEM hItem = GetSelectedItem();
	CString strClass = GetItemText(hItem);

	GetCourseManager().DeleteClass(strClass);
}

int CMyGuideTree::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (VividTree::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	m_treeMenu.LoadMenu(IDR_TREE_MENU);	
	((CNewMenu*)m_treeMenu.GetSubMenu(0))->LoadToolBar(IDR_TOOLBAR_FOR_TREE_CONTEXT);
	((CNewMenu*)m_treeMenu.GetSubMenu(1))->LoadToolBar(IDR_TOOLBAR_FOR_TREE_CLASS);
	((CNewMenu*)m_treeMenu.GetSubMenu(2))->LoadToolBar(IDR_TOOLBAR_FOR_TREE_CHAPTER);
	((CNewMenu*)m_treeMenu.GetSubMenu(3))->LoadToolBar(IDR_TOOLBAR_FOR_TREE_SECTION);
	((CNewMenu*)m_treeMenu.GetSubMenu(4))->LoadToolBar(IDR_TOOLBAR_FOR_TREE_COURSEWARE);

	return 0;
}


void CMyGuideTree::OnAddMultiCourseware() 
{
	HTREEITEM hItem = GetSelectedItem();
	CString strSection = GetItemText(hItem);
	hItem = GetParentItem(hItem);
	CString strChapter = GetItemText(hItem);
	hItem = GetParentItem(hItem);
	CString strClass = GetItemText(hItem);

	CAddCoursewareDlg3 dlg;
	dlg.m_strClass = strClass;
	dlg.m_strChapter = strChapter;
	dlg.m_strSection = strSection;
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

void CMyGuideTree::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	if(nChar == VK_DELETE) {
		//	判断选定item的层数
		HTREEITEM   hItem = GetSelectedItem();
		int nCount = 0;
		while(hItem) {		
			hItem = GetParentItem(hItem);
			nCount++;
		} 
		switch(nCount) {
		case 0:
			//	do nothing
			break;
		case 1:
			OnDelClass();
			break;
		case 2:
			OnDelChapter();
			break;
		case 3:
			OnDelSection();
			break;
		case 4:
			OnDelCourseware();
			break;		
		}
	}
	
	VividTree::OnKeyDown(nChar, nRepCnt, nFlags);
}
