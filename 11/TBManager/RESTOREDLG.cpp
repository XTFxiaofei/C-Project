// RESTOREDLG.cpp : implementation file
//

#include "stdafx.h"
#include "tbmanager.h"
#include "RESTOREDLG.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern CTBManagerApp theApp;
/////////////////////////////////////////////////////////////////////////////
// RESTOREDLG dialog


RESTOREDLG::RESTOREDLG(CWnd* pParent /*=NULL*/)
	: CDialog(RESTOREDLG::IDD, pParent)
{
	//{{AFX_DATA_INIT(RESTOREDLG)
	m_path = _T("D:\\abao.bak");
	//}}AFX_DATA_INIT
}


void RESTOREDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(RESTOREDLG)
	DDX_Text(pDX, IDC_EDIT1, m_path);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(RESTOREDLG, CDialog)
	//{{AFX_MSG_MAP(RESTOREDLG)
	ON_BN_CLICKED(ID_SELECT, OnSelect)
	ON_BN_CLICKED(ID_RESTORE, OnRestore)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// RESTOREDLG message handlers

void RESTOREDLG::OnSelect() 
{
	CFileDialog filedlg(true,"bak",NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,
		"备份文件(*.bak)|*.bak|All Files (*.*)|*.*||");  
	if(filedlg.DoModal()==IDOK)
	{
		m_path=filedlg.GetPathName();
		UpdateData(FALSE);
	}	
}

void RESTOREDLG::OnRestore() 
{
	if(m_path=="")
	{
		AfxMessageBox("请选择文件!");
		return;
	}
	else
	{
		pDB->Open("driver={SQL Server};Server=HC\\MSSQL2008;DATABASE=master;");
		//pDB->Open("driver={SQL Server};Server=HC\\MSSQL2008;DATABASE=master;UID=sa; PWD=");
		CString sqlstr;
		sqlstr="select spid from master..sysprocesses where dbid=db_id('abao')";	
		//获得与数据库相连接的进程连接字串
		_RecordsetPtr recordset;
		recordset.CreateInstance(__uuidof(Recordset));	
		recordset=pDB->m_pConnection->Execute((_bstr_t)sqlstr,NULL,adModeUnknown);	   
		while(!recordset->adoEOF)
		{
			CString temp=(LPCSTR)(_bstr_t)recordset->Fields->GetItem("spid")->Value;
			sqlstr.Format("kill %i",atoi(temp));//断开连接的进程 
			pDB->Execute(sqlstr);  
			recordset->MoveNext();
		}		
		sqlstr.Format("use master drop database abao");
		pDB->m_pConnection->Execute((_bstr_t)sqlstr,NULL,adModeUnknown);
		sqlstr.Format("use master restore database abao from Disk = '%s' WITH MOVE 'abao_Data'  TO  'c:\\abao.mdf', MOVE  'abao_Log'  TO  'c:\\abao.ldf'",m_path);
		pDB->m_pConnection->Execute((_bstr_t)sqlstr,NULL,adModeUnknown);
		AfxMessageBox("还原成功!");
		pDB->m_pConnection->Close();
		pDB->Close();
		CDialog::OnCancel();
        pDB->Open("driver={SQL Server};Server=HC\\MSSQL2008;DATABASE=abao;");
		//pDB->Open("driver={SQL Server};Server=HC\\MSSQL2008;DATABASE=abao;UID=sa; PWD=");
	}
}

BOOL RESTOREDLG::OnInitDialog() 
{
	CDialog::OnInitDialog();	
	pDB=new CADODatabase;

	return TRUE;  // return TRUE unless you set the focus to a control
}
