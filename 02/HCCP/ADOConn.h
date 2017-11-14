// ADOConn.h: interface for the ADOConn class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#if !defined(AFX_ADOCONN_H__CF72097A_C007_4C0B_8B55_324170C47F2F__INCLUDED_)
#define AFX_ADOCONN_H__CF72097A_C007_4C0B_8B55_324170C47F2F__INCLUDED_
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class ADOConn  
{
public:
	ADOConn();
	virtual ~ADOConn();
	_ConnectionPtr m_pConnection;//添加一个指向Connection对象的指针
	_RecordsetPtr m_pRecordset;//添加一个指向Recordset对象的指针
	void OnInitDBConnect();//初始化—连接数据库
	_RecordsetPtr &GetRecordSet(_bstr_t bstrSQL);//执行查询
	BOOL ExecuteSQL(_bstr_t bstrSQL);//执行SQL语句,Insert Update_variant_t
	void ExitConnect();

};

#endif // !defined(AFX_ADOCONN_H__CF72097A_C007_4C0B_8B55_324170C47F2F__INCLUDED_)
