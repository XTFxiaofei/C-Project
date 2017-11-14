// ClassRecordset.cpp: implementation of the CClassRecordset class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ClassRecordset.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CClassRecordset::CClassRecordset()
{

}

CClassRecordset::CClassRecordset(CAdoDatabase* pDB)
{
	m_pDB = pDB;
}

CClassRecordset::~CClassRecordset()
{

}

int CClassRecordset::Query(const CString& strSQL, vector<ClassTableItem>& vecCTI, 
						 const CString& strSort)
{
	int nRet = 0;

	if(!OpenRecordset(strSQL)) 
		return -1;	//	fail

	m_pRecordset->Sort = _bstr_t(strSort);

	if(!m_pRecordset->BOF) {
		m_pRecordset->MoveFirst();
	}
	
	_variant_t varValue;
	while(!m_pRecordset->adoEOF)
	{
		++nRet;
		ClassTableItem cti;
		//	id
		varValue = m_pRecordset->GetFields()->GetItem(_T("id"))->Value;
		cti.m_lID = atol(VariantToCString(varValue));
		//	name
		varValue = m_pRecordset->GetFields()->GetItem(_T("name"))->Value;
		cti.m_strName = VariantToCString(varValue);
		///////////////////////////////////////
		vecCTI.push_back(cti);
		m_pRecordset->MoveNext();
	}
	
	m_pRecordset->Close();
	m_pRecordset=NULL;

	return nRet;	//	have not found
}	

int CClassRecordset::Insert(const ClassTableItem& cti)
{
	CString strSQL;
	strSQL.Format(_T("SELECT * FROM `class` WHERE `name`='%s'"), cti.m_strName);
	if(!OpenRecordset(strSQL))
	{
		AfxMessageBox("Fail to open the table!");
		return 0;
	}

	//	avoid inserting the same item
	if(!m_pRecordset->adoEOF)
		return 0;

	//	insert new item
	try
	{		
		m_pRecordset->AddNew();
		m_pRecordset->PutCollect("name",    _variant_t(cti.m_strName));
		//	update the database
		m_pRecordset->Update();				
		m_pRecordset->MoveLast();
	}
	catch(_com_error e)
	{
		CString strError;
		strError.Format(_T("warning£ºexception in inserting, error info£º %s"),\
			e.ErrorMessage());
		AfxMessageBox(strError);
	}
	m_pRecordset->Close();	
	m_pRecordset = NULL;

	return 1;	//	success
}

int CClassRecordset::Delete(const CString& strSQL)
{
	if(!OpenRecordset(strSQL))
	{
		AfxMessageBox("Fail to open the table!");
		return 0;
	}	

	if(m_pRecordset->adoEOF)	//	not found
		return 0;	

	//	delete from the database
	try
	{
		m_pRecordset->MoveFirst();
		while(!m_pRecordset->adoEOF) {
			m_pRecordset->Delete(adAffectCurrent);
			m_pRecordset->MoveNext();
		}
	}
	catch(_com_error e)
	{
		CString strError;
		strError.Format(_T("warning£ºexception in deleting, error info£º %s"),\
			e.ErrorMessage());
		AfxMessageBox(strError);
	}

	m_pRecordset->Close();
	m_pRecordset = NULL;	

	return 1;	//	success
}

int CClassRecordset::Modify(const CString& strSQL, const ClassTableItem& cti)
{	
	if(!OpenRecordset(strSQL))
	{
		AfxMessageBox(_T("Fail to open the table!"));
		return 0;
	}
	if(m_pRecordset->adoEOF) {
		AfxMessageBox(_T("Fail to find the record to be modified!"));
		return 0;
	}
	
	try
	{
		m_pRecordset->MoveFirst();
		while(!m_pRecordset->adoEOF) {
			if(!cti.m_strName.IsEmpty())
				m_pRecordset->PutCollect("name", _variant_t(cti.m_strName));			
			m_pRecordset->MoveNext();
		}
		m_pRecordset->Update();		
		m_pRecordset->MoveLast();
	}
	catch(_com_error e)
	{
		CString strError;
		strError.Format(_T("warning£ºexception in modifying, error info£º %s"),\
			e.ErrorMessage());
		AfxMessageBox(strError);
	}
	m_pRecordset->Close();	
	m_pRecordset = NULL;

	return 1;	//	success
}



long CClassRecordset::GetClassID(const CString &strClassName)
{
	vector<ClassTableItem> cti;
	CString strSQL;
	strSQL.Format(_T("SELECT * FROM `class` WHERE `name`='%s'"), strClassName);
	Query(strSQL, cti);
	
	ASSERT(cti.size() == 1);
	return cti[0].m_lID;
}
