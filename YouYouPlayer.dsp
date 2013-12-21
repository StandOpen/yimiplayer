# Microsoft Developer Studio Project File - Name="YouYouPlayer" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=YouYouPlayer - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "YouYouPlayer.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "YouYouPlayer.mak" CFG="YouYouPlayer - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "YouYouPlayer - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "YouYouPlayer - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "YouYouPlayer - Win32 Release"

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

!ELSEIF  "$(CFG)" == "YouYouPlayer - Win32 Debug"

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

# Name "YouYouPlayer - Win32 Release"
# Name "YouYouPlayer - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\IsMiniDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\LrcDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MulitLineListBox.cpp
# End Source File
# Begin Source File

SOURCE=.\MyButton.cpp
# End Source File
# Begin Source File

SOURCE=.\MyListBox.cpp
# End Source File
# Begin Source File

SOURCE=.\MyMemDC.cpp
# End Source File
# Begin Source File

SOURCE=.\MySlider.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\YouYouPlayer.cpp
# End Source File
# Begin Source File

SOURCE=.\YouYouPlayer.rc
# End Source File
# Begin Source File

SOURCE=.\YouYouPlayerDlg.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\IsMiniDlg.h
# End Source File
# Begin Source File

SOURCE=.\LrcDlg.h
# End Source File
# Begin Source File

SOURCE=.\MulitLineListBox.h
# End Source File
# Begin Source File

SOURCE=.\MyButton.h
# End Source File
# Begin Source File

SOURCE=.\MyListBox.h
# End Source File
# Begin Source File

SOURCE=.\MyMemDC.h
# End Source File
# Begin Source File

SOURCE=.\MySlider.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\YouYouPlayer.h
# End Source File
# Begin Source File

SOURCE=.\YouYouPlayerDlg.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\12.bmp
# End Source File
# Begin Source File

SOURCE=.\res\13.bmp
# End Source File
# Begin Source File

SOURCE=.\res\20120713032143221_easyicon_cn_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\20120713032253311_easyicon_cn_48.ico
# End Source File
# Begin Source File

SOURCE=.\res\20120713032304109_easyicon_cn_48.ico
# End Source File
# Begin Source File

SOURCE=.\res\20120713032312354_easyicon_cn_48.ico
# End Source File
# Begin Source File

SOURCE=.\res\20120713032320335_easyicon_cn_48.ico
# End Source File
# Begin Source File

SOURCE=.\res\20120804100358978_easyicon_cn_48.ico
# End Source File
# Begin Source File

SOURCE=.\res\20120804100401770_easyicon_cn_48.ico
# End Source File
# Begin Source File

SOURCE=.\res\20120804100403566_easyicon_cn_48.ico
# End Source File
# Begin Source File

SOURCE=.\res\20120804100407259_easyicon_cn_48.ico
# End Source File
# Begin Source File

SOURCE=.\res\20120804100411164_easyicon_cn_48.ico
# End Source File
# Begin Source File

SOURCE=.\res\9004.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap8.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Button_close_00.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Button_close_01.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Button_min_00.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Button_min_02.bmp
# End Source File
# Begin Source File

SOURCE=.\res\cue.ico
# End Source File
# Begin Source File

SOURCE=.\res\cursorHand.cur
# End Source File
# Begin Source File

SOURCE=.\res\hand1.cur
# End Source File
# Begin Source File

SOURCE=.\res\hand2.cur
# End Source File
# Begin Source File

SOURCE=.\res\laba.bmp
# End Source File
# Begin Source File

SOURCE=.\res\laba_0.bmp
# End Source File
# Begin Source File

SOURCE=.\res\laba_1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\logo.bmp
# End Source File
# Begin Source File

SOURCE=.\res\shutdown.ico
# End Source File
# Begin Source File

SOURCE=.\res\YouYouPlayer.ico
# End Source File
# Begin Source File

SOURCE=.\res\YouYouPlayer.rc2
# End Source File
# Begin Source File

SOURCE=".\res\¿Æ∞».ico"
# End Source File
# Begin Source File

SOURCE=".\res\¿Æ∞»2.ico"
# End Source File
# Begin Source File

SOURCE=".\res\“Ù¿÷.ico"
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
