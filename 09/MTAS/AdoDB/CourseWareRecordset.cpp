// CourseWareRecordset.cpp: implementation of the CCourseWareRecordset class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CourseWareRecordset.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCourseWareRecordset::CCourseWareRecordset()
{
}

CCourseWareRecordset::CCourseWareRecordset(CAdoDatabase* pDB)
{
	m_pDB = pDB;
}

CCourseWareRecordset::~CCourseWareRecordset()
{

}

int CCourseWareRecordset::Query(const CString& strSQL, vector<CCourseWareInfo>& vecCWInfo, 
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
		CCourseWareInfo cwi;
		//	name
		varValue = m_pRecordset->GetFields()->GetItem(_T("name"))->Value;
		cwi.m_strName = VariantToCString(varValue);
		//	type
		varValue = m_pRecordset->GetFields()->GetItem(_T("type"))->Value;
		cwi.m_strType = VariantToCString(varValue);
		//	size
		varValue = m_pRecordset->GetFields()->GetItem(_T("size"))->Value;
		cwi.m_lSize = _ttol(VariantToCString(varValue));
		//	path
		varValue = m_pRecordset->GetFields()->GetItem(_T("path"))->Value;
		cwi.m_strPath = VariantToCString(varValue);
		//	modtime
		varValue = m_pRecordset->GetFields()->GetItem(_T("modtime"))->Value;
		cwi.m_strModTime = VariantToCString(varValue);
		//	class
		varValue = m_pRecordset->GetFields()->GetItem(_T("class"))->Value;
		cwi.m_strClass = VariantToCString(varValue);
		//	chapter
		varValue = m_pRecordset->GetFields()->GetItem(_T("chapter"))->Value;
		cwi.m_strChapter = VariantToCString(varValue);
		//	section
		varValue = m_pRecordset->GetFields()->GetItem(_T("section"))->Value;
		cwi.m_strSection = VariantToCString(varValue);
		///////////////////////////////////////
		vecCWInfo.push_back(cwi);
		m_pRecordset->MoveNext();
	}
	
	m_pRecordset->Close();
	m_pRecordset=NULL;

	return nRet;	//	have not found
}	

int CCourseWareRecordset::Insert(const CCourseWareInfo& cwi)
{
	CString strSQL;
	strSQL.Format(_T("SELECT * FROM `cw` WHERE `name`='%s' AND `type`='%s' AND \
		`class`='%s' AND `chapter`='%s' AND `section`='%s' AND `size`=%ld"), 
		cwi.m_strName, cwi.m_strType, cwi.m_strClass, cwi.m_strChapter, cwi.m_strSection, cwi.m_lSize);
	if(!OpenRecordset(strSQL))
	{
		AfxMessageBox("Fail to open the table!");
		return 0;
	}

	//	avoid inserting the same item
	if(!m_pRecordset->BOF) {
		m_pRecordset->MoveFirst();
	}
	if(!m_pRecordset->adoEOF)
		return 0;

	//	insert new item
	try
	{		
		m_pRecordset->AddNew();
		m_pRecordset->PutCollect("name",    _variant_t(cwi.m_strName));
		m_pRecordset->PutCollect("type",    _variant_t(cwi.m_strType));
		m_pRecordset->PutCollect("size",    _variant_t(cwi.m_lSize));
		m_pRecordset->PutCollect("path",    _variant_t(cwi.m_strPath));
		m_pRecordset->PutCollect("modtime", _variant_t(cwi.m_strModTime));
		m_pRecordset->PutCollect("class",   _variant_t(cwi.m_strClass));						
		m_pRecordset->PutCollect("chapter",   _variant_t(cwi.m_strChapter));
		m_pRecordset->PutCollect("section",   _variant_t(cwi.m_strSection));
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

int CCourseWareRecordset::Delete(const CString& strSQL)
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

int CCourseWareRecordset::Modify(const CString& strSQL, const CCourseWareInfo& cwi)
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
			if(!cwi.m_strName.IsEmpty())
				m_pRecordset->PutCollect("name",    _variant_t(cwi.m_strName));			
			if(!cwi.m_strType.IsEmpty())
				m_pRecordset->PutCollect("type",    _variant_t(cwi.m_strType));
			if(cwi.m_lSize > 0)
				m_pRecordset->PutCollect("size",    _variant_t(cwi.m_lSize));
			if(!cwi.m_strPath.IsEmpty())
				m_pRecordset->PutCollect("path",    _variant_t(cwi.m_strPath));
			if(!cwi.m_strModTime.IsEmpty())
				m_pRecordset->PutCollect("modtime", _variant_t(cwi.m_strModTime));	
			if(!cwi.m_strClass.IsEmpty())
				m_pRecordset->PutCollect("class",   _variant_t(cwi.m_strClass));
			if(!cwi.m_strChapter.IsEmpty())
				m_pRecordset->PutCollect("chapter",   _variant_t(cwi.m_strChapter));
			if(!cwi.m_strSection.IsEmpty())
				m_pRecordset->PutCollect("section",   _variant_t(cwi.m_strSection));
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

int CCourseWareRecordset::QueryField(const CString& strSQL, const CString& strField,
							  vector<CString>& vecStr, const CString& strSort)
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
		CString strFieldValue;
		varValue = m_pRecordset->GetFields()->GetItem(_variant_t(strField))->Value;
		strFieldValue = VariantToCString(varValue);
		///////////////////////////////////////
		vecStr.push_back(strFieldValue);
		m_pRecordset->MoveNext();
	}
	
	m_pRecordset->Close();
	m_pRecordset=NULL;

	return nRet;	//	have not found
}
