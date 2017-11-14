// TecrInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "gradudemis.h"
#include "TecrInfoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTecrInfoDlg dialog


CTecrInfoDlg::CTecrInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTecrInfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTecrInfoDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CTecrInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTecrInfoDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTecrInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CTecrInfoDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTecrInfoDlg message handlers
