// StudentDlg.cpp : implementation file
//

#include "stdafx.h"
#include "gradudemis.h"
#include "StudentDlg.h"
#include "StudentTab1.h"
#include "StudentTab2.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStudentDlg dialog


CStudentDlg::CStudentDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStudentDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStudentDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CStudentDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStudentDlg)
	DDX_Control(pDX, IDC_TAB1, m_Tab);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStudentDlg, CDialog)
	//{{AFX_MSG_MAP(CStudentDlg)
	ON_WM_DESTROY()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, OnSelchangeTab1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStudentDlg message handlers

void CStudentDlg::SetDlgState(CWnd *pWnd,BOOL bShow)
{
	pWnd->EnableWindow(bShow);				//窗口的隐藏与显示根据变量的值
	if(bShow)								//判断
	{
		pWnd->ShowWindow(SW_SHOW);			//显示点击标签关联的窗口
		pWnd->CenterWindow();				//窗口居中
		if(bTab[1])								
			m_pTab2Dlg->OnShow();			//显示窗口
	}
	else 
		pWnd->ShowWindow(SW_HIDE);			//隐藏窗口
}

void CStudentDlg::DoTab(int nTab)		
{
	if(nTab>1)nTab=1;						//边界的判断
	if(nTab<0)nTab=0;
	bTab[0]=bTab[1]=false;					//定义布尔变量初始值false
	bTab[nTab]=TRUE;						//点击哪个标签其为true
	SetDlgState(m_pTab1Dlg,bTab[0]);		//更改窗口的状态
	SetDlgState(m_pTab2Dlg,bTab[1]);		//更改窗口的状态
}

void CStudentDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	if(m_pTab1Dlg) delete m_pTab1Dlg;		//释放窗口的指针
	if(m_pTab2Dlg) delete m_pTab2Dlg;		//释放窗口的指针	
}

void CStudentDlg::OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int nSelect=m_Tab.GetCurSel();			//获取用户点击标签的索引号
	if (nSelect>=0)
		DoTab(nSelect);						//调用函数改变窗口状态
	*pResult = 0;
}
BOOL CStudentDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CStudentTab1 *p=(CStudentTab1 *)AfxGetApp();
	m_pTab1Dlg=new CStudentTab1();			//new一个对话框指针
	m_pTab2Dlg=new CStudentTab2();
	m_pTab1Dlg->Create(IDD_STU_DIALOG1,&m_Tab);//创建对话框
	m_pTab2Dlg->Create(IDD_STU_DIALOG2,&m_Tab);
	m_Tab.InsertItem(0,"学生信息查询",0);	//为标签插入标题
	m_Tab.InsertItem(1,"学生信息操作",1);
	m_Tab.SetMinTabWidth(80);				//设置标签的宽度
	m_Tab.SetPadding(CSize(6,2));			//设置尺寸
	m_Tab.SetCurSel(0);						//默认选中第一个标签
	DoTab(0);								//显示第一个标签惯量的窗口
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
