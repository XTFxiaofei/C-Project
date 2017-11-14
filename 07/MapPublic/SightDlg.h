#if !defined(AFX_SIGHTDLG_H__F0582B0F_AEA1_4FA8_96B2_C24C61DF4323__INCLUDED_)
#define AFX_SIGHTDLG_H__F0582B0F_AEA1_4FA8_96B2_C24C61DF4323__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SightDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSightDlg dialog

class CSightDlg : public CPropertyPage
{
	DECLARE_DYNCREATE(CSightDlg)

// Construction
public:
	CSightDlg();
	~CSightDlg();
   
	void showpicture();
// Dialog Data
	//{{AFX_DATA(CSightDlg)
	enum { IDD = IDD_SIGHT_DIALOG };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA
public:
	CBitmap  m_bmp;
	  CString sPath;

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CSightDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
public:
	// Generated message map functions
	//{{AFX_MSG(CSightDlg)
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIGHTDLG_H__F0582B0F_AEA1_4FA8_96B2_C24C61DF4323__INCLUDED_)
