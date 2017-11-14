// AddressStatic.cpp : implementation file
//

#include "stdafx.h"
#include "mtas.h"
#include "AddressStatic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddressStatic

CAddressStatic::CAddressStatic()
{
	m_lfHeight = 5;
    m_lfWeight = FW_NORMAL;
    m_strFaceName = _T("MS Sans Serif");
}

CAddressStatic::~CAddressStatic()
{
}


BEGIN_MESSAGE_MAP(CAddressStatic, CStatic)
	//{{AFX_MSG_MAP(CAddressStatic)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddressStatic message handlers

BOOL CAddressStatic::CreateFont(LONG lfHeight, LONG lfWeight, LPCTSTR lpszFaceName)
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

int CAddressStatic::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CStatic::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if(!CreateFont(m_lfHeight, m_lfWeight, m_strFaceName))
    {
        TRACE0("Failed to create font for static\n");
		return -1;      // fail to create
    }	

	return 0;
}
