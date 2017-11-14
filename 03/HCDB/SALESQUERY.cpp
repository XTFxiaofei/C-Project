// SALESQUERY.cpp : implementation file
//

#include "stdafx.h"
#include "HCDB.h"
#include "SALESQUERY.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSALESQUERY dialog

extern CHCDBApp theApp;
CSALESQUERY::CSALESQUERY(CWnd* pParent /*=NULL*/)
	: CDialog(CSALESQUERY::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSALESQUERY)
	m_begintime = 0;
	m_endtime = 0;
	m_edit = _T("");
	//}}AFX_DATA_INIT
}


void CSALESQUERY::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSALESQUERY)
	DDX_Control(pDX, IDC_CHECK1, m_check);
	DDX_Control(pDX, IDC_LIST2, m_list2);
	DDX_Control(pDX, IDC_LIST1, m_list1);
	DDX_Control(pDX, IDC_COMBO1, m_comquery);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, m_begintime);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER2, m_endtime);
	DDX_Text(pDX, IDC_EDIT3, m_edit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSALESQUERY, CDialog)
	//{{AFX_MSG_MAP(CSALESQUERY)
	ON_BN_CLICKED(IDC_INVALIDATE, OnInvalidate)
	ON_BN_CLICKED(IDC_CHECK1, OnCheck1)
	ON_CBN_CLOSEUP(IDC_COMBO1, OnCloseupCombo1)
	ON_BN_CLICKED(IDC_CHAXUNxsd, OnCHAXUNxsd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSALESQUERY message handlers

BOOL CSALESQUERY::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	Initdate() ;
    ShowWindows(false);
    SetList1Style();
	SetList2Style();
	CString sqlstr;
	sqlstr.Format("select a.buyid,a.mercid,b.mercname,a.operid,a.quitinfo  from tb_sale a inner join tb_merchangiseinfo b on a.mercid=b.id" );
	SetList1Value(sqlstr);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void CSALESQUERY::Initdate() 
{
	CTime tm=CTime::GetCurrentTime();
	m_begintime=tm;
    m_endtime=tm;
	m_comquery.SetCurSel(0);
	UpdateData(false);

	return ; 
}

void CSALESQUERY::ShowWindows(bool flag)
{
	GetDlgItem(IDC_EDIT3)->ShowWindow(flag);
	GetDlgItem(IDC_STATIC1)->ShowWindow(flag);
    GetDlgItem(IDC_DATETIMEPICKER1)->ShowWindow(!flag);
    GetDlgItem(IDC_DATETIMEPICKER2)->ShowWindow(!flag);
}

void CSALESQUERY::OnInvalidate() 
{
	// TODO: Add your control notification handler code here
	
}

int CSALESQUERY::GetRecord(CString sqlstr)
{
  	m_record=NULL;
	m_record.CreateInstance(__uuidof(Recordset));
	try{
		m_record->Open((_variant_t )sqlstr,theApp.m_connection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	}
    catch(...)
	{
		MessageBox("error");
	}
		int count=0;
   if(m_record!=NULL)
   {
	   try
	   {
		   m_record->MoveFirst();
	   }
	   catch(...)
	   {
		   return 0;
	   }
	   if(m_record->_EOF)return 0;
	   while(!m_record->_EOF)
	   {
		  m_record->MoveNext();
		   count++;
	   }
   }
   m_record->MoveFirst();
   return count;
}

void CSALESQUERY::SetList1Style()
{
    m_list1.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list1.InsertColumn(0,"销售单号",LVCFMT_CENTER,80);
	m_list1.InsertColumn(1,"商品编号",LVCFMT_CENTER,140);
	m_list1.InsertColumn(2,"商品名称",LVCFMT_CENTER,140);
	m_list1.InsertColumn(3,"操作员",LVCFMT_CENTER,80);
    m_list1.InsertColumn(4,"备注",LVCFMT_CENTER,140);
}

void CSALESQUERY::SetList2Style()
{
   	m_list2.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list2.InsertColumn(0,"销售单号",LVCFMT_CENTER,80);
	m_list2.InsertColumn(1,"商品编号",LVCFMT_CENTER,140);
	m_list2.InsertColumn(2,"商品名称",LVCFMT_CENTER,80);
	m_list2.InsertColumn(3,"操作员",LVCFMT_CENTER,80);
    m_list2.InsertColumn(4,"备注",LVCFMT_CENTER,140);
}

void CSALESQUERY::SetList1Value(CString sqlstr)
{  
	GetRecord(sqlstr);
	m_list1.DeleteAllItems();
	int rows=0;
	try
	{
		while(!m_record->_EOF)
		{
			for(int i=0;i<4;i++)
			{
				CString str;
				str=(LPCSTR)(_bstr_t)m_record->Fields->GetItem(long(i))->Value;
				if(i==0)m_list1.InsertItem(rows,str);
				else
					m_list1.SetItemText(rows,i,str);
			}
			m_record->MoveNext();
			rows++;
		}
	}
	catch(...)
	{ 
		AfxMessageBox("没有找到该纪录!");
	}

}

void CSALESQUERY::SetList2Value(CString sqlstr)
{
   	GetRecord(sqlstr);
	m_list2.DeleteAllItems();
	int rows=0;
	try
	{
		while(!m_record->_EOF)
		{
			for(int i=0;i<4;i++)
			{
				CString str;
				str=(LPCSTR)(_bstr_t)m_record->Fields->GetItem(long(i))->Value;
				if(i==0)m_list1.InsertItem(rows,str);
				else
				m_list1.SetItemText(rows,i,str);
			}
			m_record->MoveNext();
			rows++;
		}
	}
	catch(...)
	{ 
		AfxMessageBox("没有找到该纪录!");
	}
}

void CSALESQUERY::OnCheck1() 
{
	// TODO: Add your control notification handler code here
	if(m_check.GetCheck())
	{
		
		GetDlgItem(IDC_DATETIMEPICKER1)->ShowWindow(true);
		GetDlgItem(IDC_DATETIMEPICKER2)->ShowWindow(true);
		GetDlgItem(IDC_EDIT3)->ShowWindow(true);
		GetDlgItem(IDC_STATIC1)->ShowWindow(true);
	}
	else
	{
	
		GetDlgItem(IDC_EDIT3)->ShowWindow(false);
		GetDlgItem(IDC_STATIC1)->ShowWindow(false);
	}
}

void CSALESQUERY::OnCloseupCombo1() 
{
	// TODO: Add your control notification handler code here
	
	if(m_comquery.GetCurSel()!=0)
	{
      ShowWindows(false);

	}
	else
	{
	  ShowWindows(true);
	}
}

void CSALESQUERY::OnCHAXUNxsd() 
{
	// TODO: Add your control notification handler code here
	CString sqlstr,sqlstr1,sqlstr2;
	CString str,fileds;
	UpdateData();
	m_comquery.GetLBText(m_comquery.GetCurSel(),str);

	if(str=="商品编号汇总")
	{

	}
	if(str=="入库编号汇总")
	{

	}

	if(str=="时间查询")
	{
		CTime tm1(m_begintime.GetYear(),m_begintime.GetMonth(),m_begintime.GetDay(),0,0,0);
		CTime tm2(m_endtime.GetYear(),m_endtime.GetMonth(),m_endtime.GetDay(),0,0,0);
		sqlstr.Format("select a.merchandiseid,b.mercname,a.unitprice,a.numbers,b.discount,a.paymoney,a.operid,a.storid,a.storflag from tb_storage a inner join tb_merchangiseinfo b\
			on a.merchandiseid=b.id where a.saledate between '%s' and '%s'",tm1.Format("%Y-%m-%d"),tm2.Format("%Y-%m-%d"));
			sqlstr1.Format("select sum(numbers) as allnum from tb_storage a inner join tb_merchangiseinfo b\
				on a.merchandiseid=b.id where a.stordate between '%s' and '%s' and a.storflag='0'",tm1.Format("%Y-%m-%d"),tm2.Format("%Y-%m-%d"));
				sqlstr2.Format("select sum(paymoney) as allmoney from tb_storage a inner join tb_merchangiseinfo b\
					on a.merchandiseid=b.id where a.stordate between '%s' and '%s' and a.storflag='0'",tm1.Format("%Y-%m-%d"),tm2.Format("%Y-%m-%d"));
	}
	//ShowList2(sqlstr);
}
