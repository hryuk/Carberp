@del !err.txt
@set nm=peinf
@echo !!! BUILD %nm%.exe
@set lcc=c:\lcc\bin\
@set res=
@set def=
@set lb1=advapi32.lib
@set lb2=
@set lb3=
@set lb4=
@if exist %nm%.obj del %nm%.obj
@if exist %nm%.exe del %nm%.exe
@if exist %nm%.rc %lcc%lrc.exe %nm%.rc
@if exist %nm%.res set res=%nm%.res
@%lcc%lcc.exe -errout=!err.txt -nw -O %nm%.c
@%lcc%lcclnk.exe -s -subsystem console %nm%.obj %res% %def% %lb1% %lb2% %lb3% %lb4%
@del %nm%.obj
