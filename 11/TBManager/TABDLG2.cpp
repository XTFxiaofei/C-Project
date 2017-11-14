// TABDLG2.cpp : implementation file
//

#include "stdafx.h"
#include "TBManager.h"
#include "TABDLG2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTABDLG2 dialog


CTABDLG2::CTABDLG2(CWnd* pParent /*=NULL*/)
	: CDialog(CTABDLG2::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTABDLG2)
	m_tigan = _T("");
	m_answer = _T("");
	m_difficulty = _T("");
	m_tno = 0;
	//}}AFX_DATA_INIT
}


void CTABDLG2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTABDLG2)
	DDX_Text(pDX, IDC_EDIT2, m_tigan);
	DDX_Text(pDX, IDC_EDIT3, m_answer);
	DDX_Text(pDX, IDC_EDIT4, m_difficulty);
	DDX_Text(pDX, IDC_EDIT1, m_tno);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTABDLG2, CDialog)
	//{{AFX_MSG_MAP(CTABDLG2)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTABDLG2 message handlers
