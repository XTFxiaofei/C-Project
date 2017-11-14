// OverTimeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hmsys.h"
#include "OverTimeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COverTimeDlg dialog


COverTimeDlg::COverTimeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COverTimeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(COverTimeDlg)
	m_nHour = 0;
	//}}AFX_DATA_INIT
	m_nType = 0;
}


void COverTimeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COverTimeDlg)
	DDX_Control(pDX, IDC_COMBO1, m_Type);
	DDX_Text(pDX, IDC_TIME, m_nHour);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COverTimeDlg, CDialog)
	//{{AFX_MSG_MAP(COverTimeDlg)
	ON_CBN_EDITCHANGE(IDC_COMBO1, OnEditchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COverTimeDlg message handlers

BOOL COverTimeDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_Type.SetCurSel(0);	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void COverTimeDlg::OnEditchangeCombo1() 
{
	m_nType = m_Type.GetCurSel();	
}

void COverTimeDlg::OnSelchangeCombo1() 
{
	m_nType = m_Type.GetCurSel();
}
