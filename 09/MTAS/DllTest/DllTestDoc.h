// DllTestDoc.h : interface of the CDllTestDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DLLTESTDOC_H__6D243874_47FB_464D_9568_97F273B71419__INCLUDED_)
#define AFX_DLLTESTDOC_H__6D243874_47FB_464D_9568_97F273B71419__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDllTestDoc : public CDocument
{
protected: // create from serialization only
	CDllTestDoc();
	DECLARE_DYNCREATE(CDllTestDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDllTestDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDllTestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDllTestDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLLTESTDOC_H__6D243874_47FB_464D_9568_97F273B71419__INCLUDED_)
