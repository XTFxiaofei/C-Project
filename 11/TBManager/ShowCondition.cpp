// ShowCondition.cpp : implementation file
//

#include "stdafx.h"
#include "TBManager.h"
#include "ShowCondition.h"
#include "msword.h"
#include "stdlib.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShowCondition dialog


CShowCondition::CShowCondition(CWnd* pParent /*=NULL*/)
	: CDialog(CShowCondition::IDD, pParent)
{
	//{{AFX_DATA_INIT(CShowCondition)
	m_difficult2 = 0;
	m_difficult4 = 0;
	m_fulldifficult = _T("");
	m_fullscore = _T("");
	m_num1 = 0;
	m_num2 = 0;
	m_num3 = 0;
	m_num4 = 0;
	m_score1 = 0;
	m_score2 = 0;
	m_score3 = 0;
	m_score4 = 0;
	m_difficult1 = 0;
	m_difficult3 = 0;
	m_examname = _T("");
	//}}AFX_DATA_INIT
}


void CShowCondition::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CShowCondition)
	DDX_Text(pDX, IDC_DIFFICULT2, m_difficult2);
	DDX_Text(pDX, IDC_DIFFICULT4, m_difficult4);
	DDX_Text(pDX, IDC_FULLDIFFICULT, m_fulldifficult);
	DDX_Text(pDX, IDC_FULLSCORE, m_fullscore);
	DDX_Text(pDX, IDC_NUM1, m_num1);
	DDX_Text(pDX, IDC_NUM2, m_num2);
	DDX_Text(pDX, IDC_NUM3, m_num3);
	DDX_Text(pDX, IDC_NUM4, m_num4);
	DDX_Text(pDX, IDC_SCORE1, m_score1);
	DDX_Text(pDX, IDC_SCORE2, m_score2);
	DDX_Text(pDX, IDC_SCORE3, m_score3);
	DDX_Text(pDX, IDC_SCORE4, m_score4);
	DDX_Text(pDX, IDC_DIFFICULT1, m_difficult1);
	DDX_Text(pDX, IDC_DIFFICULT3, m_difficult3);
	DDX_Text(pDX, IDC_EXAMNAME, m_examname);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CShowCondition, CDialog)
	//{{AFX_MSG_MAP(CShowCondition)
	ON_BN_CLICKED(IDC_CHECK1, OnCheck1)
	ON_BN_CLICKED(IDC_CHECK2, OnCheck2)
	ON_BN_CLICKED(IDC_CHECK3, OnCheck3)
	ON_BN_CLICKED(IDC_CHECK4, OnCheck4)
	ON_EN_CHANGE(IDC_DIFFICULT1, OnChangeDifficult1)
	ON_EN_CHANGE(IDC_DIFFICULT2, OnChangeDifficult2)
	ON_EN_CHANGE(IDC_DIFFICULT3, OnChangeDifficult3)
	ON_EN_CHANGE(IDC_DIFFICULT4, OnChangeDifficult4)
	ON_EN_CHANGE(IDC_NUM1, OnChangeNum1)
	ON_EN_CHANGE(IDC_NUM2, OnChangeNum2)
	ON_EN_CHANGE(IDC_NUM3, OnChangeNum3)
	ON_EN_CHANGE(IDC_NUM4, OnChangeNum4)
	ON_EN_CHANGE(IDC_SCORE1, OnChangeScore1)
	ON_EN_CHANGE(IDC_SCORE2, OnChangeScore2)
	ON_EN_CHANGE(IDC_SCORE3, OnChangeScore3)
	ON_EN_CHANGE(IDC_SCORE4, OnChangeScore4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowCondition message handlers

void CShowCondition::ShowData()
{
	UpdateData(true);
	float difficult;
	int score;
	score=0;difficult=0;
	if((m_num1+m_num2+m_num3+m_num4)==0)m_fulldifficult=="0.00";
	else
	{
		difficult=float(m_num1*m_difficult1+m_num2*m_difficult2+m_num3*m_difficult3+m_num4*m_difficult4)/float(m_num1+m_num2+m_num3+m_num4);
		m_fulldifficult.Format("%1.2f",difficult);
	}
	score=m_num1*m_score1+m_num2*m_score2+m_num3*m_score3+m_num4*m_score4;
	m_fullscore.Format("%d",score);
	UpdateData(false);
}

void CShowCondition::OnCheck1() 
{
	CButton *p;
	p=(CButton *)GetDlgItem(IDC_CHECK1);
	if(p->GetCheck())
	{
		p=(CButton *)GetDlgItem(IDC_NUM1);
		p->EnableWindow(true);
		p=(CButton *)GetDlgItem(IDC_DIFFICULT1);
		p->EnableWindow(true);
		p=(CButton *)GetDlgItem(IDC_SCORE1);
		p->EnableWindow(true);	
	}
	else
	{
		p=(CButton *)GetDlgItem(IDC_NUM1);
		p->EnableWindow(false);
		p=(CButton *)GetDlgItem(IDC_DIFFICULT1);
		p->EnableWindow(false);
		p=(CButton *)GetDlgItem(IDC_SCORE1);
		p->EnableWindow(false);
	}
	
}

void CShowCondition::OnCheck2() 
{
	CButton *p;
	p=(CButton *)GetDlgItem(IDC_CHECK2);
	if(p->GetCheck())
	{
		p=(CButton *)GetDlgItem(IDC_NUM2);
		p->EnableWindow(true);
		p=(CButton *)GetDlgItem(IDC_DIFFICULT2);
		p->EnableWindow(true);
		p=(CButton *)GetDlgItem(IDC_SCORE2);
		p->EnableWindow(true);	
	}
	else
	{
		p=(CButton *)GetDlgItem(IDC_NUM2);
		p->EnableWindow(false);
		p=(CButton *)GetDlgItem(IDC_DIFFICULT2);
		p->EnableWindow(false);
		p=(CButton *)GetDlgItem(IDC_SCORE2);
		p->EnableWindow(false);
	}
	
}

void CShowCondition::OnCheck3() 
{
	CButton *p;
	p=(CButton *)GetDlgItem(IDC_CHECK3);
	if(p->GetCheck())
	{
		p=(CButton *)GetDlgItem(IDC_NUM3);
		p->EnableWindow(true);
		p=(CButton *)GetDlgItem(IDC_DIFFICULT3);
		p->EnableWindow(true);
		p=(CButton *)GetDlgItem(IDC_SCORE3);
		p->EnableWindow(true);	
	}
	else
	{
		p=(CButton *)GetDlgItem(IDC_NUM3);
		p->EnableWindow(false);
		p=(CButton *)GetDlgItem(IDC_DIFFICULT3);
		p->EnableWindow(false);
		p=(CButton *)GetDlgItem(IDC_SCORE3);
		p->EnableWindow(false);
	}
//	delete p;
}

void CShowCondition::OnCheck4() 
{
	CButton *p;
	p=(CButton *)GetDlgItem(IDC_CHECK4);
	if(p->GetCheck())
	{
		p=(CButton *)GetDlgItem(IDC_NUM4);
		p->EnableWindow(true);
		p=(CButton *)GetDlgItem(IDC_DIFFICULT4);
		p->EnableWindow(true);
		p=(CButton *)GetDlgItem(IDC_SCORE4);
		p->EnableWindow(true);	
	}
	else
	{
		p=(CButton *)GetDlgItem(IDC_NUM4);
		p->EnableWindow(false);
		p=(CButton *)GetDlgItem(IDC_DIFFICULT4);
		p->EnableWindow(false);
		p=(CButton *)GetDlgItem(IDC_SCORE4);
		p->EnableWindow(false);
	}
//	delete p;
}

BOOL CShowCondition::OnInitDialog() 
{
	CDialog::OnInitDialog();
	pDB=new CADODatabase;
	pDB->Open("driver={SQL Server};Server=HC\\MSSQL2008;DATABASE=abao;");
	pRS=new CADORecordset(pDB);
	m_fullscore="0";
	m_fulldifficult="0.00";
	CButton *p;
	p=(CButton *)GetDlgItem(IDC_NUM1);
	p->EnableWindow(false);
	p=(CButton *)GetDlgItem(IDC_DIFFICULT1);
	p->EnableWindow(false);
	p=(CButton *)GetDlgItem(IDC_SCORE1);
	p->EnableWindow(false);
	p=(CButton *)GetDlgItem(IDC_NUM2);
	p->EnableWindow(false);
	p=(CButton *)GetDlgItem(IDC_DIFFICULT2);
	p->EnableWindow(false);
	p=(CButton *)GetDlgItem(IDC_SCORE2);
	p->EnableWindow(false);
	p=(CButton *)GetDlgItem(IDC_NUM3);
	p->EnableWindow(false);
	p=(CButton *)GetDlgItem(IDC_DIFFICULT3);
	p->EnableWindow(false);
	p=(CButton *)GetDlgItem(IDC_SCORE3);
	p->EnableWindow(false);
	p=(CButton *)GetDlgItem(IDC_NUM4);
	p->EnableWindow(false);
	p=(CButton *)GetDlgItem(IDC_DIFFICULT4);
	p->EnableWindow(false);
	p=(CButton *)GetDlgItem(IDC_SCORE4);
	p->EnableWindow(false);
	UpdateData(false);
//	delete p;
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CShowCondition::OnChangeDifficult1() 
{
	UpdateData();
	if(m_difficult1<1||m_difficult1>5)AfxMessageBox("请键入1到5之间的数");
	ShowData();
	
}

void CShowCondition::OnChangeDifficult2() 
{
	UpdateData();
	if(m_difficult2<1||m_difficult2>5)AfxMessageBox("请键入1到5之间的数");
		ShowData();
}

void CShowCondition::OnChangeDifficult3() 
{
	UpdateData();
	if(m_difficult3<1||m_difficult3>5)AfxMessageBox("请键入1到5之间的数");
		ShowData();
}

void CShowCondition::OnChangeDifficult4() 
{
	UpdateData();
	if(m_difficult4<1||m_difficult4>5)AfxMessageBox("请键入1到5之间的数");
	ShowData();
}

void CShowCondition::OnChangeNum1() 
{
	UpdateData();
	if(m_num1<10||m_num1>20)AfxMessageBox("请键入10到20之间的数");
//	UpdateData(false);
	ShowData();
}

void CShowCondition::OnChangeNum2() 
{
	UpdateData();
	if(m_num2<10||m_num2>20)AfxMessageBox("请键入10到20之间的数");
	ShowData();
}

void CShowCondition::OnChangeNum3() 
{
	UpdateData();
	if(m_num1<3||m_num1>6)AfxMessageBox("请键入3到6之间的数");
	ShowData();
}

void CShowCondition::OnChangeNum4() 
{
	UpdateData();
	if(m_num4<2||m_num4>4)AfxMessageBox("请键入2到4之间的数");
		ShowData();
}

void CShowCondition::OnChangeScore1() 
{
	UpdateData();
	if(m_score1<2||m_score1>4)AfxMessageBox("请键入2到4之间的数");
		ShowData();
}

void CShowCondition::OnChangeScore2() 
{
	UpdateData();
	if(m_score2<1||m_score2>2)AfxMessageBox("请键入1到2之间的数");
		ShowData();
}

void CShowCondition::OnChangeScore3() 
{
	UpdateData();
	if(m_score3<3||m_score3>8)AfxMessageBox("请键入3到8之间的数");
		ShowData();
	
}

void CShowCondition::OnChangeScore4() 
{
	UpdateData();
	if(m_score4<4||m_score4>8)AfxMessageBox("请键入4到8之间的数");
		ShowData();
}

void CShowCondition::OnOK() //自动生成
{
	UpdateData();
	if(m_examname=="")
	{
		AfxMessageBox("请填写试题题目");
		return;
	}
	
	if(m_fulldifficult=="0.00")
	{
		AfxMessageBox("请填写题目难度");
		return;
	}
	if(m_fullscore=="")
	{
		AfxMessageBox("请填写试题数量和分值");
		return;
	}
	_Application WordApp;
	CoInitialize(NULL);
	if(!WordApp.CreateDispatch("Word.Application",NULL))
	{
		AfxMessageBox("创建Word服务失败!");
		exit(1);
		return;
	}
	
	WordApp.SetVisible(TRUE);
	_Document doc;
	Documents docs=WordApp.GetDocuments();
	COleVariant covOptional((long) DISP_E_PARAMNOTFOUND,VT_ERROR);
	doc=docs.Add(covOptional,covOptional,covOptional,covOptional);	
	COleVariant start_line,end_line;
	Range range;
	Table table;
	Tables tables;
	Cell cell;
	Paragraph paragraph;
	Paragraphs paragraphs;
	start_line=end_line=covOptional;
	range=doc.Range(start_line,end_line);
	tables=range.GetTables();
	table=tables.Add(range,11,1,covOptional,covOptional);
	cell=table.Cell(1,1);
	range=cell.GetRange();
	_Font ft=range.GetFont();
	ft.SetSize(20);
	ft.SetName("华文行楷");
	ft.SetColor(RGB(255,55,66));
	range.SetBold(1);
	CString test;
	test="             "+m_examname;
	range.SetText(test);
	range.SetBold(1);
	cell=table.Cell(2,1);
	range=cell.GetRange();
	range.SetBold(1);
	test.Format("                                             试题总分:%s 出题人:_________ ",m_fullscore);
		
	range.SetText(test);
	CButton *p1,*p2,*p3,*p4;
	CString strsql,subject;
	bool flag[4];
	flag[1]=flag[2]=flag[3]=flag[0]=true;
	int i=1;
	p1=(CButton *)GetDlgItem(IDC_CHECK1);
	p2=(CButton *)GetDlgItem(IDC_CHECK2);
	p3=(CButton *)GetDlgItem(IDC_CHECK3);
	p4=(CButton *)GetDlgItem(IDC_CHECK4);
	cell=table.Cell(3,1);
	range=cell.GetRange();
	range.SetBold(1);
	if(p1->GetCheck())
	{
		flag[0]=false;
		test.Format("《%d》：选择题(每题 %d 分，共 %d 题)",i,m_score1,m_num1);
		strsql="select * from ti_choose";
		i++;
	}
	
	else if(p2->GetCheck())
	{
		flag[1]=false;
		test.Format("《%d》：判断题(每题 %d 分，共 %d 题)",i,m_score2,m_num2);
		strsql="select * from ti_judge";
		i++;
	}
	else if(p3->GetCheck())
	{
		flag[2]=false;
		test.Format("《%d》：填空题(每题 %d 分，共 %d 题)",i,m_score3,m_num3);
		strsql="select * from ti_filltext";
		i++;
	}
	else
	{
		flag[3]=false;
		test.Format("《%d》：问答题(每题 %d 分，共 %d 题)",i,m_score4,m_num4);
		strsql="select * from ti_procedure";
		i++;
	}
	
	range.SetText(test);
	srand((unsigned)time(NULL));
	cell=table.Cell(4,1);
	range=cell.GetRange();
	subject=ShowFullSubject(strsql);
	range.SetText(subject);
	cell=table.Cell(5,1);
	range=cell.GetRange();
	test="";
	strsql="";
	range.SetBold(1);
	if(p2->GetCheck())
	{
		if(flag[1])
		{
			flag[1]=false;
			test.Format("《%d》：判断题(每题 %d 分，共 %d 题)",i,m_score2,m_num2);
			strsql="select * from ti_judge";
			i++;
		}
	}
	else if(p3->GetCheck())
	{
		if(flag[2])
		{
			flag[2]=false;
			test.Format("《%d》：填空题(每题 %d 分，共 %d 题)",i,m_score3,m_num3);
			strsql="select * from ti_filltext";
			i++;
		}
	}
	else if(p4->GetCheck())
	{
		if(flag[3])
		{
			flag[3]=false;
			test.Format("《%d》：问答题(每题 %d 分，共 %d 题)",i,m_score4,m_num4);
			strsql="select * from ti_procedure";
			i++;
		}
	}
	range.SetText(test);
	cell=table.Cell(6,1);
	range=cell.GetRange();
	subject=ShowFullSubject(strsql);
	range.SetText(subject);
	cell=table.Cell(7,1);
	test="";
	strsql="";
	range=cell.GetRange();
	range.SetBold(1);
	if(p3->GetCheck())
	{
		if(flag[2])
		{
			flag[2]=false;
			test.Format("《%d》：填空题(每题 %d 分，共 %d 题)",i,m_score3,m_num3);
			strsql="select * from ti_filltext";
			i++;
		}
	}
	else if(p4->GetCheck())
	{
		if(flag[3])
		{
			flag[3]=false;
			test.Format("《%d》：问答题(每题 %d 分，共 %d 题)",i,m_score4,m_num4);
			strsql="select * from ti_procedure";
			i++;
		}
	}
	range.SetText(test);
	cell=table.Cell(8,1);
	range=cell.GetRange();
	subject=ShowFullSubject(strsql);
	range.SetText(subject);
	cell=table.Cell(9,1);
	test="";
	strsql="";
	range=cell.GetRange();
	range.SetBold(1);
	if(p4->GetCheck())
	{
		if(flag[3])test.Format("《%d》：问答题(每题 %d 分，共 %d 题)",i,m_score4,m_num4);
		strsql="select * from ti_procedure";
	}
	range.SetText(test);
	cell=table.Cell(10,1);
	range=cell.GetRange();

	subject=ShowFullSubject(strsql);
	range.SetText(subject);
	ft.ReleaseDispatch();
	docs.ReleaseDispatch();		//Documents 也不用了
	WordApp.ReleaseDispatch();	
	CDialog::OnOK();
}

CString CShowCondition::ShowFullSubject(CString strsql)
{
	UpdateData();
	CString strsqladd,str1,str2,str3,str4,str5;
	CString subject;
	CString subjectnum;
	subject="";
	int count,getrand;
	int i;
	count=getrand=0;
	int label=1;
	if(strsql=="select * from ti_choose")
	{
		pRS->Open(_bstr_t(strsql),CADORecordset.openQuery);
		if(!pRS->IsOpen())return"";
		if(pRS->GetRecordCount()<=0)return"";
		count=pRS->GetRecordCount();
		pRS->Close();
		for(i=0;i<m_num1;i++)
		{
			strsql="select * from ti_choose";
			getrand=rand()%(count+1);
			strsqladd.Format(" where number=%d",getrand);
			strsql+=strsqladd;
			pRS->Open(_bstr_t(strsql),CADORecordset.openQuery);
			if(!pRS->IsOpen())return"";
			if(pRS->GetRecordCount()<=0)return"";
			pRS->MoveFirst();
			pRS->GetFieldValue("tigan",str1);
			pRS->GetFieldValue("xa",str2);
			pRS->GetFieldValue("xb",str3);
			pRS->GetFieldValue("xc",str4);
			pRS->GetFieldValue("xd",str5);
			subjectnum.Format("(%d).",i+1);
			subject+=subjectnum+str1+"(  )\r\n   "+str2+"\r\n   "+str3+"\r\n    "+str4+"\r\n   "+str5+"\r\n";
			pRS->Close();
		}
		
	}
	if(strsql=="select * from ti_judge")
	{
		pRS->Open(_bstr_t(strsql),CADORecordset.openQuery);
		if(!pRS->IsOpen())return"";
		if(pRS->GetRecordCount()<=0)return"";
		count=pRS->GetRecordCount();
		pRS->Close();
		for(i=0;i<m_num2;i++)
		{
			strsql="select * from ti_judge";
			getrand=rand()%(count+1);
			strsqladd.Format(" where number=%d",getrand);
			strsql+=strsqladd;
			pRS->Open(_bstr_t(strsql),CADORecordset.openQuery);
			if(!pRS->IsOpen())return"";
			if(pRS->GetRecordCount()<=0)return"";
			pRS->MoveFirst();
			pRS->GetFieldValue("tigan",str1);
			subjectnum.Format("(%d).",i+1);
			subject+=subjectnum+str1+"(  )"+"\r\n";
			pRS->Close();
		}
	}
	if(strsql=="select * from ti_filltext")
	{
		pRS->Open(_bstr_t(strsql),CADORecordset.openQuery);
		if(!pRS->IsOpen())return"";
		if(pRS->GetRecordCount()<=0)return"";
		count=pRS->GetRecordCount();
		pRS->Close();
		for(i=0;i<m_num3;i++)
		{
			strsql="select * from ti_filltext";
			getrand=rand()%(count+1);
			strsqladd.Format(" where number=%d",getrand);
			strsql+=strsqladd;
			pRS->Open(_bstr_t(strsql),CADORecordset.openQuery);
			if(!pRS->IsOpen())return"";
			if(pRS->GetRecordCount()<=0)return"";
			pRS->MoveFirst();
			pRS->GetFieldValue("tigan",str1);
			subjectnum.Format("(%d).",i+1);
			subject+=subjectnum+str1+"\r\n";
			pRS->Close();
		}
	}
	if(strsql=="select * from ti_procedure")
	{
		pRS->Open(_bstr_t(strsql),CADORecordset.openQuery);
		if(!pRS->IsOpen())return"";
		if(pRS->GetRecordCount()<=0)return"";
		count=pRS->GetRecordCount();
		pRS->Close();
		for(i=0;i<m_num4;i++)
		{
			strsql="select * from ti_procedure";
			getrand=rand()%(count+1);
			strsqladd.Format(" where number=%d",getrand);
			strsql+=strsqladd;
			pRS->Open(_bstr_t(strsql),CADORecordset.openQuery);
			if(!pRS->IsOpen())return"";
			if(pRS->GetRecordCount()<=0)return"";
			pRS->MoveFirst();
			pRS->GetFieldValue("tigan",str1);
			subjectnum.Format("(%d).",i+1);
			subject+=subjectnum+str1+"\r\n\r\n\r\n\r\n";
			pRS->Close();
		}
	}
	return subject;
}
