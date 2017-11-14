// PASSDLG.cpp : implementation file
//

#include "stdafx.h"
#include "HCDB.h"
#include "PASSDLG.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PASSDLG dialog


PASSDLG::PASSDLG(CWnd* pParent /*=NULL*/)
	: CDialog(PASSDLG::IDD, pParent)
{
	//{{AFX_DATA_INIT(PASSDLG)
	m_user = _T("");
	m_pass = _T("");
	//}}AFX_DATA_INIT
}


void PASSDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PASSDLG)
	DDX_Text(pDX, IDC_EDIT1, m_user);
	DDX_Text(pDX, IDC_EDIT2, m_pass);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PASSDLG, CDialog)
	//{{AFX_MSG_MAP(PASSDLG)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PASSDLG message handlers


