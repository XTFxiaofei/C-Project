//**************************************************************
//
//              主程序设计：李建湘
//                电子邮件：root@saniseat.com.cn
//                           2002.12.24
//
//**************************************************************

// LjxWnd.cpp : implementation file
//

#include "stdafx.h"
#include "LjxWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLjxWnd

CLjxWnd::CLjxWnd()
{
   	m_bitmap.LoadBitmap(IDB_SPLASH);//拷贝资源位图
	
    m_bitmap.GetBitmap(&bm);//得到位图结构中的大小信息
}

CLjxWnd::~CLjxWnd()
{

}


BEGIN_MESSAGE_MAP(CLjxWnd, CWnd)
	//{{AFX_MSG_MAP(CLjxWnd)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CLjxWnd message handlers

void CLjxWnd::CreatLjxWnd()
{
   //建立大小与位图大小相同的窗口
   CreateEx(0,
   AfxRegisterWndClass(0,AfxGetApp()->LoadStandardCursor(IDC_ARROW)),
						"animatesplash",
						WS_POPUP,
						0,0,bm.bmWidth,bm.bmHeight,
						NULL,
						NULL,
						NULL );
}



void CLjxWnd::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	MemDC.CreateCompatibleDC(NULL);//建立一个和dc兼容的内存DC放置位图
    old_bitmap=MemDC.SelectObject(&m_bitmap);//将创建的位图选入内存DC

int i,j,stepx,stepy,dispnum,x,y; 
int ljx[20][20];      //数组记录已显示过的数据组 

for ( i=0; i<20; i++ ) 

for ( j=0; j<20; j++ ) 

ljx[i][j]=0; 

stepx=bm.bmWidth/20; 

stepy=bm.bmHeight/20; 

srand( (unsigned)time( NULL ) ); 

dispnum=0; 

//记录已显示过的数据组的个数 

while(1) 

{ x=rand() % 20; 

y=rand() % 20; 

if ( ljx[x][y] ) //如果为1，则已经显示了，跳出循环。

continue; 

ljx[x][y]=1; //显示，设置为1


dc.StretchBlt( 

x*stepx, y*stepy, 

//目标设备逻辑横、纵坐标 

stepx,stepy, 

//显示位图的像素宽、高度 

&MemDC, 

//位图内存设备对象 

x*stepx, y*stepy, 

//位图的起始横、纵坐标 

stepx,stepy, 

//位图的像素宽、高度 

SRCCOPY); 

dispnum++; 

if ( dispnum >=400 ) 

break; 

Sleep(1); 

}


      MemDC.SelectObject(old_bitmap);
	// Do not call CWnd::OnPaint() for painting messages
}
