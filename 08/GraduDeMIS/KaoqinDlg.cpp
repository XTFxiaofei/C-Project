// KaoqinDlg.cpp : implementation file
//

#include "stdafx.h"
#include "gradudemis.h"
#include "KaoqinDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKaoqinDlg dialog


CKaoqinDlg::CKaoqinDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CKaoqinDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CKaoqinDlg)
	m_strClass = _T("");
	m_strStuName = _T("");
	m_strClass2 = _T("");
	m_strStuName2 = _T("");
	m_strFrom = 0;
	m_strTo = 0;
	m_bCheck = FALSE;
	m_strUnAttRea = _T("");
	//}}AFX_DATA_INIT
}


void CKaoqinDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CKaoqinDlg)
	DDX_Control(pDX, IDC_EDIT_UnAttRea, m_ctrUnAttRea);
	DDX_Control(pDX, IDC_StuName_COMBO2, m_ctrlStuName2);
	DDX_Control(pDX, IDC_Class_COMBO2, m_ctrlClass2);
	DDX_Control(pDX, IDC_LIST1, m_ctrlList);
	DDX_Control(pDX, IDC_StuName_COMBO, m_ctrlStuName);
	DDX_Control(pDX, IDC_Class_COMBO, m_ctrlClass);
	DDX_CBString(pDX, IDC_Class_COMBO, m_strClass);
	DDX_CBString(pDX, IDC_StuName_COMBO, m_strStuName);
	DDX_CBString(pDX, IDC_Class_COMBO2, m_strClass2);
	DDX_CBString(pDX, IDC_StuName_COMBO2, m_strStuName2);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_From, m_strFrom);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_To, m_strTo);
	DDX_Check(pDX, IDC_CHECK1, m_bCheck);
	DDX_Text(pDX, IDC_EDIT_UnAttRea, m_strUnAttRea);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CKaoqinDlg, CDialog)
	//{{AFX_MSG_MAP(CKaoqinDlg)
	ON_CBN_SELCHANGE(IDC_Class_COMBO, OnSelchangeClassCOMBO)

	ON_BN_CLICKED(IDC_Add_BTN, OnAddBTN)
	ON_CBN_SELCHANGE(IDC_Class_COMBO2, OnSelchangeClassCOMBO2)

	ON_BN_CLICKED(IDC_QUERY_BTN, OnQueryBtn)
	ON_BN_CLICKED(IDC_CHECK1, OnCheck1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
/////////////////////////////////////////////////////////////////////////////

// CKaoqinDlg message handlers

BOOL CKaoqinDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	// TODO: Add extra initialization here
	m_ctrUnAttRea.EnableWindow(false);								//控件的禁用
	m_ctrlList.InsertColumn(0,"编号",LVCFMT_LEFT,50,0);				//列表控件中插入列标题设置宽度对齐方式
	m_ctrlList.InsertColumn(1,"      日      期",LVCFMT_LEFT,120,0);
	m_ctrlList.InsertColumn(2,"出勤情况",LVCFMT_LEFT,80,0);
	m_ctrlList.InsertColumn(3,"备注",LVCFMT_LEFT,250,0);
	m_ctrlList.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);//风格的设定正行选择网格
	m_ctrlClass.InsertString(0,"信息021");							//插入数据到下拉列表框中
    m_ctrlClass.InsertString(1,"信息022");
    m_ctrlClass.SetCurSel(0);										//默认选择第一项
	m_ctrlClass2.InsertString(0,"信息021");
    m_ctrlClass2.InsertString(1,"信息022");
    m_ctrlClass2.SetCurSel(0);
	CString strSQL;													//定义字符串变量
	int i=0;
    strSQL="select * from tab_stu where stu_class='信息021'";		//构造查询相应班级的所有学生的信息的sql语句
	if(!stuSet.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))				//打开记录集
	{
		MessageBox("打开数据库失败！");
	    return false;
	}	
	while(!stuSet.IsEOF())											//如果记录没有到末尾
	{
		m_ctrlStuName.InsertString(i,stuSet.m_stu_name);			//插入数据
		m_ctrlStuName2.InsertString(i,stuSet.m_stu_name);
		stuSet.MoveNext();											//移动到下条记录
		i++;
	}
	m_ctrlStuName.SetCurSel(0);										//设置默认选择第一项
	m_ctrlStuName2.SetCurSel(0);
	stuSet.Close();													//关闭记录集
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
////////////////////////////////////////////////////////////////////////
void CKaoqinDlg::OnSelchangeClassCOMBO() 
{
	// TODO: Add your control notification handler code here
	int m=0 ,k=0;											//定义整形变量
	m=m_ctrlStuName.GetCount();								//得到控件中数据的总数
	for(int i=0;i<m;i++)
		m_ctrlStuName.DeleteString(0);						//删除控件中的所有数据
	CString strSQL,strClass;								//定义字符串变量
	m_ctrlClass.GetWindowText(strClass);					//获取控件中的文本
	if(strClass=="信息021")									//条件判断
	    strSQL="select * from tab_stu where stu_class='信息021'";//构造查询所有班级为相应班级的学生信息
	else
		strSQL="select * from tab_stu where stu_class='信息022'";//构造查询所有班级为相应班级的学生信息
	if(!stuSet.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))		//打开记录集
	{
		MessageBox("打开数据库失败！");
	    return ;
	}
	while(!stuSet.IsEOF())									//如果记录没有到末尾
	{
		m_ctrlStuName.InsertString(k,stuSet.m_stu_name);	//插入数据到控件中
		stuSet.MoveNext();									//移动到下条记录
		k++;
	}
	m_ctrlStuName.SetCurSel(0);								//默认选中的第一项
	stuSet.Close();											//关闭记录集
}

void CKaoqinDlg::OnSelchangeClassCOMBO2() 
{
	// TODO: Add your control notification handler code here
	int m=0 ,k=0;											//定义整形变量
	    m=m_ctrlStuName2.GetCount();							//得到控件中数据的总数
	for(int i=0;i<m;i++)
		m_ctrlStuName2.DeleteString(0);						//删除控件中的所有数据
	CString strSQL,strClass;								//定义字符串变量
	m_ctrlClass2.GetWindowText(strClass);					//获取控件中的文本
	if(strClass=="信息021")									//条件判断
	    strSQL="select * from tab_stu where stu_class='信息021'";//构造查询所有班级为相应班级的学生信息
	else
		strSQL="select * from tab_stu where stu_class='信息022'";//构造查询所有班级为相应班级的学生信息
	if(!stuSet.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))//打开记录集
	{
		MessageBox("打开数据库失败！");
	    return ;
	}
	while(!stuSet.IsEOF())
	{
		m_ctrlStuName2.InsertString(k,stuSet.m_stu_name);	//插入数据
		stuSet.MoveNext();									//移动到下条记录
		k++;
	}
	m_ctrlStuName2.SetCurSel(0);							//默认选择第一项
	stuSet.Close();											//关闭记录集
}


void CKaoqinDlg::OnCheck1() 
{
	// TODO: Add your control notification handler code here
	m_ctrUnAttRea.EnableWindow(!m_bCheck);					//控件的禁用
}

void CKaoqinDlg::OnQueryBtn() 
{
	// TODO: Add your control notification handler code here
	m_ctrlList.DeleteAllItems();							//删除所有
	UpdateData();											//更新数据
	int i=0;												//等译整形变量
	CString strI;											//定义字符串变量
	if(!kaoqinSet.IsOpen())
		kaoqinSet.Open();									//打开记录集
	kaoqinSet.MoveFirst();
	while(!kaoqinSet.IsEOF())								//如果记录集莫有到最后
	{
		if(kaoqinSet.m_stu_name==m_strStuName)				//条件判断
		{
			strI.Format("%d",i+1);							//整形格式化字符型
			m_ctrlList.InsertItem(i,strI);					//向列表控件中插入数据
			m_ctrlList.SetItemText(i,1,kaoqinSet.m_stu_ChuQinTime);
			if(kaoqinSet.m_stu_ChuQinStatus)
				m_ctrlList.SetItemText(i,2,"是");
			else
				m_ctrlList.SetItemText(i,2,"否");
			m_ctrlList.SetItemText(i,3,kaoqinSet.m_stu_UnAtedReason);
			i++;
		}
		kaoqinSet.MoveNext();								//移动到下条记录
	}
	kaoqinSet.Close();										//关闭记录集
}

void CKaoqinDlg::OnAddBTN() 
{
	m_ctrlList.DeleteAllItems();							//删除所有
	CTime time=CTime::GetCurrentTime();						//获取当前时间
	CString strtime=time.Format("%Y-%m-%d");				//将时间按格式格式化
    UpdateData();											//更新数据
	if(!kaoqinSet.IsOpen())									//打开记录集
		kaoqinSet.Open();
	kaoqinSet.AddNew();										//添加新的记录
    kaoqinSet.m_stu_ChuQinStatus=!m_bCheck;					//新纪录赋值
	kaoqinSet.m_stu_ChuQinTime=strtime;
	kaoqinSet.m_stu_name=m_strStuName2;
	kaoqinSet.m_stu_UnAtedReason=m_strUnAttRea;
	kaoqinSet.Update();										//更细数据
	kaoqinSet.Requery();									//刷新记录集
	kaoqinSet.Close();										//关闭记录集
	MessageBox("添加成功!");								//消息提示
}


