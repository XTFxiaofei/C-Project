// CheckManageDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hmsys.h"
#include "CheckManageDlg.h"
#include "OverTimeDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCheckManageDlg dialog
extern CHMSysApp theApp;

CCheckManageDlg::CCheckManageDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCheckManageDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCheckManageDlg)
	m_strID = _T("");
	m_strMore = _T("");
	m_Check1 = FALSE;
	m_Check2 = FALSE;
	m_Check3 = FALSE;
	m_Check4 = FALSE;
	//}}AFX_DATA_INIT
	for(int i = 0; i < 7; i++)
		m_strState[i] = "否";
	m_nFlag = -1;
}


void CCheckManageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCheckManageDlg)
	DDX_Control(pDX, IDC_RADIO1, m_Radio);
	DDX_Text(pDX, IDC_EDIT1, m_strID);
	DDX_Text(pDX, IDC_MORE, m_strMore);
	DDX_Check(pDX, IDC_CHECK1, m_Check1);
	DDX_Check(pDX, IDC_CHECK2, m_Check2);
	DDX_Check(pDX, IDC_CHECK3, m_Check3);
	DDX_Check(pDX, IDC_CHECK4, m_Check4);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCheckManageDlg, CDialog)
	//{{AFX_MSG_MAP(CCheckManageDlg)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_BN_CLICKED(IDC_SURE, OnSure)
	ON_BN_CLICKED(IDC_RADIO3, OnRadio3)
	ON_BN_CLICKED(IDC_RADIO4, OnRadio4)
	ON_BN_CLICKED(IDC_OVERTIME, OnOvertime)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCheckManageDlg message handlers

BOOL CCheckManageDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_pRecordset.CreateInstance("ADODB.Recordset");	
	GetDlgItem(IDC_CHECK1)->EnableWindow(FALSE);//复选框处于没有选中
	GetDlgItem(IDC_CHECK2)->EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK3)->EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK4)->EnableWindow(FALSE);
	m_Radio.SetCheck(1);						//单选按钮第一个为选中
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CCheckManageDlg::OnRadio1() 
{
	GetDlgItem(IDC_CHECK1)->EnableWindow();			//控件的禁用与恢复
	GetDlgItem(IDC_CHECK2)->EnableWindow();
	GetDlgItem(IDC_CHECK3)->EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK4)->EnableWindow(FALSE);
	m_strState[0] = "是";
	m_strState[5] = "否";
	m_strState[3] = "否";
	GetDlgItem(IDC_OVERTIME)->EnableWindow();
	m_nFlag = 1;
}
void CCheckManageDlg::OnRadio2() 
{
	GetDlgItem(IDC_CHECK1)->EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK2)->EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK3)->EnableWindow();
	GetDlgItem(IDC_CHECK4)->EnableWindow();	
	GetDlgItem(IDC_OVERTIME)->EnableWindow(FALSE);
	m_strState[0] = "否";
	m_strState[5] = "否";
	m_strState[3] = "否";
	m_nFlag = 2;
}
void CCheckManageDlg::OnRadio3() 
{
	m_strState[5] = "是";
	m_strState[0] = "否";
	m_strState[3] = "否";
	GetDlgItem(IDC_OVERTIME)->EnableWindow(FALSE);
}
void CCheckManageDlg::OnRadio4() 
{
	m_strState[3] = "是";
	m_strState[5] = "否";
	m_strState[0] = "否";
	GetDlgItem(IDC_OVERTIME)->EnableWindow(FALSE);
}
void CCheckManageDlg::OnSure() 
{
	UpdateData();							//数据的更新	
	if(m_strID == "")						//条件的判断
	{
		MessageBox("请出入员工号！");		//信息的输出
		return ;
	}
	CString strSQL;							//定义字符串变量
	_variant_t va;
	strSQL.Format("select count(*) from emp  where [id] = %s", m_strID);
	try
	{
		m_pRecordset = theApp.m_pConnection->Execute((_bstr_t)strSQL, NULL, adCmdText);
		va = m_pRecordset->GetCollect(_variant_t((long)0));//获取记录集的结果
		if(va.iVal == 0)
		{
			MessageBox("没有此员工！");
			return ;
		}
	}
	CATCH_ERROR;
	CTime time = CTime::GetCurrentTime();	//获取当前的系统时间
	CString strTime = time.Format("%Y-%m-%d");
	CString strYM = time.Format("%Y-%m");
	if(m_nFlag == 1)						//标记的判断
	{
		if(m_Check1 == 1)
			m_strState[2] = "是";
		else
			m_strState[2] = "否";
		if(m_Check2 == 1)
			m_strState[1] = "是";
		else
			m_strState[1] = "否";
	}
	if(m_nFlag == 2)
	{
		if(m_Check3 == 1)
			m_strState[4] = "是";
		else
			m_strState[4] = "否";
		if(m_Check4 == 1)
			m_strState[6] = "是";
		else
			m_strState[6] = "否";
	}
	strSQL.Format("insert into checkinfo values ('%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', 0, 0, 0)", 
		strTime, m_strID, m_strState[0], m_strState[1], m_strState[2], m_strState[3], m_strState[4], m_strState[5], m_strState[6], m_strMore, strYM);
	try
	{
		theApp.m_pConnection->Execute((_bstr_t)strSQL, NULL, adCmdText);//执行SQL语句
		m_strID = "";
		for(int i = 0; i < 7; i++)
			m_strState[i] = "否";
		MessageBox("添加成功！");
	}
	CATCH_ERROR;
	UpdateData(FALSE);
}



void CCheckManageDlg::OnOvertime() 
{
	COverTimeDlg dlg;					//定义对话框对象
	UpdateData();						//数据的获取
	if(dlg.DoModal() == IDOK)			//如果点击确定按钮
	{
		CString strSQL;					//定义字符串变量
		CTime time = CTime::GetCurrentTime();//或当前系统的时间
		CString strTime = time.Format("%Y-%m-%d");//将时间放到字符串中
		switch(dlg.m_nType)
		{
		case 0:
			strSQL.Format("update checkinfo set ot1 = %d where id = %s and date = '%s'", dlg.m_nHour, m_strID, strTime);
			break;
		case 1:
			strSQL.Format("update checkinfo set ot2 = %d where id = %s and date = '%s'", dlg.m_nHour, m_strID, strTime);
			break;
		case 2:
			strSQL.Format("update checkinfo set ot3 = %d where id = %s and date = '%s'", dlg.m_nHour, m_strID, strTime);
			break;
		}
		try
		{
			theApp.m_pConnection->Execute((_bstr_t)strSQL, NULL, adCmdText);//执行SQL语句
		}
		CATCH_ERROR;
	}
}
