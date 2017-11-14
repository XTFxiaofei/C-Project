# Microsoft Developer Studio Project File - Name="HCDB" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=HCDB - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "HCDB.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "HCDB.mak" CFG="HCDB - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "HCDB - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "HCDB - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "HCDB - Win32 Release"

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

!ELSEIF  "$(CFG)" == "HCDB - Win32 Debug"

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

# Name "HCDB - Win32 Release"
# Name "HCDB - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AnotherView.cpp
# End Source File
# Begin Source File

SOURCE=.\BACKUPDLG.cpp
# End Source File
# Begin Source File

SOURCE=.\BMP.cpp
# End Source File
# Begin Source File

SOURCE=.\ForeMange.cpp
# End Source File
# Begin Source File

SOURCE=.\GATHERIN.cpp
# End Source File
# Begin Source File

SOURCE=.\GATHEROUT.cpp
# End Source File
# Begin Source File

SOURCE=.\GfxGroupEdit.cpp
# End Source File
# Begin Source File

SOURCE=.\GfxOutBarCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\GfxPopupMenu.cpp
# End Source File
# Begin Source File

SOURCE=.\HCDB.cpp
# End Source File
# Begin Source File

SOURCE=.\HCDB.rc
# End Source File
# Begin Source File

SOURCE=.\HCDBDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\HCDBView.cpp
# End Source File
# Begin Source File

SOURCE=.\Hutext.cpp
# End Source File
# Begin Source File

SOURCE=.\INDETAIL.cpp
# End Source File
# Begin Source File

SOURCE=.\INSTOCKMANGE.cpp
# End Source File
# Begin Source File

SOURCE=.\INSTOCKQUERY.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\MQQAppearanceDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MyCanShowEdit.cpp
# End Source File
# Begin Source File

SOURCE=.\MyEdit.cpp
# End Source File
# Begin Source File

SOURCE=.\MyEditShowList.cpp
# End Source File
# Begin Source File

SOURCE=.\MyList.cpp
# End Source File
# Begin Source File

SOURCE=.\MyListCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\MyNumEdit.cpp
# End Source File
# Begin Source File

SOURCE=.\OUTDETAIL.cpp
# End Source File
# Begin Source File

SOURCE=.\OUTSTOCKMANGE.cpp
# End Source File
# Begin Source File

SOURCE=.\OUTSTOCKQUERY.cpp
# End Source File
# Begin Source File

SOURCE=.\PASSDLG.cpp
# End Source File
# Begin Source File

SOURCE=.\PROVDLG.cpp
# End Source File
# Begin Source File

SOURCE=.\RESTOREDLG.cpp
# End Source File
# Begin Source File

SOURCE=.\SALESQUERY.cpp
# End Source File
# Begin Source File

SOURCE=.\SALESQUITDLG.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\STOCKMANAGE.cpp
# End Source File
# Begin Source File

SOURCE=.\SYSDLG.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AnotherView.h
# End Source File
# Begin Source File

SOURCE=.\BACKUPDLG.h
# End Source File
# Begin Source File

SOURCE=.\BMP.h
# End Source File
# Begin Source File

SOURCE=.\ForeMange.h
# End Source File
# Begin Source File

SOURCE=.\GATHERIN.h
# End Source File
# Begin Source File

SOURCE=.\GATHEROUT.h
# End Source File
# Begin Source File

SOURCE=.\GfxGroupEdit.h
# End Source File
# Begin Source File

SOURCE=.\GfxOutBarCtrl.h
# End Source File
# Begin Source File

SOURCE=.\GfxPopupMenu.h
# End Source File
# Begin Source File

SOURCE=.\HCDB.h
# End Source File
# Begin Source File

SOURCE=.\HCDBDoc.h
# End Source File
# Begin Source File

SOURCE=.\HCDBView.h
# End Source File
# Begin Source File

SOURCE=.\Hutext.h
# End Source File
# Begin Source File

SOURCE=.\INDETAIL.h
# End Source File
# Begin Source File

SOURCE=.\INSTOCKMANGE.h
# End Source File
# Begin Source File

SOURCE=.\INSTOCKQUERY.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\MQQAppearanceDlg.h
# End Source File
# Begin Source File

SOURCE=.\MyCanShowEdit.h
# End Source File
# Begin Source File

SOURCE=.\MyEdit.h
# End Source File
# Begin Source File

SOURCE=.\MyEditShowList.h
# End Source File
# Begin Source File

SOURCE=.\MyList.h
# End Source File
# Begin Source File

SOURCE=.\MyListCtrl.h
# End Source File
# Begin Source File

SOURCE=.\MyNumEdit.h
# End Source File
# Begin Source File

SOURCE=.\OUTDETAIL.h
# End Source File
# Begin Source File

SOURCE=.\OUTSTOCKMANGE.h
# End Source File
# Begin Source File

SOURCE=.\OUTSTOCKQUERY.h
# End Source File
# Begin Source File

SOURCE=.\PASSDLG.h
# End Source File
# Begin Source File

SOURCE=.\PROVDLG.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\RESTOREDLG.h
# End Source File
# Begin Source File

SOURCE=.\SALESQUERY.h
# End Source File
# Begin Source File

SOURCE=.\SALESQUITDLG.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\STOCKMANAGE.h
# End Source File
# Begin Source File

SOURCE=.\SYSDLG.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\Bliss.bmp
# End Source File
# Begin Source File

SOURCE=.\res\cursor1.cur
# End Source File
# Begin Source File

SOURCE=.\res\dragging.cur
# End Source File
# Begin Source File

SOURCE=.\res\handcur.cur
# End Source File
# Begin Source File

SOURCE=.\res\HCDB.ico
# End Source File
# Begin Source File

SOURCE=.\res\HCDB.rc2
# End Source File
# Begin Source File

SOURCE=.\res\HCDBDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\LargeIcon.bmp
# End Source File
# Begin Source File

SOURCE=.\res\nodraggi.cur
# End Source File
# Begin Source File

SOURCE=.\res\SmallIcon.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
