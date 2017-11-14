// MyEdit.cpp : implementation file
//

#include "stdafx.h"
#include "HCDB.h"
#include "MyEdit.h"
#include "ForeMange.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyEdit
extern CHCDBApp theApp;
CMyEdit::CMyEdit()
{
	querystr="";
	m_backnum=0;
	m_querystr="";

}

CMyEdit::~CMyEdit()
{
}


BEGIN_MESSAGE_MAP(CMyEdit, CEdit)
	//{{AFX_MSG_MAP(CMyEdit)
	ON_WM_CHAR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyEdit message handlers

void CMyEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	
	HRESULT rs;
	
	CEdit::OnChar(nChar, nRepCnt, nFlags);	
	CForeMange *cwnd=(CForeMange *)GetParent();
	cwnd->UpdateData();
    m_querystr=cwnd->m_id;
	CString sqlstr;
	sqlstr.Format("select * from tb_merchangiseinfo where id='%s'",m_querystr);

	try
	{
		cwnd->m_record=NULL;
		cwnd->m_record.CreateInstance(__uuidof(Recordset));
        rs=cwnd->m_record->Open((_variant_t )sqlstr,theApp.m_connection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
		Refrish();
	}
    catch(_com_error e)
	{
		CString strError;
		strError.Format("CADOWrong is %s\nCode Meaning is %s\nDescription is %s",e.ErrorMessage(),
		(LPCSTR)e.Source(),(LPCSTR)e.Description());
       ::AfxMessageBox(strError);
	}

	
}

void CMyEdit::Refrish()
{
    CForeMange *cwnd=(CForeMange *)GetParent();
	cwnd->m_list.DeleteItems();
	int j=cwnd->m_record->GetRecordCount();
	int i=InsertItem;
    CString str;
	while(!cwnd->m_record->_EOF)
	{
		_variant_t var;
		var=cwnd->m_record->Fields->GetItem("id")->Value;
		cwnd->m_id=(LPSTR)(_bstr_t)var;
		CString str;
		str.Format("%d",i+1);
		cwnd->m_list.InsertItem(i,str);
		cwnd->m_list.SetItemText(i,1,(LPSTR)(_bstr_t)var);
		
		var=cwnd->m_record->Fields->GetItem("mercname")->Value;
        cwnd->m_list.SetItemText(i,2,(LPSTR)(_bstr_t)var);
		var=cwnd->m_record->Fields->GetItem("outprice")->Value;
        cwnd->m_list.SetItemText(i,4,(LPSTR)(_bstr_t)var);	
        var=cwnd->m_record->Fields->GetItem("discount")->Value;	
        cwnd->m_list.SetItemText(i,5,(LPSTR)(_bstr_t)var);
		cwnd->m_singlediscount=(LPSTR)(_bstr_t)var;
		cwnd->UpdateData(false);
		i++;
		cwnd->m_record->MoveNext();
	}
    //InsertItem=0;
}
