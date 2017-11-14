// ClickSound.h: interface for the ClickSound class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLICKSOUND_H__EBF77B5E_1B6D_4619_AD78_6A1FAB41A6E9__INCLUDED_)
#define AFX_CLICKSOUND_H__EBF77B5E_1B6D_4619_AD78_6A1FAB41A6E9__INCLUDED_

#include "resource.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class ClickSound : public CObject  
{
public:
	ClickSound(UINT nID = IDR_WAVE);
	virtual ~ClickSound();

};

#endif // !defined(AFX_CLICKSOUND_H__EBF77B5E_1B6D_4619_AD78_6A1FAB41A6E9__INCLUDED_)
