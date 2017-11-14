// SALESQUITDLG.cpp : implementation file
//

#include "stdafx.h"
#include "HCDB.h"
#include "SALESQUITDLG.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSALESQUITDLG dialog

extern CHCDBApp theApp;
CSALESQUITDLG::CSALESQUITDLG(CWnd* pParent /*=NULL*/)
	: CDialog(CSALESQUITDLG::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSALESQUITDLG)
	m_operid = _T("");
	m_info = _T("");
	m_buyid = _T("");
	m_mercid = _T("");
	m_quitnum = 0.0f;
	m_backmoney = 0.0;
	//}}AFX_DATA_INIT
	m_index=-1;
	m_index3=-1;
}


void CSALESQUITDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSALESQUITDLG)
	DDX_Control(pDX, ID_QUITNUM, m_quit);
	DDX_Control(pDX, ID_LIST3, m_list3);
	DDX_Control(pDX, ID_LIST2, m_list2);
	DDX_Control(pDX, ID_LIST1, m_list1);
	DDX_Text(pDX, ID_OPERID, m_operid);
	DDX_Text(pDX, ID_INFO, m_info);
	DDX_Text(pDX, ID_BUYID, m_buyid);
	DDX_Text(pDX, ID_MERCID, m_mercid);
	DDX_Text(pDX, ID_QUITNUM, m_quitnum);
	DDX_Text(pDX, ID_BACKMONEY, m_backmoney);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSALESQUITDLG, CDialog)
	//{{AFX_MSG_MAP(CSALESQUITDLG)
	ON_NOTIFY(LVN_ITEMCHANGED, ID_LIST1, OnItemchangedList1)
	ON_BN_CLICKED(IDC_find, Onfind)
	ON_BN_CLICKED(IDC_INVALIDATE, OnInvalidate)
	ON_NOTIFY(LVN_ITEMCHANGED, ID_LIST2, OnItemchangedList2)
	ON_BN_CLICKED(ID_TSPRD, OnTsprd)
	ON_BN_CLICKED(ID_TSPCD, OnTspcd)
	ON_NOTIFY(LVN_ITEMCHANGED, ID_LIST3, OnItemchangedList3)
	ON_BN_CLICKED(ID_OK, OnOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSALESQUITDLG message handlers

BOOL CSALESQUITDLG::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	SetListStyle();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSALESQUITDLG::SetListStyle()
{
    m_list1.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list1.InsertColumn(0,"销售单号",LVCFMT_CENTER,140);
	m_list1.InsertColumn(1,"操作员",LVCFMT_CENTER,140);
	m_list1.InsertColumn(2,"数量",LVCFMT_CENTER,140);
	m_list1.InsertColumn(3,"备注",LVCFMT_CENTER,140);
   
	
	m_list2.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list2.InsertColumn(0,"销售单号",LVCFMT_CENTER,80);
	m_list2.InsertColumn(1,"商品编号",LVCFMT_CENTER,140);
	m_list2.InsertColumn(2,"操作员",LVCFMT_CENTER,80);
	m_list2.InsertColumn(3,"数量",LVCFMT_CENTER,80);
    m_list2.InsertColumn(4,"备注",LVCFMT_CENTER,140);

	m_list3.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list3.InsertColumn(0,"销售单号",LVCFMT_CENTER,80);
	m_list3.InsertColumn(1,"商品编号",LVCFMT_CENTER,80);
	m_list3.InsertColumn(2,"商品名称",LVCFMT_CENTER,120);
	m_list3.InsertColumn(3,"规格",LVCFMT_CENTER,80);
    m_list3.InsertColumn(4,"单位",LVCFMT_CENTER,80);
	m_list3.InsertColumn(5,"供应商编号",LVCFMT_CENTER,80);
	m_list3.InsertColumn(6,"退价",LVCFMT_CENTER,80);
	m_list3.InsertColumn(7,"数量",LVCFMT_CENTER,80);
	m_list3.InsertColumn(8,"小计",LVCFMT_CENTER,140);
	CString sqlstr="select  buyid,operid,buycount,quitinfo from  tb_sale";
	SetList1Values(sqlstr);
}

int CSALESQUITDLG::GetRecord(CString sqlstr)
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
void CSALESQUITDLG::SetList1Values(CString sqlstr)
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
void CSALESQUITDLG::SetList2Values(CString sqlstr)
{
	GetRecord(sqlstr);
	m_list2.DeleteAllItems();
	int rows=0;
	try
	{
		while(!m_record->_EOF)
		{
		 for(int i=0;i<5;i++)
			{
				CString str;
				str=(LPCSTR)(_bstr_t)m_record->Fields->GetItem(long(i))->Value;
				if(i==0)m_list2.InsertItem(rows,str);
				else
				m_list2.SetItemText(rows,i,str);
			}
		 m_record->MoveNext();
		}
	  
		 UpdateData(false);
	}
	catch(...)
	{ 
		AfxMessageBox("没有找到该纪录!");
	}
}

void CSALESQUITDLG::OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	CString str=m_list1.GetItemText(pNMListView->iItem,0);
	CString sqlstr;
	sqlstr.Format("select buyid,mercid,operid,buycount,quitinfo from tb_sale where buyid='%s'",str);
	m_buyid=str;
	m_mercid=m_list1.GetItemText(pNMListView->iItem,1);
	m_info=m_list1.GetItemText(pNMListView->iItem,3);
	UpdateData(false);
	SetList2Values(sqlstr);
	
	*pResult = 0;
}

void CSALESQUITDLG::SetEditValues()
{
   
}

void CSALESQUITDLG::Onfind() 
{
   UpdateData();
   CString sqlstr;
   sqlstr.Format("select buyid,mercid,operid,buycount,quitinfo from tb_sale where buyid='%s'",m_buyid);
   SetList2Values(sqlstr);
}

void CSALESQUITDLG::OnInvalidate() 
{
	// TODO: Add your control notification handler code here
	m_list2.DeleteAllItems();
	m_buyid="";
	m_info="";
	m_operid="";
	m_list3.DeleteAllItems();
	CString sqlstr="select  buyid,operid,buycount,quitinfo from  tb_sale";
	SetList1Values(sqlstr);
	UpdateData(false);
}
void CSALESQUITDLG::SetList3Values(CString sqlstr)
{

	GetRecord1(sqlstr);
	CString str,str1;
	str=(LPCSTR)(_bstr_t)m_record->Fields->GetItem(long(7))->Value;
	str1=(LPCSTR)(_bstr_t)m_record->Fields->GetItem(long(8))->Value;
	str.TrimLeft();
	str.TrimRight();
	if(str=="该商品已退货"&&atof(str1)<0.001)
	{
	  MessageBox("该商品已全部退完!");
	  return;
	}
	
	int rows=m_list3.GetItemCount();
	try
	{
		 for(int i=0;i<7;i++)
			{
 		      str=(LPCSTR)(_bstr_t)m_record->Fields->GetItem(long(i))->Value;
				if(i==0)m_list3.InsertItem(rows,str);
				else
				m_list3.SetItemText(rows,i,str);
			}
		 m_mercid=(LPCSTR)(_bstr_t)m_record->Fields->GetItem(long(1))->Value;
		 UpdateData(false);
	}
	catch(...)
	{ 
		AfxMessageBox("没有找到该纪录!");
	}
}

void CSALESQUITDLG::OnItemchangedList2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	m_index=pNMListView ->iItem;
	*pResult = 0;
}

void CSALESQUITDLG::OnTsprd() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	if(m_index==-1)
	{
		MessageBox("当前无商品可退 ！");
		return;
	}
    else
	{
		CString str=m_list2.GetItemText(m_index,0);
	    CString str1=m_list2.GetItemText(m_index,1);
		CString sqlstr;
		sqlstr.Format("select a.buyid,b.id,b.mercname,b.spec,b.mercunit,b.provid,b.outprice, quitinfo ,a.buycount\
			 from tb_sale a inner join tb_merchangiseinfo b on a.mercid=b.id where a.buyid='%s' and b.id='%s'",str,str1);
        SetList3Values(sqlstr);
		m_index=-1;
	}
	UpdateData(false);
}
int CSALESQUITDLG::GetRecord1(CString sqlstr)
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

BOOL CSALESQUITDLG::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if   (pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_RETURN) //截取回车键   
	{
		if(::GetFocus()==m_quit)
		{
			UpdateData();
			if(m_quitnum==0)
			{
              	MessageBox("请填写退货数量");
				return false;
			}
			CString sqlstr,str1,str2;
			str1=m_list3.GetItemText(m_list3.GetItemCount()-1,0);
			str2=m_list3.GetItemText(m_list3.GetItemCount()-1,1);
			/*sqlstr.Format("Select sum(buycount) as a from tb_sale where buyid='%s' and mercid='%s'",str1,str2);
			GetRecord1(sqlstr);
			str1=(LPCSTR)(_bstr_t)m_record->Fields->GetItem("a")->Value;
			if(atof(str1)<m_quitnum)
			{
				MessageBox("退货数超过购买数");
                m_quitnum=0;
				UpdateData(false);
				return false;
			}*/
			sqlstr.Format("select sum(buycount)-sum(quitnum) as a from tb_sale where buyid='%s' and mercid='%s' ",str1,str2,m_quitnum);
			GetRecord(sqlstr);
			str1=(LPCSTR)(_bstr_t)m_record->Fields->GetItem("a")->Value;
            if(atof(str1)<m_quitnum)
			{
				MessageBox("退货数超过购买数");
                m_quitnum=0;
				UpdateData(false);
				return false;
			}

			int i=m_list3.GetItemCount();
			CString str;
			str.Format("%.2f",m_quitnum);
			m_list3.SetItemText(i-1,7,str);
			str=m_list3.GetItemText(i-1,6);
			float all=atof(str)*m_quitnum;
			str.Format("%.2f",all);
			m_list3.SetItemText(i-1,8,str);
			float backmoney=0;
			for(int j=0;j<i;j++)
			{
				CString str1=m_list3.GetItemText(j,8);
				backmoney+=atof(str);
			}
			m_backmoney=(double)backmoney;
			UpdateData(false);
			return false;
		}
		else return false;
	}
	return CDialog::PreTranslateMessage(pMsg);
}

void CSALESQUITDLG::OnTspcd() 
{
   	if(m_index3==-1)
	{
			MessageBox("请选择要出单的商品!");
	}
	else
	{
		m_list3.DeleteItem(m_index3);
		m_index3=-1;
	}
}

void CSALESQUITDLG::OnItemchangedList3(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	m_index3=pNMListView->iItem;
	*pResult = 0;
}

void CSALESQUITDLG::OnOk() 
{
	if(MessageBox("确定退货?","系统提示",MB_YESNO|MB_ICONSTOP)==6)
	{
      int i=m_list3.GetItemCount();
	  CString sqlstr1,sqlstr,sqlstr2,sqlstr3;
	  sqlstr1="update tb_sale set quitinfo='该商品已退货%s'  where buyid='%s'";
	  sqlstr2="update tb_sale set quitnum=%s  where buyid='%s'";
      for(int j=0;j<i;j++)
	  {
		  CString str;
		  str=m_list3.GetItemText(j,0);
          sqlstr.Format(sqlstr1,m_list3.GetItemText(j,7),str);
          sqlstr1=sqlstr+" and mercid='%s'";
		  str=m_list3.GetItemText(j,1);
		  sqlstr.Format(sqlstr1,str);
		  str=m_list3.GetItemText(j,7); 
		  UpdateRecord(sqlstr,str);
          sqlstr3.Format(sqlstr2,m_list3.GetItemText(j,7),str=m_list3.GetItemText(j,0));
		  sqlstr2=sqlstr3+" and mercid='%s'";
          sqlstr3.Format(sqlstr2,m_list3.GetItemText(j,1));
          Update(sqlstr3);
	  }
	  MessageBox("退货成功!");
	}
}

void CSALESQUITDLG::UpdateRecord(CString sqlstr,CString str)
{
	m_record=NULL;
	m_record.CreateInstance(__uuidof(Recordset));
	try
	{
		m_record->Open((_variant_t )sqlstr,theApp.m_connection.GetInterfacePtr(),
		adOpenDynamic,adLockOptimistic,adCmdText);		
	}
    catch(...)
	{
		MessageBox("error");
	}
}

void CSALESQUITDLG::Update(CString sqlstr)
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
}
