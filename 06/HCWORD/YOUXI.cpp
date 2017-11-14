// YOUXI.cpp : implementation file
//

#include "stdafx.h"
#include "HCWORD.h"
#include "YOUXI.h"
//#include "ASW.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// YOUXI dialog


YOUXI::YOUXI(CWnd* pParent /*=NULL*/)
	: CDialog(YOUXI::IDD, pParent)
{
	//{{AFX_DATA_INIT(YOUXI)
	m_result = _T("");
	m_test1 = _T("");
	m_test = _T("");
	//}}AFX_DATA_INIT
}


void YOUXI::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(YOUXI)
	DDX_Control(pDX, IDC_BUTTON26, m_26);
	DDX_Control(pDX, IDC_BUTTON25, m_25);
	DDX_Control(pDX, IDC_BUTTON24, m_24);
	DDX_Control(pDX, IDC_BUTTON23, m_23);
	DDX_Control(pDX, IDC_BUTTON22, m_22);
	DDX_Control(pDX, IDC_BUTTON21, m_21);
	DDX_Control(pDX, IDC_BUTTON20, m_20);
	DDX_Control(pDX, IDC_BUTTON19, m_19);
	DDX_Control(pDX, IDC_BUTTON18, m_18);
	DDX_Control(pDX, IDC_BUTTON17, m_17);
	DDX_Control(pDX, IDC_BUTTON16, m_16);
	DDX_Control(pDX, IDC_BUTTON15, m_15);
	DDX_Control(pDX, IDC_BUTTON14, m_14);
	DDX_Control(pDX, IDC_BUTTON13, m_13);
	DDX_Control(pDX, IDC_BUTTON12, m_12);
	DDX_Control(pDX, IDC_BUTTON11, m_11);
	DDX_Control(pDX, IDC_BUTTON10, m_10);
	DDX_Control(pDX, IDC_BUTTON9, m_9);
	DDX_Control(pDX, IDC_BUTTON8, m_8);
	DDX_Control(pDX, IDC_BUTTON7, m_7);
	DDX_Control(pDX, IDC_BUTTON2, m_2);
	DDX_Control(pDX, IDC_BUTTON6, m_6);
	DDX_Control(pDX, IDC_BUTTON5, m_5);
	DDX_Control(pDX, IDC_BUTTON4, m_4);
	DDX_Control(pDX, IDC_BUTTON3, m_3);
	DDX_Control(pDX, IDC_BUTTON1, m_1);
	DDX_Text(pDX, IDC_EDIT1, m_result);
	DDX_Text(pDX, IDC_EDIT7, m_test1);
	DDX_Text(pDX, IDC_EDIT6, m_test);
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_EDIT1, m_resultControl);
	DDX_Control(pDX, IDC_EDIT6, m_resultControl1);
	DDX_Control(pDX, IDC_EDIT7, m_resultControl2);

}


BEGIN_MESSAGE_MAP(YOUXI, CDialog)
ON_COMMAND_RANGE(IDC_BUTTON1,IDC_BUTTON26,OnNumberKey)
	//{{AFX_MSG_MAP(YOUXI)
	ON_BN_CLICKED(IDC_BUTTON27, OnButton27)
	ON_BN_CLICKED(IDC_BUTTON29, OnButton29)
	ON_BN_CLICKED(IDC_BUTTON30, OnButton30)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// YOUXI message handlers

BOOL YOUXI::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CString name="猜词游戏";
	this->SetWindowText(name); 

	j=0;

	CString result,result1,result2;
	result.Format("%s",m_result);
	m_resultControl.SetFontSize(27);
	m_resultControl.SetTextColor(RGB(0,0,255));
    m_resultControl.SetBkColor(RGB(255,255,255));
	m_resultControl.SetFontBold(TRUE);
	m_resultControl.SetText(result);
	
	result1.Format("%s",m_test);
	m_resultControl1.SetFontSize(15);
	m_resultControl1.SetTextColor(RGB(0,0,255));
    m_resultControl1.SetBkColor(RGB(255,255,255));
	m_resultControl1.SetFontBold(TRUE);
	m_resultControl1.SetText(result1);
	
	result2.Format("%s",m_test1);
	m_resultControl2.SetFontSize(27);
	m_resultControl2.SetTextColor(RGB(0,0,255));
    m_resultControl2.SetBkColor(RGB(255,255,255));
	m_resultControl2.SetFontBold(TRUE);
	m_resultControl2.SetText(result2);
   // m_test.rep
    pdb=new CDatabase;
    pdb->Open("ODBC;DSN=词库;Trusted_Connection=Yes;");
    m_pset=new ASW(pdb);
	ddd();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
 void YOUXI::OnNumberKey(UINT nID)
 {
	 CString t;
 	switch(nID)
	{ 
	case  IDC_BUTTON1: {n="a";m_result +=n;t=danci[j];                //当点击按钮a，看是否与单词匹配             
					   if(t=="a")
					          j++;
					   else {UpdateData(false);MessageBox("错误");m_result="";j=0;MessageBox("请重新输入");UpdateData(false);}
					   if(j==mn)
					   {
					   m_test1=danci;UpdateData(false);MessageBox("正确");OnButton29();
					   }
					   } break;
	case  IDC_BUTTON2: {n="b";m_result +=n;t=danci[j];
					   if(t=="b")
					          j++;
					   else {UpdateData(false);MessageBox("错误");m_result="";j=0;MessageBox("请重新输入");UpdateData(false);}
					   if(j==mn)
					   {
					   m_test1=danci;UpdateData(false);MessageBox("正确");OnButton29();
					   }
					   } break;
	case  IDC_BUTTON3: {n="c";m_result +=n;t=danci[j];
					   if(t=="c")
					          j++;
					   else {UpdateData(false);MessageBox("错误");m_result="";j=0;MessageBox("请重新输入");UpdateData(false);}
					   if(j==mn)
					   {
					   m_test1=danci;UpdateData(false);MessageBox("正确");OnButton29();
					   }
					   } break;
	case  IDC_BUTTON4: {n="d";m_result +=n;t=danci[j];
					   if(t=="d")
					          j++;
					   else {UpdateData(false);MessageBox("错误");m_result="";j=0;MessageBox("请重新输入");UpdateData(false);}
					   if(j==mn)
					   {
					   m_test1=danci;UpdateData(false);MessageBox("正确");OnButton29();
					   }
					   } break;
	case  IDC_BUTTON5: {n="e";m_result +=n;t=danci[j];
					   if(t=="e")
					          j++;
					   else {UpdateData(false);MessageBox("错误");m_result="";j=0;MessageBox("请重新输入");UpdateData(false);}
					   if(j==mn)
					   {
					   m_test1=danci;UpdateData(false);MessageBox("正确");OnButton29();
					   }
					   } break;
	case  IDC_BUTTON6: {n="f";m_result +=n;t=danci[j];
					   if(t=="f")
					          j++;
					   else {UpdateData(false);MessageBox("错误");m_result="";j=0;MessageBox("请重新输入");UpdateData(false);}
					   if(j==mn)
					   {
					   m_test1=danci;UpdateData(false);MessageBox("正确");OnButton29();
					   }
					   } break;

	case  IDC_BUTTON7: {n="g";m_result +=n;t=danci[j];
					   if(t=="g")
					          j++;
					   else {UpdateData(false);MessageBox("错误");m_result="";j=0;MessageBox("请重新输入");UpdateData(false);}
                       if(j==mn)
					   {
					   m_test1=danci;UpdateData(false);MessageBox("正确");OnButton29();
					   }
					   } break;
    case  IDC_BUTTON8: {n="h";m_result +=n;t=danci[j];
					   if(t=="h")
					          j++;
					   else {UpdateData(false);MessageBox("错误");m_result="";j=0;MessageBox("请重新输入");UpdateData(false);}
					   if(j==mn)
					   {
					   m_test1=danci;UpdateData(false);MessageBox("正确");OnButton29();
					   }
					   } break;
	case  IDC_BUTTON9: {n="i";m_result +=n;t=danci[j];
					   if(t=="i")
					          j++;
					   else {UpdateData(false);MessageBox("错误");m_result="";j=0;MessageBox("请重新输入");UpdateData(false);}
					   if(j==mn)
					   {
					   m_test1=danci;UpdateData(false);MessageBox("正确");OnButton29();
					   }
					   } break;
	case  IDC_BUTTON10: {n="j";m_result +=n;t=danci[j];
						if(t=="j")
					          j++;
						else {UpdateData(false);MessageBox("错误");m_result="";j=0;MessageBox("请重新输入");UpdateData(false);}
						if(j==mn)
					   {
					   m_test1=danci;UpdateData(false);MessageBox("正确");OnButton29();
					   }
						} break;
	case  IDC_BUTTON11: {n="k";m_result +=n;t=danci[j];
						if(t=="k")
					          j++;
						else {UpdateData(false);MessageBox("错误");m_result="";j=0;MessageBox("请重新输入");UpdateData(false);}
						if(j==mn)
					   {
					   m_test1=danci;UpdateData(false);MessageBox("正确");OnButton29();
					   }
						} break;
	case  IDC_BUTTON12: {n="l";m_result +=n;t=danci[j];
						if(t=="l")
					          j++;
						else {UpdateData(false);MessageBox("错误");m_result="";j=0;MessageBox("请重新输入");UpdateData(false);}
						if(j==mn)
					   {
					   m_test1=danci;UpdateData(false);MessageBox("正确");OnButton29();
					   }
						} break;
	case  IDC_BUTTON13: {n="m";m_result +=n;t=danci[j];
						if(t=="m")
					          j++;
						else {UpdateData(false);MessageBox("错误");m_result="";j=0;MessageBox("请重新输入");UpdateData(false);}
						if(j==mn)
					   {
					   m_test1=danci;UpdateData(false);MessageBox("正确");OnButton29();
					   }
						} break;
    case  IDC_BUTTON14: {n="n";m_result +=n;t=danci[j];
						if(t=="n")
					          j++;
						else {UpdateData(false);MessageBox("错误");m_result="";j=0;MessageBox("请重新输入");UpdateData(false);}
						if(j==mn)
					   {
					   m_test1=danci;UpdateData(false);MessageBox("正确");OnButton29();
					   }
						} break;
    case  IDC_BUTTON15: {n="o";m_result +=n;t=danci[j];
						if(t=="o")
					          j++;
						else {UpdateData(false);MessageBox("错误");m_result="";j=0;MessageBox("请重新输入");UpdateData(false);}
						if(j==mn)
					   {
					   m_test1=danci;UpdateData(false);MessageBox("正确");OnButton29();
					   }
						} break;
	case  IDC_BUTTON16: {n="p";m_result +=n;t=danci[j];
						if(t=="p")
					          j++;
						else {UpdateData(false);MessageBox("错误");m_result="";j=0;MessageBox("请重新输入");UpdateData(false);}
						if(j==mn)
					   {
					   m_test1=danci;UpdateData(false);MessageBox("正确");OnButton29();
					   }
						} break;
	case  IDC_BUTTON17: {n="q";m_result +=n;t=danci[j];
						if(t=="q")
					          j++;
						else {UpdateData(false);MessageBox("错误");m_result="";j=0;MessageBox("请重新输入");UpdateData(false);}
						if(j==mn)
					   {
					   m_test1=danci;UpdateData(false);MessageBox("正确");OnButton29();
					   }
						} break;
	case  IDC_BUTTON18: {n="r";m_result +=n;t=danci[j];
						if(t=="r")
					          j++;
						else {UpdateData(false);MessageBox("错误");m_result="";j=0;MessageBox("请重新输入");UpdateData(false);}
						if(j==mn)
					   {
					   m_test1=danci;UpdateData(false);MessageBox("正确");OnButton29();
					   }
						} break;
	case  IDC_BUTTON19: {n="s";m_result +=n;t=danci[j];
						if(t=="s")
					          j++;
						else {UpdateData(false);MessageBox("错误");m_result="";j=0;MessageBox("请重新输入");UpdateData(false);}
						if(j==mn)
					   {
					   m_test1=danci;UpdateData(false);MessageBox("正确");OnButton29();
					   }
						} break;
	case  IDC_BUTTON20: {n="t";m_result +=n;t=danci[j];
						if(t=="t")
					          j++;
						else {UpdateData(false);MessageBox("错误");m_result="";j=0;MessageBox("请重新输入");UpdateData(false);}
						if(j==mn)
					   {
					   m_test1=danci;UpdateData(false);MessageBox("正确");OnButton29();
					   }
						} break;
    case  IDC_BUTTON21: {n="u";m_result +=n;t=danci[j];
						if(t=="u")
					          j++;
						else {UpdateData(false);MessageBox("错误");m_result="";j=0;MessageBox("请重新输入");UpdateData(false);}
						if(j==mn)
					   {
					   m_test1=danci;UpdateData(false);MessageBox("正确");OnButton29();
					   }
						} break;
	case  IDC_BUTTON22: {n="v";m_result +=n;t=danci[j];
						if(t=="v")
					          j++;
						else {UpdateData(false);MessageBox("错误");m_result="";j=0;MessageBox("请重新输入");UpdateData(false);}
						if(j==mn)
					   {
					   m_test1=danci;UpdateData(false);MessageBox("正确");OnButton29();
					   }
						} break;
	case  IDC_BUTTON23: {n="w";m_result +=n;t=danci[j];
						if(t=="w")
					          j++;
						else {UpdateData(false);MessageBox("错误");m_result="";j=0;MessageBox("请重新输入");UpdateData(false);}
						if(j==mn)
					   {
					   m_test1=danci;UpdateData(false);MessageBox("正确");OnButton29();
					   }
						} break;
	case  IDC_BUTTON24: {n="x";m_result +=n;t=danci[j];
						if(t=="x")
					          j++;
						else {UpdateData(false);MessageBox("错误");m_result="";j=0;MessageBox("请重新输入");UpdateData(false);}
						if(j==mn)
					   {
					   m_test1=danci;UpdateData(false);MessageBox("正确");OnButton29();
					   }
						} break;
	case  IDC_BUTTON25: {n="y";m_result +=n;t=danci[j];
						if(t=="y")
					          j++;
						else {UpdateData(false);MessageBox("错误");m_result="";j=0;MessageBox("请重新输入");UpdateData(false);}
						if(j==mn)
					   {
					   m_test1=danci;UpdateData(false);MessageBox("正确");OnButton29();
					   }
						} break;
	case  IDC_BUTTON26: {n="z";m_result +=n;t=danci[j];                            
						if(t=="z")
					          j++;
						else {UpdateData(false);MessageBox("错误");m_result="";j=0;MessageBox("请重新输入");UpdateData(false);}
						if(j==mn)
					   {
					   m_test1=danci;UpdateData(false);MessageBox("正确");OnButton29();
					   }
						} break;
	}
 
 
 
 UpdateData(false);
 
 }

void YOUXI::OnButton27() 
{
	CString str;
	str=m_pset->m_IDR;
	str.TrimRight();
	if(str=="IDR_WAVE3")
		PlaySound((const char*)IDR_WAVE3,   AfxGetResourceHandle(),SND_RESOURCE); //单词读音
	else if(str=="IDR_WAVE4")
		PlaySound((const char*)IDR_WAVE4,   AfxGetResourceHandle(),SND_RESOURCE);
	else if(str=="IDR_WAVE5")
		PlaySound((const char*)IDR_WAVE5,   AfxGetResourceHandle(),SND_RESOURCE);
	else if(str=="IDR_WAVE6")
		PlaySound((const char*)IDR_WAVE6,   AfxGetResourceHandle(),SND_RESOURCE);
	else if(str=="IDR_WAVE7")
		PlaySound((const char*)IDR_WAVE7,   AfxGetResourceHandle(),SND_RESOURCE);
	else if(str=="IDR_WAVE8")
		PlaySound((const char*)IDR_WAVE8,   AfxGetResourceHandle(),SND_RESOURCE);
	else if(str=="IDR_WAVE9")
		PlaySound((const char*)IDR_WAVE9,   AfxGetResourceHandle(),SND_RESOURCE);

	//一.PlaySound函数的声明为：
/*
BOOL PlaySound(LPCSTR pszSound,HMODULE hmod,DWORD fdwSound);

1.参数pszSound:是指定了要播放声音的字符串,该参数可以是WAVE文件的名字,或是WAVE资源的名字,或是内存中声音数据的指针,或是在系统注册表WIN.INI中定义的系统事件声音.如果该参数为NULL则停止正在播放的声音.

2.参数hmod:是应用程序的实例句柄,当播放WAV资源时要用到该参数,否则它必须为NULL.

3.参数fdwSound: 是标志的组合，如下表所示。若成功则函数返回TRUE，否则返回FALSE。
二．播放标志以及含义：*/


}



void YOUXI::OnButton29() 
{
	CString str;                                                                  
	m_pset->MoveNext();
	
	if(!m_pset->IsEOF())
	{	
		m_test=m_pset->m_jieshi;
		j=0;
		m_result="";
		m_test1="";
		danci=m_pset->m_eg;
		mn=strlen(danci);
		UpdateData(false);
	}
	else
	{
		m_pset->Close();
		ddd();
	}
}

void YOUXI::OnButton30() 
{
	m_test1=danci;
	UpdateData(false);	
}
void YOUXI::ddd()
{
	CString str;
	m_pset->Open();
	m_test=m_pset->m_jieshi;
	danci=m_pset->m_eg;
	mn=strlen(danci);
	UpdateData(false);
	j=0;
	m_result="";

}
