// HMSysDoc.h : interface of the CHMSysDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HMSYSDOC_H__0D899971_6395_41B0_A967_AC0368D6D106__INCLUDED_)
#define AFX_HMSYSDOC_H__0D899971_6395_41B0_A967_AC0368D6D106__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CHMSysDoc : public CDocument
{
protected: // create from serialization only
	CHMSysDoc();
	DECLARE_DYNCREATE(CHMSysDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHMSysDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHMSysDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHMSysDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HMSYSDOC_H__0D899971_6395_41B0_A967_AC0368D6D106__INCLUDED_)
