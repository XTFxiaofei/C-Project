// ChapterTableItem.h: interface for the ChapterTableItem class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHAPTERTABLEITEM_H__F50558FA_304F_46EF_B9E3_01BBA1FC8EA1__INCLUDED_)
#define AFX_CHAPTERTABLEITEM_H__F50558FA_304F_46EF_B9E3_01BBA1FC8EA1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class AFX_EXT_CLASS ChapterTableItem : public CObject  
{
public:
	ChapterTableItem();
	ChapterTableItem(const ChapterTableItem &cti);
	virtual ~ChapterTableItem();
	ChapterTableItem operator =(const ChapterTableItem& cti);

public:
	long m_lID;
	long m_lClassID;
	CString m_strName;
};

#endif // !defined(AFX_CHAPTERTABLEITEM_H__F50558FA_304F_46EF_B9E3_01BBA1FC8EA1__INCLUDED_)
