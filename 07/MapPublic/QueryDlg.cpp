// QueryDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mappublic.h"
#include "QueryDlg.h"
#include "Action_Time_Set.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQueryDlg dialog


CQueryDlg::CQueryDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CQueryDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CQueryDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CQueryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CQueryDlg)
	DDX_Control(pDX, IDC_LIST1, m_list);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CQueryDlg, CDialog)
	//{{AFX_MSG_MAP(CQueryDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQueryDlg message handlers

BOOL CQueryDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
    DWORD style=m_list.GetExtendedStyle();
	m_list.SetExtendedStyle(style|LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
  	m_list.InsertColumn(0,"用户ID",LVCFMT_LEFT,80);
	m_list.InsertColumn(1,"用户操作",LVCFMT_LEFT,120);
	m_list.InsertColumn(2,"时间",LVCFMT_LEFT,180);
    m_list.SetBkColor(RGB(247,247,255));
   m_list.SetTextColor(RGB(0,0,255));
	CAction_Time_Set m_logSet;
   m_logSet.Open();
   m_logSet.MoveFirst();
   int i=0;
   CString strTime;
   while(!m_logSet.IsEOF())
   {
     m_list.InsertItem(i,m_logSet.m_USER_ID);
	 m_list.SetItemText(i,1,m_logSet.m_ACTION);
	 m_list.SetItemText(i,2,m_logSet.m_COME_LEAVE_TIME);
	 m_logSet.MoveNext();
	 i++;
   }
   m_logSet.Close();
   UpdateData(false);


	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
