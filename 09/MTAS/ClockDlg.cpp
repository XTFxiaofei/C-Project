// ClockDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mtas.h"
#include "ClockDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClockDlg dialog


CClockDlg::CClockDlg(CWnd* pParent /*=NULL*/)
	: CNewDialog(CClockDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CClockDlg)
	//}}AFX_DATA_INIT
}


void CClockDlg::DoDataExchange(CDataExchange* pDX)
{
	CNewDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CClockDlg)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CClockDlg, CNewDialog)
	//{{AFX_MSG_MAP(CClockDlg)
	ON_COMMAND(ID_VIEW_CLOCK, OnViewClock)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_NCHITTEST ()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClockDlg message handlers

void CClockDlg::OnOK() 
{
}

BOOL CClockDlg::OnInitDialog() 
{
	CNewDialog::OnInitDialog();
	
	// Create the clock
	m_Clock.SubclassDlgItem(IDC_CLOCKFRAME, this);
	m_Clock.Start(IDB_CLOCKST_PANE, IDB_CLOCKST_BIG, IDB_CLOCKST_SMALL);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CClockDlg::OnViewClock() 
{
	// TODO: Add your command handler code here
	
}

UINT CClockDlg::OnNcHitTest (CPoint point)
{
    UINT nHitTest = CNewDialog::OnNcHitTest (point);
    if (nHitTest == HTCLIENT)
        nHitTest = HTCAPTION;

    return nHitTest;
}
