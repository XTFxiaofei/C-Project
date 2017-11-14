#if !defined(AFX_MORECTANGLE_H__E2F63773_FAA5_4F98_905C_2F416FAEB8F5__INCLUDED_)
#define AFX_MORECTANGLE_H__E2F63773_FAA5_4F98_905C_2F416FAEB8F5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CMoPoint;
class CMoPoints;

/////////////////////////////////////////////////////////////////////////////
// CMoRectangle wrapper class

class CMoRectangle : public COleDispatchDriver
{
public:
	CMoRectangle() {}		// Calls COleDispatchDriver default constructor
	CMoRectangle(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CMoRectangle(const CMoRectangle& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:
	double GetLeft();
	void SetLeft(double);
	double GetRight();
	void SetRight(double);
	double GetTop();
	void SetTop(double);
	double GetBottom();
	void SetBottom(double);
	double GetWidth();
	void SetWidth(double);
	double GetHeight();
	void SetHeight(double);
	CMoPoint GetCenter();
	void SetCenter(LPDISPATCH);
	double GetFloor();
	void SetFloor(double);
	double GetCeiling();
	void SetCeiling(double);
	double GetDepth();
	void SetDepth(double);
	long GetShapeType();
	void SetShapeType(long);

// Operations
public:
	void ScaleRectangle(double scaleFactor);
	void Offset(double deltaX, double deltaY);
	void Inset(double deltaX, double deltaY);
	BOOL IsPointIn(LPDISPATCH Point);
	BOOL Intersects(LPDISPATCH Rectangle);
	double DistanceTo(LPDISPATCH shape);
	CMoPoints GetCrossings(LPDISPATCH shape);
	LPDISPATCH Difference(LPDISPATCH anotherShape, const VARIANT& Extent);
	LPDISPATCH Intersect(LPDISPATCH anotherShape, const VARIANT& Extent);
	LPDISPATCH Xor(LPDISPATCH anotherShape, const VARIANT& Extent);
	LPDISPATCH Union(LPDISPATCH anotherShape, const VARIANT& Extent);
	LPDISPATCH Buffer(double distance, const VARIANT& Extent);
	CMoRectangle GetExtent();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MORECTANGLE_H__E2F63773_FAA5_4F98_905C_2F416FAEB8F5__INCLUDED_)