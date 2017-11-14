// SectionTableItem.cpp: implementation of the SectionTableItem class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SectionTableItem.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SectionTableItem::SectionTableItem()
{
	m_lID        = 0;
	m_lChapterID = 0;
	m_strName    = _T("");
}

SectionTableItem::~SectionTableItem()
{

}

SectionTableItem::SectionTableItem(const SectionTableItem &sti)
{
	m_lID	   = sti.m_lID;
	m_lChapterID = sti.m_lChapterID;
	m_strName  = sti.m_strName;
}

SectionTableItem SectionTableItem::operator =(const SectionTableItem& sti)
{
	m_lID	     = sti.m_lID;
	m_lChapterID = sti.m_lChapterID;
	m_strName    = sti.m_strName;

	return *this;
}
