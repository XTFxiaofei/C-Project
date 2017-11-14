// TABDLG4.cpp : implementation file
//

#include "stdafx.h"
#include "TBManager.h"
#include "TABDLG4.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTABDLG4 dialog


CTABDLG4::CTABDLG4(CWnd* pParent /*=NULL*/)
	: CDialog(CTABDLG4::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTABDLG4)
	m_tigan = _T("");
	m_answer = _T("");
	m_difficulty = _T("");
	m_tno = 0;
	//}}AFX_DATA_INIT
}


void CTABDLG4::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTABDLG4)
	DDX_Text(pDX, IDC_EDIT2, m_tigan);
	DDX_Text(pDX, IDC_EDIT3, m_answer);
	DDX_Text(pDX, IDC_EDIT4, m_difficulty);
	DDX_Text(pDX, IDC_EDIT1, m_tno);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTABDLG4, CDialog)
	//{{AFX_MSG_MAP(CTABDLG4)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTABDLG4 message handlers
