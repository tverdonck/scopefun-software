@echo on

rem swig
swig -lua -outdir "%cd%" -o "%cd%\scopefunapi_wrap_lua.c" "%cd%\scopefunapi.i"

pause
