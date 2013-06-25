@echo off
echo Creating directories...
if not exist Release md Release
echo .

echo Generatin initial loader...
rem if exist Release\vbr.com del Release\vbr.com
..\bin\Release\i386\bkgen Release\vbr.com
echo.

echo Creating excutable installer
..\bin\Release\i386\fj ..\bin\Release\i386\bksetup.exe bksetup.cfg release\bksetup.exe

echo .
echo Creating DLL installer
..\bin\Release\i386\fj setupdll.cfg 

if exist Release\vbr.com del Release\vbr.com