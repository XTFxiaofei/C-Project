// XSCJXG.cpp : implementation file
//

#include "stdafx.h"
#include "HCCP.h"
#include "XSCJXG.h"
#include "ADOConn.h"
#include "HCCPDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// XSCJXG dialog


XSCJXG::XSCJXG(CWnd* pParent /*=NULL*/)
: CDialog(XSCJXG::IDD, pParent)
{
	//{{AFX_DATA_INIT(XSCJXG)
	m_sgrade = 0.0;
	m_sno = _T("");
	m_sname = _T("");
	//}}AFX_DATA_INIT
}


void XSCJXG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(XSCJXG)
	DDX_Control(pDX, IDC_SPIN1, m_spin);
	DDX_Text(pDX, IDC_SGRADE, m_sgrade);
	DDX_Text(pDX, IDC_SNO, m_sno);
	DDX_Text(pDX, IDC_SNAME, m_sname);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(XSCJXG, CDialog)
//{{AFX_MSG_MAP(XSCJXG)
ON_EN_CHANGE(IDC_SGRADE, OnChangeSgrade)
ON_BN_CLICKED(IDC_XIU, OnXiu)
ON_BN_CLICKED(IDC_DELCY, OnDelcy)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// XSCJXG message handlers

void XSCJXG::OnChangeSgrade() 
{
	
	
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

BOOL XSCJXG::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_spin.SetPos(0);
	m_spin.SetRange(0,100);  //设置微调按钮范围
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void XSCJXG::OnXiu() 
{
	UpdateData();
	CHCCPDlg* pdlg=(CHCCPDlg*)GetParent();  //获取父窗口对话框指针
	CString sqlstr,sqlstr1;
	m_sno.TrimRight();
	str1112.TrimRight();
	if(nCount==4)
	{
		try
		{
			sqlstr.Format("update grade set sgrade='%f' \
			where sno='%s'and cno='%s'",m_sgrade,m_sno,str1112);  //修改学生成绩
			sqlstr1.Format("update student set sname='%s' \
			where sno='%s'",m_sname,m_sno);  //修改学生成绩
			vSQL112=(_bstr_t)sqlstr;
			m_ado.ExecuteSQL(vSQL112);
			vSQL112=(_bstr_t)sqlstr1;
			m_ado.ExecuteSQL(vSQL112);
			AfxMessageBox("修改成功!");
		}
		catch(...)  //捕获异常状态
		{
			AfxMessageBox("修改失败!");
		}
	}
	flag123=false;
}

void XSCJXG::OnDelcy() 
{
	if(m_sno!="")
	{
		if(MessageBox("要删除吗?","注意",MB_YESNO|MB_ICONINFORMATION)==IDYES)
		{
			if(nCount==3)
			{
				CString str,str1;
				str.Format("delete from student where sno='%s'",m_sno);
				str1.Format("delete from grade where sno='%s'",m_sno);
				_bstr_t vSQL0,vSQL1;
				vSQL0=(_bstr_t)str;
				vSQL1=(_bstr_t)str1;
				m_ado.ExecuteSQL(vSQL0);
				m_ado.ExecuteSQL(vSQL1);
				flag123=false;
				MessageBox("删除成功!");
			}
			else if(nCount==4)
			{
				CString str1,str2,str3,str4;
				_variant_t qiguai;
				str2=leaf111;
				str2.TrimRight();
				str3.Format("select cno from class where cname='%s'",str2);
				_bstr_t vSQL12;
				vSQL12=(_bstr_t)str3;
				_RecordsetPtr m_pre;
				m_pre=m_ado.GetRecordSet(vSQL12);
				qiguai=m_pre->GetCollect("cno");
				str4=(LPCTSTR)(_bstr_t)qiguai;
				str1.Format("delete from grade where sno='%s' and cno='%s'",m_sno,str4);
				_bstr_t vSQL1;
				vSQL1=(_bstr_t)str1;
				m_ado.ExecuteSQL(vSQL1);
				flag123=false;
				MessageBox("删除成功!");
			}
			m_sno="";
			m_sgrade=0;
			UpdateData(false);
		}
	}
	else
		MessageBox("请选择要删除的成员!");
}
