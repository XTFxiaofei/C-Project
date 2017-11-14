// ClickSound.cpp: implementation of the ClickSound class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "mtas.h"
#include "ClickSound.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ClickSound::ClickSound(UINT nID)
{
	HINSTANCE hi = AfxGetInstanceHandle();
	CString str;
	str.Format("#%d", nID);
	HRSRC hr = FindResource(hi, (LPCTSTR)str, "WAVE");
	HGLOBAL hg = LoadResource(hi, hr);
	LPVOID lp = LockResource(hg);
	sndPlaySound((LPCTSTR)lp, SND_MEMORY | SND_SYNC);
	FreeResource(hg);
}

ClickSound::~ClickSound()
{

}
