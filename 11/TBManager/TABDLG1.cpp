// TABDLG1.cpp : implementation file
//

#include "stdafx.h"
#include "TBManager.h"
#include "TABDLG1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTABDLG1 dialog


CTABDLG1::CTABDLG1(CWnd* pParent /*=NULL*/)
	: CDialog(CTABDLG1::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTABDLG1)
	m_tigan = _T("");
	m_xa = _T("");
	m_xb = _T("");
	m_xc = _T("");
	m_xd = _T("");
	m_answer = _T("");
	m_difficulty = _T("");
	m_tno = 0;
	//}}AFX_DATA_INIT
}


void CTABDLG1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTABDLG1)
	DDX_Text(pDX, IDC_EDIT2, m_tigan);
	DDX_Text(pDX, IDC_EDIT3, m_xa);
	DDX_Text(pDX, IDC_EDIT4, m_xb);
	DDX_Text(pDX, IDC_EDIT5, m_xc);
	DDX_Text(pDX, IDC_EDIT6, m_xd);
	DDX_Text(pDX, IDC_EDIT7, m_answer);
	DDX_Text(pDX, IDC_EDIT8, m_difficulty);
	DDX_Text(pDX, IDC_EDIT1, m_tno);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTABDLG1, CDialog)
	//{{AFX_MSG_MAP(CTABDLG1)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTABDLG1 message handlers
