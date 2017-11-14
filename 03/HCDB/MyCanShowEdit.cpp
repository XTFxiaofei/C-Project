// MyCanShowEdit.cpp : implementation file
//

#include "stdafx.h"
#include "HCDB.h"
#include "MyCanShowEdit.h"
#include "GATHERIN.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyCanShowEdit

CMyCanShowEdit::CMyCanShowEdit()
{

	
}

CMyCanShowEdit::~CMyCanShowEdit()
{
}


BEGIN_MESSAGE_MAP(CMyCanShowEdit, CEdit)
	//{{AFX_MSG_MAP(CMyCanShowEdit)
	ON_WM_CHAR()
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyCanShowEdit message handlers

void CMyCanShowEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	
	Connect();
    CGATHERIN  *cparent=(CGATHERIN *)GetParent();
	CEdit::OnChar(nChar, nRepCnt, nFlags);
	if(cparent->GetFocus()==&cparent->m_mercidctrl)
        GetMercName();
	//if(cparent->GetFocus()==&cparent->m_mercidctrl)
     //   JustiyProvid();
}

int CMyCanShowEdit::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CEdit::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO: Add your specialized creation code here
	
	return 0;
}

bool CMyCanShowEdit::Connect()
{
  ::CoInitialize(NULL);
   if(m_connection!=NULL)
	   m_connection=NULL;
   CString sqlstr="Provider=SQLOLEDB.1;Persist Security Info=False;User ID=sa;Password=;Initial Catalog=Sales";
   try
   {
	   m_connection.CreateInstance(__uuidof(Connection));
	   HRESULT rs;
	   rs=m_connection->Open((_bstr_t)sqlstr,"","",adConnectUnspecified);
	   if(rs)
	   {
		   ::AfxMessageBox("Á¬½ÓÊ§°Ü");
		   return false;
	   }
   }
   catch(_com_error e)
   { 
	   CString strError;
	   strError.Format("CADOWrong is %s\nCode Meaning is %s\nDescription is %s",e.ErrorMessage(),
		(LPCSTR)e.Source(),(LPCSTR)e.Description());
       ::AfxMessageBox(strError);
	    return false;
   }
   return true;
}

void CMyCanShowEdit::GetMercName()
{
	CGATHERIN  *cparent=(CGATHERIN *)GetParent();
	cparent->UpdateData();
	CString sqlstr;
	sqlstr.Format("select * from tb_merchangiseinfo where id='%s'",cparent->m_mercid);
	m_record=NULL;
	m_record.CreateInstance(__uuidof(Recordset));
	try
	{
      m_record->Open((_variant_t )sqlstr,m_connection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	  if(!m_record->_EOF)
	  {
		  cparent->m_mercname=(LPCSTR)(_bstr_t)m_record->Fields->GetItem("mercname")->Value;
		  cparent->m_merctype=(LPCSTR)(_bstr_t)m_record->Fields->GetItem("spec")->Value;
		  cparent->m_provid=(LPCSTR)(_bstr_t)m_record->Fields->GetItem("provid")->Value;
          cparent->m_uint=(LPCSTR)(_bstr_t)m_record->Fields->GetItem("mercunit")->Value;
		  cparent->m_merctypectrl.EnableWindow(false);
		  cparent->m_mercnuamectrl.EnableWindow(false);
		  cparent->m_providctrl.EnableWindow(false);
          cparent->m_comuint.EnableWindow(false);
	  }
      else
	  {
		  cparent->m_mercname="";
		  cparent->m_merctype="";
		  cparent->m_provid="";
          cparent->m_comuint.SetCurSel(0);
		  cparent->m_merctypectrl.EnableWindow(true);
		  cparent->m_providctrl.EnableWindow(true);
		  cparent->m_mercnuamectrl.EnableWindow(true);
		  cparent->m_comuint.EnableWindow(true);
	  }
	  cparent->UpdateData(false);
	}
	catch(...)
	{
		return ;
	}
}

void CMyCanShowEdit::JustiyProvid()
{
    
}
