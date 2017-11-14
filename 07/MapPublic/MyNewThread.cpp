// MyNewThread.cpp : implementation file
//

#include "stdafx.h"
#include "mappublic.h"
#include "MyNewThread.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyNewThread
CFindDlg *m_finddlg;


IMPLEMENT_DYNCREATE(CMyNewThread, CWinThread)

CMyNewThread::CMyNewThread()
{
	m_finddlg=NULL;
}

CMyNewThread::~CMyNewThread()
{
}

BOOL CMyNewThread::InitInstance()
{
	 if(m_finddlg==NULL)
	  {
		   m_finddlg=new CFindDlg();
		   m_finddlg->Create(IDD_DIALOG_FIND);
		   CRect rect;
		   m_finddlg->GetWindowRect(&rect);
		   m_finddlg->SetWindowPos(NULL ,300,300,rect.Width(),rect.Height(),SWP_SHOWWINDOW);
	   }
	   else
	   {
		   delete m_finddlg;
		   m_finddlg=NULL;
	   }
	
		return TRUE;
}

int CMyNewThread::ExitInstance()
{

	
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CMyNewThread, CWinThread)
	//{{AFX_MSG_MAP(CMyNewThread)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyNewThread message handlers
