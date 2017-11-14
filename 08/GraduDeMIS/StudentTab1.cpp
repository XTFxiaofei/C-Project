// StudentTab1.cpp : implementation file
#include "stdafx.h"
#include "gradudemis.h"
#include "StudentTab1.h"
#include "StudentTab2.h"
#include"StudentSet.h"
#include "StudentTab2.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStudentTab1 dialog


CStudentTab1::CStudentTab1(CWnd* pParent /*=NULL*/)
: CDialog(CStudentTab1::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStudentTab1)
	m_strcombo1 = _T("");
	m_strCombo2 = _T("");
	//}}AFX_DATA_INIT
}


void CStudentTab1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStudentTab1)
	DDX_Control(pDX, IDC_STUTAB1_COMBO2, m_ctrlCombo2);
	DDX_Control(pDX, IDC_COMBO1, m_StuTab1Combo);
	DDX_Control(pDX, IDC_LIST1, m_StuTab1listctl);

	DDX_CBString(pDX, IDC_COMBO1, m_strcombo1);
	DDX_CBString(pDX, IDC_STUTAB1_COMBO2, m_strCombo2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStudentTab1, CDialog)
//{{AFX_MSG_MAP(CStudentTab1)
    ON_BN_CLICKED(IDC_STUTAB1_BUTTON, OnStutab1Button)
//	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, OnItemchangedList1)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStudentTab1 message handlers

BOOL CStudentTab1::OnInitDialog() 
{	
	CDialog::OnInitDialog();
	// TODO: Add extra initialization here
    pSet.Open();												//打开记录集
	m_StuTab1listctl.InsertColumn(0,"学号",LVCFMT_LEFT,70,0);	//向列表控件插入列标题设定宽度对齐方式
	m_StuTab1listctl.InsertColumn(1,"姓名",LVCFMT_LEFT,60,0);
	m_StuTab1listctl.InsertColumn(2,"性别",LVCFMT_LEFT,50,0);
	m_StuTab1listctl.InsertColumn(3,"年龄",LVCFMT_LEFT,50,0);
    m_StuTab1listctl.InsertColumn(4,"班级",LVCFMT_LEFT,80,0);
	m_StuTab1listctl.InsertColumn(5,"专业",LVCFMT_LEFT,110,0);
	m_StuTab1listctl.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);//风格的设定整行选择网格
    int i=0;													//定义整形变量
	pSet.MoveFirst();											//记录集移动到首条记录
	while(!pSet.IsEOF())										//如果记录不是末尾
	{   
		m_StuTab1listctl.InsertItem(i,pSet.m_stu_id);			//像列表控件中插入数据
		m_StuTab1listctl.SetItemText(i,1,pSet.m_stu_name);
		m_StuTab1listctl.SetItemText(i,2,pSet.m_stu_sex);
		m_StuTab1listctl.SetItemText(i,3,pSet.m_stu_age);
		m_StuTab1listctl.SetItemText(i,4,pSet.m_stu_class);
		m_StuTab1listctl.SetItemText(i,5,pSet.m_stu_depart);
        pSet.MoveNext();										//移动到下条记录
        i++;	
	}
	pSet.Close();												//关闭记录集
    CString str[6]={"学号","姓名","性别","年龄","班级","专业"};	//定义字符串数组并初始化
	for(int j=0;j<6;j++)										//将字符串数组的内容插入到下拉列表框中
	{
		m_StuTab1Combo.InsertString(j,str[j]);
	}
	m_StuTab1Combo.SetCurSel(0);								//设置默认选中第一项
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CStudentTab1::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	UpdateData();											//更新数据
	int nIndex=m_StuTab1Combo.GetCurSel();					//获取下拉列表框中选中的索引号
	switch(nIndex)					
	{
	case 0:
		break;
	case 1:
		break;
	case 2:
		{
			MyClearCombo2();								//调用函数清空下拉列表框中的内容
			m_ctrlCombo2.InsertString(0,"男");				//插入数据
		    m_ctrlCombo2.InsertString(1,"女");
		    m_ctrlCombo2.SetCurSel(0);						//设置默认选中
		}
		break;
	case 3:
		{
			CString strI;									//定义字符串变量
			MyClearCombo2();								//调用函数清空列表框中的数据
			for(int i=0;i<30;i++)
			{
				strI.Format("%d",i+10);						//整形转化字符型
				m_ctrlCombo2.InsertString(i,strI);			//插入数据
			}
		    m_ctrlCombo2.SetCurSel(0);						//默认第一项选中
		}
		break;
	case 4:
		{	
			MyClearCombo2();								//调用函数清空列表框中的数据
			m_ctrlCombo2.InsertString(0,"信息021");			//插入数据
		    m_ctrlCombo2.InsertString(1,"信息022");
		    m_ctrlCombo2.SetCurSel(0);						//默认第一项选中
		}
		break;
	case 5:
		{
			MyClearCombo2();								//调用函数清空列表框中的数据
			m_ctrlCombo2.InsertString(0,"信息与计算科学");	//插入数据
		    m_ctrlCombo2.InsertString(1,"应用数学");	
			m_ctrlCombo2.InsertString(2,"应用物理");
		    m_ctrlCombo2.SetCurSel(0);						//默认第一项选中
		}
		break;
	default:break;
	}
}

void CStudentTab1::MyClearCombo2()
{
	int nIndex=m_StuTab1Combo.GetCount();		//得到列表框中的数据的总数
	for(int i=0;i<nIndex;i++)
	{
		m_ctrlCombo2.DeleteString(0);			//删除所有
	}
}

void CStudentTab1::OnStutab1Button() 
{
	// TODO: Add your control notification handler code here
	int nIndex=m_StuTab1Combo.GetCurSel();		//得到下拉列表框选中的索引
	switch(nIndex) 
	{
	   case 0:
		   SelectItem(0);  break;				//调用函数	   
	   case 1:
		   SelectItem(1);  break; 
	   case 2:
		   SelectItem(2);  break;		   
	   case 3:
		   SelectItem(3);  break; 
	   case 4:
		   SelectItem(4);  break;		   
	   case 5:
		   SelectItem(5);  break; 
	}    
}

void CStudentTab1::SelectItem(int n)
{
	char filter[60];							//定义字符数组
	CString str[6]={"tab_stu.stu_id='%s'","tab_stu.stu_name='%s'","tab_stu.stu_sex='%s'",
		"tab_stu.stu_age='%s'","tab_stu.stu_class='%s'","tab_stu.stu_depart='%s'"};
												//定义字符串数组并赋值初值
	CString strEdit;							//定义字符串变量
    UpdateData();								//更新数据
	pSet.Open();								//打开记录集
	wsprintf(filter,str[n],m_strCombo2);		//格式化字符串
	pSet.m_strFilter=filter;					//记录赋值
	pSet.Requery();								//刷新记录集
	if(m_strCombo2=="")							//判断
	{
		MessageBox("查询条件为空，请输入关键词！");//消息提示
		pSet.Close();							//关闭记录集
		return;
	}
	else 
	{	
		if(pSet.IsEOF())						//如果记录指向末尾
			AfxMessageBox("要查找的记录不存在！");
		else
		{
			m_StuTab1listctl.DeleteAllItems();	//删除所有
			int i=0;
			while(!pSet.IsEOF())				//记录如果没有指向最后
			{
				m_StuTab1listctl.InsertItem(i,pSet.m_stu_id);		//插入数据到列表中
				m_StuTab1listctl.SetItemText(i,1,pSet.m_stu_name);
				m_StuTab1listctl.SetItemText(i,2,pSet.m_stu_sex);
				m_StuTab1listctl.SetItemText(i,3,pSet.m_stu_age);
				m_StuTab1listctl.SetItemText(i,4,pSet.m_stu_class);		
				m_StuTab1listctl.SetItemText(i,5,pSet.m_stu_depart);
				pSet.MoveNext();				//移动到下条记录
				i++;
			}
			UpdateData(false);					//更新数据
		}
		pSet.Close();							//关闭记录集
	}
}

void CStudentTab1::OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	int i=pNMListView->iItem;					//获取选中的行
	selectID=m_StuTab1listctl.GetItemText(i,0); //获取选中行第一项的文本
	*pResult = 0;
}
