// SectionRecordset.cpp: implementation of the CSectionRecordset class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SectionRecordset.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construstion/Destrustion
//////////////////////////////////////////////////////////////////////

CSectionRecordset::CSectionRecordset()
{

}

CSectionRecordset::CSectionRecordset(CAdoDatabase* pDB)
{
	m_pDB = pDB;
}

CSectionRecordset::~CSectionRecordset()
{

}

int CSectionRecordset::Query(const CString& strSQL, vector<SectionTableItem>& vecSTI, 
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
		SectionTableItem sti;
		//	id
		varValue = m_pRecordset->GetFields()->GetItem(_T("id"))->Value;
		sti.m_lID = atoi(VariantToCString(varValue));
		//	classid
		varValue = m_pRecordset->GetFields()->GetItem(_T("chapterid"))->Value;
		sti.m_lChapterID = atoi(VariantToCString(varValue));
		//	name
		varValue = m_pRecordset->GetFields()->GetItem(_T("name"))->Value;
		sti.m_strName = VariantToCString(varValue);
		///////////////////////////////////////
		vecSTI.push_back(sti);
		m_pRecordset->MoveNext();
	}
	
	m_pRecordset->Close();
	m_pRecordset = NULL;

	return nRet;	//	have not found
}	

int CSectionRecordset::Insert(const SectionTableItem& sti)
{
	CString strSQL;
	strSQL.Format(_T("SELECT * FROM `section` WHERE `chapterid`=%ld AND `name`='%s'"), 
		sti.m_lChapterID, sti.m_strName);
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
		m_pRecordset->PutCollect("chapterid", _variant_t(sti.m_lChapterID));
		m_pRecordset->PutCollect("name",      _variant_t(sti.m_strName));
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

int CSectionRecordset::Delete(const CString& strSQL)
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

int CSectionRecordset::Modify(const CString& strSQL, const SectionTableItem& sti)
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
			m_pRecordset->PutCollect("chapterid", _variant_t(sti.m_lChapterID));
			if(!sti.m_strName.IsEmpty())
				m_pRecordset->PutCollect("name", _variant_t(sti.m_strName));			
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
