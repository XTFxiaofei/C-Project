// PAGE5.cpp : implementation file
//

#include "stdafx.h"
#include "LICAI.h"
#include "PAGE5.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PAGE5 dialog


PAGE5::PAGE5(CWnd* pParent /*=NULL*/)
	: CDialog(PAGE5::IDD, pParent)
{
	//{{AFX_DATA_INIT(PAGE5)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void PAGE5::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PAGE5)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PAGE5, CDialog)
	//{{AFX_MSG_MAP(PAGE5)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PAGE5 message handlers
