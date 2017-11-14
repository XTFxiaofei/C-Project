// SYSDLG.cpp : implementation file
//

#include "stdafx.h"
#include "HCDB.h"
#include "SYSDLG.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// SYSDLG dialog


SYSDLG::SYSDLG(CWnd* pParent /*=NULL*/)
	: CDialog(SYSDLG::IDD, pParent)
{
	//{{AFX_DATA_INIT(SYSDLG)
	m_newpass = _T("");
	m_newpassr = _T("");
	m_oldpass = _T("");
	m_pass = _T("");
	m_passr = _T("");
	m_name = _T("");
	m_id = _T("");
	//}}AFX_DATA_INIT
}


void SYSDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(SYSDLG)
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	DDX_Text(pDX, IDC_EDITNEWPASS, m_newpass);
	DDX_Text(pDX, IDC_EDITNEWPASSR, m_newpassr);
	DDX_Text(pDX, IDC_EDITOLDPASS, m_oldpass);
	DDX_Text(pDX, IDC_EDITPASS, m_pass);
	DDX_Text(pDX, IDC_EDITPASSR, m_passr);
	DDX_Text(pDX, IDC_EDIT1, m_name);
	DDX_Text(pDX, IDC_EDITNAME, m_id);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(SYSDLG, CDialog)
	//{{AFX_MSG_MAP(SYSDLG)
	ON_BN_CLICKED(IDC_ADDUSER, OnAdduser)
	ON_BN_CLICKED(IDC_DELUSER, OnDeluser)
	ON_BN_CLICKED(IDC_MODIPASS, OnModipass)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// SYSDLG message handlers

BOOL SYSDLG::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	//////////////////////////////////ADO///////////////////////////////////////////////////
	m_pConnection.CreateInstance("ADODB.Connection");//创建Connection对象
	m_pRecordset.CreateInstance("ADODB.Recordset");//创建Recordset对象
	m_pConnection->Open("driver={SQL Server};Server=127.0.0.1;DATABASE=Sales;","","",adModeUnknown);///连接数据库	//给组合框初始化
	m_combo.InsertString(0,"管理员");
	m_combo.InsertString(1,"收银员");
	m_combo.SetCurSel(0);

	ShowData();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}



void SYSDLG::ShowData()
{		
	_variant_t va;
	m_pRecordset =m_pConnection->Execute("select * from tb_operator order by operid",&va,adCmdText);
	for(int i=m_list.GetCount();i>=0;i--)
		m_list.DeleteString(i);
	int k=0;
	while(!m_pRecordset->_EOF)
	{ 
		CString str1 = ((LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("opername"));
		CString str2 = ((LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("operlevel"));
		str1.TrimRight();
		str2.TrimRight();
		m_list.InsertString(k,str1+"["+str2+"]");
		k++;
		m_pRecordset->MoveNext();
	}
}

void SYSDLG::OnAdduser() 
{
	UpdateData();
	CString tempstr;
	m_combo.GetLBText(m_combo.GetCurSel(),tempstr);
	if(m_id!=""&&m_name!="")
	{
		while(!m_pRecordset->_EOF)
		{
			CString str = ((LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("opername"));		
			str.TrimRight();
			if(str==m_id)
			{				
				AfxMessageBox("该用户名已存在！\r\n请重新选择新用户进行注册！");
				m_id=m_name=m_pass=m_passr="";
			    UpdateData(false);
				return;	
			}
			m_pRecordset->MoveNext();
		}
		if(m_pass==m_passr)
		{
			CString str,str2;
			_variant_t va;
			str.Format("insert into tb_operator values('%s','%s','%s','%s')",m_id,m_name,m_pass,tempstr);			
			m_pRecordset =m_pConnection->Execute(_bstr_t(str),&va,adCmdText);
			AfxMessageBox("添加成功！！");
			m_id=m_name=m_pass=m_passr="";
			UpdateData(false);
			ShowData();
		}
		else
		{	
			AfxMessageBox("对不起!确认密码不正确!\r\n请您重新输入!");
			m_passr="";
			UpdateData(false);
			return;
		}
	}
	else 
	{
		AfxMessageBox("请输入正确的用户名!");	
		return;
	}
}

void SYSDLG::OnDeluser() 
{
	if(m_list.GetCurSel()==-1)
	{
		AfxMessageBox("请选择要删除的记录！");
		return;
	}
	else
	{
		if(MessageBox("确定要删除吗？","提醒！",MB_YESNO)==IDYES)
		{	
			CString tempstr;
			_variant_t va;
			m_list.GetText(m_list.GetCurSel(),tempstr);
			CString temp=tempstr.Left(tempstr.GetLength()-8);
			CString str;
			str.Format("delete from tb_operator where opername like '%s%%'",temp);
			m_pRecordset =m_pConnection->Execute(_bstr_t(str),&va,adCmdText);
			AfxMessageBox("删除成功！！");
			ShowData();		
		}
		else
			return;
	}
}

void SYSDLG::OnModipass() 
{
	UpdateData();
	CString tempstr;
	CString temp;
	CString oldpass;
	if(m_list.GetCurSel()==-1)
	{
		MessageBox("请选择要修改的记录!");
		return;
	}
	else
	{
		m_list.GetText(m_list.GetCurSel(),tempstr);
		temp=tempstr.Left(tempstr.GetLength()-8);
		_variant_t va;
		m_pRecordset =m_pConnection->Execute("select * from tb_operator order by opername",&va,adCmdText);
		
		while(!m_pRecordset->_EOF)
		{
			CString str1 = ((LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("opername"));
			CString str2 = ((LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("operlevel"));
			str1.TrimRight();
			str2.TrimRight();
			if(str1==temp)
			{
				UpdateData();
				oldpass = ((LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("operpassword"));
				oldpass.TrimRight();
				UpdateData(false);
				break;
				
			}
			m_pRecordset->MoveNext();		
		}
	}
	if(m_oldpass!="")
	{
		UpdateData();
		if(m_oldpass==oldpass)
		{
			
			if(m_newpass!="")
			{
				if(m_newpass==m_newpassr)
				{
					CString str;
					_variant_t va;
					str.Format("update tb_operator set operpassword='%s' where opername='%s'",m_newpass,temp);
					m_pConnection->Execute(_bstr_t(str),&va,adCmdText);
					AfxMessageBox("修改成功！！\r\n");
					AfxMessageBox("新密码为"+m_newpass+"!");
					m_oldpass=m_newpass=m_newpassr="";
					UpdateData(false);
					ShowData();	
				}
				else
				{
					AfxMessageBox("确认密码不正确!请重新输入!");
					m_newpassr="";
					UpdateData(false);
					return;
				}
			}
			else
			{
				AfxMessageBox("请输入新密码!");
				return;
			}
		}
		else
		{
			AfxMessageBox("旧密码不正确!请重新输入!");
			m_oldpass=m_newpass=m_newpassr="";
			UpdateData(false);
			return;
		}
	}
	else
	{
		AfxMessageBox("请输入旧密码!");
		return;
	}
}
