; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CHCCPDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "HCCP.h"
LastPage=0

ClassCount=13
Class1=ADDDLG
Class2=CHCCPApp
Class3=CAboutDlg
Class4=CHCCPDlg
Class5=Hutext
Class6=MyTree

ResourceCount=14
Resource1=DLG_SYS_PREVIEW
Resource2=DLG_SYS_PREGOTO
Resource3=IDD_XSCJXG
Class7=XSCJXG
Resource4=IDD_DIALOG1
Class8=XSCJCX
Resource5=IDD_XSCJPX
Class9=JIEGUO
Resource6=IDD_HCCP_DIALOG
Class10=XSCJPX
Resource7=IDD_ZHPCDLG
Class11=ZHPCDLG
Resource8=IDD_ABOUTBOX
Class12=XSZHPC
Resource9=IDD_XKXFXG
Class13=XKXFXG
Resource10=IDD_ADDDLG
Resource11=IDD_XSZHPC
Resource12=IDD_XSCJCX
Resource13=DLG_SYS_PREPARENT
Resource14=IDR_TOOLBAR

[CLS:ADDDLG]
Type=0
BaseClass=CDialog
HeaderFile=ADDDLG.h
ImplementationFile=ADDDLG.cpp
LastObject=ADDDLG
Filter=D
VirtualFilter=dWC

[CLS:CHCCPApp]
Type=0
BaseClass=CWinApp
HeaderFile=HCCP.h
ImplementationFile=HCCP.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=HCCPDlg.cpp
ImplementationFile=HCCPDlg.cpp
LastObject=CAboutDlg

[CLS:CHCCPDlg]
Type=0
BaseClass=CDialog
HeaderFile=HCCPDlg.h
ImplementationFile=HCCPDlg.cpp
Filter=D
VirtualFilter=dWC
LastObject=CHCCPDlg

[CLS:Hutext]
Type=0
BaseClass=CStatic
HeaderFile=Hutext.h
ImplementationFile=Hutext.cpp

[CLS:MyTree]
Type=0
BaseClass=CTreeCtrl
HeaderFile=MyTree.h
ImplementationFile=MyTree.cpp
LastObject=MyTree

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_HCCP_DIALOG]
Type=1
Class=CHCCPDlg
ControlCount=5
Control1=IDC_TREE1,SysTreeView32,1350631431
Control2=IDC_LIST1,SysListView32,1350631425
Control3=IDC_TAB1,SysTabControl32,1342178304
Control4=IDC_STATIC,static,1342308865
Control5=IDC_BIAOTI,static,1342308865

[DLG:IDD_ADDDLG]
Type=1
Class=ADDDLG
ControlCount=10
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_MZ,static,1342308865
Control4=IDC_NAME,edit,1350631552
Control5=IDC_KECHENGHAO,static,1342308865
Control6=IDC_CNO,edit,1350631552
Control7=IDC_XXUEFEN,static,1342308865
Control8=IDC_CGRADE,edit,1350631552
Control9=IDC_CHECK1,button,1342242819
Control10=IDC_XHAO,combobox,1344340226

[DLG:IDD_XSCJXG]
Type=1
Class=XSCJXG
ControlCount=9
Control1=IDC_STATIC,static,1342308865
Control2=IDC_STATIC,static,1342308865
Control3=IDC_SNO,edit,1350633601
Control4=IDC_SGRADE,edit,1350631553
Control5=IDC_SPIN1,msctls_updown32,1342308406
Control6=IDC_XIU,button,1342251008
Control7=IDC_DELCY,button,1342251008
Control8=IDC_STATIC,static,1342308865
Control9=IDC_SNAME,edit,1350631553

[CLS:XSCJXG]
Type=0
HeaderFile=XSCJXG.h
ImplementationFile=XSCJXG.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_SNAME
VirtualFilter=dWC

[DLG:IDD_DIALOG1]
Type=1
Class=JIEGUO
ControlCount=2
Control1=IDC_LIST2,SysListView32,1350631425
Control2=IDC_TIAOMU,static,1342308865

[DLG:IDD_XSCJCX]
Type=1
Class=XSCJCX
ControlCount=5
Control1=IDC_STATIC,static,1342308865
Control2=IDC_FIND,button,1342251008
Control3=IDC_GUANJIAN,edit,1350631552
Control4=IDC_STATIC,static,1342308865
Control5=IDC_FANWEI,combobox,1344340226

[CLS:XSCJCX]
Type=0
HeaderFile=XSCJCX.h
ImplementationFile=XSCJCX.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_FANWEI
VirtualFilter=dWC

[CLS:JIEGUO]
Type=0
HeaderFile=JIEGUO.h
ImplementationFile=JIEGUO.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_LIST2
VirtualFilter=dWC

[DLG:IDD_XSCJPX]
Type=1
Class=XSCJPX
ControlCount=3
Control1=IDC_STATIC,static,1342308865
Control2=IDC_YIJU,combobox,1344340226
Control3=IDC_SORT,button,1342242816

[CLS:XSCJPX]
Type=0
HeaderFile=XSCJPX.h
ImplementationFile=XSCJPX.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_SORT

[DLG:IDD_ZHPCDLG]
Type=1
Class=ZHPCDLG
ControlCount=12
Control1=IDC_LIST3,SysListView32,1350631425
Control2=IDC_STATIC,static,1342308865
Control3=IDC_STATIC,static,1342308865
Control4=IDC_STATIC,static,1342308865
Control5=IDC_STATIC,static,1342308865
Control6=IDC_ZHIYU,edit,1350631553
Control7=IDC_DEYU,edit,1350631553
Control8=IDC_TIYU,edit,1350631553
Control9=IDC_FUJIA,edit,1350631553
Control10=IDC_JISUAN,button,1342242816
Control11=IDC_ZPX,button,1342242816
Control12=IDC_PRINT,button,1342242816

[CLS:ZHPCDLG]
Type=0
HeaderFile=ZHPCDLG.h
ImplementationFile=ZHPCDLG.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_DEYU
VirtualFilter=dWC

[DLG:IDD_XSZHPC]
Type=1
Class=XSZHPC
ControlCount=5
Control1=IDC_STATIC,static,1342308865
Control2=IDC_XUEYUAN,combobox,1344340226
Control3=IDC_STATIC,static,1342308865
Control4=IDC_BANJI,combobox,1344340226
Control5=IDC_ZHPCBT,button,1342251008

[CLS:XSZHPC]
Type=0
HeaderFile=XSZHPC.h
ImplementationFile=XSZHPC.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_BANJI
VirtualFilter=dWC

[DLG:IDD_XKXFXG]
Type=1
Class=XKXFXG
ControlCount=5
Control1=IDC_STATIC,static,1342308865
Control2=IDC_XKM,edit,1350633601
Control3=IDC_STATIC,static,1342308865
Control4=IDC_XUEKF,edit,1350639745
Control5=IDC_XFXG,button,1342251008

[CLS:XKXFXG]
Type=0
HeaderFile=XKXFXG.h
ImplementationFile=XKXFXG.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_XKM
VirtualFilter=dWC

[DLG:DLG_SYS_PREVIEW]
Type=1
Class=?
ControlCount=0

[DLG:DLG_SYS_PREPARENT]
Type=1
Class=?
ControlCount=3
Control1=IDC_SUP,static,1342181383
Control2=IDC_SDOWN,static,1342181383
Control3=IDC_LIST1,listbox,1352728835

[DLG:DLG_SYS_PREGOTO]
Type=1
Class=?
ControlCount=5
Control1=IDC_STATIC,static,1342308352
Control2=EDT_GOTO,edit,1350631552
Control3=SPIN_GOTO,msctls_updown32,1342177331
Control4=BTN_OK,button,1342242816
Control5=BTN_CANCEL,button,1342242816

[TB:IDR_TOOLBAR]
Type=1
Class=?
Command1=TBTN_TOP
Command2=TBTN_PREVIOUS
Command3=TBTN_GOTO
Command4=TBTN_NEXT
Command5=TBTN_LAST
Command6=TBTN_EXIT
Command7=TBTN_PRINT
CommandCount=7

