// AdoDatabase.h: interface for the CAdoDatabase class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADODATABASE_H__15EA94B0_759B_44FB_ADB8_95DB11DA8304__INCLUDED_)
#define AFX_ADODATABASE_H__15EA94B0_759B_44FB_ADB8_95DB11DA8304__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class AFX_EXT_CLASS CAdoDatabase : public CObject  
{
public:
	CAdoDatabase();
	virtual ~CAdoDatabase();
	
	BOOL ConnectionDb(const CString& strConfig);

public:
	_ConnectionPtr m_pConnection;
};

#endif // !defined(AFX_ADODATABASE_H__15EA94B0_759B_44FB_ADB8_95DB11DA8304__INCLUDED_)
