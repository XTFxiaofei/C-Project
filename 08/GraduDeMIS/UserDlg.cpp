// UserDlg.cpp : implementation file
//

#include "stdafx.h"
#include "gradudemis.h"
#include "UserDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUserDlg dialog
char Label;									//保存用户选择的操作

CUserDlg::CUserDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUserDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUserDlg)
	m_strPass = _T("");
	m_strRePass = _T("");
	m_user = _T("");
	m_IsAdmin = FALSE;
	//}}AFX_DATA_INIT
}


void CUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUserDlg)
	DDX_Control(pDX, IDC_USER1, m_ctrlUser);
	DDX_Control(pDX, IDC_Passwd, m_ctrlPass);
	DDX_Control(pDX, IDC_User_LIST, m_ctrlUserList);
	DDX_Text(pDX, IDC_Passwd, m_strPass);
	DDX_Text(pDX, IDC_RePass, m_strRePass);
	DDX_Text(pDX, IDC_USER1, m_user);
	DDX_Check(pDX, IDC_IsAdmin_CHECK, m_IsAdmin);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUserDlg, CDialog)
	//{{AFX_MSG_MAP(CUserDlg)
	ON_BN_CLICKED(IDC_Exit_BTN, OnExitBTN)
	ON_BN_CLICKED(IDC_EDIT, OnEdit)
	ON_BN_CLICKED(IDC_DEL, OnDel)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_Cancel_BTN, OnCancelBTN)
	ON_BN_CLICKED(IDC_IsAdmin_CHECK, OnIsAdminCHECK)
	ON_BN_CLICKED(IDC_Save_BTN, OnSaveBTN)
	ON_LBN_SELCHANGE(IDC_User_LIST, OnSelchangeUserLIST)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUserDlg message handlers

BOOL CUserDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
//  m_ctrlUser.EnableWindow(false);
 
	if(!passwdSet.IsOpen())											//打开记录集
		passwdSet.Open();
	   passwdSet.MoveFirst();										//移动到第一条记录
	while(!passwdSet.IsEOF())										//遍历记录集
	{	
		int nIndex=m_ctrlUserList.AddString(passwdSet.m_lgn_user);	//将用户名添加到列表中
		UserInfo structSet;											//定义用户信息结构变量
		structSet.user=passwdSet.m_lgn_user;						//变量的初始化
		structSet.passwd=passwdSet.m_lgn_passwd;
		structSet.repasswd=passwdSet.m_lgn_passwd;
        structSet.bIsAdmin=passwdSet.m_lgn_isAdmin;
		m_ctrlUserList.SetItemDataPtr(nIndex,new UserInfo(structSet));//设置一个指针添加用户信息
		passwdSet.MoveNext();										//移动到下条记录
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CUserDlg::OnExitBTN() 
{
	// TODO: Add your control notification handler code here
	OnCancel();														//退出
}

void CUserDlg::OnSelchangeUserLIST() 
{
	// TODO: Add your control notification handler code here

	int nIndex=m_ctrlUserList.GetCurSel();							//获取选择的索引号
	if(nIndex!=LB_ERR)												//如果没有抛出异常
	{
		UserInfo *structSet=(UserInfo *)m_ctrlUserList.GetItemDataPtr(nIndex);//取出用户信息
		m_user=structSet->user;										//用户信息变量的赋值
		m_strPass=structSet->passwd;
		m_strRePass=structSet->repasswd;
        m_IsAdmin=structSet->bIsAdmin;
		UpdateData(false);											//更新数据
	}
}

void CUserDlg::OnAdd() 
{
	// TODO: Add your control notification handler code here
   m_user="";														//清空编辑框
   m_strPass="";
   m_strRePass="";
   m_IsAdmin=false;													//设置不为管理员
// m_ctrlUser.EnableWindow(true);
   m_ctrlUser.SetFocus();											//设置焦点
   UpdateData(false);												//更新数据
   Label='A';														//保存用户所选的操作
}

void CUserDlg::OnEdit()									
{
	// TODO: Add your control notification handler code here
	//	UpdateData(false);
	Label='E';														//保存用户所选的操作
}

void CUserDlg::OnDel() 
{
	// TODO: Add your control notification handler code here
	
}

void CUserDlg::OnSaveBTN()											//保存按钮
{
	// TODO: Add your control notification handler code here
	UpdateData();													//更新数据

	if(m_user.IsEmpty())											//判断是否为空
	{
		MessageBox("姓名不能为空");									//给出提示
		m_ctrlUser.SetFocus();										//设置焦点
		return;														//返回
	}
	if(m_strPass=="")												//判断是否为空
	{
    	MessageBox("密码不能为空，请输入密码！");					//给出提示
		m_ctrlPass.SetFocus();										//设置焦点
		return;														//返回
	}

	switch (Label)													//用户所选的操作
	{
	case 'A':
		{	//添加新用户		
			m_user.TrimLeft();										//去除左边的空格
			m_user.TrimRight();										//去除右边的空格
			if((m_ctrlUserList.FindString(-1,m_user))!=LB_ERR)		//判断是否已经添加
			{
				MessageBox("列表框中已有相同的姓名，不能添加");		//给出提示
				m_user.Empty();										//清空编辑框
                m_strPass.Empty();
                m_strRePass.Empty();
				UpdateData(false);									//更新数据
                m_ctrlUser.SetFocus();								//设置焦点
				return;	
			}

			int nIndex=m_ctrlUserList.AddString(m_user);			//没有添加则添加
			UserInfo structSet;										//定义用户信息结构
			structSet.user=m_user;									//结构体赋值
			structSet.passwd=m_strPass;
			structSet.repasswd=m_strRePass;
			structSet.bIsAdmin=m_IsAdmin;			
			m_ctrlUserList.SetItemDataPtr(nIndex,new UserInfo(structSet));//设置指针
            //写入数据库
			if(!passwdSet.IsOpen())
				passwdSet.Open();									//打开记录集
		      passwdSet.MoveFirst();								//移动到第一条记录
			  passwdSet.AddNew();									//添加新记录
			  passwdSet.m_lgn_user=structSet.user;					//表中个字段的赋值
			  passwdSet.m_lgn_passwd=structSet.passwd;
			  passwdSet.m_lgn_isAdmin=structSet.bIsAdmin;
			  passwdSet.Update();									//更新记录
			  passwdSet.Requery();									//刷新记录集
			  passwdSet.Close();									//关闭记录集
              MessageBox("用户添加成功，请记住用户名和密码！");		//给出提示
		}
		break;
	case 'E':
		{//修改用户		 
			if(m_strPass!=m_strRePass)								//判断用户两次密码是否一致
			{
				MessageBox("两次输入的密码不一致，请重新输入密码！");//给出提示
				m_ctrlPass.SetFocus();								//设置焦点
				m_strPass="";										//清空编辑框
				m_strRePass="";
				UpdateData(false);									//更新数据
				return;
			}
			CString strSQL;											//定义字符串变量
			strSQL.Format("select * from tab_password where lgn_user='%s'",m_user);
			//构造查询查询此用户信息的sql语句
			MessageBox(m_user);
			if(passwdSet.IsOpen())
				passwdSet.Close();
			if(!passwdSet.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))///////???????????????
			{
				MessageBox("打开数据库失败！");
				return;
			}	
			passwdSet.Edit();										//编辑记录
			passwdSet.m_lgn_user=m_user;							//表中字段的赋值
			passwdSet.m_lgn_passwd=m_strPass;
			passwdSet.m_lgn_isAdmin=m_IsAdmin;
			passwdSet.Update();										//更新记录集
			MessageBox("用户修改成功，请记住用户名和密码！");		//给出提示
		}
		break;
      default:break;
	}
}

void CUserDlg::OnCancelBTN() 
{
	// TODO: Add your control notification handler code here
	
}

void CUserDlg::OnIsAdminCHECK() 
{
	// TODO: Add your control notification handler code here
	
}



void CUserDlg::OnDestroy() 
{
	CDialog::OnDestroy();											//销毁对话框
	
	// TODO: Add your message handler code here
}
