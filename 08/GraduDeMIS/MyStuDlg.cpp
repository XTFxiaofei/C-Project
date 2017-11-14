// MyStuDlg.cpp : implementation file
//

#include "stdafx.h"
#include "gradudemis.h"
#include "MyStuDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// MyStuDlg dialog


MyStuDlg::MyStuDlg(CWnd* pParent /*=NULL*/)
	: CDialog(MyStuDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(MyStuDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void MyStuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(MyStuDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(MyStuDlg, CDialog)
	//{{AFX_MSG_MAP(MyStuDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// MyStuDlg message handlers
