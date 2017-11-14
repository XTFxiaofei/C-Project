// ShowEndDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mappublic.h"
#include "ShowEndDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShowEndDlg dialog


CShowEndDlg::CShowEndDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CShowEndDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CShowEndDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CShowEndDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CShowEndDlg)
	DDX_Control(pDX, IDC_STATIC1, m_sta);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CShowEndDlg, CDialog)
	//{{AFX_MSG_MAP(CShowEndDlg)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowEndDlg message handlers

BOOL CShowEndDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
    m_sta.SetTextColor(RGB(0,255,0));
	m_sta.SetBkColor(RGB(0,0,0));
	m_sta.SetTextXPos(18);
    m_sta.SetRollDirection(ROLL_UP); 
    m_sta.BeginRoll(1);	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CShowEndDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
    HBITMAP hbitmap; 
	hbitmap=::LoadBitmap(::AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BACKBMP));	
    HDC hMenDC=::CreateCompatibleDC(NULL);
	SelectObject(hMenDC,hbitmap);
	CRect rect;
	GetClientRect(rect);
	::BitBlt(dc.m_hDC,0,0,rect.right,rect.bottom,hMenDC,0,0,SRCCOPY);
	::DeleteDC(hMenDC);
	::DeleteObject(hbitmap);	
	// Do not call CDialog::OnPaint() for painting messages
}
