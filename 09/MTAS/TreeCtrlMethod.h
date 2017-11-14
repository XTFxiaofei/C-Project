// TreeCtrlMethod.h: interface for the TreeCtrlMethod class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TREECTRLMETHOD_H__30958E17_00E8_4946_9784_4D2E030D59E7__INCLUDED_)
#define AFX_TREECTRLMETHOD_H__30958E17_00E8_4946_9784_4D2E030D59E7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <map>

class TreeCtrlMethod  
{
public:
	CCourseWareInfo* FindCourseWareInfo(HTREEITEM hItem, const CString &strName);
	TreeCtrlMethod();
	virtual ~TreeCtrlMethod();

	void FillTree();
	void UpdateTree();
	void SetTree(CTreeCtrl* pTree);

    std::map<HTREEITEM, CCourseWareInfo> m_map;
private:
	CTreeCtrl* m_pTree;
};

#endif // !defined(AFX_TREECTRLMETHOD_H__30958E17_00E8_4946_9784_4D2E030D59E7__INCLUDED_)
