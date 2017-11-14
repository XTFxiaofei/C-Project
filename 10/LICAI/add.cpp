// add.cpp : implementation file
//

#include "stdafx.h"
#include "licai.h"
#include "add.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// add dialog


add::add(CWnd* pParent /*=NULL*/)
	: CDialog(add::IDD, pParent)
{
	//{{AFX_DATA_INIT(add)
	m_id = 0;
	m_time = _T("");
	m_incomenum = 0;
	m_costnum = 0;
	m_about = _T("");
	//}}AFX_DATA_INIT
}


void add::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(add)
	DDX_Control(pDX, IDC_COMBO2, m_costtype);
	DDX_Control(pDX, IDC_COMBO1, m_incometype);
	DDX_Text(pDX, IDC_EDIT1, m_id);
	DDX_Text(pDX, IDC_EDIT5, m_time);
	DDX_Text(pDX, IDC_EDIT2, m_incomenum);
	DDX_Text(pDX, IDC_EDIT3, m_costnum);
	DDX_Text(pDX, IDC_EDIT4, m_about);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(add, CDialog)
	//{{AFX_MSG_MAP(add)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// add message handlers

BOOL add::OnInitDialog() 
{
	CDialog::OnInitDialog();
	int k1=-1,k2=-1;	
    m_incometype.InsertString(0,"原有资金");
    m_incometype.InsertString(1,"工资收入");
	m_incometype.InsertString(2,"奖金");
    m_incometype.InsertString(3,"各类津贴补贴");
	m_incometype.InsertString(4,"亲友馈赠");
    m_incometype.InsertString(5,"经营所得资金");
	m_incometype.InsertString(6,"投资所得");
    m_incometype.InsertString(7,"其它各类收入");

    m_costtype.InsertString(0,"基本生活费支出");
    m_costtype.InsertString(1,"医疗保健支出");
	m_costtype.InsertString(2,"通信支出");
    m_costtype.InsertString(3,"教育费");
	m_costtype.InsertString(4,"休闲娱乐支出");
	m_costtype.InsertString(5,"购物消费支出");
    m_costtype.InsertString(6,"各类保养维护支出");
	m_costtype.InsertString(7,"投资支出");
	m_costtype.InsertString(8,"其它支出");
	if(addflag)
	{
		COleDateTime oleDt=COleDateTime::GetCurrentTime();
		CString strFileName=oleDt.Format("%Y-%m-%d %H:%M:%S");
		m_time=strFileName;
	    UpdateData(false);
		m_costtype.SetCurSel(0);
		costtype="基本生活费支出";
		m_incometype.SetCurSel(0);
		incometype="原有资金";
		SetWindowText("添加收入支出信息");
	}	    
	else 
	{
		if(incometype=="原有资金")
			k1=0;
		if(incometype=="工资收入")
			k1=1;
		if(incometype=="奖金")
			k1=2;
		if(incometype=="各类津贴补贴")
			k1=3;
		if(incometype=="亲友馈赠")
			k1=4;
		if(incometype=="经营所得资金")
			k1=5;
		if(incometype=="投资所得")
			k1=6;
		if(incometype=="其它各类收入")
			k1=7;

		if(costtype=="基本生活费支出")
			k2=0;
		if(costtype=="医疗保健支出")
			k2=1;
		if(costtype=="通信支出")
			k2=2;
		if(costtype=="教育费")
			k2=3;
		if(costtype=="休闲娱乐支出")
			k2=4;
		if(costtype=="购物消费支出")
			k2=5;
		if(costtype=="各类保养维护支出")
			k2=6;
		if(costtype=="投资支出")
			k2=7;
		if(costtype=="其它支出")
			k2=8;
		m_incometype.SetCurSel(k1);
		m_costtype.SetCurSel(k2);
		SetWindowText("修改收支信息");
	}
	return TRUE;
}

void add::OnOK() 
{
	int i,j;
	i=m_incometype.GetCurSel();
	j=m_costtype.GetCurSel();
    m_incometype.GetLBText(i,incometype);	
    m_costtype.GetLBText(j,costtype);	
	CDialog::OnOK();
}
