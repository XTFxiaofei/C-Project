// TBManagerDoc.cpp : implementation of the CTBManagerDoc class
//

#include "stdafx.h"
#include "TBManager.h"

#include "TBManagerDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTBManagerDoc

IMPLEMENT_DYNCREATE(CTBManagerDoc, CDocument)

BEGIN_MESSAGE_MAP(CTBManagerDoc, CDocument)
	//{{AFX_MSG_MAP(CTBManagerDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTBManagerDoc construction/destruction

CTBManagerDoc::CTBManagerDoc()
{
	// TODO: add one-time construction code here

}

CTBManagerDoc::~CTBManagerDoc()
{
}

BOOL CTBManagerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTBManagerDoc serialization

void CTBManagerDoc::Serialize(CArchive& ar)
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
// CTBManagerDoc diagnostics

#ifdef _DEBUG
void CTBManagerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTBManagerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTBManagerDoc commands
