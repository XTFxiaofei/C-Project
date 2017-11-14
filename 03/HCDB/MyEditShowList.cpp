// MyEditShowList.cpp : implementation file
//

#include "stdafx.h"
#include "HCDB.h"
#include "MyEditShowList.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include "GATHEROUT.h"
/////////////////////////////////////////////////////////////////////////////
// CMyEditShowList
extern CHCDBApp theApp;
#define IDC_MYLIST 10000

CMyEditShowList::CMyEditShowList()
{
	//m_list=NULL;
    width=0;
	oncharflag=false;
}

CMyEditShowList::~CMyEditShowList()
{
}


BEGIN_MESSAGE_MAP(CMyEditShowList, CEdit)
	//{{AFX_MSG_MAP(CMyEditShowList)
	ON_WM_CHAR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyEditShowList message handlers

void CMyEditShowList::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{	
	CEdit::OnChar(nChar, nRepCnt, nFlags);
	oncharflag=true;
	CString str;
    CGATHEROUT *cwnd=( CGATHEROUT *)GetParent();
	CRect rect1;cwnd->GetClientRect(rect1);
    ClientToScreen(rect1);	
	CRect rect;
	GetClientRect(rect);
	int a=rect.left;
	int b=rect.top;
	ClientToScreen(rect);
	if(!m_list)
	{
	  m_list.Create(WS_CHILD|WS_VISIBLE|WS_BORDER|LVS_REPORT,CRect(rect.left,rect.top,rect.right+200,rect.bottom+200), cwnd, 1);	
	  m_list.InsertColumn(0,"商品编号",LVCFMT_LEFT,60);
	  m_list.InsertColumn(1,"商品名称",LVCFMT_LEFT,60);
	  m_list.InsertColumn(2,"单价",LVCFMT_LEFT,60);
	  m_list.InsertColumn(3,"规格型号",LVCFMT_LEFT,60);
	  m_list.InsertColumn(4,"供应商",LVCFMT_LEFT,60);
	  m_list.InsertColumn(5,"单位",LVCFMT_LEFT,60);
	  m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	}
	TEXTMETRIC Metrics ;
	CDC * dc=this->GetDC();
	dc->GetTextMetrics(&Metrics) ; 
	 
	if(nChar!=VK_BACK)
	{   
		this;
		cwnd->UpdateData();
		querystr=cwnd->m_mercid;
		width+=Metrics.tmHeight/8;
        m_list.MoveWindow(rect.left-100+width,rect.top-100,rect.right+width,rect.bottom-500,true);
	}
    else
	{
		querystr=querystr.Mid(0,querystr.GetLength()-1);
        width-=Metrics.tmHeight/8;
        m_list.MoveWindow(rect.left-100+width,rect.top-100,rect.right+width,rect.bottom-500,true);
	}
	if(nChar==VK_DOWN)
	{
	
		::SetFocus(m_list.m_hWnd);
	}
	str.Format("select * from tb_merchangiseinfo where id like '%%%s%%'",querystr);
    GetRecord(str);

	SetListValue("");
}

void CMyEditShowList::GetRecord(CString sqlstr)
{
    if(m_record!=NULL)
	{
		m_record=NULL;

	}
	m_record.CreateInstance(__uuidof(Recordset));
	try
	{
	m_record->Open(_bstr_t(sqlstr),theApp.m_connection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	}
	catch(_com_error e)
	{
		AfxMessageBox(e.ErrorMessage());
	}
}




void CMyEditShowList::SetListValue(CString sqlstr)
{ 
	int rows=0;
	CString temp;
	m_list.DeleteAllItems();
	while(!m_record->_EOF)
	{
		m_list.ShowWindow(true);
        temp=(LPCSTR)(_bstr_t)m_record->GetCollect("id");
		m_list.InsertItem(rows,temp);
        temp=(LPCSTR)(_bstr_t)m_record->GetCollect("mercname");
		m_list.SetItemText(rows,1,temp);
		temp=(LPCSTR)(_bstr_t)m_record->GetCollect("outprice");
		m_list.SetItemText(rows,2,temp);
		temp=(LPCSTR)(_bstr_t)m_record->GetCollect("spec");
		m_list.SetItemText(rows,3,temp);
		temp=(LPCSTR)(_bstr_t)m_record->GetCollect("provid");
		m_list.SetItemText(rows,4,temp);
		temp=(LPCSTR)(_bstr_t)m_record->GetCollect("mercunit");
		m_list.SetItemText(rows,5,temp);
		m_record->MoveNext();
		rows++;
	}


}



//DEL void CMyEditShowList::OnKillFocus(CWnd* pNewWnd) 
//DEL {
//DEL 
//DEL 	if(m_list.GetItemCount()==0)
//DEL 	{
//DEL 		m_list.ShowWindow(false);
//DEL 		MessageBox("当前已没有记录！");
//DEL 	}
//DEL 	else
//DEL 	{
//DEL 		m_list.ShowWindow(true);
//DEL 	}
//DEL 	// TODO: Add your message handler code here
//DEL 	CEdit::OnKillFocus(pNewWnd);
//DEL }
