// BANZGHU.cpp : implementation file
//

#include "stdafx.h"
#include "HCWORD.h"
#include "BANZGHU.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// BANZGHU dialog


BANZGHU::BANZGHU(CWnd* pParent /*=NULL*/)
	: CDialog(BANZGHU::IDD, pParent)
{
	//{{AFX_DATA_INIT(BANZGHU)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void BANZGHU::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(BANZGHU)
	DDX_Control(pDX, IDC_EXPLORER1, m_browser);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(BANZGHU, CDialog)
	//{{AFX_MSG_MAP(BANZGHU)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// BANZGHU message handlers

BOOL BANZGHU::OnInitDialog() 
{
	CDialog::OnInitDialog();
	//ShowWindow(SW_SHOWMAXIMIZED);
	TCHAR szPath[MAX_PATH];
	::GetModuleFileName(NULL,szPath,sizeof(szPath)/sizeof(TCHAR));//为szPath分配存储空间
	CString string=szPath;                                        //定义字符串变量
	int nIndex=string.ReverseFind(_T('\\'));
	ASSERT(nIndex!=-1);
	string=string.Left(nIndex+1)+_T("index.htm");                 //为变量赋值
	m_browser.Navigate(string,NULL,NULL,NULL,NULL);                   
	CString string1="www.iciba.com";
    m_browser.Navigate(string1,NULL,NULL,NULL,NULL);              //连接网页
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
