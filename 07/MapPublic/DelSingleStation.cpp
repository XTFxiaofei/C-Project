// DelSingleStation.cpp : implementation file
//

#include "stdafx.h"
#include "MapPublic.h"
#include "DelSingleStation.h"
#include "StationSet.h"
#include "BusSet.h"

#include "Action_Time_Set.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DelSingleStation dialog


DelSingleStation::DelSingleStation(CWnd* pParent /*=NULL*/)
: CDialog(DelSingleStation::IDD, pParent)
{
	//{{AFX_DATA_INIT(DelSingleStation)
	//}}AFX_DATA_INIT
}


void DelSingleStation::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DelSingleStation)
	DDX_Control(pDX, IDOK, m_ok);
	DDX_Control(pDX, ID_DEL, m_del);
	DDX_Control(pDX, IDC_LIST2, m_list);
	DDX_Control(pDX, IDC_ROADWAY, m_roadway);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DelSingleStation, CDialog)
//{{AFX_MSG_MAP(DelSingleStation)
ON_CBN_SELCHANGE(IDC_ROADWAY, OnSelchangeRoadway)
ON_BN_CLICKED(ID_DEL, OnDel)
ON_NOTIFY(LVN_ITEMCHANGING, IDC_LIST2, OnItemchangingList2)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DelSingleStation message handlers

BOOL DelSingleStation::OnInitDialog() 
{
	CDialog::OnInitDialog();
	int i=0;
	CString str;
    CBusSet m_busset;
	if(!m_busset.IsOpen())
		m_busset.Open();
	m_busset.MoveFirst();
	while(!m_busset.IsEOF())
	{
		m_roadway.InsertString(i++,m_busset.m_ID_BUS);
		m_busset.MoveNext();
	}
	m_roadway.SetCurSel(0);
	m_roadway.GetLBText(0,str);
	m_list.InsertColumn(0,"车次");
	m_list.InsertColumn(1,"站点");
	RECT rect;
	m_list.GetWindowRect(&rect);
	int wid=rect.right-rect.left;
	m_list.SetColumnWidth(0,wid/3);
	m_list.SetColumnWidth(1,2*wid/3);
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	i=0;
    CStationSet m_StationSet;
	if(!m_StationSet.IsOpen())
		m_StationSet.Open();
	m_StationSet.MoveFirst();
	while(!m_StationSet.IsEOF())
	{
		if(m_StationSet.m_ID==str)
		{
			m_list.InsertItem(i,str);
			m_list.SetItemText(i++,1,m_StationSet.m_STATION);
			
		}
		m_StationSet.MoveNext();
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void DelSingleStation::OnSelchangeRoadway() 
{
	m_list.DeleteAllItems();
	CString str;
	m_roadway.GetLBText(m_roadway.GetCurSel(),str);
	int i=0;
    CStationSet m_StationSet;
	if(!m_StationSet.IsOpen())
		m_StationSet.Open();
	m_StationSet.MoveFirst();
	while(!m_StationSet.IsEOF())
	{
		if(m_StationSet.m_ID==str)
		{
			m_list.InsertItem(i,str);
			m_list.SetItemText(i++,1,m_StationSet.m_STATION);
			
		}
		m_StationSet.MoveNext();
	}
}

void DelSingleStation::OnDel() 
{
	
	CStationSet m_StationSet;
	CString str;
	m_roadway.GetLBText(m_roadway.GetCurSel(),str);
	if(!m_StationSet.IsOpen())
		m_StationSet.Open();
	m_StationSet.MoveFirst();
	while(!m_StationSet.IsEOF())
	{
		if(m_StationSet.m_ID==str&&m_StationSet.m_STATION==m_str)
		{
			m_StationSet.Delete();
			AfxMessageBox("删除记录成功！");
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
			CString	straction="删除一个站点";
			strSql="insert into Action_Log(USER_ID,ACTION,COME_LEAVE_TIME) values('" +app->m_User_ID+"','"+straction+"','"+strtime+"')";
			db->ExecuteSQL(strSql);
			m_ActionSet->Requery();
			m_ActionSet->Close();
			//-----------------------------------------
			break;
		}
		m_StationSet.MoveNext();
	}
	Refresh();
	
}

void DelSingleStation::OnItemchangingList2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	int i=pNMListView->iItem;
	m_str=m_list.GetItemText(i,1);	
	*pResult = 0;
}

void DelSingleStation::Refresh()
{
	m_list.DeleteAllItems();
	CString str;
	m_roadway.GetLBText(m_roadway.GetCurSel(),str);
	int i=0;
    CStationSet m_StationSet;
	if(!m_StationSet.IsOpen())
		m_StationSet.Open();
	m_StationSet.MoveFirst();
	while(!m_StationSet.IsEOF())
	{
		if(m_StationSet.m_ID==str)
		{
			m_list.InsertItem(i,str);
			m_list.SetItemText(i++,1,m_StationSet.m_STATION);
			
		}
		m_StationSet.MoveNext();
	}
	m_StationSet.Close();
	
}
