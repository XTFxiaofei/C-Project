// UserPrintDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HCOK.h"
#include "UserPrintDlg.h"
#include "PreParent.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// UserPrintDlg dialog


UserPrintDlg::UserPrintDlg(CWnd* pParent /*=NULL*/)
	: CDialog(UserPrintDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(UserPrintDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void UserPrintDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(UserPrintDlg)
	DDX_Control(pDX, IDC_LIST1, m_list);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(UserPrintDlg, CDialog)
	//{{AFX_MSG_MAP(UserPrintDlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// UserPrintDlg message handlers

BOOL UserPrintDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_list.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	   m_list.InsertColumn(0,"",LVCFMT_CENTER,120);
	   m_list.InsertColumn(1,"",LVCFMT_CENTER,120);	
	   m_list.InsertColumn(2,"",LVCFMT_CENTER,100);	


	    	 GetDlgItem(IDC_EDIT1)->SetWindowText(  timestr1);
			 GetDlgItem(IDC_EDIT2)->SetWindowText(   timestr2);
			 GetDlgItem(IDC_EDIT3)->SetWindowText(  addroomtype);
			 GetDlgItem(IDC_EDIT4)->SetWindowText(  addcardtype);
			 GetDlgItem(IDC_EDIT5)->SetWindowText( printprice);
			 GetDlgItem(IDC_EDIT6)->SetWindowText(  printabate);	
			 GetDlgItem(IDC_EDIT7)->SetWindowText(  givenmoney);
			 GetDlgItem(IDC_EDIT8)->SetWindowText(  printmoneybake);


	   showprint();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void UserPrintDlg::showprint()
{   
	
	m_list.DeleteAllItems();

/*	m_list.InsertItem(0,  timestr1);
	m_list.SetItemText(0,1,	  timestr2);
	m_list.SetItemText(0,2,	addroomtype);
	m_list.SetItemText(0,3,	addcardtype);
	m_list.SetItemText(0,4,	printabate	);
	m_list.SetItemText(0,5,	printprice);
	m_list.SetItemText(0,6,	givenmoney);
	m_list.SetItemText(0,7,	printmoneybake);
	*/
  CString title[8]={"开始消费时间","结束消费时间","包房类型","会员卡类型","每小时单价(元)","打折率","预付金额(元)","找零(元)"};
    printprice.TrimRight ();
	   CString mingxi[8]={timestr1, timestr2,addroomtype,addcardtype,printprice,printabate,	givenmoney,printmoneybake};
	   CString s0,s1,s2;
		int i=0; 
		while(i<8)  
		{
			s2=mingxi[i];
			s1= title[i];
        	s0.Format("%d",i+1 );
			m_list.InsertItem(i,s0);
			m_list.SetItemText(i,1,s1);
			m_list.SetItemText(i,2,s2); 
            i++;
		} 
		
   }



void UserPrintDlg::OnButton1()/////////////////////////打印预览按钮
{	if(m_list.GetItemCount()<= 0)
	return;
	PRNINFO PrnInfo = {0};
	PrnInfo.hListView = m_list.m_hWnd;
	PrnInfo.hWnd = this->m_hWnd;
	PrnInfo.IsPrint = FALSE;
	PrnInfo.nCurPage = 1;
	PrnInfo.nMaxLine = m_list.GetItemCount();
	
	CPreParent DlgPreView;
	DlgPreView.SetCallBackFun(DrawInfo, PrnInfo);
	DlgPreView.DoModal();
	

	
}

void UserPrintDlg::DrawInfo(CDC &memDC, PRNINFO PrnInfo)
{
	if(memDC.m_hDC == NULL)
		return;

	int nCurPage = PrnInfo.nCurPage;	//当前页
	BOOL IsPrint = PrnInfo.IsPrint;		//是否打印
	int nMaxPage = PrnInfo.nCountPage;	//最大页码
	HWND hWnd = PrnInfo.hWnd;
	HWND hList = PrnInfo.hListView;
	CString csLFinality, csRFinality;
	CTime time;
	time=CTime::GetCurrentTime();
	csLFinality = time.Format("打印日期:%Y-%m-%d");
	csRFinality.Format("第 %i 页/共 %i 页", nCurPage, nMaxPage);

	TCHAR szTitle[] = TEXT("强强点歌顾客消费账单");

	CRect rc, rt1, rt2, rt3, rt4, rt5, rt6,rt7,rt8,rt9,rt10,rt11;
	CPen *hPenOld;
	CPen		cPen;
	CFont TitleFont, DetailFont, *oldfont;
	//标题字体
	TitleFont.CreateFont(-MulDiv(14,memDC.GetDeviceCaps(LOGPIXELSY),72),
		0,0,0,FW_NORMAL,0,0,0,GB2312_CHARSET,
		OUT_STROKE_PRECIS,CLIP_STROKE_PRECIS,DRAFT_QUALITY,
		VARIABLE_PITCH|FF_SWISS,_T("楷体_GB2312"));
	//细节字体
	DetailFont.CreateFont(-MulDiv(10,memDC.GetDeviceCaps(LOGPIXELSY),72),
		0,0,0,FW_NORMAL,0,0,0,GB2312_CHARSET,
		OUT_STROKE_PRECIS,CLIP_STROKE_PRECIS,DRAFT_QUALITY,
		VARIABLE_PITCH|FF_SWISS,_T("宋体"));
	//粗笔
	cPen.CreatePen(PS_SOLID, 2, RGB(0, 0, 255));

 	int xP = GetDeviceCaps(memDC.m_hDC, LOGPIXELSX);	//x方向每英寸像素点数
	int yP = GetDeviceCaps(memDC.m_hDC, LOGPIXELSY);	//y方向每英寸像素点数

	DOUBLE xPix = (DOUBLE)xP*10/254;	//每 mm 宽度的像素
	DOUBLE yPix = (DOUBLE)yP*10/254;	//每 mm 高度的像素
	DOUBLE fAdd = 7*yPix;		//每格递增量
	DOUBLE nTop = 25*yPix;		//第一页最上线
	int	  iStart = 0;			//从第几行开始读取
	DOUBLE nBottom = nTop+B5_ONELINE*fAdd;
	if(nCurPage != 1)
		nTop = 25*yPix-fAdd;	//非第一页最上线
	if(nCurPage == 2)
		iStart = B5_ONELINE;
	if(nCurPage>2)
		iStart = B5_ONELINE+(nCurPage - 2)*B5_OTHERLINE;

	DOUBLE nLeft = 20*xPix;			//最左线
	DOUBLE nRight = xPix*(B5_W-20);	//最右线



	DOUBLE nTextAdd = 1.5*xPix;
	if(IsPrint)
	{
		//真正打印部分
		static DOCINFO di = {sizeof (DOCINFO),  szTitle} ;
		//开始文档打印
		if(memDC.StartDoc(&di)<0)
		{
			::MessageBox(hWnd, "连接到打印机化败!", "错误", MB_ICONSTOP);
		}
		else
		{
			iStart = 0;
			nTop = 25*yPix;		//第一页最上线
			for(int iTotalPages = 1; iTotalPages<=nMaxPage; iTotalPages++)
			{
				int nCurPage = iTotalPages;
				csRFinality.Format("第 %i 页/共 %i 页", nCurPage, nMaxPage);
				time=CTime::GetCurrentTime();
				csLFinality = time.Format("打印日期:%Y-%m-%d");

				if(nCurPage != 1)
					nTop = 25*yPix-fAdd;	//非第一页最上线
				if(nCurPage == 2)
					iStart = B5_ONELINE;
				if(nCurPage>2)
					iStart = B5_ONELINE+(nCurPage - 2)*B5_OTHERLINE;
				//开始页
				if(memDC.StartPage() < 0)
				{
					::MessageBox(hWnd, _T("打印失败!"), "错误", MB_ICONSTOP);
					memDC.AbortDoc();
					return;
				}
				else
				{/*
				
				*/}
			}
			memDC.EndDoc();
		}
	}
	else
	{
		//打印预览
		
		//边框线
		hPenOld = memDC.SelectObject(&cPen);
		rc.SetRect(0, 0, B5_W*xPix, B5_H*yPix);
		memDC.Rectangle(&rc);
		memDC.SelectObject(hPenOld);	
		//标题
		oldfont = memDC.SelectObject(&TitleFont);
		int nItem = B5_OTHERLINE;
		if(nCurPage == 1)
		{
			nItem = B5_ONELINE;
			rc.SetRect(0, yPix*10, B5_W*xPix, yPix*20);
			memDC.DrawText(szTitle, &rc, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		}
		//细节
 		memDC.SelectObject(&DetailFont);
		rc.SetRect(nLeft, nTop, nRight, nTop+fAdd);
		//上横线
		memDC.MoveTo(rc.left, rc.top);
		memDC.LineTo(rc.right, rc.top);
		
		rt1.SetRect(nLeft, nTop, nLeft+20*xPix, nTop+fAdd);					
		rt2.SetRect(rt1.right, rt1.top, rt1.right + 50*xPix, rt1.bottom);	
	   rt3.SetRect(rt3.right, rt1.top, rc.right, rt1.bottom);				
		
		memDC.DrawText("", &rt1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		memDC.DrawText("", &rt2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		memDC.DrawText("", &rt3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	
		memDC.MoveTo(rt1.right, rt1.top);
		memDC.LineTo(rt1.right, rt1.bottom);
		memDC.MoveTo(rt2.right, rt1.top);
		memDC.LineTo(rt2.right, rt1.bottom);
		memDC.MoveTo(rt3.right, rt1.top);
		memDC.LineTo(rt3.right, rt1.bottom);
       memDC.MoveTo(rc.left, rt1.bottom);
		memDC.LineTo(rc.right, rt1.bottom);

		//TCHAR CID[32]={0}, SName[16]={0}, GName[16]={0};
		TCHAR num[32]={0}, titl[32]={0}, ming[50]={0};
		rc.SetRect(nLeft, nTop+fAdd, nRight, nTop+2*fAdd);

		rt1.SetRect(nLeft+nTextAdd, rc.top, nLeft+20*xPix, rc.bottom);				
		rt2.SetRect(rt1.right+nTextAdd, rt1.top, rt1.right + 50*xPix, rt1.bottom);	
        rt3.SetRect(rt2.right+nTextAdd, rt1.top, rc.right, rt1.bottom);

		int nCountItem = ListView_GetItemCount(hList);
		for(int i=0;i<nItem; i++)
		{
			ListView_GetItemText(hList, i+iStart, 0, num, 32);
			ListView_GetItemText(hList, i+iStart, 1, titl,16);
			ListView_GetItemText(hList, i+iStart, 2, ming, 32);
		
			
			memDC.DrawText( num, &rt1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			memDC.DrawText(titl, &rt2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			memDC.DrawText(ming, &rt3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	
			
			
		
			//下横线
			memDC.MoveTo(rc.left, rc.bottom);
			memDC.LineTo(rc.right, rc.bottom);
			memDC.MoveTo(rt1.right, rt1.top);
			memDC.LineTo(rt1.right, rt1.bottom);
			memDC.MoveTo(rt2.right, rt1.top);
			memDC.LineTo(rt2.right, rt1.bottom);
			memDC.MoveTo(rt3.right, rt1.top);
			memDC.LineTo(rt3.right, rt1.bottom);
	     



			memDC.MoveTo(rc.left, rt1.bottom);
			memDC.LineTo(rc.right, rt1.bottom);
			
			rc.top += fAdd;
			rc.bottom += fAdd;
			rt1.top = rc.top;
			rt1.bottom = rc.bottom;
			rt2.top = rt1.top;
			rt2.bottom = rt1.bottom;
			rt3.top = rt1.top;
			rt3.bottom = rt1.bottom;
	
			if((i+iStart+1)>=nCountItem)
				break;
 		}
		//结尾
		memDC.MoveTo(rc.left, nTop);
		memDC.LineTo(rc.left, rc.top);
		memDC.MoveTo(rc.right, nTop);
		memDC.LineTo(rc.right, rc.top);
		memDC.DrawText(csLFinality, &rc, DT_LEFT| DT_VCENTER | DT_SINGLELINE);
		memDC.DrawText(csRFinality, &rc, DT_RIGHT| DT_VCENTER | DT_SINGLELINE);

		memDC.SelectObject(oldfont);
		memDC.SelectObject(hPenOld);
	}
	TitleFont.DeleteObject();
	DetailFont.DeleteObject();
	cPen.DeleteObject();
}
