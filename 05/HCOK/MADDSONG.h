#if !defined(AFX_MADDSONG_H__8B2C0E96_3893_40B7_937F_74F113202707__INCLUDED_)
#define AFX_MADDSONG_H__8B2C0E96_3893_40B7_937F_74F113202707__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MADDSONG.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// MADDSONG dialog

typedef struct _MP3INFO //MP3信息的结构
{
	char Identify[3]; //TAG三个字母可以用来鉴别是不是文件信息内容
	char Title[31];   //歌曲名，30个字节
	char Artist[31];  //歌手名，30个字节
	char Album[31];   //所属唱片，30个字节
	char Year[5];	  //年，4个字节
	char Comment[29]; //注释，28个字节
	unsigned char reserved;  //保留位，1个字节
	unsigned char reserved2; //保留位，1个字节
	unsigned char reserved3; //保留位，1个字节
} MP3INFO;

class MADDSONG : public CDialog
{
// Construction
public:
	MADDSONG(CWnd* pParent = NULL);   // standard constructor
  	CString Qfilename1,Qfilename2;
void ShowData() ;
// Dialog Data
	//{{AFX_DATA(MADDSONG)
	enum { IDD = IDD_MADDSONG };
	CButton	m_radio;
	CListCtrl	m_list;
	CComboBox	m_comb2;
	CComboBox	m_comb1;
	CString	m_filename;
	CString	m_format;
	CString	m_singer;
	CString	m_songname;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(MADDSONG)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
MP3INFO *mp3;

	// Generated message map functions
	//{{AFX_MSG(MADDSONG)
	virtual BOOL OnInitDialog();
	afx_msg void OnChoose();
	afx_msg void OnAdd();
	afx_msg void OnDel();
	afx_msg void OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MADDSONG_H__8B2C0E96_3893_40B7_937F_74F113202707__INCLUDED_)
