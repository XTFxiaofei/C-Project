// DelRoadway.cpp : implementation file
//

#include "stdafx.h"
#include "MapPublic.h"
#include "DelRoadway.h"
#include "BusSet.h"
#include "StationSet.h"

#include "Action_Time_Set.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DelRoadway dialog


DelRoadway::DelRoadway(CWnd* pParent /*=NULL*/)
	: CDialog(DelRoadway::IDD, pParent)
{
	//{{AFX_DATA_INIT(DelRoadway)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DelRoadway::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DelRoadway)
	DDX_Control(pDX, IDCANCEL, m_cancel);
	DDX_Control(pDX, ID_DEL, m_del);
	DDX_Control(pDX, IDC_LIST1, m_list);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DelRoadway, CDialog)
	//{{AFX_MSG_MAP(DelRoadway)
	ON_BN_CLICKED(ID_DEL, OnDel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DelRoadway message handlers

BOOL DelRoadway::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	int i=0;
	m_list.SetTextColor(RGB(0,0,255));
//	m_list.SetTextBkColor(RGB(255,0,0));
	RECT rect;
	m_list.GetWindowRect(&rect);
	int wid=rect.right-rect.left;
    DWORD style=m_list.GetExtendedStyle();
	m_list.SetExtendedStyle(style|LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	m_list.InsertColumn(0,"车次",LVCFMT_CENTER,wid);
    CBusSet m_busset;
	if(!m_busset.IsOpen())
		m_busset.Open();
	m_busset.MoveFirst();
	while(!m_busset.IsEOF())
	{
		m_list.InsertItem(i++,m_busset.m_ID_BUS);
		m_busset.MoveNext();
	}
    m_busset.Close();	
	return TRUE;  
}

void DelRoadway::OnDel() 
{
	CString str;
   int CurSel=m_list.GetNextItem(-1,LVNI_ALL | LVNI_SELECTED);
    str=m_list.GetItemText(CurSel,0);  
    CBusSet m_busset;
	if(!m_busset.IsOpen())
		m_busset.Open();
	m_busset.MoveFirst();
	while(!m_busset.IsEOF())
	{
		if(m_busset.m_ID_BUS==str)
		{
			m_busset.Delete();

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
			CString	straction="删除一条路线";
			strSql="insert into Action_Log(USER_ID,ACTION,COME_LEAVE_TIME) values('" +app->m_User_ID+"','"+straction+"','"+strtime+"')";
			db->ExecuteSQL(strSql);
			m_ActionSet->Requery();
			m_ActionSet->Close();
			//-----------------------------------------
			MessageBox("删除成功！");
			break;
		}
		else
			m_busset.MoveNext();

	}
	m_busset.Close();

	CStationSet m_StationSet;
	if(!m_StationSet.IsOpen())
		m_StationSet.Open();
	m_StationSet.MoveFirst();
	
	while(!m_StationSet.IsEOF())
	{
		if(m_StationSet.m_ID==str)
		{
			m_StationSet.Delete();
			m_StationSet.MoveNext();
		}
		else
			m_StationSet.MoveNext();

	}
	m_StationSet.Close();
	m_list.DeleteAllItems();
	int i=0;
	if(!m_busset.IsOpen())
		m_busset.Open();
	m_busset.MoveFirst();
	while(!m_busset.IsEOF())
	{
		m_list.InsertItem(i++,m_busset.m_ID_BUS);
		m_busset.MoveNext();
	}
    m_busset.Close();	



	
}
