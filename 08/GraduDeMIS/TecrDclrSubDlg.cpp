// TecrDclrSubDlg.cpp : implementation file
//

#include "stdafx.h"
#include "gradudemis.h"
#include "TecrDclrSubDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTecrDclrSubDlg dialog


CTecrDclrSubDlg::CTecrDclrSubDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTecrDclrSubDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTecrDclrSubDlg)
	m_SubDemandVal = _T("");
	m_SubProVal = _T("");
	m_SubTitleVal = _T("");
	m_TecrAsociVal = _T("");
	m_strSubType = _T("");
	//}}AFX_DATA_INIT
}

void CTecrDclrSubDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTecrDclrSubDlg)
	DDX_Control(pDX, IDC_SubKind_COMBO, m_SubTypeCtrl);
	DDX_Text(pDX, IDC_SubDemand_EDIT, m_SubDemandVal);
	DDX_Text(pDX, IDC_SubProEDIT, m_SubProVal);
	DDX_Text(pDX, IDC_SubTitle_EDIT, m_SubTitleVal);
	DDX_Text(pDX, IDC_TecrAsoci_EDIT, m_TecrAsociVal);
	DDX_CBString(pDX, IDC_SubKind_COMBO, m_strSubType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTecrDclrSubDlg, CDialog)
	//{{AFX_MSG_MAP(CTecrDclrSubDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTecrDclrSubDlg message handlers

BOOL CTecrDclrSubDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CString str[3]={"研究","应用研究","软件设计"};			//定义字符串数组，并初始化
	int nIndex;												//定义整形变量
	for(int i=0;i<3;i++)
	{
		nIndex=m_SubTypeCtrl.InsertString(i,str[i]);		//插入数据
	    m_SubTypeCtrl.SetItemData(nIndex,i);				
	}
	m_SubTypeCtrl.SetCurSel(0);								//设置默认选中
    CString strSubTitle;									//定义字符串变量
    if(!pchoisubSet.IsOpen())								//打开记录集
	  pchoisubSet.Open();
	pchoisubSet.MoveFirst();								//移动到首条记录 
	while(!pchoisubSet.IsEOF())								//如果记录不是最后一条
	{
		if(pchoisubSet.m_stu_name==strExternUser)
        {
			strSubTitle=pchoisubSet.m_sub_Name;				//变量赋值
			break;
		}
		else
			pchoisubSet.MoveNext();							//移动到下一条记录
	}
	pchoisubSet.Close();									//关闭记录集
	if(!psubSet.IsOpen())									//打开记录集
		psubSet.Open();
    psubSet.MoveFirst();									//移动到第一条记录
	while(!psubSet.IsEOF())									//如果记录不是最后一条
	{
		if(psubSet.m_sub_title==strSubTitle)
		{
     		m_strSubType=psubSet.m_sub_type;				//变量的赋值
			m_SubTitleVal=psubSet.m_sub_title;
			m_SubProVal=psubSet.m_sub_pro;
			m_SubDemandVal=psubSet.m_sub_demand;
			UpdateData(false);								//更新数据
			break;
		}
		else
			psubSet.MoveNext();								//移动到下条记录
	}
	psubSet.Close();										//关闭就路径
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CTecrDclrSubDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();											//更新数据
    psubSet.Open();											//打开记录集
 	int i=0;												//定义整形变量
	while(!psubSet.IsEOF())									//如果记录不是末尾
	{
		psubSet.MoveNext();									//向下移动
		i++;												//得到数据的总数
	}
	CString strSubID,strSubType;							//定义字符串变量
	strSubID.Format("%d",i+1);								//整形转化字符型
    strSubID="sub"+strSubID;					
  	psubSet.AddNew();										//添加新的记录	 
    psubSet.m_sub_title=m_SubTitleVal;						//新记录赋值
	m_SubTypeCtrl.GetWindowText(strSubType); 
    psubSet.m_sub_type=strSubType;
	if(strSubType=="请选择")
	{
		MessageBox("请选择课题类型！","提示信息",MB_OK);
		psubSet.Close();									//关闭记录集
		return;
	}
	psubSet.m_sub_demand=m_SubDemandVal;					//记录赋值	
	psubSet.m_sub_pro=m_SubProVal;
	CGraduDeMISApp *point=(CGraduDeMISApp *)AfxGetApp();	//获得应用类的指针
    ptecrSet.Open();										//打开记录集 
    ptecrSet.MoveFirst();									//移动到首条记录

	bool bDclrSubNumFlag=false;								//加标记
	int  DclrSubNum=0;										//定义整形变量
	while(!ptecrSet.IsEOF())								//如果记录没有到末尾
	{	
		if(ptecrSet.m_tecr_id==strExternUser)
		{		
			psubSet.m_tecr_name=ptecrSet.m_tecr_name;		//赋值
			break;
		}
		else
			ptecrSet.MoveNext();							//向下移动
	}
	ptecrSet.Close();										//关闭记录集
 	if(!psubSet.Update()||!psubSet.Requery())				//更新与刷新记录集
		MessageBox("课题表更新失败!");	
	else	
	{
		MessageBox("申报课题成功!","",MB_OK);	
		bDclrSubNumFlag=true;								//更改标记
	}
    psubSet.Close();										//关闭记录集
	CDialog::OnOK();										//关闭对话框
}
