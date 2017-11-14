// RoadView.cpp : implementation file
//

#include "stdafx.h"
#include "MapPublic.h"
#include "RoadView.h"
#include "StationSet.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRoadView property page

IMPLEMENT_DYNCREATE(CRoadView, CPropertyPage)

CRoadView::CRoadView() : CPropertyPage(CRoadView::IDD)
{
	//{{AFX_DATA_INIT(CRoadView)
	m_id = _T("");
	m_show = _T("");
	//}}AFX_DATA_INIT
}

CRoadView::~CRoadView()
{
}

void CRoadView::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRoadView)
	DDX_Text(pDX, IDC_STATION_ID, m_id);
	DDX_Text(pDX, IDC_SHOW, m_show);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRoadView, CPropertyPage)
	//{{AFX_MSG_MAP(CRoadView)
	ON_BN_CLICKED(IDC_BUTTON, OnButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRoadView message handlers

void CRoadView::OnButton() 
{
	UpdateData(true);
	bool flag=false;
	m_show.Empty();
	CStationSet	m_pStationSet;
   m_pStationSet.Open();
   m_pStationSet.MoveFirst();
   while(!m_pStationSet.IsEOF())
   {
	   if(m_pStationSet.m_ID==m_id)
	   {
		   m_show+=m_pStationSet.m_STATION;
		   m_show+=" -> ";
		   flag=true;
	   }
	   m_pStationSet.MoveNext();
   }
  
   if(!flag)
   {
	   MessageBox("你输入的车次不正确！");
	   m_id.Empty();
	   CWnd *pwnd;
	   pwnd=GetDlgItem(IDC_STATION_ID);
	   pwnd->SetFocus();
	   
   }
    UpdateData(false);

}
