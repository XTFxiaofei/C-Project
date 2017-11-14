// ColorStatic.cpp : implementation file
//

#include "stdafx.h"
#include "ColorStatic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CColorStatic

CColorStatic::CColorStatic()
{
	// Init our vars.
	m_clBackColor=::GetSysColor(COLOR_BTNFACE);
	m_clTextColor=::GetSysColor(COLOR_WINDOWTEXT);
	m_nTextXPos=3;
	m_nTextYPos=3;
	m_nScrollXPos=m_nTextXPos;
	m_nScrollYPos=m_nTextYPos;
	m_nStep=5;
	m_bIsSingleLine=true;
	m_bUseRoll=false;
	m_bUseSysFont=true;
	m_bHCentered=false;
	m_bVCentered=false;
	m_bTextInfoGotten=false;
	m_bRollPosSetted=false;
	m_bRollTimerKilled=false;
	m_bBkTransparent=false;
	m_bDCStored=false;
	m_nRollDirection=ROLL_LEFT;
}

CColorStatic::~CColorStatic()
{
}


BEGIN_MESSAGE_MAP(CColorStatic, CStatic)
	//{{AFX_MSG_MAP(CColorStatic)
	ON_WM_ERASEBKGND()
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CColorStatic message handlers

///////////////////////////////////////////////////////////
//  Name: OnEraseBkgnd(CDC* pDC)
///////////////////////////////////////////////////////////
//  Function: Draw the background and the text.
//
///////////////////////////////////////////////////////////
BOOL CColorStatic::OnEraseBkgnd(CDC* pDC) //需要删除背景色时调用
{
	// TODO: Add your message handler code here and/or call default
	CRect   clientRect;
	CRgn	clipRgn;
	GetClientRect(&clientRect);
/*	if(!m_bDCStored)
	{
		CBitmap   bitmap;
		m_StoreDC.CreateCompatibleDC(pDC);
		bitmap.CreateCompatibleBitmap(pDC,clientRect.Width(),clientRect.Height());
		m_StoreDC.SelectObject(&bitmap);
		m_StoreDC.BitBlt(0,0,clientRect.Width(),clientRect.Height(),pDC,0,0,SRCCOPY);
		m_bDCStored=true;
	}
	// Get our client rect and fill it with bk-color
	GetClientRect(&clientRect);

	if(m_bBkTransparent)
	{
		pDC->BitBlt(0,0,clientRect.Width(),clientRect.Height(),&m_StoreDC,0,0,SRCCOPY);
	}
	else
*///	{
		pDC->FillRect(&clientRect,&CBrush(m_clBackColor));
//	}
	pDC->SetBkMode(TRANSPARENT);
	pDC->SetTextColor(m_clTextColor);

	// Get and Set our font.
	CFont *pCurrentFont;
	if(m_bUseSysFont)
	{
		// Get the dialog's font.
	    pCurrentFont= GetFont(); 
	}
	else
	{
		// Use our member font.
		pCurrentFont=&m_font;
	}
    CFont *pOldFont = pDC->SelectObject(pCurrentFont);

	// Set clip rgn.
	clipRgn.CreateRectRgnIndirect(&clientRect);
	pDC->SelectClipRgn(&clipRgn);
	// Draw the Text.
	if(m_sText)
	{
		// judge if the text is a single line.
		m_bIsSingleLine=(m_sText.Find("\n")>=0)?false:true;

		if(m_bIsSingleLine)
		{
			if(!m_bTextInfoGotten)
			{
				// We'll get the text width and height to roll it.
				CSize  size=pDC->GetTextExtent(m_sText);
				m_nTextWidth=size.cx ;
				m_nTextHeight=size.cy ;
				// We have gotten the text info.
				m_bTextInfoGotten=true;
			}
			if(m_bHCentered)
			{
				// H Center our text.
				m_nTextXPos=(clientRect.Width()-m_nTextWidth)/2;

			}
			if(m_bVCentered)
			{
				// V center our text.
		    	m_nTextYPos=(clientRect.Height()-m_nTextHeight)/2;
			}
			if(!m_bRollPosSetted)
			{
				// Set our start roll pos.
				m_nScrollXPos=m_nTextXPos;
				m_nScrollYPos=m_nTextYPos;
				m_bRollPosSetted=true;
			}
			// Draw a single-line text.
			pDC->TextOut(m_bUseRoll?m_nScrollXPos:m_nTextXPos,m_bUseRoll?m_nScrollYPos:m_nTextYPos,m_sText);
		}
		else
		{
			// Draw multi-line text.
			CString  sShow,sOthers;
			sOthers=m_sText;
			int width;  // every line's width
			int nPos=0;  // new line's pos (in text)
			int x=m_bUseRoll?m_nScrollXPos:m_nTextXPos;
			int y=m_bUseRoll?m_nScrollYPos:m_nTextYPos;
	
			if(!m_bTextInfoGotten)
			{
				m_nTextWidth=m_nTextHeight=0;
				// Get the line-height.
				TEXTMETRIC	tm;
				pDC->GetTextMetrics(&tm);
				m_nLineHeight=tm.tmHeight+tm.tmExternalLeading;
			}

			while(!sOthers.IsEmpty())
			{
				nPos=sOthers.Find("\n");
				if(nPos>=0)
				{
					// trim left to get the line to show.
					sShow=sOthers.Left(nPos);
					// trim right.
					sOthers=sOthers.Right(sOthers.GetLength()-nPos-1);
					pDC->TextOut(x,y,sShow);
					y+=m_nLineHeight;
					// We'll get the multi-line text max width and height.
					if(m_bUseRoll && !m_bTextInfoGotten)
					{
						// Get the text info.
						CSize size=pDC->GetTextExtent(sShow);
						width=size.cx;
						if(width>m_nTextWidth)
							m_nTextWidth=width;
						m_nTextHeight+=m_nLineHeight;
					}
				}
				else
				{
					// There is no more line,so just show it.
					sShow=sOthers;
					sOthers.Empty();
					pDC->TextOut(x,y,sShow);
					if(m_bUseRoll && !m_bTextInfoGotten)
					{
						CSize size=pDC->GetTextExtent(sShow);
						width=size.cx;
						if(width>m_nTextWidth)
							m_nTextWidth=width;
						m_nTextHeight+=m_nLineHeight;
						m_bTextInfoGotten=true;
					}
				}
			}
		}
		pDC->SelectObject(pOldFont);
	}
	
	return TRUE;
}

///////////////////////////////////////////////////////////
//  Name:		SetTextColor()
///////////////////////////////////////////////////////////
//  Function:	Change the color of the text.
//  Parm:		COLORREF clTextColor
///////////////////////////////////////////////////////////
//  Remark:     Call this if you want to change the text color.
///////////////////////////////////////////////////////////
void CColorStatic::SetTextColor(COLORREF clTextColor)
{
	m_clTextColor=clTextColor;
//	MessageBox("SetTextColor");
	Invalidate();

}

///////////////////////////////////////////////////////////
//  Name:		SetBkColor()
///////////////////////////////////////////////////////////
//  Function:	Change the color of the background.
//  Parm:		COLORREF clBkColor
///////////////////////////////////////////////////////////
//  Remark:     Call this if you want to change the back color.
///////////////////////////////////////////////////////////
void CColorStatic::SetBkColor(COLORREF clBkColor)
{
	m_clBackColor=clBkColor;
//	MessageBox("SetBkColor");
	Invalidate();
}

///////////////////////////////////////////////////////////
//  We do not want the default effect,
// so we judt do nothing in function OnPaint()
///////////////////////////////////////////////////////////
void CColorStatic::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	
	// Do not call CStatic::OnPaint() for painting messages
}


///////////////////////////////////////////////////////////
//  Name: PreSubclassWindow()
///////////////////////////////////////////////////////////
//  Function: Get the static's text.
///////////////////////////////////////////////////////////
//  Remark: Because we don't use the SetWindowText() call,
//    in stead we use SetText() call to change the text,
//    so we must get the text here,not in OnEraseBkgnd().
///////////////////////////////////////////////////////////
void CColorStatic::PreSubclassWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	GetWindowText(m_sText);
   
	CStatic::PreSubclassWindow();
}

///////////////////////////////////////////////////////////
//  Name:       SetText()
///////////////////////////////////////////////////////////
//  Function:   Change the text of the ststic.
//  Parm:       CString sText
///////////////////////////////////////////////////////////
//  Remark:  Use this but not SetWindowText() if you need to
//    change the text.
//    **If we use the SetWindowText() call,there will be
//    some dreadful effect.So I wrote this function.
///////////////////////////////////////////////////////////

void CColorStatic::SetText(CString sText)
{

	if(m_sText!=sText)
	{
		m_sText=sText;
		m_bTextInfoGotten=false;
		m_bRollPosSetted=false;
		Invalidate();
	}
}
///////////////////////////////////////////////////////////
//  Name:		BeginRoll()
///////////////////////////////////////////////////////////
//  Function:	Set the vars and set a timer.
//  Parm1:		int nStep  default:5
//		- the move step of the rolling text.Increase this 
//      if you want the text rolling faster.
//  Parm2:		int nTimer default:100
//      - the time interval of the rolling text.Decrease it
//      if you want the text rolling faster.
///////////////////////////////////////////////////////////
void CColorStatic::BeginRoll(int nStep,int nTimer)
{
 //  MessageBox("BeginRoll");
	m_nStep=nStep;
	m_bUseRoll=true;
	m_bRollPosSetted=false;
	SetTimer(ID_ROLLTIMER,30,NULL);
}

///////////////////////////////////////////////////////////
//  Name:		SetRollDirection()
///////////////////////////////////////////////////////////
//  Function:	Set the rolling direction.
//  Parm:		int direction.value:
//
//					ROLL_LEFT		0
//					ROLL_RIGHT		1
//					ROLL_UP 		2
//					ROLL_DOWN		3
///////////////////////////////////////////////////////////
//  Remark:     Use this before BeginRoll()
///////////////////////////////////////////////////////////
void CColorStatic::SetRollDirection(int direction)
{
	m_nRollDirection=direction;
}

///////////////////////////////////////////////////////////
// Name:         StopRoll()
///////////////////////////////////////////////////////////
// Function:     kill the timer.
// Parm:
///////////////////////////////////////////////////////////
void CColorStatic::StopRoll()
{

	m_bUseRoll=false;
	KillTimer(ID_ROLLTIMER);
	Invalidate();
	m_bRollTimerKilled=true;
}

///////////////////////////////////////////////////////////
// Name:         OnTimer(UINT nIDEvent)
///////////////////////////////////////////////////////////
// Function:     Change the output text (if it is set to 
//          show current time) or caculate the output position
//          (if it is set to roll).
// Parm:
///////////////////////////////////////////////////////////
void CColorStatic::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if(nIDEvent==ID_ROLLTIMER)
	{
		if(!m_bTextInfoGotten)
			return;
		CRect  clientRect;
		GetClientRect(&clientRect);

		switch(m_nRollDirection)
		{
			case ROLL_LEFT:
			{
				if(m_nScrollXPos<=clientRect.left-m_nTextWidth)
				{
					m_nScrollXPos=clientRect.right;
				}
				else
				{
					m_nScrollXPos-=m_nStep;
				}
				break;
			}
			case ROLL_RIGHT:
			{
				if(m_nScrollXPos>=clientRect.right)
				{
					m_nScrollXPos=clientRect.left-m_nTextWidth;
				}
				else
				{
					m_nScrollXPos+=m_nStep;
				}
				break;
			}
			case ROLL_UP:
			{
				if(m_nScrollYPos<=clientRect.top-m_nTextHeight)
				{
					m_nScrollYPos=clientRect.bottom;
				}
				else
				{
					m_nScrollYPos-=m_nStep;
				}
				break;
			}
			case ROLL_DOWN:
			{
				if(m_nScrollYPos>=clientRect.bottom)
				{
					m_nScrollYPos=clientRect.top-m_nTextHeight;
				}
				else
				{
					m_nScrollYPos+=m_nStep;
				}
				break;
			}
		}
	}
	else if(nIDEvent==ID_CLOCKTIMER)
	{
		CTime	time=CTime::GetCurrentTime ();
		CString  scurTime;
		scurTime=time.Format ("%H:%M:%S");
		SetText(scurTime);
	}
	Invalidate();
	CStatic::OnTimer(nIDEvent);
}

///////////////////////////////////////////////////////////
// Name:         HCenterText()
///////////////////////////////////////////////////////////
// Function:     H center our text.
// Parm:
///////////////////////////////////////////////////////////
void CColorStatic::HCenterText()
{
	m_bHCentered=true;
	Invalidate();
}

///////////////////////////////////////////////////////////
// Name:         VCenterText()
///////////////////////////////////////////////////////////
// Function:     V center our text.
// Parm:
///////////////////////////////////////////////////////////
void CColorStatic::VCenterText()
{
	m_bVCentered=true;
	Invalidate();
}


///////////////////////////////////////////////////////////
// Name:         SetTextXPos()
///////////////////////////////////////////////////////////
// Function:     Set the output text's x position.
// Parm:
///////////////////////////////////////////////////////////
// Remark:       Use this to change the x pos.
///////////////////////////////////////////////////////////
void CColorStatic::SetTextXPos(int x)
{
	m_nScrollXPos=m_nTextXPos=x;
}

///////////////////////////////////////////////////////////
// Name:         SetTextYPos(int y)
///////////////////////////////////////////////////////////
// Function:     
// Parm:
///////////////////////////////////////////////////////////
void CColorStatic::SetTextYPos(int y)
{
	m_nScrollYPos=m_nTextYPos=y;
}

///////////////////////////////////////////////////////////
// Name:         SetTextFont()
///////////////////////////////////////////////////////////
// Function:     Set the output font of the text.
// Parm:	     LOGFONT *lf
///////////////////////////////////////////////////////////
void CColorStatic::SetTextFont(LOGFONT *lf)
{
	m_font.CreateFontIndirect(lf);
	m_bUseSysFont=false;
	Invalidate();
}

///////////////////////////////////////////////////////////
// Name:        SetTextHeight()
///////////////////////////////////////////////////////////
// Function:    Set the height of the output text.
// Parm:        int height
///////////////////////////////////////////////////////////
//  Remark:      Call this if you only want to change the
//            the height of the text.
//               If you call SetTextFont(LOGFONT *lf),
//            make sure don't call this.
///////////////////////////////////////////////////////////
void CColorStatic::SetTextHeight(int height)
{
	LOGFONT  lf;
	CFont *pDlgFont=GetFont();
	pDlgFont->GetLogFont(&lf);
	lf.lfHeight =height;
	lf.lfWidth =0;
	m_font.CreateFontIndirect(&lf);

	m_bUseSysFont=false;
	m_bTextInfoGotten=false;
	Invalidate();
}

///////////////////////////////////////////////////////////
// Name:        SetClock()
///////////////////////////////////////////////////////////
// Function:    Set the static to show time or date.
// Parm:		bool bTime, value
//              - true    show time
//              - false   show date
///////////////////////////////////////////////////////////
void CColorStatic::SetClock(bool bTime)
{
	if(bTime)
	{
		SetTimer(ID_CLOCKTIMER,500,NULL);
		HCenterText();
		VCenterText();
	}
	else
	{
		CString  scurTime;
		CTime	time=CTime::GetCurrentTime ();
		scurTime=time.Format ("%Y-%m-%d");
		SetText(scurTime);
		HCenterText();
		VCenterText();
	}
}

///////////////////////////////////////////////////////////
// Name:       
///////////////////////////////////////////////////////////
// Function:     
// Parm:
///////////////////////////////////////////////////////////
void CColorStatic::OnDestroy() 
{
	CStatic::OnDestroy();

	// TODO: Add your message handler code here
	if(!m_bRollTimerKilled)
		KillTimer(ID_ROLLTIMER);

	KillTimer(ID_CLOCKTIMER);
}

void CColorStatic::SetBkTransparent(bool btranparent)
{
	m_bBkTransparent=btranparent;
	Invalidate();
}
