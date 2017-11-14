// CheckInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hmsys.h"
#include "CheckInfoDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCheckInfoDlg dialog
extern CHMSysApp theApp;

CCheckInfoDlg::CCheckInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCheckInfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCheckInfoDlg)
	m_strID = _T("");
	m_Date = CTime::GetCurrentTime();
	//}}AFX_DATA_INIT
}


void CCheckInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCheckInfoDlg)
	DDX_Control(pDX, IDC_LIST1, m_ListCrtl);
	DDX_Text(pDX, IDC_ID, m_strID);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, m_Date);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCheckInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CCheckInfoDlg)
	ON_BN_CLICKED(IDC_INDEX, OnIndex)
	ON_BN_CLICKED(IDC_DEL, OnDel)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, OnItemchangedList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCheckInfoDlg message handlers

BOOL CCheckInfoDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_pRecordset.CreateInstance("ADODB.Recordset");		//创建记录集实例
	m_ListCrtl.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT );//风格的设定。整行选择
	m_ListCrtl.InsertColumn(0, "日期", LVCFMT_CENTER, 80);
	m_ListCrtl.InsertColumn(1, "员工ID", LVCFMT_CENTER, 60);
	m_ListCrtl.InsertColumn(2, "缺勤", LVCFMT_CENTER, 40);
	m_ListCrtl.InsertColumn(3, "早退", LVCFMT_CENTER, 40);
	m_ListCrtl.InsertColumn(4, "迟到", LVCFMT_CENTER, 40);
	m_ListCrtl.InsertColumn(5, "休息", LVCFMT_CENTER, 40);
	m_ListCrtl.InsertColumn(6, "病假", LVCFMT_CENTER, 40);
	m_ListCrtl.InsertColumn(7, "出差", LVCFMT_CENTER, 40);
	m_ListCrtl.InsertColumn(8, "事假", LVCFMT_CENTER, 40);
	m_ListCrtl.InsertColumn(9, "备注", LVCFMT_CENTER, 120);
	CString strSQL;								//定义字符串变量
	strSQL.Format("select * from checkinfo ");
	try
	{
		m_pRecordset = theApp.m_pConnection->Execute((_bstr_t)strSQL, NULL, adCmdText);//执行SQL语句
		int i = 0;//定义整形变量并赋初值0
		while(!m_pRecordset->adoEOF)//如果记录没有到末尾
		{
			m_ListCrtl.InsertItem(i, (char*)_bstr_t(m_pRecordset->GetCollect(_variant_t((long)0))));
			for(int j = 1; j < 9; j++)
				m_ListCrtl.SetItemText(i, j, (char*)_bstr_t(m_pRecordset->GetCollect(_variant_t((long)j))));
			i++;
			m_pRecordset->MoveNext();//移动到下一条记录
		}
	}
	CATCH_ERROR;
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CCheckInfoDlg::ShowListData(const CString& sql)
{
	m_ListCrtl.DeleteAllItems();//删除列表控件中的所有子项
	try
	{
		m_pRecordset = theApp.m_pConnection->Execute((_bstr_t)sql, NULL, adCmdText);//执行SQL语句
		int i = 0;
		while(!m_pRecordset->adoEOF)//如果记录没有到末尾
		{
			m_ListCrtl.InsertItem(i, (char*)_bstr_t(m_pRecordset->GetCollect(_variant_t((long)0))));
			//将数据插入到列表控件中
			for(int j = 1; j < 9; j++)
				m_ListCrtl.SetItemText(i, j, (char*)_bstr_t(m_pRecordset->GetCollect(_variant_t((long)j))));
			i++;
			m_pRecordset->MoveNext();//移动到下一条记录
		}
	}
	CATCH_ERROR;
}

void CCheckInfoDlg::OnIndex() 
{
	UpdateData();
	if(m_strID == "")
	{
		MessageBox("请出入查询条件！");
		return ;
	}
	CString strSQL, strDate;//定义字符串变量
	strDate.Format("%d-%d-%d", m_Date.GetYear(), m_Date.GetMonth(), m_Date.GetDay());
	strSQL.Format("select * from checkinfo where id = %s and date = '%s'", m_strID, strDate);
	ShowListData(strSQL);//
}

void CCheckInfoDlg::OnDel() 
{
	if(m_strID == "")
	{
		MessageBox("请选择一条记录！");
		return ;
	}
	if(MessageBox("确定删除吗？", "注意", MB_YESNO) == IDYES)
	{
		CString strSQL, strDate;
		strDate.Format("%d-%d-%d", m_Date.GetYear(), m_Date.GetMonth(), m_Date.GetDay());
		strSQL.Format("delete from checkinfo where id = %s and date = '%s'", m_strID, strDate);
		try 
		{
			theApp.m_pConnection->Execute((_bstr_t)strSQL, NULL, adCmdText);
			ShowListData("select * from checkinfo");
		}
		CATCH_ERROR;
	}
}

void CCheckInfoDlg::OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	int nSelect = pNMListView->iItem;//获取列表控件中选中的行的索引
	m_strID = m_ListCrtl.GetItemText(nSelect, 1);//获取列表控件选中行第二项的文本
	CString strDate = m_ListCrtl.GetItemText(nSelect, 0);
	COleVariant vtime(strDate);
	vtime.ChangeType(VT_DATE);
	COleDateTime time1=vtime;
	SYSTEMTIME systime;
	VariantTimeToSystemTime(time1, &systime);
	CTime tm(systime); 
	m_Date=tm;
	UpdateData(FALSE);	
	*pResult = 0;
}
