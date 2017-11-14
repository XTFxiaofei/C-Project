// MapPublicView.cpp : implementation of the CMapPublicView class
//

#include "stdafx.h"
#include "StationSet.h"
#include "MapPublicDoc.h"
#include "MapPublicView.h"
#include "SpeciesSet.h"
#include "malloc.h"
#include "math.h"
#include "DelSingleStation.h"
#include "FindDlg.h"
#include "AddOneRoadway.h"
#include "DelRoadway.h"
#include "hangeStation.h"
#include "Attribute.h"
#include "AddAttributeDlg.h"
#include "LoginDlg.h"
#include "SpeciesSet.h"
#include "StationSet.h"
#include "Map_Station_Set.h"
#include "Action_Time_Set.h"
#include "AttributeSet.h"
#include "QueryDlg.h"
#include "HawkSightView.h"

#include<MMSYSTEM.H>
#define ZOOMIN 111
#define ZOOMOUT 112
#define PAN 113
#define FULLSHOW 114
#define MAXLAYERS 23
#define GetDisP1toP2 115
#define GetAttribute 116
#define SELECTPOINT 117
#define LT_LIGHT 5
//#define FLASH  118
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMapPublicView



IMPLEMENT_DYNCREATE(CMapPublicView, CFormView)

BEGIN_MESSAGE_MAP(CMapPublicView, CFormView)
//{{AFX_MSG_MAP(CMapPublicView)
ON_WM_SIZE()
ON_COMMAND(ID_MAP_ZOOMIN, OnMapZoomin)
ON_COMMAND(ID_MAP_ZOOMOUT, OnMapZoomout)
ON_COMMAND(ID_MAP_PAN, OnMapPan)
ON_COMMAND(ID_MAP_FULLSHOW, OnMapFullshow)
ON_COMMAND(ID_COMMUNITY, OnCommunity)
ON_COMMAND(ID_BANK, OnBank)
ON_COMMAND(ID_EDUCATION, OnEducation)
ON_COMMAND(ID_RESTAURANT, OnRestaurant)
ON_COMMAND(ID_SHOP, OnShop)
ON_COMMAND(ID_TOUR, OnTour)
ON_COMMAND(ID_HOSPITAL, OnHospital)
ON_COMMAND(ID_TRAFFIC, OnTraffic)
ON_COMMAND(ID_ENTERPRISE, OnEnterprise)
ON_COMMAND(ID_GOVERMENT, OnGoverment)
ON_COMMAND(ID_ALL, OnAll)
ON_COMMAND(ID_SAVEBMP, OnSavebmp)
ON_COMMAND(ID_MEASURE, OnMeasure)
ON_COMMAND(ID_FIND, OnFind)
ON_COMMAND(ID_DEL_STATION, OnDelStation)
ON_COMMAND(ID_ADD_ROADWAY, OnAddRoadway)
ON_COMMAND(ID_DEL_ROADWAY, OnDelRoadway)
ON_COMMAND(ID_CHANGE_STATION, OnChangeStation)
ON_COMMAND(ID_SELECT, OnSelect)
ON_COMMAND(ID_SELECT_ATTRIBUTE, OnSelectAttribute)
ON_COMMAND(ID_SELECT_POINT, OnSelectPoint)
ON_COMMAND(ID_FRESH, OnFresh)
ON_UPDATE_COMMAND_UI(ID_SELECT_POINT, OnUpdateSelectPoint)
ON_UPDATE_COMMAND_UI(ID_DEL_STATION, OnUpdateDelStation)
ON_UPDATE_COMMAND_UI(ID_CHANGE_STATION, OnUpdateChangeStation)
ON_UPDATE_COMMAND_UI(ID_ADD_ROADWAY, OnUpdateAddRoadway)
ON_UPDATE_COMMAND_UI(ID_DEL_ROADWAY, OnUpdateDelRoadway)
ON_UPDATE_COMMAND_UI(ID_LOG, OnUpdateLog)
ON_UPDATE_COMMAND_UI(ID_SELECT_ATTRIBUTE, OnUpdateSelectAttribute)
ON_COMMAND(ID_USER_LOGIN, OnUserLogin)
ON_UPDATE_COMMAND_UI(ID_USER_LOGIN, OnUpdateUserLogin)
ON_COMMAND(ID_QUIT, OnQuit)
ON_UPDATE_COMMAND_UI(ID_QUIT, OnUpdateQuit)
ON_COMMAND(ID_PUBLIC_BUS, OnPublicBus)
ON_COMMAND(ID_HELP, OnHelp)
ON_COMMAND(ID_SYS_LOG, OnSysLog)
ON_UPDATE_COMMAND_UI(ID_SYS_LOG, OnUpdateSysLog)
	ON_WM_MOUSEMOVE()
	ON_WM_TIMER()
	ON_COMMAND(ID_MUSIC, OnMusic)
	ON_UPDATE_COMMAND_UI(ID_MUSIC, OnUpdateMusic)
	//}}AFX_MSG_MAP
// Standard printing commands

ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMapPublicView construction/destruction

CMapPublicView::CMapPublicView()
: CFormView(CMapPublicView::IDD)
{
	Number=1;
	bControlFlag=false;
	for(int i=0;i<MAXLAYERS;i++)
	{
		m_mapInfo[i].index=-1;
		m_mapInfo[i].szLayerName="";
		m_mapInfo[i].bLable=false;
		m_mapInfo[i].bVisible=true;
	}
	m_nindex=0;
	showflag=false;
	showpointflag=false;
	pointflag=false;
	bCheckMenu=false;
	musicflag=false;

	//	finddlg=NULL;
	
	
	//{{AFX_DATA_INIT(CMapPublicView)
	// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// TODO: add construction code here
	
}

CMapPublicView::~CMapPublicView()
{
	//	delete m_layers[0];
	//	delete m_maplayer[0];
}

void CMapPublicView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMapPublicView)
	DDX_Control(pDX, IDC_MAP1, m_Map);
	DDX_Control(pDX, IDC_LED7, m_Led7);
	DDX_Control(pDX, IDC_LED6, m_Led6);
	DDX_Control(pDX, IDC_LED5, m_Led5);
	DDX_Control(pDX, IDC_LED4, m_Led4);
	DDX_Control(pDX, IDC_LED3, m_Led3);
	DDX_Control(pDX, IDC_LED2, m_Led2);
	DDX_Control(pDX, IDC_LED1, m_Led1);
    DDX_Control(pDX, IDC_LED8, m_Led8);
	DDX_Control(pDX, IDC_LED9, m_Led9);
	DDX_Control(pDX, IDC_LED10, m_Led10);
	DDX_Control(pDX, IDC_LED11, m_Led11);
	DDX_Control(pDX, IDC_LED12, m_Led12);
	DDX_Control(pDX, IDC_LED13, m_Led13);
	DDX_Control(pDX, IDC_LED14, m_Led14);
	DDX_Control(pDX, IDC_LED15, m_Led15);
	DDX_Control(pDX, IDC_LED16, m_Led16);
	DDX_Control(pDX, IDC_LED17, m_Led17);
	DDX_Control(pDX, IDC_LED18, m_Led18);
	DDX_Control(pDX, IDC_LED19, m_Led19);
	DDX_Control(pDX, IDC_LED20, m_Led20);
	DDX_Control(pDX, IDC_LED21, m_Led21);
	DDX_Control(pDX, IDC_LED22, m_Led22);
	DDX_Control(pDX, IDC_LED23, m_Led23);
	//}}AFX_DATA_MAP
}

BOOL CMapPublicView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	
	return CFormView::PreCreateWindow(cs);
}

void CMapPublicView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	
	//	SetTimer(1,500,NULL);
	/*
	CMainFrame *pFrame=(CMainFrame *)AfxGetMainWnd();
	if(!pointflag)
	{
	pwnd=pFrame->m_wndToolBar.GetDlgItem(ID_SELECT_POINT);
	pwnd->EnableWindow(false);
	
	  
		}
	*/
	m_Map.SetBackColor(RGB(255,255,170));
	//	CString sPath;//保存数据库文件路径名
	GetModuleFileName(NULL,sPath.GetBufferSetLength (MAX_PATH+1),MAX_PATH);//为sPath分配存储空间
	sPath.ReleaseBuffer();
	int nPos;
	nPos=sPath.ReverseFind('\\');
	sPath=sPath.Left(nPos);//获取文件的路径
    nPos=sPath.ReverseFind('\\');
	sPath=sPath.Left(nPos);//获取文件的路径
	sPath+="\\Map";
	sPath+="\\";
    
    
	AddLayer();//添加图层
    CMoRectangle rect;
	
	rect=m_Map.GetExtent(); //m_Map.GetExtent()获得当前地图显示范围
	//设置放大系数         
	rect.ScaleRectangle(0.1);
	m_Map.SetExtent(rect);//设置当前地图显示范围
//	CMainFrame *pFrame=(CMainFrame *)AfxGetMainWnd();
//	CHawkSightView *p_View=(CHawkSightView *)(pFrame->m_wndSplitter2.GetPane(2,0));
//	p_View->m_sightdlg.showpicture();
    showlight();	
}
void CMapPublicView::showlight()
{
    m_Led1.SetLed(CLed::LED_COLOR_RED,CLed::LED_OFF,CLed::LED_ROUND);
	m_Led2.SetLed(CLed::LED_COLOR_RED,CLed::LED_OFF,CLed::LED_ROUND);
	m_Led3.SetLed(CLed::LED_COLOR_RED,CLed::LED_OFF,CLed::LED_ROUND);
	m_Led4.SetLed(CLed::LED_COLOR_RED,CLed::LED_OFF,CLed::LED_ROUND);
	m_Led5.SetLed(CLed::LED_COLOR_RED,CLed::LED_OFF,CLed::LED_ROUND);
	m_Led6.SetLed(CLed::LED_COLOR_RED,CLed::LED_OFF,CLed::LED_ROUND);
	m_Led7.SetLed(CLed::LED_COLOR_RED,CLed::LED_OFF,CLed::LED_ROUND);
	m_Led8.SetLed(CLed::LED_COLOR_RED,CLed::LED_OFF,CLed::LED_ROUND);
	m_Led9.SetLed(CLed::LED_COLOR_RED,CLed::LED_OFF,CLed::LED_ROUND);
	m_Led10.SetLed(CLed::LED_COLOR_RED,CLed::LED_OFF,CLed::LED_ROUND);
	m_Led11.SetLed(CLed::LED_COLOR_RED,CLed::LED_OFF,CLed::LED_ROUND);
	m_Led12.SetLed(CLed::LED_COLOR_RED,CLed::LED_OFF,CLed::LED_ROUND);
	m_Led13.SetLed(CLed::LED_COLOR_RED,CLed::LED_OFF,CLed::LED_ROUND);
	m_Led14.SetLed(CLed::LED_COLOR_RED,CLed::LED_OFF,CLed::LED_ROUND);
	m_Led15.SetLed(CLed::LED_COLOR_RED,CLed::LED_OFF,CLed::LED_ROUND);
	m_Led16.SetLed(CLed::LED_COLOR_RED,CLed::LED_OFF,CLed::LED_ROUND);
	m_Led17.SetLed(CLed::LED_COLOR_RED,CLed::LED_OFF,CLed::LED_ROUND);
	m_Led18.SetLed(CLed::LED_COLOR_RED,CLed::LED_OFF,CLed::LED_ROUND);
	m_Led19.SetLed(CLed::LED_COLOR_RED,CLed::LED_OFF,CLed::LED_ROUND);
	m_Led20.SetLed(CLed::LED_COLOR_RED,CLed::LED_OFF,CLed::LED_ROUND);
	m_Led21.SetLed(CLed::LED_COLOR_RED,CLed::LED_OFF,CLed::LED_ROUND);
	m_Led22.SetLed(CLed::LED_COLOR_RED,CLed::LED_OFF,CLed::LED_ROUND);
	m_Led23.SetLed(CLed::LED_COLOR_RED,CLed::LED_OFF,CLed::LED_ROUND);

	SetTimer(LT_LIGHT,22,NULL);
}

void CMapPublicView::AddLayer()
{
	
	CString lpszFileName;
	CSpeciesSet m_pSpeciesSet;
	m_pSpeciesSet.Open();
	m_pSpeciesSet.MoveFirst();
	while(!m_pSpeciesSet.IsEOF())
	{   
		lpszFileName=sPath+m_pSpeciesSet.m_ShpName;
		switch(m_pSpeciesSet.m_index)
		{
		case 0://林地
			AddShpLayer(m_maplayer,lpszFileName,RGB(104,255,104),0,0,1,0);
			m_mapInfo[m_nindex].index=m_nindex;
			m_mapInfo[m_nindex].bLable=true;
			m_mapInfo[m_nindex++].szLayerName=m_pSpeciesSet.m_ShpName;
			break;
		case 1://绿地
			AddShpLayer(m_maplayer,lpszFileName,RGB(157,255,157),0,0,1,1);
			m_mapInfo[m_nindex].index=m_nindex;
			m_mapInfo[m_nindex].bLable=true;
			m_mapInfo[m_nindex++].szLayerName=m_pSpeciesSet.m_ShpName;
			break;
		case 2://市区空地
			AddShpLayer(m_maplayer,lpszFileName,RGB(238,238,255),0,0,1,2);
			m_mapInfo[m_nindex].index=m_nindex;
			m_mapInfo[m_nindex].bLable=true;
			m_mapInfo[m_nindex++].szLayerName=m_pSpeciesSet.m_ShpName;
			break;
		case 3://街道层
			AddShpLayer(m_maplayer,lpszFileName,RGB(255,255,193),0,0,1,3);
			m_mapInfo[m_nindex].index=m_nindex;
			m_mapInfo[m_nindex].bLable=true;
			m_mapInfo[m_nindex++].szLayerName=m_pSpeciesSet.m_ShpName;
			break;
		case 4://街区
			AddShpLayer(m_maplayer,lpszFileName,RGB(255,255,170),0,0,1,4);
			m_mapInfo[m_nindex].index=m_nindex;
			m_mapInfo[m_nindex].bLable=true;
			m_mapInfo[m_nindex++].szLayerName=m_pSpeciesSet.m_ShpName;
			break;
		case 5://河流
			AddShpLayer(m_maplayer,lpszFileName,RGB(176,176,255),0,0,1,5);
			m_mapInfo[m_nindex].index=m_nindex;
			m_mapInfo[m_nindex].bLable=true;
			m_mapInfo[m_nindex++].szLayerName=m_pSpeciesSet.m_ShpName;
			break;
			
			//*************************************************
			
		case 6://铁路
			AddShpLayer(m_maplayer,lpszFileName,RGB(206,0,103),4,1,1,6);
			m_mapInfo[m_nindex].index=m_nindex;
			m_mapInfo[m_nindex].bLable=true;
			m_mapInfo[m_nindex++].szLayerName=m_pSpeciesSet.m_ShpName;
			AddLabel(m_nindex-1,RGB(0,0,0),12);
			break;
		case 7://水系注记
			AddShpLayer(m_maplayer,lpszFileName,RGB(0,0,255),0,0,1,7);
			m_mapInfo[m_nindex].index=m_nindex;
			m_mapInfo[m_nindex].bLable=true;
			m_mapInfo[m_nindex++].szLayerName=m_pSpeciesSet.m_ShpName;
			AddLabel(m_nindex-1,RGB(255,255,120),20);
			break;
		case 8://高架桥
			AddShpLayer(m_maplayer,lpszFileName,RGB(100,255,100),0,0,0,8);
			m_mapInfo[m_nindex].index=m_nindex;
			m_mapInfo[m_nindex].bLable=true;
			m_mapInfo[m_nindex++].szLayerName=m_pSpeciesSet.m_ShpName;
			//	AddLabel(m_nindex-1,RGB(128,0,255),12);
			break;
		case 9://街道线
			AddShpLayer(m_maplayer,lpszFileName,RGB(235,235,235),6,0,1,9);
			m_mapInfo[m_nindex].index=m_nindex;
			m_mapInfo[m_nindex].bLable=true;
			m_mapInfo[m_nindex++].szLayerName=m_pSpeciesSet.m_ShpName;
			AddLabel(m_nindex-1,RGB(0,0,0),10);
			break;
		case 10://宾馆酒店
			AddShpLayer(m_maplayer,lpszFileName,RGB(255,0,255),0,0,1,10);
			m_mapInfo[m_nindex].index=m_nindex;
			m_mapInfo[m_nindex].bLable=true;
			m_mapInfo[m_nindex++].szLayerName=m_pSpeciesSet.m_ShpName;
			AddLabel(m_nindex-1,RGB(255,121,188),9);
			break;
		case 11://景点
			AddShpLayer(m_maplayer,lpszFileName,RGB(128,255,128),0,0,1,11);
			m_mapInfo[m_nindex].index=m_nindex;
			m_mapInfo[m_nindex].bLable=true;
			m_mapInfo[m_nindex++].szLayerName=m_pSpeciesSet.m_ShpName;
			AddLabel(m_nindex-1,RGB(0,0,213),9);	
			break;
		case 12://厂矿企业
			AddShpLayer(m_maplayer,lpszFileName,RGB(134,159,249),0,0,1,12);
			m_mapInfo[m_nindex].index=m_nindex;
			m_mapInfo[m_nindex].bLable=true;
			m_mapInfo[m_nindex++].szLayerName=m_pSpeciesSet.m_ShpName;
			AddLabel(m_nindex-1,RGB(0,0,128),10);
			break;
		case 13://交通运输
			AddShpLayer(m_maplayer,lpszFileName,RGB(0,64,128),0,0,0,13);
			m_mapInfo[m_nindex].index=m_nindex;
			//	m_mapInfo[m_nindex].bLable=true;
			m_mapInfo[m_nindex++].szLayerName=m_pSpeciesSet.m_ShpName;
			// AddLabel(m_nindex-1,RGB(0,0,0),10);
			break;
		case 14://其它名称
			AddShpLayer(m_maplayer,lpszFileName,RGB(0,128,0),0,0,0,14);
			m_mapInfo[m_nindex].index=m_nindex;
			//	m_mapInfo[m_nindex].bLable=true;
			m_mapInfo[m_nindex++].szLayerName=m_pSpeciesSet.m_ShpName;
			//	AddLabel(m_nindex-1,RGB(0,0,0),10);
			break;
			/*		case 15://三级旅游资源
			AddShpLayer(m_maplayer,lpszFileName,RGB(128,255,128),0,0,0,15);
			m_mapInfo[m_nindex].index=m_nindex;
			//	m_mapInfo[m_nindex].bLable=true;
			m_mapInfo[m_nindex++].szLayerName=m_pSpeciesSet.m_ShpName;
			//	AddLabel(m_nindex-1,RGB(0,0,213),9);
			break;
			*/
		case 15://山峰注记
			AddShpLayer(m_maplayer,lpszFileName,RGB(0,230,0),0,0,0,15);
			m_mapInfo[m_nindex].index=m_nindex;
			//	m_mapInfo[m_nindex].bLable=true;
			m_mapInfo[m_nindex++].szLayerName=m_pSpeciesSet.m_ShpName;
			//  AddLabel(m_nindex-1,RGB(0,0,0),10); 
			break;
		case 16://商场大厦
			AddShpLayer(m_maplayer,lpszFileName,RGB(0,0,200),0,0,0,16);
			m_mapInfo[m_nindex].index=m_nindex;
			//	m_mapInfo[m_nindex].bLable=true;
			m_mapInfo[m_nindex++].szLayerName=m_pSpeciesSet.m_ShpName;
			//	AddLabel(m_nindex-1,RGB(0,0,0),10);	
			break;
		case 17://村庄小区
			AddShpLayer(m_maplayer,lpszFileName,RGB(0,0,255),0,0,0,17);
			m_mapInfo[m_nindex].index=m_nindex;
			//	m_mapInfo[m_nindex].bLable=true;
			m_mapInfo[m_nindex++].szLayerName=m_pSpeciesSet.m_ShpName;
			//   AddLabel(m_nindex-1,RGB(0,0,0),10);
			break;
		case 18://事业单位
			AddShpLayer(m_maplayer,lpszFileName,RGB(0,0,255),0,0,0,18);
			m_mapInfo[m_nindex].index=m_nindex;
			//	m_mapInfo[m_nindex].bLable=true;
			m_mapInfo[m_nindex++].szLayerName=m_pSpeciesSet.m_ShpName;
			//	AddLabel(m_nindex-1,RGB(0,0,0),10);
			break;
		case 19://金融机构
			AddShpLayer(m_maplayer,lpszFileName,RGB(128,128,255),0,0,0,19);
			m_mapInfo[m_nindex].index=m_nindex;
			//	m_mapInfo[m_nindex].bLable=true;
			m_mapInfo[m_nindex++].szLayerName=m_pSpeciesSet.m_ShpName;
			//	AddLabel(m_nindex-1,RGB(0,0,0),10);
			break;
			/*		case 21://二级旅游资源
			AddShpLayer(m_maplayer,lpszFileName,RGB(128,255,128),0,0,0,21);
			m_mapInfo[m_nindex].index=m_nindex;
			//	m_mapInfo[m_nindex].bLable=true;
			m_mapInfo[m_nindex++].szLayerName=m_pSpeciesSet.m_ShpName;
			//   AddLabel(m_nindex-1,RGB(0,0,213),9);
			break;
			case 22://文体机构
			AddShpLayer(m_maplayer,lpszFileName,RGB(0,0,255),0,0,0,22);
			m_mapInfo[m_nindex].index=m_nindex;
			//		m_mapInfo[m_nindex].bLable=true;
			m_mapInfo[m_nindex++].szLayerName=m_pSpeciesSet.m_ShpName;
			//	AddLabel(m_nindex-1,RGB(0,0,0),10);
			break;
			case 23://五级旅游资源
			AddShpLayer(m_maplayer,lpszFileName,RGB(128,255,128),0,0,0,23);
			m_mapInfo[m_nindex].index=m_nindex;
			//	m_mapInfo[m_nindex].bLable=true;
			m_mapInfo[m_nindex++].szLayerName=m_pSpeciesSet.m_ShpName;
			//	AddLabel(m_nindex-1,RGB(0,0,213),9);
			break;
			*/
		case 20://学校
			AddShpLayer(m_maplayer,lpszFileName,RGB(0,0,255),0,0,0,20);
			m_mapInfo[m_nindex].index=m_nindex;
			//	m_mapInfo[m_nindex].bLable=true;
			m_mapInfo[m_nindex++].szLayerName=m_pSpeciesSet.m_ShpName;
			//	AddLabel(m_nindex-1,RGB(0,0,0),10);
			break;
			/*		case 25://一级旅游资源
			AddShpLayer(m_maplayer,lpszFileName,RGB(128,255,128),0,0,0,25);
			m_mapInfo[m_nindex].index=m_nindex;
			//	m_mapInfo[m_nindex].bLable=true;
			m_mapInfo[m_nindex++].szLayerName=m_pSpeciesSet.m_ShpName;
			//	AddLabel(m_nindex-1,RGB(0,0,213),9);
			break;
			*/
		case 21://医疗卫生
			AddShpLayer(m_maplayer,lpszFileName,RGB(0,0,255),0,0,0,21);
			m_mapInfo[m_nindex].index=m_nindex;
			//	m_mapInfo[m_nindex].bLable=true;
			m_mapInfo[m_nindex++].szLayerName=m_pSpeciesSet.m_ShpName;
			//	AddLabel(m_nindex-1,RGB(0,0,0),10);
			break;
		case 22://政府机构
			AddShpLayer(m_maplayer,lpszFileName,RGB(128,128,255),0,0,0,22);
			m_mapInfo[m_nindex].index=m_nindex;
			//	m_mapInfo[m_nindex].bLable=true;
			m_mapInfo[m_nindex++].szLayerName=m_pSpeciesSet.m_ShpName;
			//	AddLabel(m_nindex-1,RGB(255,0,0),10);
			break;
			//******************************************************
		}
        m_pSpeciesSet.MoveNext();
	}
    m_pSpeciesSet.Close();
    
	
}
/////////////////////////////////////////////////////////////////////////////
// CMapPublicView printing

BOOL CMapPublicView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMapPublicView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMapPublicView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMapPublicView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CMapPublicView diagnostics

#ifdef _DEBUG
void CMapPublicView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMapPublicView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMapPublicDoc* CMapPublicView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMapPublicDoc)));
	return (CMapPublicDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMapPublicView message handlers

void CMapPublicView::OnSize(UINT nType, int cx, int cy) 
{
	CFormView::OnSize(nType, cx, cy);
	
    if(m_Map.m_hWnd)	//判断地图控件窗口是否创建
		m_Map.SetWindowPos(0,0,0,cx,cy,SWP_NOZORDER);
}

void CMapPublicView::OnMapZoomin() 
{
	PlayResource(IDR_WAVE2);
	m_CurrentOperation=ZOOMIN;
	m_Map.SetMousePointer(51);//将鼠标设置成放大图形
	
	
}

void CMapPublicView::OnMapZoomout() 
{
   PlayResource(IDR_WAVE2);
	m_CurrentOperation=ZOOMOUT;
	m_Map.SetMousePointer(52);//将鼠标设置成缩小图形

}

void CMapPublicView::OnMapPan() 
{
	PlayResource(IDR_WAVE2);
	m_CurrentOperation=PAN;
	m_Map.SetMousePointer(53);////将鼠标设置成漫游图形
}

BEGIN_EVENTSINK_MAP(CMapPublicView, CFormView)
//{{AFX_EVENTSINK_MAP(CMapPublicView)
ON_EVENT(CMapPublicView, IDC_MAP1, -605 /* MouseDown */, OnMouseDownMap1, VTS_I2 VTS_I2 VTS_I4 VTS_I4)
ON_EVENT(CMapPublicView, IDC_MAP1, -601 /* DblClick */, OnDblClickMap1, VTS_NONE)
ON_EVENT(CMapPublicView, IDC_MAP1, 3 /* AfterLayerDraw */, OnAfterLayerDrawMap1, VTS_I2 VTS_BOOL VTS_I4)
//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CMapPublicView::OnMouseDownMap1(short Button, short Shift, long X, long Y) 
{//Button 表示当前单击的鼠标键1左键 2右键 3中键
	//shift  表示单击时按下键盘上的键 1shift 2ctrl 3Alt
	//X 鼠标单击处X坐标
	//Y 鼠标单击处Y坐标
	CString str;
	CMoPoint m_CenterPoint;//缩放的中心点
	double m_CenterPointX;
	double m_CenterPointY;
	CMoRectangle rect_Extent;//CMoRectangle 记录鼠标所拉出的矩形范围
	///////////////////////////////////////////////////******************
	double m_TrackRectangle_Heigh;//拉框所选范围的高度
	double m_TrackRectangle_Width;//拉框所选范围的宽度
	CMoRectangle rect;//拉框范围
	double X_Scale;//x 方向拉框比例
	double Y_Scale;//Y方向拉框比例
	double m_Scale;//比例系数
	
	//比例尺
	//-----------------------------------------------------------
    int x=(int)Info.CalcScale(&m_Map);
	str.Format("比例尺 1:%d",x);
	///////////////////////////////////////////////////////////********************
    switch(m_CurrentOperation)	
	{
	case PAN://漫游
		m_Map.Pan();
		break;
	case ZOOMIN://放大
		if(x<7000)
		{
			if(!bControlFlag)
				ShowLayer();
			MessageBox("已经到最大");
			break;
		}
		rect=m_Map.TrackRectangle();
		m_TrackRectangle_Heigh=rect.GetHeight()/2;
		m_TrackRectangle_Width=rect.GetWidth()/2;
		///////////////////****************************
		//拉框放大
		if(LPDISPATCH(rect)&&m_TrackRectangle_Heigh!=0&&m_TrackRectangle_Width!=0)
		{
			m_Map.SetExtent(rect);
		}
        else//定点放大
		{
			//////////////////////*******************
			m_CenterPoint=m_Map.ToMapPoint(float(X),float(Y));//将屏幕坐标转换成空间坐标
			m_CenterPointX=m_CenterPoint.GetX();
			m_CenterPointY=m_CenterPoint.GetY();
			rect_Extent=m_Map.GetExtent(); //m_Map.GetExtent()获得当前地图显示范围
			//设置放大系数         
			rect_Extent.ScaleRectangle(0.9);
			m_Map.SetExtent(rect_Extent);//设置当前地图显示范围
			//使图形居中
			m_Map.CenterAt(m_CenterPointX,m_CenterPointY);
		}
		Number++;
        if(!bControlFlag)
		{
			ShowLayer();
		}
		break;
	case ZOOMOUT://定点缩小
		if(x>28000)
		{
			MessageBox("已经到最小");
			break;
		}
		
		rect=m_Map.TrackRectangle();
		rect_Extent=m_Map.GetExtent();//获得当前地图显示范围
		if(LPDISPATCH(rect)&&rect.GetHeight()!=0&&rect.GetWidth()!=0)
        {
			m_CenterPoint=rect.GetCenter();
			m_CenterPointX=m_CenterPoint.GetX();
			m_CenterPointY=m_CenterPoint.GetY();
			//求解并设置缩小系数
			X_Scale=rect_Extent.GetHeight()/rect.GetHeight();
			Y_Scale=rect_Extent.GetWidth()/rect.GetWidth();
			m_Scale=X_Scale;
			if(X_Scale<Y_Scale)
				m_Scale=Y_Scale;
			rect_Extent.ScaleRectangle(m_Scale);
		}
		else
		{
			
			m_CenterPoint=m_Map.ToMapPoint(float(X),float(Y));//将屏幕坐标转换成空间坐标
			m_CenterPointX=m_CenterPoint.GetX();
			m_CenterPointY=m_CenterPoint.GetY();
			rect_Extent=m_Map.GetExtent();
			//设置放大系数          //m_Map.GetExtent()获得当前地图显示范围
			rect_Extent.ScaleRectangle(1.111111);
		}
		m_Map.SetExtent(rect_Extent);//设置当前地图显示范围
		//使图形居中
		m_Map.CenterAt(m_CenterPointX,m_CenterPointY);
		
		Number--;
		if(!bControlFlag)
			HideLayer();
		break;
	case FULLSHOW:
		m_Map.SetExtent(m_Map.GetExtent());
		break;
	case GetDisP1toP2:
		if(m_mouseDownNum==0)
			m_startPoint=m_Map.ToMapPoint(float(X),float(Y));
		else
			m_endPoint=m_Map.ToMapPoint(float(X),float(Y));
        m_mouseDownNum++;
		break;
	case GetAttribute://获取道路属性
		GetSelectAttribute(X,Y);
		break;
	case SELECTPOINT://获得地物属性
		GetPointAttribute(strName,X,Y);
		break;
		
	}
	
	//********************************************************
	//点的地理坐标
	//----------------------------------------------------
	CMoPoint m_CurrentPoint;
	if(!m_CurrentPoint.CreateDispatch("MapObjects2.Point"))
		return;
	m_CurrentPoint=m_Map.ToMapPoint(float(X),float(Y));
	CString m_CoordinateStr,m_XCoordinateStr,m_YCoordinateStr;
	m_XCoordinateStr.Format("%f",m_CurrentPoint.GetX());
	m_YCoordinateStr.Format("%f",m_CurrentPoint.GetY());
	m_CoordinateStr="地理坐标：X:"+m_XCoordinateStr+",Y:"+m_YCoordinateStr;
	//-----------------------------------------------------------------
	CMainFrame*pFrame=(CMainFrame*)AfxGetApp()->m_pMainWnd;
	CStatusBar *pStatus=&pFrame->m_wndStatusBar;
    
	//	int x=(int)Info.CalcScale(&m_Map);
	//	str.Format("比例尺 1:%d",x);
	
	if(pStatus)
	{
		pStatus->SetPaneText(1,m_CoordinateStr);
		pStatus->SetPaneText(2,str);
	}
	//****************************************************
	
	
	
	
}
void CMapPublicView::HideLayer()
{
	int i=MAXLAYERS-1;
	int x=(int)Info.CalcScale(&m_Map);
	if(20000<x&&x<23000)
	{
		while(i>22)
		{
			if(m_mapInfo[i].bLable)//已经标注
			{
				m_mapLayer[i].SetVisible(false);
				m_mapInfo[i].bVisible=false;
				m_mapInfo[i--].bLable=false;
				
			}
			else i--;
		}
		
	}
	else if(23000<x&&x<26000)
	{
		while(i>18)
		{
			if(m_mapInfo[i].bLable)
			{
				m_mapLayer[i].SetVisible(false);
				m_mapInfo[i].bVisible=false;
				m_mapInfo[i--].bLable=false;
				
				
			}
			else i--;
		}
		
	}
	else if(26000<x&&x<28000)
	{
		while(i>12)
		{
			if(m_mapInfo[i].bLable)
			{
				m_mapLayer[i].SetVisible(false);
				m_mapInfo[i].bVisible=false;
				m_mapInfo[i--].bLable=false;
				
			}
			else i--;
		}
		
	}
	
	
	
    
}
void CMapPublicView::ShowLayer()
{
	int i=0;
	int x=(int)Info.CalcScale(&m_Map);
	if(x>25000)
	{
		while(i<14)
		{
			if(!m_mapInfo[i].bLable)//还没有标注
			{	
				m_mapLayer[i].SetVisible(true);
				m_mapInfo[i].bVisible=true;
				m_mapInfo[i].bLable=true;
				AddLabel(i++,RGB(72,72,72),9);
				
			}
			else i++;
		}
		
	}
	else if(23000<x&&x<25000)
	{
		while(i<15)
		{
			if(!m_mapInfo[i].bLable)
			{
				m_mapLayer[i].SetVisible(true);
				m_mapInfo[i].bVisible=true;
				m_mapInfo[i].bLable=true;
				AddLabel(i++,RGB(72,72,72),9);
				
			}
			else i++;
		}
		
	}
	else if(21000<x&&x<23000)
	{
		while(i<17)
		{
			if(!m_mapInfo[i].bLable)
			{
				m_mapLayer[i].SetVisible(true);
				m_mapInfo[i].bVisible=true;
				m_mapInfo[i].bLable=true;
				AddLabel(i++,RGB(72,72,72),9);
				
			}
			else i++;
		}
		
	}
	else if(19000<x&&x<21000)
	{
		while(i<20)
		{
			if(!m_mapInfo[i].bLable)
			{
				m_mapLayer[i].SetVisible(true);
				m_mapInfo[i].bVisible=true;
				m_mapInfo[i].bLable=true;
				AddLabel(i++,RGB(72,72,72),9);
				
			}
			else i++;
		}
		
		
	}
	else if(x<15000)
	{
		while(i<MAXLAYERS)
		{
			if(!m_mapInfo[i].bLable)
			{
				m_mapLayer[i].SetVisible(true);
				m_mapInfo[i].bVisible=true;
				m_mapInfo[i].bLable=true;
				AddLabel(i++,RGB(72,72,72),9);
				
			}
			else i++;
		}
	}
	
	//	str.Format("比例尺为：  %d",Info.CalcScale(&m_Map));
	//	MessageBox(str);
	
}
void CMapPublicView::OnMapFullshow() 
{
	PlayResource(IDR_WAVE2);
	m_CurrentOperation=FULLSHOW;
	m_Map.SetMousePointer(53);
}

CString CMapPublicView::GetFileTitle(const CString &path)
{
	CString strResult=GetFileName(path);
	int pos=strResult.ReverseFind('.');
	if(pos>=0)
		return strResult.Left(pos);
	return strResult;
}
CString CMapPublicView::GetFileName(const CString &path)
{
	int pos=path.ReverseFind('\\');
	if(pos>=0)
		return path.Right(path.GetLength()-pos-1);
	return path;
}
CString CMapPublicView::AddShpLayer(CMoMapLayer mapLayer,const CString &VectorFileName,COLORREF color,short symbolSize,short symbolStyle,BOOL VisibleFlag,int index)
{
	CMoLayers m_Layers;//=layers;
	CMoMapLayer m_MapLayer=mapLayer;
	
	m_Layers=m_Map.GetLayers();
	CMoDataConnection m_Connection;
	if(!m_Connection.CreateDispatch(TEXT("MapObjects2.DataConnection")))
		return "";
	m_Connection.SetDatabase(GetFileDirectory(VectorFileName));
	if(!m_Connection.Connect())
		return "";
	//*************************************
	/*	CMoGeoDatasets sets;
	sets=m_Connection.GetGeoDatasets();
	int tt=sets.GetCount();*/
	//***************************************** 
	if(!m_MapLayer.CreateDispatch(TEXT("MapObjects2.MapLayer")))
		return "";
	CString m_LayerName=GetFileTitle(VectorFileName);
	CMoGeoDataset m_GeoDataset=m_Connection.FindGeoDataset(m_LayerName);
	if(!m_GeoDataset)
		return  "";
	m_MapLayer.SetGeoDataset(m_GeoDataset);
	//设置是否显示当前图层
	
	//	m_MapLayer.SetVisible(true);
	
	//******************************************************
	CMoSymbol layerSymbol(m_MapLayer.GetSymbol());
	//求解数据的几何类型
	long m_ShapeType=m_MapLayer.GetShapeType();
	//点状目标
	if(m_ShapeType==21||m_ShapeType==24)
	{
		switch(index)
		{
		case 10://宾馆酒店
			layerSymbol.SetSymbolType(1);
            //----------------------------------------
			/*	layerSymbol.SetFont(NewFont);
			layerSymbol.SetStyle(4);
			layerSymbol.SetCharacterIndex(12);
			//	layerSymbol.SetColor(moBlue);
			//	layerSymbol.SetSize(60);*/
			//-----------------------------------------------
			layerSymbol.SetColor(color);
			layerSymbol.SetSize(7);
			break;
		case 8://水系注记
		case 11://景点
		case 12://厂矿企业
		case 13://交通运输
		case 14://其他名称
			//	case 15://三级旅游资源
		case 15://山峰注记
		case 16://商场大厦
		case 21://医疗卫生
		case 23://五级旅游资源
		case 25://一级旅游资源
			layerSymbol.SetSymbolType(2);
			layerSymbol.SetColor(color);
			layerSymbol.SetSize(8);
			break;
			
		case 17://村庄小区
		case 19://金融机构
		case 22://政府机构
		case 20://学校
			layerSymbol.SetSymbolType(1);
			layerSymbol.SetColor(color);
			layerSymbol.SetSize(8);
			break;
			/*	case 21://医疗卫生
			layerSymbol.SetSymbolType(3);
			layerSymbol.SetColor(color);
			layerSymbol.SetSize(8);
			break;
			*/
		}
	}
	//线状目标
	else if(m_ShapeType==22)
	{   
		layerSymbol.SetColor(color);
		layerSymbol.SetSize(symbolSize);
		layerSymbol.SetStyle(symbolStyle);
	}
	else//面状目标
	{
		layerSymbol.SetColor(color);
		layerSymbol.SetSize(symbolSize);
		layerSymbol.SetStyle(symbolStyle);
		
	}
	
	//*********************************************************
	m_Layers.Add(m_MapLayer);
	m_players=m_Layers;
	m_pmaplayer=m_MapLayer;
	m_mapLayer[index]=m_MapLayer;
	if(VisibleFlag)
		m_MapLayer.SetVisible(true);
	else
		m_MapLayer.SetVisible(false);
	return (m_MapLayer.GetName());
	
	///////////////////////////////////////////
	/////////////////////////////////////////////
}
CString CMapPublicView::GetFileDirectory(const CString &path)
{
	int pos=path.ReverseFind('\\');
	if(pos>=0)
		return path.Left(pos);
	return " ";
}
void CMapPublicView::AddLabel(int indexLayer,COLORREF color,int FontSize)
{
	if(m_mapInfo[indexLayer].bVisible&&m_mapInfo[indexLayer].bLable)
	{
		OnSetLabelParameter(indexLayer,color,FontSize);
	}
	
}
void CMapPublicView::OnSetLabelParameter(int index,COLORREF color,int FontSize)
{	
	CMoLayers m_Layers(m_Map.GetLayers());//=m_players;
    CMoMapLayer m_MapLayer=m_mapLayer[index];
    CMoFont font;
	//	if(index==9)
	//		font.SetName("宋体");
	//	else
	font.SetName("楷体_GB2312");
	font.SetSize(FontSize);
	font.SetItalic(true);
	CMoLabelPlacer m_LabelPlacer=m_MapLayer.GetRenderer();//(groupRenderer.GetRenderer(0));
    if(m_LabelPlacer==NULL)
		m_LabelPlacer.CreateDispatch(_T("MapObjects2.LabelPlacer"));
	//	if(index==15||index==21||index==23||index==25)
	//		m_LabelPlacer.SetField("Resname");
	//	else
	m_LabelPlacer.SetField("Name");
	if(m_LabelPlacer.GetField()=="")
		m_LabelPlacer.SetDrawBackground(false);
	m_LabelPlacer.SetAllowDuplicates(true);
	m_LabelPlacer.SetPlaceOn(false);
	m_LabelPlacer.SetPlaceAbove(true);
	m_LabelPlacer.SetPlaceBelow(false);
	
    CMoTextSymbol m_TextSymbol;
    m_TextSymbol=m_LabelPlacer.GetDefaultSymbol();
	m_TextSymbol.SetFont(font);
	m_TextSymbol.SetColor(color);
	///////////////////////////////////////////////
	/*	CMoSymbol Symbol(m_MapLayer.GetSymbol());
	//Symbol.SetStyle(moLightGrayFill);
	//Symbol.SetColor(moRed);
    m_LabelPlacer.SetBackgroundRenderer(Symbol);
	*/
	////////////////////////////////////////////////
	/*	m_LabelPlacer.SetMaskLabels(true);
	m_LabelPlacer.SetMaskColor(m_Map.GetBackColor());
	*/
	m_MapLayer.SetRenderer(m_LabelPlacer);
	m_Map.Refresh();
	
}

void CMapPublicView::OnCommunity() //村庄小区
{
	PlayResource(IDR_WAVE3);
	//	OnInitialUpdate();
    flashflag=false;//使公交站点层不显示
	m_Map.Refresh();
	int i;
	bControlFlag=true;
	for(i=6;i<MAXLAYERS;i++)
	{
		m_mapLayer[i].SetVisible(false);
		m_mapInfo[i].bVisible=false;
		m_mapInfo[i].bLable=false;
	}
	m_mapLayer[9].SetVisible(true);
	m_mapInfo[9].bVisible=true;
	m_mapInfo[9].bLable=true;
    AddLabel(9,RGB(0,0,0),10);
	m_mapLayer[17].SetVisible(true);
	m_mapInfo[17].bVisible=true;
	m_mapInfo[17].bLable=true;
    AddLabel(17,RGB(28,20,255),9);
	pointflag=true;//使地物选择按纽可以使用
	strName="村庄小区";
	
	
	
	
}

void CMapPublicView::OnBank() //金融机构
{
	PlayResource(IDR_WAVE3);
	flashflag=false;//使公交站点层不显示
	m_Map.Refresh();
	int i;
	bControlFlag=true;
	for(i=6;i<MAXLAYERS;i++)
	{
		m_mapLayer[i].SetVisible(false);
		m_mapInfo[i].bVisible=false;
		m_mapInfo[i].bLable=false;
	}
	m_mapLayer[9].SetVisible(true);
	m_mapInfo[9].bVisible=true;
	m_mapInfo[9].bLable=true;
    AddLabel(9,RGB(0,0,0),10);
	m_mapLayer[19].SetVisible(true);
	m_mapInfo[19].bVisible=true;
	m_mapInfo[19].bLable=true;
    AddLabel(19,RGB(28,20,255),9);
	pointflag=true;//使地物选择按纽可以使用
	strName="金融机构";
	
}

void CMapPublicView::OnEducation() //学校
{
	PlayResource(IDR_WAVE3);
	flashflag=false;//使公交站点层不显示
	m_Map.Refresh();
	int i;
	bControlFlag=true;
	for(i=6;i<MAXLAYERS;i++)
	{
		m_mapLayer[i].SetVisible(false);
		m_mapInfo[i].bVisible=false;
		m_mapInfo[i].bLable=false;
	}
	m_mapLayer[9].SetVisible(true);
	m_mapInfo[9].bVisible=true;
	m_mapInfo[9].bLable=true;
    AddLabel(9,RGB(0,0,0),10);
	/*   m_mapLayer[22].SetVisible(true);
	m_mapInfo[22].bVisible=true;
	m_mapInfo[22].bLable=true;
	AddLabel(22,RGB(128,120,255),9);
	*/
	m_mapLayer[20].SetVisible(true);
	m_mapInfo[20].bVisible=true;
	m_mapInfo[20].bLable=true;
	AddLabel(20,RGB(28,20,255),9);
	pointflag=true;//使地物选择按纽可以使用
	strName="学校";
}

void CMapPublicView::OnRestaurant() //宾馆酒店
{
	PlayResource(IDR_WAVE3);
	flashflag=false;//使公交站点层不显示
	m_Map.Refresh();
	int i;
	bControlFlag=true;
	for(i=6;i<MAXLAYERS;i++)
	{
		m_mapLayer[i].SetVisible(false);
		m_mapInfo[i].bVisible=false;
		m_mapInfo[i].bLable=false;
	}
	m_mapLayer[9].SetVisible(true);
	m_mapInfo[9].bVisible=true;
	m_mapInfo[9].bLable=true;
    AddLabel(9,RGB(0,0,0),10);
	m_mapLayer[10].SetVisible(true);
	m_mapInfo[10].bVisible=true;
	m_mapInfo[10].bLable=true;
	AddLabel(10,RGB(28,20,255),9);
	pointflag=true;//使地物选择按纽可以使用
	strName="宾馆酒店";
}

void CMapPublicView::OnShop() //商场大厦
{
	PlayResource(IDR_WAVE3);
	flashflag=false;//使公交站点层不显示
	m_Map.Refresh();
	int i;
	bControlFlag=true;
	for(i=6;i<MAXLAYERS;i++)
	{
		m_mapLayer[i].SetVisible(false);
		m_mapInfo[i].bVisible=false;
		m_mapInfo[i].bLable=false;
	}
	m_mapLayer[9].SetVisible(true);
	m_mapInfo[9].bVisible=true;
	m_mapInfo[9].bLable=true;
    AddLabel(9,RGB(0,0,0),10);
    m_mapLayer[16].SetVisible(true);
	m_mapInfo[16].bVisible=true;
	m_mapInfo[16].bLable=true;
    AddLabel(16,RGB(28,20,255),9);
	pointflag=true;//使地物选择按纽可以使用
	strName="商场大厦";
	
}

void CMapPublicView::OnTour() //旅游景点
{
	PlayResource(IDR_WAVE3);
	flashflag=false;//使公交站点层不显示
	m_Map.Refresh();
	int i;
	bControlFlag=true;
	for(i=6;i<MAXLAYERS;i++)
	{
		m_mapLayer[i].SetVisible(false);
		m_mapInfo[i].bVisible=false;
		m_mapInfo[i].bLable=false;
	}
	m_mapLayer[9].SetVisible(true);
	m_mapInfo[9].bVisible=true;
	m_mapInfo[9].bLable=true;
    AddLabel(9,RGB(0,0,0),10);
	m_mapLayer[11].SetVisible(true);
	m_mapInfo[11].bVisible=true;
	m_mapInfo[11].bLable=true;
	AddLabel(11,RGB(28,20,255),9);
	/*	m_mapLayer[15].SetVisible(true);
	m_mapInfo[15].bVisible=true;
	m_mapInfo[15].bLable=true;
	AddLabel(15,RGB(128,120,255),9);
	m_mapLayer[21].SetVisible(true);
	m_mapInfo[21].bVisible=true;
	m_mapInfo[21].bLable=true;
	AddLabel(21,RGB(128,120,255),9);
	m_mapLayer[23].SetVisible(true);
	m_mapInfo[23].bVisible=true;
	m_mapInfo[23].bLable=true;
	AddLabel(23,RGB(128,120,255),9);
	m_mapLayer[25].SetVisible(true);
	m_mapInfo[25].bVisible=true;
	m_mapInfo[25].bLable=true;
	AddLabel(25,RGB(128,120,255),9);
	*/	
	pointflag=true;//使地物选择按纽可以使用
	strName="景点";
}

void CMapPublicView::OnHospital() //医疗机构
{
	PlayResource(IDR_WAVE3);
	flashflag=false;//使公交站点层不显示
	m_Map.Refresh();
    int i;
	bControlFlag=true;
	for(i=6;i<MAXLAYERS;i++)
	{
		m_mapLayer[i].SetVisible(false);
		m_mapInfo[i].bVisible=false;
		m_mapInfo[i].bLable=false;
	}
	m_mapLayer[9].SetVisible(true);
	m_mapInfo[9].bVisible=true;
	m_mapInfo[9].bLable=true;
    AddLabel(9,RGB(0,0,0),10);
    m_mapLayer[21].SetVisible(true);
	m_mapInfo[21].bVisible=true;
	m_mapInfo[21].bLable=true;
	AddLabel(21,RGB(28,20,255),9);
	pointflag=true;//使地物选择按纽可以使用
	strName="医疗卫生";
}

void CMapPublicView::OnTraffic() //交通运输
{
	PlayResource(IDR_WAVE3);
	flashflag=false;//使公交站点层不显示
	m_Map.Refresh();
	int i;
	bControlFlag=true;
	for(i=6;i<MAXLAYERS;i++)
	{
		m_mapLayer[i].SetVisible(false);
		m_mapInfo[i].bVisible=false;
		m_mapInfo[i].bLable=false;
	}
	m_mapLayer[9].SetVisible(true);
	m_mapInfo[9].bVisible=true;
	m_mapInfo[9].bLable=true;
    AddLabel(9,RGB(0,0,0),10);
    m_mapLayer[13].SetVisible(true);
	m_mapInfo[13].bVisible=true;
	m_mapInfo[13].bLable=true;
	AddLabel(13,RGB(28,20,255),9);
	pointflag=true;//使地物选择按纽可以使用
	strName="交通运输";
}

void CMapPublicView::OnEnterprise() //事业单位
{
	PlayResource(IDR_WAVE3);
	flashflag=false;//使公交站点层不显示
	m_Map.Refresh();
	int i;
	bControlFlag=true;
	for(i=6;i<MAXLAYERS;i++)
	{
		m_mapLayer[i].SetVisible(false);
		m_mapInfo[i].bVisible=false;
		m_mapInfo[i].bLable=false;
	}
	m_mapLayer[9].SetVisible(true);
	m_mapInfo[9].bVisible=true;
	m_mapInfo[9].bLable=true;
    AddLabel(9,RGB(0,0,0),10);
	m_mapLayer[18].SetVisible(true);
	m_mapInfo[18].bVisible=true;
	m_mapInfo[18].bLable=true;
	AddLabel(18,RGB(28,20,255),9);
	pointflag=true;//使地物选择按纽可以使用
	strName="事业单位";
}

void CMapPublicView::OnGoverment() //政府机构
{
	PlayResource(IDR_WAVE3);
	flashflag=false;//使公交站点层不显示
	m_Map.Refresh();
	int i;
	bControlFlag=true;
	for(i=6;i<MAXLAYERS;i++)
	{
		m_mapLayer[i].SetVisible(false);
		m_mapInfo[i].bVisible=false;
		m_mapInfo[i].bLable=false;
	}
	m_mapLayer[9].SetVisible(true);
	m_mapInfo[9].bVisible=true;
	m_mapInfo[9].bLable=true;
    AddLabel(9,RGB(0,0,0),10);
	m_mapLayer[22].SetVisible(true);
	m_mapInfo[22].bVisible=true;
	m_mapInfo[22].bLable=true;
	AddLabel(22,RGB(28,20,255),9);
	pointflag=true;//使地物选择按纽可以使用	
	strName="政府机构";
}

void CMapPublicView::OnAll() 
{
	PlayResource(IDR_WAVE3);
	flashflag=false;//使公交站点层不显示
	m_Map.Refresh();
	int i;
	bControlFlag=true;
	for(i=0;i<MAXLAYERS;i++)
	{
		m_mapLayer[i].SetVisible(true);
		m_mapInfo[i].bVisible=true;
		m_mapInfo[i].bLable=true;
        AddLabel(i,RGB(28,20,255),10);
		
	}
	pointflag=false;//使地物选择按纽不可以使用
    strName="";
}
//*****************************************
//保存图片
void CMapPublicView::OnSavebmp() 
{
	PlayResource(IDR_WAVE2);
	m_Map.SetMousePointer(moArrow);
	CString szFilters = "位图(*.bmp)|*.bmp|增强的图元格式文件(*.emf)|*.emf|";
	szFilters += "Jpeg文件(*.jpg)|*.jpg;*.jpeg||";
	CFileDialog fileDlg(FALSE, "map", "*.bmp", OFN_FILEMUSTEXIST| OFN_HIDEREADONLY,
		szFilters, this);
	if( fileDlg.DoModal ()== IDOK)
	{
		CString ext = fileDlg.GetFileExt();
		if(ext == "bmp")
		{
			m_Map.ExportMap(moExportBMP, fileDlg.GetPathName(), 1);
		}
		else if(ext == "emf")
		{
			m_Map.ExportMap(moExportEMF, fileDlg.GetPathName(), 1);
		}
		else
		{
			m_Map.ExportMapToJpeg(fileDlg.GetPathName(), 100, TRUE, 1, 
				moLineSymbolsNotScaled);
		}
	}	
}
//****************************************************
//测量距离
//--------------------------------------------------
void CMapPublicView::OnMeasure() 
{
	PlayResource(IDR_WAVE2);
    m_Map.SetMousePointer(moArrow);
   	m_CurrentOperation=GetDisP1toP2;
	if(!m_startPoint.CreateDispatch("MapObjects2.Point"))
		return ;
	if(!m_endPoint.CreateDispatch("MapObjects2.Point"))
		return ;
	m_mouseDownNum=0;
}
//------------------------------------------------------
void CMapPublicView::OnDblClickMap1() //
{
	
    if(m_CurrentOperation==GetDisP1toP2)	
	{
		double distance;
		CString str="";
		MPoint pt[2];
		pt[0].x=m_startPoint.GetX();
		pt[0].y=m_startPoint.GetY();
		pt[1].x=m_endPoint.GetX();
		pt[1].y=m_startPoint.GetY();
		distance=(int)Info.CalcLenght(pt,2);
		str.Format("%.2f",distance);////////////////////////
		str="两点间距离约为："+str+"米";
		CMainFrame *pFrame=(CMainFrame *)AfxGetMainWnd();
		CAttribute *pView=(CAttribute *)(pFrame->m_wndSplitter2.GetPane(1,0));
        pView->m_strAttribute=str;
		pView->UpdateData(false);
		m_mouseDownNum=0;
		m_startPoint.ReleaseDispatch();
		m_endPoint.ReleaseDispatch();
	}
}
//*************************************************************
//地名查找
void CMapPublicView::OnFind() 
{
	PlayResource(IDR_WAVE2);
	m_Map.SetMousePointer(moArrow);
	CString strFind;
	CMainFrame *pFrame=(CMainFrame *)AfxGetMainWnd();
	pFrame->m_wndToolBar.m_EditBox.UpdateData(false);
	pFrame->m_wndToolBar.m_EditBox.GetWindowText(strFind);
	if(strFind!="")
		FindArea(strFind);
	else
		MessageBox("请输入查询地名！");
    
	
}
void CMapPublicView::FindArea(CString searchText)
{
	int i=0;
	CString str;
	CString expression;//查找条件表达式
	CMoRecordset recs;// 记录集对象
	bool flag=false;
	float X,Y;
	while(i<MAXLAYERS)
	{
		if(i==15||i==21||i==23||i==25)
			expression.Format("(Resname Like '%s')",searchText);
        else
			expression.Format("(Name Like '%s')",searchText);
		if(flag)
			break;
		recs=m_mapLayer[i].SearchExpression(expression);//返回满足条件的所有记录
		if(recs)
		{			
			recs.MoveFirst();
			while(!recs.GetEof())
			{
				CMoFields fields(recs.GetFields());
				CMoField shapeField(fields.Item(COleVariant("Shape")));
				if(m_mapLayer[i].GetShapeType()==21)
				{
					CMoPoint *pPoint=new CMoPoint();
					pPoint->AttachDispatch(shapeField.Get_Value().pdispVal);
					m_Map.CenterAt(pPoint->GetX(),pPoint->GetY());
					m_Map.FromMapPoint(pPoint->m_lpDispatch,&X,&Y);
				     createled(X,Y);
					 //KillTimer(30);
					//	m_Map.FlashShape(pPoint->m_lpDispatch,10);
					require_attribute(searchText);//////////////
					flag=true;
					break;
				}
				else if(m_mapLayer[i].GetShapeType()==22)
				{
					CMoLine *pLine=new CMoLine();
					pLine->AttachDispatch(shapeField.Get_Value().pdispVal);
					m_Map.FlashShape(pLine->m_lpDispatch,8);
					flag=true;
					require_attribute(searchText);//////////////
					break;
					pLine->ReleaseDispatch();
				}
				else 
					recs.MoveNext();
			}
		}
		i++;
		
	}
	if(!flag)
	{
    CMainFrame *pFrame=(CMainFrame *)AfxGetMainWnd();
	CAttribute *pView=(CAttribute *)(pFrame->m_wndSplitter2.GetPane(1,0));
	pView->m_strAttribute="";
	pView->UpdateData(false);
		MessageBox("输入地名不存在！");
	}	
}

void CMapPublicView::createled(int X,int Y)
{
	
	m_ledstatic.Create(_T(""),WS_CHILD|WS_VISIBLE,
       CRect(X-5,Y-5,X,Y),this);
	m_ledstatic.ShowWindow(SW_SHOW);
//	SetTimer(300,500,NULL);
	m_ledstatic.SetLed(CLed::LED_COLOR_RED,CLed::LED_ON,CLed::LED_ROUND);
	Sleep(250);
	m_ledstatic.SetLed(CLed::LED_COLOR_RED,CLed::LED_OFF,CLed::LED_ROUND);
    Sleep(250);
    m_ledstatic.SetLed(CLed::LED_COLOR_RED,CLed::LED_ON,CLed::LED_ROUND);
	Sleep(250);
    m_ledstatic.SetLed(CLed::LED_COLOR_RED,CLed::LED_OFF,CLed::LED_ROUND);
	Sleep(250);
    m_ledstatic.SetLed(CLed::LED_COLOR_RED,CLed::LED_ON,CLed::LED_ROUND);
	Sleep(250);
    m_ledstatic.SetLed(CLed::LED_COLOR_RED,CLed::LED_OFF,CLed::LED_ROUND);
	Sleep(250);
    m_ledstatic.SetLed(CLed::LED_COLOR_RED,CLed::LED_ON,CLed::LED_ROUND);
//	KillTimer(300);
    m_ledstatic.DestroyWindow();

}
void CMapPublicView::OnDelStation() 
{
	DelSingleStation m_del;
	m_del.DoModal();
	
}

void CMapPublicView::OnAddRoadway() 
{
	AddOneRoadway m_addoneroadway;
	m_addoneroadway.DoModal();
   	
}

void CMapPublicView::OnDelRoadway() 
{
	DelRoadway m_del;
	m_del.DoModal();
	
}

void CMapPublicView::OnChangeStation() 
{
	ChangeStation m_change;
	m_change.DoModal();
   	
}

void CMapPublicView::OnSelect() 
{
	PlayResource(IDR_WAVE2);
	m_CurrentOperation=GetAttribute;
	m_Map.SetMousePointer(moArrow);
}

void CMapPublicView::GetSelectAttribute(long X,long Y)
{
	
	const double tolerance=m_Map.ToMapDistance((float)10);
	//控件元素中的直线距离转化为地图元素中的距离.
    CMoLayers layers(m_Map.GetLayers());
	CMoMapLayer ways(layers.Item(COleVariant(TEXT("街道线"))));
	//得到街道线图层
	CMoPoint pt;
	if(!pt.CreateDispatch("MapObjects2.Point"))
		return;
	pt=m_Map.ToMapPoint((float)X,(float)Y);
	//将控件空间中的点转换为地图坐标
    m_SelectRecSet=ways.SearchByDistance(pt,tolerance,TEXT(""));
	//CMoRecordset(记录集对象)用于得到一个地图要素层的所有坐标记录和属性记录
    if(m_SelectRecSet.GetEof())
		::MessageBeep(MB_ICONQUESTION);
	else
	{
		m_SelectRecSet.MoveFirst();
		CMoFields ShapeFields(m_SelectRecSet.GetFields());
		// CMoFields(属性集对象)用于得到一张属性表中每个属性项的具体信息
		CMoField ShapeField(ShapeFields.Item(COleVariant("Shape")));
		//CMoField(属性集对象)用于得到一张属性表中某个指定的属性项的具体信息
		CMoLine *pLine=new CMoLine();
		pLine->AttachDispatch(ShapeField.GetValue().pdispVal);
		//	 m_Map.FlashShape(pLine->m_lpDispatch,8);
		double Length;
		Length=pLine->GetLength()*100000;
		//得到道路的长度
		CString  strLength;
		strLength.Format("%.2f",Length);
		//  CMoTableDesc tableDesc(m_SelectRecSet.GetTableDesc());
		//CMoTableDesc(属性表描述对象)用于得到一张属性表中每个属性项的具体信息
		//	 CString name=tableDesc.GetFieldName(1);//得到表中第二项表属性名称
		ShapeField=ShapeFields.Item(COleVariant("NAME"));
		CString value=ShapeField.GetValueAsString();
		CString m_strname=value;//保存图片名称
		CString strResult="你所选道路名称："+value+"\r\n道路长度："+strLength+"米";
		showflag=true;
		CMainFrame *pFrame=(CMainFrame *)AfxGetMainWnd();
		CAttribute *pView=(CAttribute *)(pFrame->m_wndSplitter2.GetPane(1,0));
        pView->m_strAttribute=strResult;
		pView->UpdateData(false);
		//-------------------------------------------------------
		if(m_strname!="")
		{
			CAttributeSet m_attributeSet;
			CMapPublicApp *app=(CMapPublicApp *)AfxGetApp();
			if(!m_attributeSet.IsOpen())
				m_attributeSet.Open();
			m_attributeSet.MoveFirst();
			while(!m_attributeSet.IsEOF())
			{
				if(m_attributeSet.m_NAME==m_strname&&m_attributeSet.m_ISPICTURE==1)
				{MessageBox(m_attributeSet.m_NAME);
				app->pitcure_name=m_attributeSet.m_PICTURE_NAME;
				CHawkSightView *p_View=(CHawkSightView *)(pFrame->m_wndSplitter2.GetPane(2,0));
                // p_View->m_sightdlg.UpdateData(false);
				p_View->m_sightdlg.OnPaint();
				break;
				}
				else
					m_attributeSet.MoveNext();
			}
			m_attributeSet.Close();
			m_strname="";
		}
		//------------------------------------------------- 
		m_Map.Refresh();
	}
}


void CMapPublicView::OnSelectAttribute() 
{
	CAddAttributeDlg m_attributedlg;
    m_attributedlg.DoModal();
   	
}

void CMapPublicView::OnAfterLayerDrawMap1(short index, BOOL canceled, long hDC) 
{
	CMoSymbol sym;
	sym.CreateDispatch("MapObjects2.Symbol");
	sym.SetColor(moRed);
	sym.SetSize(0);
	CMoFields ShapeFields;
	// CMoFields(属性集对象)用于得到一张属性表中每个属性项的具体信息
	CMoField ShapeField;
	//CMoField(属性集对象)用于得到一张属性表中某个指定的属性项的具体信息
	//添加注记字体
	/*	CMoFont font;
	font.SetFont("楷体_GB2312");
    //设置文本符号对象
	CMoTextSymbol m_TextSymbol;
	if(m_TextSymbol.CreateDispatch("MapObjects2.TextSymbol"))
	return;
	m_TextSymbol.SetFont(font);
	m_TextSymbol.SetColor(moBlue);
	*/
	////////////////////////////////
	
	CMoLabelRenderer lr;
	lr.CreateDispatch("MapObjects2.LabelRenderer");
	//	lr.SetField(labelField);
	lr.SetDrawBackground(FALSE);
	
	CMoTextSymbol m_TextSymbol(lr.GetSymbol(0));
	CFontHolder font(0);
	const FONTDESC fd = { sizeof(FONTDESC), OLESTR("Arial"), FONTSIZE(10), FW_NORMAL, ANSI_CHARSET, FALSE, FALSE, FALSE };
	//font.InitializeFont(&fd, sym.GetFont());
	font.InitializeFont(&fd);
	m_TextSymbol.SetFont(font.GetFontDispatch());
	m_TextSymbol.SetColor(moRed);
	m_TextSymbol.SetVerticalAlignment(moAlignBottom);
	m_TextSymbol.SetHorizontalAlignment(moAlignLeft);
	
	//////////////////////////////////////
	
	if(showflag)//画出选择的线
	{	
		ShapeFields=m_SelectRecSet.GetFields();
        ShapeField=ShapeFields.Item(COleVariant("Shape"));
		CMoLine line;
		line.AttachDispatch(ShapeField.GetValue().pdispVal);
		m_Map.DrawShape(line,sym);
	}
	if(showpointflag)//画出选择的点
	{
		//	sym.SetSize(10);
		ShapeFields=m_SelectRecSet.GetFields();
        ShapeField=ShapeFields.Item(COleVariant("Shape"));
		CMoPoint point;
		point.AttachDispatch(ShapeField.GetValue().pdispVal);
		m_Map.DrawShape(point,sym);
	}
	if(flashflag)//画出公交站点
	{
		for(int i=0;i<1000;i++)
		{
			m_Map.DrawShape(m_Struct[i].station_pt,sym);
			m_Map.DrawText(m_Struct[i].strName,m_Struct[i].station_pt,m_TextSymbol);
		}
		flashflag=false;
	}
}

void CMapPublicView::OnSelectPoint() 
{
	PlayResource(IDR_WAVE2);
	m_CurrentOperation=SELECTPOINT;
    m_Map.SetMousePointer(moArrow);
}

void CMapPublicView::GetPointAttribute(CString strname,long X,long Y)
{
	CMoPoint pt;
	if(!pt.CreateDispatch("MapObjects2.Point"))
		return;
	
	pt=m_Map.ToMapPoint((float)X,(float)Y);
	CMoRectangle select_Rect;
	   if(!select_Rect.CreateDispatch("MapObjects2.Rectangle"))
		   return;
	   double x=pt.GetX();
	   double y=pt.GetY();
	   CMoRectangle rect_Extent(m_Map.GetExtent());
	   //求解放大比例系数
	   double X_Scale;
	   double Y_Scale;
	   X_Scale=rect_Extent.GetHeight()/m_Map.GetFullExtent().GetHeight();
	   Y_Scale=rect_Extent.GetWidth()/m_Map.GetFullExtent().GetWidth();
	   double m_Scale=X_Scale;
	   if(X_Scale>Y_Scale)
		   m_Scale=Y_Scale;
	   //设置捕捉范围
	   
	   select_Rect.SetBottom(y-0.01*m_Scale);
	   select_Rect.SetTop(y+0.01*m_Scale);
	   select_Rect.SetLeft(x-0.01*m_Scale);
	   select_Rect.SetRight(x+0.01*m_Scale);
	   //捕捉并得到目标
	   /*	   
	   CString str;
	   int nlength;
	   int nPos=0;
	   while(nPos>-1)
	   {
	   strname.ReleaseBuffer();
	   nlength=strname.GetLength();
	   nPos=strname.ReverseFind('\,');
	   str=strname.Mid(nPos+1,nlength);
	   strname=strname.Left(nPos);
	   MessageBox(str);
	   */
	   CMoLayers layers(m_Map.GetLayers());
	   CMoMapLayer selectedMapLayer(layers.Item(COleVariant(TEXT(strname))));
	   //CMoRecordset
	   m_SelectRecSet=selectedMapLayer.SearchShape(select_Rect,6,"");
	   CMoTableDesc tableDesc(m_SelectRecSet.GetTableDesc());
	   CMoFields ShapeFields(m_SelectRecSet.GetFields());
	   /*	   if(str=="一级旅游资源"||str=="五级旅游资源"||str=="二级旅游资源"||str=="三级旅游资源")
	   {
	   ShapeField=ShapeFields.Item(COleVariant("RESNAME"));
	   MessageBox("4545");
	   }
	   else
	   */
	   CMoField ShapeField(ShapeFields.Item(COleVariant("NAME")));
	   CString value=ShapeField.GetValueAsString();//若为空则return
	    showpointflag=true;
       
	   //  CString m_strname=value;//保存图片名称
       require_attribute(value);
}

void CMapPublicView::require_attribute(CString string)//显示对象的所有属性，包括图片
{
	
	CString strtemp=string;
	CMainFrame *pFrame=(CMainFrame *)AfxGetMainWnd();
	CAttribute *pView=(CAttribute *)(pFrame->m_wndSplitter2.GetPane(1,0));
	string="你所选地名为："+string;
	  	CAttributeSet m_attribute_set;
		if(!m_attribute_set.IsOpen())
			m_attribute_set.Open();
		while(!m_attribute_set.IsEOF())
		{
			if(m_attribute_set.m_NAME==strtemp)
			{
				string=string+"\r\n"+m_attribute_set.m_ATTRIBUTE;
				//  str=m_attribute_set.m_ATTRIBUTE;
				break;
			}
			else
				m_attribute_set.MoveNext();
		}
		m_attribute_set.Close();
		pView->m_strAttribute=string;
		pView->UpdateData(false);
		//对象显示图片
		CAttributeSet m_attributeSet;
		CMapPublicApp *app=(CMapPublicApp *)AfxGetApp();
		if(!m_attributeSet.IsOpen())
		m_attributeSet.Open();
		m_attributeSet.MoveFirst();
		
		while(!m_attributeSet.IsEOF())
		{
		if(m_attributeSet.m_NAME==strtemp&&m_attributeSet.m_ISPICTURE==1)
		{
		app->pitcure_name=m_attributeSet.m_PICTURE_NAME;
		CHawkSightView *p_View=(CHawkSightView *)(pFrame->m_wndSplitter2.GetPane(2,0));
		p_View->m_sightdlg.showpicture();
		break;
		}
		else
		m_attributeSet.MoveNext();
		}
		m_attributeSet.Close();
		m_Map.Refresh();
		
}

void CMapPublicView::OnFresh() 
{  
	PlayResource(IDR_WAVE2);
	m_Map.SetMousePointer(moArrow);
	showflag=false;
	showpointflag=false;
	m_Map.Refresh();
}

void CMapPublicView::OnUpdateSelectPoint(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(pointflag);
	
}

void CMapPublicView::OnUpdateDelStation(CCmdUI* pCmdUI) 
{
	CMapPublicApp *app=(CMapPublicApp *)AfxGetApp();
   	pCmdUI->Enable(app->bEnableMenu);
}

void CMapPublicView::OnUpdateChangeStation(CCmdUI* pCmdUI) 
{
   	CMapPublicApp *app=(CMapPublicApp *)AfxGetApp();
   	pCmdUI->Enable(app->bEnableMenu);
}

void CMapPublicView::OnUpdateAddRoadway(CCmdUI* pCmdUI) 
{
   	CMapPublicApp *app=(CMapPublicApp *)AfxGetApp();
   	pCmdUI->Enable(app->bEnableMenu);
}

void CMapPublicView::OnUpdateDelRoadway(CCmdUI* pCmdUI) 
{
   	CMapPublicApp *app=(CMapPublicApp *)AfxGetApp();
   	pCmdUI->Enable(app->bEnableMenu);
}

void CMapPublicView::OnUpdateLog(CCmdUI* pCmdUI) 
{
   	CMapPublicApp *app=(CMapPublicApp *)AfxGetApp();
   	pCmdUI->Enable(app->bEnableMenu);
}

void CMapPublicView::OnUpdateSelectAttribute(CCmdUI* pCmdUI) 
{
   	CMapPublicApp *app=(CMapPublicApp *)AfxGetApp();
   	pCmdUI->Enable(app->bEnableMenu);
}

void CMapPublicView::OnUserLogin() 
{
   	CLoginDlg m_dlg;
	m_dlg.DoModal();
}

void CMapPublicView::OnUpdateUserLogin(CCmdUI* pCmdUI) 
{
	CMapPublicApp *app=(CMapPublicApp *)AfxGetApp();
	if(app->bEnableMenu)
	{
		pCmdUI->SetCheck(1);
        pCmdUI->Enable(false);
	}
	else
	{
		pCmdUI->SetCheck(0);
        pCmdUI->Enable(true);
	}
	
}

void CMapPublicView::OnQuit() 
{
	CMapPublicApp *app=(CMapPublicApp *)AfxGetApp();
	CAction_Time_Set *m_ActionSet;
	CDatabase *db;
	db=new CDatabase;
	m_ActionSet=new CAction_Time_Set(db);
	CString strSql;
	CTime time=CTime::GetCurrentTime();
	CString strtime=time.Format("%Y-%m-%d %H:%M:%S");
	m_ActionSet->Open();
	CString	straction="退出系统";
	strSql="insert into Action_Log(USER_ID,ACTION,COME_LEAVE_TIME) values('" +app->m_User_ID+"','"+straction+"','"+strtime+"')";
	db->ExecuteSQL(strSql);
	m_ActionSet->Requery();
	m_ActionSet->Close();
	
	app->bEnableMenu=false;
}

void CMapPublicView::OnUpdateQuit(CCmdUI* pCmdUI) 
{
	CMapPublicApp *app=(CMapPublicApp *)AfxGetApp();
   	if(!app->bEnableMenu)
	{
		pCmdUI->SetCheck(1);
        pCmdUI->Enable(false);
	}
	else
	{
		pCmdUI->SetCheck(0);
        pCmdUI->Enable(true);
	}
}

void CMapPublicView::OnPublicBus() //加载公交站点
{
	PlayResource(IDR_WAVE2);
	//采用多线程加载进度条
	if(!(p_thread=(CMyNewThread *)AfxBeginThread(RUNTIME_CLASS(CMyNewThread),
		THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED)))
	{
		MessageBox("创建线程失败");
		return;
	}
	VERIFY(p_thread->SetThreadPriority(THREAD_PRIORITY_HIGHEST)); //设置优先级
	p_thread->ResumeThread();
	
	//加载背景音乐线程
    if(!(p_music=(CMusicThread *)AfxBeginThread(RUNTIME_CLASS(CMusicThread),
		THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED)))
	{
		MessageBox("创建线程失败");
		return;
	}
	VERIFY(p_music->SetThreadPriority(THREAD_PRIORITY_HIGHEST)); //设置优先级
	p_music->ResumeThread();
	
	
	
	bControlFlag=true;
	for(int i=6;i<MAXLAYERS;i++)
	{
		m_mapLayer[i].SetVisible(false);
		m_mapInfo[i].bVisible=false;
		m_mapInfo[i].bLable=false;
	}
	m_mapLayer[9].SetVisible(true);
	m_mapInfo[9].bVisible=true;
	m_mapInfo[9].bLable=true;
    AddLabel(9,RGB(0,0,0),10);
	
	//	m_Map.SetMousePointer(moHourglass);
	if(!CreateNewLayer())
	{
		MessageBox("创建失败");
		return;
	}
	
}

bool CMapPublicView::CreateNewLayer()
{
	
	CMoLayers layers;
	CMoMapLayer selectedMapLayer;
	CMoRecordset m_RecSet;
	CMoTableDesc tableDesc;
    CSpeciesSet m_speciesSet;
    int nPos;
	if(!m_speciesSet.IsOpen())
		m_speciesSet.Open();
	m_speciesSet.MoveFirst();
    while(!m_speciesSet.IsEOF())
	{
		if(m_speciesSet.m_index<10||m_speciesSet.m_index==10||
			m_speciesSet.m_index==18||m_speciesSet.m_index==22||
			m_speciesSet.m_index==19||m_speciesSet.m_index==13||
			m_speciesSet.m_index==14||m_speciesSet.m_index==15||
			m_speciesSet.m_index==12)
		{
			m_speciesSet.MoveNext();
			continue;
		}
		layers=m_Map.GetLayers();
        m_speciesSet.m_ShpName.ReleaseBuffer();//将图层名解析出来
        nPos=m_speciesSet.m_ShpName.ReverseFind('\.');
        m_speciesSet.m_ShpName=m_speciesSet.m_ShpName.Left(nPos);
		selectedMapLayer=layers.Item(COleVariant(TEXT(m_speciesSet.m_ShpName)));
        m_RecSet=selectedMapLayer.GetRecords();
		m_Map.Refresh();//一个图层刷新一次
		CreateTable(m_RecSet);
		m_speciesSet.MoveNext();
		
	}
	m_speciesSet.Close();
	p_music->ExitInstance();
	p_thread->ExitInstance();
	
	return 1;
	
}
bool CMapPublicView::CreateTable(CMoRecordset m_RecSet)
{	
	
	CMoFields ShapeFields;
	CMoField ShapeField;
    CString value;
	m_RecSet.MoveFirst();
	while(!m_RecSet.GetEof())
	{
		ShapeFields=m_RecSet.GetFields();
		ShapeField=ShapeFields.Item(COleVariant("NAME"));
		value=ShapeField.GetValueAsString();//若为空则return
		Draw_TEXT(ShapeFields,value);
		m_RecSet.MoveNext();
	}
    
    return 1;
}
bool CMapPublicView::Draw_TEXT(CMoFields ShapeFields,CString strName)
{
	
	CMap_Station_Set m_Map_Set;
    CMoField ShapeField;
    static int index;//将得到的点坐标加入数组
	//CStationSet m_stationSet;
	if(!m_Map_Set.IsOpen())
		m_Map_Set.Open();
	m_Map_Set.MoveFirst();
	while(!m_Map_Set.IsEOF())
	{
		if(m_Map_Set.m_NAME!=strName)
		{
			m_Map_Set.MoveNext();
			continue;
		}
		else
		{
			flashflag=true;
            ShapeField=ShapeFields.Item(COleVariant("Shape"));
			CMoPoint point;
			point.AttachDispatch(ShapeField.GetValue().pdispVal);
			m_Struct[index].station_pt=point;
			m_Struct[index++].strName=strName;
            m_Map_Set.MoveNext();
		}
	}
	m_Map_Set.Close();
	
	return 1;
}

void CMapPublicView::OnHelp() 
{
	PlayResource(IDR_WAVE2);
	m_Map.SetMousePointer(moArrow);
	CString Path;//保存数据库文件路径名
	GetModuleFileName(NULL,sPath.GetBufferSetLength (MAX_PATH+1),MAX_PATH);//为sPath分配存储空间
	Path.ReleaseBuffer();
	int nPos;
	nPos=sPath.ReverseFind('\\');
	Path=Path.Left(nPos);//获取文件的路径
    nPos=Path.ReverseFind('\\');
    Path=Path.Left(nPos);//获取文件的路径
	ShellExecute(NULL,NULL,_T("用户手册.doc"),NULL,_T(Path),NULL);
	
}


void CMapPublicView::OnSysLog() 
{
	CQueryDlg m_dlg;
	m_dlg.DoModal();
	
	
}

void CMapPublicView::OnUpdateSysLog(CCmdUI* pCmdUI) 
{
	CMapPublicApp *app=(CMapPublicApp *)AfxGetApp();
   	pCmdUI->Enable(app->bEnableMenu);
	
}

BOOL CMapPublicView::PlayResource(WORD wResourceID)
{	
// Get the handle to the current instance of the application
	HINSTANCE hInstance = AfxGetInstanceHandle();
    ASSERT (hInstance != NULL);
	
	// Find the WAVE resource
	HRSRC hResInfo = 
		FindResource(hInstance, MAKEINTRESOURCE(wResourceID), _T("WAVE"));
	if(hResInfo == NULL)
		return FALSE;
	
	// Load the WAVE resource
    HANDLE hRes = LoadResource(hInstance, hResInfo);
	if (hRes == NULL)
		return FALSE;
    
	// Lock the WAVE resource and play it
    LPSTR lpRes = (LPSTR) LockResource(hRes);
	if(lpRes==NULL)
		return FALSE;
    
	if (sndPlaySound(lpRes, SND_MEMORY | SND_ASYNC) == NULL)
		return FALSE;	
	
    // Free the WAVE resource and return success or failure.
    FreeResource(hRes);
	
	return TRUE;
}

void CMapPublicView::OnMouseMove(UINT nFlags, CPoint point) 
{
	CFormView::OnMouseMove(nFlags, point);
}

void CMapPublicView::OnTimer(UINT nIDEvent) 
{
    switch(nIDEvent)
	{
	case LT_LIGHT:
		static int nCount;
		nCount++;
		// Fun stuff. Ping each Led from left to right.
		switch(nCount%23)
		{
		case 0: m_Led1.Ping(200); break;
		case 1: m_Led2.Ping(200); break;
		case 2: m_Led3.Ping(200); break;
		case 3: m_Led4.Ping(200); break;
		case 4: m_Led5.Ping(200); break;
		case 5: m_Led6.Ping(200); break;
		case 6: m_Led7.Ping(200); break;
	    case 7: m_Led8.Ping(200); break;
        case 8: m_Led9.Ping(200); break;
		case 9: m_Led10.Ping(200); break;
		case 10: m_Led11.Ping(200); break;
		case 11: m_Led12.Ping(200); break;
		case 12: m_Led13.Ping(200); break;
		case 13: m_Led14.Ping(200); break;
		case 14: m_Led15.Ping(200); break;
		case 15: m_Led16.Ping(200); break;
		case 16: m_Led17.Ping(200); break;
		case 17: m_Led18.Ping(200); break;
		case 18: m_Led19.Ping(200); break;
		case 19: m_Led20.Ping(200); break;
		case 20: m_Led21.Ping(200); break;
		case 21: m_Led22.Ping(200); break;
		case 22: m_Led23.Ping(200); break;
		}
		break;
	//	case 300:
	//		m_ledstatic.Ping(200);
	//		break;
	
	}
	CFormView::OnTimer(nIDEvent);
}

void CMapPublicView::OnMusic() 
{
    musicflag=!musicflag;
    if(musicflag)
		PlayResource(IDR_WAVE4);//播放音乐
	else if(!musicflag)
		PlayResource(IDR_WAVE5);
}

void CMapPublicView::OnUpdateMusic(CCmdUI* pCmdUI) 
{
  if(!musicflag)
		pCmdUI->SetCheck(0);
  else 
    	pCmdUI->SetCheck(1);
		
}

