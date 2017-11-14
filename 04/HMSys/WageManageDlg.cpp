// WageManageDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hmsys.h"
#include "WageManageDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWageManageDlg dialog
extern CHMSysApp theApp;

CWageManageDlg::CWageManageDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWageManageDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWageManageDlg)
	m_strID = _T("");
	m_nWage = 0;
	m_Date = CTime::GetCurrentTime();
	//}}AFX_DATA_INIT
	m_nFlag = -1;
}


void CWageManageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWageManageDlg)
	DDX_Control(pDX, IDC_COMBO1, m_Depart);
	DDX_Control(pDX, IDC_LIST1, m_ListCrtl);
	DDX_Control(pDX, IDC_TREE1, m_TreeCrtl);
	DDX_Text(pDX, IDC_ID, m_strID);
	DDX_Text(pDX, IDC_WAGE, m_nWage);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, m_Date);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWageManageDlg, CDialog)
	//{{AFX_MSG_MAP(CWageManageDlg)
	ON_NOTIFY(NM_DBLCLK, IDC_TREE1, OnDblclkTree1)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_UPDATE, OnUpdate)
	ON_BN_CLICKED(IDC_SAVE, OnSave)
	ON_BN_CLICKED(IDC_DEL, OnDel)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, OnItemchangedList1)
	ON_BN_CLICKED(IDC_INDEX, OnIndex)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWageManageDlg message handlers

BOOL CWageManageDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_pRecordset.CreateInstance("ADODB.Recordset");	
	ShowTreeData();
	m_ListCrtl.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT );//风格的设定
	m_ListCrtl.InsertColumn(0, "员工ID", LVCFMT_CENTER, 60);//列标题的设定
	m_ListCrtl.InsertColumn(1, "月薪", LVCFMT_CENTER, 60);
	m_ListCrtl.InsertColumn(2, "部门", LVCFMT_CENTER, 100);
	m_ListCrtl.InsertColumn(3, "进入时间", LVCFMT_CENTER, 100);
	GetDlgItem(IDC_SAVE)->EnableWindow(FALSE);//控件的禁用
	CString strSQL;//定义字符串变量
	strSQL.Format("select name from dep");
	try
	{
		m_pRecordset = theApp.m_pConnection->Execute((_bstr_t)strSQL, NULL, adCmdText);
		while(!m_pRecordset->adoEOF)//记录没有到末尾
		{
			m_Depart.AddString((char*)_bstr_t(m_pRecordset->GetCollect(_variant_t((long)0))));
			m_pRecordset->MoveNext();//移动到下条记录
		}
	}
	CATCH_ERROR;
	m_Depart.SetCurSel(0);
	ShowListData("select * from wageinfo");
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CWageManageDlg::ShowTreeData()
{
	m_TreeCrtl.DeleteAllItems();
	HTREEITEM hItem;
	TVINSERTSTRUCT tvInsert;
	tvInsert.hParent = NULL;
	tvInsert.hInsertAfter = NULL;
	tvInsert.item.mask = TVIF_TEXT;
	tvInsert.item.pszText = _T("某单位");
	m_hParent = m_TreeCrtl.InsertItem(&tvInsert);
	_variant_t vName;
	CString strSQL;
	strSQL.Format("select [name] from dep");
	try
	{
		m_pRecordset = theApp.m_pConnection->Execute((_bstr_t)strSQL, NULL, adCmdText);
		while(!m_pRecordset->adoEOF)
		{
			vName = m_pRecordset->GetCollect(_variant_t((long)0));
			hItem = m_TreeCrtl.InsertItem((char*)_bstr_t(vName), m_hParent);
			strSQL.Format("select name from emp");
			m_pRecordset1 = theApp.m_pConnection->Execute((_bstr_t)strSQL, NULL, adCmdText);
			while(!m_pRecordset1->adoEOF)
			{
				vName = m_pRecordset1->GetCollect(_variant_t((long)0));
				m_TreeCrtl.InsertItem((char*)_bstr_t(vName), hItem);
				m_pRecordset1->MoveNext();
			}
			m_pRecordset->MoveNext();
		}
		m_TreeCrtl.Expand(m_hParent,TVE_EXPAND);
	}
	CATCH_ERROR;
}

void CWageManageDlg::ShowListData(const CString& sql)
{
	m_ListCrtl.DeleteAllItems();
	try
	{
		m_pRecordset = theApp.m_pConnection->Execute((_bstr_t)sql, NULL, adCmdText);
		int i = 0;
		while(!m_pRecordset->adoEOF)
		{
			m_ListCrtl.InsertItem(i, (char*)_bstr_t(m_pRecordset->GetCollect(_variant_t((long)0))));
			m_ListCrtl.SetItemText(i, 1, (char*)_bstr_t(m_pRecordset->GetCollect(_variant_t((long)1))));
			m_ListCrtl.SetItemText(i, 2, (char*)_bstr_t(m_pRecordset->GetCollect(_variant_t((long)2))));
			m_ListCrtl.SetItemText(i, 3, (char*)_bstr_t(m_pRecordset->GetCollect(_variant_t((long)3))));
			i++;
			m_pRecordset->MoveNext();
		}
	}
	CATCH_ERROR;
}

void CWageManageDlg::OnDblclkTree1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	_variant_t va;
	CString strSQL;
	HTREEITEM hSelect;
	hSelect = m_TreeCrtl.GetSelectedItem();
	CString strName;
	if(hSelect != m_hParent)
	{
		strName = m_TreeCrtl.GetItemText(hSelect);
		if(m_TreeCrtl.GetParentItem(hSelect) == m_hParent)
		{
			strSQL.Format("select * from wageinfo where dep = '%s'", strName);
			ShowListData(strSQL);
		}
	}
	*pResult = 0;
}

void CWageManageDlg::OnAdd() 
{
	m_strID = "";
	m_nFlag = 1;			//标记的设定
	m_nWage = 0;
	GetDlgItem(IDC_SAVE)->EnableWindow();//控件的恢复
	UpdateData(FALSE);
}

void CWageManageDlg::OnUpdate() 
{
	UpdateData();
	if(m_strID == "")
	{
		MessageBox("请选择一条记录！");
		return ;
	}
	GetDlgItem(IDC_SAVE)->EnableWindow();	//控件的恢复
	m_nFlag = 2;	//标记的设定
}

void CWageManageDlg::OnSave() 
{
	UpdateData();				//数据的更新
	if(m_strID == "")
	{
		MessageBox("ID不能为空！");
		return ;
	}
	CString strSQL, strDep, strDate;//定义字符串变量
	_variant_t va;
	strSQL.Format("select count(*) from emp  where [id] = %s", m_strID);
	try
	{
		m_pRecordset = theApp.m_pConnection->Execute((_bstr_t)strSQL, NULL, adCmdText);
		va = m_pRecordset->GetCollect(_variant_t((long)0));//获取记录的值
		if(va.iVal == 0)
		{
			MessageBox("没有此员工！");
			return ;
		}
	}
	CATCH_ERROR;
	int nIndex = m_Depart.GetCurSel();//获取选中的索引
	m_Depart.GetLBText(nIndex, strDep);//获取选中的文本
	strDate.Format("%d-%d-%d", m_Date.GetYear(), m_Date.GetMonth(), m_Date.GetDay());
	if(m_nFlag == 1)//插入操作
	{	
		strSQL.Format("insert into wageinfo values(%s, %d, '%s', '%s')",
			m_strID, m_nWage, strDep, strDate);
	}
	if(m_nFlag == 2)//修改操作
	{
		strSQL.Format("update wageinfo set wage = %d, date = '%s' where id = %s", m_nWage, strDate, m_strID);
	}
	try
	{
		theApp.m_pConnection->Execute((_bstr_t)strSQL, NULL, adCmdText);
		GetDlgItem(IDC_SAVE)->EnableWindow(FALSE);//控件的禁用
		m_strID = "";
		m_nFlag = -1;
		m_nWage = 0;
		MessageBox("操作成功！");
		ShowListData("select * from wageinfo");
		ShowTreeData();
	}
	CATCH_ERROR;
	UpdateData(FALSE);
}

void CWageManageDlg::OnDel() 
{
	UpdateData();						//数据的更新
	if(m_strID == "")
	{
		MessageBox("请选择一条记录！");
		return ;
	}
	if(MessageBox("确定删除吗？", "注意", MB_YESNO) == IDYES)
	{
		CString strSQL;					//定义字符串变量
		strSQL.Format("delete wageinfo where id = '%s'", m_strID);
		try
		{
			theApp.m_pConnection->Execute((_bstr_t)strSQL, NULL, adCmdText);
			MessageBox("删除成功！");
			ShowTreeData();
			ShowListData("select * from wageinfo");
		}
		CATCH_ERROR;
	}		
}

void CWageManageDlg::OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	int nSelect = pNMListView->iItem;
	m_strID = m_ListCrtl.GetItemText(nSelect, 0);
	m_nWage = atoi(m_ListCrtl.GetItemText(nSelect, 1));
	GetDlgItem(IDC_COMBO1)->SetWindowText(m_ListCrtl.GetItemText(nSelect, 2));
	CString strDate = m_ListCrtl.GetItemText(nSelect, 3);

	COleVariant vtime(strDate);
	vtime.ChangeType(VT_DATE);
	COleDateTime time1=vtime;
	SYSTEMTIME systime;
	VariantTimeToSystemTime(time1, &systime);
	CTime tm(systime);
	m_Date   =   tm;  
	UpdateData(FALSE);	
	*pResult = 0;
}

void CWageManageDlg::OnIndex() 
{
	UpdateData();
	CString strSQL, strDate;
	strDate.Format("%d-%d-%d", m_Date.GetYear(), m_Date.GetMonth(), m_Date.GetDay());
	strSQL.Format("select * from wageinfo where id like '%%%s%%' and wage like '%%%d%%' and date like '%%%s%%'",
		m_strID, m_nWage, strDate);
	ShowListData(strSQL);
}
