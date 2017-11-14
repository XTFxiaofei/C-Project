// MyNumEdit.cpp : implementation file
//

#include "stdafx.h"
#include "HCDB.h"
#include "MyNumEdit.h"
#include "ForeMange.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyNumEdit

CMyNumEdit::CMyNumEdit()
{
	
	m_lastnum[0]=0;
    m_lastnum[1]=0;
	m_lastnum[2]=0;
	m_lastnum[3]=0;
	m_lastnum[4]=0;
	m_lastnum[5]=0;
	num=0;
	t=1;
	m_intdouflag=false;
	lastnum=0;
	m_allnum=0;
}

CMyNumEdit::~CMyNumEdit()
{
}


BEGIN_MESSAGE_MAP(CMyNumEdit, CEdit)
	//{{AFX_MSG_MAP(CMyNumEdit)
	ON_WM_CHAR()
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyNumEdit message handlers

///回调函数

void CMyNumEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	int i;
	CForeMange *cwnd=(CForeMange *)GetParent();
	i=cwnd->m_list.GetItemCount();
	CString strtemp,str;
	double price,discount;

   
	if(nChar>='0'&&nChar<='9'||nChar=='.')
	{   	
		CEdit::OnChar(nChar, nRepCnt, nFlags);
	    m_allnum++;
		cwnd->UpdateData();
		num=cwnd->m_num;	
		strtemp.Format("%6.2f",num);
		if(i<1)
		{
			::AfxMessageBox("请输入产品");
			num=0;
		}	
		str=cwnd->m_list.GetItemText(i-1,4);
		price=atof(str);
		str=cwnd->m_list.GetItemText(i-1,5);
		discount=atof(str);
		i=cwnd->m_list.GetItemCount();
		str=cwnd->m_list.GetItemText(i-1,3);
		float allmoney=num*price*discount;
		cwnd->m_singlediscount=discount;
		str=cwnd->m_list.GetItemText(i-1,1);
		cwnd->m_id=str;
	
		//cwnd->UpdateData(false);
		
		str.Format("%6.2f",allmoney);
		cwnd->m_list.SetItemText(i-1,6,str);
		
		
		cwnd->m_list.SetItemText(i-1,3,"");
		cwnd->m_list.SetItemText(i-1,3,strtemp);
		
	}
	if(nChar==VK_BACK)
	{   
		m_allnum--;
     	CEdit::OnChar(nChar, nRepCnt, nFlags);
		
        cwnd->UpdateData();
		num=cwnd->m_num;
		if(m_allnum==0)num=0;
		strtemp.Format("%6.2f",num);
		str=cwnd->m_list.GetItemText(i-1,4);
		price=atof(str);
		str=cwnd->m_list.GetItemText(i-1,5);
		discount=atof(str);
	    float allmoney=num*price*discount;
        str.Format("%6.2f",allmoney);
		cwnd->m_list.SetItemText(i-1,6,str);
        strtemp.Format("%6.2f",num);
		cwnd->m_list.SetItemText(i-1,3,strtemp);
		
	}
	if(nChar==VK_RETURN)
	{
		return;
	}
	else return;
}

BOOL CMyNumEdit::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	/*if   (pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_RETURN) //截取回车键   
	 {
		 return false;
	 }*/
	return CEdit::PreTranslateMessage(pMsg);
}

void CMyNumEdit::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
    
	CEdit::OnKeyDown(nChar, nRepCnt, nFlags);
}
