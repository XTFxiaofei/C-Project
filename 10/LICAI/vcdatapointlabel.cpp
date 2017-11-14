// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


#include "stdafx.h"
#include "vcdatapointlabel.h"

// Dispatch interfaces referenced by this interface
#include "VcBackdrop.h"
#include "VcFont.h"
#include "VcLCoor.h"
#include "vctextlayout.h"
#include "font.h"


/////////////////////////////////////////////////////////////////////////////
// CVcDataPointLabel properties

/////////////////////////////////////////////////////////////////////////////
// CVcDataPointLabel operations

CString CVcDataPointLabel::GetText()
{
	CString result;
	InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CVcDataPointLabel::SetText(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CVcBackdrop CVcDataPointLabel::GetBackdrop()
{
	LPDISPATCH pDispatch;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&pDispatch, NULL);
	return CVcBackdrop(pDispatch);
}

CVcFont CVcDataPointLabel::GetVtFont()
{
	LPDISPATCH pDispatch;
	InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&pDispatch, NULL);
	return CVcFont(pDispatch);
}

CVcLCoor CVcDataPointLabel::GetOffset()
{
	LPDISPATCH pDispatch;
	InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&pDispatch, NULL);
	return CVcLCoor(pDispatch);
}

CVcTextLayout CVcDataPointLabel::GetTextLayout()
{
	LPDISPATCH pDispatch;
	InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&pDispatch, NULL);
	return CVcTextLayout(pDispatch);
}

long CVcDataPointLabel::GetLocationType()
{
	long result;
	InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CVcDataPointLabel::SetLocationType(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL CVcDataPointLabel::GetCustom()
{
	BOOL result;
	InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CVcDataPointLabel::SetCustom(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

short CVcDataPointLabel::GetComponent()
{
	short result;
	InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_I2, (void*)&result, NULL);
	return result;
}

void CVcDataPointLabel::SetComponent(short nNewValue)
{
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long CVcDataPointLabel::GetLineStyle()
{
	long result;
	InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CVcDataPointLabel::SetLineStyle(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

CString CVcDataPointLabel::GetValueFormat()
{
	CString result;
	InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CVcDataPointLabel::SetValueFormat(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0xa, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString CVcDataPointLabel::GetPercentFormat()
{
	CString result;
	InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void CVcDataPointLabel::SetPercentFormat(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0xb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

short CVcDataPointLabel::GetTextLength()
{
	short result;
	InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_I2, (void*)&result, NULL);
	return result;
}

void CVcDataPointLabel::SetRefFont(LPDISPATCH newValue)
{
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0xf, DISPATCH_PROPERTYPUTREF, VT_EMPTY, NULL, parms,
		 newValue);
}

COleFont CVcDataPointLabel::GetFont()
{
	LPDISPATCH pDispatch;
	InvokeHelper(0xf, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&pDispatch, NULL);
	return COleFont(pDispatch);
}

void CVcDataPointLabel::ResetCustomLabel()
{
	InvokeHelper(0xd, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CVcDataPointLabel::Select()
{
	InvokeHelper(0xe, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}