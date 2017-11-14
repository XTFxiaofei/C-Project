// ZHPCDLG.cpp : implementation file
//

#include "stdafx.h"
#include "HCCP.h"
#include "ZHPCDLG.h"
#include "ADOConn.h"
#include "PreParent.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ZHPCDLG dialog


ZHPCDLG::ZHPCDLG(CWnd* pParent /*=NULL*/)
	: CDialog(ZHPCDLG::IDD, pParent)
{
	xfzh=xkzh=0;
	flg=true;
	//{{AFX_DATA_INIT(ZHPCDLG)
	m_zhiyu = 0.7f;
	m_tiyu = 0.1f;
	m_fujia = 0.1f;
	m_deyu = 0.1f;
	//}}AFX_DATA_INIT
}


void ZHPCDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ZHPCDLG)
	DDX_Control(pDX, IDC_LIST3, m_list3);
	DDX_Text(pDX, IDC_ZHIYU, m_zhiyu);
	DDX_Text(pDX, IDC_TIYU, m_tiyu);
	DDX_Text(pDX, IDC_FUJIA, m_fujia);
	DDX_Text(pDX, IDC_DEYU, m_deyu);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ZHPCDLG, CDialog)
	//{{AFX_MSG_MAP(ZHPCDLG)
	ON_BN_CLICKED(IDC_JISUAN, OnJisuan)
	ON_BN_CLICKED(IDC_ZPX, OnZpx)
	ON_BN_CLICKED(IDC_PRINT, OnPrint)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ZHPCDLG message handlers

BOOL ZHPCDLG::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CString str,str1;
	_RecordsetPtr rcp;
	_variant_t cno;
	str.Format("%s班学生综合测评结果!",str1212);
	SetWindowText(str);  //设置对话框标题	
	m_list3.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);  //设置list控件显示风格  
	m_list3.InsertColumn(0,"学生学号",LVCFMT_CENTER,106);  //添加列
	m_list3.InsertColumn(1,"学生姓名",LVCFMT_CENTER,106);
    m_list3.InsertColumn(2,"智育成绩",LVCFMT_CENTER,106);
    m_list3.InsertColumn(3,"德育成绩",LVCFMT_CENTER,106);
	m_list3.InsertColumn(4,"体育成绩",LVCFMT_CENTER,106);
	m_list3.InsertColumn(5,"附加分数",LVCFMT_CENTER,106);
	m_list3.InsertColumn(6,"总成绩",LVCFMT_CENTER,106);
	m_list3.InsertColumn(7,"名次",LVCFMT_CENTER,106);
	str1.Format("select * from class");  //获取class表中所有内容
	rcp=myado.GetRecordSet((_bstr_t)str1);  //获取记录集
	while(!rcp->adoEOF)
	{
		cno=rcp->GetCollect("cgrade");  //获取当前记录学分
		float cg=atof((_bstr_t)cno);  //将String强制转换成double型
		xfzh+=cg;  //计算学分总和
		rcp->MoveNext();
	}	
	ShengCh();	
	return TRUE;  
}

/*------------------------------生成list列表内容----------------------------*/

void ZHPCDLG::ShengCh()
{
	CString str,str1,str2;
	_bstr_t sQL;
	_RecordsetPtr rcp,rcp0,rcp1,rcp2;
	_variant_t sno,sname,cno,sgrade,cgrade;
	int k=0;
	str.Format("select * from student where sclass='%s'",str1212);//获取选择班级下所有成员记录
	sQL=(_bstr_t)str;
	rcp=myado.GetRecordSet(sQL);  //获取记录集
	while(!rcp->adoEOF)
	{
		sno=rcp->GetCollect("sno");  //获取学号
		sname=rcp->GetCollect("sname");  //获取姓名
		CString num=(LPCTSTR)(_bstr_t)sno;
		CString name=(LPCTSTR)(_bstr_t)sname;
		num.TrimRight();
		str1.Format("select * from grade where sno='%s'",num);  //通过学号查询成绩表
		rcp1=myado.GetRecordSet((_bstr_t)str1);  //获取学生成绩记录集
		while(!rcp1->adoEOF)
		{
			cno=rcp1->GetCollect("cno");  //获取课程号
			sgrade=rcp1->GetCollect("sgrade");  //获取该课程下学生成绩
			CString cnu=(LPCTSTR)(_bstr_t)cno;
			float sgrad=atof((LPCTSTR)(_bstr_t)sgrade);
			cnu.TrimRight();
			if(cnu=="009")
				deyu=sgrad;
			else if(cnu=="010")
				tiyu=sgrad;
			else if(cnu=="011")
				fujia=sgrad;
			str2.Format("select * from class where cno='%s'",cnu);  //通过课程号获取该课程学分
			rcp2=myado.GetRecordSet((_bstr_t)str2);
			cgrade=rcp2->GetCollect("cgrade");
			float cgrad=atof((LPCTSTR)(_bstr_t)cgrade);
			xkzh+=sgrad*cgrad;  //计算学科总和
			rcp1->MoveNext();
		}		
		xkzh=xkzh/xfzh;  //计算智育成绩总评结果
		CString jieg,sdeyu,stiyu,sfujia;
		jieg.Format("%f",xkzh);
		sdeyu.Format("%f",deyu);
		stiyu.Format("%f",tiyu);
		sfujia.Format("%f",fujia);	
		m_list3.InsertItem(k,num);  //将查询结果添加到list控件中
		m_list3.SetItemText(k,1,name);
		m_list3.SetItemText(k,2,jieg);
		m_list3.SetItemText(k,3,sdeyu);
		m_list3.SetItemText(k,4,stiyu);
		m_list3.SetItemText(k,5,sfujia);
		rcp->MoveNext();
		k++;
	}
	xkzh=0;	
}

/*------------------------------计算综合测评结果----------------------------*/

void ZHPCDLG::OnJisuan() 
{
	UpdateData();
	float zong;
	flg=false;
	_bstr_t sqlstr2,sqlstr3;
	sqlstr2="create table test (sno char(10),sname text,illgrade float,goodgrade float,sportgrade float,addgrade float,total float CONSTRAINT PK_sno PRIMARY KEY (sno))";
	//创建临时表
	try
	{  
        sqlstr3="if exists(select * from sysobjects where name='test') drop table test" ;  //若数据库中已存在该表则删除原表
        myado.ExecuteSQL(sqlstr3);  //执行删除表操作
        myado.ExecuteSQL(sqlstr2);  //执行创建临时表操作
	}
	catch(...)  //获取异常状态
	{
	 MessageBox("创建失败!");
	}
	zong=m_zhiyu+m_deyu+m_tiyu+m_fujia;  //各项成绩所占总分比例为1
	if(m_zhiyu<1&&m_deyu<1&&m_tiyu<1&&m_fujia<1)
	{
		if(zong==1)
		{
			m_list3.DeleteAllItems();  //删除list控件内所有内容
			CString str,str1,str2;
			_bstr_t sQL;
			_RecordsetPtr rcp,rcp0,rcp1,rcp2;
			_variant_t sno,sname,cno,sgrade,cgrade;
			int k=0;
			str.Format("select * from student where sclass='%s'",str1212);  //获取选择班级下所有成员记录
			sQL=(_bstr_t)str;
			rcp=myado.GetRecordSet(sQL);  //获取记录集
			while(!rcp->adoEOF)
			{
				sno=rcp->GetCollect("sno");  //获取学号
				sname=rcp->GetCollect("sname");  //获取姓名
				CString num=(LPCTSTR)(_bstr_t)sno;
				CString name=(LPCTSTR)(_bstr_t)sname;
				num.TrimRight();
				str1.Format("select * from grade where sno='%s'",num);  //通过学号查询成绩表
				rcp1=myado.GetRecordSet((_bstr_t)str1);  //获取学生成绩记录集
				while(!rcp1->adoEOF)
				{
					cno=rcp1->GetCollect("cno");  //获取课程号
					sgrade=rcp1->GetCollect("sgrade");  //获取该课程下学生成绩
					CString cnu=(LPCTSTR)(_bstr_t)cno;
					float sgrad=atof((LPCTSTR)(_bstr_t)sgrade);
					cnu.TrimRight();
					if(cnu=="009")
						deyu=sgrad;
					else if(cnu=="010")
						tiyu=sgrad;
					else if(cnu=="011")
						fujia=sgrad;
					str2.Format("select * from class where cno='%s'",cnu);  //通过课程号获取该课程学分
					rcp2=myado.GetRecordSet((_bstr_t)str2);
					cgrade=rcp2->GetCollect("cgrade");
					float cgrad=atof((LPCTSTR)(_bstr_t)cgrade);
					xkzh+=sgrad*cgrad;  //计算学科总和
					rcp1->MoveNext();
				}		
				xkzh=xkzh/xfzh;
				
				CString jieg,sdeyu,stiyu,sfujia,szcj;
				jieg.Format("%f",xkzh);
				sdeyu.Format("%f",deyu);
				stiyu.Format("%f",tiyu);
				sfujia.Format("%f",fujia);	
				zcj=xkzh*m_zhiyu+deyu*m_deyu+tiyu*m_tiyu+fujia*m_fujia;  //计算综合测评总成绩
				szcj.Format("%f",zcj);
				m_list3.InsertItem(k,num);
				m_list3.SetItemText(k,1,name);
				m_list3.SetItemText(k,2,jieg);
				m_list3.SetItemText(k,3,sdeyu);
				m_list3.SetItemText(k,4,stiyu);
				m_list3.SetItemText(k,5,sfujia);
				m_list3.SetItemText(k,6,szcj);
				rcp->MoveNext();
				k++;
				CString sqlstr;
				name.TrimRight();
				sqlstr.Format("insert into test values('%s','%s','%f','%f','%f','%f','%f')",num,name,xkzh,deyu,tiyu,fujia,zcj);
				//将所有内容添加到临时表中
				myado.ExecuteSQL((_bstr_t)sqlstr);
			}
			xkzh=0;
		}
		else
		{
			MessageBox("各成绩所占比例总和不为1,请重新输入!!");
		}
	}
	else
	{
		MessageBox("各成绩所占比例不能大于1,请重新输入!!");
	}
}

/*------------------------------按总评排序----------------------------*/

void ZHPCDLG::OnZpx() 
{
	if(flg==false)
	{
		m_list3.DeleteAllItems();  //清空list列表内容
		_bstr_t sqlstr;int k=0,n=1;
		_RecordsetPtr ptr;
		_variant_t sno,sname,tzhiyu,tdeyu,ttiyu,tfujia,tzcj;
		sqlstr="select * from test order by total DESC";  //以总成绩为依据按降序排列
		ptr=myado.GetRecordSet(sqlstr);
		while(!ptr->adoEOF)  //通过循环记录集指针将表内容显示在list控件上
		{
			sno=ptr->GetCollect("sno");
			sname=ptr->GetCollect("sname");
			tzhiyu=ptr->GetCollect("illgrade");
			tdeyu=ptr->GetCollect("goodgrade");
			ttiyu=ptr->GetCollect("sportgrade");
			tfujia=ptr->GetCollect("addgrade");
			tzcj=ptr->GetCollect("total");
			
			CString snu=(LPCTSTR)(_bstr_t)sno;
			CString name=(LPCTSTR)(_bstr_t)sname;
			CString zhiyu=(LPCTSTR)(_bstr_t)tzhiyu;
			CString deyu=(LPCTSTR)(_bstr_t)tdeyu;
			CString tiyu=(LPCTSTR)(_bstr_t)ttiyu;
			CString fujia=(LPCTSTR)(_bstr_t)tfujia;
			CString zcj=(LPCTSTR)(_bstr_t)tzcj;
			CString mc;
			mc.Format("第%d名",n);
			
			m_list3.InsertItem(k,snu);
			m_list3.SetItemText(k,1,name);
			m_list3.SetItemText(k,2,zhiyu);
			m_list3.SetItemText(k,3,deyu);
			m_list3.SetItemText(k,4,tiyu);
			m_list3.SetItemText(k,5,fujia);
			m_list3.SetItemText(k,6,zcj);
			m_list3.SetItemText(k,7,mc);
			ptr->MoveNext();
			k++;
			n++;
			
		}
	}
	else
	{
		MessageBox("请先计算总成绩!!");
	}
	
}

void ZHPCDLG::OnPrint() 
{
	if(m_list3.GetItemCount()<= 0)
	return;
	PRNINFO PrnInfo = {0};
	PrnInfo.hListView = m_list3.m_hWnd;
	PrnInfo.hWnd = this->m_hWnd;
	PrnInfo.IsPrint = FALSE;
	PrnInfo.nCurPage = 1;
	PrnInfo.nMaxLine = m_list3.GetItemCount();
	CPreParent DlgPreView;
	DlgPreView.SetCallBackFun(DrawInfo, PrnInfo);
	DlgPreView.DoModal();
}

void ZHPCDLG::DrawInfo(CDC &memDC, PRNINFO PrnInfo)
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

	TCHAR szTitle[] = TEXT("学生综合测评结果表");

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
			::MessageBox(hWnd, "连接到打印机失败!", "错误", MB_ICONSTOP);
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

		rt1.SetRect(nLeft, nTop, nLeft+18*xPix, nTop+fAdd);					
		rt2.SetRect(rt1.right, rt1.top, rt1.right + 18*xPix, rt1.bottom);
		rt3.SetRect(rt2.right, rt1.top, rt2.right + 18*xPix, rt1.bottom);
		rt4.SetRect(rt3.right, rt1.top, rt3.right + 18*xPix, rt1.bottom);
		rt5.SetRect(rt4.right, rt1.top, rt4.right + 18*xPix, rt1.bottom);
		rt6.SetRect(rt5.right, rt1.top, rt5.right + 18*xPix, rt1.bottom);
		rt7.SetRect(rt6.right, rt1.top, rt6.right + 18*xPix, rt1.bottom);
		rt8.SetRect(rt7.right, rt1.top, rc.right, rt1.bottom);				
	
		memDC.DrawText("学生学号", &rt1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		memDC.DrawText("学生姓名", &rt2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		memDC.DrawText("智育成绩", &rt3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		memDC.DrawText("德育成绩", &rt4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		memDC.DrawText("体育成绩", &rt5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		memDC.DrawText("附加分数", &rt6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		memDC.DrawText("总成绩", &rt7, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		memDC.DrawText("名次", &rt8, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
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
		memDC.MoveTo(rt6.right, rt1.top);
		memDC.LineTo(rt6.right, rt1.bottom);
		memDC.MoveTo(rt7.right, rt1.top);
		memDC.LineTo(rt7.right, rt1.bottom);
		memDC.MoveTo(rc.left, rt1.bottom);
		memDC.LineTo(rc.right, rt1.bottom);

		TCHAR CID[32]={0}, SName[32]={0}, GName[32]={0},FID[32]={0}, FName[32]={0}, EName[32]={0},HName[32]={0},NName[32]={0};
		rc.SetRect(nLeft, nTop+fAdd, nRight, nTop+2*fAdd);
		rt1.SetRect(nLeft+nTextAdd, rc.top, nLeft+18*xPix, rc.bottom);									
		rt2.SetRect(rt1.right, rt1.top, rt1.right + 18*xPix, rt1.bottom);
		rt3.SetRect(rt2.right, rt1.top, rt2.right + 18*xPix, rt1.bottom);
		rt4.SetRect(rt3.right, rt1.top, rt3.right + 18*xPix, rt1.bottom);
		rt5.SetRect(rt4.right, rt1.top, rt4.right + 18*xPix, rt1.bottom);
		rt6.SetRect(rt5.right, rt1.top, rt5.right + 18*xPix, rt1.bottom);
		rt7.SetRect(rt6.right, rt1.top, rt6.right + 18*xPix, rt1.bottom);
		rt8.SetRect(rt7.right, rt1.top, rc.right, rt1.bottom);	
		int nCountItem = ListView_GetItemCount(hList);
		for(int i=0;i<nItem; i++)
		{
			ListView_GetItemText(hList, i+iStart, 0, CID, 32);
			ListView_GetItemText(hList, i+iStart, 1, SName, 16);
			ListView_GetItemText(hList, i+iStart, 2, GName, 16);
			ListView_GetItemText(hList, i+iStart, 3, FID, 32);
			ListView_GetItemText(hList, i+iStart, 4, FName, 16);
			ListView_GetItemText(hList, i+iStart, 5, EName, 16);
			ListView_GetItemText(hList, i+iStart, 6, HName, 32);
			ListView_GetItemText(hList, i+iStart, 7, NName, 32);
			
			memDC.DrawText(CID, &rt1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			memDC.DrawText(SName, &rt2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			memDC.DrawText(GName, &rt3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			memDC.DrawText(FID, &rt4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			memDC.DrawText(FName, &rt5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			memDC.DrawText(EName, &rt6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			memDC.DrawText(HName, &rt7, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			memDC.DrawText(NName, &rt8, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
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
			memDC.MoveTo(rt6.right, rt1.top);
			memDC.LineTo(rt6.right, rt1.bottom);
			memDC.MoveTo(rt7.right, rt1.top);
			memDC.LineTo(rt7.right, rt1.bottom);
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
			rt7.top = rt1.top;
			rt7.bottom = rt1.bottom;
			rt8.top = rt1.top;
			rt8.bottom = rt1.bottom;
			
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