// PAGE3.cpp : implementation file
//

#include "stdafx.h"
#include "LICAI.h"
#include "PAGE3.h"
#include "LCSet.h"
#include "VcPlot.h"
#include "VcAxis.h"
#include "VcValueScale.h"
#include "VcSeriesCollection.h"
#include "VcSeries.h"
#include "VcPen.h"
#include "VcCategoryScale.h"
#include "VcColor.h"
#include "VcDataGrid.h"
#include "VcBackdrop.h"
#include "VcFill.h"
#include "VcBrush.h"
#include "VcDataPoints.h"
#include "VcDataPoint.h"
#include "VcDataPointLabel.h"
#include "VcAxisTitle.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PAGE3 dialog


PAGE3::PAGE3(CWnd* pParent /*=NULL*/)
	: CDialog(PAGE3::IDD, pParent)
{
	//{{AFX_DATA_INIT(PAGE3)
	//}}AFX_DATA_INIT
}


void PAGE3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PAGE3)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PAGE3, CDialog)
	//{{AFX_MSG_MAP(PAGE3)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_DRAWLINE, OnDrawline)
	ON_BN_CLICKED(IDC_DRAWCOMBI, OnDrawcombi)
	ON_BN_CLICKED(IDC_DRAWPIE, OnDrawpie)
//	ON_COMMAND_RANGE(IDC_DRAWLINE,IDC_DRAWPIE,)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PAGE3 message handlers

BOOL PAGE3::OnInitDialog() 
{
	CDialog::OnInitDialog();

		
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

int PAGE3::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	CRect rc1;
	GetClientRect(&rc1);
	CRect rc(rc1.left,rc1.top,rc1.right,rc1.bottom-50);
	WCHAR pwchLicenseKey[] =
	{
		    0x0038, 0x0045, 0x0031, 0x0034, 0x0037, 0x0043,    
			0x0036, 0x0039, 0x002D, 0x0042, 0x0044, 0x0035,    
			0x0030, 0x002D, 0x0031, 0x0031, 0x0064, 0x0031,    
			0x002D, 0x0042, 0x0031, 0x0033, 0x0037, 0x002D,    
			0x0030, 0x0030, 0x0030, 0x0030, 0x0046, 0x0038,    
			0x0037, 0x0035, 0x0033, 0x0046, 0x0035, 0x0044
	};
	BSTR bstrLicense = ::SysAllocStringLen(pwchLicenseKey,sizeof(pwchLicenseKey)/sizeof(WCHAR));
	BOOL bResult = m_Chart.Create("mschart", WS_CHILD| WS_VISIBLE, rc, this, 20000, NULL, FALSE, bstrLicense);
	::SysFreeString(bstrLicense);
	InitChart();
	DrawChart();	
	return 0;
}

void PAGE3::DrawChart()
{
	LCSet mySet;
	mySet.Open();
	mySet.MoveFirst();
	int incomenum=0,costnum=0,total;//incomenum表示总收入，costnum表示支出数目，total表示剩余的数目
	while(!mySet.IsEOF())
	{   
		incomenum+=mySet.m_incomenum;
		costnum+=mySet.m_costnum;
		mySet.MoveNext();
	}
	total=incomenum-costnum;
	if(mySet.IsOpen())
		mySet.Close();
	mySet.Open();
	bool tflag1,tflag2,tflag3;   //他们分别用来判断是否两个字符串匹配
	mySet.Requery();
	int incomenum1=0,costnum1=0,total1=0,incomenum2=0;
	int costnum2=0,total2=0,incomenum3=0,costnum3=0,total3=0;
	COleDateTime oleDt=COleDateTime::GetCurrentTime();
	CString stime=oleDt.Format("%Y-%m-%d %H:%M:%S");
	while(!mySet.IsEOF())
	{   
		for(int i=0;i<10;i++)     //i用来指明字符串下标
		{
			if(mySet.m_time[i]==stime[i])
				tflag1=true;
			else 
			{
				tflag1=false;
				break;
			}
		}
		if(tflag1)
		{
			incomenum1=incomenum1+mySet.m_incomenum;
			costnum1=costnum1+mySet.m_costnum;
		}
		for(int j=0;j<7;j++)     //j用来指明字符串下标
		{
			if(mySet.m_time[j]==stime[j])
				tflag2=true;
			else 
			{
				tflag2=false;
				break;
			}
		}
		if(tflag2)
		{
			incomenum2=incomenum2+mySet.m_incomenum;
			costnum2=costnum2+mySet.m_costnum;
		}
		for(int n=0;n<4;n++)     //n用来指明字符串下标
		{
			if(mySet.m_time[n]==stime[n])
				tflag3=true;
			else 
			{
				tflag3=false;
				break;
			}
		}
		if(tflag3)
		{
			incomenum3=incomenum3+mySet.m_incomenum;
			costnum3=costnum3+mySet.m_costnum;
		}
		mySet.MoveNext();
	}
	total1=incomenum1-costnum1;
	total2=incomenum2-costnum2;
    total3=incomenum3-costnum3;
    int nRowCount = 3;
	m_Chart.SetRowCount(nRowCount);
	VARIANT var;
	m_Chart.GetPlot().GetAxis(0,var).GetCategoryScale().SetAuto(FALSE);			// 不自动标注X轴刻度
	m_Chart.GetPlot().GetAxis(0,var).GetCategoryScale().SetDivisionsPerLabel(1);// 每刻度一个标注
	m_Chart.GetPlot().GetAxis(0,var).GetCategoryScale().SetDivisionsPerTick(1); // 每刻度一个刻度线
	m_Chart.GetPlot().GetAxis(0,var).GetAxisTitle().SetText("收支情况");			// X轴名称
	int benri[4]={incomenum1,costnum1,total1};
    int benyue[4]={incomenum2,costnum2,total2};
	int bennian[4]={incomenum3,costnum3,total3};
    int zong[4]={incomenum,costnum,total};
	char *buf[]={"用户收入","用户支出","用户节余数目"};
	char b[32];
	srand( (unsigned)time( NULL ) );
	for(int row = 1; row <= nRowCount; ++row)
	{
		m_Chart.SetRow(row);
		sprintf(b, buf[row-1]);
		m_Chart.SetRowLabel((LPCTSTR)b);
		m_Chart.GetDataGrid().SetData(row, 1, benri[row-1], 0);
		m_Chart.GetDataGrid().SetData(row, 2, benyue[row-1], 0);
		m_Chart.GetDataGrid().SetData(row, 3, bennian[row-1], 0);
		m_Chart.GetDataGrid().SetData(row, 4, zong[row-1], 0);
    }
	m_Chart.Refresh();	
}


void PAGE3::InitChart()
{
	// 设置标题
	m_Chart.SetTitleText("收支统计图表               统计人：HC");

	// 下面两句改变背景色
	m_Chart.GetBackdrop().GetFill().SetStyle(1);
	m_Chart.GetBackdrop().GetFill().GetBrush().GetFillColor().Set(255, 255, 255);

	// 显示图例
	m_Chart.SetShowLegend(TRUE);
	m_Chart.SetColumn(1);
	m_Chart.SetColumnLabel((LPCTSTR)"今日");
	m_Chart.SetColumn(2);
	m_Chart.SetColumnLabel((LPCTSTR)"本月");
	m_Chart.SetColumn(3);
	m_Chart.SetColumnLabel((LPCTSTR)"本年度");
	m_Chart.SetColumn(4);
	m_Chart.SetColumnLabel((LPCTSTR)"总收支统计");

	// 栈模式
	m_Chart.SetStacking(FALSE);

	// Y轴设置
	VARIANT var;
	m_Chart.GetPlot().GetAxis(1,var).GetValueScale().SetAuto(true);	// 不自动标注Y轴刻度
//	m_Chart.GetPlot().GetAxis(1,var).GetValueScale().SetMaximum(200);	// Y轴最大刻度
//	m_Chart.GetPlot().GetAxis(1,var).GetValueScale().SetMinimum(0);		// Y轴最小刻度
	m_Chart.GetPlot().GetAxis(1,var).GetValueScale().SetMajorDivision(10);	// Y轴刻度5等分
	m_Chart.GetPlot().GetAxis(1,var).GetValueScale().SetMinorDivision(7);	// 每刻度一个刻度线
//	m_Chart.GetPlot().GetAxis(1,var).GetAxisTitle().SetText(" 资金数(元) ");	// Y轴名称

	// 3条曲线
	m_Chart.SetColumnCount(4); 

	// 线色
	m_Chart.GetPlot().GetSeriesCollection().GetItem(1).GetPen().GetVtColor().Set(0, 0, 255);
	m_Chart.GetPlot().GetSeriesCollection().GetItem(2).GetPen().GetVtColor().Set(0, 0, 0);
	m_Chart.GetPlot().GetSeriesCollection().GetItem(3).GetPen().GetVtColor().Set(0, 0, 0);

	// 线宽(对点线图有效)
	m_Chart.GetPlot().GetSeriesCollection().GetItem(1).GetPen().SetWidth(50);
	m_Chart.GetPlot().GetSeriesCollection().GetItem(2).GetPen().SetWidth(100);
	m_Chart.GetPlot().GetSeriesCollection().GetItem(3).GetPen().SetWidth(2);

	// 数据点类型显示数据值的模式(对柱柱状图和点线图有效)
	// 0: 不显示	1: 显示在柱状图外
	// 2: 显示在柱状图内上方	3: 显示在柱状图内中间	4: 显示在柱状图内下方
	m_Chart.GetPlot().GetSeriesCollection().GetItem(1).GetDataPoints().GetItem(-1).GetDataPointLabel().SetLocationType(1);
	m_Chart.GetPlot().GetSeriesCollection().GetItem(2).GetDataPoints().GetItem(-1).GetDataPointLabel().SetLocationType(1);
	m_Chart.GetPlot().GetSeriesCollection().GetItem(3).GetDataPoints().GetItem(-1).GetDataPointLabel().SetLocationType(1);
	m_Chart.GetPlot().GetSeriesCollection().GetItem(4).GetDataPoints().GetItem(-1).GetDataPointLabel().SetLocationType(1);
}

void PAGE3::OnDrawline() 
{
	m_Chart.SetChartType(0); 
	DrawChart();
}

void PAGE3::OnDrawcombi() 
{
	m_Chart.SetChartType(5); 
	DrawChart();
	
}

void PAGE3::OnDrawpie() 
{
	m_Chart.SetChartType(6); 
	DrawChart();	
}
