#if !defined(AFX_MAP_STATION_SET_H__606A1420_5239_4F13_AA73_948C09185E34__INCLUDED_)
#define AFX_MAP_STATION_SET_H__606A1420_5239_4F13_AA73_948C09185E34__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Map_Station_Set.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMap_Station_Set recordset

class CMap_Station_Set : public CRecordset
{
public:
	CMap_Station_Set(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CMap_Station_Set)

// Field/Param Data
	//{{AFX_FIELD(CMap_Station_Set, CRecordset)
	CString	m_ID;
	CString	m_NAME;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMap_Station_Set)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAP_STATION_SET_H__606A1420_5239_4F13_AA73_948C09185E34__INCLUDED_)
