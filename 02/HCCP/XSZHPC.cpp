// XSZHPC.cpp : implementation file
//

#include "stdafx.h"
#include "HCCP.h"
#include "XSZHPC.h"
#include "ZHPCDLG.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// XSZHPC dialog


XSZHPC::XSZHPC(CWnd* pParent /*=NULL*/)
: CDialog(XSZHPC::IDD, pParent)
{
	
	//{{AFX_DATA_INIT(XSZHPC)
	// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void XSZHPC::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(XSZHPC)
	DDX_Control(pDX, IDC_BANJI, m_banji);
	DDX_Control(pDX, IDC_XUEYUAN, m_xueyuan);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(XSZHPC, CDialog)
//{{AFX_MSG_MAP(XSZHPC)
ON_BN_CLICKED(IDC_ZHPCBT, OnZhpcbt)
ON_CBN_SELCHANGE(IDC_XUEYUAN, OnSelchangeXueyuan)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// XSZHPC message handlers

BOOL XSZHPC::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_xueyuan.SetCurSel(0);
	m_banji.SetCurSel(0);
	row=3;
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

/*---------------------选择综合测评班级----------------------*/

void XSZHPC::OnZhpcbt() 
{
	int k=m_xueyuan.GetCurSel();
	m_xueyuan.GetLBText(k,temp);
	int l=m_banji.GetCurSel();
	m_banji.GetLBText(l,temp1);
	str1212=temp1;
	ZHPCDLG zhpcdlg;
	zhpcdlg.DoModal();	
}

/*---------------------通过事件监听----------------------*/

void XSZHPC::OnSelchangeXueyuan() 
{
	CString str,zhao;
	int k=m_xueyuan.GetCurSel();
	m_xueyuan.GetLBText(k,zhao);
	str.Format("select * from tree where root='%s'",zhao);  
	_bstr_t vSQL;
	vSQL=(_bstr_t)str;
	m_pRc=myado.GetRecordSet(vSQL);  //获取结点下所有子结点记录集
	for(;row>=0;row--)  //通过for循环删除下拉菜单所有内容
		m_banji.DeleteString(row);  
	k=0;
	_bstr_t leaf;
	CString str1;
	do
	{
		leaf=m_pRc->GetCollect("leaf");  //获取子结点记录
		
		str1=(LPCTSTR)(_bstr_t)leaf;
		str1.TrimRight();
		m_banji.InsertString(k,str1);  //添加班级下拉菜单中的属性	
		m_pRc->MoveNext();  //指针指向下一条记录
		k++;
	}
	while
		(!m_pRc->adoEOF);
	row=k;
	m_banji.SetCurSel(0);
}

