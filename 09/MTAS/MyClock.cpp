// MyClock.cpp : implementation file
//

#include "stdafx.h"
#include "mtas.h"
#include "MyClock.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyClock

CMyClock::CMyClock()
{
}

CMyClock::~CMyClock()
{
}


BEGIN_MESSAGE_MAP(CMyClock, CClockST)
	//{{AFX_MSG_MAP(CMyClock)
	ON_COMMAND(ID_CLOCK_CLOSE, OnClockClose)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyClock message handlers

CSize CMyClock::GetClockSize()
{
	return CSize(m_bmInfoClock.bmWidth, m_bmInfoClock.bmHeight);
}

void CMyClock::OnClockClose() 
{
	ShowWindow(SW_HIDE);	
}
