# Microsoft Developer Studio Project File - Name="MapPublic" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=MapPublic - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "MapPublic.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "MapPublic.mak" CFG="MapPublic - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "MapPublic - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "MapPublic - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "MapPublic - Win32 Release"

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

!ELSEIF  "$(CFG)" == "MapPublic - Win32 Debug"

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
# ADD LINK32 WINMM.LIB /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "MapPublic - Win32 Release"
# Name "MapPublic - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Action_Time_Set.cpp
# End Source File
# Begin Source File

SOURCE=.\AddAttributeDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\AddOneRoadway.cpp
# End Source File
# Begin Source File

SOURCE=.\Attribute.cpp
# End Source File
# Begin Source File

SOURCE=.\AttributeSet.cpp
# End Source File
# Begin Source File

SOURCE=.\BusSet.cpp
# End Source File
# Begin Source File

SOURCE=.\ColorStatic.cpp
# End Source File
# Begin Source File

SOURCE=.\CoolMenu.cpp
# End Source File
# Begin Source File

SOURCE=.\DelRoadway.cpp
# End Source File
# Begin Source File

SOURCE=.\DelSingleStation.cpp
# End Source File
# Begin Source File

SOURCE=.\clock\EDCLOCK.CPP
# End Source File
# Begin Source File

SOURCE=.\FindDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\font.cpp
# End Source File
# Begin Source File

SOURCE=.\hangeStation.cpp
# End Source File
# Begin Source File

SOURCE=.\HawkSightView.cpp
# End Source File
# Begin Source File

SOURCE=.\HawkView.cpp
# End Source File
# Begin Source File

SOURCE=.\InfoMation.cpp
# End Source File
# Begin Source File

SOURCE=.\Led.cpp
# End Source File
# Begin Source File

SOURCE=.\LjxWnd.cpp
# End Source File
# Begin Source File

SOURCE=.\LoginDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\map.cpp
# End Source File
# Begin Source File

SOURCE=.\Map_Station_Set.cpp
# End Source File
# Begin Source File

SOURCE=.\MapControlView.cpp
# End Source File
# Begin Source File

SOURCE=.\MapHelper.cpp
# End Source File
# Begin Source File

SOURCE=.\MapPublic.cpp
# End Source File
# Begin Source File

SOURCE=.\MapPublic.rc
# End Source File
# Begin Source File

SOURCE=.\MapPublicDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\MapPublicView.cpp
# End Source File
# Begin Source File

SOURCE=.\moaddresslocation.cpp
# End Source File
# Begin Source File

SOURCE=.\mochartrenderer.cpp
# End Source File
# Begin Source File

SOURCE=.\moclassbreaksrenderer.cpp
# End Source File
# Begin Source File

SOURCE=.\modataconnection.cpp
# End Source File
# Begin Source File

SOURCE=.\modatum.cpp
# End Source File
# Begin Source File

SOURCE=.\modotdensityrenderer.cpp
# End Source File
# Begin Source File

SOURCE=.\moellipse.cpp
# End Source File
# Begin Source File

SOURCE=.\moeventrenderer.cpp
# End Source File
# Begin Source File

SOURCE=.\mofield.cpp
# End Source File
# Begin Source File

SOURCE=.\mofields.cpp
# End Source File
# Begin Source File

SOURCE=.\mogeocoder.cpp
# End Source File
# Begin Source File

SOURCE=.\mogeocoordsys.cpp
# End Source File
# Begin Source File

SOURCE=.\mogeodataset.cpp
# End Source File
# Begin Source File

SOURCE=.\mogeodatasets.cpp
# End Source File
# Begin Source File

SOURCE=.\mogeoevent.cpp
# End Source File
# Begin Source File

SOURCE=.\mogeotransformation.cpp
# End Source File
# Begin Source File

SOURCE=.\mogrouprenderer.cpp
# End Source File
# Begin Source File

SOURCE=.\moimagelayer.cpp
# End Source File
# Begin Source File

SOURCE=.\molabelplacer.cpp
# End Source File
# Begin Source File

SOURCE=.\molabelrenderer.cpp
# End Source File
# Begin Source File

SOURCE=.\molayers.cpp
# End Source File
# Begin Source File

SOURCE=.\moline.cpp
# End Source File
# Begin Source File

SOURCE=.\momaplayer.cpp
# End Source File
# Begin Source File

SOURCE=.\moparts.cpp
# End Source File
# Begin Source File

SOURCE=.\moplacelocator.cpp
# End Source File
# Begin Source File

SOURCE=.\mopoint.cpp
# End Source File
# Begin Source File

SOURCE=.\mopoints.cpp
# End Source File
# Begin Source File

SOURCE=.\mopolygon.cpp
# End Source File
# Begin Source File

SOURCE=.\moprimemeridian.cpp
# End Source File
# Begin Source File

SOURCE=.\moprojcoordsys.cpp
# End Source File
# Begin Source File

SOURCE=.\moprojection.cpp
# End Source File
# Begin Source File

SOURCE=.\morecordset.cpp
# End Source File
# Begin Source File

SOURCE=.\morectangle.cpp
# End Source File
# Begin Source File

SOURCE=.\mospheroid.cpp
# End Source File
# Begin Source File

SOURCE=.\mostandardizer.cpp
# End Source File
# Begin Source File

SOURCE=.\mostatistics.cpp
# End Source File
# Begin Source File

SOURCE=.\mostrings.cpp
# End Source File
# Begin Source File

SOURCE=.\mosymbol.cpp
# End Source File
# Begin Source File

SOURCE=.\motable.cpp
# End Source File
# Begin Source File

SOURCE=.\motabledesc.cpp
# End Source File
# Begin Source File

SOURCE=.\motextsymbol.cpp
# End Source File
# Begin Source File

SOURCE=.\motrackinglayer.cpp
# End Source File
# Begin Source File

SOURCE=.\mounit.cpp
# End Source File
# Begin Source File

SOURCE=.\movaluemaprenderer.cpp
# End Source File
# Begin Source File

SOURCE=.\mozrenderer.cpp
# End Source File
# Begin Source File

SOURCE=.\MusicThread.cpp
# End Source File
# Begin Source File

SOURCE=.\MyNewThread.cpp
# End Source File
# Begin Source File

SOURCE=.\newListCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\PasswordSet.cpp
# End Source File
# Begin Source File

SOURCE=.\QueryDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\RoadView.cpp
# End Source File
# Begin Source File

SOURCE=.\ShowEndDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SightDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SpeciesSet.cpp
# End Source File
# Begin Source File

SOURCE=.\StaionWayView.cpp
# End Source File
# Begin Source File

SOURCE=.\StationSet.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\autocomplete\Subclass.cpp
# End Source File
# Begin Source File

SOURCE=.\SuperProgressCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\Tools.cpp
# End Source File
# Begin Source File

SOURCE=.\TransView.cpp
# End Source File
# Begin Source File

SOURCE=.\XPButton.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Action_Time_Set.h
# End Source File
# Begin Source File

SOURCE=.\AddAttributeDlg.h
# End Source File
# Begin Source File

SOURCE=.\AddOneRoadway.h
# End Source File
# Begin Source File

SOURCE=.\Attribute.h
# End Source File
# Begin Source File

SOURCE=.\AttributeSet.h
# End Source File
# Begin Source File

SOURCE=.\BusSet.h
# End Source File
# Begin Source File

SOURCE=.\ColorStatic.h
# End Source File
# Begin Source File

SOURCE=.\CoolMenu.h
# End Source File
# Begin Source File

SOURCE=.\DelRoadway.h
# End Source File
# Begin Source File

SOURCE=.\DelSingleStation.h
# End Source File
# Begin Source File

SOURCE=.\clock\EDCLOCK.H
# End Source File
# Begin Source File

SOURCE=.\FindDlg.h
# End Source File
# Begin Source File

SOURCE=.\font.h
# End Source File
# Begin Source File

SOURCE=.\hangeStation.h
# End Source File
# Begin Source File

SOURCE=.\HawkSightView.h
# End Source File
# Begin Source File

SOURCE=.\HawkView.h
# End Source File
# Begin Source File

SOURCE=.\InfoMation.h
# End Source File
# Begin Source File

SOURCE=.\Led.h
# End Source File
# Begin Source File

SOURCE=.\LjxWnd.h
# End Source File
# Begin Source File

SOURCE=.\LoginDlg.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\map.h
# End Source File
# Begin Source File

SOURCE=.\Map_Station_Set.h
# End Source File
# Begin Source File

SOURCE=.\MapControlView.h
# End Source File
# Begin Source File

SOURCE=.\MapHelper.h
# End Source File
# Begin Source File

SOURCE=.\MapObjects2.h
# End Source File
# Begin Source File

SOURCE=.\MapPublic.h
# End Source File
# Begin Source File

SOURCE=.\MapPublicDoc.h
# End Source File
# Begin Source File

SOURCE=.\MapPublicView.h
# End Source File
# Begin Source File

SOURCE=.\moaddresslocation.h
# End Source File
# Begin Source File

SOURCE=.\mochartrenderer.h
# End Source File
# Begin Source File

SOURCE=.\moclassbreaksrenderer.h
# End Source File
# Begin Source File

SOURCE=.\modataconnection.h
# End Source File
# Begin Source File

SOURCE=.\modatum.h
# End Source File
# Begin Source File

SOURCE=.\modotdensityrenderer.h
# End Source File
# Begin Source File

SOURCE=.\moellipse.h
# End Source File
# Begin Source File

SOURCE=.\moeventrenderer.h
# End Source File
# Begin Source File

SOURCE=.\mofield.h
# End Source File
# Begin Source File

SOURCE=.\mofields.h
# End Source File
# Begin Source File

SOURCE=.\mogeocoder.h
# End Source File
# Begin Source File

SOURCE=.\mogeocoordsys.h
# End Source File
# Begin Source File

SOURCE=.\mogeodataset.h
# End Source File
# Begin Source File

SOURCE=.\mogeodatasets.h
# End Source File
# Begin Source File

SOURCE=.\mogeoevent.h
# End Source File
# Begin Source File

SOURCE=.\mogeotransformation.h
# End Source File
# Begin Source File

SOURCE=.\mogrouprenderer.h
# End Source File
# Begin Source File

SOURCE=.\moimagelayer.h
# End Source File
# Begin Source File

SOURCE=.\molabelplacer.h
# End Source File
# Begin Source File

SOURCE=.\molabelrenderer.h
# End Source File
# Begin Source File

SOURCE=.\molayers.h
# End Source File
# Begin Source File

SOURCE=.\moline.h
# End Source File
# Begin Source File

SOURCE=.\momaplayer.h
# End Source File
# Begin Source File

SOURCE=.\moparts.h
# End Source File
# Begin Source File

SOURCE=.\moplacelocator.h
# End Source File
# Begin Source File

SOURCE=.\mopoint.h
# End Source File
# Begin Source File

SOURCE=.\mopoints.h
# End Source File
# Begin Source File

SOURCE=.\mopolygon.h
# End Source File
# Begin Source File

SOURCE=.\moprimemeridian.h
# End Source File
# Begin Source File

SOURCE=.\moprojcoordsys.h
# End Source File
# Begin Source File

SOURCE=.\moprojection.h
# End Source File
# Begin Source File

SOURCE=.\morecordset.h
# End Source File
# Begin Source File

SOURCE=.\morectangle.h
# End Source File
# Begin Source File

SOURCE=.\mospheroid.h
# End Source File
# Begin Source File

SOURCE=.\mostandardizer.h
# End Source File
# Begin Source File

SOURCE=.\mostatistics.h
# End Source File
# Begin Source File

SOURCE=.\mostrings.h
# End Source File
# Begin Source File

SOURCE=.\mosymbol.h
# End Source File
# Begin Source File

SOURCE=.\motable.h
# End Source File
# Begin Source File

SOURCE=.\motabledesc.h
# End Source File
# Begin Source File

SOURCE=.\motextsymbol.h
# End Source File
# Begin Source File

SOURCE=.\motrackinglayer.h
# End Source File
# Begin Source File

SOURCE=.\mounit.h
# End Source File
# Begin Source File

SOURCE=.\movaluemaprenderer.h
# End Source File
# Begin Source File

SOURCE=.\mozrenderer.h
# End Source File
# Begin Source File

SOURCE=.\MusicThread.h
# End Source File
# Begin Source File

SOURCE=.\MyNewThread.h
# End Source File
# Begin Source File

SOURCE=.\newListCtrl.h
# End Source File
# Begin Source File

SOURCE=.\PasswordSet.h
# End Source File
# Begin Source File

SOURCE=.\QueryDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\RoadView.h
# End Source File
# Begin Source File

SOURCE=.\ShowEndDlg.h
# End Source File
# Begin Source File

SOURCE=.\SightDlg.h
# End Source File
# Begin Source File

SOURCE=.\SpeciesSet.h
# End Source File
# Begin Source File

SOURCE=.\StaionWayView.h
# End Source File
# Begin Source File

SOURCE=.\StationSet.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\autocomplete\Subclass.h
# End Source File
# Begin Source File

SOURCE=.\SuperProgressCtrl.h
# End Source File
# Begin Source File

SOURCE=.\Tools.h
# End Source File
# Begin Source File

SOURCE=.\TransView.h
# End Source File
# Begin Source File

SOURCE=.\XPButton.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\0.BMP
# End Source File
# Begin Source File

SOURCE=.\res\1.BMP
# End Source File
# Begin Source File

SOURCE=.\res\2.BMP
# End Source File
# Begin Source File

SOURCE=.\res\3.BMP
# End Source File
# Begin Source File

SOURCE=.\res\4.BMP
# End Source File
# Begin Source File

SOURCE=.\res\5.BMP
# End Source File
# Begin Source File

SOURCE=.\res\6.BMP
# End Source File
# Begin Source File

SOURCE=.\res\7.BMP
# End Source File
# Begin Source File

SOURCE=.\res\8.BMP
# End Source File
# Begin Source File

SOURCE=.\res\9.BMP
# End Source File
# Begin Source File

SOURCE=.\res\BackBmp.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bkcolor.bmp
# End Source File
# Begin Source File

SOURCE=.\res\BLACK.BMP
# End Source File
# Begin Source File

SOURCE=.\res\icon1.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon2.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon3.ico
# End Source File
# Begin Source File

SOURCE=.\res\leds.bmp
# End Source File
# Begin Source File

SOURCE=.\res\logobar3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\MapPublic.ico
# End Source File
# Begin Source File

SOURCE=.\res\MapPublic.rc2
# End Source File
# Begin Source File

SOURCE=.\res\MapPublicDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\PEOPLE.bmp
# End Source File
# Begin Source File

SOURCE=.\res\POINT.BMP
# End Source File
# Begin Source File

SOURCE=.\Splsh16.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\toolbar1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\wave5.bin
# End Source File
# Begin Source File

SOURCE=".\res\∆Ù∂Øª≠√Ê.bmp"
# End Source File
# End Group
# Begin Source File

SOURCE=.\res\1.wav
# End Source File
# Begin Source File

SOURCE=.\res\3.wav
# End Source File
# Begin Source File

SOURCE=.\res\60.wav
# End Source File
# Begin Source File

SOURCE=.\MapPublic.dsw
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# Begin Source File

SOURCE=".\res\Windows XP ∆Ù∂Ø.wav"
# End Source File
# Begin Source File

SOURCE=".\res\Windows XP ∆¯«Ú.wav"
# End Source File
# Begin Source File

SOURCE=".\res\±≥æ∞“Ù¿÷.wav"
# End Source File
# End Target
# End Project
# Section MapPublic : {9BD6A678-CE75-11D1-AF04-204C4F4F5020}
# 	2:5:Class:CMoDotDensityRenderer
# 	2:10:HeaderFile:modotdensityrenderer.h
# 	2:8:ImplFile:modotdensityrenderer.cpp
# End Section
# Section MapPublic : {83259D44-4A42-11D2-AF7A-006097DA3688}
# 	2:5:Class:CMoLabelPlacer
# 	2:10:HeaderFile:molabelplacer.h
# 	2:8:ImplFile:molabelplacer.cpp
# End Section
# Section MapPublic : {9BD6A67F-CE75-11D1-AF04-204C4F4F5020}
# 	2:5:Class:CMoGeoEvent
# 	2:10:HeaderFile:mogeoevent.h
# 	2:8:ImplFile:mogeoevent.cpp
# End Section
# Section MapPublic : {9BD6A65F-CE75-11D1-AF04-204C4F4F5020}
# 	2:5:Class:CMoField
# 	2:10:HeaderFile:mofield.h
# 	2:8:ImplFile:mofield.cpp
# End Section
# Section MapPublic : {0C8392E4-3CC4-11D2-8AF6-0060082D41FB}
# 	2:5:Class:CMoZRenderer
# 	2:10:HeaderFile:mozrenderer.h
# 	2:8:ImplFile:mozrenderer.cpp
# End Section
# Section MapPublic : {9BD6A67A-CE75-11D1-AF04-204C4F4F5020}
# 	2:5:Class:CMoLabelRenderer
# 	2:10:HeaderFile:molabelrenderer.h
# 	2:8:ImplFile:molabelrenderer.cpp
# End Section
# Section MapPublic : {9BD6A683-CE75-11D1-AF04-204C4F4F5020}
# 	2:5:Class:CMoImageLayer
# 	2:10:HeaderFile:moimagelayer.h
# 	2:8:ImplFile:moimagelayer.cpp
# End Section
# Section MapPublic : {9BD6A663-CE75-11D1-AF04-204C4F4F5020}
# 	2:5:Class:CMoLine
# 	2:10:HeaderFile:moline.h
# 	2:8:ImplFile:moline.cpp
# End Section
# Section MapPublic : {F9C0602F-DA8D-11D1-AF16-006097DA3688}
# 	2:5:Class:CMoSpheroid
# 	2:10:HeaderFile:mospheroid.h
# 	2:8:ImplFile:mospheroid.cpp
# End Section
# Section MapPublic : {BEF6E003-A874-101A-8BBA-00AA00300CAB}
# 	2:5:Class:COleFont
# 	2:10:HeaderFile:font.h
# 	2:8:ImplFile:font.cpp
# End Section
# Section MapPublic : {9BD6A68A-CE75-11D1-AF04-204C4F4F5020}
# 	2:5:Class:CMoTableDesc
# 	2:10:HeaderFile:motabledesc.h
# 	2:8:ImplFile:motabledesc.cpp
# End Section
# Section MapPublic : {72ADFD78-2C39-11D0-9903-00A0C91BC942}
# 	1:10:IDB_SPLASH:102
# 	2:21:SplashScreenInsertKey:4.0
# End Section
# Section MapPublic : {9BD6A64E-CE75-11D1-AF04-204C4F4F5020}
# 	2:5:Class:CMoDataConnection
# 	2:10:HeaderFile:modataconnection.h
# 	2:8:ImplFile:modataconnection.cpp
# End Section
# Section MapPublic : {9BD6A657-CE75-11D1-AF04-204C4F4F5020}
# 	2:5:Class:CMoRectangle
# 	2:10:HeaderFile:morectangle.h
# 	2:8:ImplFile:morectangle.cpp
# End Section
# Section MapPublic : {F9C06023-DA8D-11D1-AF16-006097DA3688}
# 	2:5:Class:CMoProjCoordSys
# 	2:10:HeaderFile:moprojcoordsys.h
# 	2:8:ImplFile:moprojcoordsys.cpp
# End Section
# Section MapPublic : {9BD6A66E-CE75-11D1-AF04-204C4F4F5020}
# 	2:5:Class:CMoSymbol
# 	2:10:HeaderFile:mosymbol.h
# 	2:8:ImplFile:mosymbol.cpp
# End Section
# Section MapPublic : {9BD6A672-CE75-11D1-AF04-204C4F4F5020}
# 	2:5:Class:CMoStrings
# 	2:10:HeaderFile:mostrings.h
# 	2:8:ImplFile:mostrings.cpp
# End Section
# Section MapPublic : {9BD6A652-CE75-11D1-AF04-204C4F4F5020}
# 	2:5:Class:CMoLayers
# 	2:10:HeaderFile:molayers.h
# 	2:8:ImplFile:molayers.cpp
# End Section
# Section MapPublic : {9BD6A68E-CE75-11D1-AF04-204C4F4F5020}
# 	2:5:Class:CMoAddressLocation
# 	2:10:HeaderFile:moaddresslocation.h
# 	2:8:ImplFile:moaddresslocation.cpp
# End Section
# Section MapPublic : {9BD6A687-CE75-11D1-AF04-204C4F4F5020}
# 	2:5:Class:CMoTextSymbol
# 	2:10:HeaderFile:motextsymbol.h
# 	2:8:ImplFile:motextsymbol.cpp
# End Section
# Section MapPublic : {F9C06032-DA8D-11D1-AF16-006097DA3688}
# 	2:5:Class:CMoPrimeMeridian
# 	2:10:HeaderFile:moprimemeridian.h
# 	2:8:ImplFile:moprimemeridian.cpp
# End Section
# Section MapPublic : {2637C6F5-0472-11D2-909C-00600826393D}
# 	2:5:Class:CMoGeocoder
# 	2:10:HeaderFile:mogeocoder.h
# 	2:8:ImplFile:mogeocoder.cpp
# End Section
# Section MapPublic : {43FD9771-D8FF-11D1-AF14-006097DA3688}
# 	2:5:Class:CMoProjection
# 	2:10:HeaderFile:moprojection.h
# 	2:8:ImplFile:moprojection.cpp
# End Section
# Section MapPublic : {9BD6A696-CE75-11D1-AF04-204C4F4F5020}
# 	2:5:Class:CMoParts
# 	2:10:HeaderFile:moparts.h
# 	2:8:ImplFile:moparts.cpp
# End Section
# Section MapPublic : {9BD6A65D-CE75-11D1-AF04-204C4F4F5020}
# 	2:5:Class:CMoFields
# 	2:10:HeaderFile:mofields.h
# 	2:8:ImplFile:mofields.cpp
# End Section
# Section MapPublic : {83259D42-4A42-11D2-AF7A-006097DA3688}
# 	2:5:Class:CMoChartRenderer
# 	2:10:HeaderFile:mochartrenderer.h
# 	2:8:ImplFile:mochartrenderer.cpp
# End Section
# Section MapPublic : {9BD6A676-CE75-11D1-AF04-204C4F4F5020}
# 	2:5:Class:CMoClassBreaksRenderer
# 	2:10:HeaderFile:moclassbreaksrenderer.h
# 	2:8:ImplFile:moclassbreaksrenderer.cpp
# End Section
# Section MapPublic : {9BD6A661-CE75-11D1-AF04-204C4F4F5020}
# 	2:5:Class:CMoPolygon
# 	2:10:HeaderFile:mopolygon.h
# 	2:8:ImplFile:mopolygon.cpp
# End Section
# Section MapPublic : {9BD6A681-CE75-11D1-AF04-204C4F4F5020}
# 	2:5:Class:CMoEllipse
# 	2:10:HeaderFile:moellipse.h
# 	2:8:ImplFile:moellipse.cpp
# End Section
# Section MapPublic : {9BD6A67D-CE75-11D1-AF04-204C4F4F5020}
# 	2:5:Class:CMoTrackingLayer
# 	2:10:HeaderFile:motrackinglayer.h
# 	2:8:ImplFile:motrackinglayer.cpp
# End Section
# Section MapPublic : {F9C06026-DA8D-11D1-AF16-006097DA3688}
# 	2:5:Class:CMoGeoCoordSys
# 	2:10:HeaderFile:mogeocoordsys.h
# 	2:8:ImplFile:mogeocoordsys.cpp
# End Section
# Section MapPublic : {9BD6A665-CE75-11D1-AF04-204C4F4F5020}
# 	2:5:Class:CMoPoints
# 	2:10:HeaderFile:mopoints.h
# 	2:8:ImplFile:mopoints.cpp
# End Section
# Section MapPublic : {9BD6A655-CE75-11D1-AF04-204C4F4F5020}
# 	2:5:Class:CMoMapLayer
# 	2:10:HeaderFile:momaplayer.h
# 	2:8:ImplFile:momaplayer.cpp
# End Section
# Section MapPublic : {9BD6A650-CE75-11D1-AF04-204C4F4F5020}
# 	2:5:Class:CMoGeoDataset
# 	2:10:HeaderFile:mogeodataset.h
# 	2:8:ImplFile:mogeodataset.cpp
# End Section
# Section MapPublic : {9BD6A685-CE75-11D1-AF04-204C4F4F5020}
# 	2:5:Class:CMoTable
# 	2:10:HeaderFile:motable.h
# 	2:8:ImplFile:motable.cpp
# End Section
# Section MapPublic : {9BD6A64C-CE75-11D1-AF04-204C4F4F5020}
# 	2:5:Class:CMoGeoDatasets
# 	2:10:HeaderFile:mogeodatasets.h
# 	2:8:ImplFile:mogeodatasets.cpp
# End Section
# Section MapPublic : {356EF6C6-73E3-11D2-BF0D-0060082D41FB}
# 	2:5:Class:CMoEventRenderer
# 	2:10:HeaderFile:moeventrenderer.h
# 	2:8:ImplFile:moeventrenderer.cpp
# End Section
# Section MapPublic : {9BD6A670-CE75-11D1-AF04-204C4F4F5020}
# 	2:5:Class:CMoValueMapRenderer
# 	2:10:HeaderFile:movaluemaprenderer.h
# 	2:8:ImplFile:movaluemaprenderer.cpp
# End Section
# Section MapPublic : {9BD6A649-CE75-11D1-AF04-204C4F4F5020}
# 	2:5:Class:CMap1
# 	2:10:HeaderFile:map.h
# 	2:8:ImplFile:map.cpp
# End Section
# Section MapPublic : {F9C06035-DA8D-11D1-AF16-006097DA3688}
# 	2:5:Class:CMoGeoTransformation
# 	2:10:HeaderFile:mogeotransformation.h
# 	2:8:ImplFile:mogeotransformation.cpp
# End Section
# Section MapPublic : {9BD6A659-CE75-11D1-AF04-204C4F4F5020}
# 	2:5:Class:CMoRecordset
# 	2:10:HeaderFile:morecordset.h
# 	2:8:ImplFile:morecordset.cpp
# End Section
# Section MapPublic : {F9C0602C-DA8D-11D1-AF16-006097DA3688}
# 	2:5:Class:CMoDatum
# 	2:10:HeaderFile:modatum.h
# 	2:8:ImplFile:modatum.cpp
# End Section
# Section MapPublic : {2637C6F3-0472-11D2-909C-00600826393D}
# 	2:5:Class:CMoStandardizer
# 	2:10:HeaderFile:mostandardizer.h
# 	2:8:ImplFile:mostandardizer.cpp
# End Section
# Section MapPublic : {9BD6A65B-CE75-11D1-AF04-204C4F4F5020}
# 	2:5:Class:CMoPoint
# 	2:10:HeaderFile:mopoint.h
# 	2:8:ImplFile:mopoint.cpp
# End Section
# Section MapPublic : {83259D40-4A42-11D2-AF7A-006097DA3688}
# 	2:5:Class:CMoGroupRenderer
# 	2:10:HeaderFile:mogrouprenderer.h
# 	2:8:ImplFile:mogrouprenderer.cpp
# End Section
# Section MapPublic : {9BD6A64B-CE75-11D1-AF04-204C4F4F5020}
# 	2:21:DefaultSinkHeaderFile:map.h
# 	2:16:DefaultSinkClass:CMap1
# End Section
# Section MapPublic : {9BD6A674-CE75-11D1-AF04-204C4F4F5020}
# 	2:5:Class:CMoStatistics
# 	2:10:HeaderFile:mostatistics.h
# 	2:8:ImplFile:mostatistics.cpp
# End Section
# Section MapPublic : {F9C06029-DA8D-11D1-AF16-006097DA3688}
# 	2:5:Class:CMoUnit
# 	2:10:HeaderFile:mounit.h
# 	2:8:ImplFile:mounit.cpp
# End Section
# Section MapPublic : {9BD6A694-CE75-11D1-AF04-204C4F4F5020}
# 	2:5:Class:CMoPlaceLocator
# 	2:10:HeaderFile:moplacelocator.h
# 	2:8:ImplFile:moplacelocator.cpp
# End Section
