// XGQX.cpp : implementation file
//

#include "stdafx.h"
#include "licai.h"
#include "XGQX.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// XGQX dialog


XGQX::XGQX(CWnd* pParent /*=NULL*/)
	: CDialog(XGQX::IDD, pParent)
{
	//{{AFX_DATA_INIT(XGQX)
	m_id = _T("");
	//}}AFX_DATA_INIT
}


void XGQX::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(XGQX)
	DDX_Control(pDX, IDC_COMBO1, m_author);
	DDX_Text(pDX, IDC_EDIT1, m_id);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(XGQX, CDialog)
	//{{AFX_MSG_MAP(XGQX)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// XGQX message handlers

BOOL XGQX::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_author.InsertString(0,"管理员");
    m_author.InsertString(1,"来宾");
	if(glflag)
	{
		m_author.SetCurSel(0);
		author="管理员";
	}
	else
	{
		m_author.SetCurSel(1);
		author="来宾";
	}
	return TRUE; 

}

void XGQX::OnOK() 
{
	int i;
	i=m_author.GetCurSel();
    m_author.GetLBText(i,author);	
	CDialog::OnOK();
}
