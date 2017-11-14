// HCDBDoc.h : interface of the CHCDBDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HCDBDOC_H__B22E7CF7_8471_4E1C_99B1_E46F75269AA1__INCLUDED_)
#define AFX_HCDBDOC_H__B22E7CF7_8471_4E1C_99B1_E46F75269AA1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CHCDBDoc : public CDocument
{
protected: // create from serialization only
	CHCDBDoc();
	DECLARE_DYNCREATE(CHCDBDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHCDBDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHCDBDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHCDBDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HCDBDOC_H__B22E7CF7_8471_4E1C_99B1_E46F75269AA1__INCLUDED_)
