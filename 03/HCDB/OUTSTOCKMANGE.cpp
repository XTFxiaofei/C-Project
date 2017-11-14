// OUTSTOCKMANGE.cpp : implementation file
//

#include "stdafx.h"
#include "HCDB.h"
#include "OUTSTOCKMANGE.h"
#include "AnotherView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COUTSTOCKMANGE dialog
extern CHCDBApp theApp;

COUTSTOCKMANGE::COUTSTOCKMANGE(CWnd* pParent /*=NULL*/)
	: CDialog(COUTSTOCKMANGE::IDD, pParent)
{
	//{{AFX_DATA_INIT(COUTSTOCKMANGE)
	// NOTE: the ClassWizard will add member initialization here
	
	m_edit1 = _T("");
	m_begin = 0;
	m_end = 0;
	m_allnum = _T("");
	m_allmoney = _T("");
	//}}AFX_DATA_INIT	
	queryflag=false;
	m_allnum="累计\r\n数量:";
	m_allmoney="累计\r\n金额:";
}




void COUTSTOCKMANGE::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CINSTOCKMANGE)
	DDX_Control(pDX, IDC_STATIC4, m_allmoneyctrl);
	DDX_Control(pDX, IDC_STATIC3, m_allnumctrl);
	DDX_Control(pDX, IDC_STATIC2, m_static2);
	DDX_Control(pDX, IDC_EDIT3, m_edit);
	DDX_Control(pDX, IDC_STATIC1, m_static1);
	DDX_Control(pDX, IDC_DATETIMEPICKER2, m_endtime);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_begintime);
	DDX_Control(pDX, IDC_COMBO1, m_combox);
	DDX_Control(pDX, IDC_LIST2, m_list2);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Text(pDX, IDC_EDIT3, m_edit1);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, m_begin);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER2, m_end);
	DDX_Text(pDX, IDC_STATIC3, m_allnum);
	DDX_Text(pDX, IDC_STATIC4, m_allmoney);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(COUTSTOCKMANGE, CDialog)
	//{{AFX_MSG_MAP(COUTSTOCKMANGE)
		// NOTE: the ClassWizard will add message map macros here
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	ON_CBN_CLOSEUP(IDC_COMBO1, OnCloseupCombo1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
/////////////////////////////////////////////////////////////////////////////
// CINSTOCKMANGE message handlers

void COUTSTOCKMANGE::OnButton6() 
{
	// TODO: Add your control notification handler code here
	CString sqlstr;
	CString str,fileds;
	UpdateData();
	m_combox.GetLBText(m_combox.GetCurSel(),str);
	if(str=="商品编号汇总")
	{
	sqlstr.Format("select a.merchandiseid,b.mercname,a.unitprice,a.numbers,b.discount,a.paymoney,a.operid,a.storid,a.storflag from tb_storage a inner join tb_merchangiseinfo b\
		on a.merchandiseid=b.id where a.merchandiseid='%s' and a.storflag='0'",m_edit1);
	sqlstr1.Format("select sum(numbers) as allnum from tb_storage a inner join tb_merchangiseinfo b\
		on a.merchandiseid=b.id where a.merchandiseid='%s' and a.storflag='0'",m_edit1);
	sqlstr2.Format("select sum(paymoney) as allmoney from tb_storage a inner join tb_merchangiseinfo b\
		on a.merchandiseid=b.id where a.merchandiseid='%s' and a.storflag='0'",m_edit1);
	}
   if(str=="入库编号汇总")
	{
	sqlstr.Format("select a.merchandiseid,b.mercname,a.unitprice,a.numbers,b.discount,a.paymoney,a.operid,a.storid,a.storflag from tb_storage a inner join tb_merchangiseinfo b\
		on a.merchandiseid=b.id where a.storid='%s' and a.storflag='0'",m_edit1);
	sqlstr1.Format("select sum(numbers) as allnum from tb_storage a inner join tb_merchangiseinfo b\
		on a.merchandiseid=b.id where a.storid='%s' and a.storflag='0'",m_edit1);
	sqlstr2.Format("select sum(paymoney) as allmoney from tb_storage a inner join tb_merchangiseinfo b\
		on a.merchandiseid=b.id where a.storid='%s' and a.storflag='0'",m_edit1);
	}
    if(str=="年汇总")
	{
		int a=m_begin.GetYear();
		CTime tm1(a,1,1,0,0,0);
		a=m_end.GetYear();
		CTime tm2(a,12,31,0,0,0);
	sqlstr.Format("select a.merchandiseid,b.mercname,a.unitprice,a.numbers,b.discount,a.paymoney,a.operid,a.storid,a.storflag from tb_storage a inner join tb_merchangiseinfo b\
		on a.merchandiseid=b.id where a.stordate between '%s' and '%s' and a.storflag='0'",tm1.Format("%Y-%m-%d"),tm2.Format("%Y-%m-%d"));
	sqlstr1.Format("select sum(numbers) as allnum from tb_storage a inner join tb_merchangiseinfo b\
		on a.merchandiseid=b.id where a.stordate between '%s' and '%s' and a.storflag='0'",tm1.Format("%Y-%m-%d"),tm2.Format("%Y-%m-%d"));
	sqlstr2.Format("select sum(paymoney) as allmoney from tb_storage a inner join tb_merchangiseinfo b\
		on a.merchandiseid=b.id where a.stordate between '%s' and '%s' and a.storflag='0'",tm1.Format("%Y-%m-%d"),tm2.Format("%Y-%m-%d"));
	}
	if(str=="月汇总")
	{
        
		CTime tm1(m_begin.GetYear(),m_begin.GetMonth(),1,0,0,0);
		CTime tm2(m_end.GetYear(),m_end.GetMonth(),31,0,0,0);
		sqlstr.Format("select a.merchandiseid,b.mercname,a.unitprice,a.numbers,b.discount,a.paymoney,a.operid,a.storflag from tb_storage a inner join tb_merchangiseinfo b\
		on a.merchandiseid=b.id where a.stordate  between '%s' and '%s' and a.storflag='0'",tm1.Format("%Y-%m-%d"),tm2.Format("%Y-%m-%d"));
	sqlstr1.Format("select sum(numbers) as allnum from tb_storage a inner join tb_merchangiseinfo b\
		on a.merchandiseid=b.id where a.stordate between '%s' and '%s' and a.storflag='0'",tm1.Format("%Y-%m-%d"),tm2.Format("%Y-%m-%d"));
	sqlstr2.Format("select sum(paymoney) as allmoney from tb_storage a inner join tb_merchangiseinfo b\
		on a.merchandiseid=b.id where a.stordate between '%s' and '%s' and a.storflag='0'",tm1.Format("%Y-%m-%d"),tm2.Format("%Y-%m-%d"));
	}
	if(str=="天汇总")
	{
	CTime tm1(m_begin.GetYear(),m_begin.GetMonth(),m_begin.GetDay(),0,0,0);
	CTime tm2(m_end.GetYear(),m_end.GetMonth(),m_end.GetDay(),0,0,0);
	sqlstr.Format("select a.merchandiseid,b.mercname,a.unitprice,a.numbers,b.discount,a.paymoney,a.operid,a.storid,a.storflag from tb_storage a inner join tb_merchangiseinfo b\
		on a.merchandiseid=b.id where a.stordate between '%s' and '%s' and a.storflag='0'",tm1.Format("%Y-%m-%d"),tm2.Format("%Y-%m-%d"));
	sqlstr1.Format("select sum(numbers) as allnum from tb_storage a inner join tb_merchangiseinfo b\
		on a.merchandiseid=b.id where a.stordate between '%s' and '%s' and a.storflag='0'",tm1.Format("%Y-%m-%d"),tm2.Format("%Y-%m-%d"));
	sqlstr2.Format("select sum(paymoney) as allmoney from tb_storage a inner join tb_merchangiseinfo b\
		on a.merchandiseid=b.id where a.stordate between '%s' and '%s' and a.storflag='0'",tm1.Format("%Y-%m-%d"),tm2.Format("%Y-%m-%d"));
	}
	ShowList2(sqlstr);

   
}

void COUTSTOCKMANGE::OnButton7() 
{
	// TODO: Add your control notification handler code here
	CAnotherView *cview=(CAnotherView *)GetParent();
	cview->ShowBmo(true);
	cview->m_Tab.SetCurSel(0);
    ShowWindows(false);
	m_combox.SetCurSel(0);
}

void COUTSTOCKMANGE::SetListstyle()
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

BOOL COUTSTOCKMANGE::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	SetListstyle();
	SetList2Style();
	ShowWindows(false);
	m_combox.SetCurSel(0);
	Sum("select a.merchandiseid,b.mercname,a.unitprice,a.numbers,b.discount,a.paymoney,a.operid,a.storid ,a.storflag from tb_storage a inner join tb_merchangiseinfo b\
		 on a.merchandiseid=b.id where a.storflag='0' ");
	CTime tm=CTime::GetCurrentTime();
	m_begin=tm;
	m_end=tm;
	m_allmoneyctrl.SetFontSize(16);
	m_allmoneyctrl.SetTextColor(RGB(0,255,0));
	m_allmoneyctrl.SetBkColor(RGB(0,0,0));
	m_allmoneyctrl.SetFontBold(TRUE);
	m_allmoneyctrl.SetText(m_allmoney);
	m_allnumctrl.SetFontSize(16);
	m_allnumctrl.SetTextColor(RGB(0,255,0));
	m_allnumctrl.SetBkColor(RGB(0,0,0));
	m_allnumctrl.SetFontBold(TRUE);
	m_allnumctrl.SetText(m_allnum);
	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void COUTSTOCKMANGE::SetList2Style()
{
	m_list2.InsertColumn(0,"商品编号",LVCFMT_LEFT,80);
	m_list2.InsertColumn(1,"商品名称",LVCFMT_LEFT,120);
	m_list2.InsertColumn(2,"单价",LVCFMT_LEFT,80);
	m_list2.InsertColumn(3,"数量",LVCFMT_LEFT,80);
	m_list2.InsertColumn(4,"折扣",LVCFMT_LEFT,80);
	m_list2.InsertColumn(5,"金额",LVCFMT_LEFT,80);
	m_list2.InsertColumn(6,"操作员",LVCFMT_LEFT,80);
	m_list2.InsertColumn(7,"出库编号",LVCFMT_LEFT,120);
	m_list2.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);

}
void COUTSTOCKMANGE::ShowWindows(bool flag)
{
    m_begintime.ShowWindow(!flag);
	m_endtime.ShowWindow(!flag);
	m_edit.ShowWindow(flag);
	m_static1.ShowWindow(flag);
	m_static2.ShowWindow(!flag);
}

void COUTSTOCKMANGE::OnCloseupCombo1() 
{
	
	// TODO: Add your control notification handler code here
	CString str;
	m_combox.GetLBText(m_combox.GetCurSel(),str);
	if(str=="商品编号汇总")
	{
	  m_static1.SetWindowText("商品编号");
      m_edit1="";
      ShowWindows(true);
	}
	else if(str=="出库编号汇总")
	{
		m_static1.SetWindowText("出库编号");
		m_edit1="";
		ShowWindows(true);
	}
	else
	{ ShowWindows(false);}
    queryflag=true;
}

void COUTSTOCKMANGE::Sum(CString sqlstr)
{
    if(m_record!=NULL)
	{
		m_record=NULL;
	}
	m_record.CreateInstance(__uuidof(Recordset));
	m_record->Open(_bstr_t(sqlstr),theApp.m_connection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	int rows=0;
		m_list.DeleteAllItems();
		if(GetRecordCount(m_record))
		while(!m_record->_EOF)
		{
			for(int i=0;i<8;i++)
			{
				CString temp=(LPCSTR)(_bstr_t)m_record->Fields->GetItem(long(i))->Value;
				if(i==0)
				{
					m_list.InsertItem(rows,temp);
				}
				else
				{
					m_list.SetItemText(rows,i,temp);
				}
			}
			rows++;
			m_record->MoveNext();
		}
}

void COUTSTOCKMANGE::ShowList2(CString sqlstr)
{
	m_record=NULL;
	m_record.CreateInstance(__uuidof(Recordset));
	m_record->Open(_bstr_t(sqlstr),theApp.m_connection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	int rows=0;
	m_list2.DeleteAllItems();
	if(GetRecordCount(m_record))
	{
	while(!m_record->_EOF)
	{
		for(int i=0;i<8;i++)
		{
			CString temp=(LPCSTR)(_bstr_t)m_record->Fields->GetItem(long(i))->Value;
			if(i==0)
			{
				m_list2.InsertItem(rows,temp);
			}
			else
			{
				m_list2.SetItemText(rows,i,temp);
			}
		}
		rows++;
		m_record->MoveNext();
	}
	GetAllNum(sqlstr1);
	GetAllMoney(sqlstr2);
	}
	else
	{
		m_allnum="累计\r\n数量:";
		m_allmoney="累计\r\n金额:";
		
		
		m_allmoneyctrl.SetText(m_allmoney);
		
		m_allnumctrl.SetText(m_allnum);
	}
}

void COUTSTOCKMANGE::GetAllNum(CString sqlstr)
{  
    m_record->Close();
	m_record->Open(_bstr_t(sqlstr),theApp.m_connection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	if(GetRecordCount(m_record))
	{
		CString temp=(LPCSTR)(_bstr_t)m_record->Fields->GetItem("allnum")->Value;
		m_allnum="累计\r\n数量:"+temp;
	}
    m_allnumctrl.SetText(m_allnum);
}

void COUTSTOCKMANGE::GetAllMoney(CString sqlstr)
{
	m_record->Close();
	m_record->Open(_bstr_t(sqlstr),theApp.m_connection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	if(GetRecordCount(m_record))
    {
		CString temp=(LPCSTR)(_bstr_t)m_record->Fields->GetItem("allmoney")->Value;
        
		m_allmoney="累计\r\n金额:"+temp;
	}
		m_allmoneyctrl.SetText(m_allmoney);
}

int COUTSTOCKMANGE::GetRecordCount(_RecordsetPtr ptr)
{
   int count=0;
	if(ptr!=NULL)
	{
		try
		{
		   ptr->MoveFirst();
		}
		catch(...)
		{
			return 0;
		}
		if(ptr->_EOF)return 0;
		while(!ptr->_EOF)
		{
			ptr->MoveNext();
			count++;
		}
	}
	ptr->MoveFirst();
	return count;
}




/////////////////////////////////////////////////////////////////////////////
// COUTSTOCKMANGE message handlers
