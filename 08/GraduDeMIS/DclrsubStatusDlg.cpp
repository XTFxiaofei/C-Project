// DclrsubStatusDlg.cpp : implementation file
//

#include "stdafx.h"
#include "gradudemis.h"
#include "DclrsubStatusDlg.h"
#include "TecrDclrSubDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CString strStuName;
/////////////////////////////////////////////////////////////////////////////
// CDclrsubStatusDlg dialog

CString strTecrSub[10];					//定义字符串数组

CDclrsubStatusDlg::CDclrsubStatusDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDclrsubStatusDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDclrsubStatusDlg)
	m_strDclrmax = _T("");
	m_strDclrnum = _T("");
	m_strComlevel = _T("");
	m_strForlanlevel = _T("");
	m_strSchship = _T("");
	//}}AFX_DATA_INIT
}


void CDclrsubStatusDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDclrsubStatusDlg)
	DDX_Control(pDX, IDC_ChoisubStu_LIST, m_ctrlStuName);
	DDX_Control(pDX, IDC_Ownsub_LIST, m_ctrlOwnsub);
	DDX_Text(pDX, IDC_DclrMaxNum_STATIC, m_strDclrmax);
	DDX_Text(pDX, IDC_DclrNum_STATIC, m_strDclrnum);
	DDX_Text(pDX, IDC_ComLevel_EDIT, m_strComlevel);
	DDX_Text(pDX, IDC_ForLanLevel_EDIT, m_strForlanlevel);
	DDX_Text(pDX, IDC_SchShip_EDIT, m_strSchship);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDclrsubStatusDlg, CDialog)
	//{{AFX_MSG_MAP(CDclrsubStatusDlg)
	ON_BN_CLICKED(IDC_DclrSub_BTN, OnDclrSubBTN)
	ON_NOTIFY(NM_CLICK, IDC_Ownsub_LIST, OnClickOwnsubLIST)
	ON_LBN_SELCHANGE(IDC_ChoisubStu_LIST, OnSelchangeChoisubStuLIST)
	ON_BN_CLICKED(IDC_ChoiStu_BTN, OnChoiStuBTN)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDclrsubStatusDlg message handlers

BOOL CDclrsubStatusDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();	
	// TODO: Add extra initialization here
    m_ctrlOwnsub.SetFocus();								//设置焦点
	int i=0;												//定义整形变量
	m_ctrlOwnsub.InsertColumn(0,"课题",LVCFMT_LEFT,350,0);	//设置列表控件的列标题信息
    if(!pTecrsubSet.IsOpen())								//打开记录集
		pTecrsubSet.Open();
	pTecrsubSet.MoveFirst();								//移动到首条记录
	while(!pTecrsubSet.IsEOF())								//遍历记录集
	{
		if(pTecrsubSet.m_tecr_name==strExternUser)			//判断条件
		{
			m_ctrlOwnsub.InsertItem(i,pTecrsubSet.m_sub_title);//插入数据到列表中
			strTecrSub[i]=pTecrsubSet.m_sub_title;			//字符数组的赋值
			i++;	
		}		
		pTecrsubSet.MoveNext();								//移动到下条记录
	}

	pTecrsubSet.Close();									//关闭记录集
	if(!pDclrsubSet.IsOpen())								//打开记录集
	   pDclrsubSet.Open();	
	pDclrsubSet.MoveFirst();								//移动到首条记录
	while(!pDclrsubSet.IsEOF())								//如果记录不是最后一条
	{
		if(pDclrsubSet.m_tecr_name==strExternUser)			//条件判断
		{
			m_strDclrmax=pDclrsubSet.m_tecr_MaxNum;			//变量赋值
			m_strDclrnum=pDclrsubSet.m_tecr_DclrNum;
			break; 
		}
		else
			pDclrsubSet.MoveNext();							//移动到下条记录
	}
	pDclrsubSet.Close();									//关闭记录集
    UpdateData(false);										//更新数据
	if(m_strDclrmax==m_strDclrnum)
	{
		CButton *pBtn=(CButton *)GetDlgItem(IDC_DclrSub_BTN);//获取控件的指针
		pBtn->ShowWindow(SW_HIDE);						   	//隐藏控件
	}
    return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDclrsubStatusDlg::OnDclrSubBTN() 
{
	// TODO: Add your control notification handler code here
	CTecrDclrSubDlg dlg;									//定义对话框变量
	dlg.DoModal();											//显示对话框
}


void CDclrsubStatusDlg::OnClickOwnsubLIST(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int i=0;												//定义整形变量
	int nIndex=m_ctrlStuName.GetCount();					//获取控件中数据的总数

    for(int j=0;j<nIndex;j++)								//删除所有
	{
		m_ctrlStuName.DeleteString(j);
	}
	CString strSubTitle;									//定义字符串变量
	NMLISTVIEW *pLV=(NMLISTVIEW *)pNMHDR;    //  str.Format("%d",pLV->iItem);
    strSubTitle=m_ctrlOwnsub.GetItemText(pLV->iItem,0);     //获取选中的列表的文本
    if(!pstusubSet.IsOpen())								//打开记录集
		pstusubSet.Open();
	pstusubSet.MoveFirst();								//移动到首条记录
    while(!pstusubSet.IsEOF())
	{
		if(pstusubSet.m_sub_Name==strSubTitle&&pstusubSet.m_stu_choisubStatus)//条件判断
		{	
			m_ctrlStuName.InsertString(0,pstusubSet.m_stu_name);//插入数据到列表框中
			break;			
		}
		else if(pstusubSet.m_sub_Name==strSubTitle)
		{
			m_ctrlStuName.InsertString(i,pstusubSet.m_stu_name);
			i++;
		}

		pstusubSet.MoveNext();								//移动到下条记录	
	}		
	pstusubSet.Close();										//关闭记录集
	*pResult = 0;
}

void CDclrsubStatusDlg::OnSelchangeChoisubStuLIST() 
{
	// TODO: Add your control notification handler code here
   	int nIndex=m_ctrlStuName.GetCurSel();					//获取用户选中的位置
   	m_ctrlStuName.GetText(nIndex,strStuName);				//得到选中的文本
	if(!pstuAchvSet.IsOpen())								//打开记录集
	  pstuAchvSet.Open();
	pstuAchvSet.MoveFirst();								//移动到首条记录
	while(!pstuAchvSet.IsEOF())								//记录没有到末尾
	{
		if(pstuAchvSet.m_stu_name==strStuName)				//条件判断
		{
			ACHIEVE stuAch;									//定义结构变量
			stuAch.comLevel=pstuAchvSet.m_comLevel;			//结构变量的赋值
			stuAch.forlanLevel=pstuAchvSet.m_forlanLevel;
			stuAch.schship=pstuAchvSet.m_schship;
			m_ctrlStuName.SetItemDataPtr(nIndex,new ACHIEVE(stuAch));//设置指针
			break;
		}
		else
			pstuAchvSet.MoveNext();							//移动到下条记录
	}
	pstuAchvSet.Close();									//关闭记录集
	if(nIndex!=LB_ERR)
	{	
		ACHIEVE *stuAch=(ACHIEVE*)m_ctrlStuName.GetItemDataPtr(nIndex);//获取信息
		m_strComlevel=stuAch->comLevel;						//将结构信息保存在变量中
		m_strForlanlevel=stuAch->forlanLevel;
		m_strSchship=stuAch->schship;
		UpdateData(false);									//更新数据
	}
}

void CDclrsubStatusDlg::OnChoiStuBTN() 
{
	// TODO: Add your control notification handler code here
     if(!pstusubSet.IsOpen())
		pstusubSet.Open();									//打开记录集		
	 pstusubSet.MoveFirst();								//移动到首条记录
     while(!pstusubSet.IsEOF())								//如果记录没有到末尾
	 {
		 if(pstusubSet.m_stu_name==strStuName)				//判断条件
		 {
			 if(MessageBox("是否选择此学生？","提示信息",MB_YESNO)==IDYES)//给出提示
			 {
				 pstusubSet.Edit();							//编辑记录
				 pstusubSet.m_stu_choisubStatus=true;		//记录赋值
				 pstusubSet.Update();						//更新数据
				 pstusubSet.Requery();						//刷新记录集
			 }
			 break;
		 }
		 else
		   pstusubSet.MoveNext();							//移动到下条记录
	 }
	 pstusubSet.Close();									//关闭记录集
}
