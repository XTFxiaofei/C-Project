// DabianfenzuDlg.cpp : implementation file
//

#include "stdafx.h"
#include "gradudemis.h"
#include "DabianfenzuDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDabianfenzuDlg dialog


CDabianfenzuDlg::CDabianfenzuDlg(CWnd* pParent /*=NULL*/)
: CDialog(CDabianfenzuDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDabianfenzuDlg)
	m_strName = _T("");
	m_strClass = _T("");
	m_strDabianType = _T("");
	m_strSubType = _T("");
	m_strDate = _T("");
	m_strPosition = _T("");
	m_strDemand = _T("");
	m_strExpers = _T("");
	//}}AFX_DATA_INIT
}


void CDabianfenzuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDabianfenzuDlg)
	DDX_Control(pDX, IDC_LIST, m_ctrlList);
	DDX_Control(pDX, IDC_SubType_COMBO, m_ctrlSubType);
	DDX_Control(pDX, IDC_DabianType_COMBO, m_ctrlDabianType);
	DDX_Control(pDX, IDC_Class_COMBO, m_ctrlClass);
	DDX_Control(pDX, IDC_Name_COMBO, m_ctrlName);
	DDX_CBString(pDX, IDC_Name_COMBO, m_strName);
	DDX_CBString(pDX, IDC_Class_COMBO, m_strClass);
	DDX_CBString(pDX, IDC_DabianType_COMBO, m_strDabianType);
	DDX_CBString(pDX, IDC_SubType_COMBO, m_strSubType);
	DDX_Text(pDX, IDC_STATIC_Date, m_strDate);
	DDX_Text(pDX, IDC_STATIC_Position, m_strPosition);
	DDX_Text(pDX, IDC_EDIT_Demand, m_strDemand);
	DDX_Text(pDX, IDC_STATIC_Expers, m_strExpers);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDabianfenzuDlg, CDialog)
//{{AFX_MSG_MAP(CDabianfenzuDlg)
ON_CBN_SELCHANGE(IDC_Class_COMBO, OnSelchangeClassCOMBO)
ON_CBN_SELCHANGE(IDC_Name_COMBO, OnSelchangeNameCOMBO)
ON_CBN_SELCHANGE(IDC_DabianType_COMBO, OnSelchangeDabianTypeCOMBO)
ON_CBN_SELCHANGE(IDC_SubType_COMBO, OnSelchangeSubTypeCOMBO)
ON_BN_CLICKED(IDC_Ok_BTN, OnOkBTN)
ON_BN_CLICKED(IDC_QUERY_BTN, OnQueryBtn)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDabianfenzuDlg message handlers

BOOL CDabianfenzuDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_ctrlList.InsertColumn(0,"姓名",LVCFMT_LEFT,60,0);					//向列表控件中插入第一列标题，设置对齐方式，宽度
	m_ctrlList.InsertColumn(1,"答辩类型",LVCFMT_LEFT,80,0);				//向列表控件中插入第二列标题，设置对齐方式，宽度
	m_ctrlList.InsertColumn(2,"课题类型",LVCFMT_LEFT,80,0);				//向列表控件中插入第三列标题，设置对齐方式，宽度
    m_ctrlList.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES); //设置列表控件风格正行选择显示网格
	m_ctrlDabianType.InsertString(0,"院里答辩");						//添加数据到下拉列表中
	m_ctrlDabianType.InsertString(1,"系里答辩");
	m_ctrlDabianType.InsertString(2,"小组答辩");
	m_ctrlDabianType.SetCurSel(0);										//默认选择第一项
	m_ctrlSubType.InsertString(0,"软件设计");							//添加数据到下拉列表中
	m_ctrlSubType.InsertString(1,"应用研究");
	m_ctrlSubType.InsertString(2,"研究");
   	m_ctrlSubType.SetCurSel(0);											//默认选择第一项
	m_ctrlClass.InsertString(0,"信息021");								//添加数据到下拉列表中
    m_ctrlClass.InsertString(1,"信息022");
    m_ctrlClass.SetCurSel(0);											//默认选择第一项
	CString strSQL;														//定义字符串变量
	int i=0;															//定义整形变量
    strSQL="select * from tab_stu where stu_class='信息021'";			//构造查询stu_class相符的所有信息的sql语句
	if(!stuSet.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))					//打开记录集
	{
		MessageBox("打开数据库失败！");									//给出提示
		return false;
	}
	while(!stuSet.IsEOF())												//遍历记录集
	{
		m_ctrlName.InsertString(i,stuSet.m_stu_name);					//插入数据到下拉列表框中
		stuSet.MoveNext();												//移动到下一条记录
		i++;	
	}
	m_ctrlName.SetCurSel(0);											//设置默认选择
	stuSet.Close();														//关闭能记录集
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDabianfenzuDlg::OnSelchangeClassCOMBO()
{
	// TODO: Add your control notification handler code here
	int m=0 ,k=0;														//定义整形变量
	m=m_ctrlName.GetCount();											//获取下拉列表框的数据的总数
	for(int i=0;i<m;i++)												//删除所有
		m_ctrlName.DeleteString(0);
	CString strSQL,strClass;											//定义字符串变量
	m_ctrlClass.GetWindowText(strClass);
	if(strClass=="信息021")												//判断
		strSQL="select * from tab_stu where stu_class='信息021'";		//构造查询stu_class相符的所有信息的sql语句
	else
		strSQL="select * from tab_stu where stu_class='信息022'";		//构造查询stu_class相符的所有信息的sql语句
	if(!stuSet.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))					//打开记录集
	{
		MessageBox("打开数据库失败！");									//给出提示
		return ;
	}
	while(!stuSet.IsEOF())												//遍历记录集
	{
		m_ctrlName.InsertString(k,stuSet.m_stu_name);					//插入数据到下拉列表中
		stuSet.MoveNext();												//移动到下条记录
		k++;
	}
	m_ctrlName.SetCurSel(0);											//默认选择
	stuSet.Close();														//关闭记录集
}

void CDabianfenzuDlg::OnSelchangeSubTypeCOMBO() 
{
	// TODO: Add your control notification handler code here
	m_ctrlList.DeleteAllItems();						//清空所有
}
void CDabianfenzuDlg::MyClearSubTypeCombo()
{
	int nCombo=0;										//定义整形变量
	nCombo=m_ctrlSubType.GetCount();					//获取下拉列表中数据的总数
	for(int i=0;i<nCombo;i++)							//删除所有
		m_ctrlSubType.DeleteString(0);
}

void CDabianfenzuDlg::OnOkBTN()
{
	UpdateData();
	//m_ctrlList.DeleteAllItems();
    if(dabianfuzeSet.IsOpen())							    //打开记录集
		dabianfuzeSet.Close();
	CString strSQL;											//定义字符串变量
	strSQL.Format("select * from tab_DabianFenzu where stu_name='%s'",m_strName);
	//构造查询查询此用户信息的sql语句
	dabianfuzeSet.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL);
	if(dabianfuzeSet.GetRecordCount()==0)
	{
		dabianfuzeSet.Close();
		dabianfuzeSet.Open(AFX_DB_USE_DEFAULT_TYPE,"select * from tab_DabianFenzu ");
		dabianfuzeSet.AddNew();								//添加新记录
		dabianfuzeSet.m_dabian_unit=m_strDabianType;		//新记录的赋值
		dabianfuzeSet.m_stu_name=m_strName; 
		dabianfuzeSet.m_keti_type=m_strSubType;
		dabianfuzeSet.Update();								//更新记录集
		dabianfuzeSet.Requery();							//刷新记录集
		dabianfuzeSet.Close();								//关闭记录集
		m_ctrlList.InsertItem(0,m_strName);					//插入数据到列表控件
		m_ctrlList.SetItemText(0,1,m_strDabianType);
		m_ctrlList.SetItemText(0,2,m_strSubType);
		AfxMessageBox("分组成功！");
		
	}
	else
	{
		AfxMessageBox(m_strName+"同学已经分组！");
		return;
	}	
}

void CDabianfenzuDlg::OnQueryBtn() 
{
	// TODO: Add your control notification handler code here
    m_ctrlList.DeleteAllItems();						//删除所有
	int i=0;											//定义整形变量
	CString strDabianType,strSubType;					//定义字符变量
	m_ctrlDabianType.GetWindowText(strDabianType);		//获取文本内容
	m_ctrlSubType.GetWindowText(strSubType);			//获取文本内容
	MyDate_Posi_Dem_Exp(strDabianType,strSubType);		//调用自定义函数
	if(!dabianfuzeSet.IsOpen())							//打开记录集
		dabianfuzeSet.Open();			
    dabianfuzeSet.MoveFirst();							//移动到首条记录
	while(!dabianfuzeSet.IsEOF())						//遍历记录集
	{
		if((strDabianType==dabianfuzeSet.m_dabian_unit)&&(strSubType==dabianfuzeSet.m_keti_type))//判断条件
		{
			m_ctrlList.InsertItem(i,dabianfuzeSet.m_stu_name);		//插入数据到列表控件中
			m_ctrlList.SetItemText(i,1,strDabianType);
			m_ctrlList.SetItemText(i,2,strSubType);
			i++;
		}
		dabianfuzeSet.MoveNext();						//移动到下条记录
	}
	dabianfuzeSet.Close();								//关闭记录集
    UpdateData(false);									//更新数据
}

void CDabianfenzuDlg::MyDate_Posi_Dem_Exp(CString strDabianType,CString strSubType) 
{
	CString strDate,strPosition,strExpers,strDemand;	//定义字符串变量
	
	if(strDabianType=="院里答辩")						//判断类型
	{
		strDate="2006年6月18日上午8：00~11：30";		//变量的赋值
		strPosition="W1529";
		strExpers="蒋美萍 赵璧 石澄贤 徐明华 王启伦";
		strDemand="       请每个同学准备好汇报的幻灯片，每个同学的答辩时间大约30分钟，其中汇报时间控制在10~15分钟左右，回答答辩小组专家问题的时间在20分钟以内。";
		
	}
	else if((strDabianType=="系里答辩")&&(strSubType=="软件设计"))
	{	
		strDate="2006年6月18日下午13：30~17：00";
		strPosition="W1529";
		strExpers="蒋美萍 徐明华 王启伦 张洪波 胡  超";
		strDemand="       请同学准备好汇报的材料（尽量用幻灯片），每个同学的答辩时间不超过25分钟，其中汇报时间控制在10~15分钟左右，回答答辩小组专家问题的时间在10分钟以内。";	
	}
	else if((strDabianType=="系里答辩")&&(strSubType=="研究"||strSubType=="应用研究"))
	{	
		strDate="2006年6月18日下午13：30~17：00";
		strPosition="W13阶";
		strExpers="石澄贤  费忠华  刘玉清  赵志新  阮宏顺";
		strDemand="       请同学准备好汇报的材料（尽量用幻灯片），每个同学的答辩时间不超过25分钟，其中汇报时间控制在10~15分钟左右，回答答辩小组专家问题的时间在10分钟以内。";
	}
	else if((strDabianType=="小组答辩")&&(strSubType=="软件设计"))
	{
		strDate="2006年6月19日上午8：00~11：30";
		strPosition="W17阶";
		strExpers="石澄贤  张洪波  胡  超  张燕新";
		strDemand="       请每个同学准备好汇报的材料，答辩时间大约10分钟，其中汇报时间控制在6分钟左右，回答答辩小组专家问题的时间在4分钟以内。";
	}
	else if((strDabianType=="小组答辩")&&(strSubType=="应用研究"))
	{
		strDate="2006年6月19日上午8：00~11：30";
		strPosition="W2213";
		strExpers="费忠华  阮宏顺  黄清龙 郭淑娟";
		strDemand="       请每个同学准备好汇报的材料，答辩时间大约10分钟，其中汇报时间控制在6分钟左右，回答答辩小组专家问题的时间在4分钟以内。";
	}
	else if((strDabianType=="小组答辩")&&(strSubType=="研究"))
	{
		strDate="2006年6月19日上午8：00~11：30";
		strPosition="W2217";
		strExpers="刘玉清  赵志新  王福利  吴春青";
		strDemand="       请每个同学准备好汇报的材料，答辩时间大约10分钟，其中汇报时间控制在6分钟左右，回答答辩小组专家问题的时间在4分钟以内。";
	}
	
	m_strDate=strDate;								//变量赋值给控件
	m_strPosition=strPosition;
    m_strExpers=strExpers;
	m_strDemand=strDemand;
	
	UpdateData(false);								//更新数据
	
}
void CDabianfenzuDlg::OnSelchangeNameCOMBO() 
{
	// TODO: Add your control notification handler code here
	
}


void CDabianfenzuDlg::OnSelchangeDabianTypeCOMBO() 
{
	// TODO: Add your control notification handler code here
	m_ctrlList.DeleteAllItems();										//清空所有
	
																		/*	CString strDabianType;
																		m_ctrlDabianType.GetWindowText(strDabianType);
																		if(strDabianType=="院里答辩")
																		{
																		MyClearSubTypeCombo();
																		m_ctrlSubType.InsertString(0,"");
																		m_ctrlSubType.InsertString(1,"");
																		m_ctrlSubType.InsertString(2,"");
																		}
																		else if(strDabianType=="系里答辩")
																		{
																		MyClearSubTypeCombo();
																		}
																		else if(strDabianType=="小组答辩")
																		{		
																		MyClearSubTypeCombo();
																		}
	*/
}
