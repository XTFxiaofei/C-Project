// MADDSONG.cpp : implementation file
//

#include "stdafx.h"
#include "HCOK.h"
#include "MADDSONG.h"
#include "ADOConn.h"
#include "ADDSGEDLG.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CString desongname1,desingername1,deformat1;
bool mp3filebroken;
/////////////////////////////////////////////////////////////////////////////
// MADDSONG dialog


MADDSONG::MADDSONG(CWnd* pParent /*=NULL*/)
	: CDialog(MADDSONG::IDD, pParent)
{
	//{{AFX_DATA_INIT(MADDSONG)
	m_filename = _T("");
	m_format = _T("");
	m_singer = _T("");
	m_songname = _T("");
	//}}AFX_DATA_INIT
}


void MADDSONG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(MADDSONG)
	DDX_Control(pDX, IDC_RADIO1, m_radio);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_COMBO2, m_comb2);
	DDX_Control(pDX, IDC_COMBO1, m_comb1);
	DDX_Text(pDX, IDC_FILENAME, m_filename);
	DDX_Text(pDX, IDC_FORMAT, m_format);
	DDX_Text(pDX, IDC_SINGER, m_singer);
	DDX_Text(pDX, IDC_SONGNAME, m_songname);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(MADDSONG, CDialog)
	//{{AFX_MSG_MAP(MADDSONG)
	ON_BN_CLICKED(IDC_CHOOSE, OnChoose)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_DEL, OnDel)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, OnItemchangedList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// MADDSONG message handlers

BOOL MADDSONG::OnInitDialog() 
{
	CDialog::OnInitDialog();
	//*********************初始化歌曲名字数选项*********************///
    m_comb1.InsertString(0,"1");
	m_comb1.InsertString(1,"2");
	m_comb1.InsertString(2,"3");
	m_comb1.InsertString(3,"4");
	m_comb1.InsertString(4,"5");
	m_comb1.InsertString(5,"6");
    m_comb1.InsertString(6,"7");
	m_comb1.InsertString(7,"8");
	m_comb1.InsertString(8,"9");
	m_comb1.InsertString(9,"10");
	m_comb1.InsertString(10,"11");
	m_comb1.InsertString(11,"12");
    m_comb1.SetCurSel(0);
	//*********************初始化歌曲类型选项*********************///
	m_comb2.InsertString(0,"流行");
	m_comb2.InsertString(1,"民族");
	m_comb2.InsertString(2,"通俗");
	m_comb2.InsertString(3,"古典");
	m_comb2.InsertString(4,"爵士");
	m_comb2.InsertString(5,"摇滚");
    m_comb2.InsertString(6,"轻音乐");
	   m_comb2.SetCurSel(0);
		//*********************初始化list控件********************///
	   
	   m_list.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	   m_list.InsertColumn(0,"歌名",LVCFMT_CENTER,150);
	   m_list.InsertColumn(1,"歌手名",LVCFMT_CENTER,100);
	   m_list.InsertColumn(2,"歌曲风格",LVCFMT_CENTER,80);
	   m_list.InsertColumn(3,"格式",LVCFMT_CENTER,80);

	   m_radio.SetCheck(1);  //默认选择链接添加
/////////////////////////////////////////////
	   mp3filebroken=false;
	   ShowData() ;
	   return TRUE;  // return TRUE unless you set the focus to a control
//		
}

void MADDSONG::OnChoose() 
{
	//设置可以选择的文件类型
	char szFilter[] =" 媒体文件 (所有类型)|*.mp3;*.wma;*.wmv;*.wav;*.avi;*.rm;*.rmvb\
		|视频文件 |*.wmv;*.avi;*.rm;*.rmvb|音频文件|*.mp3;*.wma;*.wav|所有文件 (*.*)|*.*||";
		CFileDialog filedlg(TRUE,NULL,NULL,OFN_HIDEREADONLY,szFilter); 	
	if(filedlg.DoModal()==IDOK)
	{
		CString  strname,strname1;
		strname=filedlg.GetFileName();////////////////////////的到文件名
		strname1=filedlg.GetFileTitle();////////////////////////文件名
		Qfilename1=filedlg.GetPathName();/////////////////////////传值
		Qfilename2=strname;//////////////////传值
		GetDlgItem(IDC_FILENAME)->SetWindowText(strname);//显示到编辑框
		CString strname2,strname3,strname4;
		GetDlgItem(IDC_SONGNAME)->GetWindowText(strname2);//得到编辑后的值
		GetDlgItem(IDC_FILENAME)->GetWindowText(strname3);//得到编辑后的值
		strname4=strname3.Right(strname3.GetLength()-strname1.GetLength()-1);//得到文件的格式 ,如'mp3,wma'
		if( strname4=="mp3")//如果是MP3格式的就用方法自动读取文件属性	
		{
			CFile file;
			file.Open(strname,CFile::modeRead);
			//把文件的最后128字节信息读给pbuf数组
			long seekPos = 128;
			file.Seek(-seekPos,CFile::end);
			BYTE pbuf[128];
			memset(pbuf,0,sizeof(pbuf));
			file.Read(pbuf,128);
			//获得tag,如果不是tag，那么就返回
			if(!((pbuf[0] == 'T'|| pbuf[0] == 't')
				&&(pbuf[1] == 'A'|| pbuf[1] == 'a')
				&&(pbuf[2] == 'G'|| pbuf[0] == 'g')))
			{
				file.Close();
				mp3filebroken=true;
				return ;
			}
			mp3=(MP3INFO *) new BYTE[sizeof(MP3INFO)];
			ZeroMemory(mp3,sizeof(MP3INFO));	
			memcpy(mp3->Identify,pbuf,3); //获得tag
			memcpy(mp3->Title,pbuf+3,30); //获得歌名
			memcpy(mp3->Artist,pbuf+33,30); //获得作者
			memcpy(mp3->Album,pbuf+63,30); //获得唱片名
			memcpy(mp3->Year,pbuf+93,4); //获得年
			memcpy(mp3->Comment,pbuf+97,28); //获得注释
			memcpy(&mp3->reserved,pbuf+125,1); //获得保留
			memcpy(&mp3->reserved2,pbuf+126,1);
			memcpy(&mp3->reserved3,pbuf+127,1);
			GetDlgItem(IDC_SONGNAME)->SetWindowText(mp3->Title);//将歌名返回编辑框
			GetDlgItem(IDC_SINGER)->SetWindowText(mp3->Artist);//将歌手名返回编辑框
			GetDlgItem(IDC_FORMAT)->SetWindowText(strname4);//将格式返回编辑框
			file.Close();
			delete mp3;	
		}
		else{
			GetDlgItem(IDC_FORMAT)->SetWindowText(strname4);//是用截取得到的值
			GetDlgItem(IDC_SONGNAME)->SetWindowText(  strname1); //显示歌名
			GetDlgItem(IDC_FILENAME)->SetWindowText(strname);//文件名
		}
		mp3filebroken=false;
	}		 
}


void MADDSONG::OnAdd() 
{	 
	tempshow++;
	CString songname,format,strname4,singer,addpath,newfilename,strtemp;
	GetDlgItem(IDC_SONGNAME)->GetWindowText(  songname);  
	GetDlgItem(IDC_FORMAT)->GetWindowText(  format);
	GetDlgItem(IDC_SINGER)->GetWindowText(  singer);///////////////////获取歌手名
	if(Qfilename1==""||songname=="")  //路径和歌名为空时
		GetDlgItem(IDC_INFOR)->SetWindowText("请先选择歌曲!");
	else
	{
		if( singer=="")//如果歌手名为空
		{	GetDlgItem(IDC_INFOR)->SetWindowText("请填歌手!");
		if( mp3filebroken==true)
			GetDlgItem(IDC_INFOR)->SetWindowText("请填歌手姓名和格式形式!");
		}
		else
		{
			ADOConn m_AdoConn;/////////////////////////////用ADO连接数据库	
			m_AdoConn.OnInitADOConn();  //连接数据库
			_RecordsetPtr m_pRecordset;  //定义记录集
			_bstr_t sql;
			sql ="select*from musiclist where muname ='"+songname+"'and singernam='"+singer+"'";//查询歌曲
			m_pRecordset=m_AdoConn.GetRecordSet(sql);
			if(!(m_pRecordset->adoEOF))////////////////////////判断有歌曲记录
				GetDlgItem(IDC_INFOR)->SetWindowText("您已经添加过这首歌曲!");	
			else//判断有没歌手
			{  
				_bstr_t findsin;
				findsin = "select* from singer where sinnam='"+ singer+"'";////////////////////
				m_pRecordset=m_AdoConn.GetRecordSet(findsin);
				if(m_pRecordset->adoEOF)  //没有当前你输入的歌手的资料,会弹出对话框让你添加
				{
					GetDlgItem(IDC_INFOR)->SetWindowText("歌库中没有该歌曲歌手的信息,请补充!");
					ADDSGEDLG addsinger;
					addsinger.m_singer=singer;
					addsinger.DoModal();
				}
				//物理添加,将文件添加到工程文件夹下,此方法不好,可用直接的文件复制函数
				if(!m_radio.GetCheck() )//添加文件到歌曲文件夹/////////////////
				{
					CString sPath ,fullname;
					int nPos;
					CFile* writefile;//////////////////////写文件
					CFile* readfile;////////////////////////读文件
					long readlen,poslen,filelen;
					LPVOID pvData;
					HGLOBAL hGlobal;
					GetModuleFileName(NULL,sPath.GetBufferSetLength (MAX_PATH+1),MAX_PATH);//得到要输出文件的路径
					nPos=sPath.ReverseFind('\\');
					sPath=sPath.Left(nPos);
					nPos=sPath.ReverseFind('\\');
				    sPath=sPath.Left(nPos);
					sPath=sPath+"\\歌库文件夹";
					CString  strname,strname1,filename1;
					filename1=  Qfilename1; ////////////////得到路径 ,在选择文件那边得到的
					strname=   Qfilename2;////////////////////////的到文件名,在选择文件那边得到的
					fullname.Format("%s\\%s",sPath,strname);
					readfile=new CFile(filename1,CFile::modeRead);
					HANDLE hfile=::CreateFile(	fullname,GENERIC_WRITE|GENERIC_WRITE,0,0,CREATE_NEW,FILE_ATTRIBUTE_NORMAL,0);
					CloseHandle(hfile);
					writefile=new CFile(fullname,CFile::modeWrite);
					filelen=readfile->GetLength();
					hGlobal = GlobalAlloc(GMEM_MOVEABLE,512);
					pvData = GlobalLock(hGlobal);
					while(1)
					{
						ZeroMemory(pvData,512);
						readlen=readfile->ReadHuge(pvData,512);
						poslen=readfile->GetPosition();//获取文件指针的位置
						writefile->WriteHuge(pvData,readlen);
						if(poslen==filelen)//如果指针移到末尾,就退出循环
							break;
					}
					GlobalUnlock(hGlobal);
					readfile->Close();  //流关闭
					writefile->Close();
					//重命名文件
					songname.TrimRight();  //去空格
					CString	stredfilename=songname+'.'+format;//得到文件名+格式
					CString temp,strtemp;strtemp=temp=	fullname;
					int pos1=temp.Find("\\");
					while(pos1>0)
					{
						temp=temp.Right(temp.GetLength()-1-pos1);
						pos1=temp.Find("\\");
					}
					strtemp=strtemp.Left(strtemp.GetLength()-temp.GetLength());
					strtemp+=stredfilename; 
					CFile::Rename(fullname,strtemp);
					addpath="系统文件夹下";
					newfilename=stredfilename;
				}    
				else//*************用于只存地址的不复制文件的
				{
					addpath=Qfilename1;
					songname.TrimRight();
					newfilename=songname+'.'+format;
				}
				CString strname5, format;
				GetDlgItem(IDC_SINGER)->GetWindowText(  strname5);///////////////////获取歌手名
				CString munum;
				int k=m_comb1.GetCurSel();
				m_comb1.GetLBText(k,munum);///////////////////得到歌字数
				CString mutype;
				int k2=m_comb2.GetCurSel();
				m_comb2.GetLBText(k2,mutype);////////////////////得到歌类型名
				GetDlgItem(IDC_FORMAT)->GetWindowText( format);//得到格式名
				m_AdoConn.ExitConnect();	
				m_AdoConn.OnInitADOConn();
				_RecordsetPtr m_pRecordset;
				_bstr_t sql;
				sql = "select*from musiclist";
				m_pRecordset=m_AdoConn.GetRecordSet(sql);
				m_pRecordset->AddNew();//添加新行
				m_pRecordset->GetFields()->GetItem("singernam")->Value=(_bstr_t) strname5 ;///写入歌手名
				m_pRecordset->GetFields()->GetItem("muname")->Value=(_bstr_t) songname;////写入歌名
				m_pRecordset->GetFields()->GetItem("mnum")->Value=(_bstr_t)  munum;////写入歌字数
				m_pRecordset->GetFields()->GetItem("mtpye")->Value=(_bstr_t)  mutype ;////写入歌的类型
				m_pRecordset->GetFields()->GetItem("fname")->Value=(_bstr_t) newfilename;////写入文件名
				m_pRecordset->GetFields()->GetItem("format")->Value=(_bstr_t)  format ;////写入格式
				m_pRecordset->GetFields()->GetItem("path")->Value=(_bstr_t)  addpath ;////写入路径
				m_pRecordset->Update();
				m_AdoConn.ExitConnect();//释放数据库资源
				GetDlgItem(IDC_INFOR)->SetWindowText("添加"+songname+"成功到歌库!");
				GetDlgItem(IDC_SONGNAME)->SetWindowText("");  //清空输入框
				GetDlgItem(IDC_SINGER)->SetWindowText(""); //清空输入框
				GetDlgItem(IDC_FILENAME)->SetWindowText(""); //清空输入框
				GetDlgItem(IDC_FORMAT)->SetWindowText("");//清空输入框
				m_comb1.SetCurSel(0);//设置显示第一列
				m_comb2.SetCurSel(0);//设置显示第一列
				}
				}
		}
		
		ShowData() ;			
}
void MADDSONG::ShowData() //显示信息
{
	CString  muname, singername, mtype,format;
	m_list.DeleteAllItems();  //删除所有的
	int k=0;
	ADOConn m_AdoConn;//定义数据库操作对象
			
	m_AdoConn.OnInitADOConn();//连接数据库
   _RecordsetPtr m_pRecordset; //定义记录集
	_bstr_t sql;
				
	sql = "select*from musiclist";
		
		m_pRecordset=m_AdoConn.GetRecordSet(sql);//得到记录集
	if(m_pRecordset->adoEOF)  //如果没有就退出函数
	{
			m_AdoConn.ExitConnect(); //释放数据库资源
					return;
	}
	m_pRecordset->MoveFirst();
			

while(!m_pRecordset->adoEOF)  //遍历记录集显示在list中
	{   		

	muname=m_pRecordset->GetFields()->GetItem("muname")->Value.bstrVal;/////////////////取歌曲名
	   singername=m_pRecordset->GetFields()->GetItem("singernam")->Value.bstrVal;/////////////////取歌手名
	   
	   mtype=m_pRecordset->GetFields()->GetItem("mtpye")->Value.bstrVal;/////////////////取歌的类型
	   format=m_pRecordset->GetFields()->GetItem("format")->Value.bstrVal;/////////////////取格式
	   m_list.InsertItem(k, muname);  //显示歌名到list中
	   m_list.SetItemText(k,1,singername);//显示歌手到list中
	   m_list.SetItemText(k,2, mtype);
	   m_list.SetItemText(k,3,format);
	   m_pRecordset->MoveNext();
	   k++;
	}
	m_AdoConn.ExitConnect();
}

void MADDSONG::OnDel() 
{
	delsongfresh++;
	ADOConn m_AdoConn;//创建数据库连接对象
			
	m_AdoConn.OnInitADOConn();  //创建连接
	_RecordsetPtr m_pRecordset; //定义记录集
     _bstr_t sql;
		
	sql = "delete from musiclist where singernam='"+desingername1+"'and muname='"+desongname1+"'";
    m_pRecordset=m_AdoConn.GetRecordSet(sql);//删除数据库中
	//得到系统文件路径\Debug\歌库文件夹
    CString sPath ;
	int nPos;
	GetModuleFileName(NULL,sPath.GetBufferSetLength (MAX_PATH+1),MAX_PATH);
	nPos=sPath.ReverseFind('\\');
	sPath=sPath.Left(nPos);
	nPos=sPath.ReverseFind('\\');
	sPath=sPath.Left(nPos);

	sPath=sPath+"\\歌库文件夹";
	desongname1.TrimRight();//去右边的空格
	
	CString	defilename1=desongname1+'.'+deformat1; //得到文件加格式名

     CString	filename=sPath+"\\"+defilename1;//得到完整路径
	DeleteFile(filename);
	ShowData() ;
		GetDlgItem(IDC_INFOR)->SetWindowText("删除"+desongname1+"成功!");
	
}

void MADDSONG::OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	int selectrow=pNMListView->iItem;
   desongname1=m_list.GetItemText(selectrow,0);//得到歌名
    desingername1=m_list.GetItemText(selectrow,1); //得到歌手名
    deformat1=m_list.GetItemText(selectrow,3);//得到格式
   UpdateData(false);
	
	
	*pResult = 0;
}
