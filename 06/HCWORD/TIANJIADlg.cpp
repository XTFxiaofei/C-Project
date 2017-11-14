// TIANJIADlg.cpp : implementation file
//

#include "stdafx.h"
#include "HCWORD.h"
#include "TIANJIADlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// TIANJIADlg dialog


TIANJIADlg::TIANJIADlg(CWnd* pParent /*=NULL*/)
	: CDialog(TIANJIADlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(TIANJIADlg)
	m_1 = _T("");
	m_3 = _T("");
	//}}AFX_DATA_INIT
	addflag=false;
}


void TIANJIADlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(TIANJIADlg)
	DDX_Control(pDX, IDC_EDIT1, m_word);
	DDX_Text(pDX, IDC_EDIT1, m_1);
	DDX_Text(pDX, IDC_EDIT3, m_3);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(TIANJIADlg, CDialog)
	//{{AFX_MSG_MAP(TIANJIADlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// TIANJIADlg message handlers

BOOL TIANJIADlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	if(addflag)
	{
		m_word.SetReadOnly(false);
		SetWindowText("添加界面");
	}
	else
	{
		m_word.SetReadOnly(true);
		SetWindowText("修改界面");
	}
	return TRUE;
}

void TIANJIADlg::OnButton1() 
{
	CDialog::OnOK();	
}
