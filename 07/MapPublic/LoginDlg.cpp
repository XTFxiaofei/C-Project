// LoginDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mappublic.h"
#include "LoginDlg.h"
#include "PasswordSet.h"

#include "Action_Time_Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg dialog


CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLoginDlg)
	m_name = _T("");
	m_pass = _T("");
	//}}AFX_DATA_INIT
}


void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLoginDlg)
	DDX_Control(pDX, IDCANCEL, m_cancel);
	DDX_Control(pDX, ID_USERLOG, m_userlog);
	DDX_Text(pDX, IDC_USERNAME, m_name);
	DDX_Text(pDX, IDC_PASSWORD, m_pass);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialog)
	//{{AFX_MSG_MAP(CLoginDlg)
	ON_BN_CLICKED(ID_USERLOG, OnUserlog)
	//}}AFX_MSG_MAP

END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg message handlers

BOOL CLoginDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
    LOGFONT LogFont;
	GetFont()->GetLogFont(&LogFont);
    LogFont.lfHeight+=LogFont.lfHeight/2;
	LogFont.lfWidth+=LogFont.lfWidth/2;
    CFont m_font;
	m_font.CreateFontIndirect(&LogFont);
	GetDlgItem(IDC_STATIC_LOG)->SetFont(&m_font);
	
    SetWindowText("用户登录");
	

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CLoginDlg::OnUserlog() 
{
	
   	CPasswordSet m_pset;
	UpdateData();
	try
	{
		if(m_pset.Open())
			m_pset.Close();
		m_pset.m_strFilter.Format("USER_ID='%s'",m_name);
		m_pset.Open(CRecordset::snapshot,NULL,CRecordset::none);
		if(m_pset.IsEOF())
		{
			m_pset.Close();
			MessageBox("用户名错误请重试!","提示!",MB_ICONWARNING);
			m_name="";
			m_pass="";
			UpdateData(false);
			return;
		}
        m_pset.m_strFilter="";
		m_pset.Close();
        m_pset.m_strFilter.Format("USER_PASSWORD='%s'",m_pass);
		m_pset.Open(CRecordset::snapshot,NULL,CRecordset::none);
		if(m_pset.IsEOF())
		{
			m_pset.Close();
			MessageBox("密码错误请重试!","提示!",MB_ICONWARNING);
			m_pass="";
			UpdateData(false);
			return;
		}

		else
		{	
			CAction_Time_Set *m_ActionSet;
	        CDatabase *db;
        	db=new CDatabase;
	        m_ActionSet=new CAction_Time_Set(db);
	        CString strSql;
			CTime time=CTime::GetCurrentTime();
			CString strtime=time.Format("%Y-%m-%d %H:%M:%S");
			m_ActionSet->Open();
		    CString	straction="登录系统";
			strSql="insert into Action_Log(USER_ID,ACTION,COME_LEAVE_TIME) values('" +m_name+"','"+straction+"','"+strtime+"')";
			db->ExecuteSQL(strSql);
            m_ActionSet->Requery();
			m_ActionSet->Close();
            EndDialog(IDOK);
			CMapPublicApp *app=(CMapPublicApp *)AfxGetApp();
			app->m_User_ID=m_name;
			app->bEnableMenu=true;
		}
	}	
	catch(CDBException *e)
	{
       e->ReportError();
	   return;
	}
}
