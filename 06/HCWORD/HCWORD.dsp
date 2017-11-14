# Microsoft Developer Studio Project File - Name="HCWORD" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=HCWORD - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "HCWORD.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "HCWORD.mak" CFG="HCWORD - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "HCWORD - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "HCWORD - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "HCWORD - Win32 Release"

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

!ELSEIF  "$(CFG)" == "HCWORD - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
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
# ADD LINK32 winmm.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "HCWORD - Win32 Release"
# Name "HCWORD - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\ADDdlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ASW.cpp
# End Source File
# Begin Source File

SOURCE=.\BANZGHU.cpp
# End Source File
# Begin Source File

SOURCE=.\BTNST.CPP
# End Source File
# Begin Source File

SOURCE=.\ClockST.cpp
# End Source File
# Begin Source File

SOURCE=.\HCset.cpp
# End Source File
# Begin Source File

SOURCE=.\HCWORD.cpp
# End Source File
# Begin Source File

SOURCE=.\HCWORD.rc
# End Source File
# Begin Source File

SOURCE=.\HCWORDDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Hutext.cpp
# End Source File
# Begin Source File

SOURCE=.\HY.cpp
# End Source File
# Begin Source File

SOURCE=.\MyTreeCtrl.cpp
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

SOURCE=.\REMDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SIJI.cpp
# End Source File
# Begin Source File

SOURCE=.\Splash1.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\TABDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\TESTdlg.cpp
# End Source File
# Begin Source File

SOURCE=.\TESTSet.cpp
# End Source File
# Begin Source File

SOURCE=.\TIANJIADlg.cpp
# End Source File
# Begin Source File

SOURCE=.\TKSet.cpp
# End Source File
# Begin Source File

SOURCE=.\webbrowser2.cpp
# End Source File
# Begin Source File

SOURCE=.\Wjset.cpp
# End Source File
# Begin Source File

SOURCE=.\YOUXI.cpp
# End Source File
# Begin Source File

SOURCE=.\YUU.cpp
# End Source File
# Begin Source File

SOURCE=.\ZLSet.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\ADDdlg.h
# End Source File
# Begin Source File

SOURCE=.\ASW.h
# End Source File
# Begin Source File

SOURCE=.\BANZGHU.h
# End Source File
# Begin Source File

SOURCE=.\BTNST.H
# End Source File
# Begin Source File

SOURCE=.\ClockST.h
# End Source File
# Begin Source File

SOURCE=.\HCset.h
# End Source File
# Begin Source File

SOURCE=.\HCWORD.h
# End Source File
# Begin Source File

SOURCE=.\HCWORDDlg.h
# End Source File
# Begin Source File

SOURCE=.\Hutext.h
# End Source File
# Begin Source File

SOURCE=.\HY.h
# End Source File
# Begin Source File

SOURCE=.\mmsystem.h
# End Source File
# Begin Source File

SOURCE=.\MyTreeCtrl.h
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

SOURCE=.\REMDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\SIJI.h
# End Source File
# Begin Source File

SOURCE=.\SkinMagic\SkinMagicLib.h
# End Source File
# Begin Source File

SOURCE=.\Splash1.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\TABDlg.h
# End Source File
# Begin Source File

SOURCE=.\TESTdlg.h
# End Source File
# Begin Source File

SOURCE=.\TESTSet.h
# End Source File
# Begin Source File

SOURCE=.\TIANJIADlg.h
# End Source File
# Begin Source File

SOURCE=.\TKSet.h
# End Source File
# Begin Source File

SOURCE=.\webbrowser2.h
# End Source File
# Begin Source File

SOURCE=.\Wjset.h
# End Source File
# Begin Source File

SOURCE=.\YOUXI.h
# End Source File
# Begin Source File

SOURCE=.\YUU.h
# End Source File
# Begin Source File

SOURCE=.\ZLSet.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\11.bmp
# End Source File
# Begin Source File

SOURCE=.\res\22.bmp
# End Source File
# Begin Source File

SOURCE=".\res\43∏±±æ.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\56.bmp
# End Source File
# Begin Source File

SOURCE=.\res\66.bmp
# End Source File
# Begin Source File

SOURCE=.\res\77.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap10.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap5.bmp
# End Source File
# Begin Source File

SOURCE=.\IMAGE\bmp_back.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Calendar.ico
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

SOURCE=.\res\cursor1.cur
# End Source File
# Begin Source File

SOURCE=.\res\fg.bmp
# End Source File
# Begin Source File

SOURCE=.\res\HCWORD.ico
# End Source File
# Begin Source File

SOURCE=.\res\HCWORD.rc2
# End Source File
# Begin Source File

SOURCE=.\res\icon1.ico
# End Source File
# Begin Source File

SOURCE=.\res\LargeIcon.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Notes.ico
# End Source File
# Begin Source File

SOURCE=.\res\Outlook.ico
# End Source File
# Begin Source File

SOURCE=.\IMAGE\preview.ico
# End Source File
# Begin Source File

SOURCE=.\res\Source.ico
# End Source File
# Begin Source File

SOURCE=.\res\TabWizard.bmp
# End Source File
# Begin Source File

SOURCE=.\IMAGE\toolbar1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\TreeBoot.bmp
# End Source File
# Begin Source File

SOURCE=.\res\tt.bmp
# End Source File
# Begin Source File

SOURCE=".\res\tt∏±±æ.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\ww.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\msg.wav
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# Begin Source File

SOURCE=".\µ•¥ …˘“Ù01.WAV"
# End Source File
# Begin Source File

SOURCE=".\µ•¥ …˘“Ù02.WAV"
# End Source File
# Begin Source File

SOURCE=".\µ•¥ …˘“Ù03.WAV"
# End Source File
# Begin Source File

SOURCE=".\µ•¥ …˘“Ù04 WAV.wav"
# End Source File
# Begin Source File

SOURCE=".\µ•¥ …˘“Ù05 WAV.wav"
# End Source File
# Begin Source File

SOURCE=".\µ•¥ …˘“Ù07.WAV"
# End Source File
# Begin Source File

SOURCE=".\µ•¥ …˘“Ù10.WAV"
# End Source File
# Begin Source File

SOURCE=".\«˙÷’»À…¢.wav"
# End Source File
# Begin Source File

SOURCE=.\SkinMagic\SkinMagicLib.lib
# End Source File
# End Target
# End Project
