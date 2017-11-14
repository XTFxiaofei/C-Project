// XSCJPX.cpp : implementation file
//

#include "stdafx.h"
#include "HCCP.h"
#include "XSCJPX.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// XSCJPX dialog


XSCJPX::XSCJPX(CWnd* pParent /*=NULL*/)
: CDialog(XSCJPX::IDD, pParent)
{
	//{{AFX_DATA_INIT(XSCJPX)
	// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void XSCJPX::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(XSCJPX)
	DDX_Control(pDX, IDC_YIJU, m_yiju);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(XSCJPX, CDialog)
//{{AFX_MSG_MAP(XSCJPX)
ON_BN_CLICKED(IDC_SORT, OnSort)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// XSCJPX message handlers

BOOL XSCJPX::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_yiju.SetCurSel(0);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void XSCJPX::OnSort() 
{
	UpdateData();
	if(nCount==4)
	{
		flag121=false;		
		int k=m_yiju.GetCurSel();
		m_yiju.GetLBText(k,temp);  //设置排序依据
		if(temp=="学号")
			temp="sno";
		else if(temp=="姓名")
			temp="sname";
		else if(temp=="成绩")
			temp="sgrade";
	}
	else
		AfxMessageBox("请选择学生成绩表!");
}
