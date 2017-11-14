// HawkView.cpp : implementation file
//

#include "stdafx.h"
#include "MapPublic.h"
#include "HawkView.h"
#include "mosymbol.h"
#include "mopoint.h"
#include "MainFrm.h"
#include "MapPublicView.h"
#include "morectangle.h"
#include "MapObjects2.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHawkView

IMPLEMENT_DYNCREATE(CHawkView, CPropertyPage)

CHawkView::CHawkView()
	: CPropertyPage(CHawkView::IDD)
{
	//{{AFX_DATA_INIT(CHawkView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CHawkView::~CHawkView()
{
}

void CHawkView::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHawkView)
	DDX_Control(pDX, IDC_MAP1, m_HawkMap);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHawkView, CPropertyPage)
	//{{AFX_MSG_MAP(CHawkView)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHawkView diagnostics

#ifdef _DEBUG
void CHawkView::AssertValid() const
{
	CPropertyPage::AssertValid();
}

void CHawkView::Dump(CDumpContext& dc) const
{
	CPropertyPage::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHawkView message handlers

void CHawkView::OnSize(UINT nType, int cx, int cy) 
{
	CPropertyPage::OnSize(nType, cx, cy);
	if(m_HawkMap.m_hWnd)//判断窗口是否已存在
		m_HawkMap.SetWindowPos(0,0,0,cx,cy,SWP_NOZORDER);
    	
}

BEGIN_EVENTSINK_MAP(CHawkView, CPropertyPage)
    //{{AFX_EVENTSINK_MAP(CHawkView)
	ON_EVENT(CHawkView, IDC_MAP1, -605 /* MouseDown */, OnMouseDownMap1, VTS_I2 VTS_I2 VTS_I4 VTS_I4)
	ON_EVENT(CHawkView, IDC_MAP1, 3 /* AfterLayerDraw */, OnAfterLayerDrawMap1, VTS_I2 VTS_BOOL VTS_I4)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CHawkView::OnAfterLayerDrawMap1(short index, BOOL canceled, long hDC) 
{
    if(index!=0)	
		return;
	//构造一个符号对象
	CMoSymbol sym;
	sym.CreateDispatch(_T("MapObjects2.Symbol"));
	sym.SetOutlineColor(moRed);
	sym.SetOutline(TRUE);
	sym.SetSymbolType(moFillSymbol);
	sym.SetStyle(moTransparentFill);
	CMainFrame *pFrame=(CMainFrame *)AfxGetMainWnd();
	CMapPublicView *pMapView=(CMapPublicView *)(pFrame->m_wndSplitter.GetPane(0,0));
	m_HawkMap.DrawShape(pMapView->m_Map.GetExtent(),sym);

}


void CHawkView::OnMouseDownMap1(short Button, short Shift, long X, long Y) 
{
    CMoSymbol sym;
	sym.CreateDispatch(_T("MaqpObjects2.Symbol"));
	sym.SetOutline(moRed);
	sym.SetOutline(true);
	sym.SetSymbolType(moFillSymbol);
	sym.SetStyle(moTransparentFill);

	CMoPoint point;
	point=m_HawkMap.ToMapPoint((float)X,(float)Y);
    CMainFrame *pFrame=(CMainFrame *)AfxGetMainWnd();
	CMapPublicView *pMapView=(CMapPublicView *)(pFrame->m_wndSplitter.GetPane(0,0));

	pMapView->m_Map.CenterAt(point.GetX(),point.GetY());
	m_HawkMap.SetExtent(m_HawkMap.GetExtent());
}

BOOL CHawkView::OnInitDialog()
{
	CPropertyPage::OnInitDialog();
	
    m_HawkMap.SetBackColor(RGB(238,238,255));
	GetModuleFileName(NULL,sPath.GetBufferSetLength (MAX_PATH+1),MAX_PATH);//为sPath分配存储空间
	sPath.ReleaseBuffer();
	int nPos;
	nPos=sPath.ReverseFind('\\');
	sPath=sPath.Left(nPos);//获取文件的路径
    nPos=sPath.ReverseFind('\\');
	sPath=sPath.Left(nPos);//获取文件的路径
	sPath+="\\Map";
	sPath+="\\";
	
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
			AddShpLayer(lpszFileName,RGB(104,255,104),0,0,1,0);
			break;
		case 1://绿地
			AddShpLayer(lpszFileName,RGB(157,255,157),0,0,1,1);
			break;
	//	case 2://市区空地
		//	AddShpLayer(lpszFileName,RGB(238,238,255),0,0,1,2);
		//	break;
		case 3://街道层
    		AddShpLayer(lpszFileName,RGB(255,255,193),0,0,1,3);
			break;
	  //  case 4://街区
	//		AddShpLayer(lpszFileName,RGB(255,255,170),0,0,1,4);
		//	break;
			
		case 5://河流
		    AddShpLayer(lpszFileName,RGB(176,176,255),0,0,1,5);
			break;
	

			//*************************************************

	//	case 6://铁路
	//			AddShpLayer(lpszFileName,RGB(0,0,0),4,1,0,6);
	//			 break;
	
		}
		m_pSpeciesSet.MoveNext();
	}
		m_pSpeciesSet.Close();

			return TRUE; 

}
	
CString CHawkView::AddShpLayer(const CString &VectorFileName,COLORREF color,short symbolSize,short symbolStyle,BOOL VisibleFlag,int index)
{
    
	CMoLayers m_Layers;//=layers;
	m_Layers=m_HawkMap.GetLayers();
	CMoMapLayer m_MapLayer;
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
	
	m_MapLayer.SetVisible(true);
	
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
			layerSymbol.SetColor(color);
			layerSymbol.SetSize(7);
			break;
		case 8://水系注记
		case 11://景点
		case 12://厂矿企业
		case 13://交通运输
		case 14://其他名称
		case 15://三级旅游资源
		case 16://山峰注记
		case 17://商场大厦
        case 20://金融机构
		case 21://二级旅游资源
		case 23://五级旅游资源
		case 25://一级旅游资源
			layerSymbol.SetSymbolType(2);
			layerSymbol.SetColor(color);
			layerSymbol.SetSize(8);
			break;
		case 18://村庄小区
		case 19://事业单位
		case 22://文体机构
		case 24://学校
			layerSymbol.SetSymbolType(1);
			layerSymbol.SetColor(color);
			layerSymbol.SetSize(8);
			break;
		case 26://医疗卫生
			layerSymbol.SetSymbolType(3);
			layerSymbol.SetColor(color);
			layerSymbol.SetSize(8);
			break;
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
	if(VisibleFlag)
		m_MapLayer.SetVisible(true);
	else
		m_MapLayer.SetVisible(false);

	return (m_MapLayer.GetName());
	
	///////////////////////////////////////////
	/////////////////////////////////////////////
	
}


CString CHawkView::GetFileTitle(const CString &path)
{
	CString strResult=GetFileName(path);
	int pos=strResult.ReverseFind('.');
	if(pos>=0)
		return strResult.Left(pos);
	return strResult;
	
	
}
CString CHawkView::GetFileName(const CString &path)
{
	int pos=path.ReverseFind('\\');
	if(pos>=0)
		return path.Right(path.GetLength()-pos-1);
	return path;
	
	
}


CString CHawkView::GetFileDirectory(const CString &path)
{
	int pos=path.ReverseFind('\\');
	if(pos>=0)
		return path.Left(pos);
	return " ";
	
	
}
