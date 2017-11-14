// MapPublicDoc.h : interface of the CMapPublicDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAPPUBLICDOC_H__2B13E8FA_BA49_4DE2_AC3D_6B4FD6FDA7A7__INCLUDED_)
#define AFX_MAPPUBLICDOC_H__2B13E8FA_BA49_4DE2_AC3D_6B4FD6FDA7A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMapPublicDoc : public CDocument
{
protected: // create from serialization only
	CMapPublicDoc();
	DECLARE_DYNCREATE(CMapPublicDoc)

// Attributes
public:

// Operations
public:
    
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMapPublicDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMapPublicDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMapPublicDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAPPUBLICDOC_H__2B13E8FA_BA49_4DE2_AC3D_6B4FD6FDA7A7__INCLUDED_)
