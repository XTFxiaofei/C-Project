// SubOperProPage.cpp : implementation file
//

#include "stdafx.h"
#include "gradudemis.h"
#include "SubOperProPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSubOperProPage property page

IMPLEMENT_DYNCREATE(CSubOperProPage, CPropertyPage)

CSubOperProPage::CSubOperProPage() : CPropertyPage(CSubOperProPage::IDD)
{
	//{{AFX_DATA_INIT(CSubOperProPage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CSubOperProPage::~CSubOperProPage()
{
}

void CSubOperProPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSubOperProPage)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSubOperProPage, CPropertyPage)
	//{{AFX_MSG_MAP(CSubOperProPage)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSubOperProPage message handlers
