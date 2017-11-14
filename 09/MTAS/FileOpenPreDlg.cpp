// FileOpenPreDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mtas.h"
#include "FileOpenPreDlg.h"
#include <atlbase.h>
#include "dlgs.h"	//	for lst2

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFileOpenPreDlg

IMPLEMENT_DYNAMIC(CFileOpenPreDlg, CFileDialog)

CFileOpenPreDlg::CFileOpenPreDlg(BOOL bOpenFileDialog, LPCTSTR lpszDefExt, LPCTSTR lpszFileName,
		DWORD dwFlags, LPCTSTR lpszFilter, CWnd* pParentWnd) :
		CFileDialog(bOpenFileDialog, lpszDefExt, lpszFileName, dwFlags, lpszFilter, pParentWnd)
{
	m_pBrowserApp = NULL;
}

CFileOpenPreDlg::~CFileOpenPreDlg()
{
	if (m_pBrowserApp != NULL)
		m_pBrowserApp->Release();
}

BEGIN_MESSAGE_MAP(CFileOpenPreDlg, CFileDialog)
	//{{AFX_MSG_MAP(CFileOpenPreDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CFileOpenPreDlg::OnFileNameChange()
{
	CFileDialog::OnFileNameChange();
	
	TCHAR tcBuf[_MAX_PATH] = _T("");
	CString strPathName = _T("");
	CString strFolderPath = GetFolderPath();
	CListCtrl* pLc = (CListCtrl*)(GetParent()->GetDlgItem(lst2)->GetDlgItem(1));
	int nItem = pLc->GetNextItem(-1, LVNI_SELECTED);
	pLc->GetItemText(nItem, 0, tcBuf, _MAX_PATH);
	CString strFileName(tcBuf);
	if(!strFileName.IsEmpty())
		strPathName = strFolderPath + _T("\\") + strFileName;
	if(strPathName.IsEmpty() || IsFolder(strPathName)) {			
		return;	//	do nothing
	}

	CString strFileExt = 
		strFileName.Right(strFileName.GetLength() - strFileName.ReverseFind(_T('.')) - 1);
	strFileExt.MakeLower();
	if(!(strFileExt == _T("ppt") || strFileExt == _T("swf") || 
		strFileExt == _T("doc")	|| strFileExt == _T("txt"))) {		
		return;	//	do nothing
	}

	//	preview the content
	CWnd* pWnd = GetDlgItem(stc32);
	ASSERT(pWnd != NULL);	
	if(!strPathName.IsEmpty()) {
		CRect rtClient, rtDlg, rtPreview;		
		pWnd->GetClientRect(&rtClient);
		GetClientRect(&rtDlg);
		
		rtPreview.top = rtClient.top + 30;
		rtPreview.left = rtClient.right + 20;
		rtPreview.right = rtDlg.right - 10;
		rtPreview.bottom = rtDlg.bottom - 15;

		m_wndBrowser.MoveWindow(&rtPreview);
		m_wndBrowser.ShowWindow(SW_SHOW);
		COleVariant vURL(strPathName, VT_BSTR);		
		m_pBrowserApp->Navigate2(vURL, 0, 0, 0, 0);
	}

	return;
}

BOOL CFileOpenPreDlg::OnInitDialog() 
{
	CFileDialog::OnInitDialog();
	
	GetParent()->ModifyStyle(WS_THICKFRAME, 0);	//	cancel sizing window style
	// create the control window
	if (!m_wndBrowser.CreateControl(CLSID_WebBrowser, NULL,
				WS_VISIBLE | WS_CHILD, CRect(0, 0, 0, 0), this, 230))
	{
		DestroyWindow();
		return FALSE;
	}

	LPUNKNOWN lpUnk = m_wndBrowser.GetControlUnknown();
	HRESULT hr = lpUnk->QueryInterface(IID_IWebBrowser2, (void**)&m_pBrowserApp);
	if (!SUCCEEDED(hr))
	{
		m_pBrowserApp = NULL;
		m_wndBrowser.DestroyWindow();
		DestroyWindow();
		return FALSE;
	}
	GetParent()->MoveWindow(0, 0, 570, 430);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CFileOpenPreDlg::IsFolder(const CString& strPath)
{
	if(GetFileAttributes(strPath) != FILE_ATTRIBUTE_DIRECTORY)
		return FALSE;
	return TRUE;
}
