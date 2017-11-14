// AddressComboBox.cpp : implementation file
//

#include "stdafx.h"
#include "mtas.h"
#include "AddressComboBox.h"
#include "mainfrm.h"
#include "MTASView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddressComboBox

CAddressComboBox::CAddressComboBox()
{
    m_lfHeight = 5;
    m_lfWeight = FW_NORMAL;
    m_strFaceName = _T("MS Sans Serif");
}

CAddressComboBox::~CAddressComboBox()
{
}

BEGIN_MESSAGE_MAP(CAddressComboBox, CComboBoxXP)
	//{{AFX_MSG_MAP(CAddressComboBox)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


BOOL CAddressComboBox::CreateFont(LONG lfHeight, LONG lfWeight, LPCTSTR lpszFaceName)
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

BOOL CAddressComboBox::PreTranslateMessage(MSG* pMsg) 
{
	if(pMsg->message == WM_KEYDOWN) {
		if(pMsg->wParam == VK_RETURN) {		
			CMainFrame* pMainWnd = GetMainFrame();
			CView* pView = (CView*)pMainWnd->GetActiveView();
			if(pView->GetRuntimeClass()->m_lpszClassName == _T("CMTASView")) {
				CMTASView* pMTASView = (CMTASView*)pView;				
				GetWindowText(m_strURL);
				pMTASView->m_sUrl = m_strURL;
				pMTASView->Navigate2(m_strURL);
			} 	 
		}
	}
	
	return CComboBoxXP::PreTranslateMessage(pMsg);
}
/////////////////////////////////////////////////////////////////////////////
// CAddressComboBox message handlers

int CAddressComboBox::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CComboBoxXP::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if(!CreateFont(m_lfHeight, m_lfWeight, m_strFaceName))
    {
        TRACE0("Failed to create font for combo box\n");
		return -1;      // fail to create
    }
	
	return 0;
}
