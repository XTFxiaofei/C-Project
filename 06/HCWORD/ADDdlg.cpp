// ADDdlg.cpp : implementation file
//

#include "stdafx.h"
#include "HCWORD.h"
#include "ADDdlg.h"
#include "HCset.h"
#include "TIANJIADlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
//CString logFileName;
/////////////////////////////////////////////////////////////////////////////
// ADDdlg dialog


ADDdlg::ADDdlg(CWnd* pParent /*=NULL*/)
	: CDialog(ADDdlg::IDD, pParent)
{    //m_set=new HCset();
	//{{AFX_DATA_INIT(ADDdlg)
	//}}AFX_DATA_INIT
}


void ADDdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ADDdlg)
	DDX_Control(pDX, IDC_LIST3, m_list);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ADDdlg, CDialog)
	//{{AFX_MSG_MAP(ADDdlg)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST3, OnItemchangedList3)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	ON_BN_CLICKED(IDC_MODIFY, OnModify)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////



BOOL ADDdlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
    word="";
	columnname1="eg";                                                           //初始化
	tablename="eh";
	selectrow=-1;
	m_list.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT); //设置列表控件的风格
    m_list.InsertColumn(0,"单词",LVCFMT_CENTER,250);                //添加列表控件的列名
	m_list.InsertColumn(1,"释义",LVCFMT_CENTER,250);
    pdb=new CDatabase;                                               //定义数据库访问指针
	pdb->OpenEx("DSN=词库;Trusted_Connection=Yes;");                                     //打开数据库
    m_combo.SetCurSel(0);                                            //初始化下拉控件                                 
	show();  
    return TRUE;  
}
void ADDdlg::show()                                                 //自定义函数
{
	int i=0;
	CString temp1,temp2;
	strsql="select * from "+tablename;                          //获取数据表中数据信息
	pdb->ExecuteSQL(strsql);
	CRecordset m_Set(pdb);
	m_Set.Open(CRecordset::dynaset,strsql);
	CODBCFieldInfo fieldinfo; 
    m_Set.GetODBCFieldInfo(short(0), fieldinfo);//取第1个字段的信息
	columnname1=fieldinfo.m_strName;
	m_Set.GetODBCFieldInfo(short(1), fieldinfo);//取第2个字段的信息
	columnname2=fieldinfo.m_strName;
	m_list.DeleteAllItems();                                          //列表控件清空
	while(!m_Set.IsEOF())                                             //判断是否数据遍历到数据库中数据的最后
	{ 
		m_Set.GetFieldValue(short(0),temp1);
		m_Set.GetFieldValue(short(1),temp2);
		temp1.TrimRight();
		temp2.TrimRight();
		m_list.InsertItem(i,temp1);                               //把数据库中的数据对应列名显示     
		m_list.SetItemText(i,1,temp2);
		i++;                                                               
        m_Set.MoveNext();                                          //移动到下一条记录
	}
	UpdateData(false);                                         //刷新数据
	m_Set.Close();                                         //关闭数据库
}  


void ADDdlg::OnSelchangeCombo1() 
{
	CString temp;
	m_combo.GetLBText(m_combo.GetCurSel(),temp);             //获取下拉控件的值
	if(temp=="词库表")                                      
	{
		tablename="eh";                                    
	}
	else if(temp=="生词表")
	{
		tablename="ziliao";
	}
	else if(temp=="四级考试单词表")
	{
		tablename="four";
	}
	show();                                       //调用函数
}

void ADDdlg::OnItemchangedList3(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	selectrow=pNMListView->iItem;
    word=m_list.GetItemText(selectrow,0);                     //获取键盘输入信息
	mean=m_list.GetItemText(selectrow,1);                     //获取键盘输入信息

	*pResult = 0;
}

void ADDdlg::OnButton1() 
{
	if(word!="")                                                  //判断输入信息是否为空
	{
		CString str,temp,str2;                                        //定义字符串变量
		str.Format("select * from %s where %s='%s'",tablename,columnname1,word);    //根据条件，遍历数据表	
		pdb->ExecuteSQL(str);
		CRecordset m_Set(pdb);
		m_Set.Open(CRecordset::dynaset,str);
		m_Set.GetFieldValue(short(1),temp);	
		m_Set.Close();
		str2=temp;                                  //获取数据	
		CString sPath; 
		GetModuleFileName(NULL,sPath.GetBufferSetLength (MAX_PATH+1),MAX_PATH);//为sPath分配存储空间
		sPath.ReleaseBuffer();
		int nPos;
		nPos=sPath.ReverseFind('\\');
		sPath=sPath.Left(nPos);
		nPos=sPath.ReverseFind('\\');
		sPath=sPath.Left(nPos);
		logFileName = sPath + "\\log.txt";  
		CTime t=CTime::GetCurrentTime();//获取本地的当前时间
        CString strtime=t.Format("%Y年%m月%d日 %H时%M分%S秒");
		CString   strTmp=strtime+"\r\n"+word+"\t\t"+str2+"\n\n\n";//获取显示信息
		CStdioFile file(logFileName,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);
		file.SeekToEnd();                                          //先定位到文件尾部
		file.WriteString(strTmp);                                  //写出显示信息
		file.Close();                                              //关闭文件
	}
	REMDlg mydlg;                                             //定义对象
	mydlg.DoModal();                                          //响应消息函数	
}

void ADDdlg::OnAdd() 
{
	
	TIANJIADlg mydlg;
	mydlg.addflag=true;
	if(mydlg.DoModal()==IDOK)
	{
		if(mydlg.m_1!=""&&mydlg.m_3!="")
		{
		CString str,temp,str2;                                        //定义字符串变量
		str.Format("insert into %s(%s,%s) values('%s','%s')",tablename,columnname1,columnname2,mydlg.m_1,mydlg.m_3);    //根据条件，遍历数据表	
		pdb->ExecuteSQL(str);
		show();
        AfxMessageBox("添加成功！");
		}
		else
		{
			AfxMessageBox("请输入单词和解释");
			return;
		}
	}
}

void ADDdlg::OnDelete() 
{
	 if(word=="")
	{
		AfxMessageBox("请先选择要删除的记录");
		return;
	}
	if(MessageBox("注意","确定要删除吗？",MB_OKCANCEL)==IDOK)
	{
		CString str,temp,str2;                                        //定义字符串变量
		str.Format("delete from %s where %s='%s'",tablename,columnname1,word);//根据条件，遍历数据表	
		pdb->ExecuteSQL(str);
		show();
        AfxMessageBox("删除成功！");	
	}	
}

void ADDdlg::OnModify() 
{
	TIANJIADlg mydlg;
	mydlg.addflag=false;
	mydlg.m_1=word;
	mydlg.m_3=mean;
    if(word=="")
	{
		AfxMessageBox("请先选择要修改的记录");
		return;
	}
	if(mydlg.DoModal()==IDOK)
	{
		if(mydlg.m_1!=""&&mydlg.m_3!="")
		{
		CString str,temp,str2;                                        //定义字符串变量
		str.Format("update %s set %s='%s' where %s='%s'",tablename,columnname2,mydlg.m_3,columnname1,mydlg.m_1);//根据条件，遍历数据表	
		pdb->ExecuteSQL(str);
		show();
        AfxMessageBox("修改成功！");
		}
		else
		{
			AfxMessageBox("请输入单词和解释");
			return;
		}
	}
}
