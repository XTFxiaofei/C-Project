// AnswZigeChekDlg.cpp : implementation file
//

#include "stdafx.h"
#include "gradudemis.h"
#include "AnswZigeChekDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// AnswZigeChekDlg dialog


AnswZigeChekDlg::AnswZigeChekDlg(CWnd* pParent /*=NULL*/)
	: CDialog(AnswZigeChekDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(AnswZigeChekDlg)
	m_strAttDays = _T("");
	m_strCompuLevel = _T("");
	m_strHoliDays = _T("");
	m_strYDaoDays = _T("");
	m_strEngLevel = _T("");
	m_strResult = _T("");
	m_strColiResult = _T("");
	//}}AFX_DATA_INIT
}

void AnswZigeChekDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(AnswZigeChekDlg)
	DDX_Control(pDX, IDC_StuName_COMBO, m_ctrlStuName);
	DDX_Control(pDX, IDC_Class_COMBO, m_ctrlClass);
	DDX_Text(pDX, IDC_EDIT_AttDays, m_strAttDays);
	DDX_Text(pDX, IDC_EDIT_CompuLevel, m_strCompuLevel);
	DDX_Text(pDX, IDC_EDIT_HoliDays, m_strHoliDays);
	DDX_Text(pDX, IDC_EDIT_YDaoDays, m_strYDaoDays);
	DDX_Text(pDX, IDC_EDIT_EngLevel, m_strEngLevel);
	DDX_Text(pDX, IDC_EDIT_Result, m_strResult);
	DDX_Text(pDX, IDC_EDIT_ColiResult, m_strColiResult);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(AnswZigeChekDlg, CDialog)
	//{{AFX_MSG_MAP(AnswZigeChekDlg)
	ON_CBN_SELCHANGE(IDC_StuName_COMBO, OnSelchangeStuNameCOMBO)
	ON_CBN_SELCHANGE(IDC_Class_COMBO, OnSelchangeClassCOMBO)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// AnswZigeChekDlg message handlers

//初始化函数
BOOL AnswZigeChekDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	// TODO: Add extra initialization here
    m_ctrlClass.InsertString(0,"信息021");					//向下拉框中插入数据
    m_ctrlClass.InsertString(1,"信息022");
    m_ctrlClass.SetCurSel(0);
	CString strSQL;
	int i=0;
    strSQL="select * from tab_stu where stu_class='信息021'";//查询所有班级为'信息021'的所有学生信息
	if(!stuSet.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败！");
	    return false;
	}
	while(!stuSet.IsEOF())									//遍历所有数据
	{
		m_ctrlStuName.InsertString(i,stuSet.m_stu_name);	//将学生姓名插入到列表框中
		stuSet.MoveNext();									//移动到下一条记录
		i++;
	}
	m_ctrlStuName.SetCurSel(0);								//默认选择第一项
	stuSet.Close();											//关闭记录集
 //	OnSelchangeStuNameCOMBO();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE

}

void AnswZigeChekDlg::OnSelchangeClassCOMBO() 
{
	// TODO: Add your control notification handler code here
	int m=0 ,k=0;
	  m=m_ctrlStuName.GetCount();							//获取学生的总数
	for(int i=0;i<m;i++)									
		m_ctrlStuName.DeleteString(0);						//清空下拉列表框
	CString strSQL,strClass;
	m_ctrlClass.GetWindowText(strClass);					//空间中的获取文本
	if(strClass=="信息021")
	    strSQL="select * from tab_stu where stu_class='信息021'";//查询班级为相应文本的所有信息
	else
		strSQL="select * from tab_stu where stu_class='信息022'";
	if(!stuSet.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))		//sql语句打开记录集
	{
		MessageBox("打开数据库失败！");
	    return ;
	}
	while(!stuSet.IsEOF())									//遍历所有的记录
	{
		m_ctrlStuName.InsertString(k,stuSet.m_stu_name);	//插入学生的姓名
		stuSet.MoveNext();									//移动到下一条记录
		k++;
	}
	m_ctrlStuName.SetCurSel(0);								//默认选择第一项
	stuSet.Close();											//关闭记录集
}

void AnswZigeChekDlg::OnSelchangeStuNameCOMBO() 
{
	// TODO: Add your control notification handler code here
   	int m=0,i=0;
	m=m_ctrlStuName.GetCount();							//获取总数
	CString strStuName;
	m_ctrlStuName.GetWindowText(strStuName);				//获取控件的文本
	if(kqsumSet.IsOpen())									//打开你记录集
		kqsumSet.Close();
	kqsumSet.Open();
    while(!kqsumSet.IsEOF())								//遍历记录集
	{
		if(kqsumSet.m_stu_name==strStuName)					//查找当前学生
		{	
			m_strAttDays=kqsumSet.m_stu_attDays;			//获取学生的出勤天数
			m_strHoliDays=kqsumSet.m_stu_holiDays;			//请假天数
			m_strYDaoDays=kqsumSet.m_stu_YDaoDays;			//应到天数
			break;
		}
		else
			kqsumSet.MoveNext();							//移动到下条记录
	}
	kqsumSet.Close();										//关闭记录集
	if(!pstuachieveSet.IsOpen())							//打开学生是否可以进行答辩记录集
	   pstuachieveSet.Open();
	pstuachieveSet.MoveFirst();								//移动到第一条记录
    while(!pstuachieveSet.IsEOF())							//遍历记录
	{
		if(pstuachieveSet.m_stu_name==strStuName)			//查询学生姓名
		{
            m_strCompuLevel=pstuachieveSet.m_comLevel;		//读取计算机等级情况
			m_strEngLevel=pstuachieveSet.m_forlanLevel;		//读取外语等级
			m_strColiResult=pstuachieveSet.m_schship;		//读取学生在校记录
			break;
		}
		else
		  pstuachieveSet.MoveNext();						//移动到下一条记录
	}
	pstuachieveSet.Close();									//关闭记录集
    m_strResult="可以正常进行答辩";
	UpdateData(false);										//更新数据		
}
