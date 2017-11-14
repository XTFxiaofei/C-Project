// TABDLG3.cpp : implementation file
//

#include "stdafx.h"
#include "TBManager.h"
#include "TABDLG3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTABDLG3 dialog


CTABDLG3::CTABDLG3(CWnd* pParent /*=NULL*/)
	: CDialog(CTABDLG3::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTABDLG3)
	m_tigan = _T("");
	m_ka = _T("");
	m_kb = _T("");
	m_kc = _T("");
	m_kd = _T("");
	m_difficulty = _T("");
	m_tno = 0;
	//}}AFX_DATA_INIT
}


void CTABDLG3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTABDLG3)
	DDX_Text(pDX, IDC_EDIT2, m_tigan);
	DDX_Text(pDX, IDC_EDIT3, m_ka);
	DDX_Text(pDX, IDC_EDIT4, m_kb);
	DDX_Text(pDX, IDC_EDIT5, m_kc);
	DDX_Text(pDX, IDC_EDIT6, m_kd);
	DDX_Text(pDX, IDC_EDIT7, m_difficulty);
	DDX_Text(pDX, IDC_EDIT1, m_tno);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTABDLG3, CDialog)
	//{{AFX_MSG_MAP(CTABDLG3)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTABDLG3 message handlers
