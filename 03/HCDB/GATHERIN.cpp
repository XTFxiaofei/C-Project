// GATHERIN.cpp : implementation file
//

#include "stdafx.h"
#include "HCDB.h"
#include "GATHERIN.h"
#include "AnotherView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGATHERIN dialog
extern CHCDBApp theApp;

CGATHERIN::CGATHERIN(CWnd* pParent /*=NULL*/)
	: CDialog(CGATHERIN::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGATHERIN)
	m_provname = _T("");
	m_innumber = _T("");
	m_date = 0;
	m_mercid = _T("");
	m_mercname = _T("");
	m_merctype = _T("");
	m_provid = _T("");
	m_inprice = 0.0;
	m_numbers = 0.0;
	m_uint = _T("");
	m_storinfo = _T("");
	m_operid = _T("");
	m_intype = _T("");
	m_provid1 = _T("");
	//}}AFX_DATA_INIT
	delitem=-1;
}


void CGATHERIN::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGATHERIN)
	DDX_Control(pDX, IDC_EDIT8, m_providctrl);
	DDX_Control(pDX, IDC_EDIT7, m_merctypectrl);
	DDX_Control(pDX, IDC_EDIT3, m_operidctrl);
	DDX_Control(pDX, IDC_COMBO3, m_comuint);
	DDX_Control(pDX, IDC_EDIT9, m_inpricectrl);
	DDX_Control(pDX, IDC_EDIT10, m_numbersctrl);
	DDX_Control(pDX, IDC_EDIT6, m_mercnuamectrl);
	DDX_Control(pDX, IDC_EDIT5, m_mercidctrl);
	DDX_Control(pDX, IDC_STATIC7, m_allmoney);
	DDX_Control(pDX, IDC_COMBOPROVID, m_comprovid);
	DDX_Control(pDX, IDC_COMBOINTYPE, m_comintype);
	DDX_Control(pDX, IDC_LIST2, m_list);
	DDX_Text(pDX, IDC_EDITPROVNAME, m_provname);
	DDX_Text(pDX, IDC_EDIT_INNUMBER, m_innumber);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, m_date);
	DDX_Text(pDX, IDC_EDIT5, m_mercid);
	DDX_Text(pDX, IDC_EDIT6, m_mercname);
	DDX_Text(pDX, IDC_EDIT7, m_merctype);
	DDX_Text(pDX, IDC_EDIT8, m_provid);
	DDX_Text(pDX, IDC_EDIT9, m_inprice);
	DDX_Text(pDX, IDC_EDIT10, m_numbers);
	DDX_CBString(pDX, IDC_COMBO3, m_uint);
	DDX_Text(pDX, IDC_EDIT4, m_storinfo);
	DDX_Text(pDX, IDC_EDIT3, m_operid);
	DDX_CBString(pDX, IDC_COMBOINTYPE, m_intype);
	DDX_CBString(pDX, IDC_COMBOPROVID, m_provid1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGATHERIN, CDialog)
	//{{AFX_MSG_MAP(CGATHERIN)
	ON_BN_CLICKED(IDC_TN_SAVE, OnTnSave)
	ON_BN_CLICKED(IDC_BTN_ADDNEW, OnBtnAddnew)
	ON_BN_CLICKED(IDC_BTN_DEL, OnBtnDel)
	ON_BN_CLICKED(IDC_BTN_OK, OnBtnOk)
	ON_BN_CLICKED(IDC_BTN_CANCEL, OnBtnCancel)
	ON_CBN_CLOSEUP(IDC_COMBOPROVID, OnCloseupComboprovid)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIMEPICKER1, OnDatetimechangeDatetimepicker1)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST2, OnItemchangedList2)
	ON_CBN_EDITCHANGE(IDC_COMBOPROVID, OnEditchangeComboprovid)
	ON_CBN_KILLFOCUS(IDC_COMBOPROVID, OnKillfocusComboprovid)
	ON_EN_KILLFOCUS(IDC_EDIT3, OnKillfocusEdit3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGATHERIN message handlers

BOOL CGATHERIN::OnInitDialog() 
{
	CDialog::OnInitDialog();
	// TODO: Add extra initialization here
	SetListStyle();
	ShowButton(false);
    ShowWindows(false);
	CloseupFlag=false;
    GetProvid();
	CTime tm=CTime::GetCurrentTime();
	SetDate(tm);
	SetInNumber();
	flag=false;
	SetComUint();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

CRect CGATHERIN::ReSetRect(CRect rect)
{ 
   rect.top=rect.top;
   rect.left=rect.left-100;
  
   return rect;
}

void CGATHERIN::OnTnSave() 
{
	if(flag)
	{
		m_recordstore=NULL;
		UpdateData();
		m_recordstore.CreateInstance(__uuidof(Recordset));
		CString sqlstr;
		CString datestr=m_date.Format("%Y-%m-%d");
		
		int j=m_list.GetItemCount();
		if(!SaveMercInfo())
		{	
			ClearAll();
			m_list.DeleteAllItems();
			ShowWindows(false);
			ShowButton(false);
			return;
			
		}
		for(int i=0;i<j;i++)
		{	
			m_mercid=m_list.GetItemText(i,0);
			CString inprice=m_list.GetItemText(i,5);
			CString numbers=m_list.GetItemText(i,7);
			CString paympney=m_list.GetItemText(i,6);
			sqlstr.Format("update tb_storemanage set nowvalues=nowvalues+%s where mercid='%s' and (nowvalues+%s)<uplimit",numbers,m_mercid,numbers);
			_variant_t va;
			theApp.m_connection->Execute(_bstr_t(sqlstr),&va,adModeUnknown);
			if(va.intVal==0)
			{
				CString str;
				str.Format("'%s'数量大于最大库存数!",m_mercid);
				MessageBox(str);
				continue;
			}
		
			try{
			sqlstr.Format("insert into tb_storage (storid,merchandiseid,stordate,stortype,provid,storinfo,operid,storflag,unitprice,numbers,paymoney)\
				values ('%s','%s','%s','%s','%s','%s','%s','1',%s,%s,%s)",m_innumber,m_mercid,m_dateArr.GetAt(i),m_intypeArr.GetAt(i),\
				m_provArr.GetAt(i),m_storinfoArr.GetAt(i),m_operidArr.GetAt(i),inprice,numbers,paympney);
			m_recordstore->Open((_bstr_t)sqlstr,theApp.m_connection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
			MessageBox("保存成功");
			SetInNumber();
			}
			catch(...)
			{
				MessageBox("不能保存");
				return;
			}
		}

	}
	else
	{
		MessageBox("请选择“入库确认  按钮”");
	
	}	
	    flag=false;	
		ShowButton(false);
		ShowWindows(false);
		m_list.DeleteAllItems();
		m_comuint.SetCurSel(0);
		m_provArr.RemoveAll();
		m_innumberArr.RemoveAll();
		m_dateArr.RemoveAll();
		m_merctypeArr.RemoveAll();
		m_storinfoArr.RemoveAll();
		m_operidArr.RemoveAll();
		m_comuint.ResetContent();
		SetComUint();
		m_comuint.SetCurSel(0);
}

void CGATHERIN::OnBtnAddnew() 
{
	// TODO: Add your control notification handler code here
	ShowButton(true);
	ShowWindows(true);
}

void CGATHERIN::OnBtnDel() 
{

	if(delitem>-1)
	{
		int a=MessageBox("确认删除?","系统提示",MB_YESNO|MB_ICONSTOP);
		m_provArr.RemoveAt(delitem);
		m_innumberArr.RemoveAt(delitem);
		m_dateArr.RemoveAt(delitem);
		m_merctypeArr.RemoveAt(delitem);
		m_storinfoArr.RemoveAt(delitem);
		m_operidArr.RemoveAt(delitem);
		if(a==6)
		{
           m_list.DeleteItem(delitem);
		   delitem=-1;
		   GetAllmoney();
		}
		else return;
	}
	else
    MessageBox("请选择商品?");
}

void CGATHERIN::OnBtnOk() 
{
   UpdateData();
   if(m_mercid==""){MessageBox("编号不能为零");return;}
   if(m_inprice==0){MessageBox("进价不能为零");return;}
   if(m_numbers==0){MessageBox("数量不能为零");return;}
   if(MessageBox("确认入库?","系统提示!",MB_OKCANCEL|MB_ICONQUESTION)==1)
   {
	 int i=m_list.GetItemCount();
	 m_list.InsertItem(i,m_mercid);
	 m_list.SetItemText(i,1,m_mercname);
	 m_list.SetItemText(i,2,m_merctype);
	 m_list.SetItemText(i,3,m_provid);
	 CString str;
	 m_list.SetItemText(i,4,m_uint);
	 str.Format("%.2f",m_numbers);
	 m_list.SetItemText(i,5,str);
	 str.Format("%.2f",m_inprice);
	 m_list.SetItemText(i,6,str);
	 float allmoney=m_inprice*m_numbers;
	 str.Format("%.2f",allmoney);
	 m_list.SetItemText(i,7,str);
	 GetAllmoney();
	 ClearAll();
	 ////////////////////**************************///////////////新的数组的使用
	 CString provstr;
	 m_comprovid.GetLBText(m_comprovid.GetCurSel(),provstr);
     m_provArr.Add(provstr);
	 m_innumberArr.Add(m_innumber);
	 CString datearr=m_date.Format("%Y-%m-%d");
	 m_dateArr.Add(datearr);
	 m_merctypeArr.Add(m_merctype);
	 m_storinfoArr.Add(m_storinfo);
	 m_operidArr.Add(m_operid);
     m_intypeArr.Add(m_intype);
	 flag=true;
     return ;
   }
   else return;

   
}

void CGATHERIN::OnBtnCancel() 
{
	// TODO: Add your control notification handler code here

	CAnotherView *cview=(CAnotherView *)GetParent();
	cview->ShowBmo(true);
	cview->m_Tab.SetCurSel(0);
	ClearAll();
	ShowWindows(false);
}

void CGATHERIN::SetListStyle()
{
    m_list.InsertColumn(0,"商品编号",LVCFMT_LEFT,80);
	m_list.InsertColumn(1,"商品名称",LVCFMT_LEFT,80);
	m_list.InsertColumn(2,"型号规格",LVCFMT_LEFT,80);
	m_list.InsertColumn(3,"供应商",LVCFMT_LEFT,80);
	m_list.InsertColumn(4,"单位",LVCFMT_LEFT,80);
	m_list.InsertColumn(5,"数量",LVCFMT_LEFT,80);
	m_list.InsertColumn(6," 进价",LVCFMT_LEFT,80);
	m_list.InsertColumn(7,"合计",LVCFMT_LEFT,80);
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|SWP_DRAWFRAME);
	m_comintype.SetCurSel(0);

}

void CGATHERIN::GetProvid()
{
	UpdateData();
    CString sqlstr;
	m_comprovid.ResetContent();
	sqlstr="select * from tb_provider";
	//m_recordprovid=NULL;
	m_recordprovid.CreateInstance(__uuidof(Recordset));
	m_recordprovid=theApp.m_connection->Execute(_bstr_t(sqlstr),NULL,adModeUnknown);
	int i=0;
	CString strgetprovid;
	while(!m_recordprovid->_EOF)
	{   
		strgetprovid=(LPCSTR)(_bstr_t)m_recordprovid->Fields->GetItem("provid")->Value;
        m_comprovid.InsertString(i,strgetprovid);
		m_recordprovid->MoveNext();
	}
	m_comprovid.SetCurSel(0);
	int k=m_comprovid.GetCurSel();
	CString tempstr;
	m_comprovid.GetLBText(k,tempstr);
	sqlstr.Format("select * from tb_provider where provid='%s'",tempstr);
    m_provname=GetProvname(sqlstr);
	m_provid1=tempstr;
	UpdateData(false);
}

CString CGATHERIN::GetProvname(CString sqlstr)
{ 
	CString strgetprovname;
  	m_recordprovid=NULL;
	m_recordprovid.CreateInstance(__uuidof(Recordset));
	m_recordprovid->Open((_variant_t )sqlstr,theApp.m_connection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	if(!m_recordprovid->_EOF)
	{
      strgetprovname=(LPCSTR)(_bstr_t)m_recordprovid->Fields->GetItem("provname")->Value;
	}
	UpdateData(false);
	UpdateData(false);
	m_provname=strgetprovname;
	return strgetprovname;
}

void CGATHERIN::OnCloseupComboprovid() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	CString sqlstr;
  	UpdateData();
    int k=m_comprovid.GetCurSel();
	CString tempstr;
	m_comprovid.GetLBText(k,tempstr);
	sqlstr.Format("select * from tb_provider where provid='%s'",tempstr);
	GetProvname(sqlstr);
	m_provid1=tempstr;
	CloseupFlag=true;
	UpdateData(false);
}

//DEL void CGATHERIN::OnEditchangeComboprovid() 
//DEL {
//DEL 	// TODO: Add your control notification handler code here
//DEL 	UpdateData();
//DEL 	CString sqlstr;
//DEL 	sqlstr.Format("select * from tb_provider where provid='%s'",m_provid);
//DEL 	//m_comprovid.InsertString(m_comprovid.GetCount(),m_provid);
//DEL 	m_provid=m_provid;
//DEL     m_provname=GetProvname(sqlstr);
//DEL 	CloseupFlag=false;
//DEL 	//UpdateData(false);
//DEL }



void CGATHERIN::SetInNumber()
{
   
   m_innumber=GetStroId();
   UpdateData(false);
   return;
}

void CGATHERIN::SetDate(CTime tm)
{
   m_date=tm;
   UpdateData(false);
}


CString CGATHERIN::GetStroId()
{ 
  UpdateData();
  m_recordstorid=NULL;
  m_recordstorid.CreateInstance(__uuidof(Recordset));
  CString sqlstr;
  CString str=m_date.Format("%Y-%m-%d");
  sqlstr.Format("select *from tb_storage where stordate='%s' and storflag='1'",str);
  m_recordstorid->Open((_variant_t )sqlstr,theApp.m_connection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
  if(GetRecordCount(m_recordstorid))
  {
	  m_recordstorid->Close();
	  sqlstr.Format("select Max(storid) as maxstorid from tb_storage where stordate='%s'",str);
	  m_recordstorid->Open((_variant_t )sqlstr,theApp.m_connection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	  if(GetRecordCount(m_recordstorid))
	  {
		  str=(LPCSTR)(_bstr_t)m_recordstorid->Fields->GetItem("maxstorid")->Value;
		  CString str1,str2;
		  str1=str.Mid(0,8);
		  str2=str.Mid(8);
		  str2.TrimRight();
		  int num=atoi(str2);
		  num+=1;
		  CString str3;
		  str3.Format("%d",num);
		  for(int j=0;j<str3.GetLength();j++)
		  {
			  str2.SetAt(str2.GetLength()-str3.GetLength(),str3.GetAt(j));
		  }
		  str=str1+str2;
	  }
  }
  else
  {
	  str=str.Mid(0,4)+str.Mid(5,2)+str.Mid(8,2)+"000001";
  }
  
  return str;
}



void CGATHERIN::OnDatetimechangeDatetimepicker1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	SetInNumber();
	*pResult = 0;
}

int CGATHERIN::GetRecordCount(_RecordsetPtr ptr)
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

void CGATHERIN::ShowButton(bool flag)
{
   	GetDlgItem(IDC_TN_SAVE)->EnableWindow(flag);
	GetDlgItem(IDC_BTN_OK)->EnableWindow(flag);
}

void CGATHERIN::ShowWindows(bool flag)
{
	int i=0; 
	m_allmoney.SetFontSize(20);
	m_allmoney.SetTextColor(RGB(0,255,0));
	m_allmoney.SetBkColor(RGB(0,0,0));
	m_allmoney.SetText("累计\r\n金额：");	
	GetDlgItem(IDC_STATIC1)->ShowWindow(flag);
	GetDlgItem(IDC_STATIC2)->ShowWindow(flag);
	GetDlgItem(IDC_STATIC3)->ShowWindow(flag);
	GetDlgItem(IDC_STATIC4)->ShowWindow(flag);
	GetDlgItem(IDC_STATIC5)->ShowWindow(flag);
	GetDlgItem(IDC_STATIC6)->ShowWindow(flag);
	GetDlgItem(IDC_STATIC7)->ShowWindow(flag);
	GetDlgItem(IDC_STATIC8)->ShowWindow(flag);
	GetDlgItem(IDC_STATIC9)->ShowWindow(flag);
	GetDlgItem(IDC_STATIC10)->ShowWindow(flag);
	GetDlgItem(IDC_EDIT5)->ShowWindow(flag);
	GetDlgItem(IDC_EDIT6)->ShowWindow(flag);
	GetDlgItem(IDC_EDIT7)->ShowWindow(flag);
	GetDlgItem(IDC_EDIT8)->ShowWindow(flag);
	GetDlgItem(IDC_EDIT9)->ShowWindow(flag);
	GetDlgItem(IDC_EDIT10)->ShowWindow(flag);
	GetDlgItem(IDC_COMBO3)->ShowWindow(flag);	
}

BOOL CGATHERIN::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if   (pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_RETURN) //截取回车键   
	{
		if(::GetFocus()==m_providctrl)
		{
			UpdateData();
            CString sqlstr;
			sqlstr.Format("select * from tb_provider where provid='%s'",m_provid);
			m_recordprovid=NULL;
			m_recordprovid.CreateInstance(__uuidof(Recordset));
			try
			{
				m_recordprovid->Open((_variant_t )sqlstr,theApp.m_connection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
				if(!m_recordprovid->_EOF)
				{
					MessageBox("已有该用户");
					return true;
				}
				else
				{
					MessageBox("不存在该用户");
					return false;
				}
				UpdateData(false);
			}
			catch(...)
			{
				return true;
			}
		}
		if(::GetFocus()==m_numbersctrl)
		{
			UpdateData();
			if(m_inprice==0)
			{
				MessageBox("请输入进价!","系统提示",MB_ICONSTOP|MB_OK);
				::SetFocus(m_numbersctrl.m_hWnd);
                return false;
			}
            if(m_numbers==0)
			{
				MessageBox("请输入数量!","系统提示",MB_ICONSTOP|MB_OK);
				::SetFocus(m_inpricectrl.m_hWnd);
                return false;
			}
			else
			{
			   return true;
			}
		}
		else return false;
	}
	return CDialog::PreTranslateMessage(pMsg);
}

double CGATHERIN::GetAllmoney()
{
   int i=m_list.GetItemCount();
   CString strnum,strprice;
   float allmoney=0;
   for(int j=0;j<i;j++)
   {
     strnum=m_list.GetItemText(j,5);
	 strprice=m_list.GetItemText(j,6);
	 allmoney+=atof(strnum)*atof(strprice);
   }
   CString str;
   str.Format("累计\r\n金额：%.2f",allmoney);
   m_allmoney.SetText(str);
   return allmoney;
}

void CGATHERIN::SetComUint()
{
	m_recordmercinfo=NULL;
	m_recordmercinfo.CreateInstance(__uuidof(Recordset));
	CString sqlstr,str;int i=0;
	sqlstr.Format("select distinct mercunit from tb_merchangiseinfo");
	try
	{
	 m_recordmercinfo->Open((_variant_t )sqlstr,theApp.m_connection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	 while(!m_recordmercinfo->_EOF)
	 {
		 
		 str=(LPCSTR)(_bstr_t)m_recordmercinfo->Fields->GetItem("mercunit")->Value;
		 m_comuint.InsertString(i,str);
		 i++;
         m_recordmercinfo->MoveNext();
	 }
	 m_comuint.SetCurSel(0);
	}
	catch(...)
	{
		return;
	}
}

void CGATHERIN::ClearAll()
{  
	m_mercid="";
    m_mercname="";
	m_merctype="";
	m_provid="";
	m_inprice=0;
	m_numbers=0;
	m_comuint.ResetContent();
	SetComUint();
	m_comuint.SetCurSel(0);
	UpdateData(false);
}



void CGATHERIN::OnItemchangedList2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
    delitem=pNMListView->iItem;	
	*pResult = 0;
}

bool CGATHERIN::SaveMercInfo()
{
	int j=m_list.GetItemCount();

	CString sqlstr;
	for(int i=0;i<j;i++)
	{	
		m_recordmercinfo=NULL;
	    m_recordmercinfo.CreateInstance(__uuidof(Recordset));
		m_mercid=m_list.GetItemText(i,0);
		m_mercname=m_list.GetItemText(i,1);
		CString uint=m_list.GetItemText(i,4);
		CString inprice=m_list.GetItemText(i,5);
		float outprice=atof(inprice)*1.10;
		CString numbers=m_list.GetItemText(i,6);
		sqlstr.Format("select * from tb_merchangiseinfo where id='%s'",m_mercid);
		m_recordmercinfo->Open((_bstr_t)sqlstr,theApp.m_connection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
		if(m_recordmercinfo->_EOF)
        {
			try{
				m_recordmercinfo->Close();
				sqlstr.Format("insert into tb_merchangiseinfo values('%s','%s','%s','%s','%s',%s,%s,'%s',1)",\
					m_mercid,m_mercname,m_merctypeArr.GetAt(i),uint,inprice,outprice,m_provArr.GetAt(i));
				m_recordmercinfo->Open((_bstr_t)sqlstr,theApp.m_connection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
			}
			catch(...)
			{
				MessageBox("商品信息不正确!");
				return false;
			}
		}
	  	
	}
    return true;
}

void CGATHERIN::OnEditchangeComboprovid() 
{
	// TODO: Add your control notification handler code here

}
CString m_extermprovid;
void CGATHERIN::OnKillfocusComboprovid() 
{
	if(!m_recordprovid->_EOF)
		m_recordprovid->Close();
	UpdateData();
	CString sqlstr;
	if(m_provid1!="")
	{   this;
		sqlstr.Format("select * from tb_provider where provid='%s'",m_provid1);
		m_recordprovid=theApp.m_connection->Execute(_bstr_t(sqlstr),NULL,adModeUnknown);
		if(m_recordprovid->_EOF)
		{
			if(MessageBox("不存在该供应商!是否添加 ?","系统提示",MB_YESNO|MB_ICONSTOP)==6)
			{
				m_extermprovid=m_provid1;
				dlg.flag=true;
				if(dlg.DoModal()==IDOK)
				{
					m_provname=GetProvname(sqlstr);
					GetProvid();
					m_operidctrl.SetFocus();
					UpdateData(false);
				}	
				else
				{
				
					m_providctrl.SetFocus();
					UpdateData(false);
				}
			}
		
		}
		else
		{
			m_provname=GetProvname(sqlstr);
			UpdateData(false);
		}
	}	
}

void CGATHERIN::OnKillfocusEdit3() 
{
	// TODO: Add your control notification handler code here
	if(m_recordprovid!=NULL)
		m_recordprovid=NULL;
	UpdateData();
	m_recordprovid.CreateInstance(__uuidof(Recordset));
	CString sqlstr;
	if(m_operid!="")
	{
		sqlstr.Format("select * from tb_operator where operid='%s'",m_operid);
		m_recordprovid=theApp.m_connection->Execute(_bstr_t(sqlstr),NULL,adModeUnknown);
		if(m_recordprovid->_EOF)
		{
			MessageBox("不存在该操作员!","系统提示",MB_OK|MB_ICONSTOP);
			m_operid="";
			UpdateData(false);
			::SetFocus(GetDlgItem(IDC_EDIT3)->m_hWnd);
			return ;
		}
	}
	else
	{
            MessageBox("请填写操作人","系统提示");
			return;
	}
}
