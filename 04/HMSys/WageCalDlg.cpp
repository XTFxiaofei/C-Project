// WageCalDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hmsys.h"
#include "WageCalDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWageCalDlg dialog
extern CHMSysApp theApp;

CWageCalDlg::CWageCalDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWageCalDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWageCalDlg)
	m_bingjia = 0;
	m_chuchai = 0;
	m_fading = 0;
	m_pingshi = 0;
	m_shijia = 0;
	m_shuangxiu = 0;
	//}}AFX_DATA_INIT
}


void CWageCalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWageCalDlg)
	DDX_Text(pDX, IDC_BINGJIA, m_bingjia);
	DDX_Text(pDX, IDC_CHUCHAI, m_chuchai);
	DDX_Text(pDX, IDC_FADING, m_fading);
	DDX_Text(pDX, IDC_PINGSHI, m_pingshi);
	DDX_Text(pDX, IDC_SHIJIA, m_shijia);
	DDX_Text(pDX, IDC_SHUANGXIU, m_shuangxiu);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWageCalDlg, CDialog)
	//{{AFX_MSG_MAP(CWageCalDlg)
	ON_BN_CLICKED(IDC_SURE, OnSure)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWageCalDlg message handlers

BOOL CWageCalDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_pRecordset.CreateInstance("ADODB.Recordset");	
	CString strSQL;					//定义字符串变量
	strSQL.Format("select * from wagecal");
	_variant_t va;
	try
	{
		m_pRecordset = theApp.m_pConnection->Execute((_bstr_t)strSQL, NULL, adCmdText);
		va = m_pRecordset->GetCollect(_variant_t((long)0));//获取记录集中第一列的数据
		m_chuchai = va.iVal;
		va = m_pRecordset->GetCollect(_variant_t((long)1));
		m_bingjia = va.iVal;
		va = m_pRecordset->GetCollect(_variant_t((long)2));
		m_shijia = va.iVal;
		va = m_pRecordset->GetCollect(_variant_t((long)3));
		m_pingshi = va.iVal;
		va = m_pRecordset->GetCollect(_variant_t((long)4));
		m_shuangxiu = va.iVal;
		va = m_pRecordset->GetCollect(_variant_t((long)5));
		m_fading = va.iVal;
	}
	CATCH_ERROR;
	UpdateData(FALSE);//数据的更新
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CWageCalDlg::OnSure() 
{
	UpdateData();					//数据的更新
	CString strSQL;					//定义字符串变量
	strSQL.Format("update wagecal set chuchai = %d, bingjia = %d, shijia = %d, pingshi = %d, shuangxiu = %d, fading = %d", 
		m_chuchai, m_bingjia, m_shijia, m_pingshi, m_shuangxiu, m_fading);
	try
	{
		m_pRecordset = theApp.m_pConnection->Execute((_bstr_t)strSQL, NULL, adCmdText);
		MessageBox("设置成功！");//执行SQL语句
	}
	CATCH_ERROR;
}
