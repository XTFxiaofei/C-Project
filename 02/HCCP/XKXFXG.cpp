// XKXFXG.cpp : implementation file
//

#include "stdafx.h"
#include "HCCP.h"
#include "XKXFXG.h"
#include "ADOConn.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// XKXFXG dialog


XKXFXG::XKXFXG(CWnd* pParent /*=NULL*/)
	: CDialog(XKXFXG::IDD, pParent)
{
	//{{AFX_DATA_INIT(XKXFXG)
	m_xkm = _T("");
	m_xuekf = 0.0f;
	//}}AFX_DATA_INIT
}


void XKXFXG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(XKXFXG)
	DDX_Text(pDX, IDC_XKM, m_xkm);
	DDX_Text(pDX, IDC_XUEKF, m_xuekf);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(XKXFXG, CDialog)
	//{{AFX_MSG_MAP(XKXFXG)
	ON_BN_CLICKED(IDC_XFXG, OnXfxg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// XKXFXG message handlers

void XKXFXG::OnXfxg() 
{
	UpdateData();
	ADOConn ado;
	_bstr_t vSQL;
	CString sqlstr;
	if(nCount==4)
	{
		try
		{
			sqlstr.Format("update class set cgrade='%f' where cname='%s'",m_xuekf,m_xkm);  //通过update语句更新数据库内容
			vSQL=(_bstr_t)sqlstr;
			ado.ExecuteSQL(vSQL);  //执行sql语句
			AfxMessageBox("修改成功!");
		}
		catch(...)
		{
			AfxMessageBox("修改失败!");
		}
	}
}
