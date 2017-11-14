// StudentTab2.cpp : implementation file
//

#include "stdafx.h"
#include "gradudemis.h"
#include "StudentTab2.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStudentTab2 dialog

CStudentTab2::CStudentTab2(CWnd* pParent /*=NULL*/)
	: CDialog(CStudentTab2::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStudentTab2)
	m_StuTab2_ID = _T("");
	m_StuTab2_NAME = _T("");
//	m_StuTab2_DEPART = _T("");
//	m_StuTab2_AGE = _T("");
	m_strSex = _T("");
	m_strClass = _T("");
	m_strAge = _T("");
	m_strDepart = _T("");
	//}}AFX_DATA_INIT
    bAddBtnFlag=bEditBtnFlag=false;

}
void CStudentTab2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStudentTab2)
	DDX_Control(pDX, IDC_Depart_COMBO, m_ctrlDepart);
	DDX_Control(pDX, IDC_Age_COMBO, m_ctrlAge);
	DDX_Control(pDX, IDC_Class_COMBO, m_ctrlClass);
	DDX_Control(pDX, IDC_Sex_COMBO, m_ctrlSex);
	DDX_Control(pDX, IDC_EDIT_ID, m_StuTab2EditCtl);
	DDX_Text(pDX, IDC_EDIT_ID, m_StuTab2_ID);
	DDX_Text(pDX, IDC_EDIT_NAME, m_StuTab2_NAME);
//	DDX_Text(pDX, IDC_EDIT_DEPART, m_StuTab2_DEPART);
//	DDX_Text(pDX, IDC_EDIT_AGE, m_StuTab2_AGE);
	DDX_CBString(pDX, IDC_Sex_COMBO, m_strSex);
	DDX_CBString(pDX, IDC_Class_COMBO, m_strClass);
	DDX_CBString(pDX, IDC_Age_COMBO, m_strAge);
	DDX_CBString(pDX, IDC_Depart_COMBO, m_strDepart);
	//}}AFX_DATA_MAP
}
BEGIN_MESSAGE_MAP(CStudentTab2, CDialog)
	//{{AFX_MSG_MAP(CStudentTab2)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_CANCLE, OnButtonCancle)
	ON_BN_CLICKED(IDC_BUTTON_DEL, OnButtonDel)
	ON_BN_CLICKED(IDC_BUTTON_EDIT, OnButtonEdit)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, OnButtonSave)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStudentTab2 message handlers

BOOL CStudentTab2::OnInitDialog() 
{
	CDialog::OnInitDialog();
	// TODO: Add extra initialization here
    MyBtnHide(1,1,1,0,0);						//用户自定义函数控制按钮的隐藏与显示				
    m_ctrlSex.AddString("男");					//添加数据
    m_ctrlSex.AddString("女");					//添加数据
    m_ctrlSex.SetCurSel(0);						//设置默认选中
    m_ctrlClass.AddString("信息021");			//添加数据
    m_ctrlClass.AddString("信息022");
    m_ctrlClass.SetCurSel(0);					//设置默认选中
	CString strI;								//定义字符串变量
	for(int i=0;i<30;i++)
	{
		strI.Format("%d",i+10);
		m_ctrlAge.InsertString(i,strI);			//添加数据到控件中
	}
    m_ctrlAge.SetCurSel(0);						//设置默认选定
	m_ctrlDepart.InsertString(0,"信息与计算科学");//插入数据
	m_ctrlDepart.InsertString(1,"应用物理");
	m_ctrlDepart.InsertString(2,"应用数学");
    m_ctrlDepart.SetCurSel(0);					//设置默认选中

	if(!pSet2.IsOpen())							//打开记录集
		pSet2.Open();	
	pSet2.MoveFirst();							//移动到受天记录
	m_StuTab2_ID=pSet2.m_stu_id;				//变量的赋值
	m_StuTab2_NAME=pSet2.m_stu_name;	
	m_strSex=pSet2.m_stu_sex;
    m_strAge=pSet2.m_stu_age;
	m_strDepart=pSet2.m_stu_depart;    
	m_strClass=pSet2.m_stu_class;
	pSet2.Close();								//关闭记录集
	UpdateData(false);							//更新数据
	return TRUE;  // return TRUE unless you set the focus to a control
		// EXCEPTION: OCX Property Pages should return FALSE
}

void CStudentTab2::OnButtonAdd() 
{
	// TODO: Add your control notification handler code here

   MyBtnHide(0,0,0,1,1);						//按钮的隐藏与显示
   bAddBtnFlag=true;							//更改标记
   MyClearItem();								//清楚所有控件中的数据

}

void CStudentTab2::OnButtonEdit() 
{

	// TODO: Add your control notification handler code here
	MyBtnHide(0,0,0,1,1);						//按钮的隐藏与显示
	bEditBtnFlag=true;							//更改标记

}

void CStudentTab2::OnButtonDel() 
{
	// TODO: Add your control notification handler code here
	MyBtnHide(0,0,0,1,1);						//按钮的隐藏与显示
	pSet2.Open();								//打开记录集
	if(!pSet2.CanUpdate())						//判断
	{
		AfxMessageBox("删除失败！请选择某条记录");
		pSet2.Close();
		return;
	}
	if(MessageBox("确定要删除吗？删除后不可恢复，并且相关的库存信息也将被删除！",
		          "注意！",MB_YESNO)!=IDYES)
	{  	
		pSet2.Close();							//关闭记录集
		MyBtnHide(1,1,1,0,0);					//按钮的隐藏与显示
		return;	
	};
	while(!pSet2.IsEOF())						//如果记录没有到末尾
	{
		if(pSet2.m_stu_id==selectID)		
		{
			pSet2.Delete();						//删除数据
			MyClearItem();						//清空
		}
		else
			pSet2.MoveNext();					//移动到下条
	}
	pSet2.Close();								//关闭记录集
	MyBtnHide(1,1,1,0,0);						//按钮的隐藏与显示
}

void CStudentTab2::OnButtonSave() 
{
	if(bEditBtnFlag)							//判断标记
	{	
		UpdateData();							//更新数据
		bEditBtnFlag=false;						//更改标记
	    if(!pSet2.IsOpen())						//打开记录集
		   pSet2.Open();
        pSet2.MoveFirst();						//移动到第一条
		pSet2.Edit();							//编辑记录
		while(!pSet2.IsEOF())					//如果记录没有到末尾
		{
			if(pSet2.m_stu_id==selectID)	
			{	
				pSet2.m_stu_id=m_StuTab2_ID;	//记录赋值
				pSet2.m_stu_name=m_StuTab2_NAME;
				pSet2.m_stu_sex=m_strSex;
				pSet2.m_stu_age=m_strAge;
				pSet2.m_stu_class=m_strClass;
				pSet2.m_stu_depart=m_strDepart;	
				pSet2.Update();					//更细数据
				pSet2.Requery();				//刷新记录集
				break;
			}
			else
				pSet2.MoveNext();				//向下移动
				AfxMessageBox(selectID);
		}
		pSet2.Close();							//关闭记录集
		MessageBox("修改成功！","提示信息",MB_OK);//信息提示
	}
	MyBtnHide(1,1,1,0,0);						//按钮的隐藏与显示
}

void CStudentTab2::OnButtonCancle() 
{

	MyBtnHide(1,1,1,0,0);						//按钮的隐藏与显示
}

CStudentTab2::MyClearItem()
{
	UpdateData();								//更新数据
	m_StuTab2_ID="";            //自动由前向后分配学号???	
    m_StuTab2_NAME="";							//清空信息
    m_strSex="";
    m_strAge="";
    m_strClass="";
    m_strDepart="";   
	UpdateData(false);							//更新数据
}

void CStudentTab2::OnShow()
{
	if(!pSet2.IsOpen())							//打开记录集
	pSet2.Open();
	while(!pSet2.IsEOF())						//记录不是末尾
	{
		if(pSet2.m_stu_id==selectID)
		{
			m_StuTab2_ID=pSet2.m_stu_id;		///变量赋值
			m_StuTab2_NAME=pSet2.m_stu_name;
			m_strSex=pSet2.m_stu_sex;
			m_strAge=pSet2.m_stu_age;
			m_strDepart=pSet2.m_stu_depart;    
			m_strClass=pSet2.m_stu_class;
			break;
		}
		else
			pSet2.MoveNext();					//向下移动
	}
	pSet2.Close();								//关闭记录集
	UpdateData(FALSE);							//更新数据
}

CStudentTab2::MyBtnHide(bool bBtnAdd,bool bBtnEdit,bool bBtnDel,bool bBtnSave,bool bBtnCancel)
{
	CButton *pBtnAdd=(CButton *)GetDlgItem(IDC_BUTTON_ADD);			//获取按钮的指针
	CButton *pBtnDel=(CButton *)GetDlgItem(IDC_BUTTON_DEL);
	CButton *pBtnEdit=(CButton *)GetDlgItem(IDC_BUTTON_EDIT);
	CButton *pBtnSave=(CButton *)GetDlgItem(IDC_BUTTON_SAVE);
	CButton *pBtnCancel=(CButton *)GetDlgItem(IDC_BUTTON_CANCLE);
	
	if(bBtnAdd)  
		pBtnAdd->ShowWindow(SW_SHOW);						//显示按钮
	else
		pBtnAdd->ShowWindow(SW_HIDE);						//隐藏按钮

	if(bBtnEdit)  
		pBtnEdit->ShowWindow(SW_SHOW);						//显示按钮
	else
		pBtnEdit->ShowWindow(SW_HIDE);						//隐藏按钮

	if(bBtnDel)  
		pBtnDel->ShowWindow(SW_SHOW);						//显示按钮
	else
		pBtnDel->ShowWindow(SW_HIDE);						//隐藏按钮

	if(bBtnSave)  
		pBtnSave->ShowWindow(SW_SHOW);						//显示按钮
	else
		pBtnSave->ShowWindow(SW_HIDE);						//隐藏按钮

	if(bBtnCancel)  
		pBtnCancel->ShowWindow(SW_SHOW);					//显示按钮
	else
		pBtnCancel->ShowWindow(SW_HIDE);						//隐藏按钮
}
