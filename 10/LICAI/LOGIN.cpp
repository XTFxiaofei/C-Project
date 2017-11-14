// LOGIN.cpp : implementation file
//

#include "stdafx.h"
#include "licai.h"
#include "LOGIN.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// LOGIN dialog


LOGIN::LOGIN(CWnd* pParent /*=NULL*/)
	: CDialog(LOGIN::IDD, pParent)
{
	//{{AFX_DATA_INIT(LOGIN)
	m_id = _T("");
	m_password = _T("");
	//}}AFX_DATA_INIT
}


void LOGIN::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(LOGIN)
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	DDX_Text(pDX, IDC_EDIT1, m_id);
	DDX_Text(pDX, IDC_EDIT2, m_password);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(LOGIN, CDialog)
	//{{AFX_MSG_MAP(LOGIN)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// LOGIN message handlers

BOOL LOGIN::OnInitDialog() 
{
	CDialog::OnInitDialog();
	MessageBox("说明：管理员帐号为hc密码123","家庭理财系统",MB_OK);
	m_combo.InsertString(0,"管理员");
    m_combo.InsertString(1,"来宾");
	if(loginflag)
	{	
		m_combo.SetCurSel(0);
		author="管理员";
	}	
	else
	{	
		m_combo.SetCurSel(1);
		author="来宾";
	}
	return TRUE;
}
void LOGIN::OnOK() 
{
	int i;
	i=m_combo.GetCurSel();
    m_combo.GetLBText(i,author);	
	CDialog::OnOK();
}
