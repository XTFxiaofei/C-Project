// ChapterTableItem.cpp: implementation of the ChapterTableItem class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ChapterTableItem.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ChapterTableItem::ChapterTableItem()
{
	m_lID      = 0;
	m_lClassID = 0;
	m_strName  = _T("");
}

ChapterTableItem::~ChapterTableItem()
{

}

ChapterTableItem::ChapterTableItem(const ChapterTableItem &cti)
{
	m_lID	   = cti.m_lID;
	m_lClassID = cti.m_lClassID;
	m_strName  = cti.m_strName;
}

ChapterTableItem ChapterTableItem::operator =(const ChapterTableItem& cti)
{
	m_lID	   = cti.m_lID;
	m_lClassID = cti.m_lClassID;
	m_strName  = cti.m_strName;

	return *this;
}
