// AddOneRoadway.cpp : implementation file
//

#include "stdafx.h"
#include "MapPublic.h"
#include "AddOneRoadway.h"
#include "StationSet.h"
#include "BusSet.h"
#include "Action_Time_Set.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// AddOneRoadway dialog


AddOneRoadway::AddOneRoadway(CWnd* pParent /*=NULL*/)
: CDialog(AddOneRoadway::IDD, pParent)
{
	firstflag=false;
	stationflag=false;
	//{{AFX_DATA_INIT(AddOneRoadway)
	m_roadway = _T("");
	m_sendtime = _T("");
	m_startstation = _T("");
	m_station = _T("");
	m_stoptime = _T("");
	m_endstation = _T("");
	//}}AFX_DATA_INIT
	addroadflag=false;
}


void AddOneRoadway::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(AddOneRoadway)
	DDX_Control(pDX, IDOK, m_quit);
	DDX_Control(pDX, ID_OK, m_ok);
	DDX_Text(pDX, IDC_EDIT_ROADWAY, m_roadway);
	DDX_Text(pDX, IDC_EDIT_SEND, m_sendtime);
	DDX_Text(pDX, IDC_EDIT_START, m_startstation);
	DDX_Text(pDX, IDC_EDIT_STATION, m_station);
	DDX_Text(pDX, IDC_EDIT_STOP, m_stoptime);
	DDX_Text(pDX, IDC_EDIT_END, m_endstation);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(AddOneRoadway, CDialog)
//{{AFX_MSG_MAP(AddOneRoadway)
ON_BN_CLICKED(ID_OK, OnOk)
ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// AddOneRoadway message handlers

void AddOneRoadway::OnOk() 
{
	UpdateData(true);
	//	bool flagFocus=false;
	if(!firstflag)
	{
		if(m_roadway!=""&&m_station!=""&&m_startstation!=""&&m_endstation!=""&&m_sendtime!=""&&m_stoptime!="")
		{
			//	flagFocus=!flagFocus;
			stationflag=!stationflag;
			CBusSet m_busset;
			if(!m_busset.IsOpen())
				m_busset.Open();
			m_busset.AddNew();
			m_busset.m_ID_BUS=m_roadway;
			m_busset.m_BEGIN=m_startstation;
			m_busset.m_END=m_endstation;
			m_busset.m_AMTIME=m_sendtime;
			m_busset.m_PMTIME=m_stoptime;
			m_busset.Update();
			m_busset.Requery();
			m_busset.Close();
			
			CStationSet m_StationSet;
			if(!m_StationSet.IsOpen())
				m_StationSet.Open();
			m_StationSet.AddNew();
			m_StationSet.m_ID=m_roadway;
			m_StationSet.m_STATION=m_station;
			m_StationSet.Update();
			m_StationSet.Requery();
			m_StationSet.Close();
			m_station="";
			UpdateData(false);
			firstflag=true;
			CWnd *pwnd;
			pwnd=GetDlgItem(IDC_EDIT_ROADWAY);
			pwnd->EnableWindow(false);
			pwnd=GetDlgItem(IDC_EDIT_START);
			pwnd->EnableWindow(false);
			pwnd=GetDlgItem(IDC_EDIT_SEND);
			pwnd->EnableWindow(false);
			pwnd=GetDlgItem(IDC_EDIT_END);
			pwnd->EnableWindow(false);
			pwnd=GetDlgItem(IDC_EDIT_STOP);
			pwnd->EnableWindow(false);
			GetDlgItem(ID_OK)->SetFocus();
		}
		else
			MessageBox("信息不能为空!");
	}
	else
	{
		
		UpdateData(true);
		CStationSet m_StationSet;
		if(!m_StationSet.IsOpen())
			m_StationSet.Open();
		m_StationSet.MoveLast();
		m_StationSet.AddNew();
		m_StationSet.m_ID=m_roadway;
		m_StationSet.m_STATION=m_station;
		m_StationSet.Update();
		m_StationSet.Requery();
		m_StationSet.Close();
		m_station="";
		UpdateData(false);
		GetDlgItem(IDC_EDIT_STATION)->SetFocus();
		addroadflag=true;
		
	}
	
	
	
	
}

void AddOneRoadway::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	
	CDialog::OnKeyDown(nChar, nRepCnt, nFlags);
}

BOOL AddOneRoadway::PreTranslateMessage(MSG* pMsg) 
{
    if(pMsg->wParam==VK_RETURN)	
	{
		if(!stationflag)
		{
			GetDlgItem(IDC_EDIT_STATION)->SetFocus();
			stationflag=!stationflag;
		}
		else
		{
			GetDlgItem(ID_OK)->SetFocus();
			stationflag=!stationflag;
       	}
		
	}
	return CDialog::PreTranslateMessage(pMsg);
}

void AddOneRoadway::OnOK() 
{
	if(addroadflag)
	{
	//--------------------------------------
	CMapPublicApp *app=(CMapPublicApp *)AfxGetApp();
	CAction_Time_Set *m_ActionSet;
	CDatabase *db;
	db=new CDatabase;
	m_ActionSet=new CAction_Time_Set(db);
	CString strSql;
	CTime time=CTime::GetCurrentTime();
	CString strtime=time.Format("%Y-%m-%d %H:%M:%S");
	m_ActionSet->Open();
	CString	straction="添加一条路线";
	strSql="insert into Action_Log(USER_ID,ACTION,COME_LEAVE_TIME) values('" +app->m_User_ID+"','"+straction+"','"+strtime+"')";
	db->ExecuteSQL(strSql);
	m_ActionSet->Requery();
	m_ActionSet->Close();
	//-----------------------------------------
	}
	CDialog::OnOK();
}
