// BACKUPDLG.cpp : implementation file
//

#include "stdafx.h"
#include "HCDB.h"
#include "BACKUPDLG.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// BACKUPDLG dialog


BACKUPDLG::BACKUPDLG(CWnd* pParent /*=NULL*/)
	: CDialog(BACKUPDLG::IDD, pParent)
{
	//{{AFX_DATA_INIT(BACKUPDLG)
	m_edit = _T("");
	//}}AFX_DATA_INIT
}


void BACKUPDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(BACKUPDLG)
	DDX_Text(pDX, IDC_EDIT1, m_edit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(BACKUPDLG, CDialog)
	//{{AFX_MSG_MAP(BACKUPDLG)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// BACKUPDLG message handlers

void BACKUPDLG::OnButton1() 
{
    CFileDialog cfile(FALSE,"org",NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,
		"备份文件(*.bak)|*.bak|All Files (*.*)|*.*||");
	if(cfile.DoModal()==IDOK)
	{
	   CString str; 
	   str=cfile.GetPathName();	
       if(str!="")
         m_edit=str;
	   UpdateData(false);
	}
    else return;
}

void BACKUPDLG::OnButton3() 
{
   	if(MessageBox("确定备份？","系统提示",MB_ICONQUESTION|MB_YESNO)==6)
	{
	   CString sqlstr;
       if(m_edit)
	   {
		   try
		   {
			   sqlstr.Format("select Max(id) as maxid from tb_backup");
			   _RecordsetPtr rs=NULL;
			   rs.CreateInstance(__uuidof(Recordset));
			   rs->Open((_variant_t )sqlstr,m_connection.GetInterfacePtr(),
				         adOpenDynamic,adLockOptimistic,adCmdText);
			   CString a=(LPCSTR)(_bstr_t)rs->Fields->GetItem("maxid")->Value;
			   int b=atoi(a);
			   b++;
			   sqlstr.Format("insert into tb_backup values (%d,'%s','%s')",b,
				             CTime::GetCurrentTime().Format("%Y-%m-%d"),m_edit);
			   rs=NULL;
			   rs.CreateInstance(__uuidof(Recordset));
			   rs->Open((_variant_t )sqlstr,m_connection.GetInterfacePtr(),
				        adOpenDynamic,adLockOptimistic,adCmdText);
			   sqlstr.Format("backup database Sales to disk='%s'",m_edit);
			   m_connection->Execute((_bstr_t)sqlstr,NULL,adCmdUnknown);
               MessageBox("备份成功!");
			   m_connection->Close();			   
			   CDialog::OnOK();
		   }
		   catch(...)
		   {
			   MessageBox("备份失败!");
			   return;
		   }
	   }
	}
	else return;
}

BOOL BACKUPDLG::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_edit="F:\\sales.bak";
	UpdateData(false);
	Connect();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void BACKUPDLG::Connect()
{
	m_connection.CreateInstance(__uuidof(Connection));
	//////////////////////////////////////conection
	::CoInitialize(NULL);
	if(m_connection!=NULL)
		m_connection=NULL;
	CString sqlstr="driver={SQL Server};Server=HC\\MSSQL2008;Database=Sales";
	try
	{
		m_connection.CreateInstance(__uuidof(Connection));
		HRESULT rs;
		rs=m_connection->Open((_bstr_t)sqlstr,"","",adConnectUnspecified);
		if(rs)
		{
			::AfxMessageBox("连接失败");
			return ;
		}
	}
	catch(_com_error e)
	{ 
		CString strError;
		strError.Format("CADOWrong is %s\nCode Meaning is %s\nDescription is %s",e.ErrorMessage(),
			(LPCSTR)e.Source(),(LPCSTR)e.Description());
		::AfxMessageBox(strError);
		return ;
	}
}

void BACKUPDLG::OnButton4() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}
