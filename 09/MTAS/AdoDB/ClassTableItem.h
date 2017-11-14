// ClassTableItem.h: interface for the ClassTableItem class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLASSTABLEITEM_H__8E3C7CF7_0406_4097_BA66_E66FB8E7EC75__INCLUDED_)
#define AFX_CLASSTABLEITEM_H__8E3C7CF7_0406_4097_BA66_E66FB8E7EC75__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class AFX_EXT_CLASS ClassTableItem : public CObject  
{
public:
	ClassTableItem();
	ClassTableItem(const ClassTableItem &cti);
	virtual ~ClassTableItem();
	ClassTableItem operator =(const ClassTableItem& cti);

public:
	long	m_lID;
	CString	m_strName;
};

#endif // !defined(AFX_CLASSTABLEITEM_H__8E3C7CF7_0406_4097_BA66_E66FB8E7EC75__INCLUDED_)
