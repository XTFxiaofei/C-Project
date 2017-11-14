#if !defined(AFX_STATIONSET_H__BD585F65_E9CE_48C6_87A5_33F8765A8C41__INCLUDED_)
#define AFX_STATIONSET_H__BD585F65_E9CE_48C6_87A5_33F8765A8C41__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StationSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStationSet recordset

class CStationSet : public CRecordset
{
public:
	CStationSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CStationSet)

// Field/Param Data
	//{{AFX_FIELD(CStationSet, CRecordset)
	CString	m_ID;
	CString	m_STATION;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStationSet)
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

#endif // !defined(AFX_STATIONSET_H__BD585F65_E9CE_48C6_87A5_33F8765A8C41__INCLUDED_)
