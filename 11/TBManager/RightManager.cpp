// RightManager.cpp : implementation file
//

#include "stdafx.h"
#include "TBManager.h"
#include "RightManager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRightManager dialog


CRightManager::CRightManager(CWnd* pParent /*=NULL*/)
	: CDialog(CRightManager::IDD, pParent)
{
	CString strConnection="File Name=ThemeBase.udl";
	pDB=new CADODatabase;
	pDB->Open(strConnection);
	pRS=new CADORecordset(pDB);
	//{{AFX_DATA_INIT(CRightManager)
	m_name = _T("");
	m_right = _T("");
	m_namemanager = _T("");
	//}}AFX_DATA_INIT
}


void CRightManager::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRightManager)
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Text(pDX, IDC_NAME, m_name);
	DDX_Text(pDX, IDC_RIGHT, m_right);
	DDX_Text(pDX, IDC_EDIT4, m_namemanager);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRightManager, CDialog)
	//{{AFX_MSG_MAP(CRightManager)
	ON_BN_CLICKED(IDC_SHOWUPDATE, OnShowupdate)
	ON_WM_DESTROY()
	ON_LBN_SELCHANGE(IDC_LIST1, OnSelchangeList1)
	ON_BN_CLICKED(IDC_ADDUSER, OnAdduser)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRightManager message handlers

BOOL CRightManager::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_name=username;
	if(userright=="0")
		m_right="管理员";
	else m_right="普通用户";
	pRS->Open("select * from users",CADORecordset.openQuery);
	if(!pRS->IsOpen())
		return false;
	if(pRS->GetRecordCount()<=0)
		return false;
	pRS->MoveFirst();
	CString str1,str2;
	int i=0;
	while(!pRS->IsEOF())
	{
		pRS->GetFieldValue("name",str1);
		pRS->GetFieldValue("userright",str2);
		if(str2=="0")
			str1+="**管理员";
		else str1+="**普通用户";
		m_list.InsertString(i,str1);
		i++;
		pRS->MoveNext();
	}
	pRS->Close();
	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CRightManager::OnShowupdate() 
{
	CButton *p;
	p=(CButton *)GetDlgItem(IDC_EDIT1);
	p->EnableWindow(true);
	p=(CButton *)GetDlgItem(IDC_EDIT2);
	p->EnableWindow(true);
	p=(CButton *)GetDlgItem(IDC_EDIT3);
	p->EnableWindow(true);
	p=(CButton *)GetDlgItem(IDC_STATIC1);
	p->EnableWindow(true);
	p=(CButton *)GetDlgItem(IDC_STATIC2);
	p->EnableWindow(true);
	p=(CButton *)GetDlgItem(IDC_STATIC3);
	p->EnableWindow(true);
	
}

void CRightManager::OnDestroy() 
{
	CDialog::OnDestroy();
	pDB->Close();	
	
}

void CRightManager::OnSelchangeList1() 
{
	int i=m_list.GetCurSel();
	CString temp,test;
	m_list.GetText(i,temp);
	int position=temp.Find("**");
	test=temp.Left(position);
	m_namemanager=test;
	UpdateData(false);
//	test.Format("%d",position);
//	AfxMessageBox(test);
	
}

void CRightManager::OnAdduser() 
{
	// TODO: Add your control notification handler code here
	
}
