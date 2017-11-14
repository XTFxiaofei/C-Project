// SectionTableItem.h: interface for the SectionTableItem class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SECTIONTABLEITEM_H__8A79C727_451F_4135_A582_7042AE7E2B65__INCLUDED_)
#define AFX_SECTIONTABLEITEM_H__8A79C727_451F_4135_A582_7042AE7E2B65__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class AFX_EXT_CLASS SectionTableItem : public CObject  
{
public:
	SectionTableItem();
	SectionTableItem(const SectionTableItem &sti);
	virtual ~SectionTableItem();
	SectionTableItem operator =(const SectionTableItem& sti);
	
public:
	long m_lID;
	long m_lChapterID;
	CString m_strName;
};

#endif // !defined(AFX_SECTIONTABLEITEM_H__8A79C727_451F_4135_A582_7042AE7E2B65__INCLUDED_)
