// newListCtrl.cpp : implementation file
//

#include "stdafx.h"

#include "newListCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CnewListCtrl

CnewListCtrl::CnewListCtrl()
{
	m_nitem=-1;
	m_nsubitem=-1;
	m_nitem1=-1;
	m_nsubitem1=-1;
}

CnewListCtrl::~CnewListCtrl()
{
}


BEGIN_MESSAGE_MAP(CnewListCtrl, CListCtrl)
//{{AFX_MSG_MAP(CnewListCtrl)
ON_WM_LBUTTONDOWN()
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CnewListCtrl message handlers
void CnewListCtrl::Edit()
{
	CRect rect;
	if(GetSubItemRect(m_nitem,m_nsubitem,LVIR_LABEL,rect)==FALSE)
		return;
	int sty=WS_CHILD|WS_CLIPSIBLINGS|WS_EX_TOOLWINDOW|WS_BORDER;
	//设置编辑框样式
	if(m_edit.Create(sty,rect,this,ID_MYEDIT)==FALSE)
		//创建编辑框
		return;
	CString txt=GetItemText(m_nitem,m_nsubitem);
	m_edit.SetWindowText(txt);//设置编辑框的内容
	m_edit.SetFocus();
	m_edit.SetSel(0,-1);
	m_edit.ShowWindow(SW_SHOW);//显示编辑框
	m_nitem1=m_nitem;
	m_nsubitem1=m_nsubitem;

	
}
void CnewListCtrl::EndEdit()
{
	if(m_nitem1!=-1&&m_nsubitem1!=-1)//判断是否为初始时
	{
		CString txt;
		m_edit.GetWindowText(txt);
		SetItemText(m_nitem1,m_nsubitem1,txt);//设置为编辑后的文件内容
		m_edit.DestroyWindow();
	}
}

void CnewListCtrl::OnLButtonDown(UINT nFlags, CPoint point) 
{
	LVHITTESTINFO testinfo;
	testinfo.pt.x=point.x;
	testinfo.pt.y=point.y;
	testinfo.flags=LVHT_ONITEMLABEL;//强调点击必是标题
	if(SubItemHitTest(&testinfo)<0)
		return;
	m_nitem=testinfo.iItem;//得到行号
	m_nsubitem=testinfo.iSubItem;//得到列号
	if(m_nitem==m_nitem1&&m_nsubitem==m_nsubitem1)//判断是否是前一点击的行列
		return;
	else
	{
		EndEdit();//结束编辑框
		Edit();//创建新的编辑框对列表框进行编辑
		
		// TODO: Add your message handler code here and/or call default
	}
		CListCtrl::OnLButtonDown(nFlags, point);
	}
