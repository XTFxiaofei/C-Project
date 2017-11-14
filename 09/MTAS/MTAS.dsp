# Microsoft Developer Studio Project File - Name="MTAS" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=MTAS - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "MTAS.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "MTAS.mak" CFG="MTAS - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "MTAS - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "MTAS - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "MTAS - Win32 Release"

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

!ELSEIF  "$(CFG)" == "MTAS - Win32 Debug"

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
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /ZI /Od /I "Prof-UIS/include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
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

# Name "MTAS - Win32 Release"
# Name "MTAS - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AddChapterDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\AddChapterDlg2.cpp
# End Source File
# Begin Source File

SOURCE=.\AddClassDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\AddCoursewareDlg1.cpp
# End Source File
# Begin Source File

SOURCE=.\AddCoursewareDlg2.cpp
# End Source File
# Begin Source File

SOURCE=.\AddCoursewareDlg3.cpp
# End Source File
# Begin Source File

SOURCE=.\AddressComboBox.cpp
# End Source File
# Begin Source File

SOURCE=.\AddressStatic.cpp
# End Source File
# Begin Source File

SOURCE=.\AddSectionDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\AddSectionDlg2.cpp
# End Source File
# Begin Source File

SOURCE=.\PinnableCtrlBar\AutoHideBar.cpp
# End Source File
# Begin Source File

SOURCE=.\BtnST\BtnST.cpp
# End Source File
# Begin Source File

SOURCE=.\Tools\ButtonXP.cpp
# End Source File
# Begin Source File

SOURCE=.\ClickSound.cpp
# End Source File
# Begin Source File

SOURCE=.\ClockDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ClockST\ClockST.cpp
# End Source File
# Begin Source File

SOURCE=.\CntrItem.cpp
# End Source File
# Begin Source File

SOURCE=.\Tools\ComboBoxXP.cpp
# End Source File
# Begin Source File

SOURCE=.\CourseManager.cpp
# End Source File
# Begin Source File

SOURCE=.\CourseWareManager.cpp
# End Source File
# Begin Source File

SOURCE=.\CustomTabCtrl\CustomTabCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\CWToolBar.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgListCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgProperties.cpp
# End Source File
# Begin Source File

SOURCE=.\Tools\Draw.cpp
# End Source File
# Begin Source File

SOURCE=.\PinnableCtrlBar\DrawFrame.cpp
# End Source File
# Begin Source File

SOURCE=.\FlashComboBox.cpp
# End Source File
# Begin Source File

SOURCE=.\FlashListCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\FlashToolBar.cpp
# End Source File
# Begin Source File

SOURCE=.\FlashView.cpp
# End Source File
# Begin Source File

SOURCE=.\GuideBar.cpp
# End Source File
# Begin Source File

SOURCE=.\HyperLink.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\Tools\MenuXP.cpp
# End Source File
# Begin Source File

SOURCE=.\MTAS.cpp
# End Source File
# Begin Source File

SOURCE=.\MTAS.rc
# End Source File
# Begin Source File

SOURCE=.\MTASDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\MTASView.cpp
# End Source File
# Begin Source File

SOURCE=.\MyGuideTree.cpp
# End Source File
# Begin Source File

SOURCE=.\MyListCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\MyView.cpp
# End Source File
# Begin Source File

SOURCE=.\NavigateToolBar.cpp
# End Source File
# Begin Source File

SOURCE=.\CoolMenu\NewMenu.cpp
# End Source File
# Begin Source File

SOURCE=.\CoolMenu\NewToolBar.cpp
# End Source File
# Begin Source File

SOURCE=.\Options.cpp
# End Source File
# Begin Source File

SOURCE=.\OutlookTabCtrl\OutlookTabCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\OutlookTabCtrl\OutlookTabCtrlEx.cpp
# End Source File
# Begin Source File

SOURCE=.\Persist.cpp
# End Source File
# Begin Source File

SOURCE=.\PinnableCtrlBar\PinDockBar.cpp
# End Source File
# Begin Source File

SOURCE=.\PptListCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\PptView.cpp
# End Source File
# Begin Source File

SOURCE=.\SizingCtrlBar\scbarcf.cpp
# End Source File
# Begin Source File

SOURCE=.\SizingCtrlBar\scbarg.cpp
# End Source File
# Begin Source File

SOURCE=.\shockwaveflash.cpp
# End Source File
# Begin Source File

SOURCE=.\SimpleSplashWnd.cpp
# End Source File
# Begin Source File

SOURCE=.\SizingCtrlBar\sizecbar.cpp
# End Source File
# Begin Source File

SOURCE=.\Tools\StatusBarXP.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=".\CustomTabCtrl\TabSDIFrameWnd .cpp"
# End Source File
# Begin Source File

SOURCE=.\CustomTabCtrl\ThemeUtil.cpp
# End Source File
# Begin Source File

SOURCE=.\Tools\ToolBarXP.cpp
# End Source File
# Begin Source File

SOURCE=.\Tools\Tools.cpp
# End Source File
# Begin Source File

SOURCE=.\TreeCtrlMethod.cpp
# End Source File
# Begin Source File

SOURCE=.\TreeGuideBar.cpp
# End Source File
# Begin Source File

SOURCE=.\VividTree.cpp
# End Source File
# Begin Source File

SOURCE=.\webbrowser2.cpp
# End Source File
# Begin Source File

SOURCE=.\BtnST\WinXPButtonST.cpp
# End Source File
# Begin Source File

SOURCE=.\WordListCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\WordView.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AddChapterDlg.h
# End Source File
# Begin Source File

SOURCE=.\AddChapterDlg2.h
# End Source File
# Begin Source File

SOURCE=.\AddClassDlg.h
# End Source File
# Begin Source File

SOURCE=.\AddCoursewareDlg1.h
# End Source File
# Begin Source File

SOURCE=.\AddCoursewareDlg2.h
# End Source File
# Begin Source File

SOURCE=.\AddCoursewareDlg3.h
# End Source File
# Begin Source File

SOURCE=.\AddressComboBox.h
# End Source File
# Begin Source File

SOURCE=.\AddressStatic.h
# End Source File
# Begin Source File

SOURCE=.\AddSectionDlg.h
# End Source File
# Begin Source File

SOURCE=.\AddSectionDlg2.h
# End Source File
# Begin Source File

SOURCE=.\PinnableCtrlBar\AutoHideBar.h
# End Source File
# Begin Source File

SOURCE=.\ClickSound.h
# End Source File
# Begin Source File

SOURCE=.\ClockDlg.h
# End Source File
# Begin Source File

SOURCE=.\CntrItem.h
# End Source File
# Begin Source File

SOURCE=.\CourseManager.h
# End Source File
# Begin Source File

SOURCE=.\CourseWareManager.h
# End Source File
# Begin Source File

SOURCE=.\CustomTabCtrl\CustomTabCtrl.h
# End Source File
# Begin Source File

SOURCE=.\CWToolBar.h
# End Source File
# Begin Source File

SOURCE=.\DlgListCtrl.h
# End Source File
# Begin Source File

SOURCE=.\DlgProperties.h
# End Source File
# Begin Source File

SOURCE=.\PinnableCtrlBar\DrawFrame.h
# End Source File
# Begin Source File

SOURCE=.\FlashComboBox.h
# End Source File
# Begin Source File

SOURCE=.\FlashListCtrl.h
# End Source File
# Begin Source File

SOURCE=.\FlashToolBar.h
# End Source File
# Begin Source File

SOURCE=.\FlashView.h
# End Source File
# Begin Source File

SOURCE=.\GuideBar.h
# End Source File
# Begin Source File

SOURCE=.\HyperLink.h
# End Source File
# Begin Source File

SOURCE=.\IUpdate.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\MTAS.h
# End Source File
# Begin Source File

SOURCE=.\MTASDoc.h
# End Source File
# Begin Source File

SOURCE=.\MTASView.h
# End Source File
# Begin Source File

SOURCE=.\MyGuideTree.h
# End Source File
# Begin Source File

SOURCE=.\MyListCtrl.h
# End Source File
# Begin Source File

SOURCE=.\MyView.h
# End Source File
# Begin Source File

SOURCE=.\NavigateToolBar.h
# End Source File
# Begin Source File

SOURCE=.\Persist.h
# End Source File
# Begin Source File

SOURCE=.\PinnableCtrlBar\PinDockBar.h
# End Source File
# Begin Source File

SOURCE=.\PptListCtrl.h
# End Source File
# Begin Source File

SOURCE=.\PptView.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\SizingCtrlBar\scbarcf.h
# End Source File
# Begin Source File

SOURCE=.\SizingCtrlBar\scbarg.h
# End Source File
# Begin Source File

SOURCE=.\CustomTabCtrl\Schemadef.h
# End Source File
# Begin Source File

SOURCE=.\shockwaveflash.h
# End Source File
# Begin Source File

SOURCE=.\SimpleSplashWnd.h
# End Source File
# Begin Source File

SOURCE=.\SizingCtrlBar\sizecbar.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\CustomTabCtrl\TabSDIFrameWnd.h
# End Source File
# Begin Source File

SOURCE=.\Tools\ToolbarXP.h
# End Source File
# Begin Source File

SOURCE=.\TreeCtrlMethod.h
# End Source File
# Begin Source File

SOURCE=.\TreeGuideBar.h
# End Source File
# Begin Source File

SOURCE=.\webbrowser2.h
# End Source File
# Begin Source File

SOURCE=.\WordListCtrl.h
# End Source File
# Begin Source File

SOURCE=.\WordView.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\00038.ico
# End Source File
# Begin Source File

SOURCE=.\res\00040.ico
# End Source File
# Begin Source File

SOURCE=.\res\00049.ico
# End Source File
# Begin Source File

SOURCE=.\res\00137.ico
# End Source File
# Begin Source File

SOURCE=.\res\00138.ico
# End Source File
# Begin Source File

SOURCE=.\res\00156.ico
# End Source File
# Begin Source File

SOURCE=.\res\00178.ico
# End Source File
# Begin Source File

SOURCE=.\res\00186.ico
# End Source File
# Begin Source File

SOURCE=.\res\00189.ico
# End Source File
# Begin Source File

SOURCE=.\res\00228.ico
# End Source File
# Begin Source File

SOURCE=.\res\00439.ico
# End Source File
# Begin Source File

SOURCE=.\res\00508.ico
# End Source File
# Begin Source File

SOURCE=.\res\00610.ico
# End Source File
# Begin Source File

SOURCE=.\res\00626.ico
# End Source File
# Begin Source File

SOURCE=.\res\00700.ico
# End Source File
# Begin Source File

SOURCE=.\res\00751.ico
# End Source File
# Begin Source File

SOURCE=.\res\01088.ico
# End Source File
# Begin Source File

SOURCE=.\res\01661.ico
# End Source File
# Begin Source File

SOURCE=.\res\01664.ico
# End Source File
# Begin Source File

SOURCE=.\res\02134.ico
# End Source File
# Begin Source File

SOURCE=.\res\02706.ico
# End Source File
# Begin Source File

SOURCE=.\res\04265.ico
# End Source File
# Begin Source File

SOURCE=.\res\05597.ico
# End Source File
# Begin Source File

SOURCE=.\res\06277.ico
# End Source File
# Begin Source File

SOURCE=.\res\06278.ico
# End Source File
# Begin Source File

SOURCE=.\res\06579.ico
# End Source File
# Begin Source File

SOURCE=.\res\06981.ico
# End Source File
# Begin Source File

SOURCE=.\res\07226.ico
# End Source File
# Begin Source File

SOURCE=.\res\07227.ico
# End Source File
# Begin Source File

SOURCE=.\res\07275.ico
# End Source File
# Begin Source File

SOURCE=.\res\07293.ico
# End Source File
# Begin Source File

SOURCE=.\res\07778.ico
# End Source File
# Begin Source File

SOURCE=.\res\09725.ico
# End Source File
# Begin Source File

SOURCE="C:\Documents and Settings\Administrator\桌面\OutlookTabCtrl_src\res\Background.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\Background.bmp
# End Source File
# Begin Source File

SOURCE=.\res\BIGBUG.bmp
# End Source File
# Begin Source File

SOURCE=..\mfcbind\res\BindDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\BTBack.ico
# End Source File
# Begin Source File

SOURCE=.\res\BTForward.ico
# End Source File
# Begin Source File

SOURCE=.\res\BTRefresh.ico
# End Source File
# Begin Source File

SOURCE=.\res\BTStop.ico
# End Source File
# Begin Source File

SOURCE=C:\Chapter08\res\Chapter08.ico
# End Source File
# Begin Source File

SOURCE=C:\Chapter08\res\Chapter08Doc.ico
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

SOURCE="C:\Documents and Settings\Administrator\桌面\新建文件夹\res\code_project.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\code_project.bmp
# End Source File
# Begin Source File

SOURCE="C:\Documents and Settings\Administrator\桌面\新建文件夹\res\code_project.ico"
# End Source File
# Begin Source File

SOURCE=.\res\code_project.ico
# End Source File
# Begin Source File

SOURCE=..\CodeProject\CustomTabCtrlDemo\CustomTabCtrlDemoSDI\res\CustomTabCtrlDemoSDI.ico
# End Source File
# Begin Source File

SOURCE=..\CodeProject\CustomTabCtrlDemo\CustomTabCtrlDemoSDI\res\CustomTabCtrlDemoSDIDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\cw_toolb.bmp
# End Source File
# Begin Source File

SOURCE=..\CodeProject\CustomTabCtrlDemo\CustomTabCtrlDemoSDI\res\DRAGMOVE.CUR
# End Source File
# Begin Source File

SOURCE=.\res\DRAGMOVE.CUR
# End Source File
# Begin Source File

SOURCE=.\res\dummy.bmp
# End Source File
# Begin Source File

SOURCE="D:\my code\XI\res\dx.ico"
# End Source File
# Begin Source File

SOURCE="..\my code\XI\res\dx.ico"
# End Source File
# Begin Source File

SOURCE=.\res\flashpause.BMP
# End Source File
# Begin Source File

SOURCE=.\res\flashplay.BMP
# End Source File
# Begin Source File

SOURCE=.\res\flashstop.BMP
# End Source File
# Begin Source File

SOURCE=.\res\FlashToolBar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\fullscreen.BMP
# End Source File
# Begin Source File

SOURCE="D:\my code\XI\res\icon1.ico"
# End Source File
# Begin Source File

SOURCE=.\res\icon1.ico
# End Source File
# Begin Source File

SOURCE="..\my code\XI\res\icon1.ico"
# End Source File
# Begin Source File

SOURCE="D:\my code\XI\res\icon2.ico"
# End Source File
# Begin Source File

SOURCE="..\my code\XI\res\icon2.ico"
# End Source File
# Begin Source File

SOURCE="D:\my code\XI\res\icon3.ico"
# End Source File
# Begin Source File

SOURCE="..\my code\XI\res\icon3.ico"
# End Source File
# Begin Source File

SOURCE=.\res\icon4.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon5.ico
# End Source File
# Begin Source File

SOURCE=..\mfcbind\res\MFCBind.ico
# End Source File
# Begin Source File

SOURCE=.\res\MTAS.ico
# End Source File
# Begin Source File

SOURCE=.\res\MTAS.rc2
# End Source File
# Begin Source File

SOURCE=.\res\MTASDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\navigate.bmp
# End Source File
# Begin Source File

SOURCE=.\res\normalscreen.BMP
# End Source File
# Begin Source File

SOURCE="D:\my code\XI\icon\pause.ico"
# End Source File
# Begin Source File

SOURCE="..\my code\XI\icon\pause.ico"
# End Source File
# Begin Source File

SOURCE="D:\my code\XI\icon\play.ico"
# End Source File
# Begin Source File

SOURCE="..\my code\XI\icon\play.ico"
# End Source File
# Begin Source File

SOURCE="C:\Documents and Settings\Administrator\桌面\OutlookTabCtrl_src\res\Project.ico"
# End Source File
# Begin Source File

SOURCE="C:\Documents and Settings\Administrator\桌面\新建文件夹\res\rt_manif.bin"
# End Source File
# Begin Source File

SOURCE="D:\my code\XI\icon\stop playing.ico"
# End Source File
# Begin Source File

SOURCE="..\my code\XI\icon\stop playing.ico"
# End Source File
# Begin Source File

SOURCE=.\res\Tab.bmp
# End Source File
# Begin Source File

SOURCE="C:\Documents and Settings\Administrator\桌面\OutlookTabCtrl_src\res\TabBig.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\TabBig.bmp"
# End Source File
# Begin Source File

SOURCE="C:\Documents and Settings\Administrator\桌面\OutlookTabCtrl_src\res\TabDisabledBig.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\TabDisabledBig.bmp
# End Source File
# Begin Source File

SOURCE="C:\Documents and Settings\Administrator\桌面\OutlookTabCtrl_src\res\TabDisabledSmall.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\TabDisabledSmall.bmp
# End Source File
# Begin Source File

SOURCE="C:\Documents and Settings\Administrator\桌面\OutlookTabCtrl_src\res\TabSmall.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\TabSmall.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\toolbar1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\toolbar_.bmp
# End Source File
# Begin Source File

SOURCE=.\res\res\ToolBarForFlashList.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ToolBarForFlashList.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ToolBarForList.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ToolBarForPptList.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ToolBarForTabFrame.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ToolBarForTreeChapter.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ToolBarForTreeClass.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ToolBarForTreeContext.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ToolBarForTreeCourseware.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ToolBarForTreeSection.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ToolBarForWord.BMP
# End Source File
# Begin Source File

SOURCE=.\res\ToolBarForWordList.bmp
# End Source File
# Begin Source File

SOURCE="C:\Documents and Settings\Administrator\桌面\新建文件夹\res\tree_closed.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\tree_closed.bmp
# End Source File
# Begin Source File

SOURCE="C:\Documents and Settings\Administrator\桌面\新建文件夹\res\tree_opened.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\tree_opened.bmp
# End Source File
# Begin Source File

SOURCE="C:\Documents and Settings\Administrator\桌面\新建文件夹\res\TreeTest.ico"
# End Source File
# Begin Source File

SOURCE=".\res\高等数学精品课程图标.BMP"
# End Source File
# End Group
# Begin Source File

SOURCE=.\res\click.wav
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
# Section MTAS : {8856F961-340A-11D0-A96B-00C04FD705A2}
# 	2:21:DefaultSinkHeaderFile:webbrowser2.h
# 	2:16:DefaultSinkClass:CWebBrowser2
# End Section
# Section MTAS : {AEB71054-4573-45C3-9866-B2AB63443A9B}
# 	2:23:CLASS: CPersistentFrame:CPersistentFrame
# 	2:11:Persist.cpp:Persist.cpp
# 	2:9:Persist.h:Persist.h
# 	2:19:Application Include:mtas.h
# End Section
# Section MTAS : {D27CDB6E-AE6D-11CF-96B8-444553540000}
# 	2:21:DefaultSinkHeaderFile:shockwaveflash.h
# 	2:16:DefaultSinkClass:CShockwaveFlash
# End Section
# Section MTAS : {D30C1661-CDAF-11D0-8A3E-00C04FC9E26E}
# 	2:5:Class:CWebBrowser2
# 	2:10:HeaderFile:webbrowser2.h
# 	2:8:ImplFile:webbrowser2.cpp
# End Section
# Section MTAS : {D27CDB6C-AE6D-11CF-96B8-444553540000}
# 	2:5:Class:CShockwaveFlash
# 	2:10:HeaderFile:shockwaveflash.h
# 	2:8:ImplFile:shockwaveflash.cpp
# End Section
