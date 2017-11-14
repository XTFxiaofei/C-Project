// PROVDLG.cpp : implementation file
//

#include "stdafx.h"
#include "HCDB.h"
#include "PROVDLG.h"
#include "GATHERIN.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPROVDLG dialog

extern CHCDBApp theApp;
CPROVDLG::CPROVDLG(CWnd* pParent /*=NULL*/)
	: CDialog(CPROVDLG::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPROVDLG)
	m_edit1 = _T("");
	m_edit2 = _T("");
	m_edit3 = _T("");
	m_edit4 = _T("");
	//}}AFX_DATA_INIT
	flag=false;
}


void CPROVDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPROVDLG)
	DDX_Control(pDX, IDC_EDIT4, m_edit4ctrl);
	DDX_Control(pDX, IDC_EDIT3, m_edit3ctrl);
	DDX_Control(pDX, IDC_EDIT2, m_edit2ctrl);
	DDX_Control(pDX, IDC_EDIT1, m_edit1ctrl);
	DDX_Control(pDX, IDC_STATIC23, m_hutex23);
	DDX_Control(pDX, IDC_STATIC22, m_hutex22);
	DDX_Control(pDX, IDC_STATIC21, m_hutex21);
	DDX_Control(pDX, IDC_STATIC20, m_hutex20);
	DDX_Control(pDX, IDC_STATIC4, m_m_static3);
	DDX_Control(pDX, IDC_STATIC3, m_m_static);
	DDX_Control(pDX, IDC_STATIC2, m_m_static2);
	DDX_Control(pDX, IDC_STATIC1, m_static1);
	DDX_Text(pDX, IDC_EDIT1, m_edit1);
	DDX_Text(pDX, IDC_EDIT2, m_edit2);
	DDX_Text(pDX, IDC_EDIT3, m_edit3);
	DDX_Text(pDX, IDC_EDIT4, m_edit4);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPROVDLG, CDialog)
	//{{AFX_MSG_MAP(CPROVDLG)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPROVDLG message handlers

void CPROVDLG::SetStaticStyle()
{
	for(int i=0;i<4;i++)
	{
		CString str;
		str.LoadString(IDC_STRING1+i);
		Hutext * cwnd=(Hutext *)GetDlgItem(IDC_STATIC1+i);
		cwnd->SetFontSize(16);
		cwnd->SetTextColor(RGB(0,255,0));
		cwnd->SetBkColor(RGB(0,0,0));
		cwnd->SetFontBold(TRUE);
		cwnd->SetText(str);
	}
	for(int j=0;j<4;j++)
	{
		Hutext * cwnd=(Hutext *)GetDlgItem(IDC_STATIC20+j);
		cwnd->SetFontSize(16);
		cwnd->SetTextColor(RGB(0,255,0));
		cwnd->SetBkColor(RGB(0,0,0));
		cwnd->SetFontBold(TRUE);
	}
}

BOOL CPROVDLG::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_edit1ctrl.SetFocus();
	// TODO: Add extra initialization here
	SetStaticStyle();
	if(flag)
	{
		m_edit1=m_extermprovid;
		flag=false;
		m_edit1ctrl.EnableWindow(false);
	}
	else m_edit1ctrl.EnableWindow(true);
	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPROVDLG::SetEditStyle(int nSize)
{

	queryFont.CreateFont(   
		16,                                                 //   nHeight   
		16,                                                   //   nWidth   
		0,                                                   //   nEscapement   
		0,                                                   //   nOrientation   
		FW_NORMAL,                                   //   nWeight   
		FALSE,                                           //   bItalic   
		FALSE,                                           //   bUnderline   
		0,                                                   //   cStrikeOut   
		DEFAULT_CHARSET,                       //   nCharSet   
		OUT_DEFAULT_PRECIS,                 //   nOutPrecision   
		CLIP_DEFAULT_PRECIS,               //   nClipPrecision   
		DEFAULT_QUALITY,                       //   nQuality   
		DEFAULT_PITCH   |   FF_SWISS,     //   nPitchAndFamily   
		"宋体");                         //   lpszFacename   
    
	m_edit1ctrl.SetFont(&queryFont);
	m_edit2ctrl.SetFont(&queryFont);
	m_edit3ctrl.SetFont(&queryFont);
	m_edit3ctrl.SetFont(&queryFont);

}

HBRUSH CPROVDLG::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	if(pWnd->GetDlgCtrlID()==IDC_EDIT1) 
	{ 
		  pDC->SetBkColor(RGB(0,0,0));
		  pDC-> SetTextColor(RGB(0,255,255)); 
          return ::CreateSolidBrush(RGB(0,0,0)); 
	}    
	if(pWnd->GetDlgCtrlID()==IDC_EDIT2) 
	{ 
		pDC->SetBkColor(RGB(0,0,0));
		pDC-> SetTextColor(RGB(0,255,255)); 
		return ::CreateSolidBrush(RGB(0,0,0)); 
	}    
	if(pWnd->GetDlgCtrlID()==IDC_EDIT3) 
	{ 
		pDC->SetBkColor(RGB(0,0,0));
		pDC-> SetTextColor(RGB(0,255,255)); 
		return ::CreateSolidBrush(RGB(0,0,0)); 
	}    
	if(pWnd->GetDlgCtrlID()==IDC_EDIT4) 
	{ 
		pDC->SetBkColor(RGB(0,0,0));
		pDC-> SetTextColor(RGB(0,255,255)); 
		return ::CreateSolidBrush(RGB(0,0,0)); 
	}    
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CPROVDLG::OnOK() 
{
	// TODO: Add extra validation here
	m_record=NULL;
    m_record.CreateInstance(__uuidof(Recordset));
	CString sqlstr;
	UpdateData();
	sqlstr.Format("insert into tb_provider values('%s','%s','%s','%s')",m_edit1,m_edit2,m_edit3,m_edit4);
	try{
		m_record=theApp.m_connection->Execute(_bstr_t(sqlstr),NULL,adModeUnknown);
	}
	catch(...)
	{
		MessageBox("没有添加成功!");
		
	}
	m_edit1=m_edit2=m_edit3=m_edit4="";
    UpdateData(false);
	CDialog::OnOK();
}
