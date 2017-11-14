#if !defined(AFX_LABEL_H__59128F70_6CC6_11D4_BD73_000021479D21__INCLUDED_)
#define AFX_LABEL_H__59128F70_6CC6_11D4_BD73_000021479D21__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Label.h : header file
//

#define NM_LINKCLICK WM_APP + 0x200

/////////////////////////////////////////////////////////////////////////////
// Hutext window

class Hutext : public CStatic
{
// Construction
public:
 enum FlashType {None, Text, Background };
 enum Type3D { Raised, Sunken};

 Hutext();
 virtual Hutext& SetBkColor(COLORREF crBkgnd);
 virtual Hutext& SetTextColor(COLORREF crText);
 virtual Hutext& SetText(const CString& strText);
 virtual Hutext& SetFontBold(BOOL bBold);
 virtual Hutext& SetFontName(const CString& strFont);
 virtual Hutext& SetFontUnderline(BOOL bSet);
 virtual Hutext& SetFontItalic(BOOL bSet);
 virtual Hutext& SetFontSize(int nSize);
 virtual Hutext& SetSunken(BOOL bSet);
 virtual Hutext& SetBorder(BOOL bSet);
 virtual Hutext& SetTransparent(BOOL bSet);
 virtual Hutext& FlashText(BOOL bActivate);
 virtual Hutext& FlashBackground(BOOL bActivate);
 virtual Hutext& SetLink(BOOL bLink,BOOL bNotifyParent);
 virtual Hutext& SetLinkCursor(HCURSOR hCursor);
 virtual Hutext& SetFont3D(BOOL bSet,Type3D type=Raised);
 virtual Hutext& SetRotationAngle(UINT nAngle,BOOL bRotation);
 virtual Hutext& SetText3DHiliteColor(COLORREF cr3DHiliteColor);

// Attributes
public:
 void ReconstructFont();
 COLORREF m_crText;
 COLORREF m_cr3DHiliteColor;
 HBRUSH  m_hwndBrush;
 HBRUSH  m_hBackBrush;
 LOGFONT  m_lf;
 CFont  m_font;
 CString  m_strText;
 BOOL  m_bState;
 BOOL  m_bTimer;
 BOOL  m_bLink;
 BOOL  m_bTransparent;
 BOOL  m_bFont3d;
 BOOL  m_bToolTips;
 BOOL  m_bNotifyParent;
 BOOL  m_bRotation;
 FlashType m_Type;
 HCURSOR  m_hCursor;
 Type3D  m_3dType;

 // Operations
public:

// Overrides
 // ClassWizard generated virtual function overrides
 //{{AFX_VIRTUAL(Hutext)
 public:
 //}}AFX_VIRTUAL

// Implementation
public:
 virtual ~Hutext();

 // Generated message map functions
protected:
 //{{AFX_MSG(Hutext)
 afx_msg void OnTimer(UINT nIDEvent);
 afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
 afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
 afx_msg void OnSysColorChange();
 afx_msg void OnPaint();
 //}}AFX_MSG

 DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LABEL_H__59128F70_6CC6_11D4_BD73_000021479D21__INCLUDED_)

