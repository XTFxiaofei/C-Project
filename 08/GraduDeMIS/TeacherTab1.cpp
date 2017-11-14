// TeacherTab1.cpp : implementation file
#include "stdafx.h"
#include "gradudemis.h"
#include "TeacherTab1.h"
#include "PreParent.h"		//打印预览父窗口
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTeacherTab1 dialog
CTeacherTab1::CTeacherTab1(CWnd* pParent /*=NULL*/)
	: CDialog(CTeacherTab1::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTeacherTab1)
	m_tecr_edit = _T("");
	//}}AFX_DATA_INIT
}
void CTeacherTab1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTeacherTab1)
	DDX_Control(pDX, IDC_TEACHER_EDIT, m_tecr_editctrl);
	DDX_Control(pDX, IDC_TEACHER_COMBO, m_tecr_combo);
	DDX_Control(pDX, IDC_TEACHER_LIST, m_tecr_listctrl);
	DDX_Text(pDX, IDC_TEACHER_EDIT, m_tecr_edit);
	//}}AFX_DATA_MAP
}
BEGIN_MESSAGE_MAP(CTeacherTab1, CDialog)
	//{{AFX_MSG_MAP(CTeacherTab1)
	ON_BN_CLICKED(IDC_TEACHER_BTN, OnTeacherBtn)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_TEACHER_LIST, OnItemchangedTeacherList)
	ON_BN_CLICKED(IDC_PRINTTEST, OnPrinttest)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTeacherTab1 message handlers

BOOL CTeacherTab1::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	pSet1.Open();											//打开记录集
	m_tecr_listctrl.InsertColumn(0,"姓名",LVCFMT_LEFT,60,0);//插入列标题，设定宽度，对齐方式
	m_tecr_listctrl.InsertColumn(1,"性别",LVCFMT_LEFT,40,0);
	m_tecr_listctrl.InsertColumn(2,"年龄",LVCFMT_LEFT,40,0);
	m_tecr_listctrl.InsertColumn(3,"教研室",LVCFMT_LEFT,80,0);
	m_tecr_listctrl.InsertColumn(4,"职称",LVCFMT_LEFT,60,0);
	m_tecr_listctrl.InsertColumn(5,"联系方式",LVCFMT_LEFT,100,0);

    m_tecr_listctrl.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
															//设定风格整行选择网格
	int i=0;												//定义整形变量
	while(!pSet1.IsEOF())									//如果记录不是最后一条
	{
		m_tecr_listctrl.InsertItem(i,pSet1.m_tecr_name);	//像列表控件中插入数据
		m_tecr_listctrl.SetItemText(i,1,pSet1.m_tecr_sex);
		m_tecr_listctrl.SetItemText(i,2,pSet1.m_tecr_age);
		m_tecr_listctrl.SetItemText(i,3,pSet1.m_tecr_TRroom);
		m_tecr_listctrl.SetItemText(i,4,pSet1.m_tecr_level);		
		m_tecr_listctrl.SetItemText(i,5,pSet1.m_tecr_asoci);
        pSet1.MoveNext();									//移动到下条记录
        i++;
	}
	pSet1.Close();											//关闭记录集
//组合框
	CString str[6]={"姓名","性别","年龄","教研室","职称"};	//定义字符串数组赋初值
	for(int j=0;j<5;j++)
		m_tecr_combo.InsertString(j,str[j]);				//插入数据到下拉列表框中
    m_tecr_combo.SetCurSel(0);								//默认选中第一项
		UpdateData(false);									//更新数据
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void CTeacherTab1::OnTeacherBtn() 
{
	// TODO: Add your control notification handler code here
	int nIndex=m_tecr_combo.GetCurSel();					//获取用户选定的索引号
	switch(nIndex)
	{ 
	   case 0:
		   SelectItem(0);  break;							//调用自定义函数  
	   case 1:
		   SelectItem(1);  break; 
	   case 2:
		   SelectItem(2);  break;		   
	   case 3:
		   SelectItem(3);  break; 
	   case 4:
		   SelectItem(4);  break;		   
	   case 5:
		   SelectItem(5);  break; 
	};
}

//教师信息查询
void CTeacherTab1::SelectItem(int n)
{
	char filter[60];												//定义字符数组
	CString str[5]={"tab_tecr.tecr_name='%s'","tab_tecr.tecr_sex='%s'",
		"tab_tecr.tecr_age='%s'","tab_tecr.tecr_TRroom='%s'","tab_tecr.tecr_level='%s'"};
	CString strEdit;												//定义字符串变量
    UpdateData();													//更新数据
	pSet1.Open();													//打开记录集
	wsprintf(filter,str[n],m_tecr_edit);							//格式化
	pSet1.m_strFilter=filter;										//记录赋值
	pSet1.Requery();												//刷新记录集
    m_tecr_editctrl.GetWindowText(strEdit);							//获取控件的文本
	if(strEdit=="")
	{
		MessageBox("查询条件为空，请输入关键词！");					//消息提示
		pSet1.Close();												//关闭记录集
		return;
	}
	else 
	{	
		if(pSet1.IsEOF())											//记录已经到末尾
			AfxMessageBox("要查找的记录不存在！");
		else
		{
		  m_tecr_listctrl.DeleteAllItems();							//删除所有数据
		  int i=0;													//定义整形变量
		  while(!pSet1.IsEOF())										//如果记录没有到末尾
		  {
			m_tecr_listctrl.InsertItem(i,pSet1.m_tecr_name);		//插入数据到列表控件中
			m_tecr_listctrl.SetItemText(i,1,pSet1.m_tecr_sex);
			m_tecr_listctrl.SetItemText(i,2,pSet1.m_tecr_age);
			m_tecr_listctrl.SetItemText(i,3,pSet1.m_tecr_TRroom);
			m_tecr_listctrl.SetItemText(i,4,pSet1.m_tecr_level);
			m_tecr_listctrl.SetItemText(i,5,pSet1.m_tecr_asoci);
			pSet1.MoveNext();										//移动到下条记录
			i++;
		  }
		 UpdateData(false);											//更新数据
		}
	   pSet1.Close();												//关闭记录集
	}
}

void CTeacherTab1::OnItemchangedTeacherList(NMHDR* pNMHDR, LRESULT* pResult) 
{

	// TODO: Add your control notification handler code here
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	int i=pNMListView->iItem;					//获取选中的行号
	selectID=m_tecr_listctrl.GetItemText(i,0);	//获取选中行的第一列的文本
	*pResult = 0;
}

//一下是打印预览
void CTeacherTab1::OnPrinttest() 
{
    if(m_tecr_listctrl.GetItemCount()<= 0)
		return;
	PRNINFO PrnInfo = {0};
	PrnInfo.hListView = m_tecr_listctrl.m_hWnd;
	PrnInfo.hWnd = this->m_hWnd;
	PrnInfo.IsPrint = FALSE;
	PrnInfo.nCurPage = 1;
	PrnInfo.nMaxLine = m_tecr_listctrl.GetItemCount();
	
	CPreParent DlgPreView;
	DlgPreView.SetCallBackFun(DrawInfo, PrnInfo);
	DlgPreView.DoModal();

}
void CTeacherTab1::DrawInfo(CDC &memDC, PRNINFO PrnInfo)
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
	csLFinality = time.Format("报表日期:%Y-%m-%d");
	csRFinality.Format("第 %i 页/共 %i 页", nCurPage, nMaxPage);

	TCHAR szTitle[] = TEXT("教师信息表");
	

	CRect rc, rt1, rt2, rt3, rt4, rt5, rt6;
	CPen *hPenOld;
	CPen		cPen;
	CFont TitleFont, DetailFont, *oldfont;
	//标题字体
	TitleFont.CreateFont(-MulDiv(14,memDC.GetDeviceCaps(LOGPIXELSY),72),
		0,0,0,FW_NORMAL,0,0,0,GB2312_CHARSET,
		OUT_STROKE_PRECIS,CLIP_STROKE_PRECIS,DRAFT_QUALITY,
		VARIABLE_PITCH|FF_SWISS,_T("黑体"));
	//细节字体
	DetailFont.CreateFont(-MulDiv(10,memDC.GetDeviceCaps(LOGPIXELSY),72),
		0,0,0,FW_NORMAL,0,0,0,GB2312_CHARSET,
		OUT_STROKE_PRECIS,CLIP_STROKE_PRECIS,DRAFT_QUALITY,
		VARIABLE_PITCH|FF_SWISS,_T("宋体"));
	//粗笔
	cPen.CreatePen(PS_SOLID, 2, RGB(0, 0, 0));

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
				csLFinality = time.Format("报表日期:%Y-%m-%d");

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
				{
					//打印
					//标题
					/*
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

					rt1.SetRect(nLeft, nTop, nLeft+20*xPix, nTop+fAdd);					//学号
					rt2.SetRect(rt1.right, rt1.top, rt1.right + 25*xPix, rt1.bottom);	//姓名
					rt3.SetRect(rt2.right, rt1.top, rt2.right + 10*xPix, rt1.bottom);	//性别
					rt4.SetRect(rt3.right, rt1.top, rt3.right + 25*xPix, rt1.bottom);	//专业
					rt5.SetRect(rt4.right, rt1.top, rt4.right + 25*xPix, rt1.bottom);	//年级
					rt6.SetRect(rt5.right, rt1.top, rc.right, rt1.bottom);				//班级
					memDC.DrawText("学 号", &rt1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					memDC.DrawText("姓 名", &rt2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					memDC.DrawText("性别", &rt3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					memDC.DrawText("专 业", &rt4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					memDC.DrawText("年 级", &rt5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					memDC.DrawText("班 级", &rt6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

					memDC.MoveTo(rt1.right, rt1.top);
					memDC.LineTo(rt1.right, rt1.bottom);
					memDC.MoveTo(rt2.right, rt1.top);
					memDC.LineTo(rt2.right, rt1.bottom);
					memDC.MoveTo(rt3.right, rt1.top);
					memDC.LineTo(rt3.right, rt1.bottom);
					memDC.MoveTo(rt4.right, rt1.top);
					memDC.LineTo(rt4.right, rt1.bottom);
					memDC.MoveTo(rt5.right, rt1.top);
					memDC.LineTo(rt5.right, rt1.bottom);
//					memDC.MoveTo(rt6.right, rt1.top);
//					memDC.LineTo(rt6.right, rt1.bottom);
					memDC.MoveTo(rc.left, rt1.bottom);
					memDC.LineTo(rc.right, rt1.bottom);

					TCHAR szID[32]={0}, szName[16]={0}, szSex[8]={0}, szZY[32]={0}, szNJ[32]={0}, szBJ[32]={0};
					rc.SetRect(nLeft, nTop+fAdd, nRight, nTop+2*fAdd);
					rt1.SetRect(nLeft+nTextAdd, rc.top, nLeft+20*xPix, rc.bottom);				//学号
					rt2.SetRect(rt1.right+nTextAdd, rt1.top, rt1.right + 25*xPix, rt1.bottom);	//姓名
					rt3.SetRect(rt2.right+nTextAdd, rt1.top, rt2.right + 10*xPix, rt1.bottom);	//性别
					rt4.SetRect(rt3.right+nTextAdd, rt1.top, rt3.right + 25*xPix, rt1.bottom);	//专业
					rt5.SetRect(rt4.right+nTextAdd, rt1.top, rt4.right + 25*xPix, rt1.bottom);	//年级
					rt6.SetRect(rt5.right+nTextAdd, rt1.top, rc.right, rt1.bottom);				//班级

					int nCountItem = ListView_GetItemCount(hList);
					for(int i=0;i<nItem; i++)
					{
						ListView_GetItemText(hList, i+iStart, 0, szID, 32);
						ListView_GetItemText(hList, i+iStart, 1, szName, 16);
						ListView_GetItemText(hList, i+iStart, 2, szSex, 8);
						ListView_GetItemText(hList, i+iStart, 3, szZY, 32);
						ListView_GetItemText(hList, i+iStart, 4, szNJ, 32);
						ListView_GetItemText(hList, i+iStart, 5, szBJ, 32);
						
						memDC.DrawText(szID, &rt1, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
						memDC.DrawText(szName, &rt2, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
						memDC.DrawText(szSex, &rt3, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
						memDC.DrawText(szZY, &rt4, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
						memDC.DrawText(szNJ, &rt5, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
						memDC.DrawText(szBJ, &rt6, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
						//下横线
						memDC.MoveTo(rc.left, rc.bottom);
						memDC.LineTo(rc.right, rc.bottom);
						memDC.MoveTo(rt1.right, rt1.top);
						memDC.LineTo(rt1.right, rt1.bottom);
						memDC.MoveTo(rt2.right, rt1.top);
						memDC.LineTo(rt2.right, rt1.bottom);
						memDC.MoveTo(rt3.right, rt1.top);
						memDC.LineTo(rt3.right, rt1.bottom);
						memDC.MoveTo(rt4.right, rt1.top);
						memDC.LineTo(rt4.right, rt1.bottom);
						memDC.MoveTo(rt5.right, rt1.top);
						memDC.LineTo(rt5.right, rt1.bottom);
//						memDC.MoveTo(rt6.right, rt1.top);
//						memDC.LineTo(rt6.right, rt1.bottom);
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
						rt4.top = rt1.top;
						rt4.bottom = rt1.bottom;
						rt5.top = rt1.top;
						rt5.bottom = rt1.bottom;
						rt6.top = rt1.top;
						rt6.bottom = rt1.bottom;
						
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
					memDC.EndPage();
					memDC.SelectObject(oldfont);
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

		rt1.SetRect(nLeft, nTop, nLeft+20*xPix, nTop+fAdd);					//学号
		rt2.SetRect(rt1.right, rt1.top, rt1.right + 25*xPix, rt1.bottom);	//姓名
		rt3.SetRect(rt2.right, rt1.top, rt2.right + 10*xPix, rt1.bottom);	//性别
		rt4.SetRect(rt3.right, rt1.top, rt3.right + 25*xPix, rt1.bottom);	//专业
		rt5.SetRect(rt4.right, rt1.top, rt4.right + 25*xPix, rt1.bottom);	//年级
		rt6.SetRect(rt5.right, rt1.top, rc.right, rt1.bottom);				//班级
		memDC.DrawText("姓 名", &rt1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		memDC.DrawText("性 别", &rt2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		memDC.DrawText("年 龄", &rt3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		memDC.DrawText("教研室", &rt4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		memDC.DrawText("职 称", &rt5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		memDC.DrawText("联系方式", &rt6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

		memDC.MoveTo(rt1.right, rt1.top);
		memDC.LineTo(rt1.right, rt1.bottom);
		memDC.MoveTo(rt2.right, rt1.top);
		memDC.LineTo(rt2.right, rt1.bottom);
		memDC.MoveTo(rt3.right, rt1.top);
		memDC.LineTo(rt3.right, rt1.bottom);
		memDC.MoveTo(rt4.right, rt1.top);
		memDC.LineTo(rt4.right, rt1.bottom);
		memDC.MoveTo(rt5.right, rt1.top);
		memDC.LineTo(rt5.right, rt1.bottom);
//		memDC.MoveTo(rt6.right, rt1.top);
//		memDC.LineTo(rt6.right, rt1.bottom);
		memDC.MoveTo(rc.left, rt1.bottom);
		memDC.LineTo(rc.right, rt1.bottom);

		TCHAR szID[32]={0}, szName[16]={0}, szSex[8]={0}, szZY[32]={0}, szNJ[32]={0}, szBJ[32]={0};
		rc.SetRect(nLeft, nTop+fAdd, nRight, nTop+2*fAdd);
		rt1.SetRect(nLeft+nTextAdd, rc.top, nLeft+20*xPix, rc.bottom);				//学号
		rt2.SetRect(rt1.right+nTextAdd, rt1.top, rt1.right + 25*xPix, rt1.bottom);	//姓名
		rt3.SetRect(rt2.right+nTextAdd, rt1.top, rt2.right + 10*xPix, rt1.bottom);	//性别
		rt4.SetRect(rt3.right+nTextAdd, rt1.top, rt3.right + 25*xPix, rt1.bottom);	//专业
		rt5.SetRect(rt4.right+nTextAdd, rt1.top, rt4.right + 25*xPix, rt1.bottom);	//年级
		rt6.SetRect(rt5.right+nTextAdd, rt1.top, rc.right, rt1.bottom);				//班级

		int nCountItem = ListView_GetItemCount(hList);
		for(int i=0;i<nItem; i++)
		{
			ListView_GetItemText(hList, i+iStart, 0, szID, 32);
			ListView_GetItemText(hList, i+iStart, 1, szName, 16);
			ListView_GetItemText(hList, i+iStart, 2, szSex, 8);
			ListView_GetItemText(hList, i+iStart, 3, szZY, 32);
			ListView_GetItemText(hList, i+iStart, 4, szNJ, 32);
			ListView_GetItemText(hList, i+iStart, 5, szBJ, 32);
			
			memDC.DrawText(szID, &rt1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			memDC.DrawText(szName, &rt2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			memDC.DrawText(szSex, &rt3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			memDC.DrawText(szZY, &rt4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			memDC.DrawText(szNJ, &rt5,DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			memDC.DrawText(szBJ, &rt6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			//下横线
			memDC.MoveTo(rc.left, rc.bottom);
			memDC.LineTo(rc.right, rc.bottom);
			memDC.MoveTo(rt1.right, rt1.top);
			memDC.LineTo(rt1.right, rt1.bottom);
			memDC.MoveTo(rt2.right, rt1.top);
			memDC.LineTo(rt2.right, rt1.bottom);
			memDC.MoveTo(rt3.right, rt1.top);
			memDC.LineTo(rt3.right, rt1.bottom);
			memDC.MoveTo(rt4.right, rt1.top);
			memDC.LineTo(rt4.right, rt1.bottom);
			memDC.MoveTo(rt5.right, rt1.top);
			memDC.LineTo(rt5.right, rt1.bottom);
//			memDC.MoveTo(rt6.right, rt1.top);
//			memDC.LineTo(rt6.right, rt1.bottom);
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
			rt4.top = rt1.top;
			rt4.bottom = rt1.bottom;
			rt5.top = rt1.top;
			rt5.bottom = rt1.bottom;
			rt6.top = rt1.top;
			rt6.bottom = rt1.bottom;
			
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
