// MQQAppearanceDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HCDB.h"
#include "MQQAppearanceDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMQQAppearanceDlg

IMPLEMENT_DYNCREATE(CMQQAppearanceDlg, CFormView)

CMQQAppearanceDlg::CMQQAppearanceDlg()
	: CFormView(CMQQAppearanceDlg::IDD)
{
	//{{AFX_DATA_INIT(CMQQAppearanceDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CMQQAppearanceDlg::~CMQQAppearanceDlg()
{
}

void CMQQAppearanceDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMQQAppearanceDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMQQAppearanceDlg, CFormView)
	//{{AFX_MSG_MAP(CMQQAppearanceDlg)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMQQAppearanceDlg diagnostics

#ifdef _DEBUG
void CMQQAppearanceDlg::AssertValid() const
{
	CFormView::AssertValid();
}

void CMQQAppearanceDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMQQAppearanceDlg message handlers
#define IDC_LST_MENU	WM_USER + 1000
void CMQQAppearanceDlg::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
		//创建抽屉菜单控件
	DWORD dwf = CGfxOutBarCtrl::fDragItems|CGfxOutBarCtrl::fEditGroups|CGfxOutBarCtrl::fEditItems|CGfxOutBarCtrl::fRemoveGroups|
		CGfxOutBarCtrl::fRemoveItems|CGfxOutBarCtrl::fAddGroups|CGfxOutBarCtrl::fAnimation
		|CGfxOutBarCtrl::fSelHighlight;
	CRect rc;
	GetClientRect(&rc);
	rc.bottom=rc.bottom-rc.bottom*0.1;
	wndBar.Create(WS_CHILD|WS_VISIBLE, rc, this,IDC_LST_MENU, dwf);
	wndBar.SetOwner(this);
	
	//创建并设置大小图标链表
	imaLarge.Create(IDB_IMAGELIST, 32, 0, RGB(0,130,132));
	imaSmall.Create(IDB_SMALL_IMAGELIST, 16, 0, RGB(0,128,128));
	wndBar.SetImageList(&imaLarge, CGfxOutBarCtrl::fLargeIcon);
	wndBar.SetImageList(&imaSmall, CGfxOutBarCtrl::fSmallIcon);

	//创建4个抽屉
	wndBar.SetAnimationTickCount(1);
	wndBar.SetAnimSelHighlight(50);
	wndBar.AddFolder("前台管理", 0);
	wndBar.AddFolder("入出库管理",1);
	wndBar.AddFolder("库存管理", 2);
	wndBar.AddFolder("销售管理", 3);
	wndBar.AddFolder("后台设置", 4);
	//给第一个抽屉加图标按钮
	wndBar.InsertItem(0, 0, "前台管理", 0, 0);
	
	
	//给第二个抽屉加图标按钮
	wndBar.InsertItem(1, 0, "登记入库", 0, 0);
	wndBar.InsertItem(1, 1, "入库单查询",0,0);
    wndBar.InsertItem(1, 2, "入库明细",0,0);
	wndBar.InsertItem(1, 3, "登记出库",0,0);
	wndBar.InsertItem(1, 4, "出库单查询",0,0);
	wndBar.InsertItem(1, 5, "出库明细",0,0);
	wndBar.InsertItem(1, 6, "入库汇总",0,0);
	wndBar.InsertItem(1, 7, "出库汇总",0,0);
	//给第三个抽屉加图标按钮
	wndBar.InsertItem(2, 0, "库存管理", 0, 0);
	
	//给第四个抽屉加图标按钮
	wndBar.InsertItem(3, 0, "销售管理", 3, 0);
    //打开第一个抽屉
	wndBar.InsertItem(4, 0, "数据备份", 1, 0);
	wndBar.InsertItem(4, 1, "数据还原", 1, 0);
	wndBar.SetSelFolder(0);
   
	// TODO: Add your specialized code here and/or call the base class
	
}
