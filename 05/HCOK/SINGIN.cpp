// SINGIN.cpp : implementation file
//

#include "stdafx.h"
#include "HCOK.h"
#include "SINGIN.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// SINGIN dialog


SINGIN::SINGIN(CWnd* pParent /*=NULL*/)
	: CDialog(SINGIN::IDD, pParent)
{
	//{{AFX_DATA_INIT(SINGIN)
	//}}AFX_DATA_INIT
}


void SINGIN::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(SINGIN)
	DDX_Control(pDX, IDC_COMBO2, m_combo2);
	DDX_Control(pDX, IDC_COMBO1, m_combo1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(SINGIN, CDialog)
	//{{AFX_MSG_MAP(SINGIN)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// SINGIN message handlers

BOOL SINGIN::OnInitDialog() 
{
	CDialog::OnInitDialog();	
	//**************初始化****************//
    m_combo1.InsertString(0,"小包间");
	m_combo1.InsertString(1,"中包间");
	m_combo1.InsertString(2,"大包间");
	m_combo1.InsertString(3,"豪华包间");

    m_combo1.SetCurSel(0);
	m_combo2.InsertString(0,"非会员");
	m_combo2.InsertString(1,"一般会员");
	m_combo2.InsertString(2,"中级会员");
	m_combo2.InsertString(3,"高级会员");
	m_combo2.SetCurSel(0);
	(CEdit*)GetDlgItem(IDC_GIVENMONEY)->SetFocus();//设置焦点
	return false;
}

void SINGIN::OnOK() 
{			
	int k=m_combo1.GetCurSel();
	m_combo1.GetLBText(k,addroomtype);//得到房间类型
	int k2=m_combo2.GetCurSel();
	m_combo2.GetLBText(k2,addcardtype);//得到会员卡类型名
	GetDlgItem(IDC_GIVENMONEY)->GetWindowText(givenmoney);//得到格式名	
	CDialog::OnOK();
}
