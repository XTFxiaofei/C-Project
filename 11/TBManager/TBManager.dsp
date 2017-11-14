# Microsoft Developer Studio Project File - Name="TBManager" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=TBManager - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "TBManager.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "TBManager.mak" CFG="TBManager - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "TBManager - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "TBManager - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "TBManager - Win32 Release"

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

!ELSEIF  "$(CFG)" == "TBManager - Win32 Debug"

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

# Name "TBManager - Win32 Release"
# Name "TBManager - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\ADDDLG.cpp
# End Source File
# Begin Source File

SOURCE=.\ado.cpp
# End Source File
# Begin Source File

SOURCE=.\BACKUPDLG.cpp
# End Source File
# Begin Source File

SOURCE=.\HandPapers.cpp
# End Source File
# Begin Source File

SOURCE=.\LeftView.cpp
# End Source File
# Begin Source File

SOURCE=.\LoginDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\msword.cpp
# End Source File
# Begin Source File

SOURCE=.\MyTreeCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\QueryDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\RESTOREDLG.cpp
# End Source File
# Begin Source File

SOURCE=.\RightManager.cpp
# End Source File
# Begin Source File

SOURCE=.\RightView.cpp
# End Source File
# Begin Source File

SOURCE=.\ShowCondition.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\TABDLG1.cpp
# End Source File
# Begin Source File

SOURCE=.\TABDLG2.cpp
# End Source File
# Begin Source File

SOURCE=.\TABDLG3.cpp
# End Source File
# Begin Source File

SOURCE=.\TABDLG4.cpp
# End Source File
# Begin Source File

SOURCE=.\TBManager.cpp
# End Source File
# Begin Source File

SOURCE=.\TBManager.rc
# End Source File
# Begin Source File

SOURCE=.\TBManagerDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\TBManagerView.cpp
# End Source File
# Begin Source File

SOURCE=.\TrackLookButton.cpp
# End Source File
# Begin Source File

SOURCE=.\USERDLG.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\ADDDLG.h
# End Source File
# Begin Source File

SOURCE=.\ado.h
# End Source File
# Begin Source File

SOURCE=.\BACKUPDLG.h
# End Source File
# Begin Source File

SOURCE=.\HandPapers.h
# End Source File
# Begin Source File

SOURCE=.\LeftView.h
# End Source File
# Begin Source File

SOURCE=.\LoginDlg.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\msword.h
# End Source File
# Begin Source File

SOURCE=.\MyTreeCtrl.h
# End Source File
# Begin Source File

SOURCE=.\QueryDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\RESTOREDLG.h
# End Source File
# Begin Source File

SOURCE=.\RightManager.h
# End Source File
# Begin Source File

SOURCE=.\RightView.h
# End Source File
# Begin Source File

SOURCE=.\ShowCondition.h
# End Source File
# Begin Source File

SOURCE=.\SkinMagic.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\TABDLG1.h
# End Source File
# Begin Source File

SOURCE=.\TABDLG2.h
# End Source File
# Begin Source File

SOURCE=.\TABDLG3.h
# End Source File
# Begin Source File

SOURCE=.\TABDLG4.h
# End Source File
# Begin Source File

SOURCE=.\TBManager.h
# End Source File
# Begin Source File

SOURCE=.\TBManagerDoc.h
# End Source File
# Begin Source File

SOURCE=.\TBManagerView.h
# End Source File
# Begin Source File

SOURCE=.\TrackLookButton.h
# End Source File
# Begin Source File

SOURCE=.\USERDLG.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=".\res\(2)Folder-open.ico"
# End Source File
# Begin Source File

SOURCE=.\res\1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\11.bmp
# End Source File
# Begin Source File

SOURCE=.\res\2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\22.bmp
# End Source File
# Begin Source File

SOURCE=.\res\3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\33.bmp
# End Source File
# Begin Source File

SOURCE=.\res\4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\44.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap11.bmp
# End Source File
# Begin Source File

SOURCE=".\res\Click Me.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\Daffodil1.ico
# End Source File
# Begin Source File

SOURCE=".\res\Download Arrow.ico"
# End Source File
# Begin Source File

SOURCE=.\res\EMD.ico
# End Source File
# Begin Source File

SOURCE=.\res\fight.ico
# End Source File
# Begin Source File

SOURCE=.\res\Flower1.ico
# End Source File
# Begin Source File

SOURCE=".\Key manager.ico"
# End Source File
# Begin Source File

SOURCE=.\res\Lilac.ico
# End Source File
# Begin Source File

SOURCE=".\res\Mac OS X Modern Icon 10.ico"
# End Source File
# Begin Source File

SOURCE=".\res\Mac OS X Modern Icon 13.ico"
# End Source File
# Begin Source File

SOURCE=.\res\TBManager.ico
# End Source File
# Begin Source File

SOURCE=.\res\TBManager.rc2
# End Source File
# Begin Source File

SOURCE=.\res\TBManagerDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Water_Lilly.ico
# End Source File
# Begin Source File

SOURCE=".\res\ΩÁ√Ê.bmp"
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
