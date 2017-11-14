#if !defined(AFX_FILEOPENPREDLG_H__2670FB1D_CA1E_4F98_B9F6_45C07AECE121__INCLUDED_)
#define AFX_FILEOPENPREDLG_H__2670FB1D_CA1E_4F98_B9F6_45C07AECE121__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FileOpenPreDlg.h : header file
//

#include "webbrowser2.h"


/////////////////////////////////////////////////////////////////////////////
// CFileOpenPreDlg dialog

class CFileOpenPreDlg : public CFileDialog
{
	DECLARE_DYNAMIC(CFileOpenPreDlg)

public:
	static BOOL IsFolder(const CString& strPath);
	CFileOpenPreDlg(BOOL bOpenFileDialog, // TRUE for FileOpen, FALSE for FileSaveAs
		LPCTSTR lpszDefExt = NULL,
		LPCTSTR lpszFileName = NULL,
		DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		LPCTSTR lpszFilter = NULL,
		CWnd* pParentWnd = NULL);
	virtual ~CFileOpenPreDlg();

protected:
	//{{AFX_MSG(CFileOpenPreDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	IWebBrowser2*	m_pBrowserApp;
	CWebBrowser2	m_wndBrowser;
	void OnFileNameChange();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEOPENPREDLG_H__2670FB1D_CA1E_4F98_B9F6_45C07AECE121__INCLUDED_)
