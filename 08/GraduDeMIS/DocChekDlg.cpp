// DocChekDlg.cpp : implementation file
//

#include "stdafx.h"
#include "gradudemis.h"
#include "DocChekDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDocChekDlg dialog


CDocChekDlg::CDocChekDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDocChekDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDocChekDlg)
	m_strFanyi = _T("");
	m_strKaiti = _T("");
	m_strShixi = _T("");
	m_bFYnum = FALSE;
	m_bFYrelate = FALSE;
	m_bFYsubmit = FALSE;
	m_bKTbasecndi = FALSE;
	m_bKTplan = FALSE;
	m_bKTsubmit = FALSE;
	m_bSXrelate = FALSE;
	m_bSXsubmit = FALSE;
	m_strFYQuality = _T("");
	m_strKTunderstand = _T("");
	m_strSXbehave = _T("");
	m_strStuName = _T("");
	//}}AFX_DATA_INIT
}

void CDocChekDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDocChekDlg)
	DDX_Control(pDX, IDC_COMBO_Kaiti, m_ctrlKTunderstand);
	DDX_Control(pDX, IDC_COMBO_Shixi, m_ctrlShixi);
	DDX_Control(pDX, IDC_COMBO_Fanyi, m_ctrlFanyi);
	DDX_Control(pDX, IDC_StuName_COMBO, m_ctrlStuName);
	DDX_Control(pDX, IDC_Class_COMBO, m_ctrlClass);
	DDX_Text(pDX, IDC_EDIT_Fanyi, m_strFanyi);
	DDX_Text(pDX, IDC_EDIT_Kaiti, m_strKaiti);
	DDX_Text(pDX, IDC_EDIT_Shixi, m_strShixi);
	DDX_Check(pDX, IDC_FY_bNum_CHECK, m_bFYnum);
	DDX_Check(pDX, IDC_FY_bRelate_CHECK, m_bFYrelate);
	DDX_Check(pDX, IDC_FY_bSubmit_CHECK, m_bFYsubmit);
	DDX_Check(pDX, IDC_KT_bBaseCndi_CHECK, m_bKTbasecndi);
	DDX_Check(pDX, IDC_KT_bPlan_CHECK, m_bKTplan);
	DDX_Check(pDX, IDC_KT_bSubmit_CHECK, m_bKTsubmit);
	DDX_Check(pDX, IDC_SX_bRelate_CHECK, m_bSXrelate);
	DDX_Check(pDX, IDC_SX_bSubmit_CHECK, m_bSXsubmit);
	DDX_CBString(pDX, IDC_COMBO_Fanyi, m_strFYQuality);
	DDX_CBString(pDX, IDC_COMBO_Kaiti, m_strKTunderstand);
	DDX_CBString(pDX, IDC_COMBO_Shixi, m_strSXbehave);
	DDX_CBString(pDX, IDC_StuName_COMBO, m_strStuName);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDocChekDlg, CDialog)
	//{{AFX_MSG_MAP(CDocChekDlg)
	ON_BN_CLICKED(IDC_OkBTN, OnOkBTN)
	ON_WM_CLOSE()
	ON_CBN_SELCHANGE(IDC_StuName_COMBO, OnSelchangeStuNameCOMBO)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDocChekDlg message handlers

BOOL CDocChekDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	// TODO: Add extra initialization here
	m_ctrlFanyi.InsertString(0,"优秀");					//向下拉列表框中插入数据
	m_ctrlFanyi.InsertString(1,"良好");
	m_ctrlFanyi.InsertString(2,"一般");
	m_ctrlFanyi.InsertString(3,"较差");
	m_ctrlKTunderstand.InsertString(0,"优秀");			//向下拉列表框中插入数据
	m_ctrlKTunderstand.InsertString(1,"良好");
	m_ctrlKTunderstand.InsertString(2,"一般");
	m_ctrlKTunderstand.InsertString(3,"较差");
	m_ctrlShixi.InsertString(0,"优秀");					//向下拉列表框中插入数据
	m_ctrlShixi.InsertString(1,"良好");    
	m_ctrlShixi.InsertString(2,"一般");    
	m_ctrlShixi.InsertString(3,"较差");    
	m_ctrlClass.InsertString(0,"信息021");				//向下拉列表框中插入数据
    m_ctrlClass.InsertString(1,"信息022");
    m_ctrlClass.SetCurSel(0);							//默认选择第一项
	CString strSQL;										//定义字符串变量
	int i=0;
    strSQL="select * from tab_stu where stu_class='信息021'";//构造查询相应班级的所有信息的sql语句
	if(!stuSet.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))	//打开记录集
	{
		MessageBox("打开数据库失败！");
	    return false;
	}
	while(!stuSet.IsEOF())								//如果记录没有到末尾
	{
		m_ctrlStuName.InsertString(i,stuSet.m_stu_name);//插入数据到下拉列表框中
		stuSet.MoveNext();								//移动到下条记录
		i++;
	}
	m_ctrlStuName.SetCurSel(0);							//默认选择首条记录
	stuSet.Close();										//关闭记录集
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDocChekDlg::OnOkBTN() 
{
	// TODO: Add your control notification handler code here
	UpdateData();										//更新数据
	if(!pkaitiSet.IsOpen())								//打开记录集
		pkaitiSet.Open();	
	pkaitiSet.MoveFirst();								//移动到首条记录
	pkaitiSet.AddNew();									//增加新的记录
    pkaitiSet.m_stu_name=m_strStuName;					//记录的赋值
	pkaitiSet.m_kaiti_bBaseCndi=m_bKTbasecndi;
	pkaitiSet.m_kaiti_bPlan=m_bKTplan;
	pkaitiSet.m_kaiti_bSubmit=m_bKTsubmit;
	pkaitiSet.m_kaiti_ColiResult=m_strKaiti;
	pkaitiSet.m_kaiti_Understand=m_strKTunderstand;
	pkaitiSet.Update();									//更新数据
	pkaitiSet.Requery();								//刷新记录集
	pkaitiSet.Close();									//关闭记录集
	if(!pShixiSet.IsOpen())								//打开记录集
		pShixiSet.Open();
	pShixiSet.MoveFirst();								//移动到首条记录
	pShixiSet.AddNew();									//增加新的记录
    pShixiSet.m_stu_name=m_strStuName;
	pShixiSet.m_shixi_Behave=m_strSXbehave;				//记录赋值
	pShixiSet.m_shixi_bRelate=m_bSXrelate;
	pShixiSet.m_shixi_bSubmit=m_bSXsubmit;
	pShixiSet.m_shixi_Result=m_strShixi;
	pShixiSet.Update();									//更新记录
	pShixiSet.Requery();								//刷新记录集
	pShixiSet.Close();									//关闭记录集
	if(!pFanyiSet.IsOpen())								//打开记录集
		pFanyiSet.Open();
	pFanyiSet.MoveFirst();								//移动到首条记录
	pFanyiSet.AddNew();									//添加新的记录
    pFanyiSet.m_stu_name=m_strStuName;					//记录的赋值
	pFanyiSet.m_fanyi_bNum=m_bFYnum;
	pFanyiSet.m_fanyi_bRelate=m_bFYrelate;
	pFanyiSet.m_fanyi_bSubmit=m_bFYsubmit;
	pFanyiSet.m_fanyi_Quality=m_strFanyi;
	pFanyiSet.m_fanyi_Result=m_strKTunderstand;
	pFanyiSet.Update();									//更新记录
	pFanyiSet.Requery();								//刷新记录集
	pFanyiSet.Close();									//关闭记录集
}

void CDocChekDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	EndDialog(IDD_DocChek_DLG);	
//	CDialog::OnClose();
}

void CDocChekDlg::OnSelchangeStuNameCOMBO() 
{
	// TODO: Add your control notification handler code here
	
}