// SubjectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "gradudemis.h"
#include "SubjectDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSubjectDlg dialog


CSubjectDlg::CSubjectDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSubjectDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSubjectDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CSubjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSubjectDlg)
	DDX_Control(pDX, IDC_TAB1, m_Tab);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSubjectDlg, CDialog)
	//{{AFX_MSG_MAP(CSubjectDlg)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, OnSelchangeTab1)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSubjectDlg message handlers

BOOL CSubjectDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_pTab1Dlg= new CSubTab1Dlg();					//创建一个对话框的指针
	m_pTab2Dlg= new CSubTab2Dlg();
	m_pTab1Dlg->Create(IDD_SubTab1_DLG,&m_Tab);		//创建对话框
	m_pTab2Dlg->Create(IDD_SubTab2_DLG,&m_Tab);

	m_Tab.InsertItem(0,"课题信息查询",0);			//设定标签的标题
	m_Tab.InsertItem(1,"课题信息操作",1);
	DoTab(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSubjectDlg::OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int nSelect=m_Tab.GetCurSel();					//获取选定标签的索引
	if(nSelect>=0)									
		DoTab(nSelect);								//用户自定义函数，改变窗口状态

	*pResult = 0;
}

void CSubjectDlg::SetDlgState(CWnd *pWnd,BOOL bShow)
{
    pWnd->EnableWindow(bShow);						
	if(bShow)
	{
		pWnd->ShowWindow(SW_SHOW);					//显示窗口
		pWnd->CenterWindow();						//使窗口居中
		if(bTab[1])						
		   m_pTab2Dlg->MyShow();		
	}
	else pWnd->ShowWindow(SW_HIDE);					//隐藏窗口
}
void CSubjectDlg::DoTab(int nTab)
{
	if(nTab>1)nTab=1;								//边界的判断
	if(nTab<0)nTab=0;
	bTab[0]=bTab[1]=false;							//定义布尔变量设定初值
	bTab[nTab]=TRUE;								//让选中的为真
	SetDlgState(m_pTab1Dlg,bTab[0]);				//改变窗口的状态
	SetDlgState(m_pTab2Dlg,bTab[1]);
}

void CSubjectDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	if(m_pTab1Dlg) delete m_pTab1Dlg;				//释放窗口的指针
	if(m_pTab2Dlg) delete m_pTab2Dlg;
		
}
