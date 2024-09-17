@echo off
set file_name=%~n1

./rpgcc.exe < examples\%file_name%.rpgle > output\%file_name%.c
gcc output\%file_name%.c

@echo on