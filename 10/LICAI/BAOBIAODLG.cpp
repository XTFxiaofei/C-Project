// BAOBIAODLG.cpp : implementation file
//

#include "stdafx.h"
#include "licai.h"
#include "BAOBIAODLG.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// BAOBIAODLG dialog


BAOBIAODLG::BAOBIAODLG(CWnd* pParent /*=NULL*/)
	: CDialog(BAOBIAODLG::IDD, pParent)
{
	//{{AFX_DATA_INIT(BAOBIAODLG)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void BAOBIAODLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(BAOBIAODLG)
	DDX_Control(pDX, IDC_LIST1, m_list);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(BAOBIAODLG, CDialog)
	//{{AFX_MSG_MAP(BAOBIAODLG)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// BAOBIAODLG message handlers

BOOL BAOBIAODLG::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	pdb=new CDatabase;
	mySet=new LCSet(pdb);
	mySet->Open();	
	m_list.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
    m_list.InsertColumn(0,"统计时间",LVCFMT_CENTER,93);
    m_list.InsertColumn(1,"总收入数目(元)",LVCFMT_CENTER,125);
    m_list.InsertColumn(2,"总支出数目(元)",LVCFMT_CENTER,125);  
	m_list.InsertColumn(3,"总盈余数目(元)",LVCFMT_CENTER,150);
	LOADDATA();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void BAOBIAODLG::LOADDATA()
{
	bool tflag1,tflag2,tflag3;   //他们分别用来判断是否两个字符串匹配
	mySet->Requery();
	m_list.DeleteAllItems();
	int incomenum1=0,costnum1=0,total1=0,incomenum2=0;
	int costnum2=0,total2=0,incomenum3=0,costnum3=0,total3=0;
	CString dstr,dstr1,dstr2,mstr,mstr1,mstr2,ystr,ystr1,ystr2;    //把数据转换成字符串
	COleDateTime oleDt=COleDateTime::GetCurrentTime();
	CString stime=oleDt.Format("%Y-%m-%d %H:%M:%S");
	while(!mySet->IsEOF())
	{   
		for(int i=0;i<10;i++)     //i用来指明字符串下标
		{
			if(mySet->m_time[i]==stime[i])
				tflag1=true;
			else 
			{
				tflag1=false;
				break;
			}
		}
		if(tflag1)
		{
			incomenum1=incomenum1+mySet->m_incomenum;
			costnum1=costnum1+mySet->m_costnum;
		}
		for(int j=0;j<7;j++)     //j用来指明字符串下标
		{
			if(mySet->m_time[j]==stime[j])
				tflag2=true;
			else 
			{
				tflag2=false;
				break;
			}
		}
		if(tflag2)
		{
			incomenum2=incomenum2+mySet->m_incomenum;
			costnum2=costnum2+mySet->m_costnum;
		}
		for(int n=0;n<4;n++)     //n用来指明字符串下标
		{
			if(mySet->m_time[n]==stime[n])
				tflag3=true;
			else 
			{
				tflag3=false;
				break;
			}
		}
		if(tflag3)
		{
			incomenum3=incomenum3+mySet->m_incomenum;
			costnum3=costnum3+mySet->m_costnum;
		}
		mySet->MoveNext();
	}
	total1=incomenum1-costnum1;
	total2=incomenum2-costnum2;
	total3=incomenum3-costnum3;

	dstr.Format("%d",incomenum1);
	dstr1.Format("%d",costnum1);
	dstr2.Format("%d",total1);
	mstr.Format("%d",incomenum2);
	mstr1.Format("%d",costnum2);
	mstr2.Format("%d",total2);
	ystr.Format("%d",incomenum3);
	ystr1.Format("%d",costnum3);
	ystr2.Format("%d",total3);
	m_list.InsertItem(0,"今日统计");
   	m_list.SetItemText(0,1,dstr);
   	m_list.SetItemText(0,2,dstr1);
   	m_list.SetItemText(0,3,dstr2);
	m_list.InsertItem(1,"");
   	m_list.SetItemText(1,1,"");
   	m_list.SetItemText(1,2,"");
   	m_list.SetItemText(1,3,"");
	m_list.InsertItem(2,"目前本月统计");
	m_list.SetItemText(2,1,mstr);
	m_list.SetItemText(2,2,mstr1);
	m_list.SetItemText(2,3,mstr2);
	m_list.InsertItem(3,"");
   	m_list.SetItemText(3,1,"");
   	m_list.SetItemText(3,2,"");
   	m_list.SetItemText(3,3,"");
	m_list.InsertItem(4,"本年度统计");
	m_list.SetItemText(4,1,ystr);
	m_list.SetItemText(4,2,ystr1);
	m_list.SetItemText(4,3,ystr2);
	mySet->Close();
}
