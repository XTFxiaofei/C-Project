// MapPublicDoc.cpp : implementation of the CMapPublicDoc class
//

#include "stdafx.h"
#include "MapPublic.h"
#include "MapPublicView.h"
#include "MapPublicDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMapPublicDoc

IMPLEMENT_DYNCREATE(CMapPublicDoc, CDocument)

BEGIN_MESSAGE_MAP(CMapPublicDoc, CDocument)
	//{{AFX_MSG_MAP(CMapPublicDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMapPublicDoc construction/destruction

CMapPublicDoc::CMapPublicDoc()
{
	// TODO: add one-time construction code here

}

CMapPublicDoc::~CMapPublicDoc()
{
}

BOOL CMapPublicDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMapPublicDoc serialization

void CMapPublicDoc::Serialize(CArchive& ar)
{
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
// CMapPublicDoc diagnostics

#ifdef _DEBUG
void CMapPublicDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMapPublicDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMapPublicDoc commands

