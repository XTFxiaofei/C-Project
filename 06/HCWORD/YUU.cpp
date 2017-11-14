// YUU.cpp : implementation file
//

#include "stdafx.h"
#include "HCWORD.h"
#include "YUU.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// YUU dialog


YUU::YUU(CWnd* pParent /*=NULL*/)
	: CDialog(YUU::IDD, pParent)
{
	//{{AFX_DATA_INIT(YUU)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void YUU::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(YUU)
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_TREE1, m_tree);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(YUU, CDialog)
	//{{AFX_MSG_MAP(YUU)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, OnSelchangedTree1)
	ON_WM_TIMER()
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// YUU message handlers


BOOL YUU::OnInitDialog() 
{
	CDialog::OnInitDialog();
    CRect dlgRect;
	GetWindowRect(dlgRect);
	CRect desktopRect;
	//将窗口开始大小设为0
	GetDesktopWindow()->GetWindowRect(desktopRect);
	MoveWindow((desktopRect.Width() - dlgRect.Width()) / 2,
	(desktopRect.Height() - dlgRect.Height()) / 2,0,0 );
	//初始化变化大小
	m_nWidth=dlgRect.Width();
	m_nHeight=dlgRect.Height();
	m_nDx=6;
	m_nDy=6;
	m_nDx1=6;
	m_nDy1=6;                                                            //设定定时器1	
	SetTimer(1,10,NULL);
    m_theImageList.Create(IDB_BITMAP11,16,1,RGB(0,255,0));       //创建图像列表
	m_tree.SetImageList(&m_theImageList,TVSIL_NORMAL);          //树形控件载入位图
	CString userTreeHeader[3]={"语法知识","中外机构","英语沙龙"};
	HTREEITEM userItem[3];                                      //树形控件的根项
	for(int i=0;i<3;i++)
	{
		userItem[i]=m_tree.InsertItem(userTreeHeader[i],0,0,TVI_ROOT);//插入父项
		m_tree.SetItemData(userItem[i],(DWORD)(i+10));          //给父项设值
	}
	HTREEITEM thePoint;
	HTREEITEM userSpecifics=m_tree.InsertItem("不规则动词表",2,2,userItem[0]);//父项1插入子项
	m_tree.SetItemData(userSpecifics,(DWORD)0);                //子项赋值0
	thePoint=userSpecifics;
	userSpecifics=m_tree.InsertItem("数词总表",3,3,userItem[0]);//父项1插入子项
	m_tree.SetItemData(userSpecifics,(DWORD)1);                //子项赋值1
	userSpecifics=m_tree.InsertItem("本词典缩略语",3,3,userItem[0]);//父项1插入子项
	m_tree.SetItemData(userSpecifics,(DWORD)2);                //子项赋值2
	userSpecifics=m_tree.InsertItem("联合国主要机构",3,3,userItem[1]);//父项2插入子项
	m_tree.SetItemData(userSpecifics,(DWORD)3);               //子项赋值3
	userSpecifics=m_tree.InsertItem("中国机构",3,3,userItem[1]);//父项2插入子项
	m_tree.SetItemData(userSpecifics,(DWORD)4);                //子项赋值4
	userSpecifics=m_tree.InsertItem("日常习语",3,3,userItem[2]);//父项3插入子项
	m_tree.SetItemData(userSpecifics,(DWORD)5);                 //子项赋值5
	userSpecifics=m_tree.InsertItem("奥运英语",3,3,userItem[2]);//父项3插入子项
	return TRUE;

}
void YUU::OnSelchangedTree1(NMHDR* pNMHDR, LRESULT* pResult) 
{	
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
   	HTREEITEM SelItem;
	SelItem=m_tree.GetSelectedItem();                          //获取选中的子项
	DWORD m;
	m=m_tree.GetItemData(SelItem);                             //读取子项的值
	switch (m)
	{	
	case 0:
		{	                                               //列表视的表头
			for(int i=0;i<3;i++)
			{
				m_list.DeleteColumn(i);                         //插入表头标题
			}
			for(int j=0;j<3;j++)
			{
				m_list.InsertColumn(j,"",LVCFMT_LEFT,220);     //插入表头标题
			}
			m_list.DeleteColumn(3);
			pdb=new CDatabase;
            pdb->Open("ODBC;DSN=词库;Trusted_Connection=Yes");
            m_pset=new ZLSet(pdb);
			m_pset->Open();	
			m_tree.SetItemImage(activeItem,3,3);               //先前活动子项更改图标
			m_tree.SetItemImage(activeparentItem,0,0);           //先前活动父项更改图标
			m_tree.SetItemImage(SelItem,2,2);                     //当前活动子项更改图标
			HTREEITEM Itemparent;
			Itemparent=m_tree.GetNextItem( SelItem, TVGN_PARENT);//获取当前子项的父项
			m_tree.SetItemImage(Itemparent,1,1);                 //当前活动父项更改图标
			activeItem=SelItem;
			activeparentItem=Itemparent;
            CString str;
			m_list.DeleteAllItems();
			str="不规则动词表:";
			m_list.InsertItem(0,str);
			m_list.SetItemText(0,1,"");
			m_list.SetItemText(0,2,"");
			int k=1;
			while(!m_pset->IsEOF())
			{		  
				m_pset->m_piezi.TrimRight();
				m_pset->m_baozi.TrimRight();
				m_pset->m_guoqing.TrimRight();
				m_list.InsertItem(k,m_pset->m_piezi);
				m_list.SetItemText(k,1,m_pset->m_baozi);
				m_list.SetItemText(k,2,m_pset->m_guoqing);
				k++;
				m_pset->MoveNext();
			}
			m_pset->Close();
            break;
		}
	case 1:
		{	
			CString Field[3]={"","",""};                         //列表视的表头
			for(int i=0;i<3;i++)
			{
				m_list.DeleteColumn(i);                             //插入表头标题
			}
			for(int j=0;j<3;j++)
			{
				m_list.InsertColumn(j,Field[j],LVCFMT_LEFT,300);     //插入表头标题
			}
			m_list.DeleteColumn(2);
			m_list.DeleteColumn(3);
			m_list.DeleteColumn(4);
			pdb=new CDatabase;
            pdb->Open("ODBC;DSN=词库;Trusted_Connection=Yes");
            m_pset=new ZLSet(pdb);
			m_pset->Open();	
			m_tree.SetItemImage(activeItem,3,3);                   //先前活动子项更改图标
			m_tree.SetItemImage(activeparentItem,0,0);            //先前活动父项更改图标
			m_tree.SetItemImage(SelItem,2,2);                     //当前活动子项更改图标
			HTREEITEM Itemparent;
			Itemparent=m_tree.GetNextItem( SelItem, TVGN_PARENT);//获取当前子项的父项
			m_tree.SetItemImage(Itemparent,1,1);                 //当前活动父项更改图标
			activeItem=SelItem;
			activeparentItem=Itemparent;
			CString str;
			m_list.DeleteAllItems();
			str="本词典缩略语:";
			m_list.InsertItem(0,str);
			m_list.SetItemText(0,1,"");
			m_list.SetItemText(0,2,"");
			m_list.SetItemText(0,3,"");
			int k=1;
			while(!m_pset->IsEOF())
			{		  
				m_pset->m_dian.TrimRight();
				m_pset->m_hua.TrimRight();
				m_list.InsertItem(k,m_pset->m_dian);
				m_list.SetItemText(k,1,m_pset->m_hua);
				k++;
				m_pset->MoveNext();
			}
			m_pset->Close();
			
			break;
		}
	case 2:
		{	
			CString Field[4]={"","","",""};                          //列表视的表头
			for(int i=0;i<4;i++)
			{
				m_list.DeleteColumn(i);                            //插入表头标题
			}
			for(int j=0;j<4;j++)
			{
				m_list.InsertColumn(j,Field[j],LVCFMT_LEFT,170);   //插入表头标题
			}
			m_list.DeleteColumn(4);
            pdb=new CDatabase;
            pdb->Open("ODBC;DSN=词库;Trusted_Connection=Yes");
            m_pset=new ZLSet(pdb);
			m_pset->Open();	
			m_tree.SetItemImage(activeItem,3,3);                 //先前活动子项更改图标
			m_tree.SetItemImage(activeparentItem,0,0);            //先前活动父项更改图标
			m_tree.SetItemImage(SelItem,2,2);                     //当前活动子项更改图标
			HTREEITEM Itemparent;
			Itemparent=m_tree.GetNextItem( SelItem, TVGN_PARENT);//获取当前子项的父项
			m_tree.SetItemImage(Itemparent,1,1);                 //当前活动父项更改图标
			activeItem=SelItem;
			activeparentItem=Itemparent;
			CString str;
			m_list.DeleteAllItems();
			str="本词典缩略语:";
			m_list.InsertItem(0,str);
			m_list.SetItemText(0,1,"");
			m_list.SetItemText(0,2,"");
			m_list.SetItemText(0,3,"");
			int k=1;
			while(!m_pset->IsEOF())
			{		  
				m_pset->m_w1.TrimRight();
				m_pset->m_w2.TrimRight();
				m_pset->m_w3.TrimRight();
				m_pset->m_w4.TrimRight();
				m_list.InsertItem(k,m_pset->m_w1);
				m_list.SetItemText(k,1,m_pset->m_w2);
				m_list.SetItemText(k,2,m_pset->m_w3);
				m_list.SetItemText(k,3,m_pset->m_w4);
				k++;
				m_pset->MoveNext();
			}
			m_pset->Close();
			
			break;
		}
	case 3:
		{	
			CString Field[4]={"","","",""};                       //列表视的表头
			for(int i=0;i<4;i++)
			{
				m_list.DeleteColumn(i);                            //插入表头标题
			}
			for(int j=0;j<4;j++)
			{
				m_list.InsertColumn(j,Field[j],LVCFMT_LEFT,200);   //插入表头标题
			}
			m_list.DeleteColumn(4);
			m_list.DeleteColumn(5);
			m_list.DeleteColumn(6);
			pdb=new CDatabase;
            pdb->Open("ODBC;DSN=词库;Trusted_Connection=Yes");
            m_pset=new ZLSet(pdb);
			m_pset->Open();	
			m_tree.SetItemImage(activeItem,3,3);                   //先前活动子项更改图标
			m_tree.SetItemImage(activeparentItem,0,0);            //先前活动父项更改图标
			m_tree.SetItemImage(SelItem,2,2);                     //当前活动子项更改图标
			HTREEITEM Itemparent;
			Itemparent=m_tree.GetNextItem( SelItem, TVGN_PARENT);//获取当前子项的父项
			m_tree.SetItemImage(Itemparent,1,1);                 //当前活动父项更改图标
			activeItem=SelItem;
			activeparentItem=Itemparent;
			CString str;
			m_list.DeleteAllItems();
			str="联合国主要机构:";
			m_list.InsertItem(0,str);
			m_list.SetItemText(0,1,"");
			m_list.SetItemText(0,2,"");
			m_list.SetItemText(0,3,"");
			int k=1;
			while(!m_pset->IsEOF())
			{		  
				m_pset->m_j3.TrimRight();
				m_pset->m_j4.TrimRight();
				m_pset->m_j5.TrimRight();
				m_pset->m_j6.TrimRight();
				
				m_list.InsertItem(k,m_pset->m_j3);
				m_list.SetItemText(k,1,m_pset->m_j4);
				m_list.SetItemText(k,2,m_pset->m_j5);
				m_list.SetItemText(k,3,m_pset->m_j6);
				
				
				k++;
				m_pset->MoveNext();
			}
			m_pset->Close();
			break;
		}
	case 4:
		{	CString Field[2]={"",""};                        //列表视的表头
		for(int i=0;i<2;i++)
		{
			m_list.DeleteColumn(i);                        //插入表头标题
		}
		for(int j=0;j<2;j++)
		{
			m_list.InsertColumn(j,Field[j],LVCFMT_LEFT,340);//插入表头标题
		}
		m_list.DeleteColumn(2);
		m_list.DeleteColumn(3);
		m_list.DeleteColumn(4);
		pdb=new CDatabase;
		pdb->Open("ODBC;DSN=词库;Trusted_Connection=Yes");
		m_pset=new ZLSet(pdb);
		m_pset->Open();	
		m_tree.SetItemImage(activeItem,3,3);                //先前活动子项更改图标
		m_tree.SetItemImage(activeparentItem,0,0);          //先前活动父项更改图标
		m_tree.SetItemImage(SelItem,2,2);                   //当前活动子项更改图标
		HTREEITEM Itemparent;
		Itemparent=m_tree.GetNextItem( SelItem, TVGN_PARENT);//获取当前子项的父项
		m_tree.SetItemImage(Itemparent,1,1);               //当前活动父项更改图标
		activeItem=SelItem;
		activeparentItem=Itemparent;
		CString str;
		m_list.DeleteAllItems();
		str="全国人民代表大会:";
		m_list.InsertItem(0,str);
		m_list.SetItemText(0,1,"");
		int k=1;
		while(!m_pset->IsEOF())
		{		  
			m_pset->m_j1.TrimRight();
			m_pset->m_j2.TrimRight();
			m_list.InsertItem(k,m_pset->m_j1);
            m_list.SetItemText(k,1,m_pset->m_j2);
            
            k++;
            m_pset->MoveNext();
		}
		m_pset->Close();
		break;
		}
	case 5:
		
		{	CString Field[1]={""};                               //列表视的表头
		for(int i=0;i<1;i++)
		{
			m_list.DeleteColumn(i);                            //插入表头标题
		}
		for(int j=0;j<1;j++)
		{
			m_list.InsertColumn(j,Field[j],LVCFMT_LEFT,650);  //插入表头标题
		}
		m_list.DeleteColumn(1);
		pdb=new CDatabase;
		pdb->Open("ODBC;DSN=词库;Trusted_Connection=Yes");
		m_pset=new ZLSet(pdb);
		m_pset->Open();	
		m_tree.SetItemImage(activeItem,3,3);                 //先前活动子项更改图标
		m_tree.SetItemImage(activeparentItem,0,0);           //先前活动父项更改图标
		m_tree.SetItemImage(SelItem,2,2);                    //当前活动子项更改图标
		HTREEITEM Itemparent;
		Itemparent=m_tree.GetNextItem( SelItem, TVGN_PARENT);//获取当前子项的父项
		m_tree.SetItemImage(Itemparent,1,1);                 //当前活动父项更改图标
		activeItem=SelItem;
		activeparentItem=Itemparent;
		CString str;
		m_list.DeleteAllItems();
		str="日常习语:";
		m_list.InsertItem(0,str);
		
		int k=1;
		while(!m_pset->IsEOF())
		{		  
			m_pset->m_j7.TrimRight();
			
			m_list.InsertItem(k,m_pset->m_j7);
			
            
            k++;
            m_pset->MoveNext();
		}
		m_pset->Close();
		break;
		}
	case 6:
		{	CString Field[2]={"",""};                          //列表视的表头
		for(int i=0;i<2;i++)
		{
			m_list.DeleteColumn(i);                         //插入表头标题
		}
		for(int j=0;j<2;j++)
		{
			m_list.InsertColumn(j,Field[j],LVCFMT_LEFT,320);//插入表头标题
		}
		pdb=new CDatabase;
		pdb->Open("ODBC;DSN=词库;Trusted_Connection=Yes");
		m_pset=new ZLSet(pdb);
		m_pset->Open();
		m_tree.SetItemImage(activeItem,3,3);               //先前活动子项更改图标
		m_tree.SetItemImage(activeparentItem,0,0);         //先前活动父项更改图标
		m_tree.SetItemImage(SelItem,2,2);                  //当前活动子项更改图标
		HTREEITEM Itemparent;
		Itemparent=m_tree.GetNextItem( SelItem, TVGN_PARENT);//获取当前子项的父项
		m_tree.SetItemImage(Itemparent,1,1);                 //当前活动父项更改图标
		activeItem=SelItem;
		activeparentItem=Itemparent;
		CString str;
		m_list.DeleteAllItems();
		str="奥运英语:";
		m_list.InsertItem(0,str);
		m_list.SetItemText(0,1,"");
		int k=1;
		while(!m_pset->IsEOF())
		{		  
			m_pset->m_j8.TrimRight();
			m_pset->m_j9.TrimRight();
			m_list.InsertItem(k,m_pset->m_j8);
            m_list.SetItemText(k,1,m_pset->m_j9);
            
            k++;
            m_pset->MoveNext();
		}
		m_pset->Close();
		break;
		break;
		}
	}
	*pResult = 0;
}

void YUU::OnTimer(UINT nIDEvent) 
{                                                                      
	CRect dlgRect;
	GetWindowRect(dlgRect);//获得此时窗口的实际大小
	CRect desktopRect;
	GetDesktopWindow()->GetWindowRect(desktopRect);//获得桌面的大小
	if(nIDEvent == 1)//如果是窗口弹出过程，则逐渐增大窗口
	{
		MoveWindow((-m_nDx+desktopRect.Width() - dlgRect.Width()) / 2,
			(-m_nDy+desktopRect.Height() - dlgRect.Height()) / 2, 
		+m_nDx+dlgRect.Width(),+m_nDy+dlgRect.Height() );
		if(dlgRect.Width() >=m_nWidth)//不要超过窗口预设的宽度 
			m_nDx=0; 
		if(dlgRect.Height() >=m_nHeight)//不要超过窗口预设的高度
			m_nDy=0;
		if((dlgRect.Width() >=m_nWidth) && (dlgRect.Height() >=m_nHeight))
			KillTimer(1);//停止变化，关闭定时器1 
	}
	if((dlgRect.Width() >=m_nWidth) && (dlgRect.Height() >=m_nHeight))
		KillTimer(1);//停止变化，关闭定时器1 
	if(nIDEvent == 2)//如果是窗口关闭过程，则逐渐缩小窗口
	{
		MoveWindow((+m_nDx+desktopRect.Width() - dlgRect.Width()) / 2,
                   (+m_nDy+desktopRect.Height() - dlgRect.Height()) / 2,
		        	-m_nDx1+dlgRect.Width(),-m_nDy1+dlgRect.Height() );
		if(dlgRect.Width() <= 0)//当宽度等于零后宽度就不在变化 
			m_nDx1=0;
		if(dlgRect.Height() <= 0 )//当高度等于零后高度就不在变化
			m_nDy1=0; 
		if((dlgRect.Width() <= 0 ) && (dlgRect.Height() <=0))//停止变化，关闭定时器2，并且关闭窗口
		{
			KillTimer(2);
			CDialog::OnOK();
		}	
	}	
	CDialog::OnTimer(nIDEvent);
}

void YUU::OnClose() 
{
	SetTimer(2,100,NULL);
	
	CDialog::OnClose();
}
