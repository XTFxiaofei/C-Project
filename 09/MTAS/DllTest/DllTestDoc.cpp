// DllTestDoc.cpp : implementation of the CDllTestDoc class
//

#include "stdafx.h"
#include "DllTest.h"

#include "DllTestDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDllTestDoc

IMPLEMENT_DYNCREATE(CDllTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CDllTestDoc, CDocument)
	//{{AFX_MSG_MAP(CDllTestDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDllTestDoc construction/destruction

CDllTestDoc::CDllTestDoc()
{
	// TODO: add one-time construction code here

}

CDllTestDoc::~CDllTestDoc()
{
}

BOOL CDllTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDllTestDoc serialization

void CDllTestDoc::Serialize(CArchive& ar)
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
// CDllTestDoc diagnostics

#ifdef _DEBUG
void CDllTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDllTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDllTestDoc commands
