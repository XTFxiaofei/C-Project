# Microsoft Developer Studio Project File - Name="HCCP" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=HCCP - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "HCCP.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "HCCP.mak" CFG="HCCP - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "HCCP - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "HCCP - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "HCCP - Win32 Release"

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

!ELSEIF  "$(CFG)" == "HCCP - Win32 Debug"

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
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
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

# Name "HCCP - Win32 Release"
# Name "HCCP - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\ADDDLG.cpp
# End Source File
# Begin Source File

SOURCE=.\ADOConn.cpp
# End Source File
# Begin Source File

SOURCE=.\HCCP.cpp
# End Source File
# Begin Source File

SOURCE=.\HCCP.rc
# End Source File
# Begin Source File

SOURCE=.\HCCPDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Hutext.cpp
# End Source File
# Begin Source File

SOURCE=.\JIEGUO.cpp
# End Source File
# Begin Source File

SOURCE=.\MyTree.cpp
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

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\XKXFXG.cpp
# End Source File
# Begin Source File

SOURCE=.\XSCJCX.cpp
# End Source File
# Begin Source File

SOURCE=.\XSCJPX.cpp
# End Source File
# Begin Source File

SOURCE=.\XSCJXG.cpp
# End Source File
# Begin Source File

SOURCE=.\XSZHPC.cpp
# End Source File
# Begin Source File

SOURCE=.\ZHPCDLG.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\ADDDLG.h
# End Source File
# Begin Source File

SOURCE=.\ADOConn.h
# End Source File
# Begin Source File

SOURCE=.\HCCP.h
# End Source File
# Begin Source File

SOURCE=.\HCCPDlg.h
# End Source File
# Begin Source File

SOURCE=.\Hutext.h
# End Source File
# Begin Source File

SOURCE=.\JIEGUO.h
# End Source File
# Begin Source File

SOURCE=.\MyTree.h
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

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\XKXFXG.h
# End Source File
# Begin Source File

SOURCE=.\XSCJCX.h
# End Source File
# Begin Source File

SOURCE=.\XSCJPX.h
# End Source File
# Begin Source File

SOURCE=.\XSCJXG.h
# End Source File
# Begin Source File

SOURCE=.\XSZHPC.h
# End Source File
# Begin Source File

SOURCE=.\ZHPCDLG.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\ban.bmp
# End Source File
# Begin Source File

SOURCE=.\res\HCCP.ico
# End Source File
# Begin Source File

SOURCE=.\res\HCCP.rc2
# End Source File
# Begin Source File

SOURCE=.\IMAGE\bmp_back.bmp
# End Source File
# Begin Source File

SOURCE="..\新建文件夹\KOBE\IMAGE\bmp_back.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\ji.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ke.bmp
# End Source File
# Begin Source File

SOURCE=.\IMAGE\preview.ico
# End Source File
# Begin Source File

SOURCE="..\新建文件夹\KOBE\IMAGE\preview.ico"
# End Source File
# Begin Source File

SOURCE=.\IMAGE\toolbar1.bmp
# End Source File
# Begin Source File

SOURCE="..\新建文件夹\KOBE\IMAGE\toolbar1.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\TreeBoot.bmp
# End Source File
# Begin Source File

SOURCE=.\res\xh.bmp
# End Source File
# Begin Source File

SOURCE=.\res\xi.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
