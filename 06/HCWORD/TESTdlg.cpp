// TESTdlg.cpp : implementation file
//

#include "stdafx.h"
#include "HCWORD.h"
#include "TESTdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
int sum=0;

/////////////////////////////////////////////////////////////////////////////
// TESTdlg dialog


TESTdlg::TESTdlg(CWnd* pParent /*=NULL*/)
	: CDialog(TESTdlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(TESTdlg)
	answer = -1;
	m_test = _T("");
	m_test1 = _T("");
	m_test2 = _T("");
	m_test3 = _T("");
	m_test4 = _T("");
	//}}AFX_DATA_INIT
}


void TESTdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(TESTdlg)
	DDX_Text(pDX, IDC_EDIT1, m_test);
	DDX_Text(pDX, IDC_EDIT2, m_test1);
	DDX_Text(pDX, IDC_EDIT3, m_test2);
	DDX_Text(pDX, IDC_EDIT4, m_test3);
	DDX_Text(pDX, IDC_EDIT5, m_test4);
	DDX_Control(pDX, IDC_EDIT1, m_resultControl);
	DDX_Control(pDX, IDC_EDIT2, m_resultControl1);
	DDX_Control(pDX, IDC_EDIT3, m_resultControl2);
	DDX_Control(pDX, IDC_EDIT4, m_resultControl3);
	DDX_Control(pDX, IDC_EDIT5, m_resultControl4);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(TESTdlg, CDialog)
	//{{AFX_MSG_MAP(TESTdlg)
	ON_COMMAND_RANGE(IDC_RADIO1,IDC_RADIO4,Answer)
	ON_BN_CLICKED(IDC_NEXT, OnNext)
	ON_BN_CLICKED(IDC_SELECT, OnSelect)
	ON_BN_CLICKED(IDC_SUBMIT, OnSubmit)
	ON_BN_CLICKED(IDC_SUM, OnSum)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// TESTdlg message handlers

void TESTdlg::Answer(UINT nID) 
{
	switch(nID)
	{
	case IDC_RADIO1:answer=0;break;
	case IDC_RADIO2:answer=1;break;
	case IDC_RADIO3:answer=2;break;
	case IDC_RADIO4:answer=3;break;
	}
}

BOOL TESTdlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	GetDlgItem(IDC_SUBMIT)->EnableWindow(false);    //按钮的禁用
	GetDlgItem(IDC_NEXT)->EnableWindow(false);
	GetDlgItem(IDC_SUM)->EnableWindow(false);

	CString result,result1,result2,result3,result4;
	result.Format("%s",m_test);
	m_resultControl.SetFontSize(15);                 //设置字体的颜色
	m_resultControl.SetTextColor(RGB(0,0,255));      //设置文本的颜色
	m_resultControl.SetBkColor(RGB(255,255,255));          //设置背景颜色
	m_resultControl.SetFontBold(TRUE);
	m_resultControl.SetText(result);

	result1.Format("%s",m_test1);
	m_resultControl1.SetFontSize(15);
	m_resultControl1.SetTextColor(RGB(0,0,255));
    m_resultControl1.SetBkColor(RGB(255,255,255));
	m_resultControl1.SetFontBold(TRUE);
	m_resultControl1.SetText(result1);

	result2.Format("%s",m_test2);
	m_resultControl2.SetFontSize(15);
	m_resultControl2.SetTextColor(RGB(0,0,255));
    m_resultControl2.SetBkColor(RGB(255,255,255));
	m_resultControl2.SetFontBold(TRUE);
	m_resultControl2.SetText(result2);

	result3.Format("%s",m_test3);
	m_resultControl3.SetFontSize(15);
	m_resultControl3.SetTextColor(RGB(0,0,255));
    m_resultControl3.SetBkColor(RGB(255,255,255));
	m_resultControl3.SetFontBold(TRUE);
	m_resultControl3.SetText(result3);

	result4.Format("%s",m_test4);
	m_resultControl4.SetFontSize(15);
	m_resultControl4.SetTextColor(RGB(0,0,255));
    m_resultControl4.SetBkColor(RGB(255,255,255));
	m_resultControl4.SetFontBold(TRUE);
	m_resultControl4.SetText(result4);
	pdb=new CDatabase;
    pdb->Open("ODBC;DSN=词库;Trusted_Connection=Yes;");
    m_pset=new TKSet(pdb);
    return TRUE;  	             
}

void TESTdlg::OnNext() 
{
	CString str;
	if(m_pset->IsEOF())
		MessageBox("题目测试完毕！");
	else
	{
		m_pset->MoveNext();
		str.Format("题号%d:",m_pset->m_id);
		m_test=str+m_pset->m_tm;
		m_test1=m_pset->m_xuanx1;
		m_test2=m_pset->m_xuanx2;
		m_test3=m_pset->m_xuanx3;
		m_test4=m_pset->m_xuanx4;
		UpdateData(false);
	}	
}

void TESTdlg::OnSelect() 
{
	UpdateData();                                       
	CString strsql,str,str1;
	int tt,m[7],temp,y;
	for(int k=0;k<7;k++)
		m[k]=k;
	for(int i=0;i<3;i++)
	{
		tt=rand()%(7-i-1);//随机选题
		temp=m[i];
		m[i]=m[tt+i];
		m[tt+i]=temp;	
	}
	for(int j=0;j<3;j++)
	{
		for(int k=j+1;k<3;k++)
			if(m[j]>m[k])
			{
				y=m[j];
				m[j]=m[k];
				m[k]=y;
			}	
	}
	strsql.Format("select * from TK where id=%d or id=%d or id=%d",m[0],m[1],m[2]);
	m_pset->Open(AFX_DB_USE_DEFAULT_TYPE,strsql);
	str.Format("%d:",m_pset->m_id);
	m_test=str+m_pset->m_tm;
	m_test1=m_pset->m_xuanx1;
	m_test2=m_pset->m_xuanx2;
	m_test3=m_pset->m_xuanx3;
	m_test4=m_pset->m_xuanx4;
	UpdateData(false);
	GetDlgItem(IDC_SELECT)->EnableWindow(false);
	GetDlgItem(IDC_NEXT)->EnableWindow(true);
	GetDlgItem(IDC_SUBMIT)->EnableWindow(true);
	GetDlgItem(IDC_SUM)->EnableWindow(true);	
}

void TESTdlg::OnSubmit() 
{
	CString str,temp,dbtemp[4];
	dbtemp[0]=m_pset->m_xuanx1;
	dbtemp[1]=m_pset->m_xuanx2;
	dbtemp[2]=m_pset->m_xuanx3;
	dbtemp[3]=m_pset->m_xuanx4;
	temp=m_pset->m_da;
	if(temp==dbtemp[answer])//判断是否匹配
	{
		MessageBox("恭喜你答对了"); 
		sum++;
	}
	else
	{
		str.Format("答错了，正确答案是%s",temp);
		MessageBox(str);	
	}
}

void TESTdlg::OnSum() 
{
	CString str;
	str.Format("你总共答对%d题目",sum);
	MessageBox(str);	
}
