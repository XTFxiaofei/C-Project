// MyTree.cpp : implementation file
//

#include "stdafx.h"
#include "HCCP.h"
#include "MyTree.h"
#include "ADOConn.h"
#include "ADDDLG.h"
#include "HCCPDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// MyTree

MyTree::MyTree()
{
	flag=true;
}

MyTree::~MyTree()
{
}


BEGIN_MESSAGE_MAP(MyTree, CTreeCtrl)
	//{{AFX_MSG_MAP(MyTree)
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND_RANGE(ID_POPUP_MEMU1,ID_POPUP_MEMU2,Operate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// MyTree message handlers

/*-------------------------通过tree派生类创建右键菜单-----------------------------*/

void MyTree::OnRButtonDown(UINT nFlags, CPoint point) 
{
	if(!flag)
	{
			CMenu menu;
			menu.CreatePopupMenu();
			menu.AppendMenu(MF_SEPARATOR);
			switch(nCount)  //通过当前结点级别创建菜单
			{
			case 1:
				menu.AppendMenu(0,ID_POPUP_MEMU1,"添加新院系&A");  //添加菜单选项
				menu.AppendMenu(MF_GRAYED,ID_POPUP_MEMU2,"删除该学校&D");break;
			case 2:
				menu.AppendMenu(0,ID_POPUP_MEMU1,"添加新班级&A");
				menu.AppendMenu(0,ID_POPUP_MEMU2,"删除该院系&D");break;
			case 3:
				menu.AppendMenu(0,ID_POPUP_MEMU1,"添加新课程或学生&A");
				menu.AppendMenu(0,ID_POPUP_MEMU2,"删除该班级&D");break;
			case 4:
				menu.AppendMenu(0,ID_POPUP_MEMU1,"添加新成绩&A");
				menu.AppendMenu(0,ID_POPUP_MEMU2,"删除该课程&D");break;
			}
			menu.CheckMenuRadioItem(ID_POPUP_MEMU1,ID_POPUP_MEMU2,ID_POPUP_MEMU1,MF_BYCOMMAND);	
			::GetCursorPos(&point);
			menu.TrackPopupMenu(TPM_RIGHTBUTTON,point.x,point.y,this);
			menu.DestroyMenu();
			return;
	}
	else return;
	flag=true;
	CTreeCtrl::OnRButtonDown(nFlags, point);
}

void MyTree::OnLButtonDown(UINT nFlags, CPoint point) 
{
	flag=false;
	CTreeCtrl::OnLButtonDown(nFlags, point);
}

/*---------------------通过选取菜单项判断操作方法----------------------*/

void MyTree::Operate(UINT nID)
{	
	m_AdoConn.OnInitDBConnect();
	
	switch(nID)
	{
		case ID_POPUP_MEMU1: add();break;
		case ID_POPUP_MEMU2: del();break;
	}
}

/*---------------------添加操作----------------------*/

void MyTree::add()
{
	ADDDLG dlg;
	CHCCPDlg* pdlg=(CHCCPDlg*)GetParent();	
	if(nCount==1||nCount==2)
	{
		if(dlg.DoModal()==IDOK)
		{ 
			CString str;
			str.Format("insert into tree values('%s','%s')",dlg.m_name,leaf111);
			_bstr_t vSQL0;
			vSQL0=(_bstr_t)str;
			m_AdoConn.GetRecordSet(vSQL0);			
			pdlg->CreateTree();
			MessageBox("添加成功!");
		}
	}
	else if(nCount==3)
	{
		if(dlg.DoModal()==IDOK)
		{ 
			if(flag001)
			{
				CString str,str1,str2,jieg,str3,jieg1,qi,jieg2;
				qi=leaf111;
				qi.TrimRight();
				str.Format("insert into tree values('%s','%s')",dlg.m_name,leaf111);
				str1.Format("insert into class values('%s','%s','%f')",dlg.m_cno,dlg.m_name,dlg.m_cgrade);
				str2.Format("select * from class where cno='%s'",dlg.m_cno);
				str3.Format("select root from tree where leaf='%s'",dlg.m_name);
				_bstr_t vSQL0,vSQL1,vSQL2,vSQL3;
				_RecordsetPtr m_pR,m_pR1;
				vSQL0=(_bstr_t)str;
				vSQL1=(_bstr_t)str1;
				vSQL2=(_bstr_t)str2;
				vSQL3=(_bstr_t)str3;
				try
				{
					m_pR=m_AdoConn.GetRecordSet(vSQL2);
					jieg=(LPCTSTR)(_bstr_t)(m_pR->GetCollect("cno"));
					jieg2=(LPCTSTR)(_bstr_t)(m_pR->GetCollect("cname"));
					jieg.TrimRight();
					jieg2.TrimRight();
				}
				catch(...)
				{}
				if(jieg=="")
				{
					m_AdoConn.GetRecordSet(vSQL0);
					m_AdoConn.GetRecordSet(vSQL1);
					MessageBox("添加成功!");
				}
				else
				{
					try
					{
					m_pR1=m_AdoConn.GetRecordSet(vSQL3);
					jieg1=(LPCTSTR)(_bstr_t)(m_pR1->GetCollect("root"));
					jieg1.TrimRight();
					}
					catch(...)
					{}
					if(jieg2!=dlg.m_name)
						MessageBox("添加失败!");
					else
					{
						m_AdoConn.GetRecordSet(vSQL0);
						MessageBox("添加成功!");
					}
				}
				pdlg->CreateTree();
				
			}
			else
			{
				CString str1,str5,str6;
				str5=leaf11;
				str5.TrimRight();
				str6=leaf111;
				str6.TrimRight();
				str1.Format("insert into student values('%s','%s','%s','%s')",dlg.m_cno,dlg.m_name,str5,str6);
				_bstr_t vSQL1;
				vSQL1=(_bstr_t)str1;
				m_AdoConn.GetRecordSet(vSQL1);
				flag123=false;
				MessageBox("添加成功!");
			}
		}
	}
	else if(nCount==4)
	{
		if(dlg.DoModal()==IDOK)
		{ 
			CString str,str2,str3,str4,jieg1;
			_variant_t qiguai;
			str2=leaf111;
			str2.TrimRight();
			str3.Format("select cno from class where cname='%s'",str2);
			_bstr_t vSQL12,vSQL3;
			vSQL12=(_bstr_t)str3;
			_RecordsetPtr m_pre,m_pR1;
			m_pre=m_AdoConn.GetRecordSet(vSQL12);
			qiguai=m_pre->GetCollect("cno");
			str4=(LPCTSTR)(_bstr_t)qiguai;
			str.Format("insert into grade values('%s','%s','%f')",dlg.zhao,str4,dlg.m_cgrade);
			_bstr_t vSQL0;
			vSQL0=(_bstr_t)str;
			try
			{
				str3.Format("select * from grade where sno='%s' and cno='%s'",dlg.zhao,str4);
				vSQL3=(_bstr_t)str3;
				m_pR1=m_AdoConn.GetRecordSet(vSQL3);
				jieg1=(LPCTSTR)(_bstr_t)(m_pR1->GetCollect("sgrade"));
				jieg1.TrimRight();
			}
			catch(...)
			{}
			if(jieg1=="")
			{
				m_AdoConn.GetRecordSet(vSQL0);
				flag123=false;
				MessageBox("添加成功!");
			}
			else
			{
				MessageBox("该学生成绩已存在!");
			}
		}
	}
}

/*---------------------删除操作----------------------*/

void MyTree::del()
{
	CHCCPDlg* pdlg=(CHCCPDlg*)GetParent();
	try
	{
		_RecordsetPtr m_pR1;
		if(nCount==1||nCount==2||nCount==3)
		{
			if(MessageBox("要删除吗?","注意!",MB_YESNO|MB_ICONINFORMATION)==IDYES)
			{
				CString str;
				str.Format("delete from tree where leaf='%s'",leaf111);
				_bstr_t vSQL0;
				vSQL0=(_bstr_t)str;
				m_AdoConn.GetRecordSet(vSQL0);
				pdlg->CreateTree();
				MessageBox("刪除成功!");
			}
		}
		else if(nCount==4)
		{
			if(MessageBox("要删除吗?","注意",MB_YESNO|MB_ICONINFORMATION)==IDYES)
			{
				CString str,str1,str2,str3,jieg;CHCCPDlg* pdlg=(CHCCPDlg*)GetParent();
				str.Format("delete from tree where leaf='%s'",leaf111);
				str1=leaf111;
				str1.TrimRight();
				str2.Format("select * from grade where cno='%s'",str1);
				_bstr_t vSQL0,vSQL1;
				vSQL0=(_bstr_t)str;vSQL1=(_bstr_t)str2;
				m_AdoConn.GetRecordSet(vSQL0);
				m_pR1=m_AdoConn.GetRecordSet(vSQL1);
				jieg=(LPCTSTR)(_bstr_t)(m_pR1->GetCollect("cno"));
				jieg.TrimRight();
				str3.Format("delete from grade where cno='%s'",jieg);
				vSQL1=(_bstr_t)str3;
				
				m_AdoConn.GetRecordSet(vSQL1);
				
				pdlg->CreateTree();
				MessageBox("刪除成功!");
			}
		}
	}
	catch(...)
	{
		pdlg->CreateTree();
	}
}
