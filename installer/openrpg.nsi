!include "MUI2.nsh"

!ifndef VERSION
  !define VERSION "0.0.0"
!endif

Name "openrpg ${VERSION}"
OutFile "openrpg-${VERSION}-windows-x64.exe"
InstallDir "$PROGRAMFILES64\openrpg"
InstallDirRegKey HKLM "Software\openrpg" "InstallDir"
RequestExecutionLevel admin
Unicode true

!define MUI_ABORTWARNING

!insertmacro MUI_PAGE_WELCOME
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_INSTFILES
!insertmacro MUI_PAGE_FINISH

!insertmacro MUI_UNPAGE_CONFIRM
!insertmacro MUI_UNPAGE_INSTFILES

!insertmacro MUI_LANGUAGE "English"

Section "Install"
    SetOutPath "$INSTDIR"
    File "rpgc.exe"

    SetOutPath "$INSTDIR\runtime"
    File "rpg_runtime.h"
    File "rpg_sql_runtime.h"
    File "rpg_xml_runtime.h"
    File "rpg_json_runtime.h"

    ; Add install dir to system PATH
    nsExec::ExecToStack "powershell -NonInteractive -Command $\"[Environment]::SetEnvironmentVariable('PATH', [Environment]::GetEnvironmentVariable('PATH', 'Machine') + ';$INSTDIR', 'Machine')$\""

    WriteUninstaller "$INSTDIR\uninstall.exe"

    WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\openrpg" "DisplayName" "openrpg"
    WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\openrpg" "UninstallString" '"$INSTDIR\uninstall.exe"'
    WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\openrpg" "DisplayVersion" "${VERSION}"
    WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\openrpg" "Publisher" "Daniel Long"
    WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\openrpg" "NoModify" 1
    WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\openrpg" "NoRepair" 1
SectionEnd

Section "Uninstall"
    Delete "$INSTDIR\rpgc.exe"
    Delete "$INSTDIR\runtime\rpg_runtime.h"
    Delete "$INSTDIR\runtime\rpg_sql_runtime.h"
    Delete "$INSTDIR\runtime\rpg_xml_runtime.h"
    Delete "$INSTDIR\runtime\rpg_json_runtime.h"
    Delete "$INSTDIR\uninstall.exe"
    RMDir "$INSTDIR\runtime"
    RMDir "$INSTDIR"

    ; Remove install dir from system PATH
    nsExec::ExecToStack "powershell -NonInteractive -Command $\"$$p = [Environment]::GetEnvironmentVariable('PATH', 'Machine'); $$p = ($$p -split ';' | Where-Object { $$_ -ne '$INSTDIR' }) -join ';'; [Environment]::SetEnvironmentVariable('PATH', $$p, 'Machine')$\""

    DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\openrpg"
    DeleteRegKey HKLM "Software\openrpg"
SectionEnd
