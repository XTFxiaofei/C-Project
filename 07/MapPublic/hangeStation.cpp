// hangeStation.cpp : implementation file
//

#include "stdafx.h"
#include "MapPublic.h"
#include "hangeStation.h"
#include "BusSet.h"
#include "StationSet.h"

#include "Action_Time_Set.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ChangeStation dialog


ChangeStation::ChangeStation(CWnd* pParent /*=NULL*/)
	: CDialog(ChangeStation::IDD, pParent)
{
	//{{AFX_DATA_INIT(ChangeStation)
	//}}AFX_DATA_INIT
}


void ChangeStation::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ChangeStation)
	DDX_Control(pDX, IDOK, m_ok);
	DDX_Control(pDX, ID_CHANGE_STATION, m_change_station);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_COMBO1, m_roadway);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ChangeStation, CDialog)
	//{{AFX_MSG_MAP(ChangeStation)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	ON_BN_CLICKED(ID_CHANGE_STATION, OnChangeStation)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ChangeStation message handlers

BOOL ChangeStation::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CBusSet m_busset;
	int i=0;
	if(!m_busset.IsOpen())
		m_busset.Open();
	m_busset.MoveFirst();
	while(!m_busset.IsEOF())
	{
		m_roadway.InsertString(i++,m_busset.m_ID_BUS);
		m_busset.MoveNext();

	}
	m_roadway.SetCurSel(0);
	m_busset.Close();

	RECT rect;
	m_list.GetWindowRect(&rect);
	int wid=rect.right-rect.left;

	m_list.InsertColumn(0,"车次",LVCFMT_CENTER,wid/3);
	m_list.InsertColumn(1,"站点",LVCFMT_CENTER,2*wid/3);

	CString str;
	m_roadway.GetLBText(0,str);
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
	m_StationSet.Close();
	
	m_list.SetExtendedStyle(WS_CHILD|WS_CLIPSIBLINGS|WS_EX_TOOLWINDOW|WS_BORDER|LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);//修改其样式
    	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void ChangeStation::OnSelchangeCombo1() 
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

void ChangeStation::OnChangeStation() 
{
	int i=0;
	
	
	CString str1,str;
	m_roadway.GetLBText(m_roadway.GetCurSel(),str1);
	CDatabase *m_datebase;
	m_datebase=new CDatabase;//初始化
    CStationSet *m_Set;
	m_Set=new CStationSet(m_datebase);//数据库与记录集关联
    m_Set->Open();
	str.Format("delete from STATION where ID='%s'",str1);
	m_datebase->ExecuteSQL(str);
	m_Set->Requery();
	CStationSet m_StationSet;
	if(!m_StationSet.IsOpen())
		m_StationSet.Open();
	m_StationSet.AddNew();
	do
	{
		m_StationSet.m_ID=m_list.GetItemText(i,0);
		m_StationSet.m_STATION=m_list.GetItemText(i++,1);
	}while(i<m_list.GetItemCount());
    m_StationSet.Update();
	m_StationSet.Requery();

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
			CString	straction="修改一个站点";
			strSql="insert into Action_Log(USER_ID,ACTION,COME_LEAVE_TIME) values('" +app->m_User_ID+"','"+straction+"','"+strtime+"')";
			db->ExecuteSQL(strSql);
			m_ActionSet->Requery();
			m_ActionSet->Close();
			//-----------------------------------------
		
	AfxMessageBox("修改记录成功！");
	m_StationSet.Close();

}
