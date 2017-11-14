// ClassTableItem.cpp: implementation of the ClassTableItem class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ClassTableItem.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ClassTableItem::ClassTableItem()
{
	m_lID = 0;
	m_strName = _T("");
}

ClassTableItem::~ClassTableItem()
{

}

ClassTableItem::ClassTableItem(const ClassTableItem &cti)
{
	m_lID	  = cti.m_lID;
	m_strName = cti.m_strName;
}

ClassTableItem ClassTableItem::operator =(const ClassTableItem& cti)
{
	m_lID	  = cti.m_lID;
	m_strName = cti.m_strName;

	return *this;
}
