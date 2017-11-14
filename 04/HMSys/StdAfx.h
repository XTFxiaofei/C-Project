// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__EDCF97E4_4444_43B9_8B37_A5B149CE3F47__INCLUDED_)
#define AFX_STDAFX_H__EDCF97E4_4444_43B9_8B37_A5B149CE3F47__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#import "c:\program files\common files\system\ado\msado15.dll" no_namespace rename("EOF","adoEOF")
#define CATCH_ERROR												\
			catch (_com_error e)								\
			{													\
				CString strComError;							\
				strComError.Format("错误编号: %08lx\r\n\r\n错误信息: %s\r\n\r\n错误源: %s\r\n\r\n错误描述: %s", \
									e.Error(),                  \
									e.ErrorMessage(),           \
									(LPCSTR) e.Source(),        \
									(LPCSTR) e.Description());  \
				SetDlgItemText(IDC_MESSAGE,strComError);		\
				::MessageBox(NULL,strComError,"提示",MB_OK | MB_ICONWARNING); \
			}
#define SET_TEXT SetDlgItemText(IDC_MESSAGE,"!\r\n\r\n\r\n\r\n\t\t操作成功完成!");
#define IDC_MESSAGE 324650
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__EDCF97E4_4444_43B9_8B37_A5B149CE3F47__INCLUDED_)
