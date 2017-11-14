// RightView.cpp : implementation file
//

#include "stdafx.h"
#include "TBManager.h"
#include "RightView.h"
#include "QueryDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRightView

IMPLEMENT_DYNCREATE(CRightView, CFormView)

CRightView::CRightView()
	: CFormView(CRightView::IDD)
{
	//strcondition=_T("");
	strtixing="ti_choose";
	page=0;
	strsql="";
	selectrow=-1;
	CString strConnection="File Name=ThemeBase.udl";
	pDB=new CADODatabase;
	pDB->Open(strConnection);
	pRS=new CADORecordset(pDB);
	//recordset=pRS;
	//{{AFX_DATA_INIT(CRightView)
	m_tixing = _T("选择题");
	m_difficulty = _T("");
	m_content = _T("");
	m_pageno = _T("1");
	//}}AFX_DATA_INIT
}

CRightView::~CRightView()
{
}

void CRightView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRightView)
	DDX_Control(pDX, IDC_TOP, m_top);
	DDX_Control(pDX, IDC_LAST, m_last);
	DDX_Control(pDX, IDC_FRONT, m_front);
	DDX_Control(pDX, IDC_BACK, m_back);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Text(pDX, IDC_EDIT2, m_tixing);
	DDX_Text(pDX, IDC_DIFFICULTY, m_difficulty);
	DDX_Text(pDX, IDC_CONTENT, m_content);
	DDX_Text(pDX, IDC_PAGENO, m_pageno);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRightView, CFormView)
	//{{AFX_MSG_MAP(CRightView)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, OnItemchangedList1)
	ON_BN_CLICKED(IDC_FRONT, OnFront)
	ON_BN_CLICKED(IDC_LAST, OnLast)
	ON_BN_CLICKED(IDC_BACK, OnBack)
	ON_BN_CLICKED(IDC_TOP, OnTop)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_UPDATE, OnUpdate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRightView diagnostics

#ifdef _DEBUG
void CRightView::AssertValid() const
{
	CFormView::AssertValid();
}

void CRightView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRightView message handlers

void CRightView::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	
	m_list.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	m_list.InsertColumn(0,"题号",LVCFMT_CENTER,36);
	m_list.InsertColumn(1,"题干",LVCFMT_CENTER,100);
	m_list.InsertColumn(2,"选项A",LVCFMT_CENTER,100);
	m_list.InsertColumn(3,"选项B",LVCFMT_CENTER,100);
	m_list.InsertColumn(4,"选项C",LVCFMT_CENTER,100);
	m_list.InsertColumn(5,"选项D",LVCFMT_CENTER,100);
	m_list.InsertColumn(6,"答案",LVCFMT_CENTER,100);
	m_list.InsertColumn(7,"难度",LVCFMT_CENTER,100);
//	QueryDlg mydlg;

//	recordset=*pRS;
//	if(mydlg.DoModal()==IDOK)
//	{
//		strcondition=mydlg.m_condition;

	strsql="select top 15 * from ti_choose order by tno"; 
	page=1;
			//where tigan like '%%%s%%'",strcondition
	Conditionstr="";
	strtixing="ti_choose";
	ShowTheme(strsql);	
//	}

	m_tooltip.Create(this);
	m_tooltip.AddTool(&m_front,"上一页");
	m_tooltip.AddTool(&m_top,"首页");
	m_tooltip.AddTool(&m_back,"下一页");
	m_tooltip.AddTool(&m_last,"尾页");
	UpdateData(false);
}

void CRightView::ShowTheme(CString strsql)
{
	Hidetopbuttom(page);
	CString str1,str2,str3,str4,str5,str6,str7,str8;
	int i=0;
	int   Columns;   
	CHeaderCtrl*  pHeader=(CHeaderCtrl*)m_list.GetDlgItem(0);   
	if(pHeader)   
	{   
		Columns=pHeader->GetItemCount();   
	} 
	int j;
	j=Columns;
	for(;j>=0;j--)   
	{   
		m_list.DeleteColumn(i);   
	}
	m_list.DeleteAllItems();
	m_list.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	m_list.InsertColumn(0,"题号",LVCFMT_CENTER,36);
	m_list.InsertColumn(1,"题干",LVCFMT_CENTER,100);
	m_list.InsertColumn(2,"选项A",LVCFMT_CENTER,100);
	m_list.InsertColumn(3,"选项B",LVCFMT_CENTER,100);
	m_list.InsertColumn(4,"选项C",LVCFMT_CENTER,100);
	m_list.InsertColumn(5,"选项D",LVCFMT_CENTER,100);
	m_list.InsertColumn(6,"答案",LVCFMT_CENTER,100);
	m_list.InsertColumn(7,"难度",LVCFMT_CENTER,100);
	pRS->Open(_bstr_t(strsql),CADORecordset.openQuery);
	CButton *p;
	if(!pRS->IsOpen())return;
	if(pRS->GetRecordCount()<=0)return;
	if(pRS->GetRecordCount()<15)
	{	
		p=(CButton *)GetDlgItem(IDC_LAST);
		p->EnableWindow(false);
		p=(CButton *)GetDlgItem(IDC_BACK);
		p->EnableWindow(false);
	}
	else
	{
		p=(CButton *)GetDlgItem(IDC_LAST);
		p->EnableWindow(true);
		p=(CButton *)GetDlgItem(IDC_BACK);
		p->EnableWindow(true);	
	}
	pRS->MoveFirst();
	while(!pRS->IsEOF())
	{
		pRS->GetFieldValue("tno",str1);
		m_list.InsertItem(i,str1);
		pRS->GetFieldValue("tigan",str2);
		m_list.SetItemText(i,1,str2);
		pRS->GetFieldValue("xa",str3);
		m_list.SetItemText(i,2,str3);
		pRS->GetFieldValue("xb",str4);
		m_list.SetItemText(i,3,str4);
		pRS->GetFieldValue("xc",str5);
		m_list.SetItemText(i,4,str5);
		pRS->GetFieldValue("xd",str6);
		m_list.SetItemText(i,5,str6);
		pRS->GetFieldValue("answer",str7);
		m_list.SetItemText(i,6,str7);
		pRS->GetFieldValue("difficulty",str8);
		m_list.SetItemText(i,7,str8);
		i++;
		pRS->MoveNext();
	}
	pRS->Close();
	UpdateData(false);
}

void CRightView::ShowThemejudge(CString strsql)
{
	Hidetopbuttom(page);
	CString str1,str2,str3,str4,str5;
	int i=0;
	m_list.DeleteAllItems();
	int   Columns;   
	CHeaderCtrl*  pHeader=(CHeaderCtrl*)m_list.GetDlgItem(0);   
	if(pHeader)   
	{   
		Columns=pHeader->GetItemCount();   
	} 
	int j;
	j=Columns;
	for(;j>=0;j--)   
	{   
		m_list.DeleteColumn(i);   
	}
	m_list.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	m_list.InsertColumn(0,"题号",LVCFMT_CENTER,36);
	m_list.InsertColumn(1,"题干",LVCFMT_CENTER,300);
	m_list.InsertColumn(2,"答案",LVCFMT_CENTER,100);
	m_list.InsertColumn(3,"难度",LVCFMT_CENTER,100);
	pRS->Open(_bstr_t(strsql),CADORecordset.openQuery);
	if(!pRS->IsOpen())return;
	if(pRS->GetRecordCount()<=0)return;
	CButton *p;
	if(pRS->GetRecordCount()<15)
	{
		//CButton *p;
		p=(CButton *)GetDlgItem(IDC_LAST);
		p->EnableWindow(false);
		p=(CButton *)GetDlgItem(IDC_BACK);
		p->EnableWindow(false);
	}
	else
	{
		p=(CButton *)GetDlgItem(IDC_LAST);
		p->EnableWindow(true);
		p=(CButton *)GetDlgItem(IDC_BACK);
		p->EnableWindow(true);	
	}
	pRS->MoveFirst();
	while(!pRS->IsEOF())
	{
		pRS->GetFieldValue("tno",str1);
		m_list.InsertItem(i,str1);
		pRS->GetFieldValue("tigan",str2);
		m_list.SetItemText(i,1,str2);
		pRS->GetFieldValue("answer",str3);
		m_list.SetItemText(i,2,str3);
		pRS->GetFieldValue("difficulty",str4);
		m_list.SetItemText(i,3,str4);
		i++;
		pRS->MoveNext();
	}
	
	//	}
	pRS->Close();
	UpdateData(false);
}

void CRightView::OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	selectrow=pNMListView->iItem;
	CString  temp=m_list.GetItemText(selectrow,0);
	int m_tno=atoi(temp);
	ShowfullMessage(selectrow);
	*pResult = 0;
}

void CRightView::ShowfullMessage(int selectrow)
{
	UpdateData();
	m_content="";
	m_difficulty="";
	if(m_tixing=="选择题")
	{
		m_content+=m_list.GetItemText(selectrow,1);
		m_content+="\r\n";
		m_content+=m_list.GetItemText(selectrow,2);
		m_content+="\r\n";
		m_content+=m_list.GetItemText(selectrow,3);
		m_content+="\r\n";
		m_content+=m_list.GetItemText(selectrow,4);
		m_content+="\r\n";
		m_content+=m_list.GetItemText(selectrow,5);
		m_content+="\r\n";
		m_content+="答案:  ";
		m_content+=m_list.GetItemText(selectrow,6);
		m_difficulty=m_list.GetItemText(selectrow,7);
	}
	if(m_tixing=="判断题")
	{
		m_content+=m_list.GetItemText(selectrow,1);
		m_content+="\r\n";
		m_content+="答案:  ";
		m_content+=m_list.GetItemText(selectrow,2);
		m_difficulty=m_list.GetItemText(selectrow,3);
	}
	if(m_tixing=="填空题")
	{
		m_content+=m_list.GetItemText(selectrow,1);
		m_content+="\r\n";
		m_content+="答案:  ";
		m_content+=m_list.GetItemText(selectrow,2);
		m_content+="   ";
		m_content+=m_list.GetItemText(selectrow,3);
		m_content+="   ";
		m_content+=m_list.GetItemText(selectrow,4);
		m_content+="   ";
		m_content+=m_list.GetItemText(selectrow,5);
		m_difficulty=m_list.GetItemText(selectrow,6);
	}
	if(m_tixing=="问答题")
	{
		m_content+=m_list.GetItemText(selectrow,1);
		m_content+="\r\n";
		m_content+="答案:  ";
		m_content+=m_list.GetItemText(selectrow,2);
		m_difficulty=m_list.GetItemText(selectrow,3);
	}
	UpdateData(false);

}

void CRightView::OnFront() 
{
	page--;
	int count;
	if(page==1)OnTop();
	//AfxMessageBox(strtixing);
	else
	{
		count=15*(page-1);
		strsql.Format("select top 15 * from %s where tigan like '%%%s%%' and(tno>(select max(tno) from (select top %d tno from %s where tigan like '%%%s%%' )as t))order by tno",strtixing,Conditionstr,count,strtixing,Conditionstr);
		Hidetopbuttom(page);
		if(strtixing=="ti_choose")ShowTheme(strsql);
		m_pageno.Format("%d",page);
		
		if(strtixing=="ti_judge")ShowThemejudge(strsql);
		if(strtixing=="ti_filltext")ShowThemefilltext(strsql);
		if(strtixing=="ti_procedure")ShowThemeprocedure(strsql);
	}
	UpdateData(false);
	
}

void CRightView::OnLast() 
{
	strsql.Format("select * from %s where tigan like '%%%s%%' order by tno",strtixing,Conditionstr);
	//Hidetopbuttom(page);
	pRS->Open(_bstr_t(strsql),CADORecordset.openQuery);
	if(!pRS->IsOpen())return;
	if(pRS->GetRecordCount()<=0)return;
	int n=pRS->GetRecordCount();
	pRS->Close();
	int m,l=0,o=0,count;
	m=n%15;
	l=n/15;
	if(m!=0)
	{
		page=l+1;
		m_pageno.Format("%d",page);
		count=l*15;
		strsql.Format("select top %d * from %s where tigan like '%%%s%%' and(tno>(select max(tno) from (select top %d tno from %s where tigan like '%%%s%%' )as t))order by tno",m,strtixing,Conditionstr,count,strtixing,Conditionstr);
		if(strtixing=="ti_choose")ShowTheme(strsql);
		if(strtixing=="ti_judge")ShowThemejudge(strsql);
		if(strtixing=="ti_filltext")ShowThemefilltext(strsql);
		if(strtixing=="ti_procedure")ShowThemeprocedure(strsql);
	}
	else
	{
		page=l;
		m_pageno.Format("%d",page);
		count=15*(page-1);
		strsql.Format("select top 15 * from %s where tigan like '%%%s%%' and(tno>(select max(tno) from (select top %d tno from %s where tigan like '%%%s%%' )as t))order by tno",strtixing,Conditionstr,count,strtixing,Conditionstr);
		Hidetopbuttom(page);
		//AfxMessageBox(strsql);
		if(strtixing=="ti_choose")ShowTheme(strsql);
		//m_pageno.Format("%d",page);
		
		if(strtixing=="ti_judge")ShowThemejudge(strsql);
		if(strtixing=="ti_filltext")ShowThemefilltext(strsql);
		if(strtixing=="ti_procedure")ShowThemeprocedure(strsql);
	}

}

void CRightView::OnBack() 
{
	page++;
	int count;
	//AfxMessageBox(strtixing);
	count=15*(page-1);
	strsql.Format("select top 15 * from %s where tigan like '%%%s%%' and(tno>(select max(tno) from (select top %d tno from %s where tigan like '%%%s%%' )as t))order by tno",strtixing,Conditionstr,count,strtixing,Conditionstr);
	Hidetopbuttom(page);
	//AfxMessageBox(strsql);
	if(strtixing=="ti_choose")ShowTheme(strsql);
	if(strtixing=="ti_judge")ShowThemejudge(strsql);
	if(strtixing=="ti_filltext")ShowThemefilltext(strsql);
	if(strtixing=="ti_procedure")ShowThemeprocedure(strsql);
	m_pageno.Format("%d",page);
	UpdateData(false);
}

void CRightView::OnTop() 
{
	page=1;
	strsql.Format("select top 15 * from %s where tigan like '%%%s%%' order by tno",strtixing,Conditionstr);
	Hidetopbuttom(page);
	if(strtixing=="ti_choose")ShowTheme(strsql);
	if(strtixing=="ti_judge")ShowThemejudge(strsql);
	if(strtixing=="ti_filltext")ShowThemefilltext(strsql);
	if(strtixing=="ti_procedure")ShowThemeprocedure(strsql);
	m_pageno.Format("%d",page);
	UpdateData(false);
}

void CRightView::Hidetopbuttom(int page)
{
	CButton *p;	
	if(page==1)
	{
		p=(CButton *)GetDlgItem(IDC_TOP);
		p->EnableWindow(false);
		p=(CButton *)GetDlgItem(IDC_FRONT);
		p->EnableWindow(false);
	}
	else 
	{
		p=(CButton *)GetDlgItem(IDC_TOP);
		p->EnableWindow(TRUE);
		p=(CButton *)GetDlgItem(IDC_FRONT);
		p->EnableWindow(TRUE);
	}
}

BOOL CRightView::PreTranslateMessage(MSG* pMsg) 
{
	switch(pMsg->message)
	{
	case WM_LBUTTONDOWN:
	case WM_LBUTTONUP:
	case WM_MOUSEMOVE:
		m_tooltip.RelayEvent(pMsg);
	}

	
	return CFormView::PreTranslateMessage(pMsg);
}

void CRightView::ShowThemefilltext(CString strsql)
{
	Hidetopbuttom(page);
	CString str1,str2,str3,str4,str5,str6,str8;
	int i=0;
	int   Columns;   
	CHeaderCtrl*  pHeader=(CHeaderCtrl*)m_list.GetDlgItem(0);   
	if(pHeader)   
	{   
		Columns=pHeader->GetItemCount();   
	} 
	int j;
	j=Columns;
	for(;j>=0;j--)   
	{   
		m_list.DeleteColumn(i);   
	}
	m_list.DeleteAllItems();
	m_list.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	m_list.InsertColumn(0,"题号",LVCFMT_CENTER,36);
	m_list.InsertColumn(1,"题干",LVCFMT_CENTER,100);
	m_list.InsertColumn(2,"填充A",LVCFMT_CENTER,100);
	m_list.InsertColumn(3,"填充B",LVCFMT_CENTER,100);
	m_list.InsertColumn(4,"填充C",LVCFMT_CENTER,100);
	m_list.InsertColumn(5,"填充D",LVCFMT_CENTER,100);
	//m_list.InsertColumn(6,"答案",LVCFMT_CENTER,100);
	m_list.InsertColumn(6,"难度",LVCFMT_CENTER,100);
	pRS->Open(_bstr_t(strsql),CADORecordset.openQuery);
	CButton *p;
	if(!pRS->IsOpen())return;
	if(pRS->GetRecordCount()<=0)return;
	if(pRS->GetRecordCount()<15)
	{
	
		p=(CButton *)GetDlgItem(IDC_LAST);
		p->EnableWindow(false);
		p=(CButton *)GetDlgItem(IDC_BACK);
		p->EnableWindow(false);
	}
	else
	{
		p=(CButton *)GetDlgItem(IDC_LAST);
		p->EnableWindow(true);
		p=(CButton *)GetDlgItem(IDC_BACK);
		p->EnableWindow(true);	
	}
	pRS->MoveFirst();
	while(!pRS->IsEOF())
	{
		pRS->GetFieldValue("tno",str1);
		m_list.InsertItem(i,str1);
		pRS->GetFieldValue("tigan",str2);
		m_list.SetItemText(i,1,str2);
		pRS->GetFieldValue("ka",str3);
		m_list.SetItemText(i,2,str3);
		pRS->GetFieldValue("kb",str4);
		m_list.SetItemText(i,3,str4);
		pRS->GetFieldValue("kc",str5);
		m_list.SetItemText(i,4,str5);
		pRS->GetFieldValue("kd",str6);
		m_list.SetItemText(i,5,str6);
	//	pRS->GetFieldValue("answer",str7);
	//	m_list.SetItemText(i,6,str7);
		pRS->GetFieldValue("difficulty",str8);
		m_list.SetItemText(i,6,str8);
		i++;
		pRS->MoveNext();
	}
	
	//	}
	pRS->Close();
	UpdateData(false);

}

void CRightView::ShowThemeprocedure(CString strsql)
{
	Hidetopbuttom(page);
	CString str1,str2,str3,str4,str5;
	int i=0;
	m_list.DeleteAllItems();
	int   Columns;   
	CHeaderCtrl*  pHeader=(CHeaderCtrl*)m_list.GetDlgItem(0);   
	if(pHeader)   
	{   
		Columns=pHeader->GetItemCount();   
	} 
	int j;
	j=Columns;
	for(;j>=0;j--)   
	{   
		m_list.DeleteColumn(i);   
	}
	m_list.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	m_list.InsertColumn(0,"题号",LVCFMT_CENTER,36);
	m_list.InsertColumn(1,"题干",LVCFMT_CENTER,300);
	m_list.InsertColumn(2,"答案",LVCFMT_CENTER,100);
	m_list.InsertColumn(3,"难度",LVCFMT_CENTER,100);
	pRS->Open(_bstr_t(strsql),CADORecordset.openQuery);
	if(!pRS->IsOpen())return;
	if(pRS->GetRecordCount()<=0)return;
	CButton *p;
	if(pRS->GetRecordCount()<15)
	{
		
		p=(CButton *)GetDlgItem(IDC_LAST);
		p->EnableWindow(false);
		p=(CButton *)GetDlgItem(IDC_BACK);
		p->EnableWindow(false);
	}
	else
	{
		p=(CButton *)GetDlgItem(IDC_LAST);
		p->EnableWindow(true);
		p=(CButton *)GetDlgItem(IDC_BACK);
		p->EnableWindow(true);	
	}
	pRS->MoveFirst();
	while(!pRS->IsEOF())
	{
		pRS->GetFieldValue("tno",str1);
		m_list.InsertItem(i,str1);
		pRS->GetFieldValue("tigan",str2);
		m_list.SetItemText(i,1,str2);
		pRS->GetFieldValue("answer",str3);
		m_list.SetItemText(i,2,str3);
		pRS->GetFieldValue("difficulty",str4);
		m_list.SetItemText(i,3,str4);
		i++;
		pRS->MoveNext();
	}
	
	//	}
	pRS->Close();
	UpdateData(false);
	
}

void CRightView::OnDestroy() 
{
	CFormView::OnDestroy();
	
	pDB->Close();
	
}
void CRightView::OperationUpdate()
{
	OnUpdate();

}
void CRightView::OnUpdate() 
{
	if(strtixing=="ti_choose")
		ShowTheme(strsql);
	if(strtixing=="ti_judge")
		ShowThemejudge(strsql);
	if(strtixing=="ti_filltext")
		ShowThemefilltext(strsql);
	if(strtixing=="ti_procedure")
		ShowThemeprocedure(strsql);
	
}
