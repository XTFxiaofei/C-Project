// StuChoiSubDlg.cpp : implementation file
//

#include "stdafx.h"
#include "gradudemis.h"
#include "StuChoiSubDlg.h"
#include "ChoiSubDlg.h"
#include "TecrDclrSubDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStuChoiSubDlg dialog

CStuChoiSubDlg::CStuChoiSubDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStuChoiSubDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStuChoiSubDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

void CStuChoiSubDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStuChoiSubDlg)
	DDX_Control(pDX, IDC_ChoiSub_LIST, m_ChoiSubList);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CStuChoiSubDlg, CDialog)
	//{{AFX_MSG_MAP(CStuChoiSubDlg)
	ON_BN_CLICKED(IDC_DclrSub_BTN, OnDclrSubBTN)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStuChoiSubDlg message handlers

BOOL CStuChoiSubDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();	
	// TODO: Add extra initialization here
	int i=0;									//定义整形变量
	m_ChoiSubList.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
												//列表控件风格的设定整行选择网格
	m_ChoiSubList.InsertColumn(0,"课题",LVCFMT_LEFT,270,0);//设置列标题，宽度，对齐方式
    m_ChoiSubList.InsertColumn(1,"类型",LVCFMT_LEFT,70,0);
	m_ChoiSubList.InsertColumn(2,"导师",LVCFMT_LEFT,60,0);
	m_ChoiSubList.InsertColumn(3,"学生",LVCFMT_LEFT,60,0);
    if(!pchoisubSet.IsOpen())
		pchoisubSet.Open();						//打开记录集
	pchoisubSet.MoveFirst();					//移动到首条
	if(!psubSet.IsOpen())						//打开记录集
		psubSet.Open();
	psubSet.MoveFirst();						//移动到首条
    while(!pchoisubSet.IsEOF())					//如果记录不是末尾
	{
//		if(pchoisubSet.m_stu_choisubStatus)
		{
			m_ChoiSubList.InsertItem(i,pchoisubSet.m_sub_Name);	//插入第一项数据到列表控件中
            m_ChoiSubList.SetItemText(i,3,pchoisubSet.m_stu_name); //插入数据到列表控件中
            
			while(!psubSet.IsEOF())				//如果记录没有到末尾
			{
				if(psubSet.m_sub_title==pchoisubSet.m_sub_Name)		//判断条件
				{
					m_ChoiSubList.SetItemText(i,1,psubSet.m_sub_type);//插入数据到列表控件中
					m_ChoiSubList.SetItemText(i,2,psubSet.m_tecr_name);
					break;
				}
				else
					psubSet.MoveNext();			//移动到下条记录
			}
			psubSet.MoveFirst();				//移动记录到第一条
		}
		pchoisubSet.MoveNext();					//移动到下条记录
	}
	pchoisubSet.Close();						//关闭记录集
	psubSet.Close();							//关闭记录集
    return TRUE;  // return TRUE unless you set the focus to a control
// EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CStuChoiSubDlg::DestroyWindow() 
{
	// TODO: Add your specialized code here and/or call the base class	
	return CDialog::DestroyWindow();		//销毁窗口
}

void CStuChoiSubDlg::OnDclrSubBTN() 
{
	// TODO: Add your control notification handler code here
	OnCancel();								//退出
	CTecrDclrSubDlg dlg;					//定义对话框对象
	dlg.DoModal();							//显示对话框
}
