// GATHEROUT.cpp : implementation file
//

#include "stdafx.h"
#include "HCDB.h"
#include "GATHEROUT.h"
#include "AnotherView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGATHEROUT dialog
extern CHCDBApp theApp;

CGATHEROUT::CGATHEROUT(CWnd* pParent /*=NULL*/)
	: CDialog(CGATHEROUT::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGATHEROUT)
	m_mercid = _T("");
	m_mercname = _T("");
	m_outprice = _T("");
	m_merctype = _T("");
	m_provid = _T("");
	m_uint = _T("");
	m_outnumberid = _T("");
	m_date = 0;
	m_provname = _T("");
	m_operid = _T("");
	m_provid1 = _T("");
	m_numbers = 0.0f;
	m_storinfo = _T("");
	m_intype = _T("");
	//}}AFX_DATA_INIT
	enterflag=false;
	delitem=-1;
}


void CGATHEROUT::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGATHEROUT)
	DDX_Control(pDX, IDC_EDIT3, m_operidctrl);
	DDX_Control(pDX, IDC_STATIC7, m_allmoney);
	DDX_Control(pDX, IDC_LIST2, m_list);
	DDX_Control(pDX, IDC_COMBOPROVID, m_comprovid);
	DDX_Control(pDX, IDC_COMBOINTYPE, m_comtype);
	DDX_Control(pDX, IDC_EDIT5, m_mercidctrl);
	DDX_Text(pDX, IDC_EDIT5, m_mercid);
	DDX_Text(pDX, IDC_EDIT6, m_mercname);
	DDX_Text(pDX, IDC_EDIT9, m_outprice);
	DDX_Text(pDX, IDC_EDIT7, m_merctype);
	DDX_Text(pDX, IDC_EDIT8, m_provid);
	DDX_Text(pDX, IDC_EDIT11, m_uint);
	DDX_Text(pDX, IDC_EDIT_INNUMBER, m_outnumberid);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, m_date);
	DDX_Text(pDX, IDC_EDITPROVNAME, m_provname);
	DDX_Text(pDX, IDC_EDIT3, m_operid);
	DDX_CBString(pDX, IDC_COMBOPROVID, m_provid1);
	DDX_Text(pDX, IDC_EDIT10, m_numbers);
	DDX_Text(pDX, IDC_EDIT4, m_storinfo);
	DDX_CBString(pDX, IDC_COMBOINTYPE, m_intype);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGATHEROUT, CDialog)
	//{{AFX_MSG_MAP(CGATHEROUT)
	ON_EN_KILLFOCUS(IDC_EDIT5, OnKillfocusEdit5)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIMEPICKER1, OnDatetimechangeDatetimepicker1)
	ON_CBN_CLOSEUP(IDC_COMBOPROVID, OnCloseupComboprovid)
	ON_EN_KILLFOCUS(IDC_EDIT3, OnKillfocusEdit3)
	ON_BN_CLICKED(IDC_BTN_ADDNEW, OnBtnAddnew)
	ON_BN_CLICKED(IDC_BTN_OK, OnBtnOk)
	ON_BN_CLICKED(IDC_TN_SAVE, OnTnSave)
	ON_BN_CLICKED(IDC_BTN_DEL, OnBtnDel)
	ON_BN_CLICKED(IDC_BTN_CANCEL, OnBtnCancel)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST2, OnItemchangedList2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGATHEROUT message handlers

BOOL CGATHEROUT::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	this;
	CTime tm=CTime::GetCurrentTime();
	m_date=tm;
	UpdateData(false);
	SetInNumber();
	GetProvid();
	m_comtype.SetCurSel(0);
	CloseupFlag=false;
	SetListStyle();
	ShowButton(false);
    ShowWindows(false);
	UpdateData(false);
	m_comtype.SetCurSel(0);
	flag=false;
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CGATHEROUT::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if   (pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_RETURN) //截取回车键   
	{
		if(::GetFocus()==m_mercidctrl.m_list)
		{
          m_mercidctrl.m_list.ShowWindow(false);
		  return false;
		}
		else if(::GetFocus()==m_mercidctrl)
		{
			if(m_mercidctrl.m_list.GetItemCount()==0)
			{
				m_mercidctrl.m_list.ShowWindow(false);	
				m_mercid="";
				UpdateData(false);
				MessageBox("没有该商品!");
				enterflag=true;
				return false;
			}
		}
		
	}
	else return false;
	//return CDialog::PreTranslateMessage(pMsg);
}

void CGATHEROUT::OnKillfocusEdit5() 
{
	if(enterflag)
	{
		if(m_mercidctrl.oncharflag)
		{
			if(m_mercidctrl.m_list.GetItemCount()==0)
			{
				MessageBox("没有记录？");
			}
			else
			{
				//m_mercidctrl.m_list.ShowWindow(true);
			}
		}
	}
    enterflag=true;
}

void CGATHEROUT::SetInNumber()
{
   m_outnumberid=GetStroid();
   UpdateData(false);
   return;
}

CString CGATHEROUT::GetStroid()
{
	UpdateData();
	m_record=NULL;
	m_record.CreateInstance(__uuidof(Recordset));
	CString sqlstr;
	CString str=m_date.Format("%Y-%m-%d");
	sqlstr.Format("select * from tb_storage where stordate='%s' and storflag='0'",str);
	m_record->Open((_variant_t )sqlstr,theApp.m_connection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	if(!m_record->_EOF)
	{
		m_record->Close();
		sqlstr.Format("select Max(storid) as maxstorid from tb_storage where stordate='%s' and storflag='0'",str);
		m_record->Open((_variant_t )sqlstr,theApp.m_connection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
		if(!m_record->_EOF)
		{
			str=(LPCSTR)(_bstr_t)m_record->Fields->GetItem("maxstorid")->Value;
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



void CGATHEROUT::OnDatetimechangeDatetimepicker1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	SetInNumber();
	*pResult = 0;
}

CString CGATHEROUT::GetProvname(CString sqlstr)
{
  
	CString strgetprovname;
  	m_record->Close();
	m_record->Open((_variant_t )sqlstr,theApp.m_connection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	if(!m_record->_EOF)
	{
      strgetprovname=(LPCSTR)(_bstr_t)m_record->Fields->GetItem("provname")->Value;
	}
	UpdateData(false);
	return strgetprovname;
}

void CGATHEROUT::GetProvid()
{
	UpdateData();
    CString sqlstr;
	sqlstr="select * from tb_provider";
	//m_recordprovid=NULL;
	m_record->Close();
	m_record=theApp.m_connection->Execute(_bstr_t(sqlstr),NULL,adModeUnknown);
	int i=0;
	CString strgetprovid;
	while(!m_record->_EOF)
	{   
		strgetprovid=(LPCSTR)(_bstr_t)m_record->Fields->GetItem("provid")->Value;
        m_comprovid.InsertString(i,strgetprovid);
		m_record->MoveNext();
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

void CGATHEROUT::OnCloseupComboprovid() 
{
	// TODO: Add your control notification handler code here
   UpdateData();
	CString sqlstr;
  	UpdateData();
    int k=m_comprovid.GetCurSel();
	CString tempstr;
	m_comprovid.GetLBText(k,tempstr);
	sqlstr.Format("select * from tb_provider where provid='%s'",tempstr);
    m_provname=GetProvname(sqlstr);
	CloseupFlag=true;
	UpdateData(false);
}

void CGATHEROUT::OnKillfocusEdit3() 
{
	// TODO: Add your control notification handler code here
	m_record=NULL;
    m_record.CreateInstance(__uuidof(Recordset));
	UpdateData();
	CString sqlstr;
	if(m_operid!="")
	{
		sqlstr.Format("select * from tb_operator where operid='%s'",m_operid);
		m_record=theApp.m_connection->Execute(_bstr_t(sqlstr),NULL,adModeUnknown);
		if(m_record->_EOF)
		{
			MessageBox("不存在该操作员!","系统提示",MB_OK|MB_ICONSTOP);
			m_operid="";
			UpdateData(false);
			::SetFocus(GetDlgItem(IDC_EDIT3)->m_hWnd);
			return ;
		}
	}
}



void CGATHEROUT::SetListStyle()
{
  
    m_list.InsertColumn(0,"商品编号",LVCFMT_LEFT,80);
	m_list.InsertColumn(1,"商品名称",LVCFMT_LEFT,80);
	m_list.InsertColumn(2,"型号规格",LVCFMT_LEFT,80);
	m_list.InsertColumn(3,"供应商",LVCFMT_LEFT,80);
	m_list.InsertColumn(4,"单位",LVCFMT_LEFT,80);
	m_list.InsertColumn(5,"数量",LVCFMT_LEFT,80);
	m_list.InsertColumn(6,"出价",LVCFMT_LEFT,80);
	m_list.InsertColumn(7,"合计",LVCFMT_LEFT,80);
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|SWP_DRAWFRAME);
}

void CGATHEROUT::ShowButton(bool flag)
{
	m_comtype.SetCurSel(0);
	GetDlgItem(IDC_TN_SAVE)->EnableWindow(flag);
	GetDlgItem(IDC_BTN_OK)->EnableWindow(flag);
}

void CGATHEROUT::ShowWindows(bool flag)
{
	m_comtype.SetCurSel(0);
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
	GetDlgItem(IDC_EDIT11)->ShowWindow(flag);
}

void CGATHEROUT::OnBtnAddnew() 
{
	// TODO: Add your control notification handler code here
	ShowButton(true);
	ShowWindows(true);
}

void CGATHEROUT::OnBtnOk() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	if(m_mercid==""){MessageBox("编号不能为零");return;}
	if(m_outprice==""){MessageBox("进价不能为零");return;}
	if(m_numbers==0){MessageBox("数量不能为零");return;}
   if(MessageBox("确认出库?","系统提示!",MB_OKCANCEL|MB_ICONQUESTION)==1)
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
	
	 m_list.SetItemText(i,6,m_outprice);
	 float allmoney=atof(m_outprice)*m_numbers;
	 str.Format("%.2f",allmoney);
	 m_list.SetItemText(i,7,str);
	 GetAllmoney();
	 ClearAll();
	 ////////////////////**************************///////////////新的数组的使用
	 CString provstr;
	 m_comprovid.GetLBText(m_comprovid.GetCurSel(),provstr);
     m_provArr.Add(provstr);
	 m_innumberArr.Add(m_outnumberid);
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

void CGATHEROUT::ClearAll()
{
	m_comtype.SetCurSel(0);
  	m_mercid="";
    m_mercname="";
	m_merctype="";
	m_provid="";
	m_outprice="";
	m_numbers=0;
	UpdateData(false);
}

float CGATHEROUT::GetAllmoney()
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

void CGATHEROUT::OnTnSave() 
{
	// TODO: Add your control notification handler code here
	if(flag)
	{
		if(m_record!=NULL)
			m_record=NULL;
		m_record.CreateInstance(__uuidof(Recordset));
		CString datestr=m_date.Format("%Y-%m-%d");
		CString sqlstr;
		int j=m_list.GetItemCount();
		
		for(int i=0;i<j;i++)
		{
			m_mercid=m_list.GetItemText(i,0);
			CString inprice=m_list.GetItemText(i,5);
			CString numbers=m_list.GetItemText(i,7);
			CString paympney=m_list.GetItemText(i,6);
			sqlstr.Format("update tb_storemanage set nowvalues=nowvalues-%s where mercid='%s' and (nowvalues-%s)>downlimit",numbers,m_mercid,numbers);
			_variant_t va;
			theApp.m_connection->Execute(_bstr_t(sqlstr),&va,adModeUnknown);
			try{
			sqlstr.Format("insert into tb_storage (storid,merchandiseid,stordate,stortype,provid,storinfo,operid,storflag,unitprice,numbers,paymoney)\
				values ('%s','%s','%s','%s','%s','%s','%s','0',%s,%s,%s)",m_outnumberid,m_mercid,m_dateArr.GetAt(i),m_intypeArr.GetAt(i),\
				m_provArr.GetAt(i),m_storinfoArr.GetAt(i),m_operidArr.GetAt(i),inprice,numbers,paympney);
		    theApp.m_connection->Execute(_bstr_t(sqlstr),NULL,adModeUnknown);
			if(va.intVal==0)
			{
				CString str;
				str.Format("'%s'数量已小于最小库存数!",m_mercid);
				MessageBox(str);
				continue;
			}
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
		MessageBox("出库确认后在保存!");
	}
	    flag=false; 
		ShowButton(false);
		ShowWindows(false);
		m_list.DeleteAllItems();
		m_provArr.RemoveAll();
		m_innumberArr.RemoveAll();
		m_dateArr.RemoveAll();
		m_merctypeArr.RemoveAll();
		m_storinfoArr.RemoveAll();
		m_operidArr.RemoveAll();
   
}



void CGATHEROUT::OnBtnDel() 
{
	// TODO: Add your control notification handler code here
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

void CGATHEROUT::OnBtnCancel() 
{
	// TODO: Add your control notification handler code here
	CAnotherView *cview=(CAnotherView *)GetParent();
	cview->ShowBmo(true);
	cview->m_Tab.SetCurSel(0);
	ClearAll();
	ShowWindows(false);
}

void CGATHEROUT::OnItemchangedList2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here

    delitem=pNMListView->iItem;	

	*pResult = 0;
}
