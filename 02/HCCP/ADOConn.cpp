// ADOConn.cpp: implementation of the ADOConn class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ADOConn.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ADOConn::ADOConn()
{

}

ADOConn::~ADOConn()
{

}

void ADOConn::OnInitDBConnect()
{
	
	::CoInitialize(NULL);  //初始化OLE/COM库环境
	try
	{
		m_pConnection.CreateInstance("ADODB.Connection");  //创建connection对象		
		m_pConnection->Open("driver={SQL Server};Server=HC\\MSSQL2008;Database=HCCP;","","",adModeUnknown);
	  //m_pConnection->Open("driver={SQL Server};Server=HC\\MSSQL2008;Database=HCCP;UID=sa;PWD=","","",adModeUnknown);  //设置连接字符串,必须是BSTR型或者_bstr_t类型
	}
	catch(_com_error e)  //捕捉异常
	{
		AfxMessageBox(e.Description());//显示错误信息
	}
}

_RecordsetPtr& ADOConn::GetRecordSet(_bstr_t bstrSQL)
{
	try
	{		
		if(m_pConnection==NULL)  //连接数据库,如果connection对象为空,则重新连接数据库8
			OnInitDBConnect();
		
		m_pRecordset.CreateInstance(__uuidof(Recordset));  //创建记录集对象		
		m_pRecordset->Open(bstrSQL,m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);  //取得集中的记录
	}
	
	catch(_com_error e)  //捕捉异常
	{
		AfxMessageBox(e.Description());  //显示错误信息
	}
	return m_pRecordset;  //返回记录集
}

BOOL ADOConn::ExecuteSQL(_bstr_t bstrSQL)
{
	try
	{		
		if(m_pConnection==NULL)  //是否已经连接到数据库
			OnInitDBConnect();
		m_pConnection->Execute(bstrSQL,NULL,adCmdText);
		return true;
	}
	
	catch(_com_error e)  //捕捉异常
	{
		AfxMessageBox(e.Description());  //显示错误信息
		return false;
	}
}

void ADOConn::ExitConnect()
{	
	if(m_pRecordset!=NULL)  //关闭记录集和连接
	{
		m_pRecordset->Close();
		m_pConnection->Close();
	}
	
	::CoUninitialize();  //释放环境
}