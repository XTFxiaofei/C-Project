// SubTab1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "gradudemis.h"
#include "SubTab1Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSubTab1Dlg dialog


CSubTab1Dlg::CSubTab1Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSubTab1Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSubTab1Dlg)
	m_find = _T("");
	//}}AFX_DATA_INIT
}


void CSubTab1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSubTab1Dlg)
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	DDX_Control(pDX, IDC_LIST1, m_ctrlsubTab1list);
	DDX_Text(pDX, IDC_EDIT1, m_find);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSubTab1Dlg, CDialog)
	//{{AFX_MSG_MAP(CSubTab1Dlg)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, OnItemchangedList1)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSubTab1Dlg message handlers
void CSubTab1Dlg::OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	int i=pNMListView->iItem;						//获取选定的行号
	selectID=m_ctrlsubTab1list.GetItemText(i,0);	//去除选定行的第一列的文本
	*pResult = 0;
}


BOOL CSubTab1Dlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_ctrlsubTab1list.InsertColumn(0,"题目",LVCFMT_LEFT,60,0);//插入列标题，设定宽度，对齐方式
	m_ctrlsubTab1list.InsertColumn(1,"类型",LVCFMT_LEFT,80,0);
	m_ctrlsubTab1list.InsertColumn(2,"简述",LVCFMT_LEFT,150,0);
	m_ctrlsubTab1list.InsertColumn(3,"要求",LVCFMT_LEFT,150,0);
	m_ctrlsubTab1list.InsertColumn(4,"导师",LVCFMT_LEFT,80,0);
    m_ctrlsubTab1list.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);	
	m_pSet.Open();	
	int i=0;												//定义整形变量
	while(!m_pSet.IsEOF())									//如果记录不是最后一条
	{
		m_ctrlsubTab1list.InsertItem(i,m_pSet.m_sub_title);	//像列表控件中插入数据
		m_ctrlsubTab1list.SetItemText(i,1,m_pSet.m_sub_type);
		m_ctrlsubTab1list.SetItemText(i,2,m_pSet.m_sub_pro);
		m_ctrlsubTab1list.SetItemText(i,3,m_pSet.m_sub_demand);
		m_ctrlsubTab1list.SetItemText(i,4,m_pSet.m_tecr_name);		
        m_pSet.MoveNext();									//移动到下条记录
        i++;
	}
	m_pSet.Close();			
	m_combo.SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSubTab1Dlg::OnButton1() 
{
	UpdateData();
	if(m_find == "")
	{
		MessageBox("请输入查询条件！");
		return ;
	}
	CString str, sql;
	int nIndex = m_combo.GetCurSel();
	switch(nIndex)
	{
	case 0:
		sql.Format("select * from tab_sub where sub_title like '%%%s%%'", m_find);
		
		break;
	case 1:
		sql.Format("select * from tab_sub where tecr_name like '%%%s%%'", m_find);
		break;
	case 2:
		sql.Format("select * from tab_sub where sub_type like '%%%s%%'", m_find);
		break;
	}
	CDatabase *pDb = new CDatabase();
	CSubjectSet *pSet = new CSubjectSet(pDb);
	pSet->Open(AFX_DB_USE_DEFAULT_TYPE, sql);

	m_ctrlsubTab1list.DeleteAllItems();
	int i=0;												//定义整形变量
	while(!pSet->IsEOF())									//如果记录不是最后一条
	{
		m_ctrlsubTab1list.InsertItem(i,pSet->m_sub_title);	//像列表控件中插入数据
		m_ctrlsubTab1list.SetItemText(i,1,pSet->m_sub_type);
		m_ctrlsubTab1list.SetItemText(i,2,pSet->m_sub_pro);
		m_ctrlsubTab1list.SetItemText(i,3,pSet->m_sub_demand);
		m_ctrlsubTab1list.SetItemText(i,4,pSet->m_tecr_name);		
        pSet->MoveNext();									//移动到下条记录
        i++;
	}
	pSet->Close();
}
