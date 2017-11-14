// ChoisubDlg.cpp : implementation file
//

#include "stdafx.h"
#include "gradudemis.h"
#include "ChoisubDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChoisubDlg dialog


CChoisubDlg::CChoisubDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChoisubDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChoisubDlg)
	m_QueSubVal = _T("");
	//}}AFX_DATA_INIT
}


void CChoisubDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChoisubDlg)
	DDX_Control(pDX, IDC_QuerySubEDIT, m_QueSubCtrl);
	DDX_Control(pDX, IDC_SubQuery_LIST, m_SubQueryList);
	DDX_Control(pDX, IDC_SubQuery_COMBO, m_SubQueryCombo);
	DDX_Text(pDX, IDC_QuerySubEDIT, m_QueSubVal);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CChoisubDlg, CDialog)
	//{{AFX_MSG_MAP(CChoisubDlg)
	ON_BN_CLICKED(IDC_QUERY_BTN, OnQueryBtn)
	ON_NOTIFY(NM_DBLCLK, IDC_SubQuery_LIST, OnDblclkSubQueryLIST)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChoisubDlg message handlers


BOOL CChoisubDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	// TODO: Add extra initialization here      
	m_SubQueryList.InsertColumn(0,"课题名",LVCFMT_LEFT,300,0);
	m_SubQueryList.InsertColumn(1,"导师",LVCFMT_LEFT,60,0);
	m_SubQueryList.InsertColumn(2,"课题类型",LVCFMT_LEFT,70,0);
	m_SubQueryList.InsertColumn(3,"课题简介",LVCFMT_LEFT,250,0);
	m_SubQueryList.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);//列表控件风格的设定整行选择网格
    int i=0;												//定义整形变量
	if(!psubSet.IsOpen())
    psubSet.Open();											//打开记录集
	psubSet.MoveFirst();									//移动到首条记录
	while(!psubSet.IsEOF())									//如果记录不是末尾
	{  
		m_SubQueryList.InsertItem(i,psubSet.m_sub_title);	//向列表控件中插入数据
		m_SubQueryList.SetItemText(i,1,psubSet.m_tecr_name);
		m_SubQueryList.SetItemText(i,2,psubSet.m_sub_type);
		m_SubQueryList.SetItemText(i,3,psubSet.m_sub_pro);
        psubSet.MoveNext();									//移动到下条记录
        i++;
	}	
	psubSet.Close();										//关闭记录集
    CString str[3]={"课题名","导师","课题类型"};			//定义字符串数组赋初值
	for(int j=0;j<3;j++)
		m_SubQueryCombo.InsertString(j,str[j]);				//将数组内容插入到下拉列表框中
	m_SubQueryCombo.SetCurSel(0);							//设定默认选择第一项
	UpdateData(false);										//更新数据
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void CChoisubDlg::OnQueryBtn() 
{
	// TODO: Add your control notification handler code here
	int nIndex=m_SubQueryCombo.GetCurSel();					//得到下拉列表框选中的索引
	switch(nIndex)	
	{
	   case 0:
		   SelectItem(0);  break;							//调用用户自定义函数	   
	   case 1:
		   SelectItem(1);  break; 
	   case 2:
		   SelectItem(2); break;
	   default:break;
	}    
}

void CChoisubDlg::SelectItem(int n)	
{  
	char filter[60];                                            //钉子字符数组
	CString str[3]={"tab_sub.sub_title='%s'","tab_sub.tecr_name='%s'","tab_sub.sub_type='%s'"};		
	CString strEdit;                                            //定义字符串
    UpdateData();												//更新数据
	psubSet.Open();												//打开记录集
	wsprintf(filter,str[n],m_QueSubVal);						//格式化字符
	psubSet.m_strFilter=filter;									//记录集赋值
	psubSet.Requery();											//刷新记录集
    m_QueSubCtrl.GetWindowText(strEdit);						//获取控件的文本
	if(strEdit=="")												//判断条件
	{
		MessageBox("查询条件为空，请输入关键词！");
		m_QueSubCtrl.SetFocus();								//设置焦点
		psubSet.Close();										//关闭记录集
		return;
	}
	else 
	{	
		if(psubSet.IsEOF())										//如果记录不是末尾
			AfxMessageBox("要查找的课题不存在！");
		else
		{
		  m_SubQueryList.DeleteAllItems();						//删除所有控件中的数据
		  int i=0;												//定义整形变量
		  while(!psubSet.IsEOF())								//如果记录不是末尾
		  {	
			m_SubQueryList.InsertItem(i,psubSet.m_sub_title);	//插入数据到列表控件中
			m_SubQueryList.SetItemText(i,1,psubSet.m_tecr_name);
			m_SubQueryList.SetItemText(i,2,psubSet.m_sub_type);
			m_SubQueryList.SetItemText(i,3,psubSet.m_sub_pro);
			psubSet.MoveNext();									//移动到下条记录
			i++;
		  }
		 UpdateData(false);										//更新数据
		}	
	   psubSet.Close();											//关闭记录集
	}
}

void CChoisubDlg::OnDblclkSubQueryLIST(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
   NMLISTVIEW *pLV=(NMLISTVIEW *)pNMHDR;
   CString strSubTitle;											//定义字符串
   strSubTitle=m_SubQueryList.GetItemText(pLV->iItem,0);		//获取用户选择的行
   if(MessageBox("每人只能选择一题，是否选择此题？","提示信息",MB_YESNO)==IDYES)
   {
	   pchoisubSet.Open();
	   pchoisubSet.AddNew();  									//添加新的记录
	   pchoisubSet.m_stu_name=strExternUser;					//新记录赋值
	   pchoisubSet.m_stu_choisubStatus=false;
	   pchoisubSet.m_sub_Name=strSubTitle;
	   pchoisubSet.Update();									//更新数据
	   pchoisubSet.Requery();									//刷新记录集
	   pchoisubSet.MoveLast();									//移动到末尾
	   pchoisubSet.Close();										//关闭记录集
       MessageBox("选题成功！","提示信息",MB_OK);				//消息提示
   }
   else
       return;
	*pResult = 0;
}

void CChoisubDlg::OnClose() 
{
	CDialog::OnClose();				//关闭对话框
}
