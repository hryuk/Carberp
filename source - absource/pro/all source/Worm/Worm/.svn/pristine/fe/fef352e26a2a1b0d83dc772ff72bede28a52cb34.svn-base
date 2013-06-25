@set nm=hash
@set lcc=X:\lcc\bin\
@if exist %nm%.obj del %nm%.obj
@if exist %nm%.exe del %nm%.exe
@if exist %nm%.rc %lcc%lrc.exe %nm%.rc
@if exist %nm%.rc set res=%nm%.res
@%lcc%lcc.exe -errout=!err.txt -O %nm%.c
@%lcc%lcclnk.exe -s -subsystem console %nm%.obj kernel32.lib
@del %nm%.obj
