// TABDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HCWORD.h"
#include "TABDlg.h"
#include "PreParent.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// TABDlg dialog


TABDlg::TABDlg(CWnd* pParent /*=NULL*/)
	: CDialog(TABDlg::IDD, pParent)
{ 
	//{{AFX_DATA_INIT(TABDlg)
	m_mosh = 0;
	//}}AFX_DATA_INIT
}


void TABDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(TABDlg)
	DDX_Control(pDX, IDC_SPIN1, m_spin);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Text(pDX, IDC_ED, m_mosh);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(TABDlg, CDialog)
	//{{AFX_MSG_MAP(TABDlg)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, OnItemchangedList1)
	ON_NOTIFY(NM_OUTOFMEMORY, IDC_SPIN1, OnOutofmemorySpin1)
	ON_BN_CLICKED(IDC_MODIFY, OnModify)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_OUT, OnOut)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	ON_BN_CLICKED(IDC_PRINT, OnPrint)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// TABDlg message handlers

BOOL TABDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	int y;
    y=m_spin.SetPos(0);
	m_spin.SetRange(0,7);
    word="";
    pdb=new CDatabase;
	pdb->Open("ODBC;DSN=词库;Trusted_Connection=Yes;");
	m_set=new HY(pdb);
	m_set->Open();
	m_list.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	m_list.InsertColumn(0,"     单词",LVCFMT_CENTER,120);	
    m_list.InsertColumn(1,"     解释",LVCFMT_CENTER,120);
    m_list.InsertColumn(2,"     添加日期",LVCFMT_CENTER,150);
	m_list.InsertColumn(3," 陌生程度",LVCFMT_CENTER,150);
    ShowData();
	return TRUE;  
}

void TABDlg::OnAdd() 
{
	CString strsql,str;
	TIANJIADlg mydlg;
    if(mydlg.DoModal()==IDOK)
	{
		if(mydlg.m_1==""||mydlg.m_3=="")
		{	
			MessageBox("生词项不能为空");
			return;
		}
		else
		{
			try 
			{
				strsql.Format("insert into eh(eg,zw) values('%s','%s')",mydlg.m_1,mydlg.m_3);
				str.Format("insert into shengci(strange,jsh,riqi) values('%s','%s','%s')",mydlg.m_1,mydlg.m_3,Time);
				pdb->ExecuteSQL(strsql);
				pdb->ExecuteSQL(str);
			}
			catch(...)
			{
				AfxMessageBox("单词已经有了！");
				return ; 
			}
		}
		AfxMessageBox("添加成功");
		m_set->Requery();
		ShowData();	
	}		
}

void TABDlg::ShowData()
{ 	
    m_list.SetBkColor(RGB(0,0,0));
	m_list.SetTextBkColor(RGB(185,190,0));
	m_list.SetTextColor(RGB(55,167,0));
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES |
    LVS_EX_ONECLICKACTIVATE);   
	CTime t=CTime::GetCurrentTime();
	Time=t.Format("%Y-%m-%d %H:%M:%S");
	m_list.DeleteAllItems();
    CString str,str1,str2;
	m_set->MoveFirst();
    int i=0;
    while(!m_set->IsEOF())
	{
		 str=m_set->m_eg;
		 str.TrimRight();
		 str1=m_set->m_jsh;
		 str1.TrimRight();
		 str2.Format("%d",m_set->m_mosh);
		 m_list.InsertItem(i,str);
		 m_list.SetItemText(i,1,str1);
		 m_list.SetItemText(i,2,m_set->m_riqi);
		 m_list.SetItemText(i,3,str2);
		 i++;
         m_set->MoveNext();		 
	 } 
}

void TABDlg::OnDelete() 
{
	CString strsql;
	if(word=="")
	{
		MessageBox("请选择要删除的单词！");
		return;
	}
	else if(MessageBox("确定要删除吗？","提示",MB_YESNO)==IDYES)
	{
		strsql.Format("delete from shengci where eg='%s'",word);
		pdb->ExecuteSQL(strsql);
		m_set->Requery();
		ShowData();
	}
}

void TABDlg::OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
    int selectrow=pNMListView->iItem;
    word=m_list.GetItemText(selectrow,0);	
	*pResult = 0;
}

void TABDlg::OnModify() 
{
	UpdateData();
	TIANJIADlg mydlg;	
	CString str;
	if(word=="")
	{
		MessageBox("请选择要修改的单词！");
		return;
	}
	m_set->Close();
	str.Format("select * from shengci where eg='%s'",word);
    m_set->Open(AFX_DB_USE_DEFAULT_TYPE,str);
	mydlg.m_1=word;
	mydlg.m_3=m_set->m_jsh;
	UpdateData(false);
	if(mydlg.DoModal()==IDOK)
	{	 
		m_set->Edit();
		m_set->m_jsh=mydlg.m_3;
		m_set->m_mosh=m_mosh;
		m_set->Update();
		m_set->Requery(); 
        MessageBox("修改成功！");
	}	
	ShowData();	 	
}

void TABDlg::OnOut() 
{
		  CString str,str1,filename;
		  str="单词      解释      陌生程度\r\n";
		  CFile infile; 
		  CFileDialog filedlg(false,"txt",NULL,
			  OFN_HIDEREADONLY,"文本文件(*.txt)|*.txt|");	  
		  if(filedlg.DoModal()==IDOK)
			  filename=filedlg.GetPathName();
		  else
			  return;
		  infile.Open(filename,CFile::modeCreate|CFile::modeWrite);
		  infile.SeekToEnd();
		  { 
			  if(m_set->IsOpen())
				  m_set->Close();
			  m_set->Open();
			  while(!m_set->IsEOF())
			  {
				  m_set->m_eg.TrimRight();
				  m_set->m_jsh.TrimRight();
				  str=str+m_set->m_eg+"   ";
				  str=m_set->m_jsh+"   ";
				  str1.Format("%d",m_set->m_mosh);
				  str+=str1+"\r\n";
				  m_set->MoveNext();
			  }
			  m_set->Close();
			  infile.Write(str,str.GetLength()); 
		  }
		  infile.Close();
		  AfxMessageBox("导出成功！");
}

void TABDlg::OnOutofmemorySpin1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	m_mosh=m_spin.SetPos(3);
	*pResult = 0;
}

void TABDlg::OnPrint() 
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

void TABDlg::DrawInfo(CDC &memDC, PRNINFO PrnInfo)
{    
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

	TCHAR szTitle[] = TEXT("生词本总表");

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

	DOUBLE xPix = (DOUBLE)xP*10/254;	                //每 mm 宽度的像素
	DOUBLE yPix = (DOUBLE)yP*10/254;	                //每 mm 高度的像素
	DOUBLE fAdd = 7*yPix;		                        //每格递增量
	DOUBLE nTop = 25*yPix;		                        //第一页最上线
	int	  iStart = 0;			                        //从第几行开始读取
	DOUBLE nBottom = nTop+B5_ONELINE*fAdd;
	if(nCurPage != 1)
		nTop = 25*yPix-fAdd;	                        //非第一页最上线
	if(nCurPage == 2)
		iStart = B5_ONELINE;
	if(nCurPage>2)
		iStart = B5_ONELINE+(nCurPage - 2)*B5_OTHERLINE;

	DOUBLE nLeft = 20*xPix;			                   //最左线
	DOUBLE nRight = xPix*(B5_W-20);	                   //最右线
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
			nTop = 25*yPix;		                    //第一页最上线
			for(int iTotalPages = 1; iTotalPages<=nMaxPage; iTotalPages++)
			{
				int nCurPage = iTotalPages;
				csRFinality.Format("第 %i 页/共 %i 页", nCurPage, nMaxPage);
				time=CTime::GetCurrentTime();
				csLFinality = time.Format("报表日期:%Y-%m-%d");

				if(nCurPage != 1)
					nTop = 25*yPix-fAdd;	       //非第一页最上线
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

					rt1.SetRect(nLeft, nTop, nLeft+20*xPix, nTop+fAdd);					//编 号
					rt2.SetRect(rt1.right, rt1.top, rt1.right + 25*xPix, rt1.bottom);	//记录时间
					rt3.SetRect(rt2.right, rt1.top, rt2.right + 35*xPix, rt1.bottom);	//收入类型
					rt4.SetRect(rt3.right, rt1.top, rt3.right + 40*xPix, rt1.bottom);	//收入数目(元)
				                                                                    	//消费类型
					rt5.SetRect(rt4.right, rt1.top, rc.right, rt1.bottom);				//消费数目(元)
					memDC.DrawText("生词", &rt1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					memDC.DrawText("音标", &rt2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					memDC.DrawText("解释", &rt3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					memDC.DrawText("记录时间", &rt4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					memDC.DrawText("陌生程度", &rt5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				

					memDC.MoveTo(rt1.right, rt1.top);
					memDC.LineTo(rt1.right, rt1.bottom);
					memDC.MoveTo(rt2.right, rt1.top);
					memDC.LineTo(rt2.right, rt1.bottom);
					memDC.MoveTo(rt3.right, rt1.top);
					memDC.LineTo(rt3.right, rt1.bottom);
					memDC.MoveTo(rt4.right, rt1.top);
					memDC.LineTo(rt4.right, rt1.bottom);
			
					memDC.MoveTo(rc.left, rt1.bottom);
					memDC.LineTo(rc.right, rt1.bottom);

					TCHAR ID[32]={0}, TIME[32]={0}, SRLX[32]={0}, SRSM[32]={0}, XFLX[32]={0}, XFSM[32]={0};
					rc.SetRect(nLeft, nTop+fAdd, nRight, nTop+2*fAdd);
					rt1.SetRect(nLeft+nTextAdd, rc.top, nLeft+20*xPix, rc.bottom);				//编号
					rt2.SetRect(rt1.right+nTextAdd, rt1.top, rt1.right + 25*xPix, rt1.bottom);	//记录时间
					rt3.SetRect(rt2.right+nTextAdd, rt1.top, rt2.right + 35*xPix, rt1.bottom);	//收入类型
					rt4.SetRect(rt3.right+nTextAdd, rt1.top, rt3.right + 40*xPix, rt1.bottom);	//收入数目
				                                                                               	//消费类型
					rt5.SetRect(rt4.right+nTextAdd, rt1.top, rc.right, rt1.bottom);				//消费数目

					int nCountItem = ListView_GetItemCount(hList);
					for(int i=0;i<nItem; i++)
					{
						ListView_GetItemText(hList, i+iStart, 0, ID, 32);
						ListView_GetItemText(hList, i+iStart, 1, TIME, 32);
						ListView_GetItemText(hList, i+iStart, 2, SRLX, 32);
						ListView_GetItemText(hList, i+iStart, 3, SRSM, 32);
						
						ListView_GetItemText(hList, i+iStart, 5, XFSM, 32);
						
						memDC.DrawText(ID, &rt1, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
						memDC.DrawText(TIME, &rt2, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
						memDC.DrawText(SRLX, &rt3, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
						memDC.DrawText(SRSM, &rt4, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
						memDC.DrawText(XFLX, &rt5, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
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

		rt1.SetRect(nLeft, nTop, nLeft+35*xPix, nTop+fAdd);					
		rt2.SetRect(rt1.right, rt1.top, rt1.right + 35*xPix, rt1.bottom);	
		rt3.SetRect(rt2.right, rt1.top, rt2.right + 40*xPix, rt1.bottom);	
		rt4.SetRect(rt3.right, rt1.top, rt3.right + 20*xPix, rt1.bottom);	
	
		rt5.SetRect(rt4.right, rt1.top, rc.right, rt1.bottom);				
		memDC.DrawText("生词", &rt1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		memDC.DrawText("解释", &rt2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		memDC.DrawText("记录时间", &rt3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		memDC.DrawText("陌生程度", &rt4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);


		memDC.MoveTo(rt1.right, rt1.top);
		memDC.LineTo(rt1.right, rt1.bottom);
		memDC.MoveTo(rt2.right, rt1.top);
		memDC.LineTo(rt2.right, rt1.bottom);
		memDC.MoveTo(rt3.right, rt1.top);
		memDC.LineTo(rt3.right, rt1.bottom);

		memDC.MoveTo(rc.left, rt1.bottom);
		memDC.LineTo(rc.right, rt1.bottom);

		TCHAR ID[32]={0}, TIME[32]={0}, SRLX[32]={0}, SRSM[32]={0}, XFLX[32]={0}, XFSM[32]={0};
		rc.SetRect(nLeft, nTop+fAdd, nRight, nTop+2*fAdd);
		rt1.SetRect(nLeft+nTextAdd, rc.top, nLeft+35*xPix, rc.bottom);				
		rt2.SetRect(rt1.right+nTextAdd, rt1.top, rt1.right + 35*xPix, rt1.bottom);	
		rt3.SetRect(rt2.right+nTextAdd, rt1.top, rt2.right + 40*xPix, rt1.bottom);	
		rt4.SetRect(rt3.right+nTextAdd, rt1.top, rt3.right + 20*xPix, rt1.bottom);
		


		int nCountItem = ListView_GetItemCount(hList);
		for(int i=0;i<nItem; i++)
		{
			ListView_GetItemText(hList, i+iStart, 0, ID, 32);
			ListView_GetItemText(hList, i+iStart, 1, TIME, 32);
			ListView_GetItemText(hList, i+iStart, 2, SRLX, 32);
			ListView_GetItemText(hList, i+iStart, 3, SRSM, 32);
			ListView_GetItemText(hList, i+iStart, 4, XFLX, 32);
		
			
			memDC.DrawText(ID, &rt1, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
			memDC.DrawText(TIME, &rt2, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
			memDC.DrawText(SRLX, &rt3, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
			memDC.DrawText(SRSM, &rt4, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
			memDC.DrawText(XFLX, &rt5, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
	
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
			rt4.top = rt1.top;
			rt4.bottom = rt1.bottom;
			rt5.top = rt1.top;
			rt5.bottom = rt1.bottom;
		
			
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


