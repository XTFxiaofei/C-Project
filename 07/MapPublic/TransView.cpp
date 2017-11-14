// TransView.cpp : implementation file
//

#include "stdafx.h"
#include "MapPublic.h"
#include "TransView.h"
#include "StationSet.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTransView property page

IMPLEMENT_DYNCREATE(CTransView, CPropertyPage)

CTransView::CTransView() : CPropertyPage(CTransView::IDD)
{
	//{{AFX_DATA_INIT(CTransView)
	m_scheme = _T("");
	//}}AFX_DATA_INIT
}

CTransView::~CTransView()
{
}

void CTransView::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTransView)
	DDX_Control(pDX, IDC_END, m_end);
	DDX_Control(pDX, IDC_START, m_start);
	DDX_Text(pDX, IDC_EDIT_SCHEME, m_scheme);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTransView, CPropertyPage)
	//{{AFX_MSG_MAP(CTransView)
	ON_BN_CLICKED(IDC_BUT_FIND, OnButFind)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTransView message handlers

BOOL CTransView::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	CStationSet m_stationSet;
	int i=0;
	m_stationSet.Open();
	m_stationSet.MoveFirst();
	while(!m_stationSet.IsEOF())
	{
		m_start.InsertString(i,m_stationSet.m_STATION);
		m_end.InsertString(i,m_stationSet.m_STATION);
		i++;
		m_stationSet.MoveNext();

	}
	m_stationSet.Close();
	m_start.SetCurSel(1);
	m_end.SetCurSel(5);
    	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CTransView::OnButFind() 
{
	CWnd *pwnd;
	CMapPublicApp *app=(CMapPublicApp *)AfxGetApp();
	app->m_show="";
	pwnd=GetDlgItem(IDC_EDIT_SCHEME);
	m_scheme="";

	UpdateData(false);
	CString start,end;
	m_start.GetLBText(m_start.GetCurSel(),start);
    m_end.GetLBText(m_end.GetCurSel(),end);
  	if(start!=end)
	{
		if(m_InfoMation.Query(pwnd,start,end))
		{
		//	AfxMessageBox(app->m_show);
			m_scheme=app->m_show;
			UpdateData(false);
		}

	}
	else 
		AfxMessageBox("起始站和终点站不能相同！");
	
	
}
