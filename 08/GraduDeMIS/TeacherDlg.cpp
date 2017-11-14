// TeacherDlg.cpp : implementation file
//

#include "stdafx.h"
#include "gradudemis.h"
#include "TeacherDlg.h"
#include "TeacherTab1.h"
#include "TeacherTab2.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTeacherDlg dialog


CTeacherDlg::CTeacherDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTeacherDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTeacherDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CTeacherDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTeacherDlg)
	DDX_Control(pDX, IDC_TEACHER_TAB, m_TeacherTab);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTeacherDlg, CDialog)
	//{{AFX_MSG_MAP(CTeacherDlg)
	ON_WM_DESTROY()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TEACHER_TAB, OnSelchangeTeacherTab)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTeacherDlg message handlers
BOOL CTeacherDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	// TODO: Add extra initialization here
	
	m_pTab1Dlg=new CTeacherTab1();					//定义对话框指针
	m_pTab2Dlg=new CTeacherTab2();
	
	m_pTab1Dlg->Create(IDD_TEACHER_DIALOG1,&m_TeacherTab);//创建对话框
	m_pTab2Dlg->Create(IDD_TEACHER_DIALOG2,&m_TeacherTab);

	m_TeacherTab.InsertItem(0,"教师信息查询",0);	//设定标签的标题
	m_TeacherTab.InsertItem(1,"教师信息操作",1);

	m_TeacherTab.SetMinTabWidth(80);				//设定标签的宽度
	m_TeacherTab.SetPadding(CSize(6,2));			//设定标签的尺寸
	m_TeacherTab.SetCurSel(0);

	DoTab(0);										//默认选定第一个标签
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CTeacherDlg::SetDlgState(CWnd *pWnd,BOOL bShow)
{
	pWnd->EnableWindow(bShow);
	if(bShow)
	{	
		pWnd->ShowWindow(SW_SHOW);					//显示窗口
		pWnd->CenterWindow();						//窗口居中
        if(bTab[1])
		m_pTab2Dlg->MyShow();	
	}
	else pWnd->ShowWindow(SW_HIDE);					//隐藏窗口
}

void CTeacherDlg::DoTab(int nTab)
{
	if(nTab>1)nTab=1;								//便捷的判断
	if(nTab<0)nTab=0;
	bTab[0]=bTab[1]=false;							//定义布尔变量并赋初值
	bTab[nTab]=TRUE;
	SetDlgState(m_pTab1Dlg,bTab[0]);				//设定窗口的状态
	SetDlgState(m_pTab2Dlg,bTab[1]);
 
}
void CTeacherDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	if(m_pTab1Dlg) delete m_pTab1Dlg;				//释放对话卡ungzhizhen
	if(m_pTab2Dlg) delete m_pTab2Dlg;
		
}

void CTeacherDlg::OnSelchangeTeacherTab(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int nSelect=m_TeacherTab.GetCurSel();			//获取用户选定标签的索引
	if (nSelect>=0)
		DoTab(nSelect);								//控制窗口的隐藏与显示

	*pResult = 0;
}

