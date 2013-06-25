@echo off
echo Creating directories...
if not exist Release md Release

echo .
echo Creating excutable installer
..\release\fj ..\release\bksetup.exe bksetup.cfg release\bksetup.exe

echo .
echo Creating DLL installer
..\release\fj setupdll.cfg 