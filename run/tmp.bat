@echo off
:start
create.exe
fc result.out tag.out
if not errorlevel 1 goto start
pause