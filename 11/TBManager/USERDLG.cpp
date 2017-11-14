// USERDLG.cpp : implementation file
//

#include "stdafx.h"
#include "TBManager.h"
#include "USERDLG.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// USERDLG dialog


USERDLG::USERDLG(CWnd* pParent /*=NULL*/)
: CDialog(USERDLG::IDD, pParent)
{
	//{{AFX_DATA_INIT(USERDLG)
	m_name = _T("");
	m_newpass = _T("");
	m_nnewpass = _T("");
	m_oldpass = _T("");
	m_pass1 = _T("");
	m_pass2 = _T("");
	//}}AFX_DATA_INIT
}


void USERDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(USERDLG)
	DDX_Control(pDX, IDC_LIST2, m_list);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	DDX_Text(pDX, IDC_NAME, m_name);
	DDX_Text(pDX, IDC_NEWPASS, m_newpass);
	DDX_Text(pDX, IDC_NNEWPASS, m_nnewpass);
	DDX_Text(pDX, IDC_OLDPASS, m_oldpass);
	DDX_Text(pDX, IDC_PASS1, m_pass1);
	DDX_Text(pDX, IDC_PASS2, m_pass2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(USERDLG, CDialog)
//{{AFX_MSG_MAP(USERDLG)
ON_BN_CLICKED(IDC_MODIFY, OnModify)
ON_BN_CLICKED(IDC_ADDUSER, OnAdduser)
ON_BN_CLICKED(IDC_DELUSER, OnDeluser)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// USERDLG message handlers

void USERDLG::OnModify() 
{
	UpdateData();
	if(m_list.GetCurSel()==-1)		
	{
		MessageBox("请选择用户!");
		return ;
	}
	int mmm;
	CString temp,temp1; 
	int k=m_list.GetCurSel();
	m_list.GetText(k,temp);
	mmm=temp.GetLength();
	temp1=temp.Left(mmm-8);
	if(m_oldpass=="")
	{
   	    MessageBox("请输入密码!");
		GetDlgItem(IDC_OLDPASS)->SetFocus();
		return ;
	}
	if(pRS->IsOpen())
	pRS->Close();
	CString str;
	str.Format("select * from password where name='%s' and password='%s'",temp1,m_oldpass);
	pRS->Open(str,CADORecordset.openQuery);
	if(pRS->GetRecordCount()<=0)
	{
		MessageBox("密码与原密码不符，请重新输入!");
		GetDlgItem(IDC_OLDPASS)->SetFocus();
		m_oldpass=m_newpass=m_nnewpass="";
		UpdateData(false);
		return ;
	}
	if(m_newpass!=m_nnewpass)
	{
		MessageBox("密码不符!");
		GetDlgItem(IDC_OLDPASS)->SetFocus();
		m_oldpass=m_newpass=m_nnewpass="";
		UpdateData(false);
		return ;
	}
	else
	{
		CString str;
		str.Format("update password set password='%s' where name='%s'",m_newpass,temp1);
		pDB->Execute(str);
		MessageBox("密码修改成功!");
	}
}

void USERDLG::OnAdduser() 
{
	UpdateData();
	CString temp,str;
	_variant_t ra;
	int k=m_combo.GetCurSel();
    if(m_name=="")
	{
		MessageBox("用户名不能为空!");
		GetDlgItem(IDC_NAME)->SetFocus();
	}
	else if(m_pass1!=m_pass2)
	{  
		MessageBox("密码不符!");	
		GetDlgItem(IDC_PASS1)->SetFocus();
		m_pass1=m_pass2="";
		UpdateData(false);
	}
	else 
	{
		str.Format("insert into password values('%s','%s',%d)",m_name,m_pass1,k);
		pDB->Execute(str);
		showdata();
		MessageBox("添加用户成功!");	
	}
}

void USERDLG::OnDeluser() 
{
	UpdateData();
	if(m_list.GetCurSel()==-1)		
	{
		MessageBox("请选择用户!");
		GetDlgItem(IDC_OLDPASS)->SetFocus();
		return ;
	}
	int mmm;
	CString temp,temp1; 
	int k=m_list.GetCurSel();
	m_list.GetText(k,temp);
	mmm=temp.GetLength();
	temp1=temp.Left(mmm-8);
    _variant_t ra;
	CString str;
	str.Format("delete from password where name='%s'",temp1);
	if(MessageBox("确定删除？","注意",MB_YESNO)==IDYES)
	{
		pDB->Execute(str);
		MessageBox("删除成功！");
	}
	showdata();
}

BOOL USERDLG::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_combo.InsertString(0,"管理员");
	m_combo.InsertString(1,"录入员");
	m_combo.SetCurSel(0);
	
	CString strConnection="File Name=ThemeBase.udl";
	pDB=new CADODatabase;
	pDB->Open(strConnection);
	pRS=new CADORecordset(pDB);
	showdata();
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void USERDLG::showdata()
{
	m_list.ResetContent();
	CString user,password,power,temp;
	if(pRS->IsOpen())
		pRS->Close();
	pRS->Open("select * from password",CADORecordset.openQuery);
	
	if(pRS->GetRecordCount()<=0)
		return ;
	pRS->MoveFirst();
	int k=0;
	while(!pRS->IsEOF())
	{
		pRS->GetFieldValue("name",user);		
		pRS->GetFieldValue("password",password);	
		pRS->GetFieldValue("userright",power);
		if(power=="0")
			power="管理员";
		else
			power="录入员";
		temp=user+"["+power+"]";
		m_list.InsertString(k,temp);		
		pRS->MoveNext();
		k++;
	}
}
