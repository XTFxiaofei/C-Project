// PAGE1.cpp : implementation file
//

#include "stdafx.h"
#include "LICAI.h"
#include "PAGE1.h"
#include "PreParent.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PAGE1 dialog


PAGE1::PAGE1(CWnd* pParent /*=NULL*/)
	: CDialog(PAGE1::IDD, pParent)
{
	//{{AFX_DATA_INIT(PAGE1)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void PAGE1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PAGE1)
	DDX_Control(pDX, IDC_PRINT, m_PRINT);
	DDX_Control(pDX, IDC_FIND, m_FIND);
	DDX_Control(pDX, IDC_LOOK, m_look);
	DDX_Control(pDX, IDC_SHUAXIN, m_SHUAXIN);
	DDX_Control(pDX, IDC_MODIFY, m_MODIFY);
	DDX_Control(pDX, IDC_DELE, m_DELE);
	DDX_Control(pDX, IDC_ADD, m_ADD);
	DDX_Control(pDX, IDC_LIST1, m_list);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PAGE1, CDialog)
	//{{AFX_MSG_MAP(PAGE1)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, OnItemchangedList1)
	ON_BN_CLICKED(IDC_DELE, OnDele)
	ON_BN_CLICKED(IDC_MODIFY, OnModify)
	ON_BN_CLICKED(IDC_LOOK, OnLook)
	ON_BN_CLICKED(IDC_FIND, OnFind)
	ON_BN_CLICKED(IDC_PRINT, OnPrint)
	ON_BN_CLICKED(IDC_REQUERY, OnRequery)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PAGE1 message handlers

BOOL PAGE1::OnInitDialog() 
{
	CDialog::OnInitDialog();
	pdb=new CDatabase;
	mySet=new LCSet(pdb);
	mySet->Open();
	m_list.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
    m_list.InsertColumn(0,"编号",LVCFMT_CENTER,40);
    m_list.InsertColumn(1,"记录时间",LVCFMT_CENTER,145);
    m_list.InsertColumn(2,"收入类型",LVCFMT_CENTER,120);  
    m_list.InsertColumn(3,"收入数目(元)",LVCFMT_CENTER,100);
    m_list.InsertColumn(4,"消费类型",LVCFMT_CENTER,120);
    m_list.InsertColumn(5,"消费数目(元)",LVCFMT_CENTER,100);
    m_list.InsertColumn(6,"备注信息",LVCFMT_CENTER,150);
	LOADDATA();	
	if(!loginflag)
	{
		m_ADD.EnableWindow(FALSE);
		m_DELE.EnableWindow(FALSE);
		m_MODIFY.EnableWindow(FALSE);
		m_look.EnableWindow(FALSE);
		m_FIND.EnableWindow(FALSE);
		m_PRINT.EnableWindow(FALSE);
	}	
	return TRUE;  	              
}

void PAGE1::OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult) //获得对应列表框信息
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
    int selectrow=pNMListView->iItem;	
	m_id=m_list.GetItemText(selectrow,0);	
	*pResult = 0;
}

void PAGE1::LOADDATA()
{
	mySet->Requery();
	m_list.DeleteAllItems();
	int i=0;
	while(!mySet->IsEOF())
	{
		CString str,str1,str2;                     //因为id,incomenum,costnum等是整型数据所以要转换成字符串型的变量
		str.Format("%d",mySet->m_id);
		str1.Format("%d",mySet->m_incomenum);
		str2.Format("%d",mySet->m_costnum);
		m_list.InsertItem(i,str);
		m_list.SetItemText(i,1,mySet->m_time);
		m_list.SetItemText(i,2,mySet->m_incometype);
		m_list.SetItemText(i,3,str1);
		m_list.SetItemText(i,4,mySet->m_costtype);
		m_list.SetItemText(i,5,str2);
		m_list.SetItemText(i,6,mySet->m_about);
		i++;
		mySet->MoveNext();
	}
}

void PAGE1::OnAdd() //添加收支信息
{
	addflag=true;
	int i=0;
	add mydlg;
	if(mySet->IsOpen())
		mySet->Close();
	mySet->Open();
    while(!mySet->IsEOF())
	{
		mySet->MoveNext();
		i++;
	}
	if(i==0)
	{
		mydlg.m_id=1;
	} 
	else
		mydlg.m_id=mySet->m_id+1;   
	if(mydlg.DoModal()==IDOK)
	{
		    mySet->AddNew();
			mySet->m_id=mydlg.m_id;
			mySet->m_time=mydlg.m_time;
		    mySet->m_incomenum=mydlg.m_incomenum;
		    mySet->m_incometype=mydlg.incometype;
		    mySet->m_costtype=mydlg.costtype;
		    mySet->m_costnum=mydlg.m_costnum;
		    mySet->m_about=mydlg.m_about;
		    mySet->Update();
		    mySet->Requery();
		    UpdateData(false);
			OnRequery();
			MessageBox("记录添加成功!","提示",MB_OK|MB_ICONINFORMATION);
			COleDateTime oleDt=COleDateTime::GetCurrentTime();//获取本地的当前时间
			CString strFileName=oleDt.Format("%Y年%m月%d日 %H时%M分%S秒");
			CString strTmp=strFileName+"\r\n管理员"+ID+"添加记录成功\r\n";
			CStdioFile file(logFileName,CFile::modeNoTruncate|CFile::modeWrite);
			file.SeekToEnd();//先定位到文件尾部
			file.WriteString(strTmp);
			file.Close();
	}
}

void PAGE1::OnDele()   //删除收支信息
{   
	CString str,str1;
    int i=0;
    if(mySet->IsOpen())
		mySet->Close();
	mySet->Open();
	if(m_id=="")
	{
		MessageBox("请选择需要删除的记录","提示",MB_OK|MB_ICONINFORMATION);
		return;
	}
	if(MessageBox("确定删除此记录吗?","提示",MB_YESNO|MB_ICONINFORMATION)==IDYES)
	{	
		str.Format("delete from licai where id=%s",m_id);
		pdb->ExecuteSQL(str);
		mySet->Requery();
		LOADDATA();
		MessageBox("记录删除成功!","提示",MB_OK|MB_ICONINFORMATION);
		m_id="";
	}	
}

void PAGE1::OnModify() //修改收支信息
{
	addflag=false;
	CString str;
	if(m_id=="")
		MessageBox("请选择所需修改的记录","提示",MB_OK|MB_ICONINFORMATION);
	else
	{
		mySet->MoveFirst();
		while(!mySet->IsEOF())
		{   
			str.Format("%d",mySet->m_id);
			if(str==m_id)
				break;
			else
			{
				mySet->MoveNext();
			}	
		}
		add mydlg;
		mydlg.m_id=mySet->m_id;
		mydlg.m_time=mySet->m_time;
		mydlg.incometype=mySet->m_incometype;
		mydlg.costtype=mySet->m_costtype;
		mydlg.m_incomenum=mySet->m_incomenum;
		mydlg.m_costnum=mySet->m_costnum;
		mydlg.m_about=mySet->m_about;
		UpdateData(false);
		if(mydlg.DoModal()==IDOK)
		{ 	
			mySet->Edit();
			mySet->m_incomenum=mydlg.m_incomenum;
			mySet->m_incometype=mydlg.incometype;
			mySet->m_costtype=mydlg.costtype;
			mySet->m_costnum=mydlg.m_costnum;
			mySet->m_about=mydlg.m_about;
			mySet->Update();
			UpdateData(false);
			LOADDATA();
			MessageBox("记录修改成功!","家庭个人理财系统",MB_OK|MB_ICONINFORMATION);
			COleDateTime oleDt=COleDateTime::GetCurrentTime();//获取本地的当前时间
			CString strFileName=oleDt.Format("%Y年%m月%d日 %H时%M分%S秒"); 
			CString strTmp=strFileName+"\r\n\n管理员 "+ID+" 修改 "+m_id+" 号记录    记录修改成功\r\n\n\n\n";
			CStdioFile file(logFileName,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);
			file.SeekToEnd();//先定位到文件尾部
			file.WriteString(strTmp);
			file.Close();
			m_id="";
		}		
	}		
}

void PAGE1::OnLook() 
{
	BAOBIAODLG mydlg;
	mydlg.DoModal();
}

void PAGE1::OnFind() 
{
	FIND mydlg;
	if(mydlg.DoModal()==IDOK)
	{
		CString str,time="time";
	    str.Format("%s like '%%%s%%'",time,mydlg.time);
        mySet->m_strFilter=str;
        mySet->Requery();
        LOADDATA();
	}
}

void PAGE1::OnPrint() 
{
	if(m_list.GetItemCount()<= 0)
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
void PAGE1::DrawInfo(CDC &memDC, PRNINFO PrnInfo)
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

	TCHAR szTitle[] = TEXT("收支信息详细报表");

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

					rt1.SetRect(nLeft, nTop, nLeft+10*xPix, nTop+fAdd);					//编 号
					rt2.SetRect(rt1.right, rt1.top, rt1.right + 40*xPix, rt1.bottom);	//记录时间
					rt3.SetRect(rt2.right, rt1.top, rt2.right + 25*xPix, rt1.bottom);	//收入类型
					rt4.SetRect(rt3.right, rt1.top, rt3.right + 25*xPix, rt1.bottom);	//收入数目(元)
					rt5.SetRect(rt4.right, rt1.top, rt4.right + 25*xPix, rt1.bottom);	//消费类型
					rt6.SetRect(rt5.right, rt1.top, rc.right, rt1.bottom);				//消费数目(元)
					memDC.DrawText("编 号", &rt1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					memDC.DrawText("记录时间", &rt2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					memDC.DrawText("收入类型", &rt3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					memDC.DrawText("收入数目(元)", &rt4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					memDC.DrawText("消费类型", &rt5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					memDC.DrawText("消费数目(元)", &rt6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

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

					TCHAR ID[32]={0}, TIME[32]={0}, SRLX[32]={0}, SRSM[32]={0}, XFLX[32]={0}, XFSM[32]={0};
					rc.SetRect(nLeft, nTop+fAdd, nRight, nTop+2*fAdd);
					rt1.SetRect(nLeft+nTextAdd, rc.top, nLeft+10*xPix, rc.bottom);				//编号
					rt2.SetRect(rt1.right+nTextAdd, rt1.top, rt1.right + 40*xPix, rt1.bottom);	//记录时间
					rt3.SetRect(rt2.right+nTextAdd, rt1.top, rt2.right + 25*xPix, rt1.bottom);	//收入类型
					rt4.SetRect(rt3.right+nTextAdd, rt1.top, rt3.right + 25*xPix, rt1.bottom);	//收入数目
					rt5.SetRect(rt4.right+nTextAdd, rt1.top, rt4.right + 25*xPix, rt1.bottom);	//消费类型
					rt6.SetRect(rt5.right+nTextAdd, rt1.top, rc.right, rt1.bottom);				//消费数目

					int nCountItem = ListView_GetItemCount(hList);
					for(int i=0;i<nItem; i++)
					{
						ListView_GetItemText(hList, i+iStart, 0, ID, 32);
						ListView_GetItemText(hList, i+iStart, 1, TIME, 32);
						ListView_GetItemText(hList, i+iStart, 2, SRLX, 32);
						ListView_GetItemText(hList, i+iStart, 3, SRSM, 32);
						ListView_GetItemText(hList, i+iStart, 4, XFLX, 32);
						ListView_GetItemText(hList, i+iStart, 5, XFSM, 32);
						
						memDC.DrawText(ID, &rt1, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
						memDC.DrawText(TIME, &rt2, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
						memDC.DrawText(SRLX, &rt3, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
						memDC.DrawText(SRSM, &rt4, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
						memDC.DrawText(XFLX, &rt5, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
						memDC.DrawText(XFSM, &rt6, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
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
				}
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

		rt1.SetRect(nLeft, nTop, nLeft+10*xPix, nTop+fAdd);					//编 号
		rt2.SetRect(rt1.right, rt1.top, rt1.right + 38*xPix, rt1.bottom);	//记录时间
		rt3.SetRect(rt2.right, rt1.top, rt2.right + 22*xPix, rt1.bottom);	//收入类型
		rt4.SetRect(rt3.right, rt1.top, rt3.right + 22*xPix, rt1.bottom);	//收入数目(元)
		rt5.SetRect(rt4.right, rt1.top, rt4.right + 29*xPix, rt1.bottom);	//消费类型
		rt6.SetRect(rt5.right, rt1.top, rc.right, rt1.bottom);				//消费数目(元)
		memDC.DrawText("编 号", &rt1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		memDC.DrawText("记录时间", &rt2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		memDC.DrawText("收入类型", &rt3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		memDC.DrawText("收入数目(元)", &rt4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		memDC.DrawText("消费类型", &rt5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		memDC.DrawText("消费数目(元)", &rt6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

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

		TCHAR ID[32]={0}, TIME[32]={0}, SRLX[32]={0}, SRSM[32]={0}, XFLX[32]={0}, XFSM[32]={0};
		rc.SetRect(nLeft, nTop+fAdd, nRight, nTop+2*fAdd);
		rt1.SetRect(nLeft+nTextAdd, rc.top, nLeft+10*xPix, rc.bottom);				//编 号
		rt2.SetRect(rt1.right+nTextAdd, rt1.top, rt1.right + 38*xPix, rt1.bottom);	//记录时间
		rt3.SetRect(rt2.right+nTextAdd, rt1.top, rt2.right + 22*xPix, rt1.bottom);	//收入类型
		rt4.SetRect(rt3.right+nTextAdd, rt1.top, rt3.right + 22*xPix, rt1.bottom);	//收入数目(元)
		rt5.SetRect(rt4.right+nTextAdd, rt1.top, rt4.right + 29*xPix, rt1.bottom);	//消费类型
		rt6.SetRect(rt5.right+nTextAdd, rt1.top, rc.right, rt1.bottom);				//消费数目(元)

		int nCountItem = ListView_GetItemCount(hList);
		for(int i=0;i<nItem; i++)
		{
			ListView_GetItemText(hList, i+iStart, 0, ID, 32);
			ListView_GetItemText(hList, i+iStart, 1, TIME, 32);
			ListView_GetItemText(hList, i+iStart, 2, SRLX, 32);
			ListView_GetItemText(hList, i+iStart, 3, SRSM, 32);
			ListView_GetItemText(hList, i+iStart, 4, XFLX, 32);
			ListView_GetItemText(hList, i+iStart, 5, XFSM, 32);
			
			memDC.DrawText(ID, &rt1, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
			memDC.DrawText(TIME, &rt2, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
			memDC.DrawText(SRLX, &rt3, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
			memDC.DrawText(SRSM, &rt4, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
			memDC.DrawText(XFLX, &rt5, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
			memDC.DrawText(XFSM, &rt6, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
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


void PAGE1::OnRequery() 
{
	mySet->m_strFilter="";
	mySet->Requery();
	LOADDATA();
	
}
