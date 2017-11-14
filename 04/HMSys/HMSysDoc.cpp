// HMSysDoc.cpp : implementation of the CHMSysDoc class
//

#include "stdafx.h"
#include "HMSys.h"

#include "HMSysDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHMSysDoc

IMPLEMENT_DYNCREATE(CHMSysDoc, CDocument)

BEGIN_MESSAGE_MAP(CHMSysDoc, CDocument)
	//{{AFX_MSG_MAP(CHMSysDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHMSysDoc construction/destruction

CHMSysDoc::CHMSysDoc()
{
	// TODO: add one-time construction code here

}

CHMSysDoc::~CHMSysDoc()
{
}

BOOL CHMSysDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CHMSysDoc serialization

void CHMSysDoc::Serialize(CArchive& ar)
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
// CHMSysDoc diagnostics

#ifdef _DEBUG
void CHMSysDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHMSysDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHMSysDoc commands
