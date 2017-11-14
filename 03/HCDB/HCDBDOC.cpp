// HCDBDoc.cpp : implementation of the CHCDBDoc class
//

#include "stdafx.h"
#include "HCDB.h"

#include "HCDBDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHCDBDoc

IMPLEMENT_DYNCREATE(CHCDBDoc, CDocument)

BEGIN_MESSAGE_MAP(CHCDBDoc, CDocument)
	//{{AFX_MSG_MAP(CHCDBDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHCDBDoc construction/destruction

CHCDBDoc::CHCDBDoc()
{
	// TODO: add one-time construction code here

}

CHCDBDoc::~CHCDBDoc()
{
}

BOOL CHCDBDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CHCDBDoc serialization

void CHCDBDoc::Serialize(CArchive& ar)
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
// CHCDBDoc diagnostics

#ifdef _DEBUG
void CHCDBDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHCDBDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHCDBDoc commands
