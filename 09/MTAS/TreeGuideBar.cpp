// TreeGuideBar.cpp : implementation file
//

#include "stdafx.h"
#include "mtas.h"
#include "mainfrm.h"
#include "TreeGuideBar.h"
#include <map>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTreeGuideBar

CTreeGuideBar::CTreeGuideBar()
{
}

CTreeGuideBar::~CTreeGuideBar()
{
}


BEGIN_MESSAGE_MAP(CTreeGuideBar, baseCTreeGuideBar)
	//{{AFX_MSG_MAP(CTreeGuideBar)
	ON_WM_CREATE()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// gradient defines (if not already defined)
#ifndef COLOR_GRADIENTACTIVECAPTION
#define COLOR_GRADIENTACTIVECAPTION     27
#define COLOR_GRADIENTINACTIVECAPTION   28
#define SPI_GETGRADIENTCAPTIONS         0x1008
#endif

/////////////////////////////////////////////////////////////////////////////
// CTreeGuideBar message handlers

int CTreeGuideBar::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (baseCTreeGuideBar::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_tree.Create(WS_CHILD | WS_VISIBLE | TVS_HASLINES |
		TVS_HASBUTTONS | TVS_LINESATROOT, CRect(0, 0, 0, 0), this, 459))
	{
		TRACE0("Failed to create instant bar child\n");
		return -1;
	}
	GetCourseWareManager().AddUpdateWindow(&m_tree);
	GetCourseManager().AddUpdateWindow(&m_tree);
	// Setup VividTree BackGround bitmap (bitmap resource id)
//	m_tree.SetBitmapID( IDB_CODE_PROJECT );
	// Override the default background mode to use a bitmap
	m_background_mode = CMyGuideTree::BK_MODE_BMP;
	m_tree.SetBkMode( m_background_mode );

	// Add a couple of pixels to the height (optional)
	// m_tree.SetItemHeight( m_tree.GetItemHeight() + 2 );

	// Setup a default tree leaf icon - in this case the code project alien is used
	m_icon = (HICON)LoadImage( AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_CODE_PROJECT), 
		IMAGE_ICON,	16, 16, LR_VGACOLOR );
	m_tree.SetItemIcon( m_icon );

	// Create the Tree content 
	m_tree.m_method.FillTree();

	return 0;
}
/*
void CTreeGuideBar::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	bool redraw_it = false;
	Options options;

	// WARNING: dialog radio buttons must in the same order as values defined
	// in the enum VividTree::BkMode. 
	options.m_bkground_mode = (int)(m_tree.GetBkMode()) - (int)(m_tree.BK_MODE_BMP);
	options.m_tiled = m_tree.GetBitmapTiledMode();
	options.m_horz = m_tree.GetGradientHorz();

	if ( options.DoModal() == IDOK )
	{
		// If any settings are different than they were, record the
		// new settings and redraw (invalidate).
		VividTree::BkMode new_mode = (VividTree::BkMode)(
			(int)(m_tree.BK_MODE_BMP) + options.m_bkground_mode );
		if ( m_tree.GetBkMode() != new_mode )
		{
			m_tree.SetBkMode( new_mode );
			redraw_it = true;
		}
		if ( m_tree.GetBitmapTiledMode() != (options.m_tiled ? true : false) )
		{
			m_tree.SetBitmapTiledMode( (options.m_tiled ? true : false) );
			redraw_it = true;
		}
		if ( m_tree.GetGradientHorz() != (options.m_horz ? true : false) )
		{
			m_tree.SetGradientHorz( (options.m_horz ? true : false) );
			redraw_it = true;
		}
		if ( redraw_it )
			Invalidate();  // redraw
	}

}
*/
void CTreeGuideBar::OnSize(UINT nType, int cx, int cy) 
{
	baseCTreeGuideBar::OnSize(nType, cx, cy);
	
	// Cover the client area with the tree
	CRect rect;
	GetClientRect( rect );
	m_tree.MoveWindow( 0, 0, rect.Width(), rect.Height() );		
}



void CTreeGuideBar::NcCalcClient(LPRECT pRc, UINT nDockBarID)
{
    CRect rcBar(pRc); // save the bar rect

    // subtract edges
    baseCTreeGuideBar::NcCalcClient(pRc, nDockBarID);

    if (!HasGripper())
        return;

    CRect rc(pRc); // the client rect as calculated by the base class

    BOOL bHorz = (nDockBarID == AFX_IDW_DOCKBAR_TOP) ||
                 (nDockBarID == AFX_IDW_DOCKBAR_BOTTOM);
    if (bHorz)
        rc.DeflateRect(2, 0, 0, 0);
    else
        rc.DeflateRect(0, 2, 0, 0);

    // set position for the "x" (hide bar) button
    CPoint ptOrgBtn;
    if (bHorz)
        ptOrgBtn = CPoint(rc.left - 13, rc.top);
    else
        ptOrgBtn = CPoint(rc.right - 14, rc.top - 16);

    m_biHide.Move(ptOrgBtn - rcBar.TopLeft());

    *pRc = rc;
}

void CTreeGuideBar::NcPaintGripper(CDC* pDC, CRect rcClient)
{
    if (!HasGripper())
        return;

    // compute the caption rectangle
    BOOL bHorz = IsHorzDocked();
    CRect rcGrip = rcClient;
    CRect rcBtn = m_biHide.GetRect();
    if (bHorz)
    {   // right side gripper
        rcGrip.left -= m_cyGripper + 1;
        rcGrip.right = rcGrip.left + 11;
        rcGrip.top = rcBtn.bottom + 3;
    }
    else
    {   // gripper at top
        rcGrip.top -= m_cyGripper + 3;
        rcGrip.bottom = rcGrip.top + 12;
        rcGrip.right = rcBtn.left - 2;
    }
    rcGrip.InflateRect(bHorz ? 1 : 0, bHorz ? 0 : 1);

    // draw the caption background
    //CBrush br;
    COLORREF clrCptn = m_bActive ?
        ::GetSysColor(COLOR_ACTIVECAPTION) :
        ::GetSysColor(COLOR_INACTIVECAPTION);

    // query gradient info (usually TRUE for Win98/Win2k)
    BOOL bGradient = FALSE;
    ::SystemParametersInfo(SPI_GETGRADIENTCAPTIONS, 0, &bGradient, 0);
    
    if (!bGradient)
        pDC->FillSolidRect(&rcGrip, clrCptn); // solid color
    else
    {
        // gradient from left to right or from bottom to top
        // get second gradient color (the right end)
        COLORREF clrCptnRight = m_bActive ?
            ::GetSysColor(COLOR_GRADIENTACTIVECAPTION) :
            ::GetSysColor(COLOR_GRADIENTINACTIVECAPTION);

        // this will make 2^6 = 64 fountain steps
        int nShift = 6;
        int nSteps = 1 << nShift;

        for (int i = 0; i < nSteps; i++)
        {
            // do a little alpha blending
            int nR = (GetRValue(clrCptn) * (nSteps - i) +
                      GetRValue(clrCptnRight) * i) >> nShift;
            int nG = (GetGValue(clrCptn) * (nSteps - i) +
                      GetGValue(clrCptnRight) * i) >> nShift;
            int nB = (GetBValue(clrCptn) * (nSteps - i) +
                      GetBValue(clrCptnRight) * i) >> nShift;

            COLORREF cr = RGB(nR, nG, nB);

            // then paint with the resulting color
            CRect r2 = rcGrip;
            if (bHorz)
            {
                r2.bottom = rcGrip.bottom - 
                    ((i * rcGrip.Height()) >> nShift);
                r2.top = rcGrip.bottom - 
                    (((i + 1) * rcGrip.Height()) >> nShift);
                if (r2.Height() > 0)
                    pDC->FillSolidRect(r2, cr);
            }
            else
            {
                r2.left = rcGrip.left + 
                    ((i * rcGrip.Width()) >> nShift);
                r2.right = rcGrip.left + 
                    (((i + 1) * rcGrip.Width()) >> nShift);
                if (r2.Width() > 0)
                    pDC->FillSolidRect(r2, cr);
            }
        }
    }

    // draw the caption text - first select a font
    CFont font;
    int ppi = pDC->GetDeviceCaps(LOGPIXELSX);
    int pointsize = MulDiv(85, 96, ppi); // 8.5 points at 96 ppi

    LOGFONT lf;
    BOOL bFont = font.CreatePointFont(pointsize, m_sFontFace);
    if (bFont)
    {
        // get the text color
        COLORREF clrCptnText = m_bActive ?
            ::GetSysColor(COLOR_CAPTIONTEXT) :
            ::GetSysColor(COLOR_INACTIVECAPTIONTEXT);

        int nOldBkMode = pDC->SetBkMode(TRANSPARENT);
        COLORREF clrOldText = pDC->SetTextColor(clrCptnText);

        if (bHorz)
        {
            // rotate text 90 degrees CCW if horizontally docked
            font.GetLogFont(&lf);
            font.DeleteObject();
            lf.lfEscapement = 900;
            font.CreateFontIndirect(&lf);
        }
        
        CFont* pOldFont = pDC->SelectObject(&font);
        CString sTitle;
        GetWindowText(sTitle);

        CPoint ptOrg = bHorz ?
            CPoint(rcGrip.left - 1, rcGrip.bottom - 3) :
            CPoint(rcGrip.left + 3, rcGrip.top);

        pDC->ExtTextOut(ptOrg.x, ptOrg.y,
            ETO_CLIPPED, rcGrip, sTitle, NULL);

        pDC->SelectObject(pOldFont);
        pDC->SetBkMode(nOldBkMode);
        pDC->SetTextColor(clrOldText);
    }

    // draw the button
    m_biHide.Paint(pDC);
}

CMyGuideTree* CTreeGuideBar::GetTree()
{
	return &m_tree;
}
