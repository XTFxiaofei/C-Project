// ADDSGEDLG.cpp : implementation file
//

#include "stdafx.h"
#include "HCOK.h"
#include "ADDSGEDLG.h"
#include "ADOConn.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ADDSGEDLG dialog


ADDSGEDLG::ADDSGEDLG(CWnd* pParent /*=NULL*/)
	: CDialog(ADDSGEDLG::IDD, pParent)
{
	//{{AFX_DATA_INIT(ADDSGEDLG)
	m_singer = _T("");
	//}}AFX_DATA_INIT
}


void ADDSGEDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ADDSGEDLG)
	DDX_Control(pDX, IDC_COMBO2, m_combo2);
	DDX_Control(pDX, IDC_COMBO1, m_combo1);
	DDX_Text(pDX, IDC_SINGER, m_singer);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ADDSGEDLG, CDialog)
	//{{AFX_MSG_MAP(ADDSGEDLG)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ADDSGEDLG message handlers

void ADDSGEDLG::OnOK() 
{
	
	CString singername,singersex,singerarea,singerpin;
	
	
	GetDlgItem(IDC_SINGER)->GetWindowText(singername);//得到歌手名
	
	int kk=m_combo1.GetCurSel();
	m_combo1.GetLBText(kk,singersex);///////////////////得到歌手性别
	int kk2=m_combo2.GetCurSel();
	m_combo2.GetLBText(kk2,singerarea);///////////////////得到歌手地区
	GetDlgItem(IDC_SGEPIN)->GetWindowText(	singerpin);	//得到歌手拼音
    singersex=singersex+"歌手";  
	////////////////////////////////////////////////////

	ADOConn m_AdoConn;//创建数据库操作对象

	m_AdoConn.OnInitADOConn();  //链接数据库

	_RecordsetPtr m_pRecordset;  //定义记录集
	_bstr_t sql;
		sql = "select* from singer where sinnam='"+singername+"'";//在歌手表中查询歌手
			
				m_pRecordset=m_AdoConn.GetRecordSet(sql);//得到记录集
				if(!m_pRecordset->adoEOF)  //存在该处提示信息
				MessageBox("该歌手已存在,添加失败!","系统提示：",MB_OK|MB_ICONASTERISK);
				else{

	
				m_pRecordset->AddNew();   //如果不存在,就将信息写进数据库
	m_pRecordset->GetFields()->GetItem("sinnam")->Value=(_bstr_t) singername;	///写入歌手名
	m_pRecordset->GetFields()->GetItem("sinsex")->Value=(_bstr_t) singersex;////写入性别
	m_pRecordset->GetFields()->GetItem("sinarea")->Value=(_bstr_t) singerarea;////写入地区
	m_pRecordset->GetFields()->GetItem("sinpin")->Value=(_bstr_t)  singerpin;////写入拼音
		MessageBox("歌手资料添加成功!","系统提示：",MB_OK|MB_ICONASTERISK);
		m_pRecordset->Update();
				}
    	m_AdoConn.ExitConnect();   //释放数据库资源
		
	
	CDialog::OnOK();
}

BOOL ADDSGEDLG::OnInitDialog() 
{
	CDialog::OnInitDialog();
	//*********初始化控件***************************//
    m_combo1.InsertString(0,"男");
    m_combo1.InsertString(1,"女");
    m_combo1.SetCurSel(0);
    m_combo2.InsertString(0,"大陆");
    m_combo2.InsertString(1,"香港");
	m_combo2.InsertString(2,"台湾");
 
	m_combo2.InsertString(3,"日韩");
	m_combo2.InsertString(4,"欧美");
    m_combo2.InsertString(5,"其他");
	 m_combo2.SetCurSel(0);
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
