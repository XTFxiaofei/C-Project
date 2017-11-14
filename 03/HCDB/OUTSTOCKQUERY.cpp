// OUTSTOCKQUERY.cpp : implementation file
//

#include "stdafx.h"
#include "HCDB.h"
#include "OUTSTOCKQUERY.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COUTSTOCKQUERY dialog
extern CHCDBApp theApp;

COUTSTOCKQUERY::COUTSTOCKQUERY(CWnd* pParent /*=NULL*/)
	: CDialog(COUTSTOCKQUERY::IDD, pParent)
{
	//{{AFX_DATA_INIT(COUTSTOCKQUERY)
		// NOTE: the ClassWizard will add member initialization here
	m_begintime = 0;
	m_endtime = 0;
	m_edit2 = _T("");
	//}}AFX_DATA_INIT
}


void COUTSTOCKQUERY::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COUTSTOCKQUERY)
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_DATETIMEPICKER2, m_endtimectrl);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_begintimectrl);
	DDX_Control(pDX, IDC_COMBO1, m_comquery);
	DDX_Control(pDX, IDC_CHECK2, m_check2);
	DDX_Control(pDX, IDC_CHECK1, m_check);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, m_begintime);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER2, m_endtime);
	DDX_Text(pDX, IDC_EDIT2, m_edit2);
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COUTSTOCKQUERY, CDialog)
	//{{AFX_MSG_MAP(COUTSTOCKQUERY)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_EN_KILLFOCUS(IDC_EDIT2, OnKillfocusEdit2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COUTSTOCKQUERY message handlers

void COUTSTOCKQUERY::GetMercRecord(CString sqlstr)
{
    m_mercRecord=NULL;
	m_mercRecord.CreateInstance(__uuidof(Recordset));
	CString strgetprovname;
	m_mercRecord=NULL;
	m_mercRecord.CreateInstance(__uuidof(Recordset));
	m_mercRecord->Open((_variant_t )sqlstr,theApp.m_connection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	if(m_mercRecord->RecordCount==0)
	{ 
		MessageBox("没有找到");
		return;
	}
}

void COUTSTOCKQUERY::GetRecord(CString sqlstr)
{ 
    m_record=NULL;
	m_record.CreateInstance(__uuidof(Recordset));
	CString strgetprovname;
	m_record=NULL;
	m_record.CreateInstance(__uuidof(Recordset));
	m_record->Open((_variant_t )sqlstr,theApp.m_connection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
}

void COUTSTOCKQUERY::InitDate()
{
   	CTime tm=CTime::GetCurrentTime();
	m_begintime=tm;
    m_endtime=tm;
	UpdateData(false);
}

void COUTSTOCKQUERY::OnButton1() 
{
	// TODO: Add your control notification handler code here
	if((m_check.GetCheck()==false)&&(m_check2.GetCheck()==false))
	{
		MessageBox("请设置查询条件","系统提示",64);
		return ;
	}
	if(m_check.GetCheck()==true&&(m_check2.GetCheck()==false))
	{
		UpdateData();
		if(m_edit2=="")
		{
         MessageBox("请设置查询条件","系统提示",64);
		 return ;
		}
		CString sqlstr;
		m_list.DeleteAllItems();
		CString fileds;
        fileds="storid";
        sqlstr.Format("select * from tb_storage where %s='%s' and storflag='0'",fileds,m_edit2);
        GetRecord(sqlstr);
        int row=0;
		while(!m_record->_EOF)
		{
			CString temp;
		
			temp=(LPCSTR)(_bstr_t)m_record->GetFields()->GetItem("merchandiseid")->Value;
            m_list.InsertItem(row,temp);
			sqlstr.Format("select * from tb_merchangiseinfo where id='%s'",temp);
			GetMercRecord(sqlstr);
			temp=(LPCSTR)(_bstr_t)m_mercRecord->GetFields()->GetItem("mercname")->Value;
			m_list.SetItemText(row,1,temp);
            temp=(LPCSTR)(_bstr_t)m_mercRecord->GetFields()->GetItem("inprice")->Value;
			m_list.SetItemText(row,2,temp);
			temp=(LPCSTR)(_bstr_t)m_record->GetFields()->GetItem("numbers")->Value;
			m_list.SetItemText(row,3,temp);
			temp=(LPCSTR)(_bstr_t)m_record->GetFields()->GetItem("paymoney")->Value;
			m_list.SetItemText(row,4,temp);
			temp=(LPCSTR)(_bstr_t)m_mercRecord->GetFields()->GetItem("discount")->Value;
			m_list.SetItemText(row,5,temp);
			temp=(LPCSTR)(_bstr_t)m_record->GetFields()->GetItem("operid")->Value;
			
			m_list.SetItemText(row,6,temp);
			temp=(LPCSTR)(_bstr_t)m_record->GetFields()->GetItem("storid")->Value;
			m_list.SetItemText(row,7,temp);
			m_record->MoveNext();
			row++;
		}
		CString str;
		
		str.Format("找到了%d条记录",row);
		MessageBox(str);
	}


	if(m_check.GetCheck()==true&&(m_check2.GetCheck()==true))
	{
		UpdateData();
		if(m_edit2=="")
		{
         MessageBox("请设置查询条件","系统提示",64);
		 return ;
		}
		CString sqlstr;
		m_list.DeleteAllItems();
		CString fileds;
        fileds="storid";
	    sqlstr.Format("select * from tb_storage where %s='%s' and storflag='0' and stordate between '%s' and '%s'",fileds,m_edit2,m_begintime.Format("%Y-%m-%d"),m_endtime.Format("%Y-%m-%d"));
        GetRecord(sqlstr);
        int row=0;
		while(!m_record->_EOF)
		{
			CString temp;
		
			temp=(LPCSTR)(_bstr_t)m_record->GetFields()->GetItem("merchandiseid")->Value;
            m_list.InsertItem(row,temp);
			sqlstr.Format("select * from tb_merchangiseinfo where id='%s'",temp);
			GetMercRecord(sqlstr);
			temp=(LPCSTR)(_bstr_t)m_mercRecord->GetFields()->GetItem("mercname")->Value;
			m_list.SetItemText(row,1,temp);
            temp=(LPCSTR)(_bstr_t)m_mercRecord->GetFields()->GetItem("inprice")->Value;
			m_list.SetItemText(row,2,temp);
			temp=(LPCSTR)(_bstr_t)m_record->GetFields()->GetItem("numbers")->Value;
			m_list.SetItemText(row,3,temp);
			temp=(LPCSTR)(_bstr_t)m_record->GetFields()->GetItem("paymoney")->Value;
			m_list.SetItemText(row,4,temp);
			temp=(LPCSTR)(_bstr_t)m_mercRecord->GetFields()->GetItem("discount")->Value;
			m_list.SetItemText(row,5,temp);
			temp=(LPCSTR)(_bstr_t)m_record->GetFields()->GetItem("operid")->Value;
			
			m_list.SetItemText(row,6,temp);
			temp=(LPCSTR)(_bstr_t)m_record->GetFields()->GetItem("storid")->Value;
			m_list.SetItemText(row,7,temp);
			m_record->MoveNext();
			row++;
		}
		CString str;
		
		str.Format("找到了%d条记录",row);
		MessageBox(str);
	}
		if(m_check.GetCheck()==false&&(m_check2.GetCheck()==true))
	{
		UpdateData();
        CString sqlstr;
        sqlstr.Format("select * from tb_storage where stordate between '%s' and '%s' and storflag='0'",m_begintime.Format("%Y-%m-%d"),m_endtime.Format("%Y-%m-%d"));
        GetRecord(sqlstr);
        int row=0;
		m_list.DeleteAllItems();
		while(!m_record->_EOF)
		{
			CString temp;
		
			temp=(LPCSTR)(_bstr_t)m_record->GetFields()->GetItem("merchandiseid")->Value;
            m_list.InsertItem(row,temp);
			sqlstr.Format("select * from tb_merchangiseinfo where id='%s'",temp);
			GetMercRecord(sqlstr);
			temp=(LPCSTR)(_bstr_t)m_mercRecord->GetFields()->GetItem("mercname")->Value;
			m_list.SetItemText(row,1,temp);
            temp=(LPCSTR)(_bstr_t)m_mercRecord->GetFields()->GetItem("inprice")->Value;
			m_list.SetItemText(row,2,temp);
			temp=(LPCSTR)(_bstr_t)m_record->GetFields()->GetItem("numbers")->Value;
			m_list.SetItemText(row,3,temp);
			temp=(LPCSTR)(_bstr_t)m_record->GetFields()->GetItem("paymoney")->Value;
			m_list.SetItemText(row,4,temp);
			temp=(LPCSTR)(_bstr_t)m_mercRecord->GetFields()->GetItem("discount")->Value;
			m_list.SetItemText(row,5,temp);
			temp=(LPCSTR)(_bstr_t)m_record->GetFields()->GetItem("operid")->Value;
			
			m_list.SetItemText(row,6,temp);
			temp=(LPCSTR)(_bstr_t)m_record->GetFields()->GetItem("storid")->Value;
			m_list.SetItemText(row,7,temp);
			m_record->MoveNext();
			row++;
		}
		CString str;
		
		str.Format("找到了%d条记录",row);
		MessageBox(str);
	}
}

void COUTSTOCKQUERY::SetListStyle()
{
    m_list.InsertColumn(0,"商品编号",LVCFMT_LEFT,80);
	m_list.InsertColumn(1,"商品名称",LVCFMT_LEFT,120);
	m_list.InsertColumn(2,"单价",LVCFMT_LEFT,80);
	m_list.InsertColumn(3,"数量",LVCFMT_LEFT,80);
	m_list.InsertColumn(4,"折扣",LVCFMT_LEFT,80);
	m_list.InsertColumn(5,"金额",LVCFMT_LEFT,80);
	m_list.InsertColumn(6,"操作员",LVCFMT_LEFT,120);
	m_list.InsertColumn(7,"出库编号",LVCFMT_LEFT,120);
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
}

void COUTSTOCKQUERY::OnKillfocusEdit2() 
{
	// TODO: Add your control notification handler code here
	
}

BOOL COUTSTOCKQUERY::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
		SetListStyle();
	InitDate();
	m_comquery.SetCurSel(0);
	m_comquery.EnableWindow(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

