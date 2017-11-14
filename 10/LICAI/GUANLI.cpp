// GUANLI.cpp : implementation file
//

#include "stdafx.h"
#include "licai.h"
#include "GUANLI.h"
#include "XGQX.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// GUANLI dialog


GUANLI::GUANLI(CWnd* pParent /*=NULL*/)
	: CDialog(GUANLI::IDD, pParent)
{
	//{{AFX_DATA_INIT(GUANLI)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void GUANLI::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(GUANLI)
	DDX_Control(pDX, IDC_LIST1, m_list);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(GUANLI, CDialog)
	//{{AFX_MSG_MAP(GUANLI)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, OnItemchangedList1)
	ON_BN_CLICKED(IDC_BUTTON1, OnModify)
	ON_BN_CLICKED(IDC_BUTTON2, OnDele)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// GUANLI message handlers

BOOL GUANLI::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	pdb=new CDatabase;
	mySet=new PWSet(pdb);
	mySet->Open();	
	m_list.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
    m_list.InsertColumn(0,"用户名",LVCFMT_CENTER,150);
    m_list.InsertColumn(1,"用户权限",LVCFMT_CENTER,150);
	LOADDATA();	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void GUANLI::LOADDATA()
{
	mySet->Requery();
	m_list.DeleteAllItems();
	int i=0;
	while(!mySet->IsEOF())
	{
		m_list.InsertItem(i,mySet->m_ID);
		m_list.SetItemText(i,1,mySet->m_AUTHOR);
		i++;
		mySet->MoveNext();
	}
}

void GUANLI::OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult) //获得对应列表框信息
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
    int selectrow=pNMListView->iItem;	
	m_id=m_list.GetItemText(selectrow,0);
	*pResult = 0;
}

void GUANLI::OnModify() 
{
	if(m_id=="")
	{
		MessageBox("请选择所需修改的记录","提示",MB_OK|MB_ICONINFORMATION);
		return;
	}
	if(ID==m_id)
	{
		MessageBox("当前用户无法修改权限","提示",MB_OK|MB_ICONINFORMATION);
		return;
	}
	else
	{
		mySet->MoveFirst();
		while(!mySet->IsEOF())
		{   
			if(mySet->m_ID==m_id)
				break;
			else
				mySet->MoveNext();		
		}
		XGQX mydlg;
		mydlg.m_id=mySet->m_ID;
		if(mySet->m_AUTHOR=="管理员")
			glflag=true;
		else
			glflag=false;
		UpdateData(false);
		if(mydlg.DoModal()==IDOK)
		{ 	
			mySet->Edit();
			mySet->m_AUTHOR=mydlg.author;
			mySet->Update();
			UpdateData(false);
			LOADDATA();
			MessageBox("用户权限修改成功","提示",MB_OK|MB_ICONINFORMATION);
			COleDateTime oleDt=COleDateTime::GetCurrentTime();//获取本地的当前时间
			CString strFileName=oleDt.Format("%Y年%m月%d日 %H时%M分%S秒"); 
			CString strTmp=strFileName+"\r\n管理员 "+ID+" 修改用户名"+m_id+" 的权限为"+mydlg.author+"\r\n";
			CStdioFile file(logFileName,CFile::modeNoTruncate|CFile::modeWrite);
			file.SeekToEnd();//先定位到文件尾部
			file.WriteString(strTmp);
			file.Close();
			m_id="";
		}		
	}			
}

void GUANLI::OnDele() 
{
	CString str;
    int i=0;
    if(mySet->IsOpen())       //判断用户数据表是否为空
		mySet->Close();
	mySet->Open();
    while(!mySet->IsEOF())
	{
		mySet->MoveNext();
		i++;
	}
	if(i==0)
	{
		MessageBox("       程序错误无用户信息          ","家庭个人理财系统",MB_OK|MB_ICONINFORMATION);
	} 
	else
    {   
		mySet->MoveFirst();
		if(m_id=="")
			MessageBox("          请选择需要删除的用户                ","家庭个人理财系统",MB_OK|MB_ICONINFORMATION);
		else if(MessageBox("          确定删除此用户吗?                 ","是否删除",MB_YESNO|MB_ICONINFORMATION)==IDYES)
		{	
			while(!mySet->IsEOF())
		{  
				if(ID==m_id)
				{
					MessageBox("  当前管理员登陆帐号无法删除,请使用其他管理员权限进行删除   ","家庭个人理财系统",MB_OK|MB_ICONINFORMATION);
					LOADDATA();
					break;
				}
				if(mySet->m_ID!=m_id)
					mySet->MoveNext();
				else
				{
					str.Format("delete from password where ID='%s'",mySet->m_ID);     //SQL语句对ID为当前选中的用户信息删除
		            pdb->ExecuteSQL(str);
		            mySet->Requery();
	              	LOADDATA();
			    	MessageBox("          该用户被成功删除                 ","家庭个人理财系统",MB_OK|MB_ICONINFORMATION);
			        COleDateTime oleDt=COleDateTime::GetCurrentTime();//获取本地的当前时间
		         	CString strFileName=oleDt.Format("%Y年%m月%d日 %H时%M分%S秒");
          			CString strTmp=strFileName+"\r\n\n管理员 "+ID+" 删除用户名为 "+m_id+" 的用户   删除成功\r\n\n\n\n\n";
	           		CStdioFile file(logFileName,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);
        			file.SeekToEnd();//先定位到文件尾部
	        		file.WriteString(strTmp);
        			file.Close();
	         		m_id="";
			    	break;				
				}
			}
		}	
	}	
}
