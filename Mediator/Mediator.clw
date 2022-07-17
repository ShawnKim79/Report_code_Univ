; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMediatorDlg
LastTemplate=CEditView
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Mediator.h"

ClassCount=4
Class1=CMediatorApp
Class2=CMediatorDlg

ResourceCount=2
Resource1=IDR_MAINFRAME
Class3=CInputWnd
Class4=COutputWnd
Resource2=IDD_MEDIATOR_DIALOG

[CLS:CMediatorApp]
Type=0
HeaderFile=Mediator.h
ImplementationFile=Mediator.cpp
Filter=N

[CLS:CMediatorDlg]
Type=0
HeaderFile=MediatorDlg.h
ImplementationFile=MediatorDlg.cpp
Filter=D
LastObject=CMediatorDlg
BaseClass=CDialog
VirtualFilter=dWC



[DLG:IDD_MEDIATOR_DIALOG]
Type=1
Class=CMediatorDlg
ControlCount=3
Control1=IDC_BUTTONTRANS,button,1342242816
Control2=IDC_EDITINPUT,edit,1350635648
Control3=IDC_EDITOUTPUT,edit,1350631552

[CLS:CInputWnd]
Type=0
HeaderFile=InputWnd.h
ImplementationFile=InputWnd.cpp
BaseClass=CEdit
Filter=W
VirtualFilter=WC
LastObject=CInputWnd

[CLS:COutputWnd]
Type=0
HeaderFile=OutputWnd.h
ImplementationFile=OutputWnd.cpp
BaseClass=CEditView
Filter=C

