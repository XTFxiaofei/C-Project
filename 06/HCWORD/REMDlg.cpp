// REMDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HCWORD.h"
#include "REMDlg.h"
#include "ADDdlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// REMDlg dialog


REMDlg::REMDlg(CWnd* pParent /*=NULL*/)
	: CDialog(REMDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(REMDlg)
	m_edit = _T("");
	//m_edit="ghsajbdsjabdnsabdnasbdnasndcasmsncsaghgfhgfhjjkkkklllllllllllnnnnnnnnnnn";
	//}}AFX_DATA_INIT
}


void REMDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(REMDlg)
	DDX_Text(pDX, IDC_EDIT1, m_edit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(REMDlg, CDialog)
	//{{AFX_MSG_MAP(REMDlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// REMDlg message handlers

BOOL REMDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CString str; 
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
//	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void REMDlg::OnButton1() 
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

void REMDlg::OnButton2() 
{
if(MessageBox("          确定删除记录吗?                ","电子词典系统",MB_YESNO|MB_ICONINFORMATION)==IDYES)
	{
		CFile TempFile; 
		CStdioFile file; 
		if(file.Open(logFileName,CFile::modeRead))
		{
			file.Close();                                    //关闭文件
    		TempFile.Remove(logFileName);
            m_edit="";
		    UpdateData(false);
		}	
	}	
}

void REMDlg::OnButton3() 
{
	OnInitDialog();
	
}
