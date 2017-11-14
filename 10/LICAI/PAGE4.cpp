// PAGE4.cpp : implementation file
//

#include "stdafx.h"
#include "LICAI.h"
#include "PAGE4.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PAGE4 dialog


PAGE4::PAGE4(CWnd* pParent /*=NULL*/)
	: CDialog(PAGE4::IDD, pParent)
{
	//{{AFX_DATA_INIT(PAGE4)
	m_edit = _T("");
	//}}AFX_DATA_INIT
}


void PAGE4::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PAGE4)
	DDX_Control(pDX, IDC_Open, m_open);
	DDX_Control(pDX, IDC_delefile, m_dele);
	DDX_Text(pDX, IDC_EDIT1, m_edit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PAGE4, CDialog)
	//{{AFX_MSG_MAP(PAGE4)
	ON_BN_CLICKED(IDC_SHUXIN, OnShuxin)
	ON_BN_CLICKED(IDC_delefile, Ondelefile)
	ON_BN_CLICKED(IDC_Open, OnOpen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PAGE4 message handlers

BOOL PAGE4::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CString str(""); 
   	CString strLine;  
   	CStdioFile file; 
  	if(!file.Open(logFileName,CFile::modeRead))   
	   	return FALSE;   
   	while(file.ReadString(strLine))   
	{   
	   	str+=strLine;
        str+="\r\n";   
	}   
   	file.Close();   
   	CWnd *pWnd=(CWnd*)GetDlgItem(IDC_EDIT1);   
   	pWnd->SetWindowText(str);
	if(!loginflag)
	{
		m_dele.EnableWindow(FALSE);
		m_open.EnableWindow(FALSE);
	}
		
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void PAGE4::OnShuxin() 
{
	OnInitDialog();	
}

void PAGE4::Ondelefile() 
{
	if(MessageBox("          确定删除日志文件吗?                ","家庭个人理财系统",MB_YESNO|MB_ICONINFORMATION)==IDYES)
	{
		CFile TempFile; 
		CStdioFile file; 
		if(file.Open(logFileName,CFile::modeRead))
		{
			file.Close();
    		TempFile.Remove(logFileName);
            m_edit="";
		    UpdateData(false);
		}	
	}
}

void PAGE4::OnOpen() 
{
	//显示文件打开对话框
	CFileDialog dlg(TRUE, "SQL", "*.txt",OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,"文本文件(*.txt)|*.txt|所有文件(*.*)|*.*||");
	if ( dlg.DoModal()!=IDOK ) 
		return;
	//获取文件的绝对路径
	CString sFileName=dlg.GetPathName();
	//打开文件
	CStdioFile out;
	out.Open(sFileName, CFile::modeRead);
	CString sSql="",s;
	//读取文件
	do
	{
		out.ReadString(s);
		sSql=sSql+s+"\r\n"+(char)10;

	}
	while (out.GetPosition()!=out.GetLength());
	out.Close();
	GetDlgItem(IDC_EDIT1)->SetWindowText(sSql);	
}
