// TBManagerDoc.h : interface of the CTBManagerDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TBMANAGERDOC_H__A62CC85A_5455_483D_848C_FC5EAB85D33F__INCLUDED_)
#define AFX_TBMANAGERDOC_H__A62CC85A_5455_483D_848C_FC5EAB85D33F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTBManagerDoc : public CDocument
{
protected: // create from serialization only
	CTBManagerDoc();
	DECLARE_DYNCREATE(CTBManagerDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTBManagerDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTBManagerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTBManagerDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TBMANAGERDOC_H__A62CC85A_5455_483D_848C_FC5EAB85D33F__INCLUDED_)
