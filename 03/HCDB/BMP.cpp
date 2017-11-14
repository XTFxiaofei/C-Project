// BMP.cpp : implementation file
//

#include "stdafx.h"
#include "HCDB.h"
#include "BMP.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBMP dialog


CBMP::CBMP(CWnd* pParent /*=NULL*/)
	: CDialog(CBMP::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBMP)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CBMP::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBMP)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBMP, CDialog)
	//{{AFX_MSG_MAP(CBMP)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBMP message handlers
