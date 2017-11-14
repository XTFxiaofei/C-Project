// AdoDatabase.cpp: implementation of the CAdoDatabase class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AdoDatabase.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CAdoDatabase::CAdoDatabase()
{

}

CAdoDatabase::~CAdoDatabase()
{
	if(m_pConnection->State)
	{
		m_pConnection->Close();
		m_pConnection = NULL;
	}
}

BOOL CAdoDatabase::ConnectionDb(const CString& strConfig)
{
	//	create ADO connection
	m_pConnection.CreateInstance(__uuidof(Connection));

	try {	
		m_pConnection->Open((_bstr_t)strConfig, "", "", adModeUnknown);
	} catch (_com_error e) {
		CString strError;
		strError.Format(_T("warning£ºexception in opening connection, error info£º %s"), 
			e.ErrorMessage());
		AfxMessageBox(strError);
		return FALSE;
	}
	return TRUE;
}

