
// SkinMagic.h : Í·ÎÄ¼þ
//

#pragma once

class CDllLoad
{
public:
	CDllLoad(LPCTSTR lpszName)
	{
		m_hModule = ::LoadLibrary(lpszName);
	}
	~CDllLoad()
	{	
		::FreeLibrary(m_hModule);	 
		m_hModule = NULL;
	}
	operator  HMODULE() { return m_hModule;}

protected:
	HMODULE m_hModule;
};

class CSkinMagic
{
public:
	virtual ~CSkinMagic()
	{
		if (m_fnExitSkinMagicLib)
			m_fnExitSkinMagicLib();
	}
	CSkinMagic()
		: m_SkinDll("SkinMagicTrial.dll")
		, m_fnInitSkinMagicLib(NULL)
		, m_fnLoadSkinFile(NULL)
		, m_fnSetDialogSkin(NULL)
		, m_fnSetWindowSkin(NULL)
		, m_fnExitSkinMagicLib(NULL)
	{
		InitSkinMagicLib();
	}

	int InitSkinMagicLib()
	{
		m_fnInitSkinMagicLib = (INITSKINMAGICLIB)GetProcAddress(HMODULE(m_SkinDll), "InitSkinMagicLib");
		m_fnLoadSkinFile = (LOADSKINFILE)GetProcAddress(HMODULE(m_SkinDll), "LoadSkinFile");
		m_fnSetDialogSkin = (SETDIALOGSKIN)GetProcAddress(HMODULE(m_SkinDll), "SetDialogSkin");
		m_fnSetWindowSkin = (SETWINDOWSKIN)GetProcAddress(HMODULE(m_SkinDll), "SetWindowSkin");
		m_fnExitSkinMagicLib = (EXITSKINMAGICLIB)GetProcAddress(HMODULE(m_SkinDll), "ExitSkinMagicLib");

		if (m_fnInitSkinMagicLib)
			return m_fnInitSkinMagicLib(::GetModuleHandle(NULL), "Demo", NULL, NULL);

		return 0;
	}

	int LoadSkinFile( LPCTSTR lpSkinFile )
	{
		if (m_fnLoadSkinFile)
			return m_fnLoadSkinFile(lpSkinFile);
		return 0;
	}

	int  SetDialogSkin( LPCTSTR szSkinName )
	{
		if (m_fnSetDialogSkin)
			return m_fnSetDialogSkin(szSkinName);
		return 0;
	}

	int SetWindowSkin(HWND hWnd, LPCTSTR szSkinName)
	{
		if (m_fnSetWindowSkin)
			return m_fnSetWindowSkin(hWnd, szSkinName);
		return 0;
	}

private:
	CDllLoad		m_SkinDll;

	typedef int (__stdcall * INITSKINMAGICLIB)( HINSTANCE hInstance, 
								 LPCTSTR lpApplication , 
								 LPCTSTR lpReserved1,
								 LPCTSTR lpReserved2 );
	typedef int (__stdcall * LOADSKINFILE) ( LPCTSTR lpSkinFile );
	typedef int (__stdcall * SETDIALOGSKIN)( LPCTSTR szSkinName );
	typedef int (__stdcall * SETWINDOWSKIN)( HWND hWnd, LPCTSTR szSkinName );
	typedef int (__stdcall * EXITSKINMAGICLIB)();

	INITSKINMAGICLIB	m_fnInitSkinMagicLib;
	LOADSKINFILE		m_fnLoadSkinFile;
	SETDIALOGSKIN		m_fnSetDialogSkin;
	SETWINDOWSKIN		m_fnSetWindowSkin;
	EXITSKINMAGICLIB	m_fnExitSkinMagicLib;

};