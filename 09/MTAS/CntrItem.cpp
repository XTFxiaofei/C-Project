// CntrItem.cpp : implementation of the CMTASCntrItem class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) 1992-1998 Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"
#include "MTAS.h"

#include "MTASDoc.h"
#include "MTASView.h"
#include "CntrItem.h"
#include "mainfrm.h"
//#include "ObjView.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMTASCntrItem implementation

int CMTASCntrItem::m_nDocID = 1;

IMPLEMENT_SERIAL(CMTASCntrItem, COleDocObjectItem, 0)

CMTASCntrItem::CMTASCntrItem(CMTASDoc* pContainer)
	: COleDocObjectItem(pContainer)
{
}

CMTASCntrItem::~CMTASCntrItem()
{
	// TODO: add cleanup code here

}

void CMTASCntrItem::OnChange(OLE_NOTIFICATION nCode, DWORD dwParam)
{
	ASSERT_VALID(this);

	COleDocObjectItem::OnChange(nCode, dwParam);
	GetDocument()->UpdateAllViews(NULL);
}

BOOL CMTASCntrItem::OnChangeItemPosition(const CRect& rectPos)
{
	ASSERT_VALID(this);

	if (!COleDocObjectItem::OnChangeItemPosition(rectPos))
		return FALSE;
	return TRUE;
}

void CMTASCntrItem::OnGetItemPosition(CRect& rPosition)
{
	ASSERT_VALID(this);
	m_pView->GetClientRect(rPosition);
}

void CMTASCntrItem::OnActivate()
{
   CFrameWnd* pFrame = DYNAMIC_DOWNCAST(CFrameWnd, AfxGetApp()->m_pMainWnd);
   ASSERT(pFrame != NULL);

   CWnd* pView = pFrame->GetActiveView();
   ASSERT(pView != NULL);

   COleDocObjectItem* pItem =
	  (COleDocObjectItem*) GetDocument()->GetInPlaceActiveItem(pView);

   // if this isn't the item being activated, deactivate it.
   if (pItem != NULL && pItem != this)
	  pItem->Deactivate();

   COleDocObjectItem::OnActivate();
}

void CMTASCntrItem::OnDeactivateUI(BOOL bUndoable)
{
	COleDocObjectItem::OnDeactivateUI(bUndoable);
}

void CMTASCntrItem::Serialize(CArchive& ar)
{
	ASSERT_VALID(this);

	// Call base class first to read in COleDocObjectItem data.
	// Since this sets up the m_pDocument pointer returned from
	//  CMTASCntrItem::GetDocument, it is a good idea to call
	//  the base class Serialize first.
	COleDocObjectItem::Serialize(ar);

	// now store/retrieve data specific to CMTASCntrItem
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMTASCntrItem diagnostics

#ifdef _DEBUG
void CMTASCntrItem::AssertValid() const
{
	COleDocObjectItem::AssertValid();
}

void CMTASCntrItem::Dump(CDumpContext& dc) const
{
	COleDocObjectItem::Dump(dc);
}
#endif

/////////////////////////////////////////////////////////////////////////////
//

void CMTASCntrItem::ProcessNewObject()
{

}

BOOL CMTASCntrItem::FinishCreate(SCODE sc)
{
	// FinishCreate is an undocumented virtual function that we
	// override here to do some extra processing after the object
	// has been created.

	if (FAILED(sc))
	{
		AfxMessageBox(_T("无法打开指定位置的文件，请检查该文件是否存在或更名!"));
		return FALSE;
	}

	BOOL bRet = COleDocObjectItem::FinishCreate(sc);
	if (bRet)
		ProcessNewObject();
	return bRet;

}

void CMTASCntrItem::LoadFromMoniker(LPUNKNOWN pUnk, OLECHAR* szwName)
{
	HRESULT hr;
	// Ask the system for a URL Moniker
	IMoniker* pIMoniker;
	hr = CreateURLMoniker(NULL, (LPWSTR)szwName, &pIMoniker);
	if ( SUCCEEDED(hr) )
	{
		// Get the IPersistMoniker interface
		IPersistMoniker* pPMk;
		hr = pUnk->QueryInterface(
								IID_IPersistMoniker,
								(void **)&pPMk);
		if ( SUCCEEDED(hr) )
		{
				// note: do not register our BSC when calling IPM::Load directly
			IBindCtx *pBCtx;
			hr = CreateBindCtx(0, &pBCtx);
			if ( SUCCEEDED(hr) )
			{
				// Call Load on the IPersistMoniker
				hr = pPMk->Load(FALSE, pIMoniker, pBCtx, STGM_READ);
					pBCtx->Release();
			}
			pPMk->Release();
		}
		pIMoniker->Release( );
	}
}
