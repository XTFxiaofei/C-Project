# Microsoft Developer Studio Project File - Name="HCOK" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=HCOK - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "HCOK.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "HCOK.mak" CFG="HCOK - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "HCOK - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "HCOK - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "HCOK - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "HCOK - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "HCOK - Win32 Release"
# Name "HCOK - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\ADDSGEDLG.cpp
# End Source File
# Begin Source File

SOURCE=.\ADMIN.cpp
# End Source File
# Begin Source File

SOURCE=.\ADOConn.cpp
# End Source File
# Begin Source File

SOURCE=.\BYPINYINDLG.cpp
# End Source File
# Begin Source File

SOURCE=.\BYSGRDLG.cpp
# End Source File
# Begin Source File

SOURCE=.\BYSONGTYPDLG.cpp
# End Source File
# Begin Source File

SOURCE=.\BYZISHUDLG.cpp
# End Source File
# Begin Source File

SOURCE=.\HCOK.cpp
# End Source File
# Begin Source File

SOURCE=.\HCOK.rc
# End Source File
# Begin Source File

SOURCE=.\HCOKDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Hutext.cpp
# End Source File
# Begin Source File

SOURCE=.\MADDSONG.cpp
# End Source File
# Begin Source File

SOURCE=.\ManageDLG.cpp
# End Source File
# Begin Source File

SOURCE=.\mediaplayer2.cpp
# End Source File
# Begin Source File

SOURCE=.\mediaplayerdvd.cpp
# End Source File
# Begin Source File

SOURCE=.\MODIFISINGER.cpp
# End Source File
# Begin Source File

SOURCE=.\PreGoto.cpp
# End Source File
# Begin Source File

SOURCE=.\PreParent.cpp
# End Source File
# Begin Source File

SOURCE=.\PreView.cpp
# End Source File
# Begin Source File

SOURCE=.\SELECTEDDLG.cpp
# End Source File
# Begin Source File

SOURCE=.\SETPRICE.cpp
# End Source File
# Begin Source File

SOURCE=.\SINGIN.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\UserPrintDlg.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\ADDSGEDLG.h
# End Source File
# Begin Source File

SOURCE=.\ADMIN.h
# End Source File
# Begin Source File

SOURCE=.\ADOConn.h
# End Source File
# Begin Source File

SOURCE=.\BYPINYINDLG.h
# End Source File
# Begin Source File

SOURCE=.\BYSGRDLG.h
# End Source File
# Begin Source File

SOURCE=.\BYSONGTYPDLG.h
# End Source File
# Begin Source File

SOURCE=.\BYZISHUDLG.h
# End Source File
# Begin Source File

SOURCE=.\HCOK.h
# End Source File
# Begin Source File

SOURCE=.\HCOKDlg.h
# End Source File
# Begin Source File

SOURCE=.\Hutext.h
# End Source File
# Begin Source File

SOURCE=.\MADDSONG.h
# End Source File
# Begin Source File

SOURCE=.\ManageDLG.h
# End Source File
# Begin Source File

SOURCE=.\mediaplayer2.h
# End Source File
# Begin Source File

SOURCE=.\mediaplayerdvd.h
# End Source File
# Begin Source File

SOURCE=.\MODIFISINGER.h
# End Source File
# Begin Source File

SOURCE=.\PreGoto.h
# End Source File
# Begin Source File

SOURCE=.\PreParent.h
# End Source File
# Begin Source File

SOURCE=.\PreView.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\SELECTEDDLG.h
# End Source File
# Begin Source File

SOURCE=.\SETPRICE.h
# End Source File
# Begin Source File

SOURCE=.\SINGIN.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\UserPrintDlg.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\IMAGE\bmp_back.bmp
# End Source File
# Begin Source File

SOURCE=.\res\HCOK.ico
# End Source File
# Begin Source File

SOURCE=.\res\HCOK.rc2
# End Source File
# Begin Source File

SOURCE=.\IMAGE\preview.ico
# End Source File
# Begin Source File

SOURCE=.\IMAGE\toolbar1.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
# Section HCOK : {20D4F5E0-5475-11D2-9774-0000F80855E6}
# 	2:5:Class:CMediaPlayer2
# 	2:10:HeaderFile:mediaplayer2.h
# 	2:8:ImplFile:mediaplayer2.cpp
# End Section
# Section HCOK : {22D6F312-B0F6-11D0-94AB-0080C74C7E95}
# 	2:21:DefaultSinkHeaderFile:mediaplayer2.h
# 	2:16:DefaultSinkClass:CMediaPlayer2
# End Section
# Section HCOK : {746EB440-3835-11D2-9774-0000F80855E6}
# 	2:5:Class:CMediaPlayerDvd
# 	2:10:HeaderFile:mediaplayerdvd.h
# 	2:8:ImplFile:mediaplayerdvd.cpp
# End Section
