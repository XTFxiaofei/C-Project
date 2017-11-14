// SubQueryProPage.cpp : implementation file
//

#include "stdafx.h"
#include "gradudemis.h"
#include "SubQueryProPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSubQueryProPage property page

IMPLEMENT_DYNCREATE(CSubQueryProPage, CPropertyPage)

CSubQueryProPage::CSubQueryProPage() : CPropertyPage(CSubQueryProPage::IDD)
{
	//{{AFX_DATA_INIT(CSubQueryProPage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CSubQueryProPage::~CSubQueryProPage()
{
}

void CSubQueryProPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSubQueryProPage)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSubQueryProPage, CPropertyPage)
	//{{AFX_MSG_MAP(CSubQueryProPage)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSubQueryProPage message handlers
