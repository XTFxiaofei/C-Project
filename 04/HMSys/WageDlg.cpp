// WageDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hmsys.h"
#include "WageDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWageDlg dialog

extern CHMSysApp theApp;
CWageDlg::CWageDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWageDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWageDlg)
	m_strID = _T("");
	//}}AFX_DATA_INIT
}


void CWageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWageDlg)
	DDX_Control(pDX, IDC_COMBO1, m_Month);
	DDX_Control(pDX, IDC_LIST1, m_ListCrtl);
	DDX_Text(pDX, IDC_ID, m_strID);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWageDlg, CDialog)
	//{{AFX_MSG_MAP(CWageDlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWageDlg message handlers

BOOL CWageDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_pRecordset.CreateInstance("ADODB.Recordset");	
	m_pRecordset1.CreateInstance("ADODB.Recordset");	
	m_ListCrtl.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT );//风格的设定。整行选择
	m_ListCrtl.InsertColumn(0, "员工ID", LVCFMT_CENTER, 60);
	m_ListCrtl.InsertColumn(1, "月薪(元)", LVCFMT_CENTER, 60);
	m_ListCrtl.InsertColumn(2, "月份", LVCFMT_CENTER, 60);
	m_ListCrtl.InsertColumn(3, "出差(天)", LVCFMT_CENTER, 60);
	m_ListCrtl.InsertColumn(4, "病假(天)", LVCFMT_CENTER, 60);
	m_ListCrtl.InsertColumn(5, "事假(天)", LVCFMT_CENTER, 60);
	m_ListCrtl.InsertColumn(6, "平时加班(小时)", LVCFMT_CENTER, 100);
	m_ListCrtl.InsertColumn(7, "双休日加班(小时)", LVCFMT_CENTER, 120);
	m_ListCrtl.InsertColumn(8, "法定假日加班(小时)", LVCFMT_CENTER, 120);
	m_ListCrtl.InsertColumn(9, "应发工资(元)", LVCFMT_CENTER, 100);
	CString strSQL;	//创建临时表
	strSQL.Format("create table temp (id int, wage int, ym varchar(20), chuchai int, bingjia int, shijia int, pingshi int, shuangxiu int, fading int, waged int)");
	try
	{
		theApp.m_pConnection->Execute((_bstr_t)strSQL, NULL, adCmdText);
	}
	catch(...)
	{
		strSQL.Format("drop table temp");
		theApp.m_pConnection->Execute((_bstr_t)strSQL, NULL, adCmdText);
		strSQL.Format("create table temp (id int, wage int, ym varchar(20), chuchai int, bingjia int, shijia int, pingshi int, shuangxiu int, fading int, waged int)");
		theApp.m_pConnection->Execute((_bstr_t)strSQL, NULL, adCmdText);
	}
	try//临时表中添加数据
	{
		CString SQL[9];
		strSQL = "insert into temp (id) select id from emp ;";
		//从员工表中读取员工ID
		SQL[0] = "update temp set wage = 0, ym = 2008-01, chuchai = 0, bingjia = 0, shijia = 0, pingshi = 0, shuangxiu = 0, fading = 0, waged = 0;";
		//月薪的更新
		SQL[1] = "update temp set wage = wageinfo.wage from wageinfo where temp.id = wageinfo.id;";
		//从考勤表中读取月份
		SQL[2] = "update temp set ym = checkinfo.ym from checkinfo where temp.id = checkinfo.id;";
		//根据月份从考勤表中统计考勤信息。
		SQL[3] = "update temp set chuchai = (select count(*) from checkinfo where temp.ym = checkinfo.ym and checkinfo.chuchai = '是' and temp.id = checkinfo.id);";
		SQL[4] = "update temp set bingjia = (select count(*) from checkinfo where temp.ym = checkinfo.ym and checkinfo.bingjia = '是' and temp.id = checkinfo.id);";
		SQL[5] = "update temp set shijia = (select count(*) from checkinfo where temp.ym = checkinfo.ym and checkinfo.shijia = '是' and temp.id = checkinfo.id);";
		SQL[6] = "update temp set pingshi = (select sum(ot1) from checkinfo where temp.ym = checkinfo.ym and temp.id = checkinfo.id) ;";
		SQL[7] = "update temp set shuangxiu = (select sum(ot2) from checkinfo where temp.ym = checkinfo.ym and temp.id = checkinfo.id) ;";
		SQL[8] = "update temp set fading = (select sum(ot3) from checkinfo where temp.ym = checkinfo.ym and temp.id = checkinfo.id) ;";
		for(int i = 0; i < 9; i++)
			strSQL += SQL[i];
		theApp.m_pConnection->Execute((_bstr_t)strSQL, NULL, adCmdText);
	}
	CATCH_ERROR;
	float chuchai, bingjia, shijia, pingshi, shuangxiu, fading; //读取工资的计算公式
	_variant_t va;
	strSQL = "select * from wagecal";
	try
	{
		m_pRecordset = theApp.m_pConnection->Execute((_bstr_t)strSQL, NULL, adCmdText);
		va = m_pRecordset->GetCollect(_variant_t((long)0));
		chuchai = va.iVal;
		va = m_pRecordset->GetCollect(_variant_t((long)1));
		bingjia = va.iVal;
		va = m_pRecordset->GetCollect(_variant_t((long)2));
		shijia = va.iVal;
		va = m_pRecordset->GetCollect(_variant_t((long)3));
		pingshi = va.iVal;
		va = m_pRecordset->GetCollect(_variant_t((long)4));
		shuangxiu = va.iVal;
		va = m_pRecordset->GetCollect(_variant_t((long)5));
		fading = va.iVal;
	}
	CATCH_ERROR;
	strSQL.Format("update temp set waged = (wage / 23 * chuchai * %f / 100 + wage / 23 * bingjia * %f / 100 + wage / 23 * shijia * %f / 100 + wage / 23 / 8 * pingshi * %f / 100 + wage / 23 / 8 * shuangxiu * %f / 100 + wage / 23 / 8 * fading * %f / 100 + wage / 23 * (23 - chuchai - bingjia - shijia))",
		chuchai, bingjia, shijia, pingshi, shuangxiu, fading);
	try//计算员工的工资
	{
		m_pRecordset = theApp.m_pConnection->Execute((_bstr_t)strSQL, NULL, adCmdText);
	}
	CATCH_ERROR;
	strSQL = "select * from temp";//从temp表中查询数据填充在list中
	ShowListData(strSQL);
	strSQL = "select ym from temp group by ym";//填充月份combobox
	try
	{
		m_pRecordset = theApp.m_pConnection->Execute((_bstr_t)strSQL, NULL, adCmdText);
		while(!m_pRecordset->adoEOF)
		{
			m_Month.AddString((char*)_bstr_t(m_pRecordset->GetCollect(_variant_t((long)0))));
			m_pRecordset->MoveNext();
		}
	}
	CATCH_ERROR;
	m_Month.SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CWageDlg::ShowListData(const CString& sql)
{
	m_ListCrtl.DeleteAllItems();
	try
	{
		m_pRecordset = theApp.m_pConnection->Execute((_bstr_t)sql, NULL, adCmdText);
		int i = 0;
		while(!m_pRecordset->adoEOF)
		{
			m_ListCrtl.InsertItem(i, (char*)_bstr_t(m_pRecordset->GetCollect(_variant_t((long)0))));
			for(int j = 1; j < 10; j++)
			{
				m_ListCrtl.SetItemText(i, j, (char*)_bstr_t(m_pRecordset->GetCollect(_variant_t((long)j))));
			}
			i++;
			m_pRecordset->MoveNext();
		}
	}
	CATCH_ERROR;
}

void CWageDlg::OnButton1() 
{
	UpdateData();			//数据的更新呢
	CString strSQL, strMonth;
	int nIndex = m_Month.GetCurSel();//月份的获取
	m_Month.GetLBText(nIndex, strMonth);
	strSQL.Format("select * from temp where id = %s and ym = '%s'", m_strID, strMonth);
	ShowListData(strSQL);
}
