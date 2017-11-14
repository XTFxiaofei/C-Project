// MyListBox.cpp : implementation file
//

#include "stdafx.h"
#include "mtas.h"
#include "MyListBox.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyListBox

CMyListBox::CMyListBox()
{
}

CMyListBox::~CMyListBox()
{
}


BEGIN_MESSAGE_MAP(CMyListBox, CListBox)
	//{{AFX_MSG_MAP(CMyListBox)
	ON_WM_MEASUREITEM_REFLECT()
	ON_WM_DRAWITEM_REFLECT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyListBox message handlers

void CMyListBox::MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct) 
{
	// TODO: Add your message handler code here
	
}

void CMyListBox::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	// TODO: Add your message handler code here
	
}
