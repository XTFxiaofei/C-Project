// FlashComboBox.cpp : implementation file
//

#include "stdafx.h"
#include "mtas.h"
#include "mainfrm.h"
#include "FlashComboBox.h"
#include "FlashView.h"
#include <vector>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFlashComboBox

CFlashComboBox::CFlashComboBox()
{
    m_lfHeight = 5;
    m_lfWeight = FW_NORMAL;
    m_strFaceName = _T("MS Sans Serif");
}

CFlashComboBox::~CFlashComboBox()
{
}

void CFlashComboBox::UpdateDisplay()
{
	::SendMessage(m_hWnd, CB_RESETCONTENT, 0, 0);
	vector<CString> svecName;
	CCourseWareRecordset cwrs(&theDB);
	CString strSQL = _T("SELECT DISTINCT `name` FROM `cw` WHERE `TYPE`='swf'");
	if(!cwrs.QueryField(strSQL, _T("name"), svecName))
		return;

	for(vector<CString>::iterator iter = svecName.begin(); iter != svecName.end(); ++iter) {
		::SendMessage(m_hWnd, CB_ADDSTRING, 0, (LPARAM)(LPCTSTR)*iter);
	}
}

BEGIN_MESSAGE_MAP(CFlashComboBox, CComboBoxXP)
	//{{AFX_MSG_MAP(CFlashComboBox)
	ON_WM_CREATE()
	ON_CONTROL_REFLECT(CBN_SELCHANGE, OnSelchange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFlashComboBox message handlers


int CFlashComboBox::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CComboBoxXP::OnCreate(lpCreateStruct) == -1)
		return -1;

    if(!CreateFont(m_lfHeight, m_lfWeight, m_strFaceName))
    {
        TRACE0("Failed to create font for combo box\n");
		return -1;      // fail to create
    }
	GetCourseManager().AddUpdateWindow(this);
	GetCourseWareManager().AddUpdateWindow(this);

	vector<CString> svecName;
	CCourseWareRecordset cwrs(&theDB);
	CString strSQL = _T("SELECT DISTINCT `name` FROM `cw` WHERE `TYPE`='swf'");
	if(!cwrs.QueryField(strSQL, _T("name"), svecName))
		return -1;

	for(vector<CString>::iterator iter = svecName.begin(); iter != svecName.end(); ++iter) {
		::SendMessage(m_hWnd, CB_ADDSTRING, 0, (LPARAM)(LPCTSTR)*iter);
	}

	return 0;
}

void CFlashComboBox::OnSelchange() 
{
	CString strFlashName;
	GetLBText(GetCurSel(), strFlashName);

	vec_cwi vecCWInfo;
	CCourseWareRecordset cwrs(&theDB);
	if(!cwrs.Query(_T("SELECT * FROM `cw` WHERE `TYPE`='swf'"), vecCWInfo))
		return;
	for(i_vec_cwi iter = vecCWInfo.begin(); iter != vecCWInfo.end(); ++iter) {
		if(strFlashName == iter->m_strName)
			break;
	}
	
	CMainFrame* pMainWnd = (CMainFrame*)AfxGetMainWnd();
	CView* pView = pMainWnd->GetActiveView();
	CString lpszClassName = pView->GetRuntimeClass()->m_lpszClassName;
	if(lpszClassName == _T("CFlashView")) {
		CFlashView* pFlashView = (CFlashView*)pView;
		pFlashView->LoadMovie(iter->m_strPath);
	}
}

BOOL CFlashComboBox::CreateFont(LONG lfHeight, LONG lfWeight, LPCTSTR lpszFaceName)
{
    //  Create a font for the combobox

    LOGFONT logFont;
    memset(&logFont, 0, sizeof(logFont));

    if (::GetSystemMetrics(SM_DBCSENABLED)) 
	{
        // Since design guide says toolbars are fixed height so is the font.

        logFont.lfHeight = lfHeight;
        logFont.lfWeight = lfWeight;
        CString strDefaultFont = lpszFaceName;
        lstrcpy(logFont.lfFaceName, strDefaultFont);
        if (!m_font.CreateFontIndirect(&logFont))
        {
            TRACE("Could Not create font for combo\n");
            return FALSE;
        }
        SetFont(&m_font);
    }
    else
    {
        m_font.Attach(::GetStockObject(SYSTEM_FONT));
        SetFont(&m_font);
    }
    return TRUE;
}

void CFlashComboBox::UpdateContent()
{
	::SendMessage(m_hWnd, CB_RESETCONTENT, 0, 0);
	vector<CString> svecName;
	CCourseWareRecordset cwrs(&theDB);
	CString strSQL = _T("SELECT DISTINCT `name` FROM `cw` WHERE `TYPE`='swf'");
	if(!cwrs.QueryField(strSQL, _T("name"), svecName))
		return;

	for(vector<CString>::iterator iter = svecName.begin(); iter != svecName.end(); ++iter) {
		::SendMessage(m_hWnd, CB_ADDSTRING, 0, (LPARAM)(LPCTSTR)*iter);
	}
}
