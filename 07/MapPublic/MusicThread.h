#if !defined(AFX_MUSICTHREAD_H__F9483F42_98B7_4D0F_8D0C_3BF1DA4ABA45__INCLUDED_)
#define AFX_MUSICTHREAD_H__F9483F42_98B7_4D0F_8D0C_3BF1DA4ABA45__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MusicThread.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CMusicThread thread

class CMusicThread : public CWinThread
{
	DECLARE_DYNCREATE(CMusicThread)
protected:
	        // protected constructor used by dynamic creation

// Attributes
public:
    CMusicThread(); 
	virtual ~CMusicThread();
// Operations
public:
  BOOL PlayResource(WORD wResourceID);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMusicThread)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
protected:
	

	// Generated message map functions
	//{{AFX_MSG(CMusicThread)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MUSICTHREAD_H__F9483F42_98B7_4D0F_8D0C_3BF1DA4ABA45__INCLUDED_)
