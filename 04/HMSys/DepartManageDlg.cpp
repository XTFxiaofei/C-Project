// DepartManageDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HMSys.h"
#include "DepartManageDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDepartManageDlg dialog
extern CHMSysApp theApp;

CDepartManageDlg::CDepartManageDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDepartManageDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDepartManageDlg)
	m_strManager = _T("");
	m_strMore = _T("");
	m_strName = _T("");
	m_strPhone = _T("");
	//}}AFX_DATA_INIT
	m_nSelect = -1;
}


void CDepartManageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDepartManageDlg)
	DDX_Control(pDX, IDC_TREE1, m_TreeCrtl);
	DDX_Text(pDX, IDC_MANAGER, m_strManager);
	DDX_Text(pDX, IDC_MORE, m_strMore);
	DDX_Text(pDX, IDC_NAME, m_strName);
	DDX_Text(pDX, IDC_PHONE, m_strPhone);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDepartManageDlg, CDialog)
	//{{AFX_MSG_MAP(CDepartManageDlg)
	ON_NOTIFY(NM_DBLCLK, IDC_TREE1, OnDblclkTree1)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_UPDATE, OnUpdate)
	ON_BN_CLICKED(IDC_SAVE, OnSave)
	ON_BN_CLICKED(IDC_DEL, OnDel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDepartManageDlg message handlers

BOOL CDepartManageDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_pRecordset.CreateInstance("ADODB.Recordset");
	ShowTreeData();
	GetDlgItem(IDC_SAVE)->EnableWindow(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDepartManageDlg::ShowTreeData()
{
	m_TreeCrtl.DeleteAllItems();
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
			m_TreeCrtl.InsertItem((char*)_bstr_t(vName), m_hParent);
			m_pRecordset->MoveNext();
		}
		m_TreeCrtl.Expand(m_hParent,TVE_EXPAND);
	}
	CATCH_ERROR;
}

void CDepartManageDlg::OnDblclkTree1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	_variant_t va;
	HTREEITEM hSelect;
	hSelect = m_TreeCrtl.GetSelectedItem();
	CString strName;
	if(hSelect != m_hParent)
	{
		strName = m_TreeCrtl.GetItemText(hSelect);	
		CString strSQL;
		strSQL.Format("select * from dep where name = '%s'", strName);
		try
		{
			m_pRecordset = theApp.m_pConnection->Execute((_bstr_t)strSQL, NULL, adCmdText);
			va = m_pRecordset->GetCollect(_variant_t((long)0));
			m_nID = va.iVal;
			m_strName = (char*)_bstr_t(m_pRecordset->GetCollect(_variant_t((long)1)));
			m_strManager = (char*)_bstr_t(m_pRecordset->GetCollect(_variant_t((long)2)));
			m_strPhone = (char*)_bstr_t(m_pRecordset->GetCollect(_variant_t((long)3)));
			m_strMore = (char*)_bstr_t(m_pRecordset->GetCollect(_variant_t((long)4)));
		}
		CATCH_ERROR;
	}
	UpdateData(FALSE);
	*pResult = 0;
}

void CDepartManageDlg::OnAdd() 
{
	m_strMore = m_strName = m_strManager = m_strPhone = "";
	m_nSelect = 1;
	GetDlgItem(IDC_SAVE)->EnableWindow();
	UpdateData(FALSE);
}

void CDepartManageDlg::OnUpdate() 
{
	m_nSelect = 2;
	GetDlgItem(IDC_SAVE)->EnableWindow();
}

void CDepartManageDlg::OnSave() 
{
	UpdateData();
	if(m_strName == "")
	{
		MessageBox("名称不能为空！");
		return ;
	}
	CString strSQL;
	if(m_nSelect == 1)
	{
		strSQL.Format("insert into dep (name, manager, phone, more) values ('%s', '%s', '%s', '%s')", 
			m_strName, m_strManager, m_strPhone, m_strMore);
		try
		{
			theApp.m_pConnection->Execute((_bstr_t)strSQL, NULL, adCmdText);
			ShowTreeData();
			MessageBox("添加成功");
		}
		CATCH_ERROR;
	}
	if(m_nSelect == 2)
	{
		strSQL.Format("update dep set name = '%s', manager = '%s', phone = '%s', more = '%s' where id = %d",
			m_strName, m_strManager, m_strPhone, m_strMore, m_nID);
		try
		{
			theApp.m_pConnection->Execute((_bstr_t)strSQL, NULL, adCmdText);
			ShowTreeData();
			MessageBox("修改成功");
		}
		CATCH_ERROR;
	}
	GetDlgItem(IDC_SAVE)->EnableWindow(FALSE);
}

void CDepartManageDlg::OnDel() 
{
	UpdateData();
	if(m_strName == "")
	{
		MessageBox("请选择一个部门！");
		return ;
	}
	CString strSQL;
	strSQL.Format("delete from dep where id = %d", m_nID);
	if(MessageBox("确定删除吗？", "注意", MB_YESNO) == IDYES)
	{
		try
		{
			theApp.m_pConnection->Execute((_bstr_t)strSQL, NULL, adCmdText);
			ShowTreeData();
		}
		CATCH_ERROR;
	}
}
