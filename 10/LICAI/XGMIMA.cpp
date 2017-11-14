// XGMIMA.cpp : implementation file
//

#include "stdafx.h"
#include "licai.h"
#include "XGMIMA.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// XGMIMA dialog


XGMIMA::XGMIMA(CWnd* pParent /*=NULL*/)
	: CDialog(XGMIMA::IDD, pParent)
{
	//{{AFX_DATA_INIT(XGMIMA)
	m_npassword = _T("");
	m_anpassword = _T("");
	m_password = _T("");
	m_id = _T("");
	//}}AFX_DATA_INIT
}


void XGMIMA::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(XGMIMA)
	DDX_Text(pDX, IDC_EDIT2, m_npassword);
	DDX_Text(pDX, IDC_EDIT3, m_anpassword);
	DDX_Text(pDX, IDC_EDIT4, m_password);
	DDX_Text(pDX, IDC_EDIT1, m_id);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(XGMIMA, CDialog)
	//{{AFX_MSG_MAP(XGMIMA)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// XGMIMA message handlers
