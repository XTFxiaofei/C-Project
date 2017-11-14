// EmpAddDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HMSys.h"
#include "EmpAddDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEmpAddDlg dialog

extern CHMSysApp theApp;
CEmpAddDlg::CEmpAddDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEmpAddDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEmpAddDlg)
	m_strName = _T("");
	m_nAge = 0;
	m_strAddr = _T("");
	m_strPhone = _T("");
	m_strMore = _T("");
	m_Birth = CTime::GetCurrentTime();
	//}}AFX_DATA_INIT
}


void CEmpAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEmpAddDlg)
	DDX_Control(pDX, IDC_COMBO2, m_DepartCtrl);
	DDX_Control(pDX, IDC_COMBO1, m_SexCtrl);
	DDX_Text(pDX, IDC_NAME, m_strName);
	DDX_Text(pDX, IDC_AGE, m_nAge);
	DDX_Text(pDX, IDC_ADDR, m_strAddr);
	DDX_Text(pDX, IDC_PHONE, m_strPhone);
	DDX_Text(pDX, IDC_MORE, m_strMore);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, m_Birth);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEmpAddDlg, CDialog)
	//{{AFX_MSG_MAP(CEmpAddDlg)
	ON_BN_CLICKED(IDC_BTN_ADD, OnBtnAdd)
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEmpAddDlg message handlers

void CEmpAddDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CRect Rect;							//定义一个区域
	GetDlgItem(IDC_PHOTO)->GetWindowRect(&Rect);//获取区域
	ScreenToClient(&Rect);		//将屏幕坐标转换为客户坐标		
	if(Rect.PtInRect(point))		//如果在这个区域内
	{
		CFileDialog FileDlg(TRUE, "BMP", NULL,		//定义文件对话框
			OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, "位图文件(*.BMP)|*.BMP||");
		if(FileDlg.DoModal() != IDOK)			//打开文件对话框
			return ;
		CString pathname = FileDlg.GetPathName();//获取选中文件的路径
		CFile file;						//定义一个文件变量
		if(!file.Open(pathname, CFile::modeRead) )//以制度的方式打开文件
			return ;
		m_nFileLen = file.GetLength();//获取文件的长度
		m_pBMPBuffer = new char[m_nFileLen + 1];//开辟符数组
		if(!m_pBMPBuffer)			//如果控件不够大
			return ;
		if(file.ReadHuge(m_pBMPBuffer,m_nFileLen) != m_nFileLen)//读取文件保存在字符数组中
			return ;
		LPSTR				hDIB,lpBuffer = m_pBMPBuffer;
		LPVOID				lpDIBBits;
		BITMAPFILEHEADER	bmfHeader;//保存bmp文件头的信息
		DWORD				bmfHeaderLen;//保存文件头的长度

		bmfHeaderLen = sizeof(bmfHeader);//读取文件头的长度
		strncpy((LPSTR)&bmfHeader,(LPSTR)lpBuffer,bmfHeaderLen);//文件的赋值
		if (bmfHeader.bfType != (*(WORD*)"BM"))//如果文件类型不对
			return ;
		hDIB = lpBuffer + bmfHeaderLen;	//将指针移动到文件头的后面
		BITMAPINFOHEADER &bmiHeader = *(LPBITMAPINFOHEADER)hDIB ;//读取bmp文件的数据
		BITMAPINFO &bmInfo = *(LPBITMAPINFO)hDIB ;
		lpDIBBits=(lpBuffer)+((BITMAPFILEHEADER *)lpBuffer)->bfOffBits;

		CClientDC dc(this);
		m_hPhotoBitmap = CreateDIBitmap(dc.m_hDC,&bmiHeader,CBM_INIT,lpDIBBits,&bmInfo,DIB_RGB_COLORS);
		Invalidate();
	}	
	CDialog::OnLButtonDown(nFlags, point);
}


void CEmpAddDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	CStatic *pStaic = (CStatic*)GetDlgItem(IDC_PHOTO);//获取ID为IDC_PHOTO控件的指针
	CBitmap bmp;							//定义位图变量
	bmp.Attach(m_hPhotoBitmap);	
	BITMAP bm;								//定义一个位图结构
	bmp.GetBitmap(&bm);						
	CDC dcMem; 
	dcMem.CreateCompatibleDC(GetDC());		//创建一个兼容的DC
	CBitmap *poldBitmap=(CBitmap*)dcMem.SelectObject(bmp); //将位图选入设备环境类
	CRect lRect;					    	//定义一个区域
	pStaic->GetClientRect(&lRect);			//获取控件的客户区域
	lRect.NormalizeRect(); 
	pStaic->GetDC()->StretchBlt(lRect.left ,lRect.top ,lRect.Width(),lRect.Height(), 
		&dcMem,0 ,0,bm.bmWidth,bm.bmHeight,SRCCOPY); //显示位图 
	dcMem.SelectObject(&poldBitmap); //将原有的句柄选入设备环境
}
BOOL CEmpAddDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CString strSQL;							//定义字符串变量
	strSQL.Format("select * from dep");	//格式化SQL语句
	try
	{
		m_pRecordset1 = theApp.m_pConnection->Execute((_bstr_t)strSQL, NULL, adCmdText);//执行SQL语句并将结果返回给记录集
		while(!m_pRecordset1->adoEOF)		//如果记录没有到末尾
		{
			m_DepartCtrl.AddString((char*)_bstr_t(m_pRecordset1->GetCollect(_variant_t((long)1))));//将记录集查询的结果添加到下拉列表框中
			m_pRecordset1->MoveNext();//移动到下一条记录
		}
	}
	CATCH_ERROR;

	m_pRecordset.CreateInstance("ADODB.Recordset");
	HRESULT hr = m_pRecordset->Open("SELECT * FROM emp",
		_variant_t((IDispatch *)theApp.m_pConnection,true),
		adOpenDynamic,adLockPessimistic,adCmdText);
	m_SexCtrl.SetCurSel(0);//下拉列表框默认选择第一项
	m_DepartCtrl.SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CEmpAddDlg::OnBtnAdd() 
{
	UpdateData();						//更新数据
	if(m_strName == "")					//条件判断
	{
		MessageBox("姓名不能为空！");
		return ;
	}
	if(m_nAge == 0)
	{
		MessageBox("请设置年龄！");
		return ;
	}
	CString strSex, strDepart, strBirth, strAge;//定义字符串变量
	strBirth.Format("%d-%d-%d", m_Birth.GetYear(), m_Birth.GetMonth(), m_Birth.GetDay());
	int nIndex = m_SexCtrl.GetCurSel();//获取下拉列表框选中的索引
	m_SexCtrl.GetLBText(nIndex, strSex);//获取下拉列表框的文本
	nIndex = m_DepartCtrl.GetCurSel();
	m_DepartCtrl.GetLBText(nIndex, strDepart);
	strAge.Format("%d", m_nAge);
	m_pRecordset->AddNew;
	m_pRecordset->PutCollect("name",_variant_t(m_strName));
	m_pRecordset->PutCollect("age",_variant_t((long)m_nAge));
	m_pRecordset->PutCollect("sex",_variant_t(strSex));
	m_pRecordset->PutCollect("addr",_variant_t(m_strAddr));
	m_pRecordset->PutCollect("depart",_variant_t(strDepart));
	m_pRecordset->PutCollect("birth",_variant_t(strBirth));
	m_pRecordset->PutCollect("phone",_variant_t(m_strPhone));
	m_pRecordset->PutCollect("more",_variant_t(m_strMore));
	char			*pBuf = m_pBMPBuffer;
	VARIANT			varBLOB;
	SAFEARRAY		*psa;
    SAFEARRAYBOUND	rgsabound[1];
	if(pBuf)
	{    
		rgsabound[0].lLbound = 0;
		rgsabound[0].cElements = m_nFileLen;
		psa = SafeArrayCreate(VT_UI1, 1, rgsabound);
		for (long i = 0; i < (long)m_nFileLen; i++)
			SafeArrayPutElement (psa, &i, pBuf++);
		varBLOB.vt = VT_ARRAY | VT_UI1;
		varBLOB.parray = psa;
		m_pRecordset->GetFields()->GetItem("photo")->AppendChunk(varBLOB);
	}
	m_pRecordset->Update();
	MessageBox("保存成功！");
}


void CEmpAddDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	CRect Rect;							//定义一个区域
	GetDlgItem(IDC_PHOTO)->GetWindowRect(&Rect);//获取区域
	ScreenToClient(&Rect);		//将屏幕坐标转换为客户坐标		
	if(Rect.PtInRect(point))		//如果在这个区域内
	{
		HCURSOR hCursor; 
		hCursor = AfxGetApp() -> LoadCursor(IDC_HAND); 
		SetCursor(hCursor); 	
	}
	CDialog::OnMouseMove(nFlags, point);
}
