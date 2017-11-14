// LeftView.cpp : implementation file
//

#include "stdafx.h"
#include "TBManager.h"
#include "LeftView.h"
#include "MainFrm.h"
#include "ADDDLG.h"
#include "QueryDlg.h"
#include "USERDLG.h"
#include "ShowCondition.h"
#include "msword.h"
#include <AtlBase.h>
#include "HandPapers.h"
#include "BACKUPDLG.h"
#include "RESTOREDLG.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLeftView

IMPLEMENT_DYNCREATE(CLeftView, CFormView)

CLeftView::CLeftView()
	: CFormView(CLeftView::IDD)
{
	str="";
	//{{AFX_DATA_INIT(CLeftView)
	m_userinformation = _T("");
	//}}AFX_DATA_INIT
}

CLeftView::~CLeftView()
{
}

void CLeftView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLeftView)
	DDX_Control(pDX, IDC_BUTTON4, m_button4);
	DDX_Control(pDX, IDC_BUTTON3, m_button3);
	DDX_Control(pDX, IDC_BUTTON2, m_button2);
	DDX_Control(pDX, IDC_BUTTON1, m_button1);
	DDX_Control(pDX, IDC_TREE1, m_tree);
	DDX_Text(pDX, IDC_USERINFOMATION, m_userinformation);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLeftView, CFormView)
	//{{AFX_MSG_MAP(CLeftView)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_NOTIFY(NM_DBLCLK, IDC_TREE1, OnDblclkTree1)
	ON_UPDATE_COMMAND_UI(ID_FILE_SAVE, OnUpdateFileSave)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLeftView diagnostics

#ifdef _DEBUG
void CLeftView::AssertValid() const
{
	CFormView::AssertValid();
}

void CLeftView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLeftView message handlers

void CLeftView::OnButton1() 
{
	CMainFrame*pFrame=(CMainFrame*)AfxGetApp()->m_pMainWnd;
	str.Format("select top 15 * from ti_choose where tigan like '%%%s%%' order by tno",Conditionstr);
	pFrame->m_prview->m_tixing="选择题";
	pFrame->m_prview->page=1;
	pFrame->m_prview->strtixing="ti_choose";
	pFrame->m_prview->m_pageno="1";
	pFrame->m_prview->strsql=str;
	pFrame->m_prview->ShowTheme(str);
}

void CLeftView::OnButton2() 
{
	CMainFrame*pFrame=(CMainFrame*)AfxGetApp()->m_pMainWnd;
	str.Format("select top 15 * from ti_judge where tigan like '%%%s%%' order by tno",Conditionstr); 
	pFrame->m_prview->m_tixing="判断题";
	pFrame->m_prview->page=1;
	pFrame->m_prview->strtixing="ti_judge";
	pFrame->m_prview->m_pageno="1";
	pFrame->m_prview->strsql=str;
	pFrame->m_prview->ShowThemejudge(str);
}

void CLeftView::OnButton3() 
{
	CMainFrame*pFrame=(CMainFrame*)AfxGetApp()->m_pMainWnd;
	str.Format("select top 15 * from ti_filltext where tigan like '%%%s%%' order by tno",Conditionstr); 
	pFrame->m_prview->m_tixing="填空题";
	pFrame->m_prview->page=1;
	pFrame->m_prview->strtixing="ti_filltext";
	pFrame->m_prview->m_pageno="1";
	pFrame->m_prview->strsql=str;
	pFrame->m_prview->ShowThemefilltext(str);
	
}

void CLeftView::OnButton4() 
{
	CMainFrame*pFrame=(CMainFrame*)AfxGetApp()->m_pMainWnd;
	str.Format("select top 15 * from ti_procedure where tigan like '%%%s%%' order by tno",Conditionstr); 
	pFrame->m_prview->m_tixing="问答题";
	pFrame->m_prview->page=1;
	pFrame->m_prview->strtixing="ti_procedure";
	pFrame->m_prview->m_pageno="1";
	pFrame->m_prview->strsql=str;
	pFrame->m_prview->ShowThemeprocedure(str);	
	
}

void CLeftView::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	CString tempstr;
	m_userinformation="欢迎你!"+username+"\r\n";
	if(userright=="0")
		tempstr="管理员";
	else
		tempstr="录入员";
	m_userinformation+=tempstr;
	CTBManagerApp*pApp=(CTBManagerApp*)AfxGetApp();
	m_imagelist.Create(16,16,ILC_COLOR16,9,9);
	m_imagelist.Add(pApp->LoadIcon(IDI_ICON1));
	m_imagelist.Add(pApp->LoadIcon(IDI_ICON2));
	m_imagelist.Add(pApp->LoadIcon(IDI_ICON3));
	m_imagelist.Add(pApp->LoadIcon(IDI_ICON4));
	m_imagelist.Add(pApp->LoadIcon(IDI_ICON5));
	m_imagelist.Add(pApp->LoadIcon(IDI_ICON6));
	m_imagelist.Add(pApp->LoadIcon(IDI_ICON7));
	m_imagelist.Add(pApp->LoadIcon(IDI_ICON8));
	m_imagelist.Add(pApp->LoadIcon(IDI_ICON9));
	m_tree.SetImageList(&m_imagelist,TVSIL_NORMAL);
	m_tree.SetBKImage("cibas.bmp"); 
	m_button1.LoadBitmaps(IDB_BITMAP7,IDB_BITMAP3,IDB_BITMAP3);
	m_button2.LoadBitmaps(IDB_BITMAP4,IDB_BITMAP8,IDB_BITMAP2);
	m_button3.LoadBitmaps(IDB_BITMAP5,IDB_BITMAP9,IDB_BITMAP2);
	m_button4.LoadBitmaps(IDB_BITMAP6,IDB_BITMAP2,IDB_BITMAP2);
	TV_INSERTSTRUCT tvInsert;
	tvInsert.hParent = TVI_ROOT;
	tvInsert.hInsertAfter = TVI_LAST;
	tvInsert.item.mask = TVIF_TEXT|TVIF_PARAM|TVIF_IMAGE|TVIF_SELECTEDIMAGE;
	tvInsert.item.lParam=0;
	tvInsert.item.pszText = _T("管理题库");
	tvInsert.item.iImage=0;
	tvInsert.item.iSelectedImage=2;
	HTREEITEM hManager = m_tree.InsertItem(&tvInsert);
	tvInsert.hParent = TVI_ROOT;
	tvInsert.hInsertAfter = TVI_LAST;
	tvInsert.item.mask = TVIF_TEXT|TVIF_PARAM|TVIF_IMAGE|TVIF_SELECTEDIMAGE;
	tvInsert.item.lParam=0;
	tvInsert.item.pszText = _T("生成试卷");
	tvInsert.item.iImage=1;
	tvInsert.item.iSelectedImage=2;
	HTREEITEM hOutput = m_tree.InsertItem(&tvInsert);
	tvInsert.hParent = TVI_ROOT;
	tvInsert.hInsertAfter = TVI_LAST;
	tvInsert.item.mask = TVIF_TEXT|TVIF_PARAM|TVIF_IMAGE|TVIF_SELECTEDIMAGE;
	tvInsert.item.lParam=0;
	tvInsert.item.pszText = _T("系统管理");
	tvInsert.item.iImage=7;
	tvInsert.item.iSelectedImage=2;
	HTREEITEM hMagBase = m_tree.InsertItem(&tvInsert);

	TV_INSERTSTRUCT tvInsert1;
	tvInsert1.hParent = hManager;
	tvInsert1.hInsertAfter = TVI_LAST;
	tvInsert1.item.mask = TVIF_TEXT|TVIF_PARAM|TVIF_IMAGE|TVIF_SELECTEDIMAGE;
	tvInsert1.item.lParam=0;
	tvInsert1.item.pszText = _T("添加");
	tvInsert1.item.iImage=3;
	tvInsert1.item.iSelectedImage=3;
	m_tree.InsertItem(&tvInsert1);
	tvInsert1.hParent = hManager;
	tvInsert1.hInsertAfter = TVI_LAST;
	tvInsert1.item.mask = TVIF_TEXT|TVIF_PARAM|TVIF_IMAGE|TVIF_SELECTEDIMAGE;
	tvInsert1.item.lParam=0;
	tvInsert1.item.pszText = _T("删除");
	tvInsert1.item.iImage=4;
	tvInsert1.item.iSelectedImage=4;
	m_tree.InsertItem(&tvInsert1);
	tvInsert1.hParent = hManager;
	tvInsert1.hInsertAfter = TVI_LAST;
	tvInsert1.item.mask = TVIF_TEXT|TVIF_PARAM|TVIF_IMAGE|TVIF_SELECTEDIMAGE;
	tvInsert1.item.lParam=0;
	tvInsert1.item.pszText = _T("修改");
	tvInsert1.item.iImage=5;
	tvInsert1.item.iSelectedImage=5;
	m_tree.InsertItem(&tvInsert1);
	tvInsert1.hParent = hManager;
	tvInsert1.hInsertAfter = TVI_LAST;
	tvInsert1.item.mask = TVIF_TEXT|TVIF_PARAM|TVIF_IMAGE|TVIF_SELECTEDIMAGE;
	tvInsert1.item.lParam=0;
	tvInsert1.item.pszText = _T("查询");
	tvInsert1.item.iImage=6;
	tvInsert1.item.iSelectedImage=6;
	m_tree.InsertItem(&tvInsert1);

	tvInsert1.hParent = hOutput;
	tvInsert1.hInsertAfter = TVI_LAST;
	tvInsert1.item.mask = TVIF_TEXT|TVIF_PARAM|TVIF_IMAGE|TVIF_SELECTEDIMAGE;
	tvInsert1.item.lParam=0;
	tvInsert1.item.pszText = _T("手工生成");
	tvInsert1.item.iImage=3;
	tvInsert1.item.iSelectedImage=3;
	m_tree.InsertItem(&tvInsert1);
	tvInsert1.hParent = hOutput;
	tvInsert1.hInsertAfter = TVI_LAST;
	tvInsert1.item.mask = TVIF_TEXT|TVIF_PARAM|TVIF_IMAGE|TVIF_SELECTEDIMAGE;
	tvInsert1.item.lParam=0;
	tvInsert1.item.pszText = _T("随机生成");
	tvInsert1.item.iImage=4;
	tvInsert1.item.iSelectedImage=4;
	m_tree.InsertItem(&tvInsert1);

	tvInsert1.hParent = hMagBase;
	tvInsert1.hInsertAfter = TVI_LAST;
	tvInsert1.item.mask = TVIF_TEXT|TVIF_PARAM|TVIF_IMAGE|TVIF_SELECTEDIMAGE;
	tvInsert1.item.lParam=0;
	tvInsert1.item.pszText = _T("用户管理");
	tvInsert1.item.iImage=3;
	tvInsert1.item.iSelectedImage=3;
	m_tree.InsertItem(&tvInsert1);

	tvInsert1.hParent = hMagBase;
	tvInsert1.hInsertAfter = TVI_LAST;
	tvInsert1.item.mask = TVIF_TEXT|TVIF_PARAM|TVIF_IMAGE|TVIF_SELECTEDIMAGE;
	tvInsert1.item.lParam=0;
	tvInsert1.item.pszText = _T("还原数据库");
	tvInsert1.item.iImage=3;
	tvInsert1.item.iSelectedImage=3;
	m_tree.InsertItem(&tvInsert1);

	tvInsert1.hParent = hMagBase;
	tvInsert1.hInsertAfter = TVI_LAST;
	tvInsert1.item.mask = TVIF_TEXT|TVIF_PARAM|TVIF_IMAGE|TVIF_SELECTEDIMAGE;
	tvInsert1.item.lParam=0;
	tvInsert1.item.pszText = _T("备份数据库");
	tvInsert1.item.iImage=4;
	tvInsert1.item.iSelectedImage=4;
	m_tree.InsertItem(&tvInsert1);

	UpdateData(false);
}


void CLeftView::OnDblclkTree1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	*pResult = 0;
	
	CMainFrame *pFrame=(CMainFrame*)AfxGetApp()->m_pMainWnd;
	HTREEITEM hselItem=m_tree.GetSelectedItem();
	if(m_tree.GetItemText(hselItem)=="添加")
	{
		CADDDLG mydlg;
		mydlg.DoModal();
		return;
	}
	if(m_tree.GetItemText(hselItem)=="删除")
	{
		CString str;
		pFrame->m_prview->UpdateData();
		CString table=pFrame->m_prview->strtixing;
		CString m_tno=pFrame->m_prview->m_list.GetItemText(pFrame->m_prview->selectrow,0);
		
		if(MessageBox("确定删除吗？","提示",MB_YESNO|MB_ICONINFORMATION)==IDYES)
		{
			if(pFrame->m_prview->selectrow==-1)
			{
				AfxMessageBox("没有选定记录");
				return;
			}
			else
			{				
				str.Format("delete from %s where tno=%s",table,m_tno);
				pFrame->m_prview->pRS->Open(_bstr_t(str),CADORecordset.openQuery);
				pFrame->m_prview->selectrow=-1;				
				pFrame->m_prview->pRS->Close();
				AfxMessageBox("删除成功！");				
			}
		}	
	}
	if(m_tree.GetItemText(hselItem)=="修改")
	{
		modifyflag=true;
		CADDDLG mydlg;
		CString str;
		if(pFrame->m_prview->strtixing=="ti_choose")mydlg.font=0;
		if(pFrame->m_prview->strtixing=="ti_judge")mydlg.font=1;
		if(pFrame->m_prview->strtixing=="ti_filltext")mydlg.font=2;
		if(pFrame->m_prview->strtixing=="ti_procedure")mydlg.font=3;
		if(pFrame->m_prview->selectrow==-1)
		{
			AfxMessageBox("没有选定记录");
			return;
		}
		else 
		{
			mydlg.position=atoi(pFrame->m_prview->m_list.GetItemText(pFrame->m_prview->selectrow,0));
			str.Format("%d",mydlg.position);
			pFrame->m_prview->selectrow=-1;
		}
		mydlg.DoModal();
		return;
	}
	if(m_tree.GetItemText(hselItem)=="查询")
	{
		QueryDlg mydlg;
		CString str,strcondition;
		if(mydlg.DoModal()==IDOK)
		{
			strcondition=mydlg.m_condition;	
			Conditionstr=strcondition;
			str.Format("select top 15 * from ti_choose where tigan like '%%%s%%' order by 'tno'",strcondition);
						
			pFrame->m_prview->m_pageno="1";
			pFrame->m_prview->page=1;
			pFrame->m_prview->ShowTheme(str);
			pFrame->m_prview->m_tixing="选择题";	
		}
	}
	if(m_tree.GetItemText(hselItem)=="用户管理")
	{
		USERDLG mydlg;
		mydlg.DoModal();
		return;
	}
	if(m_tree.GetItemText(hselItem)=="手工生成")
	{
		CHandPapers mydlg;
		mydlg.DoModal();
		return;
	} 
	if(m_tree.GetItemText(hselItem)=="随机生成")
	{
		CShowCondition mydlg;
		mydlg.DoModal();
		return;
	}
	
	if(m_tree.GetItemText(hselItem)=="备份数据库")
	{
		BACKUPDLG mydlg;
		mydlg.DoModal();
	}
	if(m_tree.GetItemText(hselItem)=="还原数据库")
	{
		RESTOREDLG mydlg;
		mydlg.DoModal();
	}	
	*pResult = 0;
}

void CLeftView::OnUpdateFileSave(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
	
}
