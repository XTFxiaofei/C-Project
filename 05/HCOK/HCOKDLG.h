// HCOKDlg.h : header file
//
//{{AFX_INCLUDES()
#include "mediaplayer2.h"
//}}AFX_INCLUDES

#if !defined(AFX_HCOKDLG_H__0F2A74E8_C91C_471B_BCC9_5FD84144A886__INCLUDED_)
#define AFX_HCOKDLG_H__0F2A74E8_C91C_471B_BCC9_5FD84144A886__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Hutext.h"

//**************包含相应头文件************************//
#include "BYSGRDLG.h"
#include "SELECTEDDLG.h"
#include "BYPINYINDLG.h"
#include "BYZISHUDLG.h"
#include "BYSONGTYPDLG.h"
/////////////////////////////////////////////////////////////////////////////
// CHCOKDlg dialog

class CHCOKDlg : public CDialog
{
// Construction
public:
	CHCOKDlg(CWnd* pParent = NULL);	// standard constructor
bool choosed;
int timenum;
void ShowListDate();
void  play();
int getSongNum();

//************非模态窗体指针**************************//
BYSGRDLG * bysingerdlg;      //按歌手查询的对话框成员指针
SELECTEDDLG  * seleceddlg;   //已点歌曲的对话框成员指针
BYPINYINDLG  * bypinyindlg;   //按拼音查询的对话框成员指针
BYZISHUDLG * bynumdlg;        //按歌曲名字数查询的对话框成员指针
BYSONGTYPDLG * bysongtypedlg; //按歌曲类别查询的对话框成员指针


// Dialog Data
	//{{AFX_DATA(CHCOKDlg)
	enum { IDD = IDD_HCOK_DIALOG };
Hutext	m_textctrl;
	CListCtrl	m_list;
	CMediaPlayer2	m_mediaplayer;
	CString	m_text;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHCOKDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CHCOKDlg)
	afx_msg  void GetPlayMode (UINT nID);
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnVolup();
	afx_msg void OnVoldown();
	afx_msg void OnQiuc();
	afx_msg void OnQback();
	afx_msg void OnPlaypause();
	afx_msg void OnStop();
	afx_msg void OnManage();
	afx_msg void OnLogout();
	afx_msg void OnCheckinout();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnSinfind();
	afx_msg void OnPyfind();
	afx_msg void OnNufind();
	afx_msg void OnTfind();
	afx_msg void OnSelected();
	afx_msg void OnDblclkList2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnPrevious();
	afx_msg void OnNext();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnMenudanxun();
	afx_msg void OnMenudelall();
	afx_msg void OnMenudeldan();
	afx_msg void OnMenunanqu();
	afx_msg void OnMenushubo();
	afx_msg void OnMenuxunbo();
	afx_msg void OnEndOfStreamMediaplayer1(long Result);
	afx_msg void OnDellist();
	afx_msg void OnClose();
	afx_msg void OnRclickList2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnHelp();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HCOKDLG_H__0F2A74E8_C91C_471B_BCC9_5FD84144A886__INCLUDED_)
