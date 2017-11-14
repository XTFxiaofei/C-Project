// Label.cpp : implementation file
//

#include "stdafx.h"

#include "Hutext.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Hutext

Hutext::Hutext()
{
 m_crText = GetSysColor(COLOR_WINDOWTEXT);
 m_hBackBrush = NULL;
 ::GetObject((HFONT)GetStockObject(DEFAULT_GUI_FONT),sizeof(m_lf),&m_lf);
 m_font.CreateFontIndirect(&m_lf);
 m_bTimer =   FALSE;
 m_bState =   FALSE;
 m_bTransparent = FALSE;
 m_bLink =   TRUE;
 m_hCursor =   NULL;
 m_Type =   None;
 m_bFont3d =   FALSE;
 m_bNotifyParent = FALSE;
 m_bToolTips =  FALSE;
 m_bRotation =  FALSE;
 m_cr3DHiliteColor = RGB(255,255,255); 
 m_hwndBrush = ::CreateSolidBrush(GetSysColor(COLOR_3DFACE));
}

Hutext::~Hutext()
{
 // Clean up
 m_font.DeleteObject();
 ::DeleteObject(m_hwndBrush);
 ::DeleteObject(m_hBackBrush); 
}

BEGIN_MESSAGE_MAP(Hutext, CStatic)
 //{{AFX_MSG_MAP(Hutext)
 ON_WM_TIMER()
 ON_WM_LBUTTONDOWN()
 ON_WM_SETCURSOR()
 ON_WM_SYSCOLORCHANGE()
 ON_WM_PAINT()
 //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Hutext message handlers

void Hutext::ReconstructFont()
{
 m_font.DeleteObject();
 BOOL bCreated = m_font.CreateFontIndirect(&m_lf);

 ASSERT(bCreated);
}

void Hutext::OnPaint() 
{
 CPaintDC dc(this); // device context for painting

 DWORD dwFlags = 0;

 CRect rc;
 GetClientRect(rc);
 CString strText;
 GetWindowText(strText);
 CBitmap bmp;

 // Set up for double buffering...
 CDC* pDCMem;

 if (!m_bTransparent)
 {
  pDCMem = new CDC;
  pDCMem->CreateCompatibleDC(&dc);
  bmp.CreateCompatibleBitmap(&dc,rc.Width(),rc.Height());
  pDCMem->SelectObject(&bmp);
 }
 else
 {
  pDCMem = &dc;
 }
 
 UINT nMode = pDCMem->SetBkMode(TRANSPARENT);
 
 COLORREF crText = pDCMem->SetTextColor(m_crText);
 CFont *pOldFont = pDCMem->SelectObject(&m_font);

 // Fill in backgound if not transparent
 if (!m_bTransparent)
 {
  CBrush br;
  
  if (m_bState && m_Type == Background)
  {
   if (m_hBackBrush != NULL)
    br.Attach(m_hBackBrush);
   else
    br.Attach(m_hwndBrush);
  }
  else
  {
   if (m_hBackBrush != NULL)
    br.Attach(m_hBackBrush);
   else
    br.Attach(m_hwndBrush);
  }
    
  pDCMem->FillRect(rc,&br);
  br.Detach();
 }
 
 // If the text is flashing turn the text color on
 // then to the color of the window background.

 LOGBRUSH lb;
 ZeroMemory(&lb,sizeof(lb));
 ::GetObject(m_hBackBrush,sizeof(lb),&lb);

 // Something to do with flashing
 if (!m_bState && m_Type == Text)
  pDCMem->SetTextColor(lb.lbColor);

 if (!(GetStyle() & SS_LEFTNOWORDWRAP))
  dwFlags |= DT_WORDBREAK;

 if (GetStyle() & SS_LEFT)
  dwFlags = DT_LEFT;

 if (GetStyle() & SS_RIGHT)
  dwFlags = DT_RIGHT;

 if (GetStyle() & SS_CENTER)
  dwFlags = DT_CENTER;

 // If the text centered make an assumtion that
 // the will want to center verticly as well
 if (GetStyle() & SS_CENTERIMAGE)
 {
  dwFlags = DT_CENTER;

  // Apply 
  if (strText.Find("\r\n") == -1)
  {
   dwFlags |= DT_VCENTER;
   // And because DT_VCENTER only works with single lines
   dwFlags |= DT_SINGLELINE; 
  }
 }

 // 3DÐý×ªÐ§¹û
 if (m_bRotation)
 {
  int nAlign = pDCMem->SetTextAlign (TA_BASELINE);

  CPoint pt;
  GetViewportOrgEx (pDCMem->m_hDC,&pt) ;
  SetViewportOrgEx (pDCMem->m_hDC,rc.Width() / 2, rc.Height() / 2, NULL) ;
  pDCMem->TextOut (0, 0, strText) ;
  SetViewportOrgEx (pDCMem->m_hDC,pt.x / 2, pt.y / 2, NULL) ;
  pDCMem->SetTextAlign (nAlign);
 }
 else
 {
  pDCMem->DrawText(strText,rc,dwFlags);
  if (m_bFont3d)
  {
   pDCMem->SetTextColor(m_cr3DHiliteColor);

   if (m_3dType == Raised)
    rc.OffsetRect(-1,-1);
   else
    rc.OffsetRect(1,1);

   pDCMem->DrawText(strText,rc,dwFlags);
  }
 }

 // Restore DC's State
 pDCMem->SetBkMode(nMode);
 pDCMem->SelectObject(pOldFont);
 pDCMem->SetTextColor(crText);

 if (!m_bTransparent)
 {
  dc.BitBlt(0,0,rc.Width(),rc.Height(),pDCMem,0,0,SRCCOPY);
  delete pDCMem;
 }
}

void Hutext::OnTimer(UINT nIDEvent) 
{
 m_bState = !m_bState;

 InvalidateRect(NULL,TRUE);
 UpdateWindow();
 
 CStatic::OnTimer(nIDEvent);
}

BOOL Hutext::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
 if (m_hCursor)
 {
  ::SetCursor(m_hCursor);
  return TRUE;
 }
 return CStatic::OnSetCursor(pWnd, nHitTest, message);
}

void Hutext::OnLButtonDown(UINT nFlags, CPoint point) 
{
 if (m_bNotifyParent)
 {
  CString strLink;
  GetWindowText(strLink);
  ShellExecute(NULL,"open",strLink,NULL,NULL,SW_SHOWNORMAL);
 }
 else
 {
  // To use notification in parent window
  // Respond to a OnNotify in parent and disassemble the message
  //
  NMHDR nm;
  nm.hwndFrom = GetSafeHwnd();
  nm.idFrom  = GetDlgCtrlID();
  nm.code = NM_LINKCLICK;
  GetParent()->SendMessage(WM_NOTIFY,nm.idFrom,(LPARAM) &nm);
 }
  
 CStatic::OnLButtonDown(nFlags, point);
}

Hutext& Hutext::SetText(const CString& strText)
{
 SetWindowText(strText);
 Invalidate(FALSE);

 return *this;
}

Hutext& Hutext::SetTextColor(COLORREF crText)
{
 m_crText = crText;
 RedrawWindow();
 return *this;
}

Hutext& Hutext::SetFontBold(BOOL bBold)
{
 m_lf.lfWeight = bBold ? FW_BOLD : FW_NORMAL;
 ReconstructFont();
 RedrawWindow();
 return *this;
}

Hutext& Hutext::SetFontUnderline(BOOL bSet)
{ 
 m_lf.lfUnderline = bSet;
 ReconstructFont();
 RedrawWindow();
 return *this;
}

Hutext& Hutext::SetFontItalic(BOOL bSet)
{
 m_lf.lfItalic = bSet;
 ReconstructFont();
 RedrawWindow();
 return *this; 
}

Hutext& Hutext::SetSunken(BOOL bSet)
{
 if (!bSet)
  ModifyStyleEx(WS_EX_STATICEDGE,0,SWP_DRAWFRAME);
 else
  ModifyStyleEx(0,WS_EX_STATICEDGE,SWP_DRAWFRAME);  
 return *this; 
}

Hutext& Hutext::SetBorder(BOOL bSet)
{
 if (!bSet)
  ModifyStyle(WS_BORDER,0,SWP_DRAWFRAME);
 else
  ModifyStyle(0,WS_BORDER,SWP_DRAWFRAME);  
 return *this; 
}

Hutext& Hutext::SetFontSize(int nSize)
{
 CFont cf;
 LOGFONT lf;

 cf.CreatePointFont(nSize * 10, m_lf.lfFaceName);
 cf.GetLogFont(&lf);
 m_lf.lfHeight = lf.lfHeight;
 m_lf.lfWidth  = lf.lfWidth;
 ReconstructFont();
 RedrawWindow();
 return *this;
}

Hutext& Hutext::SetBkColor(COLORREF crBkgnd)
{
 if (m_hBackBrush)
  ::DeleteObject(m_hBackBrush); 
 m_hBackBrush = ::CreateSolidBrush(crBkgnd);
 Invalidate(FALSE);
 return *this;
}

Hutext& Hutext::SetFontName(const CString& strFont)
{ 
 strcpy(m_lf.lfFaceName,strFont);
 ReconstructFont();
 RedrawWindow();
 return *this;
}

Hutext& Hutext::FlashText(BOOL bActivate)
{
 if (m_bTimer)
  KillTimer(1);

 if (bActivate)
 {
  m_bState = FALSE;  
  m_bTimer = TRUE;  
  SetTimer(1,500,NULL);
  m_Type = Text;
 }
 else
  m_Type = None;
 return *this;
}

Hutext& Hutext::FlashBackground(BOOL bActivate)
{
 if (m_bTimer)
  KillTimer(1);

 if (bActivate)
 {
  m_bState = FALSE;
  m_bTimer = TRUE;
  SetTimer(1,500,NULL);
  m_Type = Background;
 }
 return *this;
}

Hutext& Hutext::SetLink(BOOL bLink,BOOL bNotifyParent)
{

 m_bLink = bLink;
 m_bNotifyParent = bNotifyParent;

 if (bLink)
  ModifyStyle(0,SS_NOTIFY);
 else
  ModifyStyle(SS_NOTIFY,0);

 return *this;
}

Hutext& Hutext::SetLinkCursor(HCURSOR hCursor)
{

 m_hCursor = hCursor;
 return *this;
}

Hutext& Hutext::SetTransparent(BOOL bSet)
{

 m_bTransparent = bSet;
 ModifyStyleEx(0,WS_EX_TRANSPARENT);
 InvalidateRect(NULL,TRUE);
 UpdateWindow();
 return *this;
}

Hutext& Hutext::SetFont3D(BOOL bSet,Hutext::Type3D type)
{
 m_bFont3d = bSet;
 m_3dType = type;
 RedrawWindow();
 return *this;
}

void Hutext::OnSysColorChange() 
{
 if (m_hwndBrush)
  ::DeleteObject(m_hwndBrush);
 m_hwndBrush = ::CreateSolidBrush(GetSysColor(COLOR_3DFACE)); 
 RedrawWindow();  
}

Hutext& Hutext::SetRotationAngle(UINT nAngle,BOOL bRotation)
{
 m_lf.lfEscapement = m_lf.lfOrientation = (nAngle * 10);
 m_bRotation = bRotation; 
 ReconstructFont(); 
 RedrawWindow();
 return *this;
}

Hutext& Hutext::SetText3DHiliteColor(COLORREF cr3DHiliteColor)
{
 m_cr3DHiliteColor = cr3DHiliteColor;
 RedrawWindow();
 return *this;
}
