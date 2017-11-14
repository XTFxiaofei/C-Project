// InfoMation.h: interface for the CInfoMation class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INFOMATION_H__2AC3BA67_7EAB_4FFE_BD64_32C89633CD73__INCLUDED_)
#define AFX_INFOMATION_H__2AC3BA67_7EAB_4FFE_BD64_32C89633CD73__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "morectangle.h"
#include "math.h"
#include "StationSet.h"
#include "InfoMation.h"
#include "MapPublic.h"
#define MAX 80
//地图上的点
struct MPoint
{
	double x;
	double y;

};

//图层信息
struct LayerInfo
{
	CString szLayerName;   // 图层名称
	int index;//图层编号
	bool bLable;           // 是否为地物加入注记
	bool bVisible;//是否可见
};
//公交车站点信息
struct BusInfo
{
	CString RoadWay;//车次
	CString StationName;//站点名称
};
struct BestMode//乘车方案
{
	int Precept;//方案号
	int Number;//本方案中所经过的站点次数
};


class CInfoMation  
{
public:
	CInfoMation();
	virtual ~CInfoMation();

public:

	//******************************************
	//计算比例尺
	double CalcScale(CMap1* map);
	double CalcLenght(MPoint* pt,int nSize);
    void CalGuassFromLB(double dLongitude, double dLatitude, 
								  double* dX, double* dY, long nCenterL);
    void SubGussFs(double X,double Y,double L0, double* B, double* L);
    void SubGussFs(double* X, double* Y,double B,double L,int nCenterLongi);
	//*********************************************


	//*************************************************************
//公交换乘
	
	BusInfo m_BusInfo[2];
	BestMode m_BusRoad[MAX];//乘车方案
	int Num_BusRoad;//记录符合条件的公交路线
	int busnum;//对站点累加
	bool startflag;//其始站的控制
	int Num;//方案序号
	CString m_station;//站点存储
	CString S_RoadWay[MAX];//存储经过某一站点的所有车次
	CString E_RoadWay[MAX];
	int s_road;//对经过起始站的车次累加
	int e_road;
	CString m_percept;//保存站点
	void Init();//初始化
	BOOL Query(CWnd *pwnd,CString start,CString end);//查询函数
    BOOL Same_RoadWay(CWnd *pwnd,CString start,CString end);//同一车次
	BOOL Dif_RoadWay(CString start,CString end);//一次转乘
	BOOL Precept(CString start,CString end);//生成乘车方案
	BOOL Match(CString percept,CString station);//站点匹配
	int Dif_StationNum(CString s_start,CString first_roadway,CString s_middle,CString second_roadway,CString s_end);
	//参数说明：从%s乘 %s路 到 %s转乘 %s路 到%s下车
	int Num_Station(CString s_start,CString roadway,CString s_end);//计算同一条路线两点间站点数
	CString BestMode();//寻求最优方案
   //*****************************************************************
};








#endif // !defined(AFX_INFOMATION_H__2AC3BA67_7EAB_4FFE_BD64_32C89633CD73__INCLUDED_)
