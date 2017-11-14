// AddAttributeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mappublic.h"
#include "AddAttributeDlg.h"
#include "AttributeSet.h"
#include "Action_Time_Set.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddAttributeDlg dialog


CAddAttributeDlg::CAddAttributeDlg(CWnd* pParent /*=NULL*/)
: CDialog(CAddAttributeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddAttributeDlg)
	m_strAttribute = _T("");
	m_strName = _T("");
	m_pitcure_name = _T("");
	//}}AFX_DATA_INIT
	writeflag=false;
	m_check=false;
}


void CAddAttributeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddAttributeDlg)
	DDX_Control(pDX, IDCANCEL, m_cancel);
	DDX_Text(pDX, IDC_OBJECT_ATTRIBUTE, m_strAttribute);
	DDX_Text(pDX, IDC_OBJECT_NAME, m_strName);
	DDX_Text(pDX, IDC_PITCURE_NAME, m_pitcure_name);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddAttributeDlg, CDialog)
//{{AFX_MSG_MAP(CAddAttributeDlg)
ON_BN_CLICKED(ID_ADD, OnAdd)
	ON_BN_CLICKED(IDC_CHECK, OnCheck)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddAttributeDlg message handlers

BOOL CAddAttributeDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	GetDlgItem(IDC_OBJECT_NAME)->SetFocus();
	GetDlgItem(IDC_PITCURE_NAME)->EnableWindow(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CAddAttributeDlg::PreTranslateMessage(MSG* pMsg) 
{
	CWnd *pwnd;
	if (WM_KEYFIRST <= pMsg->message && pMsg->message <= WM_KEYLAST) 
	{
		if(pMsg->wParam==VK_RETURN)	
		{
			pwnd=GetFocus ();
			if(pwnd==GetDlgItem(IDC_OBJECT_NAME))
				GetDlgItem(IDC_OBJECT_ATTRIBUTE)->SetFocus();
			else if(pwnd==GetDlgItem(IDC_OBJECT_ATTRIBUTE))
				GetDlgItem(ID_ADD)->SetFocus();
		}
	}
   	
	return CDialog::PreTranslateMessage(pMsg);
}

void CAddAttributeDlg::OnAdd() 
{
	int temp=0;
	UpdateData();
	if(m_strName==""||m_strAttribute=="")
	{
		AfxMessageBox("输入不能为空！");
		return;
	}
	CButton *p_Check=(CButton *)GetDlgItem(IDC_CHECK);
	if(p_Check->GetCheck())
       temp=1;
	if(p_Check->GetCheck()&&m_pitcure_name=="")
	{
		AfxMessageBox("请输入图片名称！");
		return;
	}
    CAttributeSet *m_attributeSet;
	CDatabase *db;
	db=new CDatabase;
    m_attributeSet=new CAttributeSet(db);
	m_attributeSet->Open();
	CString str;
	str.Format("insert into AttributeSet values('%s','%s','%d','%s')",m_strName,m_strAttribute,temp,m_pitcure_name);
    db->ExecuteSQL(str);
	m_attributeSet->Requery();
	m_attributeSet->Close();
	m_strName="";
	m_strAttribute="";
	p_Check->SetCheck(false);
    m_pitcure_name="";
    GetDlgItem(IDC_PITCURE_NAME)->EnableWindow(false);
	UpdateData(false);
    GetDlgItem(IDC_OBJECT_NAME)->SetFocus();
	
}

void CAddAttributeDlg::OnCancel() 
{
    if(writeflag)	
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
	CString	straction="添加景点属性";
	strSql="insert into Action_Log(USER_ID,ACTION,COME_LEAVE_TIME) values('" +app->m_User_ID+"','"+straction+"','"+strtime+"')";
	db->ExecuteSQL(strSql);
	m_ActionSet->Requery();
	m_ActionSet->Close();
	//-----------------------------------------
	}
	CDialog::OnCancel();
}

void CAddAttributeDlg::OnCheck() 
{
	m_check=!m_check;
	if(!m_check)
		GetDlgItem(IDC_PITCURE_NAME)->EnableWindow(false);
	else
        GetDlgItem(IDC_PITCURE_NAME)->EnableWindow(true);
  	
}
