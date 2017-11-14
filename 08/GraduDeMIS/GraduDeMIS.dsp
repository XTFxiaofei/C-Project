# Microsoft Developer Studio Project File - Name="GraduDeMIS" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=GraduDeMIS - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "GraduDeMIS.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "GraduDeMIS.mak" CFG="GraduDeMIS - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "GraduDeMIS - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "GraduDeMIS - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "GraduDeMIS - Win32 Release"

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

!ELSEIF  "$(CFG)" == "GraduDeMIS - Win32 Debug"

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

# Name "GraduDeMIS - Win32 Release"
# Name "GraduDeMIS - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AnswZigeChekDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ChoiceSubSet.cpp
# End Source File
# Begin Source File

SOURCE=.\ChoiStatusDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ChoisubDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\DabianfenzuDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\DabianfenzuSet.cpp
# End Source File
# Begin Source File

SOURCE=.\DclrsubSet.cpp
# End Source File
# Begin Source File

SOURCE=.\DclrsubStatusDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\DocChekDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\FanyiSet.cpp
# End Source File
# Begin Source File

SOURCE=.\GraduDeMIS.cpp
# End Source File
# Begin Source File

SOURCE=.\GraduDeMIS.rc
# End Source File
# Begin Source File

SOURCE=.\GraduDeMISDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\KaitiSet.cpp
# End Source File
# Begin Source File

SOURCE=.\KaoqinDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\KaoqinSet.cpp
# End Source File
# Begin Source File

SOURCE=.\KaoqinsumSet.cpp
# End Source File
# Begin Source File

SOURCE=.\PasswordSet.cpp
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

SOURCE=.\ShixiSet.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\StuAchieveSet.cpp
# End Source File
# Begin Source File

SOURCE=.\StuChoiSubDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StudentDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StudentSet.cpp
# End Source File
# Begin Source File

SOURCE=.\StudentTab1.cpp
# End Source File
# Begin Source File

SOURCE=.\StudentTab2.cpp
# End Source File
# Begin Source File

SOURCE=.\SubFormView.cpp
# End Source File
# Begin Source File

SOURCE=.\SubjectDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SubjectSet.cpp
# End Source File
# Begin Source File

SOURCE=.\SubOperProPage.cpp
# End Source File
# Begin Source File

SOURCE=.\SubQueryProPage.cpp
# End Source File
# Begin Source File

SOURCE=.\SubTab1Dlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SubTab2Dlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SubView.cpp
# End Source File
# Begin Source File

SOURCE=.\SysLgnDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\TeacherDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\TeacherSet.cpp
# End Source File
# Begin Source File

SOURCE=.\TeacherTab1.cpp
# End Source File
# Begin Source File

SOURCE=.\TeacherTab2.cpp
# End Source File
# Begin Source File

SOURCE=.\TecrDclrSubDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\TecrsubSet.cpp
# End Source File
# Begin Source File

SOURCE=.\UserDlg.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AnswZigeChekDlg.h
# End Source File
# Begin Source File

SOURCE=.\ChoiceSubSet.h
# End Source File
# Begin Source File

SOURCE=.\ChoiStatusDlg.h
# End Source File
# Begin Source File

SOURCE=.\ChoisubDlg.h
# End Source File
# Begin Source File

SOURCE=.\DabianfenzuDlg.h
# End Source File
# Begin Source File

SOURCE=.\DabianfenzuSet.h
# End Source File
# Begin Source File

SOURCE=.\DclrsubSet.h
# End Source File
# Begin Source File

SOURCE=.\DclrsubStatusDlg.h
# End Source File
# Begin Source File

SOURCE=.\DocChekDlg.h
# End Source File
# Begin Source File

SOURCE=.\FanyiSet.h
# End Source File
# Begin Source File

SOURCE=.\GraduDeMIS.h
# End Source File
# Begin Source File

SOURCE=.\GraduDeMISDlg.h
# End Source File
# Begin Source File

SOURCE=.\KaitiSet.h
# End Source File
# Begin Source File

SOURCE=.\KaoqinDlg.h
# End Source File
# Begin Source File

SOURCE=.\KaoqinSet.h
# End Source File
# Begin Source File

SOURCE=.\KaoqinsumSet.h
# End Source File
# Begin Source File

SOURCE=.\PasswordSet.h
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

SOURCE=.\ShixiSet.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\StuAchieveSet.h
# End Source File
# Begin Source File

SOURCE=.\StuChoiSubDlg.h
# End Source File
# Begin Source File

SOURCE=.\StudentDlg.h
# End Source File
# Begin Source File

SOURCE=.\StudentSet.h
# End Source File
# Begin Source File

SOURCE=.\StudentTab1.h
# End Source File
# Begin Source File

SOURCE=.\StudentTab2.h
# End Source File
# Begin Source File

SOURCE=.\SubFormView.h
# End Source File
# Begin Source File

SOURCE=.\SubjectDlg.h
# End Source File
# Begin Source File

SOURCE=.\SubjectSet.h
# End Source File
# Begin Source File

SOURCE=.\SubOperProPage.h
# End Source File
# Begin Source File

SOURCE=.\SubQueryProPage.h
# End Source File
# Begin Source File

SOURCE=.\SubTab1Dlg.h
# End Source File
# Begin Source File

SOURCE=.\SubTab2Dlg.h
# End Source File
# Begin Source File

SOURCE=.\SysLgnDlg.h
# End Source File
# Begin Source File

SOURCE=.\TeacherDlg.h
# End Source File
# Begin Source File

SOURCE=.\TeacherSet.h
# End Source File
# Begin Source File

SOURCE=.\TeacherTab1.h
# End Source File
# Begin Source File

SOURCE=.\TeacherTab2.h
# End Source File
# Begin Source File

SOURCE=.\TecrDclrSubDlg.h
# End Source File
# Begin Source File

SOURCE=.\TecrsubSet.h
# End Source File
# Begin Source File

SOURCE=.\UserDlg.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\123.bmp
# End Source File
# Begin Source File

SOURCE=.\res\2.bmp
# End Source File
# Begin Source File

SOURCE=.\image\bmp_back.bmp
# End Source File
# Begin Source File

SOURCE=.\res\cursor1.cur
# End Source File
# Begin Source File

SOURCE=.\res\dog.bmp
# End Source File
# Begin Source File

SOURCE=.\res\girl.bmp
# End Source File
# Begin Source File

SOURCE=.\res\girl1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\GraduDeMIS.ico
# End Source File
# Begin Source File

SOURCE=.\res\GraduDeMIS.rc2
# End Source File
# Begin Source File

SOURCE=.\image\preview.ico
# End Source File
# Begin Source File

SOURCE=.\res\preview.ico
# End Source File
# Begin Source File

SOURCE=.\image\toolbar1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\zhujiemian.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
