// FindDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MapPublic.h"
#include "FindDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFindDlg dialog


CFindDlg::CFindDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFindDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFindDlg)
	//}}AFX_DATA_INIT
}


void CFindDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFindDlg)
	DDX_Control(pDX, IDC_PROGRESS1, m_progress);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFindDlg, CDialog)
	//{{AFX_MSG_MAP(CFindDlg)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_MESS,OnMess)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFindDlg message handlers

BOOL CFindDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
//设置透明窗体
	SetWindowLong(this->GetSafeHwnd(),GWL_EXSTYLE,
	GetWindowLong(this->GetSafeHwnd(),GWL_EXSTYLE)^0x80000);
	HINSTANCE hInst = LoadLibrary("User32.DLL"); 
	if(hInst) 
	{	
		typedef bool (WINAPI *MYFUNC)(HWND,COLORREF,BYTE,DWORD);
		MYFUNC  fun=NULL;
		fun=(MYFUNC)GetProcAddress(hInst,"SetLayeredWindowAttributes");
		if(fun)
			fun(this->GetSafeHwnd(),0,200,2);
		FreeLibrary(hInst);
	}
 /*   	HCURSOR m_Cursor;
		m_Cursor=AfxGetApp()->LoadCursor(IDC_WAIT);
		::SetCursor(m_Cursor);
		*/
    m_progress.SetPos(0);
	m_progress.SetRange(0,100);
	m_progress.SetStep(2);
    SetTimer(1,1000,NULL);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CFindDlg::OnMess()//自定义消息
{/*
	temp=m_progress.StepIt();
	if(temp==100)
	{
	//	m_progress.SetPos(0);
		KillTimer(1);
		EndDialog(IDD_DIALOG_FIND);
	}
	*/

}

void CFindDlg::OnTimer(UINT nIDEvent) 
{
   	temp=m_progress.StepIt();
	if(temp==100)
	{
		KillTimer(1);
		EndDialog(IDD_DIALOG_FIND);
	}
	CDialog::OnTimer(nIDEvent);
}
