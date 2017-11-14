// StaionWayView.cpp : implementation file
//

#include "stdafx.h"
#include "MapPublic.h"
#include "StaionWayView.h"
#include "BusSet.h"
#include "StationSet.h"
#include "MainFrm.h"
#include "MapPublicView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStaionWayView property page

IMPLEMENT_DYNCREATE(CStaionWayView, CPropertyPage)

CStaionWayView::CStaionWayView() : CPropertyPage(CStaionWayView::IDD)
{
	//{{AFX_DATA_INIT(CStaionWayView)
	m_station = _T("");
	//}}AFX_DATA_INIT
}

CStaionWayView::~CStaionWayView()
{
}

void CStaionWayView::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStaionWayView)
	DDX_Control(pDX, IDC_LIST2, m_list);
	DDX_Text(pDX, IDC_STATION, m_station);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStaionWayView, CPropertyPage)
	//{{AFX_MSG_MAP(CStaionWayView)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStaionWayView message handlers

BOOL CStaionWayView::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
    DWORD style=m_list.GetExtendedStyle();
	m_list.SetExtendedStyle(style|LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
  	m_list.InsertColumn(0,"车次",LVCFMT_LEFT,50);
	m_list.InsertColumn(1,"起始站",LVCFMT_LEFT,70);
	m_list.InsertColumn(2,"终点站",LVCFMT_LEFT,70);
	m_list.InsertColumn(3,"发车时间",LVCFMT_LEFT,70);
	m_list.InsertColumn(4,"停止时间",LVCFMT_LEFT,70);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CStaionWayView::OnButton1() 
{
   	UpdateData(true);
	int i=0;
	bool flag=false;
	CFont m_font;
	//***************************************
/*	m_font.CreateFont(16, 0,0,0,FW_NORMAL, 0,0,0,
                      DEFAULT_CHARSET, OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS,
                      DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "华文行楷");
    m_list.SetFont(&m_font);
	*/
   m_list.SetBkColor(RGB(247,247,255));
   m_list.SetTextColor(RGB(0,0,255));
	//*******************************************
	CString str,str1;
	m_list.DeleteAllItems();
	CBusSet m_pBusSet;
	CStationSet m_pStationSet;
	m_pBusSet.Open();
//	m_pBusSet.MoveFirst();
	m_pStationSet.Open();
	m_pStationSet.MoveFirst();
	while(!m_pStationSet.IsEOF())
	{
		if(m_station==m_pStationSet.m_STATION)
		{
			m_pBusSet.MoveFirst();
			while(!m_pBusSet.IsEOF())
			{
			   if(m_pStationSet.m_ID==m_pBusSet.m_ID_BUS)
			   {
				   m_list.InsertItem(i,m_pBusSet.m_ID_BUS);
				   m_list.SetItemText(i,1,m_pBusSet.m_BEGIN);
				   m_list.SetItemText(i,2,m_pBusSet.m_END);
                   m_list.SetItemText(i,3,m_pBusSet.m_AMTIME);
				   m_list.SetItemText(i,4,m_pBusSet.m_PMTIME);
				   flag=true;
				   i++;
    			   break;
			   }
			   else 
				   m_pBusSet.MoveNext();
			}
		}
	//	else
	    m_pStationSet.MoveNext();
		
	}
	m_pBusSet.Close();
    m_pStationSet.Close();
//---------------------------------------------------------
    CMainFrame *pFrame=(CMainFrame *)AfxGetMainWnd();
	CMapPublicView *pView=(CMapPublicView *)(pFrame->m_wndSplitter.GetPane(0,0));
	pView->FindArea(m_station);
  //  pView->require_attribute(m_station);
  //  CMapPublicApp *app=(CMapPublicApp *)AfxGetApp();
//	app->pitcure_name=m_station;
//----------------------------------------------------
	if(!flag)
		MessageBox("输入站点不存在!");
}
