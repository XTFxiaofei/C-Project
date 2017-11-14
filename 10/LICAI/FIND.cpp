// FIND.cpp : implementation file
//

#include "stdafx.h"
#include "licai.h"
#include "FIND.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
//monthflag=false;
/////////////////////////////////////////////////////////////////////////////
// FIND dialog


FIND::FIND(CWnd* pParent /*=NULL*/)
	: CDialog(FIND::IDD, pParent)
{
	//{{AFX_DATA_INIT(FIND)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void FIND::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(FIND)
	DDX_Control(pDX, IDC_foryear, m_foryear);
	DDX_Control(pDX, IDC_COMBO3, m_day);
	DDX_Control(pDX, IDC_COMBO2, m_month);
	DDX_Control(pDX, IDC_COMBO1, m_year);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(FIND, CDialog)
	//{{AFX_MSG_MAP(FIND)
	ON_COMMAND_RANGE(IDC_foryear,IDC_month,GetSelTime)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// FIND message handlers

BOOL FIND::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_foryear.SetCheck(1);  //默认在年那里
	m_year.InsertString(0,"2006");
	m_year.InsertString(1,"2007");
	m_year.InsertString(2,"2008");
	m_year.InsertString(3,"2009");
	m_year.InsertString(4,"2010");
	m_year.InsertString(5,"2011");
	m_month.InsertString(0,"01");
	m_month.InsertString(1,"02");
	m_month.InsertString(2,"03");
	m_month.InsertString(3,"04");
	m_month.InsertString(4,"05");
	m_month.InsertString(5,"06");
	m_month.InsertString(6,"07");
	m_month.InsertString(7,"08");
	m_month.InsertString(8,"09");
	m_month.InsertString(9,"10");
	m_month.InsertString(10,"11");
	m_month.InsertString(11,"12");
	m_day.InsertString(0,"01");
	m_day.InsertString(1,"02");
	m_day.InsertString(2,"03");
	m_day.InsertString(3,"04");
	m_day.InsertString(4,"05");
	m_day.InsertString(5,"06");
	m_day.InsertString(6,"07");
	m_day.InsertString(7,"08");
	m_day.InsertString(8,"09");
	m_day.InsertString(9,"10");
	m_day.InsertString(10,"11");
	m_day.InsertString(11,"12");
	m_day.InsertString(12,"13");
	m_day.InsertString(13,"14");
	m_day.InsertString(14,"15");
	m_day.InsertString(15,"16");
	m_day.InsertString(16,"17");
	m_day.InsertString(17,"18");
	m_day.InsertString(18,"19");
	m_day.InsertString(19,"20");
	m_day.InsertString(20,"21");
	m_day.InsertString(22,"23");
	m_day.InsertString(21,"22");
	m_day.InsertString(23,"24");
	m_day.InsertString(24,"25");
	m_day.InsertString(25,"26");
	m_day.InsertString(26,"27");
	m_day.InsertString(27,"28");
	m_day.InsertString(28,"29");
	m_day.InsertString(29,"30");
	m_day.InsertString(30,"31");

	m_year.SetCurSel(0);
	year="2006";
	month="01";
	day="01";
	m_month.SetCurSel(0);
	m_day.SetCurSel(0);
	m_month.EnableWindow(false);
	m_day.EnableWindow(false);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void FIND::GetSelTime(UINT nID)
{
	switch(nID)
	{
	case IDC_foryear:
		m_year.EnableWindow(true);
		m_month.EnableWindow(false);
		m_day.EnableWindow(false);	
		monthflag=true;
		yearflag=true;
		break;
	case IDC_formonth:
		m_year.EnableWindow(true);
		m_month.EnableWindow(true);
		m_day.EnableWindow(false);	
		monthflag=true;
		yearflag=false;
		timeflag=true;
		break;
	case IDC_forday:	
		m_year.EnableWindow(true);
		m_month.EnableWindow(true);
		m_day.EnableWindow(true);
		monthflag=true;
		yearflag=false;
		timeflag=false;
		break;
	case IDC_month:	
		m_year.EnableWindow(false);
		m_month.EnableWindow(true);
		m_day.EnableWindow(false);	
		monthflag=false;
		break;
	}
}

void FIND::OnOK() 
{
	int i,j,k;//分别用来记录选择了哪条记录
	i=m_year.GetCurSel();
    m_year.GetLBText(i,year);	//记录对应的值	
	j=m_month.GetCurSel();
    m_month.GetLBText(j,month);
	k=m_day.GetCurSel();
    m_day.GetLBText(k,day);
	if(monthflag)
	{	
		if(yearflag)	
		time=year;//查找年份
		else
		{
			if(timeflag)
				time=year+"-"+month;//如果查找年月的话
			else
				time=year+"-"+month+"-"+day;//查找年月日
		}
	}
	else
		time="-"+month+"-";
	CDialog::OnOK();
}

