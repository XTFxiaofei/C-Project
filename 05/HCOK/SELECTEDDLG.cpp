// SELECTEDDLG.cpp : implementation file
//

#include "stdafx.h"
#include "HCOK.h"
#include "SELECTEDDLG.h"
#include "ADOConn.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// SELECTEDDLG dialog
CString addallsongna;

SELECTEDDLG::SELECTEDDLG(CWnd* pParent /*=NULL*/)
	: CDialog(SELECTEDDLG::IDD, pParent)
{
	//{{AFX_DATA_INIT(SELECTEDDLG)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void SELECTEDDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(SELECTEDDLG)
	DDX_Control(pDX, IDC_LIST1, m_list);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(SELECTEDDLG, CDialog)
	//{{AFX_MSG_MAP(SELECTEDDLG)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList1)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, OnItemchangedList1)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// SELECTEDDLG message handlers
//************************下面的方法比较的笨,是先取后插,注释与前面模块类似*****************************************//

void SELECTEDDLG::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	CString 	sformat,	sfilename,	stype,	ssname,	spath;

	///////////////////////////////////////////////得到个曲的全部信息
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	_RecordsetPtr m_pRecordset;
	_bstr_t sql,addtolist,createlistsql,dellistsql;
	sql = "select*from usertemp where tmuname='"+addallsongna+"' ";
		
	m_pRecordset=m_AdoConn.GetRecordSet(sql);
	if(!m_pRecordset->adoEOF)
	{
	//	sname =m_pRecordset->GetFields()->GetItem("muname")->Value.bstrVal;/////////////////取歌曲名
		sformat =m_pRecordset->GetFields()->GetItem("tformate")->Value.bstrVal;/////////////////取歌格式		
	sfilename =m_pRecordset->GetFields()->GetItem("tfilename")->Value.bstrVal;/////////////////取歌文件名		
	stype =m_pRecordset->GetFields()->GetItem("tsongtype")->Value.bstrVal;	/////////////////取歌流派		
	ssname =m_pRecordset->GetFields()->GetItem("tsingername")->Value.bstrVal;/////////////////取歌手名	
	spath =m_pRecordset->GetFields()->GetItem("playpath")->Value.bstrVal;/////////////////取路径

	}
	else{
				m_AdoConn.ExitConnect();
				return;
		}
				
	m_pRecordset->Close();
	////////////////////////////////////////////////////////////////////添加歌曲到临时表

	//sql = "select* from playlist where tmuname='"+addallsongna+"'";////////////////////
    addtolist="select* from playlist where tmuname='"+addallsongna+"'";////////////////////	
	createlistsql = "Create table playlist(tmuname varchar(50),tformate varchar(50),tfilename varchar(50),tsongtype varchar(50),tsingername varchar(50),tsingerpin varchar(50),playpath  varchar(200))";
	//dellistsql="Drop table  playlist";	

				//m_pRecordset=m_AdoConn.GetRecordSet(sql);
				//if(!m_pRecordset->adoEOF)
			//	MessageBox("该歌曲您已经点播过,请选择其他歌曲点播!","系统提示：",MB_OK|MB_ICONASTERISK);
				//else{
					
				
				/////////////////////////////////////添加到播放临时表
				try
				{	
					m_pRecordset=m_AdoConn.GetRecordSet(addtolist);
					//if(!m_pRecordset->adoEOF)
				    if(!m_pRecordset->adoEOF)
					{
	            GetDlgItem(IDC_INFOR)->SetWindowText("该歌曲已经在播放列表中!");
					//	MessageBox("该歌曲已经在您的播放列表中,请选其他歌曲!","系统提示：",MB_OK|MB_ICONASTERISK);
			           return;
					}
						
						
						m_pRecordset->AddNew();
						m_pRecordset->GetFields()->GetItem("tmuname")->Value=(_bstr_t) addallsongna;	////////////////////取歌曲名
						m_pRecordset->GetFields()->GetItem("tformate")->Value=(_bstr_t) 	sformat;///////写入歌格式
						m_pRecordset->GetFields()->GetItem("tfilename")->Value=(_bstr_t) sfilename;////写入歌文件名	
						m_pRecordset->GetFields()->GetItem("tsongtype")->Value=(_bstr_t)  	stype;////写入歌流派	
						m_pRecordset->GetFields()->GetItem("tsingername")->Value=(_bstr_t)  ssname;////写入歌手名
						m_pRecordset->GetFields()->GetItem("playpath")->Value=(_bstr_t)  	spath;////写入歌路径
						m_pRecordset->Update();
						
					
				}
				catch(...)
				{
					//m_AdoConn.ExecuteSQL(dellistsql);
					m_AdoConn.ExecuteSQL(createlistsql);
					m_pRecordset=m_AdoConn.GetRecordSet(addtolist);
					if(!m_pRecordset->adoEOF)
					//	MessageBox("该歌曲您已经点播过,请选择其他歌曲点播!","系统提示：",MB_OK|MB_ICONASTERISK);
					{	GetDlgItem(IDC_INFOR)->SetWindowText("该歌曲已经在播放列表中!");}
					else{
						
						
						m_pRecordset->AddNew();
						m_pRecordset->GetFields()->GetItem("tmuname")->Value=(_bstr_t) addallsongna;	////////////////////取歌曲名
						m_pRecordset->GetFields()->GetItem("tformate")->Value=(_bstr_t) 	sformat;///////写入歌格式
						m_pRecordset->GetFields()->GetItem("tfilename")->Value=(_bstr_t) sfilename;////写入歌文件名	
						m_pRecordset->GetFields()->GetItem("tsongtype")->Value=(_bstr_t)  	stype;////写入歌流派	
						m_pRecordset->GetFields()->GetItem("tsingername")->Value=(_bstr_t)  ssname;////写入歌手名
						m_pRecordset->GetFields()->GetItem("playpath")->Value=(_bstr_t)  	spath;////写入歌路径
						m_pRecordset->Update();
					}
				
					
			}
				
				mainshowlist++;	
		GetDlgItem(IDC_INFOR)->SetWindowText("添加歌曲 "+addallsongna+" 到播放列表成功!");
					
			
    	m_AdoConn.ExitConnect();
	
	*pResult = 0;
}

void SELECTEDDLG::OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
  int selectrow=pNMListView->iItem;

	 addallsongna=m_list.GetItemText(selectrow,1);
     UpdateData(false);

	*pResult = 0;
}

BOOL SELECTEDDLG::OnInitDialog() 
{
	CDialog::OnInitDialog();

 m_list.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	   m_list.InsertColumn(0,"序号",LVCFMT_CENTER,100);
	   m_list.InsertColumn(1,"歌曲名",LVCFMT_CENTER,150);
	   m_list.InsertColumn(2,"歌手名",LVCFMT_CENTER,150);
	    SetTimer(1,5000,NULL);
		SetTimer(2,1,NULL);
	   ShowDate();
	  	//////////////////////////////////
   GetDlgItem(IDC_INFOR)->SetWindowText("双击左键添加到播放列表!");
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void SELECTEDDLG::ShowDate()
{
	
	CString songid,  songname,		  singername,  songtype,  filename,fileformat;
	   m_list.DeleteAllItems();
	 
	
	   
	//////////////////////////////////////////
	   ADOConn m_AdoConn;
	   m_AdoConn.OnInitADOConn();
	   _bstr_t sql;
	   _RecordsetPtr m_pRecordset;	
	   

	   sql = "select*from usertemp ";
	   
	   m_pRecordset=m_AdoConn.GetRecordSet(sql);
	 if(m_pRecordset->adoEOF)
	  {
		 m_AdoConn.ExitConnect();
		 return;
	 }
	   if(!m_pRecordset->adoEOF)
	   {  
		   int t=0;
		   m_list.DeleteAllItems();
		   while(!m_pRecordset->adoEOF)
		   {int b=t+1;
		   
		   songid.Format("%d",b);
		   
		   songname =m_pRecordset->GetFields()->GetItem("tmuname")->Value.bstrVal;/////////////////取字段
		  singername =m_pRecordset->GetFields()->GetItem("tsingername")->Value.bstrVal;/////////////////取字段
		  
		  
		   m_list.InsertItem(t,songid);
		   m_list.SetItemText(t,1,	songname);
           m_list.SetItemText(t,2,	singername );
	
		 
		 
	   
		   m_pRecordset->MoveNext();
		   t++;
		   }
	   }
	   
	   else 
	   {
		   //	GetDlgItem(IDC_INFOR)->SetWindowText("没有歌曲!");
		   m_list.DeleteAllItems();
	   }
	   
	   m_AdoConn.ExitConnect();
}

void SELECTEDDLG::OnTimer(UINT nIDEvent) 
{
	
	  switch(nIDEvent)   
        {   
                case   1:GetDlgItem(IDC_INFOR)->SetWindowText("双击左键添加到播放列表!");
	                       
	                      CDialog::OnTimer(nIDEvent);  
                case   2:
          
						int num = getSongNum();     //得到usertemp表中歌曲的条数
						int b=m_list.GetItemCount();//得到列表中的歌曲条数
						if(num != b)    //如果不相等那么刷新
						ShowDate();   //实现列表的刷新
                
        }   
}

//*****************得到usertemp表中歌曲的条数*************************************//
int SELECTEDDLG::getSongNum()
{
	   int songNum =0 ;
     	ADOConn m_AdoConn;
	    m_AdoConn.OnInitADOConn();
	   _bstr_t sql;
	   _RecordsetPtr m_pRecordset;	
	   sql = "select*from usertemp ";
	   m_pRecordset=m_AdoConn.GetRecordSet(sql);
	   if(m_pRecordset->adoEOF)
	   {
		   m_AdoConn.ExitConnect();
		   return 0;
	   }
	   else{ 
		   while(!m_pRecordset->adoEOF)
		   {
			   songNum++;
			   m_pRecordset->MoveNext();
		   }
		 return songNum ;  //返回歌曲条数
	   }
	   m_AdoConn.ExitConnect();
}