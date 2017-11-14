// MapPublicView.h : interface of the CMapPublicView class
//
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INCLUDES()
#include "map.h"
//}}AFX_INCLUDES
#include "SpeciesSet.h"
#include "MapPublic.h"
#include "modataconnection.h"
#include "mopoint.h"
#include "morectangle.h"
#include "molayers.h"
#include "momaplayer.h"
#include "mogeodataset.h"
#include "mogeodatasets.h"
#include "mosymbol.h"
#include "mogrouprenderer.h"
#include "movaluemaprenderer.h"
#include "MapObjects2.h"
#include "MapHelper.h"
#include "FindDlg.h"
#include "MainFrm.h"

#include "MyNewThread.h"
#include "MusicThread.h"
#include "Led.h"
#if !defined(AFX_MAPPUBLICVIEW_H__F17ACC6C_67EF_4EAB_9567_827159CBCC7C__INCLUDED_)
#define AFX_MAPPUBLICVIEW_H__F17ACC6C_67EF_4EAB_9567_827159CBCC7C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MapPublicDoc.h"

#include "InfoMation.h"

#include "Led.h"

struct drawtext//记录加载公交站点信息
{
	CMoPoint station_pt;
	CString strName;
	
};


class CMapPublicView : public CFormView
{
protected: // create from serialization only
	CMapPublicView();
	DECLARE_DYNCREATE(CMapPublicView)
		
public:
	//{{AFX_DATA(CMapPublicView)
	enum { IDD = IDD_MAPPUBLIC_FORM };
	CMap1	m_Map;
	CString m_editbox;
	CLed	m_Led23;
	CLed	m_Led22;
	CLed	m_Led21;
	CLed	m_Led20;
	CLed	m_Led19;
	CLed	m_Led18;
	CLed	m_Led17;
	CLed	m_Led16;
	CLed	m_Led15;
	CLed	m_Led14;
	CLed	m_Led13;
	CLed	m_Led12;
	CLed	m_Led11;
	CLed	m_Led10;
	CLed	m_Led9;
	CLed	m_Led8;
	CLed	m_Led7;
	CLed	m_Led6;
	CLed	m_Led5;
	CLed	m_Led4;
	CLed	m_Led3;
	CLed	m_Led2;
	CLed	m_Led1;
																//}}AFX_DATA
																
																// Attributes
public:
	CMapPublicDoc* GetDocument();
    CMoLayers m_layers;
    CMoMapLayer m_maplayer;
    CString sPath;//保存路径
	CMoMapLayer m_mapLayer[28];//每一层挂接的矢量数据
   	//***********************************
	CString GetFileName(const CString &path);
	CString GetFileTitle(const CString &path);
	CString GetFileDirectory(const CString &path);
	/*layers 添加的图层
	
	*/
	CString AddShpLayer(CMoMapLayer mapLayer,const CString &VectorFileName,COLORREF color,short symbolSize,short symbolStyle,BOOL VisibleFlag,int index);
    //******************************************
	void OnSetLabelParameter(int index,COLORREF color,int FontSize);
	void AddLayer();
    void AddLabel(int index,COLORREF color,int FontSize);//添加标注
	CMoLayers m_players;//全局变量
	CMoMapLayer m_pmaplayer;//全局变量
	int Number;//控制地图的显示
	
	bool bControlFlag;//控制仅显示一个主题时，
	LayerInfo m_mapInfo[28];
	int m_nindex;//控件中的各个图层
	
	void ShowLayer();//图层显示控制
	void HideLayer();//图层的隐藏
	
	//--------------------------------------
	//两点间距离
	CMoPoint m_startPoint,m_endPoint;
	int m_mouseDownNum;
	CInfoMation Info;//图层信息
	CFindDlg finddlg;
	void FindArea(CString searchText);
	//----------------------------------------
	//地物选择
	CMoRecordset m_SelectRecSet;//用于传递所得到的记录集,以便让其高亮显示
	bool showflag;//用于控制是否高亮显示
	bool showpointflag;//用于控制是否高亮显示
	void GetSelectAttribute(long x,long y);//获取道路属性
	void GetPointAttribute(CString strName,long X,long Y);//获得地物属性
	
	//------------------------------------------
	//控制鼠标样式
	UINT m_cur;
	HCURSOR m_Cursor;
	//-------------------------------------------
	//刷新以便去除标记
	//void flash();
	void require_attribute(CString string);
	//-----------------------------------------------
	// Operations
public:
	DWORD m_CurrentOperation;//鼠标当前操作
    bool pointflag;// 用于控制地物选择，当用户选择单一主题时，
	CString strName;//用于传递单个图层名
	bool bCheckMenu;//控制菜单是否选择
	//才可以使用地物选择按纽
	//----------------------------------------------------
	//自动创建公交站点图层
public:
	
	bool CreateNewLayer();//创建一个新的图层
	bool CreateTable(CMoRecordset m_RecSet);/////////name为测试用
	bool Draw_TEXT(CMoFields ShapeFields,CString strName);//将公交站点绘出
	bool flashflag;//控制图层的刷新
	drawtext m_Struct[200];
	
	//-------------------------------------------------------------
	CMyNewThread *p_thread;
	CMusicThread *p_music;
	//-----------------------------------------------------
	//界面美化
	BOOL PlayResource(WORD wResourceID);//添加声音
	void showlight();
	bool musicflag;//加载背景音乐
    CLed m_ledstatic;
	void  createled(int X,int Y);
	//--------------------------------------------------------------
	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMapPublicView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL
	
	// Implementation
public:
	virtual ~CMapPublicView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	
protected:
	
	// Generated message map functions
protected:
	//{{AFX_MSG(CMapPublicView)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnMapZoomin();
	afx_msg void OnMapZoomout();
	afx_msg void OnMapPan();
	afx_msg void OnMouseDownMap1(short Button, short Shift, long X, long Y);
	afx_msg void OnMapFullshow();
	afx_msg void OnCommunity();
	afx_msg void OnBank();
	afx_msg void OnEducation();
	afx_msg void OnRestaurant();
	afx_msg void OnShop();
	afx_msg void OnTour();
	afx_msg void OnHospital();
	afx_msg void OnTraffic();
	afx_msg void OnEnterprise();
	afx_msg void OnGoverment();
	afx_msg void OnAll();
	afx_msg void OnSavebmp();
	afx_msg void OnMeasure();
	afx_msg void OnDblClickMap1();
	afx_msg void OnFind();
	afx_msg void OnDelStation();
	afx_msg void OnAddRoadway();
	afx_msg void OnDelRoadway();
	afx_msg void OnChangeStation();
	afx_msg void OnSelect();
	afx_msg void OnSelectAttribute();
	afx_msg void OnAfterLayerDrawMap1(short index, BOOL canceled, long hDC);
	afx_msg void OnSelectPoint();
	afx_msg void OnFresh();
	afx_msg void OnUpdateSelectPoint(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDelStation(CCmdUI* pCmdUI);
	afx_msg void OnUpdateChangeStation(CCmdUI* pCmdUI);
	afx_msg void OnUpdateAddRoadway(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDelRoadway(CCmdUI* pCmdUI);
	afx_msg void OnUpdateLog(CCmdUI* pCmdUI);
	afx_msg void OnUpdateSelectAttribute(CCmdUI* pCmdUI);
	afx_msg void OnUserLogin();
	afx_msg void OnUpdateUserLogin(CCmdUI* pCmdUI);
	afx_msg void OnQuit();
	afx_msg void OnUpdateQuit(CCmdUI* pCmdUI);
	afx_msg void OnPublicBus();
	afx_msg void OnHelp();
	afx_msg void OnSysLog();
	afx_msg void OnUpdateSysLog(CCmdUI* pCmdUI);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnMusic();
	afx_msg void OnUpdateMusic(CCmdUI* pCmdUI);
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
		DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MapPublicView.cpp
inline CMapPublicDoc* CMapPublicView::GetDocument()
{ return (CMapPublicDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAPPUBLICVIEW_H__F17ACC6C_67EF_4EAB_9567_827159CBCC7C__INCLUDED_)
