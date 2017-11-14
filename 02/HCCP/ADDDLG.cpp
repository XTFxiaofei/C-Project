// ADDDLG.cpp : implementation file
//

#include "stdafx.h"
#include "HCCP.h"
#include "ADDDLG.h"
#include "ADOConn.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ADDDLG dialog


ADDDLG::ADDDLG(CWnd* pParent /*=NULL*/)
	: CDialog(ADDDLG::IDD, pParent)
{
	//{{AFX_DATA_INIT(ADDDLG)
	m_name = _T("");
	m_cno = _T("");
	m_cgrade = 0.0f;
	//}}AFX_DATA_INIT
}


void ADDDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ADDDLG)
	DDX_Control(pDX, IDC_XHAO, m_xhao);
	DDX_Control(pDX, IDC_CHECK1, m_xuanze);
	DDX_Control(pDX, IDC_MZ, m_mz);
	DDX_Text(pDX, IDC_NAME, m_name);
	DDX_Text(pDX, IDC_CNO, m_cno);
	DDX_Text(pDX, IDC_CGRADE, m_cgrade);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ADDDLG, CDialog)
	//{{AFX_MSG_MAP(ADDDLG)
	ON_BN_CLICKED(IDC_CHECK1, OnCheck1)
	ON_CBN_SELCHANGE(IDC_XHAO, OnSelchangeXhao)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ADDDLG message handlers

BOOL ADDDLG::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CString str;
	
	//通过选择树节点的层数来判断添加对话框的属性

	switch(nCount)
	{
	case 1:		
		str.Format("添加新院系");  
		GetDlgItem(IDC_CHECK1)->ShowWindow(false);
		GetDlgItem(IDC_XHAO)->ShowWindow(false);
		GetDlgItem(IDC_KECHENGHAO)->ShowWindow(false);
		GetDlgItem(IDC_XXUEFEN)->ShowWindow(false);
		GetDlgItem(IDC_CNO)->ShowWindow(false);
		GetDlgItem(IDC_CGRADE)->ShowWindow(false);
		SetWindowText(str);
		m_mz.SetWindowText("新院系名：");break;
	case 2:
		str.Format("添加新班级");
		GetDlgItem(IDC_CHECK1)->ShowWindow(false);
		GetDlgItem(IDC_XHAO)->ShowWindow(false);
		GetDlgItem(IDC_KECHENGHAO)->ShowWindow(false);
		GetDlgItem(IDC_XXUEFEN)->ShowWindow(false);
		GetDlgItem(IDC_CNO)->ShowWindow(false);
		GetDlgItem(IDC_CGRADE)->ShowWindow(false);
		SetWindowText(str);
		m_mz.SetWindowText("新班级名：");break;
	case 3:
		str.Format("添加新课程");
		GetDlgItem(IDC_XHAO)->ShowWindow(false);
		SetWindowText(str);
		m_mz.SetWindowText("新课程名：");break;
	case 4:		
		str.Format("添加新成绩");
		GetDlgItem(IDC_CHECK1)->ShowWindow(false);
		GetDlgItem(IDC_KECHENGHAO)->SetWindowText("学生学号：");
		GetDlgItem(IDC_XXUEFEN)->SetWindowText("课程成绩：");
		GetDlgItem(IDC_CNO)->ShowWindow(false);
		SetWindowText(str);
		XueSheng();
		m_mz.SetWindowText("学生名：");break;
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

/*---------------------------初始化添加成绩对话框的属性-----------------------------*/

void ADDDLG::XueSheng()
{
	k=0;
	str2=leaf11;  //通过全局变量获取到鼠标选择的节点的父节点信息
	str2.TrimRight();
	str.Format("select * from student where sclass='%s'",str2);  //获取已选取该课程的学生信息
	sQL=(_bstr_t)str;
	m_pRc=myado.GetRecordSet(sQL);  //执行sql语句并获取student记录集
	leaf=m_pRc->GetCollect("sname");  //获取记录集中学生姓名	
	str1=(LPCTSTR)(_bstr_t)leaf;  
	str1.TrimRight();
	m_name=str1;  //初始化显示第一个学生的姓名
	leaf=m_pRc->GetCollect("sno");  //获取记录集中学生学号 		
	str1=(LPCTSTR)(_bstr_t)leaf;
	str1.TrimRight();
	zhao=str1;
	do  //通过while循环读取记录集内容并关联到下拉菜单内容
	{
		leaf=m_pRc->GetCollect("sno");		
		str1=(LPCTSTR)(_bstr_t)leaf;
		str1.TrimRight();
		m_xhao.InsertString(k,str1);  //添加组合框条目
		m_pRc->MoveNext();  //指向下一条记录
		k++;
	}
	while(!m_pRc->adoEOF);

	m_xhao.SetCurSel(0);  //初始化combo控件为显示第一条记录
	UpdateData(false);
}

/*---------------------------通过check控件切换添加新成员和新课程-----------------------------*/

void ADDDLG::OnCheck1() 
{
	CString str;
	if(m_xuanze.GetCheck())
	{
		str.Format("添加新成员");
		GetDlgItem(IDC_KECHENGHAO)->SetWindowText("学生学号：");
		GetDlgItem(IDC_XXUEFEN)->ShowWindow(false);
		GetDlgItem(IDC_XXUEFEN)->SetWindowText("课程成绩：");
		GetDlgItem(IDC_CGRADE)->ShowWindow(false);
		SetWindowText(str);
		m_mz.SetWindowText("新学生名：");
		flag001=false;
	}
	else
	{
		str.Format("添加新课程");
		GetDlgItem(IDC_KECHENGHAO)->SetWindowText("课程号：");
		GetDlgItem(IDC_XXUEFEN)->ShowWindow(true);
		GetDlgItem(IDC_XXUEFEN)->SetWindowText("学分：");
		GetDlgItem(IDC_CGRADE)->ShowWindow(true);
		SetWindowText(str);
		m_mz.SetWindowText("新课程名：");
		flag001=true;
	}
}

/*---------------------------为combo控件添加消息-----------------------------*/

void ADDDLG::OnSelchangeXhao() 
{
	
	CString str;
	int n=m_xhao.GetCurSel();  //获取所选择combo控件中内容的编号
	m_xhao.GetLBText(n,zhao);  //通过编号获取到选择项目的内容
	str.Format("select sname from student where sno='%s'",zhao);  //在student表中查找对应学号的记录
	_bstr_t vSQL;
	vSQL=(_bstr_t)str;
	m_pRc=myado.GetRecordSet(vSQL);  //执行sql语句并获取记录集
	
	leaf=m_pRc->GetCollect("sname");  //获取记录集中sname的内容
	str1=(LPCTSTR)(_bstr_t)leaf;  
	str1.TrimRight();
	
	m_name=str1;  //显示学生姓名
	UpdateData(false);
}
