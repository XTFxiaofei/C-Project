// DlgListCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "mtas.h"
#include "DlgListCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgListCtrl

CDlgListCtrl::CDlgListCtrl()
{
}

CDlgListCtrl::~CDlgListCtrl()
{
}


BEGIN_MESSAGE_MAP(CDlgListCtrl, CMyListCtrl)
	//{{AFX_MSG_MAP(CDlgListCtrl)
	ON_WM_CREATE()
	ON_NOTIFY_REFLECT(LVN_COLUMNCLICK, OnColumnclick)
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgListCtrl message handlers

int CDlgListCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CMyListCtrl::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	return 0;
}

void CDlgListCtrl::InitListCtrl()
{
	InsertColumn(0, _T("课件名"), LVCFMT_LEFT, 100);
	InsertColumn(1, _T("课程"), LVCFMT_CENTER, 70);
	InsertColumn(2, _T("章"),   LVCFMT_CENTER, 50);
	InsertColumn(3, _T("节"),   LVCFMT_CENTER, 50);
	InsertColumn(4, _T("类型"), LVCFMT_CENTER, 50);
	InsertColumn(5, _T("大小"), LVCFMT_CENTER, 60);
	InsertColumn(6, _T("最后修改时间"), LVCFMT_CENTER, 100);
	InsertColumn(7, _T("位置"), LVCFMT_CENTER, 350);
}

void CDlgListCtrl::FillListCtrl(vector<CCourseWareInfo>& vecCwi)
{
	MergeVector(m_vecCwi, vecCwi);

	int nItem = 0;
	for(i_vec_cwi iter = m_vecCwi.begin(); iter != m_vecCwi.end(); ++iter) {
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


void CDlgListCtrl::MergeVector(vec_cwi &vec1, vec_cwi &vec2)
{
	for(i_vec_cwi iter2 = vec2.begin(); iter2 != vec2.end(); ++iter2) {
		BOOL bHasAlready = FALSE;
		for(i_vec_cwi iter1 = vec1.begin(); iter1 != vec1.end(); ++iter1) {
			if(*iter2 == *iter1) {
				bHasAlready = TRUE;
				break;
			}
		}
		if(!bHasAlready)
			vec1.push_back(*iter2);
	}
}

void CDlgListCtrl::UpdateDisplay()
{

}

void CDlgListCtrl::OnColumnclick(NMHDR* pNMHDR, LRESULT* pResult) 
{
	CMyListCtrl::OnColumnclick(pNMHDR, pResult);
	
	*pResult = 0;
}
	
void CDlgListCtrl::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	if(nChar == VK_DELETE) {
		int nItem = GetNextItem(-1, LVNI_SELECTED);
		DeleteFromList(nItem);
	}
	
	CListCtrl::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CDlgListCtrl::DeleteFromList(int nItemDeleted)
{
	CCourseWareInfo cwi;
	FillCourseWareInfo(cwi, nItemDeleted);

	for(vector<CCourseWareInfo>::iterator iter = m_vecCwi.begin(); 
			iter != m_vecCwi.end(); ++iter) 
	{
		if(cwi == *iter) {
			m_vecCwi.erase(iter);
			DeleteItem(nItemDeleted);
			break;
		}
	}
}
