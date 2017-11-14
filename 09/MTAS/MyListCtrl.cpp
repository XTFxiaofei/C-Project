// MyListCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "mtas.h"
#include "MyListCtrl.h"
#include "mainfrm.h"
#include "mtasview.h"
#include "CntrItem.h"
#include "MTASDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyListCtrl

CMyListCtrl::CMyListCtrl()
{
	m_bAsc = TRUE;
	m_strLastClick = _T("");
}

CMyListCtrl::~CMyListCtrl()
{
}


BEGIN_MESSAGE_MAP(CMyListCtrl, CListCtrl)
	//{{AFX_MSG_MAP(CMyListCtrl)
	ON_WM_CREATE()
	ON_NOTIFY_REFLECT(NM_CUSTOMDRAW, OnCustomdrawList)	
	ON_NOTIFY_REFLECT(LVN_COLUMNCLICK, OnColumnclick)
	ON_WM_LBUTTONDOWN()
	ON_NOTIFY_REFLECT(NM_RCLICK, OnRclick)
	ON_NOTIFY_REFLECT(NM_CLICK, OnClick)
	ON_WM_KEYDOWN()
	ON_NOTIFY_REFLECT(LVN_ITEMCHANGED, OnItemchanged)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyListCtrl message handlers

void CMyListCtrl::InitListCtrl(const CString &strSQL)
{	
	InsertColumn(0, _T("课件名"), LVCFMT_LEFT, 100);
	InsertColumn(1, _T("课程"), LVCFMT_CENTER, 70);
	InsertColumn(2, _T("章"),   LVCFMT_CENTER, 50);
	InsertColumn(3, _T("节"),   LVCFMT_CENTER, 50);
	InsertColumn(4, _T("类型"), LVCFMT_CENTER, 50);
	InsertColumn(5, _T("大小"), LVCFMT_CENTER, 60);
	InsertColumn(6, _T("最后修改时间"), LVCFMT_CENTER, 100);
	InsertColumn(7, _T("位置"), LVCFMT_CENTER, 300);

	FillListCtrl(strSQL);
}

void CMyListCtrl::FillListCtrl(const CString &strSQL, const CString& strSort)
{
	vec_cwi vecCWInfo;
	CCourseWareRecordset rscw(&theDB);
	if(!rscw.Query(strSQL, vecCWInfo, strSort))
		return;
	int nItem = 0;
	for(i_vec_cwi iter = vecCWInfo.begin(); iter != vecCWInfo.end(); ++iter) {
		CString strSize;
		strSize.Format(_T("%ldk"), iter->m_lSize / 1024);
		InsertItem(nItem, iter->m_strName);
		SetItemText(nItem, 1, iter->m_strClass);
		SetItemText(nItem, 2, iter->m_strChapter);
		SetItemText(nItem, 3, iter->m_strSection);
		SetItemText(nItem, 4, iter->m_strType);
		SetItemText(nItem, 5, strSize);
		SetItemText(nItem, 6, iter->m_strModTime);
		SetItemText(nItem, 7, iter->m_strPath);
		nItem++;
	}
}

void CMyListCtrl::FillCourseWareInfo(CCourseWareInfo &cwi, int nItem)
{
	cwi.m_strName    = GetItemText(nItem, 0);
	cwi.m_strClass   = GetItemText(nItem, 1);
	cwi.m_strChapter = GetItemText(nItem, 2);
	cwi.m_strSection = GetItemText(nItem, 3);
	cwi.m_strType    = GetItemText(nItem, 4);
	cwi.m_lSize      = atoi(GetItemText(nItem, 5));
	cwi.m_strModTime = GetItemText(nItem, 6);
    cwi.m_strPath    = GetItemText(nItem, 7);
}

BOOL CMyListCtrl::PreCreateWindow(CREATESTRUCT& cs) 
{
	return CListCtrl::PreCreateWindow(cs);
}

int CMyListCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CListCtrl::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_HEADERDRAGDROP);
    m_imglist.Create (16, 16, ILC_COLOR16 | ILC_MASK, 4, 1);

	m_listMenu.LoadMenu(IDR_LIST_CTRL_MENU);

	return 0;
}

void CMyListCtrl::OnCustomdrawList(NMHDR* pNMHDR, LRESULT* pResult)
{
	NMLVCUSTOMDRAW* pLVCD = reinterpret_cast<NMLVCUSTOMDRAW*>( pNMHDR );
    
    *pResult = 0;

    // Request item-specific notifications if this is the
    // beginning of the paint cycle.

    if (CDDS_PREPAINT == pLVCD->nmcd.dwDrawStage) {
        *pResult = CDRF_NOTIFYITEMDRAW;
    } 
	else if (CDDS_ITEMPREPAINT == pLVCD->nmcd.dwDrawStage) {
		int nItem = static_cast<int>(pLVCD->nmcd.dwItemSpec);
		pLVCD->clrTextBk =  nItem % 2 ? RGB(240, 240, 240) : RGB(255, 255, 255);
        *pResult = CDRF_NOTIFYPOSTPAINT;
    } 
	else if ( CDDS_ITEMPOSTPAINT == pLVCD->nmcd.dwDrawStage ) {
		// If this item is selected, re-draw the icon in its normal
        // color (not blended with the highlight color).
        LVITEM rItem;
        int    nItem = static_cast<int>( pLVCD->nmcd.dwItemSpec );
        // Get the image index and state of this item.  Note that we need to
        // check the selected state manually.  The docs _say_ that the
        // item's state is in pLVCD->nmcd.uItemState, but during my testing
        // it was always equal to 0x0201, which doesn't make sense, since
        // the max CDIS_* constant in commctrl.h is 0x0100.
        ZeroMemory(&rItem, sizeof(LVITEM));
        rItem.mask  = LVIF_IMAGE | LVIF_STATE;
        rItem.iItem = nItem;
        rItem.stateMask = LVIS_SELECTED;
        GetItem( &rItem );

        // If this item is selected, redraw the icon with its normal colors.
        if ( rItem.state & LVIS_SELECTED ) {
            CDC*  pDC = CDC::FromHandle (pLVCD->nmcd.hdc);
            CRect rcIcon;
            // Get the rect that holds the item's icon.
            GetItemRect (nItem, &rcIcon, LVIR_ICON);
            // Draw the icon.
			CPoint pt = rcIcon.TopLeft();
            m_imglist.Draw (pDC, rItem.iImage, pt,
                             ILD_TRANSPARENT);

            *pResult = CDRF_SKIPDEFAULT;
        }
    }
}


void CMyListCtrl::OnColumnclick(NMHDR* pNMHDR, LRESULT* pResult) 
{
	ClickSound sound;	

	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;

	// Get the name of the selected column
	CString  strClick;
	LVCOLUMN lvColumn;
	lvColumn.mask = LVCF_TEXT;
	lvColumn.pszText = strClick.GetBuffer(255);
	lvColumn.cchTextMax = 255;
	GetColumn(pNMListView->iSubItem, &lvColumn);

	if(strClick == _T("课件名"))
		strClick = _T("name");
	else if(strClick == _T("课程"))
		strClick = _T("class");
	else if(strClick == _T("章"))
		strClick = _T("chapter");
	else if(strClick == _T("节"))
		strClick = _T("section");
	else if(strClick == _T("类型"))
		strClick = _T("type");
	else if(strClick == _T("大小"))
		strClick = _T("class");
	else if(strClick == _T("最后修改时间"))
		strClick = _T("modtime");
	else if(strClick == _T("位置"))
		strClick = _T("path");

	// decide the sequence
	if( m_strLastClick != strClick )
		m_strLastClick = strClick;
	m_bAsc = !m_bAsc;

	*pResult = 0;
}

void CMyListCtrl::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CListCtrl::OnLButtonDown(nFlags, point);

	int nItem = GetNextItem(-1, LVNI_SELECTED);
	CMainFrame* pMainWnd = GetMainFrame();
	CMTASDoc* pDoc = (CMTASDoc*)pMainWnd->GetActiveDocument();
	if(nItem == -1) {
		pDoc->m_cwiCurSel.m_strName    = _T("");
		pDoc->m_cwiCurSel.m_strType    = _T("");
		pDoc->m_cwiCurSel.m_lSize      = 0;
		pDoc->m_cwiCurSel.m_strPath    = _T("");
		pDoc->m_cwiCurSel.m_strModTime = _T("");
		pDoc->m_cwiCurSel.m_strClass   = _T("");
		pDoc->m_cwiCurSel.m_strChapter = _T("");
		pDoc->m_cwiCurSel.m_strSection = _T("");
	}
	FillCourseWareInfo(pDoc->m_cwiCurSel, nItem);
}

void CMyListCtrl::OnRclick(NMHDR* pNMHDR, LRESULT* pResult) 
{
	*pResult = 0;
}

void CMyListCtrl::OnClick(NMHDR* pNMHDR, LRESULT* pResult) 
{
	*pResult = 0;
}

void CMyListCtrl::AddCourseware()
{
	CAddCoursewareDlg dlg;
	if(dlg.DoModal() != IDOK)
		return;

	CourseManager& cManager = GetCourseManager();
	if(!dlg.m_strClass.IsEmpty() && dlg.m_strClass != _T("未指定"))
		cManager.AddClass(dlg.m_strClass, FALSE);
	if(!dlg.m_strChapter.IsEmpty() && dlg.m_strChapter != _T("未指定"))
		cManager.AddChapter(dlg.m_strClass, dlg.m_strChapter, FALSE);
	if(!dlg.m_strSection.IsEmpty() && dlg.m_strSection != _T("未指定"))
		cManager.AddSection(dlg.m_strClass, dlg.m_strChapter, dlg.m_strSection, FALSE);

	CourseWareManager& cwManager = GetCourseWareManager();
	cwManager.AddCourseWare(dlg.m_cwi);
}

void CMyListCtrl::AddMutiCourseware()
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

void CMyListCtrl::DeleteCourseware()
{
	int nItem = GetNextItem(-1, LVNI_SELECTED);
	CString strPathName = GetItemText(nItem, 7);
	if(strPathName.IsEmpty()) {
		MessageBox(_T("请先选定要删除的课件"), _T("错误!"), MB_ICONEXCLAMATION);
		return;
	}
	CString strAsk = _T("真的要删除该课件吗?");
	int nRet = MessageBox(strAsk, _T("删除提示"), MB_YESNO | MB_ICONQUESTION);
	if(nRet == IDNO)
		return;

	CourseWareManager& cwManager = GetCourseWareManager();
	cwManager.DeleteCourseWare(strPathName);
}	

void CMyListCtrl::OpenCoursewareDir()
{
	int nItem = GetNextItem(-1, LVNI_SELECTED);
	CString strFilePath = GetItemText(nItem, 7);	
	CourseWareManager& cwManager = GetCourseWareManager();
	cwManager.OpenCourseWareDir(strFilePath);
}

void CMyListCtrl::OpenCourseware()
{
	int nItem = GetNextItem(-1, LVNI_SELECTED);
	if(nItem == -1)	
		return;

	CCourseWareInfo cwi;
	FillCourseWareInfo(cwi, nItem);
	CourseWareManager& cwManager = GetCourseWareManager();
	cwManager.OpenCourseWare(cwi);
}

void CMyListCtrl::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	if(nChar == VK_DELETE) {
		DeleteCourseware();
	}

	CListCtrl::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CMyListCtrl::OnItemchanged(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	
	int nItem = GetNextItem(-1, LVNI_SELECTED);
	CMainFrame* pMainWnd = GetMainFrame();
	CMTASDoc* pDoc = (CMTASDoc*)pMainWnd->GetActiveDocument();
	if(nItem == -1) {
		CCourseWareInfo cwi;
		pDoc->m_cwiCurSel = cwi;		
	}
	FillCourseWareInfo(pDoc->m_cwiCurSel, nItem);

	*pResult = 0;
}
