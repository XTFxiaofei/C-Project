// HMSysView.cpp : implementation of the CHMSysView class
//

#include "stdafx.h"
#include "HMSys.h"
#include "UserManageDlg.h"
#include "HMSysDoc.h"
#include "HMSysView.h"
#include "CheckManageDlg.h"
#include "EmpAddDlg.h"
#include "DepartManageDlg.h"
#include "EmpInfoManageDlg.h"
#include "HolidayManageDlg.h"
#include "CheckInfoDlg.h"
#include "WageCalDlg.h"
#include "WageManageDlg.h"
#include "WageDlg.h"
#include "UpdatePwdDlg.h"
#include "RestoreDlg.h"
#include "BackupDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHMSysView

IMPLEMENT_DYNCREATE(CHMSysView, CView)

BEGIN_MESSAGE_MAP(CHMSysView, CView)
	//{{AFX_MSG_MAP(CHMSysView)
	ON_COMMAND(IDM_USER_MANAGE, OnUserManage)
	ON_COMMAND(IDM_UPDATE_PWD, OnUpdatePwd)
	ON_COMMAND(IDM_EMP_ADD, OnEmpAdd)
	ON_COMMAND(IDM_DEPART_MANAGE, OnDepartManage)
	ON_COMMAND(IDM_EMP_INFO, OnEmpInfo)
	ON_COMMAND(IDM_HOLIDAT_MANAGE, OnHolidatManage)
	ON_COMMAND(IDM_CHECK_MANAGE, OnCheckManage)
	ON_COMMAND(IDM_CHECK_INFO, OnCheckInfo)
	ON_COMMAND(IDM_WAGE_CAL, OnWageCal)
	ON_COMMAND(IDM_WAGEMANAGE, OnWagemanage)
	ON_COMMAND(IDM_WAGE_TOTAL, OnWageTotal)
	ON_COMMAND(IDM_RESTORE, OnRestore)
	ON_COMMAND(IDM_BACKUP, OnBackup)
	ON_COMMAND(IDT_WAGE, OnWage)
	ON_COMMAND(IDT_CHECK_MANAGE, OnCheckManage)
	ON_COMMAND(IDT_EMP_ADD, OnEmpAdd)
	ON_COMMAND(IDT_USER_MANAGE, OnUserManage)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHMSysView construction/destruction

CHMSysView::CHMSysView()
{
	// TODO: add construction code here

}

CHMSysView::~CHMSysView()
{
}

BOOL CHMSysView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CHMSysView drawing

void CHMSysView::OnDraw(CDC* pDC)
{
	CHMSysDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);	
	CFont *poldfont,* newfont = new CFont;
	TEXTMETRIC tm;
	char str[] = "人事管理系统";
	int x = 320,y = 200, i, len;
	len = strlen(str);
	for(i = 0;i < len;i = i + 2)
	{
		newfont->CreateFont(50, 0, 0, 0, FW_NORMAL, 0, 0, 0, GB2312_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, "华文行楷");
		poldfont = pDC->SelectObject(newfont);
		pDC->GetTextMetrics(&tm);
		pDC->SetTextColor(RGB(255 / len * (i + 2), 50, 250));
		pDC->SetBkMode(TRANSPARENT);//用来设置背景色模式；
		x = x + tm.tmAveCharWidth * 3;
		pDC->TextOut(x, y, &str[i], 2);
		pDC->SelectObject(poldfont);
		newfont->DeleteObject();
	}
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CHMSysView printing

BOOL CHMSysView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CHMSysView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CHMSysView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CHMSysView diagnostics

#ifdef _DEBUG
void CHMSysView::AssertValid() const
{
	CView::AssertValid();
}

void CHMSysView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHMSysDoc* CHMSysView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHMSysDoc)));
	return (CHMSysDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHMSysView message handlers

void CHMSysView::OnUserManage() 
{
	CUserManageDlg dlg;					//定义对话框对象
	dlg.DoModal();						//显示对话框
}
void CHMSysView::OnUpdatePwd() 
{
	CUpdatePwdDlg dlg;
	dlg.DoModal();
}

void CHMSysView::OnEmpAdd() 
{
	CEmpAddDlg dlg;
	dlg.DoModal();
}

void CHMSysView::OnDepartManage() 
{
	CDepartManageDlg dlg;
	dlg.DoModal();
}

void CHMSysView::OnEmpInfo() 
{
	CEmpInfoManageDlg dlg;
	dlg.DoModal();																																						
}

void CHMSysView::OnHolidatManage() 
{
	CHolidayManageDlg dlg;
	dlg.DoModal();
}

void CHMSysView::OnCheckManage() 
{
	CCheckManageDlg dlg;
	dlg.DoModal();
}

void CHMSysView::OnCheckInfo() 
{
	CCheckInfoDlg dlg;
	dlg.DoModal();	
}

void CHMSysView::OnWageCal() 
{
	CWageCalDlg dlg;
	dlg.DoModal();
}

void CHMSysView::OnWagemanage() 
{
	CWageManageDlg dlg;
	dlg.DoModal();
}

void CHMSysView::OnWageTotal() 
{
	CWageDlg dlg;
	dlg.DoModal();
}

void CHMSysView::OnRestore() 
{
	CRestoreDlg dlg;
	dlg.DoModal();
}

void CHMSysView::OnBackup() 
{
	CBackupDlg dlg;
	dlg.DoModal();
}


void CHMSysView::OnWage() 
{
	
	CCheckInfoDlg dlg;
	dlg.DoModal();
}
