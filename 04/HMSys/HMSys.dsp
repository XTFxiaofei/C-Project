# Microsoft Developer Studio Project File - Name="HMSys" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=HMSys - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "HMSys.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "HMSys.mak" CFG="HMSys - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "HMSys - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "HMSys - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "HMSys - Win32 Release"

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

!ELSEIF  "$(CFG)" == "HMSys - Win32 Debug"

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

# Name "HMSys - Win32 Release"
# Name "HMSys - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\BackupDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\CheckInfoDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\CheckManageDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ClockST.cpp
# End Source File
# Begin Source File

SOURCE=.\DepartManageDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\EmpAddDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\EmpIndexDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\EmpInfoManageDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\EmpUpdateDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\HMSys.cpp
# End Source File
# Begin Source File

SOURCE=.\HMSys.rc
# End Source File
# Begin Source File

SOURCE=.\HMSysDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\HMSysView.cpp
# End Source File
# Begin Source File

SOURCE=.\HolidayManageDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\LoadDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\OverTimeDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\RestoreDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\UpdatePwdDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\UserManageDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\WageCalDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\WageDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\WageManageDlg.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\BackupDlg.h
# End Source File
# Begin Source File

SOURCE=.\CheckInfoDlg.h
# End Source File
# Begin Source File

SOURCE=.\CheckManageDlg.h
# End Source File
# Begin Source File

SOURCE=.\ClockST.h
# End Source File
# Begin Source File

SOURCE=.\DepartManageDlg.h
# End Source File
# Begin Source File

SOURCE=.\EmpAddDlg.h
# End Source File
# Begin Source File

SOURCE=.\EmpIndexDlg.h
# End Source File
# Begin Source File

SOURCE=.\EmpInfoManageDlg.h
# End Source File
# Begin Source File

SOURCE=.\EmpUpdateDlg.h
# End Source File
# Begin Source File

SOURCE=.\HMSys.h
# End Source File
# Begin Source File

SOURCE=.\HMSysDoc.h
# End Source File
# Begin Source File

SOURCE=.\HMSysView.h
# End Source File
# Begin Source File

SOURCE=.\HolidayManageDlg.h
# End Source File
# Begin Source File

SOURCE=.\LoadDlg.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\OverTimeDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\RestoreDlg.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\UpdatePwdDlg.h
# End Source File
# Begin Source File

SOURCE=.\UserManageDlg.h
# End Source File
# Begin Source File

SOURCE=.\WageCalDlg.h
# End Source File
# Begin Source File

SOURCE=.\WageDlg.h
# End Source File
# Begin Source File

SOURCE=.\WageManageDlg.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\bookmark_add.ico
# End Source File
# Begin Source File

SOURCE=.\res\bookmarks_list_add.ico
# End Source File
# Begin Source File

SOURCE=.\res\button_cancel.ico
# End Source File
# Begin Source File

SOURCE=.\res\ClockST_big.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ClockST_pane.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ClockST_small.bmp
# End Source File
# Begin Source File

SOURCE=.\res\default1.bin
# End Source File
# Begin Source File

SOURCE=.\res\delete_group.ico
# End Source File
# Begin Source File

SOURCE=.\res\edit.ico
# End Source File
# Begin Source File

SOURCE=.\res\exec.ico
# End Source File
# Begin Source File

SOURCE=.\res\Exit.ico
# End Source File
# Begin Source File

SOURCE=.\res\hand.cur
# End Source File
# Begin Source File

SOURCE=.\res\HMSys.ico
# End Source File
# Begin Source File

SOURCE=.\res\HMSys.rc2
# End Source File
# Begin Source File

SOURCE=.\res\HMSysDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\unlock.ico
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
