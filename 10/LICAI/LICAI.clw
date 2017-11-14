; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLICAIDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "licai.h"
LastPage=0

ClassCount=21
Class1=add
Class2=BAOBIAODLG
Class3=FIND
Class4=GUANLI
Class5=LCSet
Class6=CLICAIApp
Class7=CAboutDlg
Class8=CLICAIDlg
Class9=LOGIN
Class10=PAGE1
Class11=PAGE2
Class12=PAGE3
Class13=PAGE4
Class14=PAGE5
Class15=CPreGoto
Class16=CPreParent
Class17=CPreView
Class18=PWSet
Class19=REGIST
Class20=XGMIMA
Class21=XGQX

ResourceCount=20
Resource1=IDD_PAGE4
Resource2=IDD_PAGE1
Resource3=IDD_FIND
Resource4=IDD_PAGE2
Resource5=IDD_LOGIN
Resource6=IDD_LICAI_DIALOG
Resource7=DLG_SYS_PREVIEW
Resource8=IDD_ABOUTBOX
Resource9=IDD_DIALOG1
Resource10=IDD_ADD
Resource11=DLG_SYS_PREGOTO
Resource12=IDD_GUANLI
Resource13=IDD_PAGE5
Resource14=DLG_SYS_PREPARENT
Resource15=IDD_XGMIMA
Resource16=IDD_BAOBIAO
Resource17=IDD_PAGE3
Resource18=IDD_XGQX
Resource19=IDD_REG
Resource20=IDR_TOOLBAR

[CLS:add]
Type=0
BaseClass=CDialog
HeaderFile=add.h
ImplementationFile=add.cpp
Filter=D
VirtualFilter=dWC

[CLS:BAOBIAODLG]
Type=0
BaseClass=CDialog
HeaderFile=BAOBIAODLG.h
ImplementationFile=BAOBIAODLG.cpp

[CLS:FIND]
Type=0
BaseClass=CDialog
HeaderFile=FIND.h
ImplementationFile=FIND.cpp
LastObject=IDC_month
Filter=D
VirtualFilter=dWC

[CLS:GUANLI]
Type=0
BaseClass=CDialog
HeaderFile=GUANLI.h
ImplementationFile=GUANLI.cpp

[CLS:LCSet]
Type=0
HeaderFile=LCSet.h
ImplementationFile=LCSet.cpp
Filter=N
BaseClass=CRecordset
VirtualFilter=r

[CLS:CLICAIApp]
Type=0
BaseClass=CWinApp
HeaderFile=LICAI.h
ImplementationFile=LICAI.cpp
LastObject=CLICAIApp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=LICAIDlg.cpp
ImplementationFile=LICAIDlg.cpp

[CLS:CLICAIDlg]
Type=0
BaseClass=CDialog
HeaderFile=LICAIDlg.h
ImplementationFile=LICAIDlg.cpp
LastObject=CLICAIDlg

[CLS:LOGIN]
Type=0
BaseClass=CDialog
HeaderFile=LOGIN.h
ImplementationFile=LOGIN.cpp
LastObject=IDC_COMBO1

[CLS:PAGE1]
Type=0
BaseClass=CDialog
HeaderFile=PAGE1.h
ImplementationFile=PAGE1.cpp
LastObject=IDC_LIST1
Filter=D
VirtualFilter=dWC

[CLS:PAGE2]
Type=0
BaseClass=CDialog
HeaderFile=PAGE2.h
ImplementationFile=PAGE2.cpp
LastObject=IDC_REQUERY
Filter=D
VirtualFilter=dWC

[CLS:PAGE3]
Type=0
BaseClass=CDialog
HeaderFile=PAGE3.h
ImplementationFile=PAGE3.cpp
LastObject=IDC_DRAWCOMBI
Filter=D
VirtualFilter=dWC

[CLS:PAGE4]
Type=0
BaseClass=CDialog
HeaderFile=PAGE4.h
ImplementationFile=PAGE4.cpp

[CLS:PAGE5]
Type=0
BaseClass=CDialog
HeaderFile=PAGE5.h
ImplementationFile=PAGE5.cpp

[CLS:CPreGoto]
Type=0
BaseClass=CDialog
HeaderFile=PreGoto.h
ImplementationFile=PreGoto.cpp

[CLS:CPreParent]
Type=0
BaseClass=CDialog
HeaderFile=PreParent.h
ImplementationFile=PreParent.cpp

[CLS:CPreView]
Type=0
BaseClass=CDialog
HeaderFile=PreView.h
ImplementationFile=PreView.cpp

[CLS:PWSet]
Type=0
HeaderFile=PWSet.h
ImplementationFile=PWSet.cpp
Filter=N
BaseClass=CRecordset
VirtualFilter=r

[CLS:REGIST]
Type=0
BaseClass=CDialog
HeaderFile=REGIST.h
ImplementationFile=REGIST.cpp

[CLS:XGMIMA]
Type=0
BaseClass=CDialog
HeaderFile=XGMIMA.h
ImplementationFile=XGMIMA.cpp

[CLS:XGQX]
Type=0
BaseClass=CDialog
HeaderFile=XGQX.h
ImplementationFile=XGQX.cpp

[DB:LCSet]
DB=1
DBType=ODBC
ColumnCount=7
Column1=[id], 4, 4
Column2=[time], 12, 100
Column3=[incometype], 12, 100
Column4=[incomenum], 4, 4
Column5=[costtype], 12, 100
Column6=[costnum], 4, 4
Column7=[about], 12, 100

[DB:PWSet]
DB=1
DBType=ODBC
ColumnCount=3
Column1=[PASSWORD], 12, 20
Column2=[ID], 12, 100
Column3=[AUTHOR], 12, 100

[DLG:IDD_ADD]
Type=1
Class=add
ControlCount=19
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350633600
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_COMBO1,combobox,1344340227
Control9=IDC_COMBO2,combobox,1344340227
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_EDIT2,edit,1350631552
Control13=IDC_EDIT3,edit,1350631552
Control14=IDC_STATIC,static,1342308352
Control15=IDC_EDIT4,edit,1350631552
Control16=IDC_STATIC,button,1342177287
Control17=IDC_STATIC,button,1342177287
Control18=IDC_STATIC,button,1342177287
Control19=IDC_EDIT5,edit,1350633600

[DLG:IDD_BAOBIAO]
Type=1
Class=BAOBIAODLG
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDC_LIST1,SysListView32,1484881921
Control3=IDC_STATIC,button,1342177287

[DLG:IDD_FIND]
Type=1
Class=FIND
ControlCount=12
Control1=IDC_foryear,button,1342308361
Control2=IDC_formonth,button,1342177289
Control3=IDC_forday,button,1342177289
Control4=IDC_month,button,1342177289
Control5=IDOK,button,1342242817
Control6=IDC_COMBO1,combobox,1344340227
Control7=IDC_COMBO2,combobox,1344340227
Control8=IDC_COMBO3,combobox,1344340226
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,button,1342177287

[DLG:IDD_GUANLI]
Type=1
Class=GUANLI
ControlCount=5
Control1=IDC_LIST1,SysListView32,1350631425
Control2=IDC_STATIC,button,1342177287
Control3=IDC_BUTTON1,button,1342242816
Control4=IDC_BUTTON2,button,1342242816
Control5=IDCANCEL,button,1342242816

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=3
Control1=IDC_STATIC,static,1342308480
Control2=IDC_STATIC,static,1342308352
Control3=IDOK,button,1342373889

[DLG:IDD_LICAI_DIALOG]
Type=1
Class=CLICAIDlg
ControlCount=11
Control1=IDCANCEL,button,1342242816
Control2=IDC_TAB1,SysTabControl32,1342177280
Control3=IDC_ADD,button,1342242816
Control4=IDC_MODIFY,button,1342242816
Control5=IDC_GUANLI,button,1342242816
Control6=IDC_STATIC,button,1342177287
Control7=IDC_STATIC,button,1342177287
Control8=IDC_COPY,button,1342242816
Control9=IDC_RECOVER,button,1342242816
Control10=IDZHUXIAO,button,1342242816
Control11=IDC_STATIC,button,1342177287

[DLG:IDD_LOGIN]
Type=1
Class=LOGIN
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_EDIT2,edit,1350631584
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_COMBO1,combobox,1344340227

[DLG:IDD_PAGE1]
Type=1
Class=PAGE1
ControlCount=10
Control1=IDC_LIST1,SysListView32,1350664193
Control2=IDC_ADD,button,1342242816
Control3=IDC_MODIFY,button,1342242816
Control4=IDC_REQUERY,button,1342242816
Control5=IDC_DELE,button,1342242816
Control6=IDC_STATIC,button,1342177287
Control7=IDC_LOOK,button,1342242816
Control8=IDC_FIND,button,1342242816
Control9=IDC_PRINT,button,1342242816
Control10=IDC_STATIC,button,1342177287

[DLG:IDD_PAGE2]
Type=1
Class=PAGE2
ControlCount=5
Control1=IDC_LIST1,SysListView32,1484881921
Control2=IDC_REQUERY,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_EDIT1,edit,1350633540
Control5=IDC_STATIC,button,1342177287

[DLG:IDD_PAGE3]
Type=1
Class=PAGE3
ControlCount=4
Control1=IDC_STATIC,static,1342308352
Control2=IDC_DRAWLINE,button,1342242816
Control3=IDC_DRAWCOMBI,button,1342242816
Control4=IDC_DRAWPIE,button,1342242816

[DLG:IDD_PAGE4]
Type=1
Class=PAGE4
ControlCount=4
Control1=IDC_EDIT1,edit,1352734788
Control2=IDC_SHUXIN,button,1342242816
Control3=IDC_delefile,button,1342242816
Control4=IDC_Open,button,1342242816

[DLG:IDD_PAGE5]
Type=1
Class=PAGE5
ControlCount=0

[DLG:DLG_SYS_PREGOTO]
Type=1
Class=CPreGoto
ControlCount=5
Control1=IDC_STATIC,static,1342308352
Control2=EDT_GOTO,edit,1350631552
Control3=SPIN_GOTO,msctls_updown32,1342177331
Control4=BTN_OK,button,1342242816
Control5=BTN_CANCEL,button,1342242816

[DLG:DLG_SYS_PREPARENT]
Type=1
Class=CPreParent
ControlCount=3
Control1=IDC_SUP,static,1342181383
Control2=IDC_SDOWN,static,1342181383
Control3=IDC_LIST1,listbox,1352728835

[DLG:DLG_SYS_PREVIEW]
Type=1
Class=CPreView
ControlCount=0

[DLG:IDD_REG]
Type=1
Class=REGIST
ControlCount=10
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT1,edit,1350631552
Control8=IDC_EDIT2,edit,1350631584
Control9=IDC_EDIT3,edit,1350631584
Control10=IDC_COMBO1,combobox,1344340227

[DLG:IDD_XGMIMA]
Type=1
Class=XGMIMA
ControlCount=10
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT1,edit,1350631552
Control8=IDC_EDIT2,edit,1350631584
Control9=IDC_EDIT3,edit,1350631584
Control10=IDC_EDIT4,edit,1350631584

[DLG:IDD_XGQX]
Type=1
Class=XGQX
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT1,edit,1350633600
Control6=IDC_COMBO1,combobox,1344340227

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

[DLG:IDD_DIALOG1]
Type=1
Class=?
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

