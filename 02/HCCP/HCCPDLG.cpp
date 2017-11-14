// HCCPDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HCCP.h"
#include "HCCPDlg.h"
#include "ADOConn.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();
	
	// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA
	
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
	
	// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
//{{AFX_MSG_MAP(CAboutDlg)
// No message handlers
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHCCPDlg dialog

CHCCPDlg::CHCCPDlg(CWnd* pParent /*=NULL*/)
: CDialog(CHCCPDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHCCPDlg)
	m_text = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHCCPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHCCPDlg)
	DDX_Control(pDX, IDC_LIST1, m_list1);
	DDX_Control(pDX, IDC_TAB1, m_tab);
	DDX_Control(pDX, IDC_TREE1, m_tree);
	DDX_Text(pDX, IDC_BIAOTI, m_text);
	DDX_Control(pDX, IDC_BIAOTI, m_textctrl);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CHCCPDlg, CDialog)
//{{AFX_MSG_MAP(CHCCPDlg)
ON_WM_SYSCOMMAND()
ON_WM_PAINT()
ON_WM_QUERYDRAGICON()
ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, OnSelchangeTab1)
ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, OnSelchangedTree1)
ON_WM_TIMER()
ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, OnItemchangedList1)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHCCPDlg message handlers

BOOL CHCCPDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	// Add "About..." menu item to system menu.
	
	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	m_text="欢迎使用综合测评系统";  
	m_textctrl.SetFontSize(27);  //设置静态控件中显示字体大小
	m_textctrl.SetTextColor(RGB(0,255,0));  //设置静态控件字体颜色
	m_textctrl.SetBkColor(RGB(0,0,0));  //设置静态控件背景颜色
	m_textctrl.SetFontBold(TRUE);  //设置字体为黑体
	m_textctrl.SetText(m_text);  //设置静态控件文本内容
	
	m_list1.SetExtendedStyle(LVS_EX_FULLROWSELECT);  //设置list列表风格
	m_list1.InsertColumn(0,"学号",LVCFMT_CENTER,164);  //设置列标题
	m_list1.InsertColumn(1,"姓名",LVCFMT_CENTER,164);
	m_list1.InsertColumn(2,"分数",LVCFMT_CENTER,164);	
	
	m_TreeBootImage.Create ( IDB_BITMAP1,20,1,ILC_COLOR8);  //设置树形控件的属性
	m_tree.SetImageList ( &m_TreeBootImage,TVSIL_NORMAL );  //设置树形控件风格
	m_tree.SetTextColor (RGB(7,145,13));  //设置树形控件字体颜色
	
	InitTab();
	ShowDlg();
	CreateTree();
	SetTimer(1,250,NULL);  //打开定时器，时间间隔为250ms
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

/*------------------初始化tab控件---------------------*/

void CHCCPDlg::InitTab()
{
	showdlgnum=0;
	
	m_tab.InsertItem(0,"学生成绩修改");  //添加tab控件内容
	m_tab.InsertItem(1,"学生成绩查询");
	m_tab.InsertItem(2,"学生成绩排序");	
	m_tab.InsertItem(3,"学科学分修改");
	m_tab.InsertItem(4,"学生综合测评");

	modifydlg.Create(IDD_XSCJXG,&m_tab);  //创建tab控件child对话框对象
	finddlg.Create(IDD_XSCJCX,&m_tab);
	sortdlg.Create(IDD_XSCJPX,&m_tab);
	zhcpdlg.Create(IDD_XSZHPC,&m_tab);
	xkxgdlg.Create(IDD_XKXFXG,&m_tab);
	CRect rc;
	m_tab.GetClientRect(rc);  //获取客户区大小
	rc.top += 20;
	rc.bottom -= 8;
	rc.left += 8;
	rc.right -= 8;
	modifydlg.MoveWindow(&rc);  //设置tab控件child对话框显示区域
	finddlg.MoveWindow(&rc);
	sortdlg.MoveWindow(&rc);
	zhcpdlg.MoveWindow(&rc);
	xkxgdlg.MoveWindow(&rc);

	pdlg[0]=&modifydlg;  //获取child对话框指针
	pdlg[1]=&finddlg;
	pdlg[2]=&sortdlg;
	pdlg[3]=&xkxgdlg;
	pdlg[4]=&zhcpdlg;
	
}

/*------------------tab控件响应函数---------------------*/

void CHCCPDlg::ShowDlg()
{
	switch(showdlgnum)
	{
	case 0:
		{
			pdlg[0]->ShowWindow(SW_SHOW);		
			pdlg[1]->ShowWindow(SW_HIDE);
			pdlg[2]->ShowWindow(SW_HIDE);
			pdlg[3]->ShowWindow(SW_HIDE);
			pdlg[4]->ShowWindow(SW_HIDE);
		}break;
	case 1:
		{
			pdlg[0]->ShowWindow(SW_HIDE);
			pdlg[1]->ShowWindow(SW_SHOW);
			pdlg[2]->ShowWindow(SW_HIDE);
			pdlg[3]->ShowWindow(SW_HIDE);
			pdlg[4]->ShowWindow(SW_HIDE);
		}break;
	case 2:
		{
			pdlg[0]->ShowWindow(SW_HIDE);
			pdlg[1]->ShowWindow(SW_HIDE);
			pdlg[2]->ShowWindow(SW_SHOW);
			pdlg[3]->ShowWindow(SW_HIDE);
			pdlg[4]->ShowWindow(SW_HIDE);
		}break;
	case 3:
		{
			pdlg[0]->ShowWindow(SW_HIDE);
			pdlg[1]->ShowWindow(SW_HIDE);
			pdlg[2]->ShowWindow(SW_HIDE);
			pdlg[3]->ShowWindow(SW_SHOW);
			pdlg[4]->ShowWindow(SW_HIDE);
		}break;
	case 4:
		{
			pdlg[0]->ShowWindow(SW_HIDE);
			pdlg[1]->ShowWindow(SW_HIDE);
			pdlg[2]->ShowWindow(SW_HIDE);
			pdlg[3]->ShowWindow(SW_HIDE);
			pdlg[4]->ShowWindow(SW_SHOW);
			
		}break;
		
	}
}

/*------------------刷新显示list列表---------------------*/

void CHCCPDlg::ShowList(CString cnamedd)
{
	ADOConn m_AdoConn;
	m_AdoConn.OnInitDBConnect();
	_bstr_t vSQL;
	CString str00;
	if(flag121==false&&sortdlg.temp!="sno")
	{
		str00.Format("select student.sno,sname,sgrade from student ,grade where student.sno=grade.sno and cno='%s' order by %s DESC",cnamedd,sortdlg.temp);  //依据组合框内容排序
		flag121=true;
	}
	else
		str00.Format("select student.sno,sname,sgrade from student ,grade where student.sno=grade.sno and cno='%s'",cnamedd);  //依据课程名读取数据库成绩
	vSQL=(_bstr_t)str00;

	_RecordsetPtr m_pRs;
	m_pRs=m_AdoConn.GetRecordSet(vSQL);  //获取成绩记录集
	
	int k=0;
	
	_variant_t cno,cname,cgrade;
	
	while(!m_pRs->adoEOF)  //判断记录集结束标志
	{
		cno=m_pRs->GetCollect("sno");  //读取记录集中学号
		cname=m_pRs->GetCollect("sname");  //读取记录集中姓名
		cgrade=m_pRs->GetCollect("sgrade");  //读取记录集中成绩
		
		CString str1=(LPCTSTR)(_bstr_t)cname;
		CString str2=(LPCTSTR)(_bstr_t)cgrade;
		
		m_list1.InsertItem(k,(_bstr_t)cno);  //将学号添加到第一列
		m_list1.SetItemText(k,1,str1);  //将姓名添加到第二列
		m_list1.SetItemText(k,2,str2);  //将成绩添加到第三列
		m_pRs->MoveNext();  //指针指向下一条记录
		k++;
	}
}

/*---------------------创建tree树形控件---------------------*/

void CHCCPDlg::CreateTree()
{
	m_tree.DeleteAllItems();
	m_AdoConn.OnInitDBConnect();	
	TVINSERTSTRUCT tvInsert;  
	HTREEITEM hParent;
	tvInsert.hParent = NULL;
	tvInsert.hInsertAfter = NULL;
	tvInsert.item.mask = TVIF_TEXT;
	tvInsert.item.pszText = _T("常州大学");  //创建根结点
	hParent = m_tree.InsertItem(&tvInsert);	
	vSQL="SELECT * FROM tree where root='常州大学'";  //通过根节点选取2级结点
	m_pRs1=m_AdoConn.GetRecordSet(vSQL);
	CString yezi="leaf";  
	while(!m_pRs1->adoEOF)  //通过递归调用select方法创建树
	{	
		Select(yezi,hParent,m_pRs1);  //调用select方法创建叶子结点		
		CString str1;
		str1.Format("SELECT * FROM tree where root='%s'",str);  //通过父节点选取子结点
		vSQL1=(_bstr_t)str1;
		m_pRs2=m_AdoConn.GetRecordSet(vSQL1); //获取记录集
		
		leaf1=leaf;
		while(!m_pRs2->adoEOF)
		{	
			Select(yezi,leaf1,m_pRs2);			
			CString str2;
			str2.Format("SELECT * FROM tree where root='%s'",str);
			vSQL2=(_bstr_t)str2;
			m_pRs3=m_AdoConn.GetRecordSet(vSQL2);	
			leaf2=leaf;
			while(!m_pRs3->adoEOF)
			{
				Select(yezi,leaf2,m_pRs3);
			}
		}		
	}	
	m_tree.Expand(hParent,TVE_EXPAND);  //展开一级结点
	m_tree.Expand(m_tree.GetChildItem(hParent),TVE_EXPAND);  //展开2级结点
	m_tree.Expand(m_tree.GetChildItem(m_tree.GetChildItem(hParent)),TVE_EXPAND);  //展开3级结点	
}

void CHCCPDlg::Select(CString ming,HTREEITEM root,_RecordsetPtr m_pRs)  //创建叶子结点
{		
	name=m_pRs->GetCollect((_bstr_t)ming);  //获取子结点记录集
	str=(LPCTSTR)(_bstr_t)name;
	leaf=m_tree.InsertItem(str,0,1,root,TVI_LAST);	//添加子结点
	m_pRs->MoveNext();  //指针指向下一条记录				
}

void CHCCPDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CHCCPDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting
		
		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);
		
		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		
		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CHCCPDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

/*---------------------通过事件监听器选择tab控件---------------------*/

void CHCCPDlg::OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	int sel=0;
	sel=m_tab.GetCurSel();
	switch(sel)
	{
	case 0:
		showdlgnum=0;
		break;
		
	case 1:
		showdlgnum=1;
		break;
		
	case 2:
		showdlgnum=2;
		break;
		
	case 3:
		showdlgnum=3;
		break;
		
	case 4:
		  showdlgnum=4;
		  break;
			
	}
	ShowDlg();		  
	*pResult = 0;
}

/*---------------------通过事件监听器选择Tree型控件---------------------*/

void CHCCPDlg::OnSelchangedTree1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	
	m_list1.DeleteAllItems();  //删除list控件内容
	leaf111=m_tree.GetItemText(pNMTreeView->itemNew.hItem);  //获取当前结点内容
	leaf11=m_tree.GetItemText(m_tree.GetParentItem(pNMTreeView->itemNew.hItem));  //获取父结点内容
	leaf12=m_tree.GetItemText(m_tree.GetParentItem(m_tree.GetParentItem(pNMTreeView->itemNew.hItem)));  //获取父结点的父结点内容
	HTREEITEM   hItem =pNMTreeView->itemNew.hItem;   
	HTREEITEM   hItemTmp=hItem;
	CString biaoti;
	biaoti=leaf111;
	biaoti.TrimRight();
	int nCount1=0;
	while(hItemTmp)  //通过while循环判断当前结点的级别
	{		
		hItemTmp= m_tree.GetParentItem(hItemTmp);  //获取父结点指针判断是否为空
		nCount1++;
	}
	
	_bstr_t vSQL4;
	_RecordsetPtr m_pRs4;
	_variant_t cnamed;
	
	nCount=nCount1;
	CString str001,str002,str003;
	str002=leaf111;
	str002.TrimRight();
	if(nCount==3)
	{
		m_text=biaoti+"班学生名单：";  
		str001.Format("select * from student where sclass='%s'",str002);  //获取当前班级下学生名单
		vSQL4=(_bstr_t)str001;
		m_pRs4=m_AdoConn.GetRecordSet(vSQL4);
		
		int k=0;
		
		_variant_t sno,sname,cgrade,cname3;
		
		while(!m_pRs4->adoEOF)
		{
			sno=m_pRs4->GetCollect("sno");  //通过记录集选取学号
			sname=m_pRs4->GetCollect("sname");  //通过记录集选取学生姓名
			
			CString str1=(LPCTSTR)(_bstr_t)sname;
			
			m_list1.InsertItem(k,(_bstr_t)sno);  //将学号添加到list控件
			m_list1.SetItemText(k,1,str1);  //将姓名添加到list控件
			
			m_pRs4->MoveNext();  //指针移向下一条记录
			k++;
		}
	}
	else if(nCount==4)
	{
		m_text=biaoti+"课程期末成绩：";
		try{
			str001.Format("select * from class where cname='%s'",str002);  //获取当前课程下学生成绩
			vSQL4=(_bstr_t)str001;
			m_pRs4=m_AdoConn.GetRecordSet(vSQL4);
			cnamed=m_pRs4->GetCollect("cno");  //通过记录集获取课程号
			str003=(LPCTSTR)(_bstr_t)cnamed;
			str1112=str003;
			ShowList(str003);  
		}
		catch(...)  //捕获异常
		{}
	}
	else
		m_text="欢迎使用综合测评系统";
	
	if(nCount==4)
	{
		xkxgdlg.m_xkm=biaoti;
		str001.Format("select * from class where cname='%s'",biaoti);
		vSQL4=(_bstr_t)str001;
		m_pRs4=m_AdoConn.GetRecordSet(vSQL4);
		cnamed=m_pRs4->GetCollect("cgrade");
		str003=(LPCTSTR)(_bstr_t)cnamed;
		xkxgdlg.m_xuekf=atof(str003);	
	}
	else
	{
		xkxgdlg.m_xkm="";
		xkxgdlg.m_xuekf=0;
	}	
	xkxgdlg.UpdateData(false);

	*pResult = 0;
}

/*---------------------定时器---------------------*/

void CHCCPDlg::OnTimer(UINT nIDEvent) 
{
	i=i+5;j=j-3;k=k+2;
	color=RGB(k,j,i);  //通过定时器改变颜色
	if(i==255)
		i=0;
	if(j==15)
		j=255;
	if(k==255)
		k=1;
	if(flag123==false||flag121==false)
	{
		m_list1.DeleteAllItems();  //删除list控件全部内容
		ShowList(str1112);  //显示list控件
		flag121=flag123=true;
	}
	m_textctrl.SetTextColor(color);  //设置显示标题字体颜色

	CDialog::OnTimer(nIDEvent);
}

void CHCCPDlg::OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	int i=pNMListView->iItem;
	qiqi=i;
	modifydlg.m_sno=m_list1.GetItemText(i,0);  //获取list控件上选取条目内容
	modifydlg.m_sname=m_list1.GetItemText(i,1);  //获取list控件上选取条目内容
	if (nCount==3)
	{	
		modifydlg.UpdateData(false);
	}
	else if(nCount==4)
	{		
		modifydlg.m_sgrade=atof(m_list1.GetItemText(i,2));  //将String型强制转换成double
		modifydlg.UpdateData(false);
	}
	*pResult = 0;
}

/*-------------------------程序结束时自动备份数据库-------------------------*/

void CHCCPDlg::OnClose() 
{
    CDialog::OnClose();
	CString str;
	CString filename;
	CString sPath;
	GetModuleFileName(NULL,sPath.GetBufferSetLength (MAX_PATH+1),MAX_PATH);
	sPath.ReleaseBuffer();
	int nPos;
	nPos=sPath.ReverseFind('\\');
	sPath=sPath.Left(nPos);  //获取到工程Debug路径
	nPos=sPath.ReverseFind('\\');
	sPath=sPath.Left(nPos);  //获取到工程当前路径
	filename=sPath+"\\database\\HCBAK1";  //备份数据库名称
	DeleteFile(filename);  //删除旧的备份
	str.Format("backup database HCCP to Disk='%s'",filename);  //通过sql语句备份数据库
	vSQL=(_bstr_t)str;
	m_AdoConn.ExecuteSQL(vSQL);  //执行sql语句
	AfxMessageBox("系统自动备份数据库成功!\r\n路径："+filename+"\r\n欢迎下次使用!");
	CDialog::OnClose();
}
