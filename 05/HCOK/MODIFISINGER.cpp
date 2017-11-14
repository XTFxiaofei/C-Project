// MODIFISINGER.cpp : implementation file
//

#include "stdafx.h"
#include "HCOK.h"
#include "MODIFISINGER.h"
#include "ADOConn.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// MODIFISINGER dialog


MODIFISINGER::MODIFISINGER(CWnd* pParent /*=NULL*/)
	: CDialog(MODIFISINGER::IDD, pParent)
{
	//{{AFX_DATA_INIT(MODIFISINGER)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void MODIFISINGER::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(MODIFISINGER)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(MODIFISINGER, CDialog)
	//{{AFX_MSG_MAP(MODIFISINGER)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// MODIFISINGER message handlers

BOOL MODIFISINGER::OnInitDialog() 
{
	CDialog::OnInitDialog();


	CString temp=mkusingerarea.Left(4);	
	CString temp2=	mkusingersex.Left(2);	

    GetDlgItem(IDC_SINGER)->SetWindowText( mkusingername);
	
    GetDlgItem(IDC_SINGERSEX)->SetWindowText(temp2);
	GetDlgItem(IDC_SGEAREA)->SetWindowText(temp);
	GetDlgItem(IDC_SGEPIN)->SetWindowText(	mkusingerpin);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void MODIFISINGER::OnOK() 
{
    CString newkusingername,newkusingersex,newkusingerarea,newkusingerpin;
	
	
	GetDlgItem(IDC_SINGER)->GetWindowText( newkusingername);//得到新的姓名
		
	GetDlgItem(IDC_SINGERSEX)->GetWindowText(	newkusingersex);//得到新的性别
	GetDlgItem(IDC_SGEAREA)->GetWindowText(newkusingerarea);  //得到新的地区
	GetDlgItem(IDC_SGEPIN)->GetWindowText(	newkusingerpin);  //得到新的拼音
    newkusingerarea=newkusingerarea+"歌手";
    newkusingersex=newkusingersex+"歌手";
	////////////////////////////////////////////////////
	ADOConn m_AdoConn;//创建数据库操作对象

	m_AdoConn.OnInitADOConn(); //连接数据库

	_RecordsetPtr m_pRecordset;
	_bstr_t sql;
    sql = "select*from singer where sinnam='"+mkusingername+"'";
	m_pRecordset=m_AdoConn.GetRecordSet(sql);//用记录集覆盖当前的
	m_pRecordset->GetFields()->GetItem("sinnam")->Value=(_bstr_t) newkusingername ;	///写入歌手名
	m_pRecordset->GetFields()->GetItem("sinsex")->Value=(_bstr_t) newkusingersex;////写入性别
	m_pRecordset->GetFields()->GetItem("sinarea")->Value=(_bstr_t) newkusingerarea;////写入地区
	m_pRecordset->GetFields()->GetItem("sinpin")->Value=(_bstr_t)  newkusingerpin;////写入拼音
	
		m_pRecordset->Update();
    	m_AdoConn.ExitConnect();//释放数据库资源
		MessageBox("歌手资料更新成功!","系统提示：",MB_OK|MB_ICONASTERISK);
	CDialog::OnOK();
}
