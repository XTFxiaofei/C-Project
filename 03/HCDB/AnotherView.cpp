// AnotherView.cpp : implementation file
//

#include "stdafx.h"
#include "HCDB.h"
#include "AnotherView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CAnotherView

IMPLEMENT_DYNCREATE(CAnotherView, CFormView)

CAnotherView::CAnotherView()
	: CFormView(CAnotherView::IDD)
{
	//{{AFX_DATA_INIT(CAnotherView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CAnotherView::~CAnotherView()
{
}

void CAnotherView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAnotherView)
	DDX_Control(pDX, IDC_TAB1, m_Tab);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAnotherView, CFormView)
	//{{AFX_MSG_MAP(CAnotherView)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, OnSelchangeTab1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAnotherView diagnostics

#ifdef _DEBUG
void CAnotherView::AssertValid() const
{
	CFormView::AssertValid();
}

void CAnotherView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAnotherView message handlers

void CAnotherView::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	item.mask=TCIF_TEXT;
    CString str[9];
    
	str[0]="登记入库";                 
	str[1]="入库单查询";                 
	str[2]="入库明细";                   
	str[3]="登记出库";                  
	str[4]="出库单查询";                 
	str[5]="出库明细";             
	str[6]="入库情况汇总";               
	str[7]="出库情况汇总";
	str[8]="主界面";
    item.pszText=str[8].GetBuffer(str[8].GetLength());
    m_Tab.InsertItem(0,&item);
    for(int i=1;i<9;i++)
	{
      item.pszText=str[i-1].GetBuffer(str[i-1].GetLength());
      m_Tab.InsertItem(i,&item);
	}
    gatherinflag=false;
	gatheroutflag=false;
	indetailflag=false;
	outdetailflag=false;
	instockmanageflag=false;
	outstockmanageflag=false;
	instockqueryflag=false;
	outstockqueryflag=false;
	this->GetWindowRect(&DlgRect);
	nFramewidth=::GetSystemMetrics(SM_CXFRAME);
	nTitHeight=::GetSystemMetrics(SM_CYFRAME)+nFramewidth;
	m_Tab.GetWindowRect(&PageRect);
	int a=NewRect.left=PageRect.left-nFramewidth+2-200;
	int b=NewRect.top=PageRect.right-DlgRect.right-80;
	int c=NewRect.right=NewRect.left+PageRect.Width()-nFramewidth;
	int d=NewRect.bottom=NewRect.top+PageRect.Width()-nTitHeight-2;
   
	cbmp.Create(IDF_MBP,this); 
	
    cbmp.MoveWindow(&NewRect);
    cbmp.ShowWindow(true); 
	// TODO: Add your specialized code here and/or call the base class
	
}



void CAnotherView::OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	ClickTab(true);
	*pResult = 0;
}

void CAnotherView::ClickTab(bool flag)
{
	switch(m_Tab.GetCurSel())
	{
	case 0:ShowBmo(true);break;
	case 1:ShowGatherin(true);break;
	case 2:ShowInStockQuery(true);break;
	case 3:ShowIndetail(true);break;
	case 4:ShowGatherOut(true);break;
	case 5:ShowOutStockquery(true);break;
	case 6:ShowOutdetail(true);break;
	case 7:ShowInStockMange(true);break;
	case 8:ShowOutStockMange(true);;break;
	}
}
void CAnotherView::ShowBmo(bool showflag)
{
     CreateWindows();
	cbmp.ShowWindow(true);
    cgatherin.ShowWindow(false); 
    cgatherout.ShowWindow(false);
    cindetail.ShowWindow(false); 
	coutdetail.ShowWindow(false); 
	cinstockmange.ShowWindow(false); 
	coutstockmange.ShowWindow(false);
	cinstockquery.ShowWindow(false);
	coutstockquery.ShowWindow(false);
	//////////////////////////////
	cgatherin.ShowWindows(false);
    cgatherout.ShowWindows(false);
}
void CAnotherView::ShowGatherin(bool showflag)
{
    CreateWindows();
	cbmp.ShowWindow(false);
    cgatherin.ShowWindow(true); 
    cgatherout.ShowWindow(false);
    cindetail.ShowWindow(false); 
	coutdetail.ShowWindow(false); 
	cinstockmange.ShowWindow(false); 
	coutstockmange.ShowWindow(false);
	cinstockquery.ShowWindow(false);
	coutstockquery.ShowWindow(false);	
	
}
void CAnotherView::ShowGatherOut(bool showflag)
{
    CreateWindows();
	cbmp.ShowWindow(false);
    cgatherin.ShowWindow(false); 
    cgatherout.ShowWindow(true);
    cindetail.ShowWindow(false); 
	coutdetail.ShowWindow(false); 
	cinstockmange.ShowWindow(false); 
	coutstockmange.ShowWindow(false);
	cinstockquery.ShowWindow(false);
	coutstockquery.ShowWindow(false);
}
void CAnotherView::ShowIndetail(bool showflag)
{
    CreateWindows();
	cbmp.ShowWindow(false);
    cgatherin.ShowWindow(false); 
    cgatherout.ShowWindow(false);
    cindetail.ShowWindow(true); 
	coutdetail.ShowWindow(false); 
	cinstockmange.ShowWindow(false); 
	coutstockmange.ShowWindow(false);
	cinstockquery.ShowWindow(false);
	coutstockquery.ShowWindow(false);	
}
void CAnotherView::ShowOutdetail(bool showflag)
{
	CreateWindows();
	cbmp.ShowWindow(false);
    cgatherin.ShowWindow(false); 
    cgatherout.ShowWindow(false);
    cindetail.ShowWindow(false); 
	coutdetail.ShowWindow(true); 
	cinstockmange.ShowWindow(false); 
	coutstockmange.ShowWindow(false);
	cinstockquery.ShowWindow(false);
	coutstockquery.ShowWindow(false);
}
void CAnotherView::ShowInStockMange(bool showflag)
{
	CreateWindows();
	cbmp.ShowWindow(false);
    cgatherin.ShowWindow(false); 
    cgatherout.ShowWindow(false);
    cindetail.ShowWindow(false); 
	coutdetail.ShowWindow(false); 
	cinstockmange.ShowWindow(true); 
	coutstockmange.ShowWindow(false);
	cinstockquery.ShowWindow(false);
	coutstockquery.ShowWindow(false);
}
void CAnotherView::ShowOutStockMange(bool showflag)
{
	CreateWindows();
	cbmp.ShowWindow(false);
    cgatherin.ShowWindow(false); 
    cgatherout.ShowWindow(false);
    cindetail.ShowWindow(false); 
	coutdetail.ShowWindow(false); 
	cinstockmange.ShowWindow(false); 
	coutstockmange.ShowWindow(true);
	cinstockquery.ShowWindow(false);
	coutstockquery.ShowWindow(false);
}
void CAnotherView::ShowInStockQuery(bool showflag)
{
    CreateWindows();
	cbmp.ShowWindow(false);
    cgatherin.ShowWindow(false); 
    cgatherout.ShowWindow(false);
    cindetail.ShowWindow(false); 
	coutdetail.ShowWindow(false); 
	cinstockmange.ShowWindow(false); 
	coutstockmange.ShowWindow(false);
	cinstockquery.ShowWindow(true);
	coutstockquery.ShowWindow(false);

}
void CAnotherView::ShowOutStockquery(bool showflag)
{
    CreateWindows();
	cbmp.ShowWindow(false);
    cgatherin.ShowWindow(false); 
    cgatherout.ShowWindow(false);
    cindetail.ShowWindow(false); 
	coutdetail.ShowWindow(false); 
	cinstockmange.ShowWindow(false); 
	coutstockmange.ShowWindow(false);
	cinstockquery.ShowWindow(false);
	coutstockquery.ShowWindow(true);
	
}

BOOL CAnotherView::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
  
	return CFormView::PreTranslateMessage(pMsg);
}

void CAnotherView::CreateWindows()
{
	if(!indetailflag)
	{
		cindetail.Create(IDF_INDETAIL,this);
		cindetail.MoveWindow(&NewRect);
	}	
	indetailflag=true;
	if(!gatherinflag)
	{
		cgatherin.Create(IDF_GATHER_IN,this);
		cgatherin.MoveWindow(&NewRect);
	}
	gatherinflag=true;
	if(!gatheroutflag)
	{
		cgatherout.Create(IDF_GATHER_OUT,this);
		cgatherout.MoveWindow(&NewRect);
	}
	gatheroutflag=true;
    if(!outdetailflag)
	{
		coutdetail.Create(IDF_OUTDETAIL,this);
		coutdetail.MoveWindow(&NewRect);
	}
	outdetailflag=true;
	
	if(!outstockmanageflag)
	{
		coutstockmange.Create(IDF_OUT_STOCKMANGE ,this);
		coutstockmange.MoveWindow(&NewRect);
	}
    outstockmanageflag=true;
	if(!instockmanageflag)
	{
		cinstockmange.Create(IDF_IN_STOCKMANGE ,this);
		cinstockmange.MoveWindow(&NewRect);
	}
	instockmanageflag=true;
	if(!instockqueryflag)
	{
		cinstockquery.Create(IDF_INSTOCKQUERY,this);
		cinstockquery.MoveWindow(&NewRect);
	}
	instockqueryflag=true;
	if(!outstockqueryflag)
	{
		coutstockquery.Create(IDF_OUTSTOCKQUERY,this);
		coutstockquery.MoveWindow(&NewRect);
	}
	outstockqueryflag=true;
	
}
