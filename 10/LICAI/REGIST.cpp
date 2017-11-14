// REGIST.cpp : implementation file
//

#include "stdafx.h"
#include "licai.h"
#include "REGIST.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// REGIST dialog


REGIST::REGIST(CWnd* pParent /*=NULL*/)
	: CDialog(REGIST::IDD, pParent)
{
	//{{AFX_DATA_INIT(REGIST)
	m_id = _T("");
	m_password = _T("");
	m_npassword = _T("");
	//}}AFX_DATA_INIT
}


void REGIST::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(REGIST)
	DDX_Control(pDX, IDC_COMBO1, m_author);
	DDX_Text(pDX, IDC_EDIT1, m_id);
	DDX_Text(pDX, IDC_EDIT2, m_password);
	DDX_Text(pDX, IDC_EDIT3, m_npassword);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(REGIST, CDialog)
	//{{AFX_MSG_MAP(REGIST)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// REGIST message handlers

BOOL REGIST::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_author.InsertString(0,"管理员");
    m_author.InsertString(1,"来宾");	
	m_author.SetCurSel(0);
	author="管理员登陆";
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void REGIST::OnOK() 
{
	int i;
	i=m_author.GetCurSel();
    m_author.GetLBText(i,author);
	CDialog::OnOK();
}
