#if !defined(AFX_MYEDITSHOWLIST_H__2B80E708_DE67_44F2_8AD2_3338B6A31B58__INCLUDED_)
#define AFX_MYEDITSHOWLIST_H__2B80E708_DE67_44F2_8AD2_3338B6A31B58__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyEditShowList.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyEditShowList window
#include "MyList.h"
class CMyEditShowList : public CEdit
{
// Construction
public:
	CMyEditShowList();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyEditShowList)
	public:
	//}}AFX_VIRTUAL

// Implementation
public:
	bool oncharflag;
	void SetListValue(CString sqlstr);
	int width;
	CMyList m_list;
	void GetRecord(CString sqlstr);
	_RecordsetPtr m_record;
	CString querystr;
	virtual ~CMyEditShowList();

	// Generated message map functions
protected:
	//{{AFX_MSG(CMyEditShowList)
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYEDITSHOWLIST_H__2B80E708_DE67_44F2_8AD2_3338B6A31B58__INCLUDED_)
