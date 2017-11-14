// MyListCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "HCDB.h"
#include "MyListCtrl.h"
#include "ForeMange.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyListCtrl

CMyListCtrl::CMyListCtrl()
{
}

CMyListCtrl::~CMyListCtrl()
{
}


BEGIN_MESSAGE_MAP(CMyListCtrl, CListCtrl)
	//{{AFX_MSG_MAP(CMyListCtrl)
	ON_WM_CREATE()
	ON_NOTIFY_REFLECT(NM_KILLFOCUS, OnKillfocus)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyListCtrl message handlers

void CMyListCtrl::DeleteItems()
{
	itemcount=GetItemCount();
    CForeMange *cwnd=(CForeMange *)GetParent();
	if(cwnd->m_enter)
      DeleteItem(cwnd->m_alreadynum);
	else
      DeleteItem(cwnd->m_alreadynum-1);
}

int CMyListCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CListCtrl::OnCreate(lpCreateStruct) == -1)
		return -1;
	SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_ONECLICKACTIVATE);
	// TODO: Add your specialized creation code here
	
	return 0;
}

void CMyListCtrl::OnKillfocus(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}
