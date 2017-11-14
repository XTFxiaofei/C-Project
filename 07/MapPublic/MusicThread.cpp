// MusicThread.cpp : implementation file
//

#include "stdafx.h"
#include "mappublic.h"
#include "MusicThread.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include<MMSYSTEM.H>
/////////////////////////////////////////////////////////////////////////////
// CMusicThread

IMPLEMENT_DYNCREATE(CMusicThread, CWinThread)

CMusicThread::CMusicThread()
{
}

CMusicThread::~CMusicThread()
{
}

BOOL CMusicThread::InitInstance()
{
	PlayResource(IDR_WAVE4);//≤•∑≈“Ù¿÷
	return TRUE;
}

int CMusicThread::ExitInstance()
{
	// TODO:  perform any per-thread cleanup here
	PlayResource(IDR_WAVE5);
	return CWinThread::ExitInstance();
}


BOOL CMusicThread::PlayResource(WORD wResourceID)
{	
	// Get the handle to the current instance of the application
	HINSTANCE hInstance = AfxGetInstanceHandle();
    ASSERT (hInstance != NULL);
	
	// Find the WAVE resource
	HRSRC hResInfo = 
		FindResource(hInstance, MAKEINTRESOURCE(wResourceID), _T("WAVE"));
	if(hResInfo == NULL)
		return FALSE;
	
	// Load the WAVE resource
    HANDLE hRes = LoadResource(hInstance, hResInfo);
	if (hRes == NULL)
		return FALSE;
    
	// Lock the WAVE resource and play it
    LPSTR lpRes = (LPSTR) LockResource(hRes);
	if(lpRes==NULL)
		return FALSE;
    
	if (sndPlaySound(lpRes, SND_MEMORY | SND_ASYNC) == NULL)
		return FALSE;	
	
    // Free the WAVE resource and return success or failure.
    FreeResource(hRes);
	return TRUE;
}

BEGIN_MESSAGE_MAP(CMusicThread, CWinThread)
	//{{AFX_MSG_MAP(CMusicThread)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMusicThread message handlers
