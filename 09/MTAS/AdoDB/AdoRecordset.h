// AdoRecordset.h: interface for the CAdoRecordset class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADORECORDSET_H__29C0DB6A_418E_4513_85A6_ABEB67CEAED3__INCLUDED_)
#define AFX_ADORECORDSET_H__29C0DB6A_418E_4513_85A6_ABEB67CEAED3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class AFX_EXT_CLASS CAdoRecordset : public CObject  
{
protected:
	CAdoRecordset();

public:
	virtual ~CAdoRecordset();
	void SetDatabase(CAdoDatabase* pDB);

protected:
	BOOL OpenRecordset(const CString &strSQL);
	CString VariantToCString(const _variant_t &var);

	_RecordsetPtr  m_pRecordset;
	CAdoDatabase*  m_pDB;
};

#endif // !defined(AFX_ADORECORDSET_H__29C0DB6A_418E_4513_85A6_ABEB67CEAED3__INCLUDED_)
