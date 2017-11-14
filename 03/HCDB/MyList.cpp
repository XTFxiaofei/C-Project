// MyList.cpp : implementation file
//

#include "stdafx.h"
#include "HCDB.h"
#include "MyList.h"
#include "AnotherView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyList
#include "MyEditShowList.h"
#include "GATHEROUT.h"
CMyList::CMyList()
{
}

CMyList::~CMyList()
{
}


BEGIN_MESSAGE_MAP(CMyList, CListCtrl)
	//{{AFX_MSG_MAP(CMyList)
	ON_NOTIFY_REFLECT(LVN_ITEMCHANGED, OnItemchanged)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyList message handlers

void CMyList::OnItemchanged(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	CMyEditShowList * cwnd1=(CMyEditShowList *)GetParent();
    CAnotherView *cwnd2=(CAnotherView *)cwnd1->GetParent();
	CGATHEROUT *cwnd3=&cwnd2->cgatherout;
	int i=pNMListView->iItem;
	cwnd3->m_mercid=GetItemText(i,0);
	cwnd3->m_mercname=GetItemText(i,1);
	cwnd3->m_outprice=GetItemText(i,2);
	cwnd3->m_merctype=GetItemText(i,3);
	cwnd3->m_provid=GetItemText(i,4);
	cwnd3->m_uint=GetItemText(i,5);
	cwnd3->UpdateData(false);
	ShowWindow(false);
	*pResult = 0;
}
