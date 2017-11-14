// SysLgnDlg.cpp : implementation file
//系统登陆对话框

#include "stdafx.h"
#include "gradudemis.h"
#include "SysLgnDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSysLgnDlg dialog


CSysLgnDlg::CSysLgnDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSysLgnDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSysLgnDlg)
	m_strUser = _T("");
	m_strPasswd = _T("");
	//}}AFX_DATA_INIT
}


void CSysLgnDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSysLgnDlg)
	DDX_Control(pDX, IDC_UserUnit_COMBO, m_ctrlUserUnit);
	DDX_Control(pDX, IDC_UserType_COMBO, m_ctrlUserType);
	DDX_Control(pDX, IDC_PASSWORD, m_ctrlPasswd);
	DDX_Control(pDX, IDC_User_COMBO, m_ctrlUser);
	DDX_CBString(pDX, IDC_User_COMBO, m_strUser);
	DDX_Text(pDX, IDC_PASSWORD, m_strPasswd);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSysLgnDlg, CDialog)
	//{{AFX_MSG_MAP(CSysLgnDlg)
	ON_BN_CLICKED(IDC_LoginBtn, OnLoginBtn)
	ON_CBN_SELCHANGE(IDC_UserType_COMBO, OnSelchangeUserTypeCOMBO)
	ON_CBN_SELCHANGE(IDC_UserUnit_COMBO, OnSelchangeUserUnitCOMBO)
	ON_BN_CLICKED(IDC_ExitBtn, OnExitBtn)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSysLgnDlg message handlers

BOOL CSysLgnDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//插入数据到用户类行的下拉列表框，并默认当前选中第一项。
	m_ctrlUserType.InsertString(0," 学   生");
	m_ctrlUserType.InsertString(1," 教   师");
    m_ctrlUserType.InsertString(2,"管 理 员");
    m_ctrlUserType.SetCurSel(0);
	//插入数据到所在单位的下拉列表框，并默认当前选中第一项。
	m_ctrlUserUnit.InsertString(0,"信息021");
    m_ctrlUserUnit.InsertString(1,"信息022");
	m_ctrlUserUnit.SetCurSel(0);
//*************************************
	CString strSQL;													//定义字符串存储sql语句。
	int i=0;														//定义变量保存总数
	UpdateData();													//更新数据
    strSQL="select * from tab_password where user_unit='信息021'";	//sql语句选择所在单位为‘信息021’的所有数据
	if(!passwdSet.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))				//用sql语句打开记录集
	{
		MessageBox("打开数据库失败！");								//异常处理
	    return false;
	}
	while(!passwdSet.IsEOF())										//如果记录不是最后一条则继续读取
	{
		m_ctrlUser.InsertString(i,passwdSet.m_lgn_user);			//将数据插入到用户名的下拉列表框中
		passwdSet.MoveNext();										//移动到下一条记录
		i++;														//总数加一
	}
    m_ctrlUser.SetCurSel(0);										//初始化选中第一项

    passwdSet.Close();												//关闭记录集
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

//登陆按钮的消息相应函数
void CSysLgnDlg::OnLoginBtn()						
{
	// TODO: Add your control notification handler code here
	CString strSQL;											//定义字符串存储sql语句
	UpdateData();											//更新数据
	if(m_strUser.IsEmpty())									//判断m_strUser中的数据是否为空						
	{		
		MessageBox("请输入用户名！");
		m_ctrlUser.SetFocus();								//设置m_strUse的输入焦点
		return;
	}
	if(m_strPasswd.IsEmpty())								//判断m_strPasswd中的数据是否为空
	{
		MessageBox("请输入密码！");
		m_ctrlPasswd.SetFocus();							//设置m_strPasswd的输入焦点
		return;	
	}
    strSQL.Format("select * from tab_password where lgn_user='%s' AND lgn_passwd='%s'",m_strUser,m_strPasswd);
	//设置sql语句 从tab_password表中选择与当前输入用户名和密码匹配的数据
	if(!passwdSet.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))		//打开记录集
	{
		MessageBox("打开数据库失败！","数据库错误",MB_OK);
		return;
	}
	if(passwdSet.GetRecordCount()==0)						//如果记录为0则表示没有匹配的数据
	{
		//密码错误处理
		passwdSet.Close();									//关闭记录集。
		MessageBox("密码错误，请重新输入！");
		m_strPasswd="";										//重设密码
		m_ctrlPasswd.SetFocus();							//设置焦点
		UpdateData(false);									//更新数据
	}
	else
	{
		//密码正确进入主控制台，并分配用户权限
//	    m_bIsAdmin=passwdSet.m_lgn_isAdmin;
		passwdSet.Close();									//关闭记录集
//		MessageBox("可以进入主控制台");						
		strExternUser=m_strUser;							//保存当前登陆的用户名
		OnCancel();											//关闭当前对话框										
	}
}

//用户类型的下拉列表框选中的消息相应函数
void CSysLgnDlg::OnSelchangeUserTypeCOMBO() 
{
	// TODO: Add your control notification handler code here
	CString strUserType;									//定义字符串保存当前选中的类型
	m_ctrlUserType.GetWindowText(strUserType);				//获取m_ctrlUserType中的文本
	if(strUserType==" 学   生")								//判断用户类型
	{
		bstuExternFlag=true;								//全局变量加标记
		MessageBox("DDDDD");
		int num1=0;											//定义整形变量
    	num1=m_ctrlUserUnit.GetCount();						//获取m_ctrlUserUnit关联的下拉列表框中数据的总数
    	for(int i=0;i<num1;i++)								//删除所有
		  m_ctrlUserUnit.DeleteString(0);

		m_ctrlUserUnit.InsertString(0,"信息021");			//向下拉列表框中插入数据
		m_ctrlUserUnit.InsertString(1,"信息022");
        m_ctrlUserUnit.SetCurSel(0);						//默认选中第一项
	}
	else if(strUserType==" 教   师")						//同上	
	{	
		btecrExternFlag=true;							
		int num2=0;
     	num2=m_ctrlUserUnit.GetCount();
    	for(int i=0;i<num2;i++)
		  m_ctrlUserUnit.DeleteString(0);

		m_ctrlUserUnit.InsertString(0,"信息教研室");
		m_ctrlUserUnit.InsertString(1,"物理教研室");
		m_ctrlUserUnit.InsertString(2,"数学教研室");
        m_ctrlUserUnit.SetCurSel(0);
	}
	else													//同上
	{
		badminExternFlag=true;
		int num3=0;
     	num3=m_ctrlUserUnit.GetCount();
    	for(int i=0;i<num3;i++)
		  m_ctrlUserUnit.DeleteString(0);

		m_ctrlUserUnit.InsertString(0,"信息科学系");
        m_ctrlUserUnit.SetCurSel(0);
	}
	m_ctrlUserUnit.SetCurSel(0);
}

//用户单位的消息相应函数
void CSysLgnDlg::OnSelchangeUserUnitCOMBO() 
{
	// TODO: Add your control notification handler code here
    CString strUserUnit,strSQL;							//构造sql语句
    m_ctrlUserUnit.GetWindowText(strUserUnit);			//获取用户单位的文本

	if(strUserUnit=="信息021")
	{	
		MyAddComboBoxItem(strUserUnit);        
	}
	else if(strUserUnit=="信息022")
	{
		MyAddComboBoxItem(strUserUnit);
	}
	else if(strUserUnit=="信息教研室")
	{
		MyAddComboBoxItem(strUserUnit);
	}
	else if(strUserUnit=="物理教研室")
	{		
		MyAddComboBoxItem(strUserUnit);
	}
	else if(strUserUnit=="数学教研室")
	{	
		MyAddComboBoxItem(strUserUnit);
	}
	else if(strUserUnit=="信息科学系")
	{
		MyAddComboBoxItem(strUserUnit);
	}
}

//用户自定义函数添加用户名到相应的下拉列表框中参数为用户单位
void CSysLgnDlg::MyAddComboBoxItem(CString str)
{
	//清空Combo控件的项
	int numUser=0;
	numUser=m_ctrlUser.GetCount();
	for(int i=0;i<numUser;i++)											//删除用户名中所有的信息
		m_ctrlUser.DeleteString(0);
	//添加Combo控件的项
	CString strSQL;														//定义变量存储sql语句
	strSQL.Format("select * from tab_password where user_unit='%s'",str);//从tab_password表中选择用户类型为传递变量值的所有数据
	if(!passwdSet.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))					//以当前sql语句打开记录集
	{
		MessageBox("打开数据库失败！");
		return;
	}
	while(!passwdSet.IsEOF())											//遍历所有的数据
	{
		m_ctrlUser.AddString(passwdSet.m_lgn_user);						//将用户名添加到列表框中
		passwdSet.MoveNext();											//移动到下以条记录
	}
	passwdSet.Close();													//关闭记录集
}

//推出按钮的消息相应函数
void CSysLgnDlg::OnExitBtn()						
{
	// TODO: Add your control notification handler code here
	OnCancel();
}

//添加ON_PAINT消息添加背景等信息
void CSysLgnDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CPaintDC dc1(this); // device context for painting
	//**********************************************
	CRect rect;		
	GetClientRect(&rect);												//获取客户区大小
	HBITMAP hbitmap;													//定义句柄
	hbitmap=::LoadBitmap(::AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP5)); //读取bmp图片
	HDC hMenDC=::CreateCompatibleDC(NULL);								//创建以个兼容的DC
	SelectObject(hMenDC,hbitmap);										//选入设备环境上下文
	::StretchBlt(dc.m_hDC,0,0,1024,768,hMenDC,0,0,1024,768,SRCCOPY);	//绘制图片
	::DeleteDC(hMenDC);													//释放句柄
	::DeleteObject(hbitmap);
	// Do not call CDialog::OnPaint() for painting messages
}

