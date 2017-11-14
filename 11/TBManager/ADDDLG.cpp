// ADDDLG.cpp : implementation file
//

#include "stdafx.h"
#include "TBManager.h"
#include "ADDDLG.h"
//#include "RightView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CADDDLG dialog


CADDDLG::CADDDLG(CWnd* pParent /*=NULL*/)
	: CDialog(CADDDLG::IDD, pParent)
{
	font=-1;
	position=-1;
	nselect=0;
	//{{AFX_DATA_INIT(CADDDLG)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CADDDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CADDDLG)
	DDX_Control(pDX, IDC_TAB1, m_tab);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CADDDLG, CDialog)
	//{{AFX_MSG_MAP(CADDDLG)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, OnSelchangeTab1)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CADDDLG message handlers

void CADDDLG::SetDlgState(CWnd *pWnd, BOOL bShow)
{
	pWnd->EnableWindow(bShow);
	if(bShow)
	{
		pWnd->ShowWindow(SW_SHOW);
		pWnd->CenterWindow();
	}
	else pWnd->ShowWindow(SW_HIDE);
}

void CADDDLG::DoTab(int ntab)
{
	if(ntab>3)ntab=3;
	if(ntab<0)ntab=0;
	BOOL bTab[4];
	bTab[1]=bTab[2]=bTab[3]=bTab[0]=false;
	bTab[ntab]=true;
	SetDlgState(m_ptab1,bTab[0]);
	SetDlgState(m_ptab2,bTab[1]);
	SetDlgState(m_ptab3,bTab[2]);
	SetDlgState(m_ptab4,bTab[3]);
}

void CADDDLG::OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	if(font==-1)
	{
		nselect=m_tab.GetCurSel();
		if(nselect>=0)
			DoTab(nselect);
	}
	*pResult = 0;
}

BOOL CADDDLG::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CString strsql;
	pDB=new CADODatabase;
	pDB->Open("driver={SQL Server};Server=HC\\MSSQL2008;DATABASE=abao;");
	pRS=new CADORecordset(pDB);
	if(modifyflag)
	SetWindowText("修改试题");
	else
	SetWindowText("添加试题");

	m_ptab1=new CTABDLG1();//give place to no-model dialog
	m_ptab2=new CTABDLG2();
	m_ptab3=new CTABDLG3();
	m_ptab4=new CTABDLG4();
	m_ptab1->Create(IDD_DIALOG_TAB1,&m_tab);
	m_ptab2->Create(IDD_DIALOG_TAB2,&m_tab);
	m_ptab3->Create(IDD_DIALOG_TAB3,&m_tab);
	m_ptab4->Create(IDD_DIALOG_TAB4,&m_tab);
	m_imagelist.Create(16,16,ILC_COLOR16,3,0);//CREATE the imagelist
	m_imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON4));//add the icons to the imagelist
	m_imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON5));
	m_imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON6));
	m_imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON10));
	m_tab.SetImageList(&m_imagelist);//set the tab control's imagelist
	m_tab.InsertItem(0,"选择题",0);
	m_tab.InsertItem(1,"判断题",1);
	m_tab.InsertItem(2,"填空题",2);
	m_tab.InsertItem(3,"问答题",3);
	m_tab.SetMinTabWidth(80);
	m_tab.SetPadding(CSize(12,3));
	if(font==-1)
	{
		m_tab.SetCurSel(0);
		DoTab(0);
	}
	else
	{
		m_tab.SetCurSel(font);
		DoTab(font);	
	}
	switch(font)
	{
		case 0:
			SetWindowText("修改试题");
			strsql.Format("select * from ti_choose where tno=%d",position);
			pRS->Open(_bstr_t(strsql),CADORecordset.openQuery);
			if(!pRS->IsOpen())return false;
			if(pRS->GetRecordCount()<=0)return false;
			pRS->MoveFirst();
			m_ptab1->m_tno=position;
			pRS->GetFieldValue("tigan",m_ptab1->m_tigan);
			pRS->GetFieldValue("xa",m_ptab1->m_xa);
			pRS->GetFieldValue("xb",m_ptab1->m_xb);
			pRS->GetFieldValue("xc",m_ptab1->m_xc);
			pRS->GetFieldValue("xd",m_ptab1->m_xd);
			pRS->GetFieldValue("answer",m_ptab1->m_answer);
			pRS->GetFieldValue("difficulty",m_ptab1->m_difficulty);
			pRS->Close();
			m_ptab1->UpdateData(false);
			break;
		case 1:
			SetWindowText("修改试题");
			strsql.Format("select * from ti_judge where tno=%d",position);
			pRS->Open(_bstr_t(strsql),CADORecordset.openQuery);
			if(!pRS->IsOpen())return false;
			if(pRS->GetRecordCount()<=0)return false;
			pRS->MoveFirst();
			m_ptab2->m_tno=position;
			pRS->GetFieldValue("tigan",m_ptab2->m_tigan);
			pRS->GetFieldValue("answer",m_ptab2->m_answer);
			pRS->GetFieldValue("difficulty",m_ptab2->m_difficulty);
			pRS->Close();
			m_ptab2->UpdateData(false);
			break;
		case 2:
			SetWindowText("修改试题");
			strsql.Format("select * from ti_filltext where tno=%d",position);
			pRS->Open(_bstr_t(strsql),CADORecordset.openQuery);
			if(!pRS->IsOpen())return false;
			if(pRS->GetRecordCount()<=0)return false;
			pRS->MoveFirst();
			m_ptab3->m_tno=position;
			pRS->GetFieldValue("tigan",m_ptab3->m_tigan);
			pRS->GetFieldValue("ka",m_ptab3->m_ka);
			pRS->GetFieldValue("kb",m_ptab3->m_kb);
			pRS->GetFieldValue("kc",m_ptab3->m_kc);
			pRS->GetFieldValue("kd",m_ptab3->m_kd);
			pRS->GetFieldValue("difficulty",m_ptab3->m_difficulty);
			pRS->Close();
			m_ptab3->UpdateData(false);
			break;
		case 3:
			SetWindowText("修改试题");
			strsql.Format("select * from ti_procedure where tno=%d",position);
			pRS->Open(_bstr_t(strsql),CADORecordset.openQuery);
			if(!pRS->IsOpen())return false;
			if(pRS->GetRecordCount()<=0)return false;
			pRS->MoveFirst();
			m_ptab4->m_tno=position;
			pRS->GetFieldValue("tigan",m_ptab4->m_tigan);
			pRS->GetFieldValue("answer",m_ptab4->m_answer);
			pRS->GetFieldValue("difficulty",m_ptab4->m_difficulty);
			pRS->Close();
			m_ptab4->UpdateData(false);
			break;

	}

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CADDDLG::OnDestroy() 
{
	CDialog::OnDestroy();
	
	if(m_ptab1)delete m_ptab1;
	if(m_ptab2)delete m_ptab2;
	if(m_ptab3)delete m_ptab3;
	if(m_ptab4)delete m_ptab4;
}

BOOL CADDDLG::PreTranslateMessage(MSG* pMsg) 
{
	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam==VK_RETURN)return TRUE;
		if(pMsg->wParam==VK_ESCAPE)return TRUE;
	}
	
	return CDialog::PreTranslateMessage(pMsg);
}

void CADDDLG::OnOK() 
{
	UpdateData();
	m_ptab1->UpdateData();
	m_ptab2->UpdateData();
	m_ptab3->UpdateData();
	m_ptab4->UpdateData();
	CString strsql,tixing;
	if(!modifyflag)
	{
		switch(nselect)
		{
		case 0:
			strsql.Format("select * from ti_choose where tno =%d",m_ptab1->m_tno);

			if(!pRS->IsOpen())
			pRS->Open(_bstr_t(strsql),CADORecordset.openQuery);
			if(pRS->GetRecordCount()!=0)
			{
				AfxMessageBox("已有相同的题目！");
				pRS->Close();
				return;
			}
			pRS->AddNew();
			pRS->SetFieldValue("tno",m_ptab1->m_tno);
			pRS->SetFieldValue("tigan",m_ptab1->m_tigan);
			pRS->SetFieldValue("xa",m_ptab1->m_xa);
			pRS->SetFieldValue("xb",m_ptab1->m_xb);
			pRS->SetFieldValue("xc",m_ptab1->m_xc);
			pRS->SetFieldValue("xd",m_ptab1->m_xd);
			pRS->SetFieldValue("answer",m_ptab1->m_answer);
			pRS->SetFieldValue("difficulty",m_ptab1->m_difficulty);
			pRS->Update();
			AfxMessageBox("插入成功！");
			pRS->Close();
			break;
		case 1:
			strsql="select * from ti_judge";
			pRS->Open(_bstr_t(strsql),CADORecordset.openQuery);
			if(!pRS->IsOpen())return;
			if(pRS->GetRecordCount()<=0)return;
			pRS->AddNew();
			pRS->SetFieldValue("tno",m_ptab2->m_tno);
			pRS->SetFieldValue("tigan",m_ptab2->m_tigan);
			pRS->SetFieldValue("answer",m_ptab2->m_answer);
			pRS->SetFieldValue("difficulty",m_ptab2->m_difficulty);
			pRS->Update();
			AfxMessageBox("插入成功！");
			pRS->Close();
			break;
		case 2:
			strsql="select * from ti_filltext";
			pRS->Open(_bstr_t(strsql),CADORecordset.openQuery);
			if(!pRS->IsOpen())return;
			if(pRS->GetRecordCount()<=0)return;
			pRS->AddNew();
			pRS->SetFieldValue("tno",m_ptab3->m_tno);
			pRS->SetFieldValue("tigan",m_ptab3->m_tigan);
			pRS->SetFieldValue("ka",m_ptab3->m_ka);
			pRS->SetFieldValue("kb",m_ptab3->m_kb);
			pRS->SetFieldValue("kc",m_ptab3->m_kc);
			pRS->SetFieldValue("kd",m_ptab3->m_kd);
			pRS->SetFieldValue("difficulty",m_ptab3->m_difficulty);
			pRS->Update();
			AfxMessageBox("插入成功！");
			pRS->Close();
			break;
		case 3:
			strsql="select * from ti_procedure";
			pRS->Open(_bstr_t(strsql),CADORecordset.openQuery);
			if(!pRS->IsOpen())return;
			if(pRS->GetRecordCount()<=0)return;
			pRS->AddNew();
			pRS->SetFieldValue("tno",m_ptab4->m_tno);
			pRS->SetFieldValue("tigan",m_ptab4->m_tigan);
			pRS->SetFieldValue("answer",m_ptab4->m_answer);
			pRS->SetFieldValue("difficulty",m_ptab4->m_difficulty);
			pRS->Update();
			AfxMessageBox("插入成功！");
			pRS->Close();
			break;			
		}
	}
	else
	{
		switch(font)
		{
		case 0:
			strsql.Format("delete from ti_choose where tno=%d",position);
			pRS->Open(_bstr_t(strsql),CADORecordset.openQuery);
			pRS->Close();
			strsql="select * from ti_choose";
			AfxMessageBox(strsql);
			pRS->Open(_bstr_t(strsql),CADORecordset.openQuery);
			if(!pRS->IsOpen())return;
			if(pRS->GetRecordCount()<=0)return;
			pRS->AddNew();
			pRS->SetFieldValue("tno",m_ptab1->m_tno);
			pRS->SetFieldValue("tigan",m_ptab1->m_tigan);
			pRS->SetFieldValue("xa",m_ptab1->m_xa);
			pRS->SetFieldValue("xb",m_ptab1->m_xb);
			pRS->SetFieldValue("xc",m_ptab1->m_xc);
			pRS->SetFieldValue("xd",m_ptab1->m_xd);
			pRS->SetFieldValue("answer",m_ptab1->m_answer);
			pRS->SetFieldValue("difficulty",m_ptab1->m_difficulty);
			pRS->Update();
			AfxMessageBox("修改成功！");
			pRS->Close();
			break;
		case 1:
			strsql.Format("delete from ti_judge where tno=%d",position);
			pRS->Open(_bstr_t(strsql),CADORecordset.openQuery);
			pRS->Close();
			strsql="select * from ti_judge";
			pRS->Open(_bstr_t(strsql),CADORecordset.openQuery);
			if(!pRS->IsOpen())return;
			if(pRS->GetRecordCount()<=0)return;
			pRS->AddNew();
			pRS->SetFieldValue("tno",m_ptab2->m_tno);
			pRS->SetFieldValue("tigan",m_ptab2->m_tigan);
			pRS->SetFieldValue("answer",m_ptab2->m_answer);
			pRS->SetFieldValue("difficulty",m_ptab2->m_difficulty);
			pRS->Update();
			AfxMessageBox("修改成功！");
			pRS->Close();
			break;
		case 2:
			strsql.Format("delete from ti_filltext where tno=%d",position);
			pRS->Open(_bstr_t(strsql),CADORecordset.openQuery);
			pRS->Close();
			strsql="select * from ti_filltext";
			pRS->Open(_bstr_t(strsql),CADORecordset.openQuery);
			if(!pRS->IsOpen())return;
			if(pRS->GetRecordCount()<=0)return;
			pRS->AddNew();
			pRS->SetFieldValue("tno",m_ptab3->m_tno);
			pRS->SetFieldValue("tigan",m_ptab3->m_tigan);
			pRS->SetFieldValue("ka",m_ptab3->m_ka);
			pRS->SetFieldValue("kb",m_ptab3->m_kb);
			pRS->SetFieldValue("kc",m_ptab3->m_kc);
			pRS->SetFieldValue("kd",m_ptab3->m_kd);
			pRS->SetFieldValue("difficulty",m_ptab3->m_difficulty);
			pRS->Update();
			AfxMessageBox("修改成功！");
			pRS->Close();
			break;
		case 3:
			strsql.Format("delete from ti_procedure where tno=%d",position);
			pRS->Open(_bstr_t(strsql),CADORecordset.openQuery);
			pRS->Close();
			strsql="select * from ti_procedure";
			pRS->Open(_bstr_t(strsql),CADORecordset.openQuery);
			if(!pRS->IsOpen())return;
			if(pRS->GetRecordCount()<=0)return;
			pRS->AddNew();
			pRS->SetFieldValue("tno",m_ptab4->m_tno);
			pRS->SetFieldValue("tigan",m_ptab4->m_tigan);
			pRS->SetFieldValue("answer",m_ptab4->m_answer);
			pRS->SetFieldValue("difficulty",m_ptab4->m_difficulty);
			pRS->Update();
			AfxMessageBox("修改成功！");
			pRS->Close();
			break;
		}
	}
	CDialog::OnOK();
}
