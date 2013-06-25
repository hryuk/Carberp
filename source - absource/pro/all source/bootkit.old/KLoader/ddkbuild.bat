@echo off
setlocal
::
:: $Header: /test/LocalBin/ddkbuild.bat,v 1.12 2005/10/31 05:01:40 markr Exp $
::
set version=3.15.38

set quiet=0
if "%1" NEQ "-quiet" goto noquiet
set quiet=1
shift
:noquiet

if %quiet% EQU 0 (
  @echo DDKBUILD VERSION %version% FREEWARE FROM HOLLIS TECHNOLOGY SOLUTIONS
  @echo Comments? Suggestions? info@hollistech.com
)  

set scriptDebug=off
if "%1" NEQ "-debug" goto nodebug
set scriptDebug=on
shift
:nodebug

@echo %scriptDebug%

set verbose=0
if "%1" NEQ "-verbose" goto noverbose
set verbose=1
shift
:noverbose

set status=0

VERIFY OTHER 2>nul
setlocal ENABLEEXTENSIONS
if ERRORLEVEL 1 goto wrongplatform
::
:: some shells is different
::
set foo=dog
if %foo% EQU cat (
    set foo=rat 
) else (
    set foo=cat
)
if %foo% EQU dog goto :nt4ddkbuild   

if /I "%1" EQU "/?"    goto usage   
::
:: next test, some shells is different
::
setlocal enabledelayedexpansion
set VAR=before
if "%VAR%" == "before" (
     set VAR=after
     if "!VAR!" == "after" (
        :: @echo W2K or later system
        call :ddkbuild %*
      ) else (
        @echo nt4 or earlier system
        call :nt4ddkbuild %*
      )
      goto buildExit
)

set status=0
goto buildExit
::
:: ================
:: the latest and greatest ddkbuild
:: ================
::
:ddkbuild

if %verbose% EQU 1 @echo process args
:removeScriptArgs
if "%1" == "-debug" (
    shift
    goto removeScriptArgs
)    
if "%1" == "-verbose"  (
    shift
    goto removeScriptArgs
)    
if "%1" == "-quiet"  (
    shift
    goto removeScriptArgs
)    

set w2kflag=
:: ================
:: NOTE: w2kflag appears to be somewhat obsolete,
:: at best it is either null or non-null.
:: buildbsc may use its value, but the setting of 
:: that value is inconsistent.
:: ================
::
set chk=checked
set fre=free
set xp64=
set xp2k=0
set wnet=
set wlh=
set ddk=UNKNOWN
set prefast=
set mode=
set setenv=setenv.bat
set wdf=0
set oacrPolicy=
set separateRootSupport=
set separateRootPolicy=

if "%1" EQU ""     goto usage
if /I %1 EQU -h  goto usage
if /I %1 EQU -help goto usage
::
:: test for all known ddk variations
::
:: =========================
:: XP DDK Support (Obsolete)
:: =========================
::
:: regular xp
::
if /I "%1" EQU "-XP" (
    set w2kflag=W2K
    shift
    if "%XPBASE%" EQU "" goto NoXPBase    
    set BASEDIR=%XPBASE%
    set chk=chk
    set fre=fre
    set ddk=XP
    goto buildswitchdone
) 
::
:: 64bit xp
::
if /I "%1" EQU "-XP64" (
    set w2kflag=W2K
    shift
    if "%XPBASE%" EQU "" goto NoXPBase    
    set BASEDIR=%XPBASE%
    set chk=chk
    set fre=fre
    set xp64=64
    set ddk=XP
    goto buildswitchdone
) 
::
:: w2k build/xp ddk
::
if /I "%1" EQU "-XPW2K" (
    set w2kflag=W2K
    set xp2k=1
    shift
    if "%XPBASE%" EQU "" goto NoXPBase    
    set BASEDIR=%XPBASE%
    set chk=checked
    set fre=free
    set ddk=XP
    goto buildswitchdone
)
::
:: =========================
:: NET DDK Support
:: =========================
::
:: .net ddk .net build
::
if /I "%1" EQU "-WNET" (
    set w2kflag=W2K
    shift
    if "%WNETBASE%" EQU "" goto NoWNBase    
    set BASEDIR=%WNETBASE%
    set chk=chk
    set fre=fre
    set wnet=wnet
    set ddk=NET
    goto buildswitchdone
)
::
:: .net ddk w2k build
::
if /I "%1" EQU "-WNETW2K" (
    set w2kflag=NET
    shift
    if "%WNETBASE%" EQU "" goto NoWNBase    
    set BASEDIR=%WNETBASE%
    set chk=chk
    set fre=free
    set wnet=w2k
    set ddk=NET
    goto buildswitchdone
)
::
:: .net ddk xp build
::
if /I "%1" EQU "-WNETXP" (
    set w2kflag=NET
    shift
    if "%WNETBASE%" EQU "" goto NoWNBase    
    set BASEDIR=%WNETBASE%
    set chk=chk
    set fre=fre
    set wnet=wxp
    set ddk=NET
    goto buildswitchdone
)
::
:: .net ddk IA64 build
::
if /I "%1" EQU "-WNET64" (
    set w2kflag=NET
    shift
    if "%WNETBASE%" EQU "" goto NoWNBase    
    set BASEDIR=%WNETBASE%
    set chk=chk
    set fre=fre
    set xp64=64
    set wnet=wnet
    set ddk=NET
    goto buildswitchdone
)
::
:: .net ddk AMD64 build
::
if /I "%1" EQU "-WNETA64" (
    set w2kflag=NET
    shift
    if "%WNETBASE%" EQU "" goto NoWNBase    
    set BASEDIR=%WNETBASE%
    set chk=chk
    set fre=fre
    set xp64=AMD64
    set wnet=wnet
    set ddk=NET
    goto buildswitchdone
)
::
:: ============================
:: Longhorn (Vista) WDK Support
:: Also supports W2K8 6001 WDK
:: ============================
::
:: wlh ddk wlh build
::
if /I "%1" EQU "-WLH" (
    set w2kflag=NET
    shift
    if "%WLHBASE%" EQU "" goto NoWLHBase    
    set BASEDIR=%WLHBASE%
    set chk=chk
    set fre=fre
    set wnet=wlh
    set ddk=WLH
    goto buildswitchdone
)
::
:: wlh ddk IA64 net build
::
if /I "%1" EQU "-WLH64" (
    set w2kflag=NET
    shift
    if "%WLHBASE%" EQU "" goto NoWLHBase    
    set BASEDIR=%WLHBASE%
    set chk=chk
    set fre=fre
    set xp64=64
    set wnet=wlh
    set ddk=WLH
    goto buildswitchdone
)
::
:: wlh ddk AMD64 net build
::
if /I "%1" EQU "-WLHA64" (
    set w2kflag=NET
    shift
    if "%WLHBASE%" EQU "" goto NoWLHBase 
    if EXIST "%WLHBASE%"\DDKVersion.xml (
	    set xp64=x64
	) else (	    
        set xp64=AMD64
	)	
    set BASEDIR=%WLHBASE%
    set chk=chk
    set fre=fre
    set wnet=wlh
    set ddk=WLH
    goto buildswitchdone
)
::
:: wlh ddk w2k build
::
if /I "%1" EQU "-WLHW2K" (
    set w2kflag=NET
    shift
    if "%WLHBASE%" EQU "" goto NoWLHBase    
    set BASEDIR=%WLHBASE%
    set chk=chk
    set fre=free
    set wnet=w2k
    set ddk=WLH
    goto buildswitchdone
)
::
:: wlh ddk xp build
::
if /I "%1" EQU "-WLHXP" (
    set w2kflag=NET
    shift
    if "%WLHBASE%" EQU "" goto NoWLHBase    
    set BASEDIR=%WLHBASE%
    set chk=chk
    set fre=fre
    set wnet=wxp
    set ddk=WLH
    goto buildswitchdone
)
::
:: wlh ddk xp IA64 build
::
if /I "%1" EQU "-WLHXP64" (
    set w2kflag=NET
    shift
    if "%WLHBASE%" EQU "" goto NoWLHBase    
    set BASEDIR=%WLHBASE%
    set chk=chk
    set fre=fre
    set wnet=wxp
    set xp64=64
    set ddk=WLH
    goto buildswitchdone
)

:: wlh ddk .net build
if /I "%1" EQU "-WLHNET" (
    set w2kflag=W2K
    shift
    if "%WLHBASE%" EQU "" goto NoWLHBase    
    set BASEDIR=%WLHBASE%
    set chk=chk
    set fre=fre
    set wnet=wnet
    set ddk=WLH
    goto buildswitchdone
)
::
:: wlh ddk IA64 net build
::
if /I "%1" EQU "-WLHNET64" (
    set w2kflag=NET
    shift
    if "%WLHBASE%" EQU "" goto NoWLHBase    
    set BASEDIR=%WLHBASE%
    set chk=chk
    set fre=fre
    set xp64=64
    set wnet=wnet
    set ddk=WLH
    goto buildswitchdone
)
::
:: wlh ddk AMD64 net build
::
if /I "%1" EQU "-WLHNETA64" (
    set w2kflag=NET
    shift
    if "%WLHBASE%" EQU "" goto NoWLHBase
    if EXIST "%WLHBASE%"\DDKVersion.xml (
	    set xp64=x64
	) else (	    
        set xp64=AMD64
	)	    
    set BASEDIR=%WLHBASE%
    set chk=chk
    set fre=fre
    set wnet=wnet
    set ddk=WLH
    goto buildswitchdone
)
::
:: ============================
:: WIN7 WDK Support
:: ============================
::
:: WIN7 ddk x86 WIN7  build
::
if /I "%1" EQU "-WIN7" (
    set w2kflag=NET
    shift
    if "%WIN7BASE%" EQU "" goto NoWIN7Base    
    set BASEDIR=%WIN7BASE%
    set chk=chk
    set fre=fre
    set xp64=x86
    set wnet=win7
    set ddk=WIN7
    set oacrPolicy=no_oacr
    set separateRootSupport=1
    goto buildswitchdone
)
::
:: WIN7 ddk IA64 WIN7 build
::
if /I "%1" EQU "-WIN764" (
    set w2kflag=NET
    shift
    if "%WIN7BASE%" EQU "" goto NoWIN7Base    
    set BASEDIR=%WIN7BASE%
    set chk=chk
    set fre=fre
    set xp64=64
    set wnet=win7
    set ddk=WIN7
    set oacrPolicy=no_oacr
    set separateRootSupport=1
    goto buildswitchdone
)
::
:: WIN7 ddk AMD64 WIN7 build
::
if /I "%1" EQU "-WIN7A64" (
    set w2kflag=NET
    shift
    if "%WIN7BASE%" EQU "" goto NoWIN7Base 
	set xp64=x64
    set BASEDIR=%WIN7BASE%
    set chk=chk
    set fre=fre
    set wnet=win7
    set ddk=WIN7
    set oacrPolicy=no_oacr
    set separateRootSupport=1
    goto buildswitchdone
)

::
:: WIN7 ddk x86 WLH  build
::
if /I "%1" EQU "-WIN7WLH" (
    set w2kflag=NET
    shift
    if "%WIN7BASE%" EQU "" goto NoWIN7Base    
    set BASEDIR=%WIN7BASE%
    set chk=chk
    set fre=fre
    set xp64=x86
    set wnet=wlh
    set ddk=WIN7
    set oacrPolicy=no_oacr
    set separateRootSupport=1
    goto buildswitchdone
)
::
:: WIN7 ddk IA64 WLH build
::
if /I "%1" EQU "-WIN7WLH64" (
    set w2kflag=NET
    shift
    if "%WIN7BASE%" EQU "" goto NoWIN7Base    
    set BASEDIR=%WIN7BASE%
    set chk=chk
    set fre=fre
    set xp64=64
    set wnet=wlh
    set ddk=WIN7
    set oacrPolicy=no_oacr
    set separateRootSupport=1
    goto buildswitchdone
)
::
:: WIN7 ddk AMD64 WLH build
::
if /I "%1" EQU "-WIN7WLHA64" (
    set w2kflag=NET
    shift
    if "%WIN7BASE%" EQU "" goto NoWIN7Base 
	set xp64=x64
    set BASEDIR=%WIN7BASE%
    set chk=chk
    set fre=fre
    set wnet=wlh
    set ddk=WIN7
    set oacrPolicy=no_oacr
    set separateRootSupport=1
    goto buildswitchdone
)
::
:: WIN7 ddk x86 xp build
::
if /I "%1" EQU "-WIN7XP" (
    set w2kflag=NET
    shift
    if "%WIN7BASE%" EQU "" goto NoWIN7Base    
    set BASEDIR=%WIN7BASE%
    set chk=chk
    set fre=fre
    set xp64=x86
    set wnet=wxp
    set ddk=WIN7
    set oacrPolicy=no_oacr
    set separateRootSupport=1
    goto buildswitchdone
)
::
::WIN7 ddk .net build
::
if /I "%1" EQU "-WIN7NET" (
    set w2kflag=NET
    shift
    if "%WIN7BASE%" EQU "" goto NoWIN7HBase    
    set BASEDIR=%WIN7BASE%
    set chk=chk
    set fre=fre
    set xp64=x86
    set wnet=wnet
    set ddk=WIN7
    set oacrPolicy=no_oacr
    set separateRootSupport=1
    goto buildswitchdone
)
::
:: WIN7 ddk IA64 net build
::
if /I "%1" EQU "-WIN7NET64" (
    set w2kflag=NET
    shift
    if "%WIN7BASE%" EQU "" goto NoWIN7Base    
    set BASEDIR=%WIN7BASE%
    set chk=chk
    set fre=fre
    set xp64=64
    set wnet=wnet
    set ddk=WIN7
    set oacrPolicy=no_oacr
    set separateRootSupport=1
    goto buildswitchdone
)
::
:: WIN7 ddk AMD64 net build
::
if /I "%1" EQU "-WIN7NETA64" (
    set w2kflag=NET
    shift
    if "%WIN7BASE%" EQU "" goto NoWIN7Base
	set xp64=x64
    set BASEDIR=%WIN7BASE%
    set chk=chk
    set fre=fre
    set wnet=wnet
    set ddk=WIN7
    set oacrPolicy=no_oacr
    set separateRootSupport=1
    goto buildswitchdone
)

:buildswitchdone
::
:: =====================
:: arg sanity tests
:: =====================
::
if %verbose% EQU 1 @echo sanity tests

if "%w2kflag%" EQU "" goto BadTarget

if "%BASEDIR%" EQU "" goto ErrNoBASEDIR
set path=%BASEDIR%\bin;%path%
if "%scriptDebug%" EQU "on" @echo PATH: %PATH%
::
:: =====================
:: optional arguments
:: =====================
:optional_args
if /I "%1" EQU "-drvfast" goto optArgOk
if /I "%1" EQU "-prefast" goto optArgOk
if /I "%1" EQU "-cuv" goto optArgOk
if /I "%1" EQU "-oacr" goto optArgOk
if /I "%1" EQU "-root" goto optArgOk
::
:: =====================
:: optional arguments processed
:: =====================
::
goto endOptArgs

:optArgOk 
::
:: =====================
:: check drvfast switch
:: =====================
::
if /I "%1" EQU "-drvfast" (
    if %verbose% EQU 1 @echo drvfast support
    set prefast=prefast
    if EXIST %basedir%\bin\drvfast.cmd (
        set setenv=drvfast.cmd
    ) else if EXIST %basedir%\bin\drvfast.bat (
        set setenv=drvfast.bat
    )     
    shift
)    
::
:: =====================
:: check prefast switch
:: =====================
::
if /I "%1" EQU "-prefast" (
    if %verbose% EQU 1 @echo prefast support 
    set prefast=prefast
    shift
)

::
:: ====================
:: force prefast log file to build dir so we know where it is and
:: so it does not conflict with other activities
:: ===================
::
if "%prefast%" NEQ "" (
    set prefast_log=.\prefast.xml
    set prefast=!prefast! /log=!prefast_log! 
    if /I "%1" EQU "-prefast_filters" (
        set prefast=!prefast! /filter /FilterPreset=drivers_recommended
        shift
    )
)
::
:: =====================
:: check CUV switch
:: =====================
::
if /I "%1" EQU "-cuv" (
    if %verbose% EQU 1 @echo CUV support
    set VERIFIER_DDK_EXTENSIONS=1
    shift
)
::
:: =====================
:: check oacr switch
:: =====================
:: 
if /I "%1" EQU "-oacr" (
    if %verbose% EQU 1 @echo OACR support selected
    if "%oacrPolicy%" EQU "" (
        @echo OACR not supported
    ) else (
        set oacrPolicy=oacr
    )
    shift
)
::
:: =====================
:: check separateRoot switch
:: =====================
:: 
if /I "%1" EQU "-root" (
    if %verbose% EQU 1 @echo root selected
    if "%separateRootSupport%" EQU "" (
        @echo separate_object_root not supported
    ) else (
        set separateRootPolicy=separate_object_root
    )
    shift
)

goto optional_args
::
:: =====================
:: END of position independent switches
:: =====================
::
:endOptArgs
if /I "%1" EQU "free" (
    set mode=%fre%
) else if /I "%1" EQU "checked" (
    set mode=%chk%
)

if "%mode%" EQU "" goto ErrBadMode
shift

if "%1" EQU "" goto ErrNoDir
if not exist %1 goto ErrNoDir
set buildDir=%1
shift


set batfile=%BASEDIR%\bin\%setenv%
if "%xp2k%" EQU "1" set batfile=%BASEDIR%\bin\w2k\set2k.bat
::
:: =====================
:: invoke the DDK's setenv script
:: =====================
::
endlocal
if %verbose% EQU 1 @echo run ddk setenv
pushd .
if "%w2kflag%" NEQ "" (
    if %verbose% EQU 1 @echo check for .net sp1 ddk
    for /F "usebackq"  %%x IN (`findstr /M "_BscMake" %batfile%`) do (
        if %verbose% EQU 1 @echo call %batfile% %BASEDIR% %mode% %xp64% %wnet% bscmake %oacrPolicy% %separateRootPolicy%
        call %batfile% %BASEDIR% %mode% %xp64% %wnet% bscmake %oacrPolicy% %separateRootPolicy%
        if "%NO_BROWSER_FILE%" NEQ "" (
            set NO_BROWSER_FILE=
            if %verbose% EQU 1 @echo deleted NO_BROWSER_FILE 
        ) 
        if %verbose% EQU 1 (
            @echo post setenv environment
            set
        )            
        goto wnetddkdone
    )
    if %verbose% EQU 1 @echo call %batfile% %BASEDIR% %mode% %xp64% %wnet% %oacrPolicy% %separateRootPolicy%
    call %batfile% %BASEDIR% %mode% %xp64% %wnet% %oacrPolicy% %separateRootPolicy%
) else (
    call %batfile% %BASEDIR% %mode% 
)
:wnetddkdone    
popd
::
:: ======================
:: ancient obsolete WDF beta has its own extra setenv script, so run it if it exists
:: =======================
:: 
if %verbose% EQU 1 @echo WDF_ROOT "%WDF_ROOT%" wdf "%wdf%" 
if %wdf% EQU 1 (    
    if %verbose% EQU 1 @echo check for wdf environment scripts
    if EXIST %WDF_ROOT%\set_wdf_env.cmd (
        if %verbose% EQU 1 @echo run wdf set env
        call %WDF_ROOT%\set_wdf_env.cmd
    )
)
@echo %scriptDebug%
::
:: =====================
:: fixup the multiprocessor flag
:: so that Visual Studio doesn't get confused
:: =====================
::
if %verbose% EQU 1 @echo fix MP flags
set mpFlag=-M
if "%BUILD_ALT_DIR%" EQU "" goto NT4
set W2kEXT=%BUILD_ALT_DIR%
set mpFlag=-MI
:NT4
if "%NUMBER_OF_PROCESSORS%"=="" set mpFlag=
if "%NUMBER_OF_PROCESSORS%" EQU "1" set mpFlag=

set bflags=-e
set bscFlags="/n"
::
:: ===================
:: add any remaining commandline arguments to extraArgs
:: ===================
::
if %verbose% EQU 1 @echo add extra commandline args
:moreargs
if "%~1" NEQ "" (
    if "%~1" EQU "/a" (
        set extraArgs=%extraArgs% -cfe
    ) else (
        set extraArgs=%extraArgs% %~1
    )    
    shift
    goto moreargs
) 
:: set quietMode=
:: if %quiet% EQU 1 set moreExtraArgs=%moreExtraArgs% ^> NUL 2^>^&1
:: if %quiet% EQU 1 set quietMode= ^> NUL 2^>^&1


if EXIST %buildDir%\build%W2kEXT%.err  erase %buildDir%\build%W2kEXT%.err
if EXIST %buildDir%\build%W2kEXT%.wrn  erase %buildDir%\build%W2kEXT%.wrn
if EXIST %buildDir%\build%W2kEXT%.log  erase %buildDir%\build%W2kEXT%.log

if %quiet% EQU 0 (
    @echo.
    @echo DDKBUILD using %ddk% DDK in directory %buildDir% 
    @echo  for %mode% version basedir %BASEDIR% extension %W2kEXT%
    @echo  commandline: "%prefast% build %bflags% %mpFlag% %extraArgs% %quietMode%" 
    @echo.
)


if %verbose% EQU 1 @echo run build using path %path%
pushd .
pushd %buildDir%
::
:: ===================
:: if quiet mode all output goes to NUL
:: ===================
::
if %quiet% EQU 1 (
    %prefast% build  %bflags% %mpFlag% %extraArgs% >NUL 2>&1
) else (
    %prefast% build  %bflags% %mpFlag% %extraArgs%
)    
set status=%ERRORLEVEL%
if %status%==1 set status=0
popd
popd

@echo %scriptDebug%
::
:: ===================
:: assume that the onscreen errors are complete!
:: ===================
::
if %verbose% EQU 1 @echo process error and warning messages
if %quiet% EQU 0 @echo =============== build warnings ======================
if exist %buildDir%\build%W2kEXT%.log (
    if %quiet% EQU 1 (
        findstr "warning.*[CDLU][0-9]* error.*[CDLU][0-9]*" %buildDir%\build%W2kEXT%.log 
    ) else (
        findstr "warning.*[CDLU][0-9]*" %buildDir%\build%W2kEXT%.log
    )    
)

if %verbose% EQU 1 @echo check for warning and error log files
if exist %buildDir%\build%W2kEXT%.wrn (
    set status=3
    if %quiet% EQU 0 (
        @echo.
        @echo warnings found in build!
        @echo.
    )    
)

if exist %buildDir%\build%W2kEXT%.err (
    set status=4
    if %quiet% EQU 0 (
        @echo.
        @echo errors found in build!
        @echo.
    )    
)   

if %quiet% EQU 0 (
    @echo. 
    @echo. 
    @echo build complete status %status%
)    
::
:: ===================
:: BSCMAKE support
:: ===================
::
if %verbose% EQU 1 @echo building browse information files

@echo %scriptDebug%

if EXIST buildbrowse.cmd (
    call :doBrowsescript
    goto postBuildEvents
)

set sbrlist=sbrList.txt
if not EXIST sbrList%CPU%.txt goto sbrDefault
set sbrlist=sbrList%CPU%.txt

:sbrDefault
if not EXIST %sbrlist% goto postBuildEvents
if %bscFlags% == "" goto noBscFlags
bscmake %bscFlags% @%sbrlist%
goto postBuildEvents

:: ===============
:: Subroutines
:: ===============
::
:doBrowsescript
    call buildBrowse %mode% %w2kflag%
goto :EOF
::
:: ===================
:: error handlers
:: ===================
::
:noBscFlags
bscmake @%sbrlist%
goto buildExit


:ErrBadMode
@echo error: first param must be "checked" or "free"
goto usage

:ErrNoBASEDIR
@echo error: BASEDIR environment variable not set, reinstall DDK!
goto usage

:NoW2kBase
@echo error: W2KBASE environment variable not set!
goto usage

:NoW2k64Base
@echo error: W2K64BASE environment variable not set!
goto usage

:NoXPBase
@echo error: XPBASE environment variable not set!
goto usage

:NoWNBase
@echo error: WNETBASE environment variable not set!
goto usage

:NoWLHBase
@echo error: WLHBASE environment variable not set!
goto usage

:ErrnoDir
@echo Error: invalid build directory specified
goto usage

:BadTarget
@echo Error: invalid TARGET specified
goto usage

:NoWDFroot
@echo Error: WDF_ROOT environment variable not set!
goto usage

:NoWDFddk
@echo Error: WDF_DDK environment variable not set!
goto usage

:usage
if %quiet% EQU 0 start http:\\www.hollistech.com\Resources\ddkbuild\ddkbuildhelp3_15.htm

@echo usage: ddkbuild [-debug^|-verbose^|-quiet] "TARGET" [-prefast^|-oacr^|-root] "checked | free" "directory-to-build" [flags] 
@echo.
@echo       -debug      turns on script echoing for debug purposes
@echo.
@echo       -verbose    announce various script activities to standard out
@echo.
@echo       -quiet      no output to standard out EXCEPT warnings and errors. (And modifies prefast behavior)
@echo.
@echo        TARGET     can be any of the following combinations of DDK and target platform:
@echo.
@echo        -WNET      indicates development system uses WNETBASE environment variable
@echo                    to locate the .Net ddk and builds .net binaries (optional.)
@echo.
@echo        -WNETW2K   indicates development system uses the WNETBASE environment variable
@echo                    to locate the .Net ddk and builds W2K binaries (optional.)
@echo.
@echo        -WNETXP    indicates development system uses WNETBASE environment variable
@echo                    to locate the .Net ddk and builds xp binaries (optional.)
@echo.
@echo        -WNET64    indicates development system uses WNETBASE environment variable
@echo                    to locate the .Net ddk and builds 64bit binaries (optional.)
@echo.
@echo        -WNETA64   indicates development system uses WNETBASE environment variable
@echo                    to locate the .Net ddk and builds AMD 64bit binaries (optional.)
@echo.
@echo        -WLH       indicates development system uses the WLHBASE environment variable
@echo                    to locate the Longhorn ddk and builds Longhorn binaries (optional.)
@echo.
@echo        -WLH64     indicates development system uses the WLHBASE environment variable
@echo                    to locate the Longhorn ddk and builds IA64 Longhorn binaries (optional.)
@echo.
@echo        -WLHA64    indicates development system uses the WLHBASE environment variable
@echo                    to locate the Longhorn ddk and builds AMD64 Longhorn binaries (optional.)
@echo.
@echo        -WLHW2K    indicates development system uses the WLHBASE environment variable
@echo                    to locate the Longhorn ddk and builds W2K binaries (optional.)
@echo.
@echo        -WLHXP     indicates development system uses the WLHBASE environment variable
@echo                    to locate the Longhorn ddk and builds XP binaries (optional.)
@echo.
@echo        -WLHXP64   indicates development system uses the WLHBASE environment variable
@echo                    to locate the Longhorn ddk and builds XP IA64 binaries (optional.)
@echo.
@echo        -WLHNET    indicates development system uses the WLHBASE environment variable
@echo                    to locate the Longhorn ddk and builds .net binaries (optional.)
@echo.
@echo        -WLHNET64  indicates development system uses the WLHBASE environment variable
@echo                    to locate the Longhorn ddk and builds IA64 .bet binaries (optional.)
@echo.
@echo        -WLHNETA64 indicates development system uses the WLHBASE environment variable
@echo                    to locate the Longhorn ddk and builds AMD64 .net binaries (optional.)
@echo.
@echo        -WNETA64   indicates development system uses WNETBASE environment variable
@echo                    to locate the .Net ddk and builds AMD 64bit binaries (optional.)
@echo.
@echo        -WIN7       indicates development system uses the WIN7BASE environment variable
@echo                    to locate the WIN7 ddk and builds WIN7 x86 binaries (optional.)
@echo.
@echo        -WIN764     indicates development system uses the WIN7BASE environment variable
@echo                    to locate the WIN7 ddk and builds IA64 WIN7 binaries (optional.)
@echo.
@echo        -WIN7A64    indicates development system uses the WIN7BASE environment variable
@echo                    to locate the WIN7 ddk and builds AMD64 WIN7 binaries (optional.)
@echo.
@echo        -WIN7WLH    indicates development system uses the WIN7BASE environment variable
@echo                    to locate the WIN7 ddk and builds VISTA/W2K8 x86 binaries (optional.)
@echo.
@echo        -WIN7WLH64  indicates development system uses the WIN7BASE environment variable
@echo                    to locate the WIN7 ddk and builds IA64 VISTA/W2K binaries (optional.)
@echo.
@echo        -WIN7WLHA64 indicates development system uses the WIN7BASE environment variable
@echo                    to locate the WIN7 ddk and builds AMD64 VISTA/W2K binaries (optional.)
@echo.
@echo        -WIN7XP     indicates development system uses the WIN7BASE environment variable
@echo                    to locate the WIN7 ddk and builds XP binaries (optional.)
@echo.
@echo        -WIN7XP64   indicates development system uses the WIN7BASE environment variable
@echo                    to locate the WIN7 ddk and builds XP IA64 binaries (optional.)
@echo.
@echo        -WIN7NET    indicates development system uses the WIN7BASE environment variable
@echo                    to locate the WIN7 ddk and builds W2K3 binaries (optional.)
@echo.
@echo        -WIN7NET64  indicates development system uses the WIN7BASE environment variable
@echo                    to locate the WIN7 ddk and builds IA64 W2K3 binaries (optional.)
@echo.
@echo        -WIN7NETA64 indicates development system uses the WIN7BASE environment variable
@echo                    to locate the WIN7 ddk and builds AMD64 W2K3 binaries (optional.)
@echo.
@echo       -prefast run prefast rather than a normal build if quiet mode is not set, the prefast browser is opened
@echo                after prefast is run otherwise prefast errors and warnings goto stdout
@echo.
@echo       -oacr    run background prefast (OACR.) WIN7 WDK only. Default is no oacr.
@echo.
@echo       -root    set the WIN7 WDK separate_object_root flag. Default is off.
@echo.
@echo        checked    indicates a checked build.
@echo.
@echo        free       indicates a free build (must choose one or the other of free or checked.)
@echo.
@echo        directory  path to build directory, try . (cwd).
@echo.
@echo        flags      any random flags or arguments you think should be passed to build (note that the
@echo                    visual studio /a for clean build is translated to the equivalent build flag.)
@echo                    Note also that multiple arguments can be specified by using quotes to contain
@echo                    the set of arguments, as in "-Z foo blortz w2k xp"
@echo.        
@echo         ex: ddkbuild -WIN7 -oacr checked . -cZ
@echo.
@echo         NOTE: windows .net DDK versions supported must be build 3663 or later 
@echo.

set status=2
goto buildExit

:: ======================
:: post build events
:: currently supports prefast view
:: ======================
:postBuildEvents
if %verbose% EQU 1 @echo post build prefast processing %prefast% %prefast_log%
if "%prefast%" NEQ "" (
    if "%prefast_log%" NEQ "" (
        if exist "%prefast_log%" (
            if %quiet% EQU 1 (
                findstr DEFECTCODE %prefast_log% > NUL 2>&1     
                if not ERRORLEVEL 1 %prefast% list | findstr "warning [0-9]*  FUNCTION: PATH:"
            ) else (
                %prefast% view
            )
        ) 
    )
)
goto buildExit

:: ======================
:: bad shell error handlers
:: ======================

:wrongplatform
@echo Sorry: NT4/W2K/XP/.net only! 
set status=5
goto buildExit

:nt4ddkbuild

@echo Sorry ddkbuild supports windows2000 or later platforms only
set status=6
goto buildExit

:buildExit
exit /b %status%
