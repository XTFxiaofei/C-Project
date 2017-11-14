#if !defined(AFX_COLORSTATIC_H__1E8902A4_E5A0_11D3_A999_CCDB28E9E729__INCLUDED_)
#define AFX_COLORSTATIC_H__1E8902A4_E5A0_11D3_A999_CCDB28E9E729__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ColorStatic.h : header file
//
///////////////////////////////////////////////////////////
//*********************************************************
// Author: Andy good , Beijing, China. Chinese Name:º÷”≠¿÷
//*********************************************************
///////////////////////////////////////////////////////////
//*********************************************************
// Use this freely! If you have any good idea,
// please let me know. E-mail:andygood@263.net.
//*********************************************************
///////////////////////////////////////////////////////////
//
#define ROLL_LEFT		0
#define ROLL_RIGHT		1
#define ROLL_UP 		2
#define ROLL_DOWN		3

#define ID_ROLLTIMER    1
#define ID_CLOCKTIMER   2

/////////////////////////////////////////////////////////////////////////////
// CColorStatic window

class CColorStatic : public CStatic
{
// Construction
public:
	CColorStatic();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorStatic)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	void SetBkTransparent(bool btranparent=true);
	void SetClock(bool bTime=true);
	void SetTextHeight(int height);
	void SetTextFont(LOGFONT*  lf);
	void SetTextYPos(int y);
	void SetTextXPos(int x);
	void VCenterText();
	void HCenterText();
	void StopRoll();
	void BeginRoll(int nStep=5,int nTimer=100);
	void SetText(CString  sText);
	void SetBkColor(COLORREF clBkColor);
	void SetTextColor(COLORREF clTextColor);
	void SetRollDirection(int direction);
	virtual ~CColorStatic();

	// Generated message map functions
protected:
	bool m_bDCStored;
	CDC m_StoreDC;
	bool m_bBkTransparent;
	bool m_bRollTimerKilled;// Judge if we need to kill the roll timer.
							// If you use StopRoll(),we'll not kill timer
							// in OnDestroy().
	bool m_bRollPosSetted;  // Judge if we need to reset the roll position.
							// If you called SetText() or SetTextHeight()
							// or SetTextFont(), this var will be set to
							// false.
	bool m_bTextInfoGotten; // judge if we have gotten the text infomation.
							// If you called SetText() or SetTextHeight()
							// or SetTextFont(), this var will be set to
							// false.
	bool m_bHCentered;      // Judge whether the text should be H centered.
	bool m_bVCentered;      // Judge whether the text should be V centered.
	bool m_bUseSysFont;     // Judge whether use the default font.
	int m_nRollDirection;   // Judge the text's roll direction.
	bool m_bUseRoll;        // Judge whether we should roll the text.
	int m_nScrollYPos;      // Judge the text's output x position when rolling.
	int m_nScrollXPos;      // Judge the text's output y position when rolling.
	int m_nLineHeight;      // one line's height.
	int m_nTextHeight;      // The text's height.When it's multi-line,this var
							// indicate it's all lines' whole height.
	int m_nTextWidth;       // The text's width.When it's multi-line,this var
							// indicate it's lines'max width.
	bool m_bIsSingleLine;   // Judge if the text is single-line.
	int m_nTextYPos;        // The text's output x position.(Use this when the text is not
							// rolling.)
	int m_nStep;            // Every step distance when the is rolling.
	int m_nTextXPos;        // The text's output y position.(Use this when the text is not
							// rolling.)
	CString m_sText;        // Our static's text.
	CFont m_font;           // The user defined font.
	COLORREF m_clBackColor; // Back color.
	COLORREF m_clTextColor;  // Text color.
	//{{AFX_MSG(CColorStatic)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnDestroy();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLORSTATIC_H__1E8902A4_E5A0_11D3_A999_CCDB28E9E729__INCLUDED_)
