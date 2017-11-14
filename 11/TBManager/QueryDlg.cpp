// QueryDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TBManager.h"
#include "QueryDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// QueryDlg dialog


QueryDlg::QueryDlg(CWnd* pParent /*=NULL*/)
	: CDialog(QueryDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(QueryDlg)
	m_condition = _T("");
	//}}AFX_DATA_INIT
}


void QueryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(QueryDlg)
	DDX_Text(pDX, IDC_EDIT1, m_condition);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(QueryDlg, CDialog)
	//{{AFX_MSG_MAP(QueryDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// QueryDlg message handlers
