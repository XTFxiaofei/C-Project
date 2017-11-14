// SETPRICE.cpp : implementation file
//

#include "stdafx.h"
#include "HCOK.h"
#include "SETPRICE.h"
#include "ADOConn.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// SETPRICE dialog


SETPRICE::SETPRICE(CWnd* pParent /*=NULL*/)
	: CDialog(SETPRICE::IDD, pParent)
{
	//{{AFX_DATA_INIT(SETPRICE)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void SETPRICE::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(SETPRICE)
	DDX_Control(pDX, IDC_LIST2, m_list2);
	DDX_Control(pDX, IDC_LIST1, m_list1);
	DDX_Control(pDX, IDC_COMBO2, m_combo2);
	DDX_Control(pDX, IDC_COMBO1, m_combo1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(SETPRICE, CDialog)
	//{{AFX_MSG_MAP(SETPRICE)
	ON_BN_CLICKED(IDC_SETROOM, OnSetroom)
	ON_BN_CLICKED(IDC_SETABATE, OnSetabate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// SETPRICE message handlers

BOOL SETPRICE::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	(CEdit*)GetDlgItem(IDC_PRICE)->SetFocus();//获得焦点
	//*******************初始化控件***********************************//
    m_combo1.InsertString(0,"小包间");
	m_combo1.InsertString(1,"中包间");
	m_combo1.InsertString(2,"大包间");
	m_combo1.InsertString(3,"豪华包间");
	
    m_combo1.SetCurSel(0);//设置初始值
	///////////////////////////////////////
	m_combo2.InsertString(0,"非会员");
	m_combo2.InsertString(1,"一般会员");
	m_combo2.InsertString(2,"中级会员");
	m_combo2.InsertString(3,"高级会员");
	
    m_combo2.SetCurSel(0);	//设置初始值
	///////////////////////////////////////////////
    	m_list1.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	   m_list1.InsertColumn(0,"包房类型",LVCFMT_CENTER,100);
	   m_list1.InsertColumn(1,"每小时单价(元)",LVCFMT_CENTER,100);
	   m_list2.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	   m_list2.InsertColumn(0,"会员卡类型",LVCFMT_CENTER,100);
	   m_list2.InsertColumn(1,"打折率",LVCFMT_CENTER,100);
	   
	   ShowabatetDate() ;//显示打折率
	   ShowroomtDate();//显示房间
	return false;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void SETPRICE::OnOK() 
{

	CDialog::OnOK();	

}


void SETPRICE::ShowroomtDate() /////////////////////////显示包间价格
{
	CString room12,  price12;
	   m_list1.DeleteAllItems();//清空所有
	   //////////////////////////////////////////
	    ADOConn m_AdoConn;   //定义数据库操作对象
	   m_AdoConn.OnInitADOConn();//创建连接
	   _bstr_t sqlroom;
	   _RecordsetPtr m_pRecordset;	  //定义记录集
	   sqlroom = "select*from room ";   //查询所有房间
	 
	   m_pRecordset=m_AdoConn.GetRecordSet( sqlroom);
	   if(m_pRecordset->adoEOF)//如果没有则返回
	   {
		   m_AdoConn.ExitConnect();
		   return;
	   }     
	  
		   int t=0;
		   m_list1.DeleteAllItems();   //清空
		   while(!m_pRecordset->adoEOF)
		   {
		    room12 =m_pRecordset->GetFields()->GetItem("roomtype")->Value.bstrVal;/////////////////取字段
		    price12 =m_pRecordset->GetFields()->GetItem("price")->Value.bstrVal;/////////////////取字段
		    m_list1.InsertItem(t,room12);   //显示房间
		   m_list1.SetItemText(t,1,	price12); //显示价格
           m_pRecordset->MoveNext();
		   t++;
		   }
	    m_AdoConn.ExitConnect(); //释放数据库资源
}
void SETPRICE::ShowabatetDate() ///////////////显示打折率,注释与上面类似
{
	CString card12,  abate12;
	   m_list2.DeleteAllItems();
	//////////////////////////////////////////
	   ADOConn m_AdoConn; //定义数据库操作对象
	   m_AdoConn.OnInitADOConn();
	   _bstr_t sqlroom,sqlabate;
	   _RecordsetPtr m_pRecordset;	

	   sqlabate="select*from abate ";
	   m_pRecordset=m_AdoConn.GetRecordSet(   sqlabate);
	   if(m_pRecordset->adoEOF)
	   {
		   m_AdoConn.ExitConnect();
		   return;
	   }     
	   if(!m_pRecordset->adoEOF)
	   {  
		   int t=0;
		   m_list2.DeleteAllItems();
		   while(!m_pRecordset->adoEOF)
		   {
	
		  	card12 =m_pRecordset->GetFields()->GetItem("cardtype")->Value.bstrVal;/////////////////取字段
	       abate12 =m_pRecordset->GetFields()->GetItem("abate")->Value.bstrVal;/////////////////取字段
		  
		   m_list2.InsertItem(t,card12);
		   m_list2.SetItemText(t,1,	abate12);
  
		   m_pRecordset->MoveNext();
		   t++;
		   }
	   }
}



void SETPRICE::OnSetroom() ////////////////设置包间价格
{
	CString roomtype1;
	int k=m_combo1.GetCurSel();
	m_combo1.GetLBText(k,roomtype1);///////////////////得到房间类型	
	CString price1;
	GetDlgItem(IDC_PRICE)->GetWindowText(  price1);
	////////////////////////////////////////////////////加入数据到数据库
				
	ADOConn m_AdoConn;   //定义数据库操作对象
	m_AdoConn.OnInitADOConn();  //创建连接
	
	_RecordsetPtr m_pRecordset;
	_bstr_t sql;
	
	sql = "select*from room where roomtype='"+roomtype1+"' ";
	 double tempprice=atof( price1);////////////判断是否为字符,不正确的方法
	if( tempprice==0)
	{
		MessageBox("您没有输入的格式不对!","系统提示：",MB_OK|MB_ICONASTERISK);	
		GetDlgItem(IDC_PRICE)->SetWindowText("");
		(CEdit*)GetDlgItem(IDC_PRICE)->SetFocus();	
		return;
	}			
	
	m_pRecordset=m_AdoConn.GetRecordSet(sql);
	if(m_pRecordset->adoEOF)//如果不存在就新建一条记录,如存在就覆盖
	m_pRecordset->AddNew();
				
	m_pRecordset->GetFields()->GetItem("roomtype")->Value=(_bstr_t) roomtype1 ;///写入房间
	
	m_pRecordset->GetFields()->GetItem("price")->Value=(_bstr_t)  price1;////写入价格
	m_pRecordset->Update();
	m_AdoConn.ExitConnect();//释放数据库资源
	ShowroomtDate();///刷新
	GetDlgItem(IDC_PRICE)->SetWindowText("");
	(CEdit*)GetDlgItem(IDC_PRICE)->SetFocus();		
						
}

void SETPRICE::OnSetabate() /////////////////////设置会员打折率,注释与上面类似
{
	CString cardtype1;
	ADOConn m_AdoConn;
	
	_RecordsetPtr m_pRecordset;
	_bstr_t sql;
	int k2=m_combo2.GetCurSel();
	m_combo2.GetLBText(k2,cardtype1);///////////////////得到会员卡类型
	
	CString abate1;
	GetDlgItem(IDC_ABATD)->GetWindowText(  abate1);
	double tempabate=atof( abate1);/////////////判断是否为字符
	if( tempabate==0)
	{
		MessageBox("您没有输入的格式不对!","系统提示：",MB_OK|MB_ICONASTERISK);	
		GetDlgItem(IDC_ABATD)->SetWindowText("");
		(CEdit*)GetDlgItem(IDC_ABATD)->SetFocus();	
		return;
	}			
	if(	atof(abate1)>1||atof(abate1)<0)
		
	{
		MessageBox("打折率设置有误请输入小数!","系统提示：",MB_OK|MB_ICONASTERISK);
	}
	else
	{	
		m_AdoConn.OnInitADOConn();
		sql = "select*from abate where cardtype='"+cardtype1+"' ";
		m_pRecordset=m_AdoConn.GetRecordSet(sql);
		if(m_pRecordset->adoEOF)
			m_pRecordset->AddNew();
		
		m_pRecordset->GetFields()->GetItem("cardtype")->Value=(_bstr_t) cardtype1;////写入歌名
		
		
		m_pRecordset->GetFields()->GetItem("abate")->Value=(_bstr_t) abate1;////写入打折率
		
		m_pRecordset->Update();
		
		m_AdoConn.ExitConnect();
		
	}
	ShowabatetDate() ;
	GetDlgItem(IDC_ABATD)->SetWindowText("");
	(CEdit*)GetDlgItem(IDC_ABATD)->SetFocus();	
	
}
