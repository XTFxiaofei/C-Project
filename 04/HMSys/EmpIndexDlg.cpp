// EmpIndexDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hmsys.h"
#include "EmpIndexDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEmpIndexDlg dialog


CEmpIndexDlg::CEmpIndexDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEmpIndexDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEmpIndexDlg)
	m_strID = _T("");
	m_strName = _T("");
	//}}AFX_DATA_INIT
	m_nFlag = 0;
}


void CEmpIndexDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEmpIndexDlg)
	DDX_Control(pDX, IDC_RADIO1, m_Radio);
	DDX_Text(pDX, IDC_ID, m_strID);
	DDX_Text(pDX, IDC_NAME, m_strName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEmpIndexDlg, CDialog)
	//{{AFX_MSG_MAP(CEmpIndexDlg)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEmpIndexDlg message handlers

void CEmpIndexDlg::OnRadio1()
{
	m_nFlag = 1;
}

void CEmpIndexDlg::OnRadio2() 
{
	m_nFlag = 2;	
}

BOOL CEmpIndexDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_Radio.SetCheck(1);
	m_nFlag = 1;
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CEmpIndexDlg::OnOK() 
{
	UpdateData();
	if(m_nFlag == 1)
	{
		if(m_strID == "")
		{
			MessageBox("请输入查询条件");
			return ;
		}
	}
	if(m_nFlag == 2)
	{
		if(m_strName == "")
		{
			MessageBox("请输入查询条件");
			return ;
		}
	}
	CDialog::OnOK();
}

void CEmpIndexDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
		
	// Do not call CDialog::OnPaint() for painting messages
}
